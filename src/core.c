#include "common.h"
#include "ctools.h"

#include <X11/X.h>
#include <X11/Xlib.h>

void trace_fn(void *address, const char *file, int line)
{
    log_warn("Memory leak (%p) in file %s at %d\n", address, filename(file), line);
}

static VKAPI_ATTR VkBool32 VKAPI_CALL debug_callback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData, void *pUserData)
{
    char *container = ram_malloc(sizeof(char) * 10000);
    char *msg = strcat(container, pCallbackData->pMessage);
    // if (messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT)
    // {
    //     log_debug(msg);
    // }
    if (messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT)
    {
        log_debug(msg);
    }
    else if (messageSeverity & VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT)
    {
        log_error(msg);
    }
    ram_free(container);
    return VK_FALSE;
}

LIST(VkExtensionProperties)
LIST(VkLayerProperties)

void create_instance(struct ScCore *core)
{
#ifndef NDEBUG
    bool debug_ext_present = false, debug_layer_present = false;
    core->debugger_actually_enabled = true;
    {
        uint32_t ext_count;
        vkcheck(vkEnumerateInstanceExtensionProperties(NULL, &ext_count, NULL));
        struct List_VkExtensionProperties exts = list_create(VkExtensionProperties, ext_count);
        vkcheck(vkEnumerateInstanceExtensionProperties(NULL, &ext_count, exts.data));
        for (uint32_t i = 0; i < ext_count; ++i)
        {
            if (strcmp(exts.data[i].extensionName, VK_EXT_DEBUG_UTILS_EXTENSION_NAME) == 0)
            {
                debug_ext_present = true;
                break;
            }
        }
        list_VkExtensionProperties_destroy(&exts);
    }
    char *requ_layers[] = {"VK_LAYER_KHRONOS_validation"};
    {
        uint32_t layer_count = 0;
        vkcheck(vkEnumerateInstanceLayerProperties(&layer_count, NULL));
        struct List_VkLayerProperties layers = list_create(VkLayerProperties, layer_count);
        vkcheck(vkEnumerateInstanceLayerProperties(&layer_count, layers.data));
        for (uint32_t i = 0; i < layer_count; ++i)
        {
            if (strcmp(requ_layers[0], layers.data[i].layerName) == 0)
            {
                debug_layer_present = true;
                break;
            }
        }
        list_VkLayerProperties_destroy(&layers);
    }
    if (!debug_ext_present || !debug_layer_present)
    {
        core->debugger_actually_enabled = false;
        log_warn("unable to activate vulkan debugger");
    }
#endif // NDEBUG

    {
        vkcheck(vkEnumerateInstanceVersion(&core->api_version));
        VkApplicationInfo app_info = vkiApplicationInfo_null();
        app_info.apiVersion = core->api_version;
        VkInstanceCreateInfo info = {0};
        info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        info.pApplicationInfo = &app_info;
        uint32_t ext_count = 2;
#ifdef __linux__
        const char *exts[] = {VK_KHR_XLIB_SURFACE_EXTENSION_NAME, VK_KHR_SURFACE_EXTENSION_NAME};
#endif // __linux__
        info.enabledExtensionCount = ext_count;
        info.ppEnabledExtensionNames = exts;
#ifndef NDEBUG
        const char **exts_total = (const char **)ram_malloc(sizeof(const char *) * (ext_count + 1));
        if (core->debugger_actually_enabled)
        {
            info.enabledExtensionCount += 1;
            for (uint32_t i = 0; i < ext_count; ++i)
            {
                exts_total[i] = exts[i];
            }
            exts_total[ext_count] = VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
            info.ppEnabledExtensionNames = exts_total;
            info.enabledLayerCount = 1;
            info.ppEnabledLayerNames = (const char *const *)requ_layers;
        }
#endif // NDEBUG
        vkcheck(vkCreateInstance(&info, NULL, &core->instance));
        volkLoadInstance(core->instance);
#ifndef NDEBUG
        ram_free(exts_total);
#endif // NDEBUG
        vkGetPhysicalDeviceSurfaceSupportKHR = (PFN_vkGetPhysicalDeviceSurfaceSupportKHR)vkGetInstanceProcAddr(core->instance, "vkGetPhysicalDeviceSurfaceSupportKHR");
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR = (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)vkGetInstanceProcAddr(core->instance, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
        vkGetPhysicalDeviceSurfaceFormatsKHR = (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR)vkGetInstanceProcAddr(core->instance, "vkGetPhysicalDeviceSurfaceFormatsKHR");
        vkGetPhysicalDeviceSurfacePresentModesKHR = (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR)vkGetInstanceProcAddr(core->instance, "vkGetPhysicalDeviceSurfacePresentModesKHR");
        vkDestroySurfaceKHR = (PFN_vkDestroySurfaceKHR)vkGetInstanceProcAddr(core->instance, "vkDestroySurfaceKHR");
#ifdef __linux__
        core->vkCreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR)vkGetInstanceProcAddr(core->instance, "vkCreateXlibSurfaceKHR");
        core->vkGetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)vkGetInstanceProcAddr(core->instance, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
#endif // __linux__
    }
}

