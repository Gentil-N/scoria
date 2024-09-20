#include "common.h"
#include "ctools.h"
#include "log.h"
#include <vulkan/vulkan_core.h>

struct AutomatonCmdStack create_cmd_stack(VkDevice device, VkCommandBuffer cmd)
{
    struct AutomatonCmdStack stack = {0};
    VkFenceCreateInfo fence_info = vkiFenceCreateInfo();
    fence_info.flags = VK_FENCE_CREATE_SIGNALED_BIT;
    vkcheck(vkCreateFence(device, &fence_info, NULL, &stack.fence));
    stack.cmd = cmd;
    stack.cmds = list_create(AutomatonCmd, 0);
    return stack;
}

void destroy_cmd_stack(VkDevice device, struct AutomatonCmdStack *stack)
{
    list_AutomatonCmd_destroy(&stack->cmds);
    vkDestroyFence(device, stack->fence, NULL);
}

void cmd_stack_push(struct AutomatonCmdStack *stack, struct AutomatonCmd *cmd)
{
    list_AutomatonCmd_append(&stack->cmds, cmd);
}

void cmd_stack_flush(struct AutomatonCmdStack *stack, VkDevice device, VkQueue queue)
{
    if (stack->cmds.size == 0)
    {
        return;
    }
    vkcheck(vkWaitForFences(device, 1, &stack->fence, VK_TRUE, UINT64_MAX));
    vkcheck(vkResetFences(device, 1, &stack->fence));
    vkcheck(vkResetCommandBuffer(stack->cmd, 0));
    VkCommandBufferBeginInfo begin_info = vkiCommandBufferBeginInfo(NULL);
    vkBeginCommandBuffer(stack->cmd, &begin_info);
    for_list(i, stack->cmds)
    {
        struct AutomatonCmd *cmd = &stack->cmds.data[i];
        switch (cmd->type)
        {
            case AUTOMATON_CMD_TYPE_COPY_BUFFER_CPU_GPU:
            {
                struct AutomatonCmdCopyBufferCpuGpuInfo *info = &cmd->copy_buffer_cpu_to_gpu_info;
                memcpy((void*)((size_t)info->buffer_map + info->dst_offset), (void *)((size_t)info->src + info->src_offset), info->size);
                if (info->release_src)
                {
                    ram_free((void *)info->src);
                }
                break;
            }
            case AUTOMATON_CMD_TYPE_COPY_BUFFER_GPU_GPU:
            {
                struct AutomatonCmdCopyBufferGpuGpuInfo *info = &cmd->copy_buffer_gpu_to_gpu_info;
                vkCmdCopyBuffer(stack->cmd, info->src, info->dst, 1, &info->copy_region);
                break;
            }
            case AUTOMATON_CMD_TYPE_PERSO:
            {
                struct AutomatonCmdPersoInfo *info = &cmd->perso_info;
                info->func(stack->cmd, info->user_data);
                break;
            }
            default:
            {
                log_warn("automaton cmd type does not exist");
                break;
            }
        }
    }
    vkEndCommandBuffer(stack->cmd);
    VkSubmitInfo submit_info = vkiSubmitInfo(0, NULL, NULL, 1, &stack->cmd, 0, NULL);
    vkcheck(vkQueueSubmit(queue, 1, &submit_info, stack->fence));
    list_AutomatonCmd_resize(&stack->cmds, 0);
}

struct AutomatonQueue create_queue(VkDevice device, VkQueue handle, uint32_t index, uint32_t stack_count)
{
    struct AutomatonQueue queue = {0};
    queue.handle = handle;
    queue.index = index;
    if (handle == VK_NULL_HANDLE) return queue;
    assert_ndbg(stack_count > 0);

    VkCommandPoolCreateInfo pool_info = vkiCommandPoolCreateInfo(queue.index);
    pool_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    vkcheck(vkCreateCommandPool(device, &pool_info, NULL, &queue.pool));

    VkCommandBuffer cmd_bufs[stack_count];
    VkCommandBufferAllocateInfo cmd_info = vkiCommandBufferAllocateInfo(queue.pool, VK_COMMAND_BUFFER_LEVEL_PRIMARY, stack_count);
    vkcheck(vkAllocateCommandBuffers(device, &cmd_info, cmd_bufs));

