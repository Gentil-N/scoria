#ifdef __linux__
#define VK_USE_PLATFORM_XLIB_KHR
#else
#error other OS not supported yet
#endif // __linux__

#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>
#include "volk.h"
#define VMA_STATIC_VULKAN_FUNCTIONS 0
#define VMA_DYNAMIC_VULKAN_FUNCTIONS 1
#include "vk_mem_alloc.h"

#include <stdbool.h>
#include <assert.h>

#include "../include/scoria.h"

#include "cutils_base.h"
#include "log.h"
#include "vki.h"

typedef char *char_ptr;

LIST(size_t);
LIST(char_ptr);
LIST(float);
LIST(uint32_t);

LIST(VkImage)
LIST(VkImageView)
LIST(VkCommandBuffer)
LIST(VkSemaphore)
LIST(VkFence)
LIST(VkFramebuffer);
LIST(VkBuffer)

LIST(VmaAllocation);

VkShaderModule create_shader_module(VkDevice device, const size_t code_size, const uint32_t *code_data);

static inline VkPipelineShaderStageCreateInfo init_pipeline_shader_stage_info(VkShaderStageFlagBits flag, VkShaderModule module, const char *name)
{
    VkPipelineShaderStageCreateInfo stage_info = {0};
    stage_info.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    stage_info.stage = flag;
    stage_info.module = module;
    stage_info.pName = name;
    return stage_info;
}

/*
*   BUFFER
*/

struct Buffer
{
    VkBuffer handle;
    VmaAllocation vma;
    void *map;
};

struct Buffer create_buffer(VmaAllocator allocator, VkDeviceSize size, VkBufferUsageFlags buffer_usage, VmaMemoryUsage memory_usage, VmaAllocationCreateFlags flags, uint32_t queue_count, const uint32_t *queue_indices);

void destroy_buffer(VmaAllocator allocator, struct Buffer *buffer);

void copy_data_to_buffer(VmaAllocator allocator, struct Buffer *buffer, const void *data, size_t buf_offset, size_t data_offset, size_t size);

/*
*   IMAGE
*/
struct Image
{
    VkImage handle;
    VmaAllocation vma;
    VkImageView view;
};

struct Image create_image(VkDevice device, VmaAllocator allocator, uint32_t width, uint32_t height, uint32_t depth, VkFormat format, VkImageType image_type, VkImageViewType view_type, uint32_t queue_count, const uint32_t *queue_indices, VkImageTiling tiling, VkImageUsageFlags usage, VkImageAspectFlags aspect);

void destroy_image(VkDevice device, VmaAllocator allocator, struct Image *image);

/*
*   AUTOMATON
*/

typedef void (*PFN_AUTOMATON_CMD_PERSO_FUNC)(VkCommandBuffer cmd, void *user_data);

enum AutomatonCmdType
{
    AUTOMATON_CMD_TYPE_PERSO = 0,
    AUTOMATON_CMD_TYPE_COPY_BUFFER_CPU_GPU = 1,
    AUTOMATON_CMD_TYPE_COPY_BUFFER_GPU_GPU = 2
};

struct AutomatonCmdCopyBufferGpuGpuInfo
{
    VkBufferCopy copy_region;
    VkBuffer src;
    VkBuffer dst;
};

static inline struct AutomatonCmdCopyBufferGpuGpuInfo init_automaton_cmd_copy_buffer_gpu_gpu_info(VkBufferCopy copy_region, VkBuffer src, VkBuffer dst)
{
    struct AutomatonCmdCopyBufferGpuGpuInfo info = {0};
    info.copy_region = copy_region;
    info.src = src;
    info.dst = dst;
    info.src = src;
    return info;
}

struct AutomatonCmdCopyBufferCpuGpuInfo
{
    size_t src_offset;
    size_t dst_offset;
    size_t size;
    const void *src;
    void *buffer_map;
    VmaAllocation allocation;
    bool release_src;
};

static inline struct AutomatonCmdCopyBufferCpuGpuInfo init_automaton_cmd_copy_buffer_cpu_gpu_info(size_t src_offset, size_t dst_offset, size_t size, const void *src, void *buffer_map, VmaAllocation allocation, bool release_src)
{
    struct AutomatonCmdCopyBufferCpuGpuInfo info = {0};
    info.src_offset = src_offset;
    info.dst_offset = dst_offset;
    info.size = size;
    info.src = src;
    info.buffer_map = buffer_map;
    info.allocation = allocation;
    info.release_src = release_src;
    return info;
}

struct AutomatonCmdPersoInfo
{
    PFN_AUTOMATON_CMD_PERSO_FUNC func;
    void *user_data;
};

