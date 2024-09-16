#include "common.h"

struct SubBuffer *create_subbuffer(size_t offset, size_t segment_id)
{
    ram_alloc_init(struct SubBuffer, subbuffer);
    subbuffer->data = NULL;
    subbuffer->updated = false;
    subbuffer->_offset = offset;
    subbuffer->_segment_id = segment_id;
    return subbuffer;
}

void destroy_subbuffer(struct SubBuffer *subbuffer)
{
    ram_free(subbuffer);
}

void subbuffer_update(struct SubBuffer *subbuffer, struct Buffer *transfer_buffer, struct Buffer *gpu_buffer, size_t size, struct Automaton *automaton, enum AutomatonQueueType transfer_queue_type)
{
    if (subbuffer->data == NULL)
    {
        subbuffer->updated = false;
        return;
    }
    struct AutomatonCmdCopyBufferCpuGpuInfo cpu_gpu_info = init_automaton_cmd_copy_buffer_cpu_gpu_info(0, subbuffer->_offset, size, subbuffer->data, transfer_buffer->map, transfer_buffer->vma, false);
    struct AutomatonCmd cmd = init_automaton_cmd(AUTOMATON_CMD_TYPE_COPY_BUFFER_CPU_GPU);
    cmd.copy_buffer_cpu_to_gpu_info = cpu_gpu_info;
    automaton_push_cmds(automaton, transfer_queue_type, 0, &cmd);
    VkBufferCopy region = vkiBufferCopy(subbuffer->_offset, subbuffer->_offset, (VkDeviceSize)size);
    struct AutomatonCmdCopyBufferGpuGpuInfo gpu_gpu_info = init_automaton_cmd_copy_buffer_gpu_gpu_info(region, transfer_buffer->handle, gpu_buffer->handle);
    cmd.type = AUTOMATON_CMD_TYPE_COPY_BUFFER_GPU_GPU;
    cmd.copy_buffer_gpu_to_gpu_info = gpu_gpu_info;
    automaton_push_cmds(automaton, transfer_queue_type, 0, &cmd);
    subbuffer->updated = false;
}

struct SubBufferSegment create_segment(size_t base_offset, const struct SubBufferSegmentInfo *info)
{
    struct SubBufferSegment segment = {0};
    segment.base_offset = base_offset;
    segment.info.max_subbuffer = info->max_subbuffer;
    segment.info.subbuffer_size = info->subbuffer_size;
    segment.subbuffer_ptrs = list_create(SubBuffer_ptr, 0);
    return segment;
}

void destroy_segment(struct SubBufferSegment *segment)
{
    for_list(i, segment->subbuffer_ptrs)
    {
        destroy_subbuffer(segment->subbuffer_ptrs.data[i]);
    }
    list_SubBuffer_ptr_destroy(&segment->subbuffer_ptrs);
}

struct SubBuffer *segment_allocate_subbuffer(struct SubBufferSegment *segment, size_t segment_id)
{
    assert_ndbg(segment->subbuffer_ptrs.size < segment->info.max_subbuffer);
    struct SubBuffer *subbuffer = create_subbuffer(segment->base_offset + segment->subbuffer_ptrs.size * segment->info.subbuffer_size, segment_id);
    subbuffer->updated = true;
    list_SubBuffer_ptr_append(&segment->subbuffer_ptrs, &subbuffer);
    return subbuffer;
}

void segment_free_subbuffer(struct SubBufferSegment *segment, struct SubBuffer *subbuffer)
{
    size_t last_range_index = segment->subbuffer_ptrs.size - 1;
    size_t range_index = (size_t)((subbuffer->_offset - segment->base_offset) / segment->info.subbuffer_size);
    if (range_index != last_range_index)
    {
        assert(range_index < segment->subbuffer_ptrs.size);
        segment->subbuffer_ptrs.data[last_range_index]->_offset = subbuffer->_offset;
        segment->subbuffer_ptrs.data[range_index] = segment->subbuffer_ptrs.data[last_range_index];
        segment->subbuffer_ptrs.data[range_index]->updated = true;
    }
    list_SubBuffer_ptr_resize(&segment->subbuffer_ptrs, last_range_index);
    destroy_subbuffer(subbuffer);
}