    queue.stacks = list_create(AutomatonCmdStack, stack_count);
    for_list(i, queue.stacks)
    {
        queue.stacks.data[i] = create_cmd_stack(device, cmd_bufs[i]);
    }
    return queue;
}

void destroy_queue(VkDevice device, struct AutomatonQueue *queue)
{
    if (queue->handle == VK_NULL_HANDLE || queue->stacks.data == NULL) return;
    for_list(i, queue->stacks)
    {
        destroy_cmd_stack(device, &queue->stacks.data[i]);
    }
    list_AutomatonCmdStack_destroy(&queue->stacks);
    vkDestroyCommandPool(device, queue->pool, NULL);
}

void queue_push_cmd(struct AutomatonQueue *queue, uint32_t stack_id, struct AutomatonCmd *cmd)
{
    if (queue->handle == VK_NULL_HANDLE || queue->stacks.data == NULL)
    {
        log_warn("queue is not suitable for pushing cmd %p %p", queue->handle, queue->stacks.data);
        return;
    }
    assert(stack_id < queue->stacks.size);
    cmd_stack_push(&queue->stacks.data[stack_id], cmd);
}

void queue_flush_cmd(struct AutomatonQueue *queue, VkDevice device, uint32_t stack_id)
{
    if (queue->handle == VK_NULL_HANDLE || queue->stacks.data == NULL)
    {
        log_warn("queue is not suitable for flushing cmd");
        return;
    }
    assert(stack_id < queue->stacks.size);
    cmd_stack_flush(&queue->stacks.data[stack_id], device, queue->handle);
}

void queue_wait_idle(struct AutomatonQueue *queue)
{
    if (queue->handle == VK_NULL_HANDLE) return;
    vkQueueWaitIdle(queue->handle);
}

bool queue_check_support(const struct AutomatonQueue *queue)
{
    return (queue->handle != VK_NULL_HANDLE) && queue->stacks.size > 0;
}

struct Automaton create_automaton(VkDevice device, VmaAllocator allocator, VkQueue graphics_queue_handle, VkQueue compute_queue_handle, VkQueue transfer_queue_handle, uint32_t graphics_queue_id, uint32_t compute_queue_id, uint32_t transfer_queue_id, uint32_t graphics_stack_count, uint32_t compute_stack_count, uint32_t transfer_stack_count)
{
    struct Automaton automaton = {0};
    automaton.device = device;
    automaton.graphics_queue = create_queue(device, graphics_queue_handle, graphics_queue_id, graphics_stack_count);
    automaton.compute_queue = create_queue(device, compute_queue_handle, compute_queue_id, compute_stack_count);
    automaton.transfer_queue = create_queue(device, transfer_queue_handle, transfer_queue_id, transfer_stack_count);
    automaton.allocator = allocator;
    automaton.garbage.allocations = list_create(VmaAllocation, 0);
    automaton.garbage.vkobjects = list_create(AutomatonVkObject, 0);
    return automaton;
}

void destroy_automaton(struct Automaton *automaton)
{
    automaton_flush_garbage(automaton);
    destroy_queue(automaton->device, &automaton->graphics_queue);
    destroy_queue(automaton->device, &automaton->compute_queue);
    destroy_queue(automaton->device, &automaton->transfer_queue);
    list_AutomatonVkObject_destroy(&automaton->garbage.vkobjects);
    list_VmaAllocation_destroy(&automaton->garbage.allocations);
}

void automaton_push_cmds(struct Automaton *automaton, enum AutomatonQueueType queue_type, uint32_t stack_id, struct AutomatonCmd *cmd)
{
    switch (queue_type)
    {
    case AUTOMATON_QUEUE_TYPE_GRAPHICS:
    queue_push_cmd(&automaton->graphics_queue, stack_id, cmd);
    break;
    case AUTOMATON_QUEUE_TYPE_COMPUTE:
    queue_push_cmd(&automaton->compute_queue, stack_id, cmd);
    break;
    case AUTOMATON_QUEUE_TYPE_TRANSFER:
    queue_push_cmd(&automaton->transfer_queue, stack_id, cmd);
    break;
    default:
    log_warn("queue type not supported");
    break;
    }
}