void create_debugger(struct ScCore *core)
{
#ifndef NDEBUG
    if (core->debugger_actually_enabled != true) return;

    core->vkCreateDebugUtilsMessengerEXT = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(core->instance, "vkCreateDebugUtilsMessengerEXT");
    core->vkDestroyDebugUtilsMessengerEXT = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(core->instance, "vkDestroyDebugUtilsMessengerEXT");

    if (!core->vkCreateDebugUtilsMessengerEXT || !core->vkDestroyDebugUtilsMessengerEXT) log_error("Unable to load debug extension functions");

    VkDebugUtilsMessengerCreateInfoEXT info = {0};
    info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    info.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    info.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    info.pfnUserCallback = debug_callback;

    vkcheck(core->vkCreateDebugUtilsMessengerEXT(core->instance, &info, NULL, &core->debug_utils_msg));
#endif // NDEBUG
}

void create_surface(struct ScCore *core, const struct ScCoreInfo *core_info)
{
#ifdef __linux__
    VkXlibSurfaceCreateInfoKHR info = {0};
    info.sType = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
    info.dpy = core_info->os_specific.dpy;
    info.window = core_info->os_specific.window;
    vkcheck(core->vkCreateXlibSurfaceKHR(core->instance, &info, NULL, &core->surface));
#endif
}

LIST(VkPhysicalDevice);

typedef struct GpuDesc
{
    VkPhysicalDevice ph_device;
    VkPhysicalDeviceProperties props;
    uint32_t graph_queue;
} GpuDesc;

LIST(GpuDesc)
LIST(VkQueueFamilyProperties);
LIST(VkPresentModeKHR)
LIST(VkSurfaceFormatKHR);

VkFormat find_suitable_format(VkPhysicalDevice phd, const VkFormat *candidates, size_t candidate_count, VkImageTiling tiling, VkFormatFeatureFlags features)
{
    for (size_t i = 0; i < candidate_count; ++i)
    {
        VkFormatProperties properties;
        vkGetPhysicalDeviceFormatProperties(phd, candidates[i], &properties);
        if (tiling == VK_IMAGE_TILING_LINEAR && (properties.linearTilingFeatures & features) == features)
        {
            return candidates[i];
        } else if (tiling == VK_IMAGE_TILING_OPTIMAL && (properties.optimalTilingFeatures & features) == features) {
            return candidates[i];
        }
    }
    log_error("cannot find a suitable format");
    return VK_FORMAT_UNDEFINED;
}

