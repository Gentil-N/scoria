#include "common.h"
#include "log.h"
#include "vki.h"
#include <vulkan/vulkan_core.h>

VkShaderModule create_shader_module(VkDevice device, const size_t code_size, const uint32_t *code_data)
{
    VkShaderModuleCreateInfo info = vkiShaderModuleCreateInfo(code_size, code_data);
    VkShaderModule module;
    vkcheck(vkCreateShaderModule(device, &info, NULL, &module));
    return module;
}

struct Buffer create_buffer(VmaAllocator allocator, VkDeviceSize size, VkBufferUsageFlags buffer_usage, VmaMemoryUsage memory_usage, VmaAllocationCreateFlags flags, uint32_t queue_count, const uint32_t *queue_indices)
{
    VkBufferCreateInfo buffer_info = vkiBufferCreateInfo(size, buffer_usage, (queue_count > 1) ? VK_SHARING_MODE_CONCURRENT : VK_SHARING_MODE_EXCLUSIVE, queue_count, queue_indices);
    VmaAllocationCreateInfo alloc_info = {0};
    alloc_info.flags = flags;
    alloc_info.usage = memory_usage;
    struct Buffer buffer = {0};
    VmaAllocationInfo info = {0};
    vkcheck(vmaCreateBuffer(allocator, &buffer_info, &alloc_info, &buffer.handle, &buffer.vma, &info));
    buffer.map = info.pMappedData;
    return buffer;
}

void destroy_buffer(VmaAllocator allocator, struct Buffer *buffer)
{
    vmaDestroyBuffer(allocator, buffer->handle, buffer->vma);
}

void copy_data_to_buffer(VmaAllocator allocator, struct Buffer *buffer, const void *data, size_t buf_offset, size_t data_offset, size_t size)
{
    if (buffer->map == NULL)
    {
        log_error("buffer is not mapped for copy");
        return;
    }
    memcpy(buffer->map + buf_offset, data + data_offset, size);
    vkcheck(vmaInvalidateAllocation(allocator, buffer->vma, buf_offset, size));
    vkcheck(vmaFlushAllocation(allocator, buffer->vma, buf_offset, size));
}

struct Image create_image(VkDevice device, VmaAllocator allocator, uint32_t width, uint32_t height, uint32_t depth, VkFormat format, VkImageType image_type, VkImageViewType view_type, uint32_t queue_count, const uint32_t *queue_indices, VkImageTiling tiling, VkImageUsageFlags usage, VkImageAspectFlags aspect)
{
    VkExtent3D extent = vkiExtent3D(width, height, depth);
    VkImageCreateInfo image_info = vkiImageCreateInfo(image_type, format, extent, 1, 1, VK_SAMPLE_COUNT_1_BIT, tiling, usage, (queue_count > 1) ? VK_SHARING_MODE_CONCURRENT : VK_SHARING_MODE_EXCLUSIVE, queue_count, queue_indices, VK_IMAGE_LAYOUT_UNDEFINED);
    VmaAllocationCreateInfo alloc_info = {0};
    alloc_info.usage = VMA_MEMORY_USAGE_AUTO;
    struct Image image = {0};
    VmaAllocationInfo info = {0};
    vkcheck(vmaCreateImage(allocator, &image_info, &alloc_info, &image.handle, &image.vma, &info));

    VkComponentMapping mapping = vkiComponentMapping_null();
    VkImageSubresourceRange range = vkiImageSubresourceRange(aspect, 0, 1, 0, 1);
    VkImageViewCreateInfo view_info = vkiImageViewCreateInfo(image.handle, view_type, format, mapping, range);
    vkcheck(vkCreateImageView(device, &view_info, NULL, &image.view));

    return image;
}

void destroy_image(VkDevice device, VmaAllocator allocator, struct Image *image)
{
    vkDestroyImageView(device, image->view, NULL);
    vmaDestroyImage(allocator, image->handle, image->vma);
}