static inline struct AutomatonCmdPersoInfo init_automaton_cmd_perso_info(PFN_AUTOMATON_CMD_PERSO_FUNC func, void *user_data)
{
    struct AutomatonCmdPersoInfo info = {0};
    info.func = func;
    info.user_data = user_data;
    return info;
}

struct AutomatonCmd
{
    enum AutomatonCmdType type;
    union
    {
        struct AutomatonCmdPersoInfo perso_info;
        struct AutomatonCmdCopyBufferGpuGpuInfo copy_buffer_gpu_to_gpu_info;
        struct AutomatonCmdCopyBufferCpuGpuInfo copy_buffer_cpu_to_gpu_info;
    };
};

static inline struct AutomatonCmd init_automaton_cmd(enum AutomatonCmdType type)
{
    struct AutomatonCmd cmd = {0};
    cmd.type = type;
    return cmd;
}

typedef struct AutomatonCmd AutomatonCmd;
LIST(AutomatonCmd);

struct AutomatonCmdStack
{
    VkFence fence;
    VkCommandBuffer cmd;
    struct List_AutomatonCmd cmds;
};

typedef struct AutomatonCmdStack AutomatonCmdStack;
LIST(AutomatonCmdStack)

struct AutomatonQueue
{
    VkQueue handle;
    uint32_t index;
    VkCommandPool pool;
    struct List_AutomatonCmdStack stacks;
};

enum AutomatonVkObjectType
{
    AUTOMATON_VK_OBJECT_TYPE_DESCRIPTOR_POOL = 1,
    AUTOMATON_VK_OBJECT_TYPE_BUFFER = 2,
    AUTOMATON_VK_OBJECT_TYPE_IMAGE = 3,
    AUTOMATON_VK_OBJECT_TYPE_IMAGE_VIEW = 4,
    AUTOMATON_VK_OBJECT_TYPE_PIPELINE = 5,
    AUTOMATON_VK_OBJECT_TYPE_PIPELINE_LAYOUT = 6,
    AUTOMATON_VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT = 7,
    AUTOMATON_VK_OBJECT_TYPE_FRAMEBUFFER = 8,
    AUTOMATON_VK_OBJECT_TYPE_SAMPLER = 9,
    AUTOMATON_VK_OBJECT_TYPE_RENDERPASS = 10,
};

struct AutomatonVkObject
{
    enum AutomatonVkObjectType type;
    void *handle;
};

typedef struct AutomatonVkObject AutomatonVkObject;
LIST(AutomatonVkObject);

struct Automaton
{
    VkDevice device;
    VmaAllocator allocator;
    struct AutomatonQueue graphics_queue, compute_queue, transfer_queue;
    struct {
        struct List_VmaAllocation allocations;
        struct List_AutomatonVkObject vkobjects;
    } garbage;
};

enum AutomatonQueueType
{
    AUTOMATON_QUEUE_TYPE_INVALID = 0x0,
    AUTOMATON_QUEUE_TYPE_GRAPHICS = 0x1,
    AUTOMATON_QUEUE_TYPE_COMPUTE = 0x2,
    AUTOMATON_QUEUE_TYPE_TRANSFER = 0x4
};

struct Automaton create_automaton(VkDevice device, VmaAllocator allocator, VkQueue graphics_queue_handle, VkQueue compute_queue_handle, VkQueue transfer_queue_handle, uint32_t graphics_queue_id, uint32_t compute_queue_id, uint32_t transfer_queue_id, uint32_t graphics_stack_count, uint32_t compute_stack_count, uint32_t transfer_stack_count);

void destroy_automaton(struct Automaton *automaton);

void automaton_push_cmds(struct Automaton *automaton, enum AutomatonQueueType queue_type, uint32_t stack_id, struct AutomatonCmd *cmd);

void automaton_flush_cmds(struct Automaton *automaton, enum AutomatonQueueType queue_type, uint32_t stack_id);

void automaton_flush_garbage(struct Automaton *automaton);

struct Buffer automaton_create_buffer(struct Automaton *automaton, uint32_t queue_type_flags, VkDeviceSize size, VkBufferUsageFlags buffer_usage, VmaMemoryUsage memory_usage, VmaAllocationCreateFlags flags);

struct Image automaton_create_image(struct Automaton *automaton, uint32_t queue_type_flags, uint32_t width, uint32_t height, uint32_t depth, VkFormat format, VkImageType image_type, VkImageViewType view_type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageAspectFlags aspect);

void automaton_collect_buffer(struct Automaton *automaton, struct Buffer *buffer);

void automaton_collect_image(struct Automaton *automaton, struct Image *image);