void segment_update(struct SubBufferSegment *segment, struct Buffer *transfer_buffer, struct Buffer *gpu_buffer, struct Automaton *automaton, enum AutomatonQueueType transfer_queue_type)
{
    for_list(i, segment->subbuffer_ptrs)
    {
        if (segment->subbuffer_ptrs.data[i]->updated) 
        {
            subbuffer_update(segment->subbuffer_ptrs.data[i], transfer_buffer, gpu_buffer, segment->info.subbuffer_size, automaton, transfer_queue_type);
        }
    }
}

struct SubBufferAllocator create_subbuffer_allocator(struct Automaton *automaton, uint32_t queue_type_flags, enum AutomatonQueueType transfer_queue_type, VkBufferUsageFlags buffer_usage, size_t segment_count, const struct SubBufferSegmentInfo *segment_infos)
{
    assert(automaton_check_queue_support(automaton, transfer_queue_type) && (queue_type_flags & transfer_queue_type) > 0);
    struct SubBufferAllocator allocator = {0};
    allocator.automaton = automaton;
    allocator.transfer_queue_type = transfer_queue_type;
    allocator.segments = list_create(SubBufferSegment, segment_count);
    size_t offset = 0;
    for_loop(i, segment_count)
    {
        allocator.segments.data[i] = create_segment(offset, &segment_infos[i]);
        offset += segment_infos[i].max_subbuffer * segment_infos[i].subbuffer_size;
    }
    allocator.transfer_buffer = automaton_create_buffer(allocator.automaton, queue_type_flags, offset, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VMA_MEMORY_USAGE_AUTO_PREFER_HOST, VMA_ALLOCATION_CREATE_DEDICATED_MEMORY_BIT | VMA_ALLOCATION_CREATE_MAPPED_BIT | VMA_ALLOCATION_CREATE_HOST_ACCESS_RANDOM_BIT);
    allocator.gpu_buffer = automaton_create_buffer(allocator.automaton, queue_type_flags, offset, buffer_usage | VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT, VMA_MEMORY_USAGE_AUTO_PREFER_DEVICE, VMA_ALLOCATION_CREATE_DEDICATED_MEMORY_BIT);
    return allocator;
}

void destroy_subbuffer_allocator(struct SubBufferAllocator *allocator)
{
    automaton_collect_buffer(allocator->automaton, &allocator->gpu_buffer);
    automaton_collect_buffer(allocator->automaton, &allocator->transfer_buffer);
    for_list(i, allocator->segments)
    {
        destroy_segment(&allocator->segments.data[i]);
    }
    list_SubBufferSegment_destroy(&allocator->segments);
}

struct SubBuffer *allocate_subbuffer(struct SubBufferAllocator *allocator, size_t segment_id)
{
    assert(segment_id < allocator->segments.size);
    return segment_allocate_subbuffer(&allocator->segments.data[segment_id], segment_id);
}

void free_subbuffer(struct SubBufferAllocator *allocator, struct SubBuffer *subbuffer)
{
    segment_free_subbuffer(&allocator->segments.data[subbuffer->_segment_id], subbuffer);
}

void subbuffer_allocator_update(struct SubBufferAllocator *allocator)
{
    for_list(i, allocator->segments)
    {
        segment_update(&allocator->segments.data[i], &allocator->transfer_buffer, &allocator->gpu_buffer, allocator->automaton, allocator->transfer_queue_type);
    }
}

size_t get_subbuffer_size(struct SubBufferAllocator *allocator, struct SubBuffer *subbuffer)
{
    assert(subbuffer->_segment_id < allocator->segments.size);
    return allocator->segments.data[subbuffer->_segment_id].info.subbuffer_size;
}

size_t get_subbuffer_segment_offset(struct SubBufferAllocator *allocator, size_t segment_id)
{
    assert(segment_id < allocator->segments.size);
    return allocator->segments.data[segment_id].base_offset;
}

size_t get_subbuffer_segment_max_size(struct SubBufferAllocator *allocator, size_t segment_id)
{
    assert(segment_id < allocator->segments.size);
    return allocator->segments.data[segment_id].info.max_subbuffer * allocator->segments.data[segment_id].info.subbuffer_size;
}

size_t get_subbuffer_segment_actual_size(struct SubBufferAllocator *allocator, size_t segment_id)
{
    assert(segment_id < allocator->segments.size);
    return allocator->segments.data[segment_id].subbuffer_ptrs.size * allocator->segments.data[segment_id].info.subbuffer_size;
}

size_t get_subbuffer_segment_subsize(struct SubBufferAllocator *allocator, size_t segment_id)
{
    assert(segment_id < allocator->segments.size);
    return allocator->segments.data[segment_id].info.subbuffer_size;
}