void create_device(struct ScCore *core, const struct ScCoreInfo *core_info)
{
    uint32_t gpu_count = 0;
    vkcheck(vkEnumeratePhysicalDevices(core->instance, &gpu_count, NULL));
    struct List_VkPhysicalDevice gpus = list_create(VkPhysicalDevice, gpu_count);
    vkcheck(vkEnumeratePhysicalDevices(core->instance, &gpu_count, gpus.data));

    struct List_GpuDesc gpu_descs = list_create(GpuDesc, 0);

    for (size_t i = 0; i < gpu_count; ++i)
    {
        VkPhysicalDeviceProperties props;
        vkGetPhysicalDeviceProperties(gpus.data[i], &props);
        uint32_t ext_count = 0;
        vkcheck(vkEnumerateDeviceExtensionProperties(gpus.data[i], NULL, &ext_count, NULL));
        struct List_VkExtensionProperties exts = list_create(VkExtensionProperties, ext_count);
        vkcheck(vkEnumerateDeviceExtensionProperties(gpus.data[i], NULL, &ext_count, exts.data));
        bool ext_found = false;
        for (uint32_t j = 0; j < ext_count; ++j)
        {
            if (strcmp(exts.data[j].extensionName, VK_KHR_SWAPCHAIN_EXTENSION_NAME))
            {
                ext_found = true;
                break;
            }
        }
        uint32_t queue_count = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(gpus.data[i], &queue_count, NULL);
        struct List_VkQueueFamilyProperties queue_props = list_create(VkQueueFamilyProperties, queue_count);
        vkGetPhysicalDeviceQueueFamilyProperties(gpus.data[i], &queue_count, queue_props.data);
        uint32_t queue_index = UINT32_MAX;
        for (uint32_t j = 0; j < queue_count; ++j)
        {
            VkBool32 surface_support = VK_FALSE;
            vkcheck(vkGetPhysicalDeviceSurfaceSupportKHR(gpus.data[i], j, core->surface, &surface_support));
#ifdef __linux__
            VkBool32 pres_supported = core->vkGetPhysicalDeviceXlibPresentationSupportKHR(gpus.data[i], j, core_info->os_specific.dpy, core_info->os_specific.visual_id);
            //log_info("pres: %d %d", j, pres_supported);
#endif // __linux__
            if (queue_props.data[j].queueCount > 0 && queue_props.data[j].queueFlags & VK_QUEUE_GRAPHICS_BIT && pres_supported == VK_TRUE && surface_support)
            {
                queue_index = j;
                break;
            }
        }
        if (ext_found && queue_index != UINT32_MAX)
        {
            GpuDesc desc = {gpus.data[i], props, queue_index};
            list_GpuDesc_append(&gpu_descs, &desc);
        }
        list_VkQueueFamilyProperties_destroy(&queue_props);
        list_VkExtensionProperties_destroy(&exts);
    }
    list_VkPhysicalDevice_destroy(&gpus);
    if (gpu_descs.size == 0)
    {
        log_error("no suitable GPU");
        return;
    }
    GpuDesc desc = gpu_descs.data[0];
    for (size_t i = 0; i < gpu_descs.size; ++i)
    {
        if (gpu_descs.data[i].props.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
        {
            desc = gpu_descs.data[i];
        }
    }

    vkcheck(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(desc.ph_device, core->surface, &core->sf_caps));
    {
        core->sf_present_mode = VK_PRESENT_MODE_FIFO_KHR;
        uint32_t mode_count = 0;
        vkcheck(vkGetPhysicalDeviceSurfacePresentModesKHR(desc.ph_device, core->surface, &mode_count, NULL));
        struct List_VkPresentModeKHR modes = list_create(VkPresentModeKHR, mode_count);
        vkcheck(vkGetPhysicalDeviceSurfacePresentModesKHR(desc.ph_device, core->surface, &mode_count, modes.data));
        for (uint32_t i = 0; i < mode_count; ++i)
        {
            if (modes.data[i] == VK_PRESENT_MODE_MAILBOX_KHR)
            {
                core->sf_present_mode = VK_PRESENT_MODE_MAILBOX_KHR;
                break;
            }
        }
        list_VkPresentModeKHR_destroy(&modes);
    }
    {
        uint32_t format_count = 0;
        vkcheck(vkGetPhysicalDeviceSurfaceFormatsKHR(desc.ph_device, core->surface, &format_count, NULL));
        struct List_VkSurfaceFormatKHR formats = list_create(VkSurfaceFormatKHR, format_count);
        vkcheck(vkGetPhysicalDeviceSurfaceFormatsKHR(desc.ph_device, core->surface, &format_count, formats.data));
        core->sf_format = formats.data[0];
        for (uint32_t i = 0; i < format_count; ++i)
        {
            if (formats.data[i].format == VK_FORMAT_B8G8R8A8_SRGB && formats.data[i].colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
            {
                core->sf_format = formats.data[i];
                break;
            }
        }
        list_VkSurfaceFormatKHR_destroy(&formats);
    }
    {
        if (core->sf_caps.currentExtent.width != UINT32_MAX)
        {
            core->sf_extent = core->sf_caps.currentExtent;
        }
        else
        {
            int width, height;
            core->sf_extent.width = clamp((uint32_t)core_info->window_width, core->sf_caps.minImageExtent.width, core->sf_caps.maxImageExtent.width);
            core->sf_extent.height = clamp((uint32_t)core_info->window_height, core->sf_caps.minImageExtent.height, core->sf_caps.maxImageExtent.height);
        }
    }
    {
        VkFormat candidates[] = {VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT};
        core->depth_format = find_suitable_format(desc.ph_device, candidates, 3, VK_IMAGE_TILING_OPTIMAL, VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT);
    }
    {
        core->image_count = min(core->sf_caps.minImageCount + 1, core->sf_caps.maxImageCount);
    }

    core->phd = desc.ph_device;
    VkDeviceCreateInfo info = {};
    info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    info.enabledExtensionCount = 1;
    const char *ext_names[] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
    info.ppEnabledExtensionNames = (const char *const *)ext_names;
    VkDeviceQueueCreateInfo queue_info = {};
    queue_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    float priority = 1.0;
    queue_info.pQueuePriorities = &priority;
    queue_info.queueCount = 1;
    queue_info.queueFamilyIndex = desc.graph_queue;
    info.queueCreateInfoCount = 1;
    info.pQueueCreateInfos = &queue_info;
    vkcheck(vkCreateDevice(desc.ph_device, &info, NULL, &core->device));
    log_info("GPU initialized: %s", desc.props.deviceName);
    core->queue_index = desc.graph_queue;
    vkGetDeviceQueue(core->device, core->queue_index, 0, &core->queue);
    list_GpuDesc_destroy(&gpu_descs);
}

void create_allocator(struct ScCore *core)
{
    VmaVulkanFunctions functions = {0};
    functions.vkGetInstanceProcAddr = vkGetInstanceProcAddr;
    functions.vkGetDeviceProcAddr = vkGetDeviceProcAddr;
    VmaAllocatorCreateInfo info = {0};
    info.instance = core->instance;
    info.physicalDevice = core->phd;
    info.device = core->device;
    info.pVulkanFunctions = (const VmaVulkanFunctions *)(&functions);
    info.vulkanApiVersion = core->api_version;
    info.pAllocationCallbacks = NULL;
    vkcheck(vmaCreateAllocator(&info, &core->allocator));
}

void create_swapchain(struct ScCore *core)
{
    VkSwapchainCreateInfoKHR info = vkiSwapchainCreateInfoKHR(core->surface, core->image_count, core->sf_format.format, core->sf_format.colorSpace, core->sf_extent, 1, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT, VK_SHARING_MODE_EXCLUSIVE, 1, &core->queue_index, core->sf_caps.currentTransform, VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR, core->sf_present_mode, VK_TRUE, VK_NULL_HANDLE);
    vkcheck(vkCreateSwapchainKHR(core->device, &info, NULL, &core->swapchain));
}

void create_image_views(struct ScCore *core)
{
    uint32_t count = 0;
    vkcheck(vkGetSwapchainImagesKHR(core->device, core->swapchain, &count, NULL));
    core->simages = list_create(VkImage, count);
    core->sviews = list_create(VkImageView, count);
    core->image_count = count;
    vkcheck(vkGetSwapchainImagesKHR(core->device, core->swapchain, &count, core->simages.data));
    for (uint32_t i = 0; i < count; ++i)
    {
        VkImageViewCreateInfo info = vkiImageViewCreateInfo(core->simages.data[i], VK_IMAGE_VIEW_TYPE_2D, core->sf_format.format, vkiComponentMapping(VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY), vkiImageSubresourceRange(VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1));
        vkcheck(vkCreateImageView(core->device, &info, NULL, &core->sviews.data[i]));
    }
}

void create_presentation_resources(struct ScCore *core)
{
    {
        VkCommandPoolCreateInfo info = vkiCommandPoolCreateInfo(core->queue_index);
        info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
        vkcheck(vkCreateCommandPool(core->device, &info, NULL, &core->cmd_pool));
    }
    {
        core->cmds = list_create(VkCommandBuffer, core->image_count);
        VkCommandBufferAllocateInfo info = vkiCommandBufferAllocateInfo(core->cmd_pool, VK_COMMAND_BUFFER_LEVEL_PRIMARY, core->image_count);
        vkcheck(vkAllocateCommandBuffers(core->device, &info, core->cmds.data));
    }
    {
        core->sem_ima = list_create(VkSemaphore, core->image_count);
        core->sem_ren = list_create(VkSemaphore, core->image_count);
        core->fences = list_create(VkFence, core->image_count);
        VkSemaphoreCreateInfo seminfo = {0};
        seminfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
        VkFenceCreateInfo fenceinfo = {0};
        fenceinfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        fenceinfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;
        for (uint32_t i = 0; i < core->image_count; ++i)
        {
            vkcheck(vkCreateSemaphore(core->device, &seminfo, NULL, &core->sem_ima.data[i]));
            vkcheck(vkCreateSemaphore(core->device, &seminfo, NULL, &core->sem_ren.data[i]));
            vkcheck(vkCreateFence(core->device, &fenceinfo, NULL, &core->fences.data[i]));
        }
    }
    core->current_frame_index = 0;
}

struct ScCore *sc_init_core(const struct ScCoreInfo *core_info)
{
    ram_alloc_init(struct ScCore, core);
    assert_ndbg(core != NULL);
    if (volkInitialize() != VK_SUCCESS)
    {
        log_error("unable to load vulkan API");
        return NULL;
    }
    create_instance(core);
    create_debugger(core);
    create_surface(core, core_info);
    create_device(core, core_info);
    create_allocator(core);
    create_swapchain(core);
    create_image_views(core);
    core->automaton = create_automaton(core->device, core->allocator, core->queue, VK_NULL_HANDLE, VK_NULL_HANDLE, core->queue_index,  0, 0, 1, 0, 0);
    create_presentation_resources(core);
    core->pipeline_ptrs = list_create(ScPipeline_ptr, 0);
    return core;
}

void sc_end_core(struct ScCore *core)
{
    vkDeviceWaitIdle(core->device);

    automaton_flush_cmds(&core->automaton, AUTOMATON_QUEUE_TYPE_GRAPHICS, 0);
    automaton_flush_garbage(&core->automaton);

    list_ScPipeline_ptr_destroy(&core->pipeline_ptrs);

    /// MAIN
    vkDestroyCommandPool(core->device, core->cmd_pool, NULL);
    list_VkCommandBuffer_destroy(&core->cmds);
    for (uint32_t i = 0; i < core->image_count; ++i)
    {
        vkDestroySemaphore(core->device, core->sem_ima.data[i], NULL);
        vkDestroySemaphore(core->device, core->sem_ren.data[i], NULL);
        vkDestroyFence(core->device, core->fences.data[i], NULL);
    }
    list_VkFence_destroy(&core->fences);
    list_VkSemaphore_destroy(&core->sem_ren);
    list_VkSemaphore_destroy(&core->sem_ima);
    destroy_automaton(&core->automaton);
    for_list(i, core->sviews) vkDestroyImageView(core->device, core->sviews.data[i], NULL);
    list_VkImageView_destroy(&core->sviews);
    list_VkImage_destroy(&core->simages);
    vkDestroySwapchainKHR(core->device, core->swapchain, NULL);
    vmaDestroyAllocator(core->allocator);
    vkDestroyDevice(core->device, NULL);
    vkDestroySurfaceKHR(core->instance, core->surface, NULL);
#ifndef NDEBUG
    if (core->debugger_actually_enabled) core->vkDestroyDebugUtilsMessengerEXT(core->instance, core->debug_utils_msg, NULL);
#endif // NDEBUG
    vkDestroyInstance(core->instance, NULL);
    volkFinalize();
    ram_free(core);
    if (trk_trace(trace_fn) != 0)
    {
        log_error("failed to trace the tracker");
        return;
    }
}

void sc_update_core(struct ScCore *core)
{
    for_list(i, core->pipeline_ptrs)
    {
        core->pipeline_ptrs.data[i]->update_fn(core->pipeline_ptrs.data[i]);
    }

    automaton_flush_cmds(&core->automaton, AUTOMATON_QUEUE_TYPE_GRAPHICS, 0);
    automaton_flush_garbage(&core->automaton);

    vkcheck(vkWaitForFences(core->device, 1, &core->fences.data[core->current_frame_index], VK_TRUE, UINT64_MAX));
    vkcheck(vkResetFences(core->device, 1, &core->fences.data[core->current_frame_index]));
    uint32_t image_index;
    vkAcquireNextImageKHR(core->device, core->swapchain, UINT64_MAX, core->sem_ima.data[core->current_frame_index], VK_NULL_HANDLE, &image_index);

    vkResetCommandBuffer(core->cmds.data[core->current_frame_index], /*VkCommandBufferResetFlagBits*/ 0);
    VkCommandBufferBeginInfo begin_info = vkiCommandBufferBeginInfo_null();
    vkcheck(vkBeginCommandBuffer(core->cmds.data[core->current_frame_index], &begin_info));
    for_list(i, core->pipeline_ptrs)
    {
        core->pipeline_ptrs.data[i]->record_cmd_fn(core->pipeline_ptrs.data[i], core->cmds.data[core->current_frame_index], image_index);
    }
    vkcheck(vkEndCommandBuffer(core->cmds.data[core->current_frame_index]));

    VkSemaphore wait_sems[] = {core->sem_ima.data[core->current_frame_index]};
    VkPipelineStageFlags wait_stages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
    VkSemaphore signal_sems[] = {core->sem_ren.data[core->current_frame_index]};

    VkSubmitInfo submit_info = vkiSubmitInfo(1, wait_sems, wait_stages, 1, &core->cmds.data[core->current_frame_index], 1, signal_sems);
    submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    vkcheck(vkQueueSubmit(core->queue, 1, &submit_info, core->fences.data[core->current_frame_index]));

    VkSwapchainKHR swapchains[] = {core->swapchain};
    VkPresentInfoKHR present_info = vkiPresentInfoKHR(1, signal_sems, 1, swapchains, &image_index, NULL);
    vkcheck(vkQueuePresentKHR(core->queue, &present_info));

    core->current_frame_index = (core->current_frame_index + 1) % core->image_count;
}

void sc_attach_pipeline(struct ScCore *core, struct ScPipeline *pipeline)
{
    for_list(i, core->pipeline_ptrs)
    {
        if (core->pipeline_ptrs.data[i] == pipeline)
        {
            log_warn("pipeline %p already attached", pipeline);
            return;
        }
    }
    list_ScPipeline_ptr_append(&core->pipeline_ptrs, &pipeline);
}

void sc_detach_pipeline(struct ScCore *core, struct ScPipeline *pipeline)
{
    size_t i = list_ScPipeline_ptr_find(&core->pipeline_ptrs, &pipeline);
    if (i == SIZE_MAX)
    {
        log_warn("unable to detach pipeline %p", pipeline);
        return;
    }
    list_ScPipeline_ptr_remove(&core->pipeline_ptrs, i);
}