void automaton_collect_vkobject(struct Automaton *automaton, enum AutomatonVkObjectType type, void *handle);

bool automaton_check_queue_support(struct Automaton *automaton, enum AutomatonQueueType type);

/*
*   SUB BUFFER
*/

struct SubBufferAllocator;

struct SubBuffer
{
    bool updated; // if the range has been updated or not (in term of offset). Set it to true in order to force updating the data
    bool free_on_copy; // release data after update
    const void *data; // a pointer to some data on the user side. Must have the size of "subbuffer_size"
    size_t _offset; // offset from the beginning of the section, shouldn't be modified manually
    size_t _segment_id; // basically the index inside subbuffer_segments of a SubBufferAllocator, shouldn't be modified manually
};

typedef struct SubBuffer *SubBuffer_ptr;
LIST(SubBuffer_ptr);

struct SubBufferSegmentInfo
{
    size_t max_subbuffer; // maximum number of SubBuffer allocated inside this segment
    size_t subbuffer_size; // size of each SubBuffer allocated inside this segment
};

struct SubBufferSegment
{
    struct List_SubBuffer_ptr subbuffer_ptrs;
    size_t base_offset; // offset of the segment
    struct SubBufferSegmentInfo info;
};

typedef struct SubBufferSegment SubBufferSegment;
LIST(SubBufferSegment);

struct SubBufferAllocator
{
    struct Automaton *automaton;
    struct Buffer gpu_buffer, transfer_buffer;
    struct List_SubBufferSegment segments;
    enum AutomatonQueueType transfer_queue_type;
};

struct SubBufferAllocator create_subbuffer_allocator(struct Automaton *automaton, uint32_t queue_type_flags, enum AutomatonQueueType transfer_queue_type, VkBufferUsageFlags buffer_usage, size_t segment_count, const struct SubBufferSegmentInfo *segment_infos);

void destroy_subbuffer_allocator(struct SubBufferAllocator *allocator);

struct SubBuffer *allocate_subbuffer(struct SubBufferAllocator *allocator, size_t segment_id);

void free_subbuffer(struct SubBufferAllocator *allocator, struct SubBuffer *subbuffer);

void subbuffer_allocator_update(struct SubBufferAllocator *allocator);

size_t get_subbuffer_size(struct SubBufferAllocator *allocator, struct SubBuffer *subbuffer);

size_t get_subbuffer_segment_offset(struct SubBufferAllocator *allocator, size_t segment_id);

size_t get_subbuffer_segment_max_size(struct SubBufferAllocator *allocator, size_t segment_id);

size_t get_subbuffer_segment_actual_size(struct SubBufferAllocator *allocator, size_t segment_id);

size_t get_subbuffer_segment_subsize(struct SubBufferAllocator *allocator, size_t segment_id);

/*
*   SC ASSET
*/

struct ScAsset
{
    struct List_char_ptr mesh_names;
    struct List_float vertices;
    struct List_uint32_t indices;
    struct List_size_t vertex_byte_size_per_mesh;
    struct List_size_t index_count_per_mesh;
};

/*
*   SC ITEM
*/

struct ScItem
{
    struct SubBuffer *subbuffer;
};

/*
*   SC RESOURCE PACK
*/

typedef struct ScItem *ScItem_ptr;
LIST(ScItem_ptr);
typedef struct List_ScItem_ptr List_ScItem_ptr;
LIST(List_ScItem_ptr);

struct ScMeshPack
{
    struct List_size_t vertex_byte_offsets;
    struct List_size_t index_byte_offsets;
    struct List_size_t index_counts;
    struct List_size_t instance_offsets;
    struct List_size_t max_instances;
    size_t total_mesh_byte_size;
    struct ScPipeline *pipeline;
    struct SubBufferAllocator sb_allocator;
    struct SubBuffer *sb_mesh;
    struct List_List_ScItem_ptr list_item_ptrs;
};

void update_mesh_pack(struct ScMeshPack *mesh_pack);

bool is_mesh_pack_empty(struct ScMeshPack *mesh_pack);

size_t mesh_pack_get_mesh_count(struct ScMeshPack *mesh_pack);

size_t mesh_pack_get_instance_count(struct ScMeshPack *mesh_pack, size_t mesh_id);

VkDeviceSize mesh_pack_get_mesh_vertex_offset(struct ScMeshPack *mesh_pack, size_t mesh_id);

VkDeviceSize mesh_pack_get_mesh_index_offset(struct ScMeshPack *mesh_pack, size_t mesh_id);

VkDeviceSize mesh_pack_get_mesh_instance_offset(struct ScMeshPack *mesh_pack, size_t mesh_id);