void automaton_flush_cmds(struct Automaton *automaton, enum AutomatonQueueType queue_type, uint32_t stack_id)
{
    switch (queue_type)
    {
    case AUTOMATON_QUEUE_TYPE_GRAPHICS:
    queue_flush_cmd(&automaton->graphics_queue, automaton->device, stack_id);
    break;
    case AUTOMATON_QUEUE_TYPE_COMPUTE:
    queue_flush_cmd(&automaton->compute_queue, automaton->device, stack_id);
    break;
    case AUTOMATON_QUEUE_TYPE_TRANSFER:
    queue_flush_cmd(&automaton->transfer_queue, automaton->device, stack_id);
    break;
    default:
    log_warn("queue type not supported");
    break;
    }
}

void destroy_vkobject(VkDevice device, struct AutomatonVkObject *vkobject)
{
    switch (vkobject->type)
    {
    case AUTOMATON_VK_OBJECT_TYPE_DESCRIPTOR_POOL:
    vkDestroyDescriptorPool(device, (VkDescriptorPool)vkobject->handle, NULL);
    log_debug("descriptor pool destroyed");
    break;
    case AUTOMATON_VK_OBJECT_TYPE_PIPELINE:
    vkDestroyPipeline(device, (VkPipeline)vkobject->handle, NULL);
    log_debug("pipeline destroyed");
    break;
    case AUTOMATON_VK_OBJECT_TYPE_PIPELINE_LAYOUT:
    vkDestroyPipelineLayout(device, (VkPipelineLayout)vkobject->handle, NULL);
    log_debug("pipeline layout destroyed");
    break;
    case AUTOMATON_VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT:
    vkDestroyDescriptorSetLayout(device, (VkDescriptorSetLayout)vkobject->handle, NULL);
    log_debug("descriptor set layout destroyed");
    break;
    case AUTOMATON_VK_OBJECT_TYPE_FRAMEBUFFER:
    vkDestroyFramebuffer(device, (VkFramebuffer)vkobject->handle, NULL);
    log_debug("framebuffer destroyed");
    break;
    case AUTOMATON_VK_OBJECT_TYPE_SAMPLER:
    vkDestroySampler(device, (VkSampler)vkobject->handle, NULL);
    log_debug("sampler destroyed");
    break;
    case AUTOMATON_VK_OBJECT_TYPE_RENDERPASS:
    vkDestroyRenderPass(device, (VkRenderPass)vkobject->handle, NULL);
    log_debug("render pass destroyed");
    break;
    case AUTOMATON_VK_OBJECT_TYPE_BUFFER:
    vkDestroyBuffer(device, (VkBuffer)vkobject->handle, NULL);
    log_debug("buffer destroyed");
    break;
    case AUTOMATON_VK_OBJECT_TYPE_IMAGE:
    vkDestroyImage(device, (VkImage)vkobject->handle, NULL);
    log_debug("image destroyed");
    break;
    case AUTOMATON_VK_OBJECT_TYPE_IMAGE_VIEW:
    vkDestroyImageView(device, (VkImageView)vkobject->handle, NULL);
    log_debug("image view destroyed");
    break;
    default:
    log_warn("vkobject not recognized");
    break;
    }
}

void automaton_flush_garbage(struct Automaton *automaton)
{
    if (automaton->garbage.allocations.size > 0 || automaton->garbage.vkobjects.size)
    {
        queue_wait_idle(&automaton->graphics_queue);
        queue_wait_idle(&automaton->compute_queue);
        queue_wait_idle(&automaton->transfer_queue);
    }
    if (automaton->garbage.allocations.size > 0)
    {
        for_list(i, automaton->garbage.allocations)
        {
            //vmaUnmapMemory(allocator, garbage->vma_list[i]);
            vmaFreeMemory(automaton->allocator, automaton->garbage.allocations.data[i]);
            log_debug("memory released");
        }
        list_VmaAllocation_resize(&automaton->garbage.allocations, 0);
    }
    if (automaton->garbage.vkobjects.size > 0)
    {
        for_list(i, automaton->garbage.vkobjects)
        {
            destroy_vkobject(automaton->device, &automaton->garbage.vkobjects.data[i]);
        }
        list_AutomatonVkObject_resize(&automaton->garbage.vkobjects, 0);
    }
}