uint32_t mesh_pack_get_mesh_index_count(struct ScMeshPack *mesh_pack, size_t mesh_id);

bool mesh_pack_is_mesh_empty(struct ScMeshPack *mesh_pack, size_t mesh_id);

VkBuffer mesh_pack_get_vkbuffer(struct ScMeshPack *mesh_pack);

/*
*   SC POINT LIGHT
*/

struct ScPointLight
{
    struct SubBuffer *subbuffer;
};

/*
*   SC PIPELINE
*/

enum PipelineType
{
    PIPELINE_TYPE_3D = 1,
    PIPELINE_TYPE_2D = 2
};

typedef struct ScMeshPack *ScMeshPack_ptr;
LIST(ScMeshPack_ptr);

typedef void (*pipeline_record_command_buffer_fn)(struct ScPipeline *pipeline, VkCommandBuffer cmd, uint32_t image_index);
typedef void (*pipeline_update_fn)(struct ScPipeline *pipeline);

struct ScPipeline
{
    enum PipelineType type;
    struct Automaton *automaton;
    VkExtent2D extent;
    VkFormat present_format, depth_format;
    const struct List_VkImageView *present_views;
    pipeline_record_command_buffer_fn record_cmd_fn;
    pipeline_update_fn update_fn;
    struct List_ScMeshPack_ptr packs_ptrs;
    union
    {
        struct
        {
            struct
            {
                struct Image position_res, normal_res, albedo_res, depth_res;
                VkRenderPass rpass;
                struct List_VkFramebuffer fbufs;
                VkSampler sampler;
                VkDescriptorSetLayout setlay;
                VkPipelineLayout pipl;
                VkPipeline pip;
                VkDescriptorPool descpool;
                VkDescriptorSet world_desc_set;
            } offscreen;
            struct
            {
                struct Image depth_res;
                VkRenderPass rpass;
                struct List_VkFramebuffer fbufs;
                VkDescriptorSetLayout setlay;
                VkPipelineLayout pipl;
                VkPipeline pip;
                VkDescriptorPool descpool;
                VkDescriptorSet desc_set;
            } forward;
            struct SubBufferAllocator sb_allocator;
            struct SubBuffer *sb_camera, *sb_ambient_light, *sb_sun_light, *sb_light_count;
            union ScGlslVec4f *lights_count;
        } d3_deferred;
    };
};

struct ScPipeline create_pipeline_3d(struct Automaton *automaton, VkExtent2D extent, VkFormat present_format, VkFormat depth_format, const struct List_VkImageView *present_views);

void destroy_pipeline_3d(struct ScPipeline *pipeline);

void pipeline_3d_record_cmd(struct ScPipeline *pipeline, VkCommandBuffer cmd, uint32_t image_index);

void pipeline_3d_update(struct ScPipeline *pipeline);

/*
*   SC CORE
*/

typedef struct ScPipeline *ScPipeline_ptr;
LIST(ScPipeline_ptr);

struct ScCore
{
#ifndef NDEBUG

    /* Base */
    bool debugger_actually_enabled;
    PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT;
    PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessengerEXT;
    VkDebugUtilsMessengerEXT debug_utils_msg;
#endif // NDEBUG
    uint32_t api_version;
    VkInstance instance;
#ifdef __linux__
    PFN_vkCreateXlibSurfaceKHR vkCreateXlibSurfaceKHR;
    PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR vkGetPhysicalDeviceXlibPresentationSupportKHR;
#endif //__linux__
    VkSurfaceKHR surface;
    VkPhysicalDevice phd;
    VkSurfaceCapabilitiesKHR sf_caps;
    VkSurfaceFormatKHR sf_format;
    VkPresentModeKHR sf_present_mode;
    VkExtent2D sf_extent;
    VkFormat depth_format;
    uint32_t image_count;
    VkDevice device;
    uint32_t queue_index;
    VkQueue queue;
    VmaAllocator allocator;
    VkSwapchainKHR swapchain;
    struct List_VkImage simages;
    struct List_VkImageView sviews;
    struct Automaton automaton;
    VkCommandPool cmd_pool;
    struct List_VkCommandBuffer cmds;
    struct List_VkSemaphore sem_ima;
    struct List_VkSemaphore sem_ren;
    struct List_VkFence fences;
    uint32_t current_frame_index;
    struct List_ScPipeline_ptr pipeline_ptrs;
};

#define vkcheck(vk_fn) {VkResult result = vk_fn; if (result != VK_SUCCESS) log_error("vulkan function error");}
#define assert_ndbg(expression) if ((expression) != true) log_error("non-debug assert failed");