uint32_t fill_unique_queue_index(uint32_t queue_count, uint32_t *queue_indices, uint32_t queue_type_flags, enum AutomatonQueueType type, const struct AutomatonQueue *queue)
{
    if (queue_type_flags & type)
    {
        if (queue_check_support(queue))
        {
            for_loop(i, queue_count)
            {
                if (queue_indices[i] == queue->index) return queue_count; // already present in the list (vulkan doesn't support duplicate queue indices)
            }
            queue_indices[queue_count] = queue->index;
            return queue_count + 1;
        }
        else
        {
            log_warn("queue type %d not suitable", (uint32_t)type);
        }
    }
    return queue_count;
}

uint32_t fill_queue_indices(struct Automaton *automaton, uint32_t *queue_indices, uint32_t queue_type_flags)
{
    uint32_t queue_count = 0;
    queue_count = fill_unique_queue_index(queue_count, queue_indices, queue_type_flags, AUTOMATON_QUEUE_TYPE_GRAPHICS, &automaton->graphics_queue);
    queue_count = fill_unique_queue_index(queue_count, queue_indices, queue_type_flags, AUTOMATON_QUEUE_TYPE_COMPUTE, &automaton->compute_queue);
    queue_count = fill_unique_queue_index(queue_count, queue_indices, queue_type_flags, AUTOMATON_QUEUE_TYPE_TRANSFER, &automaton->transfer_queue);
    return queue_count;
}

struct Buffer automaton_create_buffer(struct Automaton *automaton, uint32_t queue_type_flags, VkDeviceSize size, VkBufferUsageFlags buffer_usage, VmaMemoryUsage memory_usage, VmaAllocationCreateFlags flags)
{
    uint32_t queue_indices[4] = {0};
    uint32_t queue_count = fill_queue_indices(automaton, queue_indices, queue_type_flags);
    return create_buffer(automaton->allocator, size, buffer_usage, memory_usage, flags, queue_count, queue_indices);
}

struct Image automaton_create_image(struct Automaton *automaton, uint32_t queue_type_flags, uint32_t width, uint32_t height, uint32_t depth, VkFormat format, VkImageType image_type, VkImageViewType view_type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageAspectFlags aspect)
{
    uint32_t queue_indices[4] = {0};
    uint32_t queue_count = fill_queue_indices(automaton, queue_indices, queue_type_flags);
    return create_image(automaton->device, automaton->allocator, width, height, depth, format, image_type, view_type, queue_count, queue_indices, tiling, usage, aspect);
}

void automaton_collect_buffer(struct Automaton *automaton, struct Buffer *buffer)
{
    automaton_collect_vkobject(automaton, AUTOMATON_VK_OBJECT_TYPE_BUFFER, buffer->handle);
    list_VmaAllocation_append(&automaton->garbage.allocations, &buffer->vma);
}

void automaton_collect_image(struct Automaton *automaton, struct Image *image)
{
    automaton_collect_vkobject(automaton, AUTOMATON_VK_OBJECT_TYPE_IMAGE, image->handle);
    automaton_collect_vkobject(automaton, AUTOMATON_VK_OBJECT_TYPE_IMAGE_VIEW, image->view);
    list_VmaAllocation_append(&automaton->garbage.allocations, &image->vma);
}

void automaton_collect_vkobject(struct Automaton *automaton, enum AutomatonVkObjectType type, void *handle)
{
    struct AutomatonVkObject vkobject = {type, handle};
    list_AutomatonVkObject_append(&automaton->garbage.vkobjects, &vkobject);
}

bool automaton_check_queue_support(struct Automaton *automaton, enum AutomatonQueueType type)
{
    switch (type)
    {
    case AUTOMATON_QUEUE_TYPE_GRAPHICS:
    return queue_check_support(&automaton->graphics_queue);
    case AUTOMATON_QUEUE_TYPE_COMPUTE:
    return queue_check_support(&automaton->compute_queue);
    case AUTOMATON_QUEUE_TYPE_TRANSFER:
    return queue_check_support(&automaton->transfer_queue);
    default:
    log_error("queue type is not supported");
    return false;
    }
}
