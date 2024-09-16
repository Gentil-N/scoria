#ifndef __VKI_H__
#define __VKI_H__

#include <vulkan/vulkan_core.h>

#ifdef __cplusplus
extern "C"
{
#endif

	static inline VkExtent2D vkiExtent2D_null()
	{
		VkExtent2D init = {0};
		return init;
	}

	static inline VkExtent2D vkiExtent2D(uint32_t width, uint32_t height)
	{
		VkExtent2D init = vkiExtent2D_null();
		init.width = width;
		init.height = height;
		return init;
	}

	static inline VkExtent3D vkiExtent3D_null()
	{
		VkExtent3D init = {0};
		return init;
	}

	static inline VkExtent3D vkiExtent3D(uint32_t width, uint32_t height, uint32_t depth)
	{
		VkExtent3D init = vkiExtent3D_null();
		init.width = width;
		init.height = height;
		init.depth = depth;
		return init;
	}

	static inline VkOffset2D vkiOffset2D_null()
	{
		VkOffset2D init = {0};
		return init;
	}

	static inline VkOffset2D vkiOffset2D(int32_t x, int32_t y)
	{
		VkOffset2D init = vkiOffset2D_null();
		init.x = x;
		init.y = y;
		return init;
	}

	static inline VkOffset3D vkiOffset3D_null()
	{
		VkOffset3D init = {0};
		return init;
	}

	static inline VkOffset3D vkiOffset3D(int32_t x, int32_t y, int32_t z)
	{
		VkOffset3D init = vkiOffset3D_null();
		init.x = x;
		init.y = y;
		init.z = z;
		return init;
	}

	static inline VkRect2D vkiRect2D_null()
	{
		VkRect2D init = {0};
		return init;
	}

	static inline VkRect2D vkiRect2D(VkOffset2D offset, VkExtent2D extent)
	{
		VkRect2D init = vkiRect2D_null();
		init.offset = offset;
		init.extent = extent;
		return init;
	}

	static inline VkBufferMemoryBarrier vkiBufferMemoryBarrier_null()
	{
		VkBufferMemoryBarrier init = {0};
		init.sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
		return init;
	}

	static inline VkBufferMemoryBarrier vkiBufferMemoryBarrier(VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask, uint32_t srcQueueFamilyIndex, uint32_t dstQueueFamilyIndex, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size)
	{
		VkBufferMemoryBarrier init = vkiBufferMemoryBarrier_null();
		init.srcAccessMask = srcAccessMask;
		init.dstAccessMask = dstAccessMask;
		init.srcQueueFamilyIndex = srcQueueFamilyIndex;
		init.dstQueueFamilyIndex = dstQueueFamilyIndex;
		init.buffer = buffer;
		init.offset = offset;
		init.size = size;
		return init;
	}

	static inline VkDispatchIndirectCommand vkiDispatchIndirectCommand_null()
	{
		VkDispatchIndirectCommand init = {0};
		return init;
	}

	static inline VkDispatchIndirectCommand vkiDispatchIndirectCommand(uint32_t x, uint32_t y, uint32_t z)
	{
		VkDispatchIndirectCommand init = vkiDispatchIndirectCommand_null();
		init.x = x;
		init.y = y;
		init.z = z;
		return init;
	}

	static inline VkDrawIndexedIndirectCommand vkiDrawIndexedIndirectCommand_null()
	{
		VkDrawIndexedIndirectCommand init = {0};
		return init;
	}

	static inline VkDrawIndexedIndirectCommand vkiDrawIndexedIndirectCommand(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance)
	{
		VkDrawIndexedIndirectCommand init = vkiDrawIndexedIndirectCommand_null();
		init.indexCount = indexCount;
		init.instanceCount = instanceCount;
		init.firstIndex = firstIndex;
		init.vertexOffset = vertexOffset;
		init.firstInstance = firstInstance;
		return init;
	}

	static inline VkDrawIndirectCommand vkiDrawIndirectCommand_null()
	{
		VkDrawIndirectCommand init = {0};
		return init;
	}

	static inline VkDrawIndirectCommand vkiDrawIndirectCommand(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)
	{
		VkDrawIndirectCommand init = vkiDrawIndirectCommand_null();
		init.vertexCount = vertexCount;
		init.instanceCount = instanceCount;
		init.firstVertex = firstVertex;
		init.firstInstance = firstInstance;
		return init;
	}

	static inline VkImageSubresourceRange vkiImageSubresourceRange_null()
	{
		VkImageSubresourceRange init = {0};
		return init;
	}

	static inline VkImageSubresourceRange vkiImageSubresourceRange(VkImageAspectFlags aspectMask, uint32_t baseMipLevel, uint32_t levelCount, uint32_t baseArrayLayer, uint32_t layerCount)
	{
		VkImageSubresourceRange init = vkiImageSubresourceRange_null();
		init.aspectMask = aspectMask;
		init.baseMipLevel = baseMipLevel;
		init.levelCount = levelCount;
		init.baseArrayLayer = baseArrayLayer;
		init.layerCount = layerCount;
		return init;
	}

	static inline VkImageMemoryBarrier vkiImageMemoryBarrier_null()
	{
		VkImageMemoryBarrier init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
		return init;
	}

	static inline VkImageMemoryBarrier vkiImageMemoryBarrier(VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t srcQueueFamilyIndex, uint32_t dstQueueFamilyIndex, VkImage image, VkImageSubresourceRange subresourceRange)
	{
		VkImageMemoryBarrier init = vkiImageMemoryBarrier_null();
		init.srcAccessMask = srcAccessMask;
		init.dstAccessMask = dstAccessMask;
		init.oldLayout = oldLayout;
		init.newLayout = newLayout;
		init.srcQueueFamilyIndex = srcQueueFamilyIndex;
		init.dstQueueFamilyIndex = dstQueueFamilyIndex;
		init.image = image;
		init.subresourceRange = subresourceRange;
		return init;
	}

	static inline VkMemoryBarrier vkiMemoryBarrier_null()
	{
		VkMemoryBarrier init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
		return init;
	}

	static inline VkMemoryBarrier vkiMemoryBarrier(VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask)
	{
		VkMemoryBarrier init = vkiMemoryBarrier_null();
		init.srcAccessMask = srcAccessMask;
		init.dstAccessMask = dstAccessMask;
		return init;
	}

	static inline VkPipelineCacheHeaderVersionOne vkiPipelineCacheHeaderVersionOne_null()
	{
		VkPipelineCacheHeaderVersionOne init = {0};
		return init;
	}

	static inline VkPipelineCacheHeaderVersionOne vkiPipelineCacheHeaderVersionOne(uint32_t headerSize, VkPipelineCacheHeaderVersion headerVersion, uint32_t vendorID, uint32_t deviceID)
	{
		VkPipelineCacheHeaderVersionOne init = vkiPipelineCacheHeaderVersionOne_null();
		init.headerSize = headerSize;
		init.headerVersion = headerVersion;
		init.vendorID = vendorID;
		init.deviceID = deviceID;
		return init;
	}

	static inline VkAllocationCallbacks vkiAllocationCallbacks_null()
	{
		VkAllocationCallbacks init = {0};
		return init;
	}

	static inline VkAllocationCallbacks vkiAllocationCallbacks(void *pUserData, PFN_vkAllocationFunction pfnAllocation, PFN_vkReallocationFunction pfnReallocation, PFN_vkFreeFunction pfnFree, PFN_vkInternalAllocationNotification pfnInternalAllocation, PFN_vkInternalFreeNotification pfnInternalFree)
	{
		VkAllocationCallbacks init = vkiAllocationCallbacks_null();
		init.pUserData = pUserData;
		init.pfnAllocation = pfnAllocation;
		init.pfnReallocation = pfnReallocation;
		init.pfnFree = pfnFree;
		init.pfnInternalAllocation = pfnInternalAllocation;
		init.pfnInternalFree = pfnInternalFree;
		return init;
	}

	static inline VkApplicationInfo vkiApplicationInfo_null()
	{
		VkApplicationInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		return init;
	}

	static inline VkApplicationInfo vkiApplicationInfo(const char *pApplicationName, uint32_t applicationVersion, const char *pEngineName, uint32_t engineVersion, uint32_t apiVersion)
	{
		VkApplicationInfo init = vkiApplicationInfo_null();
		init.pApplicationName = pApplicationName;
		init.applicationVersion = applicationVersion;
		init.pEngineName = pEngineName;
		init.engineVersion = engineVersion;
		init.apiVersion = apiVersion;
		return init;
	}

	static inline VkFormatProperties vkiFormatProperties_null()
	{
		VkFormatProperties init = {0};
		return init;
	}

	static inline VkFormatProperties vkiFormatProperties(VkFormatFeatureFlags linearTilingFeatures, VkFormatFeatureFlags optimalTilingFeatures, VkFormatFeatureFlags bufferFeatures)
	{
		VkFormatProperties init = vkiFormatProperties_null();
		init.linearTilingFeatures = linearTilingFeatures;
		init.optimalTilingFeatures = optimalTilingFeatures;
		init.bufferFeatures = bufferFeatures;
		return init;
	}

	static inline VkImageFormatProperties vkiImageFormatProperties_null()
	{
		VkImageFormatProperties init = {0};
		return init;
	}

	static inline VkImageFormatProperties vkiImageFormatProperties(VkExtent3D maxExtent, uint32_t maxMipLevels, uint32_t maxArrayLayers, VkSampleCountFlags sampleCounts, VkDeviceSize maxResourceSize)
	{
		VkImageFormatProperties init = vkiImageFormatProperties_null();
		init.maxExtent = maxExtent;
		init.maxMipLevels = maxMipLevels;
		init.maxArrayLayers = maxArrayLayers;
		init.sampleCounts = sampleCounts;
		init.maxResourceSize = maxResourceSize;
		return init;
	}

	static inline VkInstanceCreateInfo vkiInstanceCreateInfo_null()
	{
		VkInstanceCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		return init;
	}

	static inline VkInstanceCreateInfo vkiInstanceCreateInfo(const VkApplicationInfo *pApplicationInfo, uint32_t enabledLayerCount, const char *const *ppEnabledLayerNames, uint32_t enabledExtensionCount, const char *const *ppEnabledExtensionNames)
	{
		VkInstanceCreateInfo init = vkiInstanceCreateInfo_null();
		init.pApplicationInfo = pApplicationInfo;
		init.enabledLayerCount = enabledLayerCount;
		init.ppEnabledLayerNames = ppEnabledLayerNames;
		init.enabledExtensionCount = enabledExtensionCount;
		init.ppEnabledExtensionNames = ppEnabledExtensionNames;
		return init;
	}

	static inline VkMemoryHeap vkiMemoryHeap_null()
	{
		VkMemoryHeap init = {0};
		return init;
	}

	static inline VkMemoryHeap vkiMemoryHeap(VkDeviceSize size)
	{
		VkMemoryHeap init = vkiMemoryHeap_null();
		init.size = size;
		return init;
	}

	static inline VkMemoryType vkiMemoryType_null()
	{
		VkMemoryType init = {0};
		return init;
	}

	static inline VkMemoryType vkiMemoryType(VkMemoryPropertyFlags propertyFlags, uint32_t heapIndex)
	{
		VkMemoryType init = vkiMemoryType_null();
		init.propertyFlags = propertyFlags;
		init.heapIndex = heapIndex;
		return init;
	}

	static inline VkPhysicalDeviceFeatures vkiPhysicalDeviceFeatures_null()
	{
		VkPhysicalDeviceFeatures init = {0};
		return init;
	}

	static inline VkPhysicalDeviceFeatures vkiPhysicalDeviceFeatures(VkBool32 robustBufferAccess, VkBool32 fullDrawIndexUint32, VkBool32 imageCubeArray, VkBool32 independentBlend, VkBool32 geometryShader, VkBool32 tessellationShader, VkBool32 sampleRateShading, VkBool32 dualSrcBlend, VkBool32 logicOp, VkBool32 multiDrawIndirect, VkBool32 drawIndirectFirstInstance, VkBool32 depthClamp, VkBool32 depthBiasClamp, VkBool32 fillModeNonSolid, VkBool32 depthBounds, VkBool32 wideLines, VkBool32 largePoints, VkBool32 alphaToOne, VkBool32 multiViewport, VkBool32 samplerAnisotropy, VkBool32 textureCompressionETC2, VkBool32 textureCompressionASTC_LDR, VkBool32 textureCompressionBC, VkBool32 occlusionQueryPrecise, VkBool32 pipelineStatisticsQuery, VkBool32 vertexPipelineStoresAndAtomics, VkBool32 fragmentStoresAndAtomics, VkBool32 shaderTessellationAndGeometryPointSize, VkBool32 shaderImageGatherExtended, VkBool32 shaderStorageImageExtendedFormats, VkBool32 shaderStorageImageMultisample, VkBool32 shaderStorageImageReadWithoutFormat, VkBool32 shaderStorageImageWriteWithoutFormat, VkBool32 shaderUniformBufferArrayDynamicIndexing, VkBool32 shaderSampledImageArrayDynamicIndexing, VkBool32 shaderStorageBufferArrayDynamicIndexing, VkBool32 shaderStorageImageArrayDynamicIndexing, VkBool32 shaderClipDistance, VkBool32 shaderCullDistance, VkBool32 shaderFloat64, VkBool32 shaderInt64, VkBool32 shaderInt16, VkBool32 shaderResourceResidency, VkBool32 shaderResourceMinLod, VkBool32 sparseBinding, VkBool32 sparseResidencyBuffer, VkBool32 sparseResidencyImage2D, VkBool32 sparseResidencyImage3D, VkBool32 sparseResidency2Samples, VkBool32 sparseResidency4Samples, VkBool32 sparseResidency8Samples, VkBool32 sparseResidency16Samples, VkBool32 sparseResidencyAliased, VkBool32 variableMultisampleRate, VkBool32 inheritedQueries)
	{
		VkPhysicalDeviceFeatures init = vkiPhysicalDeviceFeatures_null();
		init.robustBufferAccess = robustBufferAccess;
		init.fullDrawIndexUint32 = fullDrawIndexUint32;
		init.imageCubeArray = imageCubeArray;
		init.independentBlend = independentBlend;
		init.geometryShader = geometryShader;
		init.tessellationShader = tessellationShader;
		init.sampleRateShading = sampleRateShading;
		init.dualSrcBlend = dualSrcBlend;
		init.logicOp = logicOp;
		init.multiDrawIndirect = multiDrawIndirect;
		init.drawIndirectFirstInstance = drawIndirectFirstInstance;
		init.depthClamp = depthClamp;
		init.depthBiasClamp = depthBiasClamp;
		init.fillModeNonSolid = fillModeNonSolid;
		init.depthBounds = depthBounds;
		init.wideLines = wideLines;
		init.largePoints = largePoints;
		init.alphaToOne = alphaToOne;
		init.multiViewport = multiViewport;
		init.samplerAnisotropy = samplerAnisotropy;
		init.textureCompressionETC2 = textureCompressionETC2;
		init.textureCompressionASTC_LDR = textureCompressionASTC_LDR;
		init.textureCompressionBC = textureCompressionBC;
		init.occlusionQueryPrecise = occlusionQueryPrecise;
		init.pipelineStatisticsQuery = pipelineStatisticsQuery;
		init.vertexPipelineStoresAndAtomics = vertexPipelineStoresAndAtomics;
		init.fragmentStoresAndAtomics = fragmentStoresAndAtomics;
		init.shaderTessellationAndGeometryPointSize = shaderTessellationAndGeometryPointSize;
		init.shaderImageGatherExtended = shaderImageGatherExtended;
		init.shaderStorageImageExtendedFormats = shaderStorageImageExtendedFormats;
		init.shaderStorageImageMultisample = shaderStorageImageMultisample;
		init.shaderStorageImageReadWithoutFormat = shaderStorageImageReadWithoutFormat;
		init.shaderStorageImageWriteWithoutFormat = shaderStorageImageWriteWithoutFormat;
		init.shaderUniformBufferArrayDynamicIndexing = shaderUniformBufferArrayDynamicIndexing;
		init.shaderSampledImageArrayDynamicIndexing = shaderSampledImageArrayDynamicIndexing;
		init.shaderStorageBufferArrayDynamicIndexing = shaderStorageBufferArrayDynamicIndexing;
		init.shaderStorageImageArrayDynamicIndexing = shaderStorageImageArrayDynamicIndexing;
		init.shaderClipDistance = shaderClipDistance;
		init.shaderCullDistance = shaderCullDistance;
		init.shaderFloat64 = shaderFloat64;
		init.shaderInt64 = shaderInt64;
		init.shaderInt16 = shaderInt16;
		init.shaderResourceResidency = shaderResourceResidency;
		init.shaderResourceMinLod = shaderResourceMinLod;
		init.sparseBinding = sparseBinding;
		init.sparseResidencyBuffer = sparseResidencyBuffer;
		init.sparseResidencyImage2D = sparseResidencyImage2D;
		init.sparseResidencyImage3D = sparseResidencyImage3D;
		init.sparseResidency2Samples = sparseResidency2Samples;
		init.sparseResidency4Samples = sparseResidency4Samples;
		init.sparseResidency8Samples = sparseResidency8Samples;
		init.sparseResidency16Samples = sparseResidency16Samples;
		init.sparseResidencyAliased = sparseResidencyAliased;
		init.variableMultisampleRate = variableMultisampleRate;
		init.inheritedQueries = inheritedQueries;
		return init;
	}

	static inline VkPhysicalDeviceLimits vkiPhysicalDeviceLimits_null()
	{
		VkPhysicalDeviceLimits init = {0};
		return init;
	}

	static inline VkPhysicalDeviceLimits vkiPhysicalDeviceLimits(uint32_t maxImageDimension1D, uint32_t maxImageDimension2D, uint32_t maxImageDimension3D, uint32_t maxImageDimensionCube, uint32_t maxImageArrayLayers, uint32_t maxTexelBufferElements, uint32_t maxUniformBufferRange, uint32_t maxStorageBufferRange, uint32_t maxPushConstantsSize, uint32_t maxMemoryAllocationCount, uint32_t maxSamplerAllocationCount, VkDeviceSize bufferImageGranularity, VkDeviceSize sparseAddressSpaceSize, uint32_t maxBoundDescriptorSets, uint32_t maxPerStageDescriptorSamplers, uint32_t maxPerStageDescriptorUniformBuffers, uint32_t maxPerStageDescriptorStorageBuffers, uint32_t maxPerStageDescriptorSampledImages, uint32_t maxPerStageDescriptorStorageImages, uint32_t maxPerStageDescriptorInputAttachments, uint32_t maxPerStageResources, uint32_t maxDescriptorSetSamplers, uint32_t maxDescriptorSetUniformBuffers, uint32_t maxDescriptorSetUniformBuffersDynamic, uint32_t maxDescriptorSetStorageBuffers, uint32_t maxDescriptorSetStorageBuffersDynamic, uint32_t maxDescriptorSetSampledImages, uint32_t maxDescriptorSetStorageImages, uint32_t maxDescriptorSetInputAttachments, uint32_t maxVertexInputAttributes, uint32_t maxVertexInputBindings, uint32_t maxVertexInputAttributeOffset, uint32_t maxVertexInputBindingStride, uint32_t maxVertexOutputComponents, uint32_t maxTessellationGenerationLevel, uint32_t maxTessellationPatchSize, uint32_t maxTessellationControlPerVertexInputComponents, uint32_t maxTessellationControlPerVertexOutputComponents, uint32_t maxTessellationControlPerPatchOutputComponents, uint32_t maxTessellationControlTotalOutputComponents, uint32_t maxTessellationEvaluationInputComponents, uint32_t maxTessellationEvaluationOutputComponents, uint32_t maxGeometryShaderInvocations, uint32_t maxGeometryInputComponents, uint32_t maxGeometryOutputComponents, uint32_t maxGeometryOutputVertices, uint32_t maxGeometryTotalOutputComponents, uint32_t maxFragmentInputComponents, uint32_t maxFragmentOutputAttachments, uint32_t maxFragmentDualSrcAttachments, uint32_t maxFragmentCombinedOutputResources, uint32_t maxComputeSharedMemorySize, uint32_t maxComputeWorkGroupInvocations, uint32_t subPixelPrecisionBits, uint32_t subTexelPrecisionBits, uint32_t mipmapPrecisionBits, uint32_t maxDrawIndexedIndexValue, uint32_t maxDrawIndirectCount, float maxSamplerLodBias, float maxSamplerAnisotropy, uint32_t maxViewports, uint32_t viewportSubPixelBits, size_t minMemoryMapAlignment, VkDeviceSize minTexelBufferOffsetAlignment, VkDeviceSize minUniformBufferOffsetAlignment, VkDeviceSize minStorageBufferOffsetAlignment, int32_t minTexelOffset, uint32_t maxTexelOffset, int32_t minTexelGatherOffset, uint32_t maxTexelGatherOffset, float minInterpolationOffset, float maxInterpolationOffset, uint32_t subPixelInterpolationOffsetBits, uint32_t maxFramebufferWidth, uint32_t maxFramebufferHeight, uint32_t maxFramebufferLayers, VkSampleCountFlags framebufferColorSampleCounts, VkSampleCountFlags framebufferDepthSampleCounts, VkSampleCountFlags framebufferStencilSampleCounts, VkSampleCountFlags framebufferNoAttachmentsSampleCounts, uint32_t maxColorAttachments, VkSampleCountFlags sampledImageColorSampleCounts, VkSampleCountFlags sampledImageIntegerSampleCounts, VkSampleCountFlags sampledImageDepthSampleCounts, VkSampleCountFlags sampledImageStencilSampleCounts, VkSampleCountFlags storageImageSampleCounts, uint32_t maxSampleMaskWords, VkBool32 timestampComputeAndGraphics, float timestampPeriod, uint32_t maxClipDistances, uint32_t maxCullDistances, uint32_t maxCombinedClipAndCullDistances, uint32_t discreteQueuePriorities, float pointSizeGranularity, float lineWidthGranularity, VkBool32 strictLines, VkBool32 standardSampleLocations, VkDeviceSize optimalBufferCopyOffsetAlignment, VkDeviceSize optimalBufferCopyRowPitchAlignment, VkDeviceSize nonCoherentAtomSize)
	{
		VkPhysicalDeviceLimits init = vkiPhysicalDeviceLimits_null();
		init.maxImageDimension1D = maxImageDimension1D;
		init.maxImageDimension2D = maxImageDimension2D;
		init.maxImageDimension3D = maxImageDimension3D;
		init.maxImageDimensionCube = maxImageDimensionCube;
		init.maxImageArrayLayers = maxImageArrayLayers;
		init.maxTexelBufferElements = maxTexelBufferElements;
		init.maxUniformBufferRange = maxUniformBufferRange;
		init.maxStorageBufferRange = maxStorageBufferRange;
		init.maxPushConstantsSize = maxPushConstantsSize;
		init.maxMemoryAllocationCount = maxMemoryAllocationCount;
		init.maxSamplerAllocationCount = maxSamplerAllocationCount;
		init.bufferImageGranularity = bufferImageGranularity;
		init.sparseAddressSpaceSize = sparseAddressSpaceSize;
		init.maxBoundDescriptorSets = maxBoundDescriptorSets;
		init.maxPerStageDescriptorSamplers = maxPerStageDescriptorSamplers;
		init.maxPerStageDescriptorUniformBuffers = maxPerStageDescriptorUniformBuffers;
		init.maxPerStageDescriptorStorageBuffers = maxPerStageDescriptorStorageBuffers;
		init.maxPerStageDescriptorSampledImages = maxPerStageDescriptorSampledImages;
		init.maxPerStageDescriptorStorageImages = maxPerStageDescriptorStorageImages;
		init.maxPerStageDescriptorInputAttachments = maxPerStageDescriptorInputAttachments;
		init.maxPerStageResources = maxPerStageResources;
		init.maxDescriptorSetSamplers = maxDescriptorSetSamplers;
		init.maxDescriptorSetUniformBuffers = maxDescriptorSetUniformBuffers;
		init.maxDescriptorSetUniformBuffersDynamic = maxDescriptorSetUniformBuffersDynamic;
		init.maxDescriptorSetStorageBuffers = maxDescriptorSetStorageBuffers;
		init.maxDescriptorSetStorageBuffersDynamic = maxDescriptorSetStorageBuffersDynamic;
		init.maxDescriptorSetSampledImages = maxDescriptorSetSampledImages;
		init.maxDescriptorSetStorageImages = maxDescriptorSetStorageImages;
		init.maxDescriptorSetInputAttachments = maxDescriptorSetInputAttachments;
		init.maxVertexInputAttributes = maxVertexInputAttributes;
		init.maxVertexInputBindings = maxVertexInputBindings;
		init.maxVertexInputAttributeOffset = maxVertexInputAttributeOffset;
		init.maxVertexInputBindingStride = maxVertexInputBindingStride;
		init.maxVertexOutputComponents = maxVertexOutputComponents;
		init.maxTessellationGenerationLevel = maxTessellationGenerationLevel;
		init.maxTessellationPatchSize = maxTessellationPatchSize;
		init.maxTessellationControlPerVertexInputComponents = maxTessellationControlPerVertexInputComponents;
		init.maxTessellationControlPerVertexOutputComponents = maxTessellationControlPerVertexOutputComponents;
		init.maxTessellationControlPerPatchOutputComponents = maxTessellationControlPerPatchOutputComponents;
		init.maxTessellationControlTotalOutputComponents = maxTessellationControlTotalOutputComponents;
		init.maxTessellationEvaluationInputComponents = maxTessellationEvaluationInputComponents;
		init.maxTessellationEvaluationOutputComponents = maxTessellationEvaluationOutputComponents;
		init.maxGeometryShaderInvocations = maxGeometryShaderInvocations;
		init.maxGeometryInputComponents = maxGeometryInputComponents;
		init.maxGeometryOutputComponents = maxGeometryOutputComponents;
		init.maxGeometryOutputVertices = maxGeometryOutputVertices;
		init.maxGeometryTotalOutputComponents = maxGeometryTotalOutputComponents;
		init.maxFragmentInputComponents = maxFragmentInputComponents;
		init.maxFragmentOutputAttachments = maxFragmentOutputAttachments;
		init.maxFragmentDualSrcAttachments = maxFragmentDualSrcAttachments;
		init.maxFragmentCombinedOutputResources = maxFragmentCombinedOutputResources;
		init.maxComputeSharedMemorySize = maxComputeSharedMemorySize;
		init.maxComputeWorkGroupInvocations = maxComputeWorkGroupInvocations;
		init.subPixelPrecisionBits = subPixelPrecisionBits;
		init.subTexelPrecisionBits = subTexelPrecisionBits;
		init.mipmapPrecisionBits = mipmapPrecisionBits;
		init.maxDrawIndexedIndexValue = maxDrawIndexedIndexValue;
		init.maxDrawIndirectCount = maxDrawIndirectCount;
		init.maxSamplerLodBias = maxSamplerLodBias;
		init.maxSamplerAnisotropy = maxSamplerAnisotropy;
		init.maxViewports = maxViewports;
		init.viewportSubPixelBits = viewportSubPixelBits;
		init.minMemoryMapAlignment = minMemoryMapAlignment;
		init.minTexelBufferOffsetAlignment = minTexelBufferOffsetAlignment;
		init.minUniformBufferOffsetAlignment = minUniformBufferOffsetAlignment;
		init.minStorageBufferOffsetAlignment = minStorageBufferOffsetAlignment;
		init.minTexelOffset = minTexelOffset;
		init.maxTexelOffset = maxTexelOffset;
		init.minTexelGatherOffset = minTexelGatherOffset;
		init.maxTexelGatherOffset = maxTexelGatherOffset;
		init.minInterpolationOffset = minInterpolationOffset;
		init.maxInterpolationOffset = maxInterpolationOffset;
		init.subPixelInterpolationOffsetBits = subPixelInterpolationOffsetBits;
		init.maxFramebufferWidth = maxFramebufferWidth;
		init.maxFramebufferHeight = maxFramebufferHeight;
		init.maxFramebufferLayers = maxFramebufferLayers;
		init.framebufferColorSampleCounts = framebufferColorSampleCounts;
		init.framebufferDepthSampleCounts = framebufferDepthSampleCounts;
		init.framebufferStencilSampleCounts = framebufferStencilSampleCounts;
		init.framebufferNoAttachmentsSampleCounts = framebufferNoAttachmentsSampleCounts;
		init.maxColorAttachments = maxColorAttachments;
		init.sampledImageColorSampleCounts = sampledImageColorSampleCounts;
		init.sampledImageIntegerSampleCounts = sampledImageIntegerSampleCounts;
		init.sampledImageDepthSampleCounts = sampledImageDepthSampleCounts;
		init.sampledImageStencilSampleCounts = sampledImageStencilSampleCounts;
		init.storageImageSampleCounts = storageImageSampleCounts;
		init.maxSampleMaskWords = maxSampleMaskWords;
		init.timestampComputeAndGraphics = timestampComputeAndGraphics;
		init.timestampPeriod = timestampPeriod;
		init.maxClipDistances = maxClipDistances;
		init.maxCullDistances = maxCullDistances;
		init.maxCombinedClipAndCullDistances = maxCombinedClipAndCullDistances;
		init.discreteQueuePriorities = discreteQueuePriorities;
		init.pointSizeGranularity = pointSizeGranularity;
		init.lineWidthGranularity = lineWidthGranularity;
		init.strictLines = strictLines;
		init.standardSampleLocations = standardSampleLocations;
		init.optimalBufferCopyOffsetAlignment = optimalBufferCopyOffsetAlignment;
		init.optimalBufferCopyRowPitchAlignment = optimalBufferCopyRowPitchAlignment;
		init.nonCoherentAtomSize = nonCoherentAtomSize;
		return init;
	}

	static inline VkPhysicalDeviceMemoryProperties vkiPhysicalDeviceMemoryProperties_null()
	{
		VkPhysicalDeviceMemoryProperties init = {0};
		return init;
	}

	static inline VkPhysicalDeviceMemoryProperties vkiPhysicalDeviceMemoryProperties(uint32_t memoryTypeCount, uint32_t memoryHeapCount)
	{
		VkPhysicalDeviceMemoryProperties init = vkiPhysicalDeviceMemoryProperties_null();
		init.memoryTypeCount = memoryTypeCount;
		init.memoryHeapCount = memoryHeapCount;
		return init;
	}

	static inline VkPhysicalDeviceSparseProperties vkiPhysicalDeviceSparseProperties_null()
	{
		VkPhysicalDeviceSparseProperties init = {0};
		return init;
	}

	static inline VkPhysicalDeviceSparseProperties vkiPhysicalDeviceSparseProperties(VkBool32 residencyStandard2DBlockShape, VkBool32 residencyStandard2DMultisampleBlockShape, VkBool32 residencyStandard3DBlockShape, VkBool32 residencyAlignedMipSize, VkBool32 residencyNonResidentStrict)
	{
		VkPhysicalDeviceSparseProperties init = vkiPhysicalDeviceSparseProperties_null();
		init.residencyStandard2DBlockShape = residencyStandard2DBlockShape;
		init.residencyStandard2DMultisampleBlockShape = residencyStandard2DMultisampleBlockShape;
		init.residencyStandard3DBlockShape = residencyStandard3DBlockShape;
		init.residencyAlignedMipSize = residencyAlignedMipSize;
		init.residencyNonResidentStrict = residencyNonResidentStrict;
		return init;
	}

	static inline VkPhysicalDeviceProperties vkiPhysicalDeviceProperties_null()
	{
		VkPhysicalDeviceProperties init = {0};
		return init;
	}

	static inline VkPhysicalDeviceProperties vkiPhysicalDeviceProperties(uint32_t apiVersion, uint32_t driverVersion, uint32_t vendorID, uint32_t deviceID, VkPhysicalDeviceType deviceType, VkPhysicalDeviceLimits limits, VkPhysicalDeviceSparseProperties sparseProperties)
	{
		VkPhysicalDeviceProperties init = vkiPhysicalDeviceProperties_null();
		init.apiVersion = apiVersion;
		init.driverVersion = driverVersion;
		init.vendorID = vendorID;
		init.deviceID = deviceID;
		init.deviceType = deviceType;
		init.limits = limits;
		init.sparseProperties = sparseProperties;
		return init;
	}

	static inline VkQueueFamilyProperties vkiQueueFamilyProperties_null()
	{
		VkQueueFamilyProperties init = {0};
		return init;
	}

	static inline VkQueueFamilyProperties vkiQueueFamilyProperties(VkQueueFlags queueFlags, uint32_t queueCount, uint32_t timestampValidBits, VkExtent3D minImageTransferGranularity)
	{
		VkQueueFamilyProperties init = vkiQueueFamilyProperties_null();
		init.queueFlags = queueFlags;
		init.queueCount = queueCount;
		init.timestampValidBits = timestampValidBits;
		init.minImageTransferGranularity = minImageTransferGranularity;
		return init;
	}

	static inline VkDeviceQueueCreateInfo vkiDeviceQueueCreateInfo_null()
	{
		VkDeviceQueueCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		return init;
	}

	static inline VkDeviceQueueCreateInfo vkiDeviceQueueCreateInfo(uint32_t queueFamilyIndex, uint32_t queueCount, const float *pQueuePriorities)
	{
		VkDeviceQueueCreateInfo init = vkiDeviceQueueCreateInfo_null();
		init.queueFamilyIndex = queueFamilyIndex;
		init.queueCount = queueCount;
		init.pQueuePriorities = pQueuePriorities;
		return init;
	}

	static inline VkDeviceCreateInfo vkiDeviceCreateInfo_null()
	{
		VkDeviceCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		return init;
	}

	static inline VkDeviceCreateInfo vkiDeviceCreateInfo(uint32_t queueCreateInfoCount, const VkDeviceQueueCreateInfo *pQueueCreateInfos, uint32_t enabledLayerCount, const char *const *ppEnabledLayerNames, uint32_t enabledExtensionCount, const char *const *ppEnabledExtensionNames, const VkPhysicalDeviceFeatures *pEnabledFeatures)
	{
		VkDeviceCreateInfo init = vkiDeviceCreateInfo_null();
		init.queueCreateInfoCount = queueCreateInfoCount;
		init.pQueueCreateInfos = pQueueCreateInfos;
		init.enabledLayerCount = enabledLayerCount;
		init.ppEnabledLayerNames = ppEnabledLayerNames;
		init.enabledExtensionCount = enabledExtensionCount;
		init.ppEnabledExtensionNames = ppEnabledExtensionNames;
		init.pEnabledFeatures = pEnabledFeatures;
		return init;
	}

	static inline VkExtensionProperties vkiExtensionProperties_null()
	{
		VkExtensionProperties init = {0};
		return init;
	}

	static inline VkExtensionProperties vkiExtensionProperties(uint32_t specVersion)
	{
		VkExtensionProperties init = vkiExtensionProperties_null();
		init.specVersion = specVersion;
		return init;
	}

	static inline VkLayerProperties vkiLayerProperties_null()
	{
		VkLayerProperties init = {0};
		return init;
	}

	static inline VkLayerProperties vkiLayerProperties(uint32_t specVersion, uint32_t implementationVersion)
	{
		VkLayerProperties init = vkiLayerProperties_null();
		init.specVersion = specVersion;
		init.implementationVersion = implementationVersion;
		return init;
	}

	static inline VkSubmitInfo vkiSubmitInfo_null()
	{
		VkSubmitInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		return init;
	}

	static inline VkSubmitInfo vkiSubmitInfo(uint32_t waitSemaphoreCount, const VkSemaphore *pWaitSemaphores, const VkPipelineStageFlags *pWaitDstStageMask, uint32_t commandBufferCount, const VkCommandBuffer *pCommandBuffers, uint32_t signalSemaphoreCount, const VkSemaphore *pSignalSemaphores)
	{
		VkSubmitInfo init = vkiSubmitInfo_null();
		init.waitSemaphoreCount = waitSemaphoreCount;
		init.pWaitSemaphores = pWaitSemaphores;
		init.pWaitDstStageMask = pWaitDstStageMask;
		init.commandBufferCount = commandBufferCount;
		init.pCommandBuffers = pCommandBuffers;
		init.signalSemaphoreCount = signalSemaphoreCount;
		init.pSignalSemaphores = pSignalSemaphores;
		return init;
	}

	static inline VkMappedMemoryRange vkiMappedMemoryRange_null()
	{
		VkMappedMemoryRange init = {0};
		init.sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
		return init;
	}

	static inline VkMappedMemoryRange vkiMappedMemoryRange(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size)
	{
		VkMappedMemoryRange init = vkiMappedMemoryRange_null();
		init.memory = memory;
		init.offset = offset;
		init.size = size;
		return init;
	}

	static inline VkMemoryAllocateInfo vkiMemoryAllocateInfo_null()
	{
		VkMemoryAllocateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		return init;
	}

	static inline VkMemoryAllocateInfo vkiMemoryAllocateInfo(VkDeviceSize allocationSize, uint32_t memoryTypeIndex)
	{
		VkMemoryAllocateInfo init = vkiMemoryAllocateInfo_null();
		init.allocationSize = allocationSize;
		init.memoryTypeIndex = memoryTypeIndex;
		return init;
	}

	static inline VkMemoryRequirements vkiMemoryRequirements_null()
	{
		VkMemoryRequirements init = {0};
		return init;
	}

	static inline VkMemoryRequirements vkiMemoryRequirements(VkDeviceSize size, VkDeviceSize alignment, uint32_t memoryTypeBits)
	{
		VkMemoryRequirements init = vkiMemoryRequirements_null();
		init.size = size;
		init.alignment = alignment;
		init.memoryTypeBits = memoryTypeBits;
		return init;
	}

	static inline VkSparseMemoryBind vkiSparseMemoryBind_null()
	{
		VkSparseMemoryBind init = {0};
		return init;
	}

	static inline VkSparseMemoryBind vkiSparseMemoryBind(VkDeviceSize resourceOffset, VkDeviceSize size, VkDeviceMemory memory, VkDeviceSize memoryOffset)
	{
		VkSparseMemoryBind init = vkiSparseMemoryBind_null();
		init.resourceOffset = resourceOffset;
		init.size = size;
		init.memory = memory;
		init.memoryOffset = memoryOffset;
		return init;
	}

	static inline VkSparseBufferMemoryBindInfo vkiSparseBufferMemoryBindInfo_null()
	{
		VkSparseBufferMemoryBindInfo init = {0};
		return init;
	}

	static inline VkSparseBufferMemoryBindInfo vkiSparseBufferMemoryBindInfo(VkBuffer buffer, uint32_t bindCount, const VkSparseMemoryBind *pBinds)
	{
		VkSparseBufferMemoryBindInfo init = vkiSparseBufferMemoryBindInfo_null();
		init.buffer = buffer;
		init.bindCount = bindCount;
		init.pBinds = pBinds;
		return init;
	}

	static inline VkSparseImageOpaqueMemoryBindInfo vkiSparseImageOpaqueMemoryBindInfo_null()
	{
		VkSparseImageOpaqueMemoryBindInfo init = {0};
		return init;
	}

	static inline VkSparseImageOpaqueMemoryBindInfo vkiSparseImageOpaqueMemoryBindInfo(VkImage image, uint32_t bindCount, const VkSparseMemoryBind *pBinds)
	{
		VkSparseImageOpaqueMemoryBindInfo init = vkiSparseImageOpaqueMemoryBindInfo_null();
		init.image = image;
		init.bindCount = bindCount;
		init.pBinds = pBinds;
		return init;
	}

	static inline VkImageSubresource vkiImageSubresource_null()
	{
		VkImageSubresource init = {0};
		return init;
	}

	static inline VkImageSubresource vkiImageSubresource(VkImageAspectFlags aspectMask, uint32_t mipLevel, uint32_t arrayLayer)
	{
		VkImageSubresource init = vkiImageSubresource_null();
		init.aspectMask = aspectMask;
		init.mipLevel = mipLevel;
		init.arrayLayer = arrayLayer;
		return init;
	}

	static inline VkSparseImageMemoryBind vkiSparseImageMemoryBind_null()
	{
		VkSparseImageMemoryBind init = {0};
		return init;
	}

	static inline VkSparseImageMemoryBind vkiSparseImageMemoryBind(VkImageSubresource subresource, VkOffset3D offset, VkExtent3D extent, VkDeviceMemory memory, VkDeviceSize memoryOffset)
	{
		VkSparseImageMemoryBind init = vkiSparseImageMemoryBind_null();
		init.subresource = subresource;
		init.offset = offset;
		init.extent = extent;
		init.memory = memory;
		init.memoryOffset = memoryOffset;
		return init;
	}

	static inline VkSparseImageMemoryBindInfo vkiSparseImageMemoryBindInfo_null()
	{
		VkSparseImageMemoryBindInfo init = {0};
		return init;
	}

	static inline VkSparseImageMemoryBindInfo vkiSparseImageMemoryBindInfo(VkImage image, uint32_t bindCount, const VkSparseImageMemoryBind *pBinds)
	{
		VkSparseImageMemoryBindInfo init = vkiSparseImageMemoryBindInfo_null();
		init.image = image;
		init.bindCount = bindCount;
		init.pBinds = pBinds;
		return init;
	}

	static inline VkBindSparseInfo vkiBindSparseInfo_null()
	{
		VkBindSparseInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO;
		return init;
	}

	static inline VkBindSparseInfo vkiBindSparseInfo(uint32_t waitSemaphoreCount, const VkSemaphore *pWaitSemaphores, uint32_t bufferBindCount, const VkSparseBufferMemoryBindInfo *pBufferBinds, uint32_t imageOpaqueBindCount, const VkSparseImageOpaqueMemoryBindInfo *pImageOpaqueBinds, uint32_t imageBindCount, const VkSparseImageMemoryBindInfo *pImageBinds, uint32_t signalSemaphoreCount, const VkSemaphore *pSignalSemaphores)
	{
		VkBindSparseInfo init = vkiBindSparseInfo_null();
		init.waitSemaphoreCount = waitSemaphoreCount;
		init.pWaitSemaphores = pWaitSemaphores;
		init.bufferBindCount = bufferBindCount;
		init.pBufferBinds = pBufferBinds;
		init.imageOpaqueBindCount = imageOpaqueBindCount;
		init.pImageOpaqueBinds = pImageOpaqueBinds;
		init.imageBindCount = imageBindCount;
		init.pImageBinds = pImageBinds;
		init.signalSemaphoreCount = signalSemaphoreCount;
		init.pSignalSemaphores = pSignalSemaphores;
		return init;
	}

	static inline VkSparseImageFormatProperties vkiSparseImageFormatProperties_null()
	{
		VkSparseImageFormatProperties init = {0};
		return init;
	}

	static inline VkSparseImageFormatProperties vkiSparseImageFormatProperties(VkImageAspectFlags aspectMask, VkExtent3D imageGranularity)
	{
		VkSparseImageFormatProperties init = vkiSparseImageFormatProperties_null();
		init.aspectMask = aspectMask;
		init.imageGranularity = imageGranularity;
		return init;
	}

	static inline VkSparseImageMemoryRequirements vkiSparseImageMemoryRequirements_null()
	{
		VkSparseImageMemoryRequirements init = {0};
		return init;
	}

	static inline VkSparseImageMemoryRequirements vkiSparseImageMemoryRequirements(VkSparseImageFormatProperties formatProperties, uint32_t imageMipTailFirstLod, VkDeviceSize imageMipTailSize, VkDeviceSize imageMipTailOffset, VkDeviceSize imageMipTailStride)
	{
		VkSparseImageMemoryRequirements init = vkiSparseImageMemoryRequirements_null();
		init.formatProperties = formatProperties;
		init.imageMipTailFirstLod = imageMipTailFirstLod;
		init.imageMipTailSize = imageMipTailSize;
		init.imageMipTailOffset = imageMipTailOffset;
		init.imageMipTailStride = imageMipTailStride;
		return init;
	}

	static inline VkFenceCreateInfo vkiFenceCreateInfo_null()
	{
		VkFenceCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
		return init;
	}

	static inline VkFenceCreateInfo vkiFenceCreateInfo()
	{
		VkFenceCreateInfo init = vkiFenceCreateInfo_null();
		return init;
	}

	static inline VkSemaphoreCreateInfo vkiSemaphoreCreateInfo_null()
	{
		VkSemaphoreCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
		return init;
	}

	static inline VkSemaphoreCreateInfo vkiSemaphoreCreateInfo()
	{
		VkSemaphoreCreateInfo init = vkiSemaphoreCreateInfo_null();
		return init;
	}

	static inline VkEventCreateInfo vkiEventCreateInfo_null()
	{
		VkEventCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;
		return init;
	}

	static inline VkEventCreateInfo vkiEventCreateInfo()
	{
		VkEventCreateInfo init = vkiEventCreateInfo_null();
		return init;
	}

	static inline VkQueryPoolCreateInfo vkiQueryPoolCreateInfo_null()
	{
		VkQueryPoolCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO;
		return init;
	}

	static inline VkQueryPoolCreateInfo vkiQueryPoolCreateInfo(VkQueryType queryType, uint32_t queryCount, VkQueryPipelineStatisticFlags pipelineStatistics)
	{
		VkQueryPoolCreateInfo init = vkiQueryPoolCreateInfo_null();
		init.queryType = queryType;
		init.queryCount = queryCount;
		init.pipelineStatistics = pipelineStatistics;
		return init;
	}

	static inline VkBufferCreateInfo vkiBufferCreateInfo_null()
	{
		VkBufferCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		return init;
	}

	static inline VkBufferCreateInfo vkiBufferCreateInfo(VkDeviceSize size, VkBufferUsageFlags usage, VkSharingMode sharingMode, uint32_t queueFamilyIndexCount, const uint32_t *pQueueFamilyIndices)
	{
		VkBufferCreateInfo init = vkiBufferCreateInfo_null();
		init.size = size;
		init.usage = usage;
		init.sharingMode = sharingMode;
		init.queueFamilyIndexCount = queueFamilyIndexCount;
		init.pQueueFamilyIndices = pQueueFamilyIndices;
		return init;
	}

	static inline VkBufferViewCreateInfo vkiBufferViewCreateInfo_null()
	{
		VkBufferViewCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO;
		return init;
	}

	static inline VkBufferViewCreateInfo vkiBufferViewCreateInfo(VkBuffer buffer, VkFormat format, VkDeviceSize offset, VkDeviceSize range)
	{
		VkBufferViewCreateInfo init = vkiBufferViewCreateInfo_null();
		init.buffer = buffer;
		init.format = format;
		init.offset = offset;
		init.range = range;
		return init;
	}

	static inline VkImageCreateInfo vkiImageCreateInfo_null()
	{
		VkImageCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
		return init;
	}

	static inline VkImageCreateInfo vkiImageCreateInfo(VkImageType imageType, VkFormat format, VkExtent3D extent, uint32_t mipLevels, uint32_t arrayLayers, VkSampleCountFlagBits samples, VkImageTiling tiling, VkImageUsageFlags usage, VkSharingMode sharingMode, uint32_t queueFamilyIndexCount, const uint32_t *pQueueFamilyIndices, VkImageLayout initialLayout)
	{
		VkImageCreateInfo init = vkiImageCreateInfo_null();
		init.imageType = imageType;
		init.format = format;
		init.extent = extent;
		init.mipLevels = mipLevels;
		init.arrayLayers = arrayLayers;
		init.samples = samples;
		init.tiling = tiling;
		init.usage = usage;
		init.sharingMode = sharingMode;
		init.queueFamilyIndexCount = queueFamilyIndexCount;
		init.pQueueFamilyIndices = pQueueFamilyIndices;
		init.initialLayout = initialLayout;
		return init;
	}

	static inline VkSubresourceLayout vkiSubresourceLayout_null()
	{
		VkSubresourceLayout init = {0};
		return init;
	}

	static inline VkSubresourceLayout vkiSubresourceLayout(VkDeviceSize offset, VkDeviceSize size, VkDeviceSize rowPitch, VkDeviceSize arrayPitch, VkDeviceSize depthPitch)
	{
		VkSubresourceLayout init = vkiSubresourceLayout_null();
		init.offset = offset;
		init.size = size;
		init.rowPitch = rowPitch;
		init.arrayPitch = arrayPitch;
		init.depthPitch = depthPitch;
		return init;
	}

	static inline VkComponentMapping vkiComponentMapping_null()
	{
		VkComponentMapping init = {0};
		return init;
	}

	static inline VkComponentMapping vkiComponentMapping(VkComponentSwizzle r, VkComponentSwizzle g, VkComponentSwizzle b, VkComponentSwizzle a)
	{
		VkComponentMapping init = vkiComponentMapping_null();
		init.r = r;
		init.g = g;
		init.b = b;
		init.a = a;
		return init;
	}

	static inline VkImageViewCreateInfo vkiImageViewCreateInfo_null()
	{
		VkImageViewCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		return init;
	}

	static inline VkImageViewCreateInfo vkiImageViewCreateInfo(VkImage image, VkImageViewType viewType, VkFormat format, VkComponentMapping components, VkImageSubresourceRange subresourceRange)
	{
		VkImageViewCreateInfo init = vkiImageViewCreateInfo_null();
		init.image = image;
		init.viewType = viewType;
		init.format = format;
		init.components = components;
		init.subresourceRange = subresourceRange;
		return init;
	}

	static inline VkShaderModuleCreateInfo vkiShaderModuleCreateInfo_null()
	{
		VkShaderModuleCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		return init;
	}

	static inline VkShaderModuleCreateInfo vkiShaderModuleCreateInfo(size_t codeSize, const uint32_t *pCode)
	{
		VkShaderModuleCreateInfo init = vkiShaderModuleCreateInfo_null();
		init.codeSize = codeSize;
		init.pCode = pCode;
		return init;
	}

	static inline VkPipelineCacheCreateInfo vkiPipelineCacheCreateInfo_null()
	{
		VkPipelineCacheCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO;
		return init;
	}

	static inline VkPipelineCacheCreateInfo vkiPipelineCacheCreateInfo(size_t initialDataSize, const void *pInitialData)
	{
		VkPipelineCacheCreateInfo init = vkiPipelineCacheCreateInfo_null();
		init.initialDataSize = initialDataSize;
		init.pInitialData = pInitialData;
		return init;
	}

	static inline VkSpecializationMapEntry vkiSpecializationMapEntry_null()
	{
		VkSpecializationMapEntry init = {0};
		return init;
	}

	static inline VkSpecializationMapEntry vkiSpecializationMapEntry(uint32_t constantID, uint32_t offset, size_t size)
	{
		VkSpecializationMapEntry init = vkiSpecializationMapEntry_null();
		init.constantID = constantID;
		init.offset = offset;
		init.size = size;
		return init;
	}

	static inline VkSpecializationInfo vkiSpecializationInfo_null()
	{
		VkSpecializationInfo init = {0};
		return init;
	}

	static inline VkSpecializationInfo vkiSpecializationInfo(uint32_t mapEntryCount, const VkSpecializationMapEntry *pMapEntries, size_t dataSize, const void *pData)
	{
		VkSpecializationInfo init = vkiSpecializationInfo_null();
		init.mapEntryCount = mapEntryCount;
		init.pMapEntries = pMapEntries;
		init.dataSize = dataSize;
		init.pData = pData;
		return init;
	}

	static inline VkPipelineShaderStageCreateInfo vkiPipelineShaderStageCreateInfo_null()
	{
		VkPipelineShaderStageCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		return init;
	}

	static inline VkPipelineShaderStageCreateInfo vkiPipelineShaderStageCreateInfo(VkShaderStageFlagBits stage, VkShaderModule module, const char *pName, const VkSpecializationInfo *pSpecializationInfo)
	{
		VkPipelineShaderStageCreateInfo init = vkiPipelineShaderStageCreateInfo_null();
		init.stage = stage;
		init.module = module;
		init.pName = pName;
		init.pSpecializationInfo = pSpecializationInfo;
		return init;
	}

	static inline VkComputePipelineCreateInfo vkiComputePipelineCreateInfo_null()
	{
		VkComputePipelineCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
		return init;
	}

	static inline VkComputePipelineCreateInfo vkiComputePipelineCreateInfo(VkPipelineShaderStageCreateInfo stage, VkPipelineLayout layout, VkPipeline basePipelineHandle, int32_t basePipelineIndex)
	{
		VkComputePipelineCreateInfo init = vkiComputePipelineCreateInfo_null();
		init.stage = stage;
		init.layout = layout;
		init.basePipelineHandle = basePipelineHandle;
		init.basePipelineIndex = basePipelineIndex;
		return init;
	}

	static inline VkVertexInputBindingDescription vkiVertexInputBindingDescription_null()
	{
		VkVertexInputBindingDescription init = {0};
		return init;
	}

	static inline VkVertexInputBindingDescription vkiVertexInputBindingDescription(uint32_t binding, uint32_t stride, VkVertexInputRate inputRate)
	{
		VkVertexInputBindingDescription init = vkiVertexInputBindingDescription_null();
		init.binding = binding;
		init.stride = stride;
		init.inputRate = inputRate;
		return init;
	}

	static inline VkVertexInputAttributeDescription vkiVertexInputAttributeDescription_null()
	{
		VkVertexInputAttributeDescription init = {0};
		return init;
	}

	static inline VkVertexInputAttributeDescription vkiVertexInputAttributeDescription(uint32_t location, uint32_t binding, VkFormat format, uint32_t offset)
	{
		VkVertexInputAttributeDescription init = vkiVertexInputAttributeDescription_null();
		init.location = location;
		init.binding = binding;
		init.format = format;
		init.offset = offset;
		return init;
	}

	static inline VkPipelineVertexInputStateCreateInfo vkiPipelineVertexInputStateCreateInfo_null()
	{
		VkPipelineVertexInputStateCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		return init;
	}

	static inline VkPipelineVertexInputStateCreateInfo vkiPipelineVertexInputStateCreateInfo(uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription *pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription *pVertexAttributeDescriptions)
	{
		VkPipelineVertexInputStateCreateInfo init = vkiPipelineVertexInputStateCreateInfo_null();
		init.vertexBindingDescriptionCount = vertexBindingDescriptionCount;
		init.pVertexBindingDescriptions = pVertexBindingDescriptions;
		init.vertexAttributeDescriptionCount = vertexAttributeDescriptionCount;
		init.pVertexAttributeDescriptions = pVertexAttributeDescriptions;
		return init;
	}

	static inline VkPipelineInputAssemblyStateCreateInfo vkiPipelineInputAssemblyStateCreateInfo_null()
	{
		VkPipelineInputAssemblyStateCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		return init;
	}

	static inline VkPipelineInputAssemblyStateCreateInfo vkiPipelineInputAssemblyStateCreateInfo(VkPrimitiveTopology topology, VkBool32 primitiveRestartEnable)
	{
		VkPipelineInputAssemblyStateCreateInfo init = vkiPipelineInputAssemblyStateCreateInfo_null();
		init.topology = topology;
		init.primitiveRestartEnable = primitiveRestartEnable;
		return init;
	}

	static inline VkPipelineTessellationStateCreateInfo vkiPipelineTessellationStateCreateInfo_null()
	{
		VkPipelineTessellationStateCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO;
		return init;
	}

	static inline VkPipelineTessellationStateCreateInfo vkiPipelineTessellationStateCreateInfo(uint32_t patchControlPoints)
	{
		VkPipelineTessellationStateCreateInfo init = vkiPipelineTessellationStateCreateInfo_null();
		init.patchControlPoints = patchControlPoints;
		return init;
	}

	static inline VkViewport vkiViewport_null()
	{
		VkViewport init = {0};
		return init;
	}

	static inline VkViewport vkiViewport(float x, float y, float width, float height, float minDepth, float maxDepth)
	{
		VkViewport init = vkiViewport_null();
		init.x = x;
		init.y = y;
		init.width = width;
		init.height = height;
		init.minDepth = minDepth;
		init.maxDepth = maxDepth;
		return init;
	}

	static inline VkPipelineViewportStateCreateInfo vkiPipelineViewportStateCreateInfo_null()
	{
		VkPipelineViewportStateCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		return init;
	}

	static inline VkPipelineViewportStateCreateInfo vkiPipelineViewportStateCreateInfo(uint32_t viewportCount, const VkViewport *pViewports, uint32_t scissorCount, const VkRect2D *pScissors)
	{
		VkPipelineViewportStateCreateInfo init = vkiPipelineViewportStateCreateInfo_null();
		init.viewportCount = viewportCount;
		init.pViewports = pViewports;
		init.scissorCount = scissorCount;
		init.pScissors = pScissors;
		return init;
	}

	static inline VkPipelineRasterizationStateCreateInfo vkiPipelineRasterizationStateCreateInfo_null()
	{
		VkPipelineRasterizationStateCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		return init;
	}

	static inline VkPipelineRasterizationStateCreateInfo vkiPipelineRasterizationStateCreateInfo(VkBool32 depthClampEnable, VkBool32 rasterizerDiscardEnable, VkPolygonMode polygonMode, VkCullModeFlags cullMode, VkFrontFace frontFace, VkBool32 depthBiasEnable, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor, float lineWidth)
	{
		VkPipelineRasterizationStateCreateInfo init = vkiPipelineRasterizationStateCreateInfo_null();
		init.depthClampEnable = depthClampEnable;
		init.rasterizerDiscardEnable = rasterizerDiscardEnable;
		init.polygonMode = polygonMode;
		init.cullMode = cullMode;
		init.frontFace = frontFace;
		init.depthBiasEnable = depthBiasEnable;
		init.depthBiasConstantFactor = depthBiasConstantFactor;
		init.depthBiasClamp = depthBiasClamp;
		init.depthBiasSlopeFactor = depthBiasSlopeFactor;
		init.lineWidth = lineWidth;
		return init;
	}

	static inline VkPipelineMultisampleStateCreateInfo vkiPipelineMultisampleStateCreateInfo_null()
	{
		VkPipelineMultisampleStateCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		return init;
	}

	static inline VkPipelineMultisampleStateCreateInfo vkiPipelineMultisampleStateCreateInfo(VkSampleCountFlagBits rasterizationSamples, VkBool32 sampleShadingEnable, float minSampleShading, const VkSampleMask *pSampleMask, VkBool32 alphaToCoverageEnable, VkBool32 alphaToOneEnable)
	{
		VkPipelineMultisampleStateCreateInfo init = vkiPipelineMultisampleStateCreateInfo_null();
		init.rasterizationSamples = rasterizationSamples;
		init.sampleShadingEnable = sampleShadingEnable;
		init.minSampleShading = minSampleShading;
		init.pSampleMask = pSampleMask;
		init.alphaToCoverageEnable = alphaToCoverageEnable;
		init.alphaToOneEnable = alphaToOneEnable;
		return init;
	}

	static inline VkStencilOpState vkiStencilOpState_null()
	{
		VkStencilOpState init = {0};
		return init;
	}

	static inline VkStencilOpState vkiStencilOpState(VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp, uint32_t compareMask, uint32_t writeMask, uint32_t reference)
	{
		VkStencilOpState init = vkiStencilOpState_null();
		init.failOp = failOp;
		init.passOp = passOp;
		init.depthFailOp = depthFailOp;
		init.compareOp = compareOp;
		init.compareMask = compareMask;
		init.writeMask = writeMask;
		init.reference = reference;
		return init;
	}

	static inline VkPipelineDepthStencilStateCreateInfo vkiPipelineDepthStencilStateCreateInfo_null()
	{
		VkPipelineDepthStencilStateCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
		return init;
	}

	static inline VkPipelineDepthStencilStateCreateInfo vkiPipelineDepthStencilStateCreateInfo(VkBool32 depthTestEnable, VkBool32 depthWriteEnable, VkCompareOp depthCompareOp, VkBool32 depthBoundsTestEnable, VkBool32 stencilTestEnable, VkStencilOpState front, VkStencilOpState back, float minDepthBounds, float maxDepthBounds)
	{
		VkPipelineDepthStencilStateCreateInfo init = vkiPipelineDepthStencilStateCreateInfo_null();
		init.depthTestEnable = depthTestEnable;
		init.depthWriteEnable = depthWriteEnable;
		init.depthCompareOp = depthCompareOp;
		init.depthBoundsTestEnable = depthBoundsTestEnable;
		init.stencilTestEnable = stencilTestEnable;
		init.front = front;
		init.back = back;
		init.minDepthBounds = minDepthBounds;
		init.maxDepthBounds = maxDepthBounds;
		return init;
	}

	static inline VkPipelineColorBlendAttachmentState vkiPipelineColorBlendAttachmentState_null()
	{
		VkPipelineColorBlendAttachmentState init = {0};
		return init;
	}

	static inline VkPipelineColorBlendAttachmentState vkiPipelineColorBlendAttachmentState(VkBool32 blendEnable, VkBlendFactor srcColorBlendFactor, VkBlendFactor dstColorBlendFactor, VkBlendOp colorBlendOp, VkBlendFactor srcAlphaBlendFactor, VkBlendFactor dstAlphaBlendFactor, VkBlendOp alphaBlendOp, VkColorComponentFlags colorWriteMask)
	{
		VkPipelineColorBlendAttachmentState init = vkiPipelineColorBlendAttachmentState_null();
		init.blendEnable = blendEnable;
		init.srcColorBlendFactor = srcColorBlendFactor;
		init.dstColorBlendFactor = dstColorBlendFactor;
		init.colorBlendOp = colorBlendOp;
		init.srcAlphaBlendFactor = srcAlphaBlendFactor;
		init.dstAlphaBlendFactor = dstAlphaBlendFactor;
		init.alphaBlendOp = alphaBlendOp;
		init.colorWriteMask = colorWriteMask;
		return init;
	}

	static inline VkPipelineColorBlendStateCreateInfo vkiPipelineColorBlendStateCreateInfo_null()
	{
		VkPipelineColorBlendStateCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		return init;
	}

	static inline VkPipelineColorBlendStateCreateInfo vkiPipelineColorBlendStateCreateInfo(VkBool32 logicOpEnable, VkLogicOp logicOp, uint32_t attachmentCount, const VkPipelineColorBlendAttachmentState *pAttachments)
	{
		VkPipelineColorBlendStateCreateInfo init = vkiPipelineColorBlendStateCreateInfo_null();
		init.logicOpEnable = logicOpEnable;
		init.logicOp = logicOp;
		init.attachmentCount = attachmentCount;
		init.pAttachments = pAttachments;
		return init;
	}

	static inline VkPipelineDynamicStateCreateInfo vkiPipelineDynamicStateCreateInfo_null()
	{
		VkPipelineDynamicStateCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		return init;
	}

	static inline VkPipelineDynamicStateCreateInfo vkiPipelineDynamicStateCreateInfo(uint32_t dynamicStateCount, const VkDynamicState *pDynamicStates)
	{
		VkPipelineDynamicStateCreateInfo init = vkiPipelineDynamicStateCreateInfo_null();
		init.dynamicStateCount = dynamicStateCount;
		init.pDynamicStates = pDynamicStates;
		return init;
	}

	static inline VkGraphicsPipelineCreateInfo vkiGraphicsPipelineCreateInfo_null()
	{
		VkGraphicsPipelineCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		return init;
	}

	static inline VkGraphicsPipelineCreateInfo vkiGraphicsPipelineCreateInfo(uint32_t stageCount, const VkPipelineShaderStageCreateInfo *pStages, const VkPipelineVertexInputStateCreateInfo *pVertexInputState, const VkPipelineInputAssemblyStateCreateInfo *pInputAssemblyState, const VkPipelineTessellationStateCreateInfo *pTessellationState, const VkPipelineViewportStateCreateInfo *pViewportState, const VkPipelineRasterizationStateCreateInfo *pRasterizationState, const VkPipelineMultisampleStateCreateInfo *pMultisampleState, const VkPipelineDepthStencilStateCreateInfo *pDepthStencilState, const VkPipelineColorBlendStateCreateInfo *pColorBlendState, const VkPipelineDynamicStateCreateInfo *pDynamicState, VkPipelineLayout layout, VkRenderPass renderPass, uint32_t subpass, VkPipeline basePipelineHandle, int32_t basePipelineIndex)
	{
		VkGraphicsPipelineCreateInfo init = vkiGraphicsPipelineCreateInfo_null();
		init.stageCount = stageCount;
		init.pStages = pStages;
		init.pVertexInputState = pVertexInputState;
		init.pInputAssemblyState = pInputAssemblyState;
		init.pTessellationState = pTessellationState;
		init.pViewportState = pViewportState;
		init.pRasterizationState = pRasterizationState;
		init.pMultisampleState = pMultisampleState;
		init.pDepthStencilState = pDepthStencilState;
		init.pColorBlendState = pColorBlendState;
		init.pDynamicState = pDynamicState;
		init.layout = layout;
		init.renderPass = renderPass;
		init.subpass = subpass;
		init.basePipelineHandle = basePipelineHandle;
		init.basePipelineIndex = basePipelineIndex;
		return init;
	}

	static inline VkPushConstantRange vkiPushConstantRange_null()
	{
		VkPushConstantRange init = {0};
		return init;
	}

	static inline VkPushConstantRange vkiPushConstantRange(VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size)
	{
		VkPushConstantRange init = vkiPushConstantRange_null();
		init.stageFlags = stageFlags;
		init.offset = offset;
		init.size = size;
		return init;
	}

	static inline VkPipelineLayoutCreateInfo vkiPipelineLayoutCreateInfo_null()
	{
		VkPipelineLayoutCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		return init;
	}

	static inline VkPipelineLayoutCreateInfo vkiPipelineLayoutCreateInfo(uint32_t setLayoutCount, const VkDescriptorSetLayout *pSetLayouts, uint32_t pushConstantRangeCount, const VkPushConstantRange *pPushConstantRanges)
	{
		VkPipelineLayoutCreateInfo init = vkiPipelineLayoutCreateInfo_null();
		init.setLayoutCount = setLayoutCount;
		init.pSetLayouts = pSetLayouts;
		init.pushConstantRangeCount = pushConstantRangeCount;
		init.pPushConstantRanges = pPushConstantRanges;
		return init;
	}

	static inline VkSamplerCreateInfo vkiSamplerCreateInfo_null()
	{
		VkSamplerCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
		return init;
	}

	static inline VkSamplerCreateInfo vkiSamplerCreateInfo(VkFilter magFilter, VkFilter minFilter, VkSamplerMipmapMode mipmapMode, VkSamplerAddressMode addressModeU, VkSamplerAddressMode addressModeV, VkSamplerAddressMode addressModeW, float mipLodBias, VkBool32 anisotropyEnable, float maxAnisotropy, VkBool32 compareEnable, VkCompareOp compareOp, float minLod, float maxLod, VkBorderColor borderColor, VkBool32 unnormalizedCoordinates)
	{
		VkSamplerCreateInfo init = vkiSamplerCreateInfo_null();
		init.magFilter = magFilter;
		init.minFilter = minFilter;
		init.mipmapMode = mipmapMode;
		init.addressModeU = addressModeU;
		init.addressModeV = addressModeV;
		init.addressModeW = addressModeW;
		init.mipLodBias = mipLodBias;
		init.anisotropyEnable = anisotropyEnable;
		init.maxAnisotropy = maxAnisotropy;
		init.compareEnable = compareEnable;
		init.compareOp = compareOp;
		init.minLod = minLod;
		init.maxLod = maxLod;
		init.borderColor = borderColor;
		init.unnormalizedCoordinates = unnormalizedCoordinates;
		return init;
	}

	static inline VkCopyDescriptorSet vkiCopyDescriptorSet_null()
	{
		VkCopyDescriptorSet init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET;
		return init;
	}

	static inline VkCopyDescriptorSet vkiCopyDescriptorSet(VkDescriptorSet srcSet, uint32_t srcBinding, uint32_t srcArrayElement, VkDescriptorSet dstSet, uint32_t dstBinding, uint32_t dstArrayElement, uint32_t descriptorCount)
	{
		VkCopyDescriptorSet init = vkiCopyDescriptorSet_null();
		init.srcSet = srcSet;
		init.srcBinding = srcBinding;
		init.srcArrayElement = srcArrayElement;
		init.dstSet = dstSet;
		init.dstBinding = dstBinding;
		init.dstArrayElement = dstArrayElement;
		init.descriptorCount = descriptorCount;
		return init;
	}

	static inline VkDescriptorBufferInfo vkiDescriptorBufferInfo_null()
	{
		VkDescriptorBufferInfo init = {0};
		return init;
	}

	static inline VkDescriptorBufferInfo vkiDescriptorBufferInfo(VkBuffer buffer, VkDeviceSize offset, VkDeviceSize range)
	{
		VkDescriptorBufferInfo init = vkiDescriptorBufferInfo_null();
		init.buffer = buffer;
		init.offset = offset;
		init.range = range;
		return init;
	}

	static inline VkDescriptorImageInfo vkiDescriptorImageInfo_null()
	{
		VkDescriptorImageInfo init = {0};
		return init;
	}

	static inline VkDescriptorImageInfo vkiDescriptorImageInfo(VkSampler sampler, VkImageView imageView, VkImageLayout imageLayout)
	{
		VkDescriptorImageInfo init = vkiDescriptorImageInfo_null();
		init.sampler = sampler;
		init.imageView = imageView;
		init.imageLayout = imageLayout;
		return init;
	}

	static inline VkDescriptorPoolSize vkiDescriptorPoolSize_null()
	{
		VkDescriptorPoolSize init = {0};
		return init;
	}

	static inline VkDescriptorPoolSize vkiDescriptorPoolSize(VkDescriptorType type, uint32_t descriptorCount)
	{
		VkDescriptorPoolSize init = vkiDescriptorPoolSize_null();
		init.type = type;
		init.descriptorCount = descriptorCount;
		return init;
	}

	static inline VkDescriptorPoolCreateInfo vkiDescriptorPoolCreateInfo_null()
	{
		VkDescriptorPoolCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		return init;
	}

	static inline VkDescriptorPoolCreateInfo vkiDescriptorPoolCreateInfo(uint32_t maxSets, uint32_t poolSizeCount, const VkDescriptorPoolSize *pPoolSizes)
	{
		VkDescriptorPoolCreateInfo init = vkiDescriptorPoolCreateInfo_null();
		init.maxSets = maxSets;
		init.poolSizeCount = poolSizeCount;
		init.pPoolSizes = pPoolSizes;
		return init;
	}

	static inline VkDescriptorSetAllocateInfo vkiDescriptorSetAllocateInfo_null()
	{
		VkDescriptorSetAllocateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
		return init;
	}

	static inline VkDescriptorSetAllocateInfo vkiDescriptorSetAllocateInfo(VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSetLayout *pSetLayouts)
	{
		VkDescriptorSetAllocateInfo init = vkiDescriptorSetAllocateInfo_null();
		init.descriptorPool = descriptorPool;
		init.descriptorSetCount = descriptorSetCount;
		init.pSetLayouts = pSetLayouts;
		return init;
	}

	static inline VkDescriptorSetLayoutBinding vkiDescriptorSetLayoutBinding_null()
	{
		VkDescriptorSetLayoutBinding init = {0};
		return init;
	}

	static inline VkDescriptorSetLayoutBinding vkiDescriptorSetLayoutBinding(uint32_t binding, VkDescriptorType descriptorType, uint32_t descriptorCount, VkShaderStageFlags stageFlags, const VkSampler *pImmutableSamplers)
	{
		VkDescriptorSetLayoutBinding init = vkiDescriptorSetLayoutBinding_null();
		init.binding = binding;
		init.descriptorType = descriptorType;
		init.descriptorCount = descriptorCount;
		init.stageFlags = stageFlags;
		init.pImmutableSamplers = pImmutableSamplers;
		return init;
	}

	static inline VkDescriptorSetLayoutCreateInfo vkiDescriptorSetLayoutCreateInfo_null()
	{
		VkDescriptorSetLayoutCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		return init;
	}

	static inline VkDescriptorSetLayoutCreateInfo vkiDescriptorSetLayoutCreateInfo(uint32_t bindingCount, const VkDescriptorSetLayoutBinding *pBindings)
	{
		VkDescriptorSetLayoutCreateInfo init = vkiDescriptorSetLayoutCreateInfo_null();
		init.bindingCount = bindingCount;
		init.pBindings = pBindings;
		return init;
	}

	static inline VkWriteDescriptorSet vkiWriteDescriptorSet_null()
	{
		VkWriteDescriptorSet init = {0};
		init.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		return init;
	}

	static inline VkWriteDescriptorSet vkiWriteDescriptorSet(VkDescriptorSet dstSet, uint32_t dstBinding, uint32_t dstArrayElement, uint32_t descriptorCount, VkDescriptorType descriptorType, const VkDescriptorImageInfo *pImageInfo, const VkDescriptorBufferInfo *pBufferInfo, const VkBufferView *pTexelBufferView)
	{
		VkWriteDescriptorSet init = vkiWriteDescriptorSet_null();
		init.dstSet = dstSet;
		init.dstBinding = dstBinding;
		init.dstArrayElement = dstArrayElement;
		init.descriptorCount = descriptorCount;
		init.descriptorType = descriptorType;
		init.pImageInfo = pImageInfo;
		init.pBufferInfo = pBufferInfo;
		init.pTexelBufferView = pTexelBufferView;
		return init;
	}

	static inline VkAttachmentDescription vkiAttachmentDescription_null()
	{
		VkAttachmentDescription init = {0};
		return init;
	}

	static inline VkAttachmentDescription vkiAttachmentDescription(VkFormat format, VkSampleCountFlagBits samples, VkAttachmentLoadOp loadOp, VkAttachmentStoreOp storeOp, VkAttachmentLoadOp stencilLoadOp, VkAttachmentStoreOp stencilStoreOp, VkImageLayout initialLayout, VkImageLayout finalLayout)
	{
		VkAttachmentDescription init = vkiAttachmentDescription_null();
		init.format = format;
		init.samples = samples;
		init.loadOp = loadOp;
		init.storeOp = storeOp;
		init.stencilLoadOp = stencilLoadOp;
		init.stencilStoreOp = stencilStoreOp;
		init.initialLayout = initialLayout;
		init.finalLayout = finalLayout;
		return init;
	}

	static inline VkAttachmentReference vkiAttachmentReference_null()
	{
		VkAttachmentReference init = {0};
		return init;
	}

	static inline VkAttachmentReference vkiAttachmentReference(uint32_t attachment, VkImageLayout layout)
	{
		VkAttachmentReference init = vkiAttachmentReference_null();
		init.attachment = attachment;
		init.layout = layout;
		return init;
	}

	static inline VkFramebufferCreateInfo vkiFramebufferCreateInfo_null()
	{
		VkFramebufferCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
		return init;
	}

	static inline VkFramebufferCreateInfo vkiFramebufferCreateInfo(VkRenderPass renderPass, uint32_t attachmentCount, const VkImageView *pAttachments, uint32_t width, uint32_t height, uint32_t layers)
	{
		VkFramebufferCreateInfo init = vkiFramebufferCreateInfo_null();
		init.renderPass = renderPass;
		init.attachmentCount = attachmentCount;
		init.pAttachments = pAttachments;
		init.width = width;
		init.height = height;
		init.layers = layers;
		return init;
	}

	static inline VkSubpassDescription vkiSubpassDescription_null()
	{
		VkSubpassDescription init = {0};
		return init;
	}

	static inline VkSubpassDescription vkiSubpassDescription(VkPipelineBindPoint pipelineBindPoint, uint32_t inputAttachmentCount, const VkAttachmentReference *pInputAttachments, uint32_t colorAttachmentCount, const VkAttachmentReference *pColorAttachments, const VkAttachmentReference *pResolveAttachments, const VkAttachmentReference *pDepthStencilAttachment, uint32_t preserveAttachmentCount, const uint32_t *pPreserveAttachments)
	{
		VkSubpassDescription init = vkiSubpassDescription_null();
		init.pipelineBindPoint = pipelineBindPoint;
		init.inputAttachmentCount = inputAttachmentCount;
		init.pInputAttachments = pInputAttachments;
		init.colorAttachmentCount = colorAttachmentCount;
		init.pColorAttachments = pColorAttachments;
		init.pResolveAttachments = pResolveAttachments;
		init.pDepthStencilAttachment = pDepthStencilAttachment;
		init.preserveAttachmentCount = preserveAttachmentCount;
		init.pPreserveAttachments = pPreserveAttachments;
		return init;
	}

	static inline VkSubpassDependency vkiSubpassDependency_null()
	{
		VkSubpassDependency init = {0};
		return init;
	}

	static inline VkSubpassDependency vkiSubpassDependency(uint32_t srcSubpass, uint32_t dstSubpass, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask, VkDependencyFlags dependencyFlags)
	{
		VkSubpassDependency init = vkiSubpassDependency_null();
		init.srcSubpass = srcSubpass;
		init.dstSubpass = dstSubpass;
		init.srcStageMask = srcStageMask;
		init.dstStageMask = dstStageMask;
		init.srcAccessMask = srcAccessMask;
		init.dstAccessMask = dstAccessMask;
		init.dependencyFlags = dependencyFlags;
		return init;
	}

	static inline VkRenderPassCreateInfo vkiRenderPassCreateInfo_null()
	{
		VkRenderPassCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
		return init;
	}

	static inline VkRenderPassCreateInfo vkiRenderPassCreateInfo(uint32_t attachmentCount, const VkAttachmentDescription *pAttachments, uint32_t subpassCount, const VkSubpassDescription *pSubpasses, uint32_t dependencyCount, const VkSubpassDependency *pDependencies)
	{
		VkRenderPassCreateInfo init = vkiRenderPassCreateInfo_null();
		init.attachmentCount = attachmentCount;
		init.pAttachments = pAttachments;
		init.subpassCount = subpassCount;
		init.pSubpasses = pSubpasses;
		init.dependencyCount = dependencyCount;
		init.pDependencies = pDependencies;
		return init;
	}

	static inline VkCommandPoolCreateInfo vkiCommandPoolCreateInfo_null()
	{
		VkCommandPoolCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
		return init;
	}

	static inline VkCommandPoolCreateInfo vkiCommandPoolCreateInfo(uint32_t queueFamilyIndex)
	{
		VkCommandPoolCreateInfo init = vkiCommandPoolCreateInfo_null();
		init.queueFamilyIndex = queueFamilyIndex;
		return init;
	}

	static inline VkCommandBufferAllocateInfo vkiCommandBufferAllocateInfo_null()
	{
		VkCommandBufferAllocateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		return init;
	}

	static inline VkCommandBufferAllocateInfo vkiCommandBufferAllocateInfo(VkCommandPool commandPool, VkCommandBufferLevel level, uint32_t commandBufferCount)
	{
		VkCommandBufferAllocateInfo init = vkiCommandBufferAllocateInfo_null();
		init.commandPool = commandPool;
		init.level = level;
		init.commandBufferCount = commandBufferCount;
		return init;
	}

	static inline VkCommandBufferInheritanceInfo vkiCommandBufferInheritanceInfo_null()
	{
		VkCommandBufferInheritanceInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
		return init;
	}

	static inline VkCommandBufferInheritanceInfo vkiCommandBufferInheritanceInfo(VkRenderPass renderPass, uint32_t subpass, VkFramebuffer framebuffer, VkBool32 occlusionQueryEnable, VkQueryControlFlags queryFlags, VkQueryPipelineStatisticFlags pipelineStatistics)
	{
		VkCommandBufferInheritanceInfo init = vkiCommandBufferInheritanceInfo_null();
		init.renderPass = renderPass;
		init.subpass = subpass;
		init.framebuffer = framebuffer;
		init.occlusionQueryEnable = occlusionQueryEnable;
		init.queryFlags = queryFlags;
		init.pipelineStatistics = pipelineStatistics;
		return init;
	}

	static inline VkCommandBufferBeginInfo vkiCommandBufferBeginInfo_null()
	{
		VkCommandBufferBeginInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		return init;
	}

	static inline VkCommandBufferBeginInfo vkiCommandBufferBeginInfo(const VkCommandBufferInheritanceInfo *pInheritanceInfo)
	{
		VkCommandBufferBeginInfo init = vkiCommandBufferBeginInfo_null();
		init.pInheritanceInfo = pInheritanceInfo;
		return init;
	}

	static inline VkBufferCopy vkiBufferCopy_null()
	{
		VkBufferCopy init = {0};
		return init;
	}

	static inline VkBufferCopy vkiBufferCopy(VkDeviceSize srcOffset, VkDeviceSize dstOffset, VkDeviceSize size)
	{
		VkBufferCopy init = vkiBufferCopy_null();
		init.srcOffset = srcOffset;
		init.dstOffset = dstOffset;
		init.size = size;
		return init;
	}

	static inline VkImageSubresourceLayers vkiImageSubresourceLayers_null()
	{
		VkImageSubresourceLayers init = {0};
		return init;
	}

	static inline VkImageSubresourceLayers vkiImageSubresourceLayers(VkImageAspectFlags aspectMask, uint32_t mipLevel, uint32_t baseArrayLayer, uint32_t layerCount)
	{
		VkImageSubresourceLayers init = vkiImageSubresourceLayers_null();
		init.aspectMask = aspectMask;
		init.mipLevel = mipLevel;
		init.baseArrayLayer = baseArrayLayer;
		init.layerCount = layerCount;
		return init;
	}

	static inline VkBufferImageCopy vkiBufferImageCopy_null()
	{
		VkBufferImageCopy init = {0};
		return init;
	}

	static inline VkBufferImageCopy vkiBufferImageCopy(VkDeviceSize bufferOffset, uint32_t bufferRowLength, uint32_t bufferImageHeight, VkImageSubresourceLayers imageSubresource, VkOffset3D imageOffset, VkExtent3D imageExtent)
	{
		VkBufferImageCopy init = vkiBufferImageCopy_null();
		init.bufferOffset = bufferOffset;
		init.bufferRowLength = bufferRowLength;
		init.bufferImageHeight = bufferImageHeight;
		init.imageSubresource = imageSubresource;
		init.imageOffset = imageOffset;
		init.imageExtent = imageExtent;
		return init;
	}

	static inline VkClearDepthStencilValue vkiClearDepthStencilValue_null()
	{
		VkClearDepthStencilValue init = {0};
		return init;
	}

	static inline VkClearDepthStencilValue vkiClearDepthStencilValue(float depth, uint32_t stencil)
	{
		VkClearDepthStencilValue init = vkiClearDepthStencilValue_null();
		init.depth = depth;
		init.stencil = stencil;
		return init;
	}

	static inline VkClearAttachment vkiClearAttachment_null()
	{
		VkClearAttachment init = {0};
		return init;
	}

	static inline VkClearAttachment vkiClearAttachment(VkImageAspectFlags aspectMask, uint32_t colorAttachment, VkClearValue clearValue)
	{
		VkClearAttachment init = vkiClearAttachment_null();
		init.aspectMask = aspectMask;
		init.colorAttachment = colorAttachment;
		init.clearValue = clearValue;
		return init;
	}

	static inline VkClearRect vkiClearRect_null()
	{
		VkClearRect init = {0};
		return init;
	}

	static inline VkClearRect vkiClearRect(VkRect2D rect, uint32_t baseArrayLayer, uint32_t layerCount)
	{
		VkClearRect init = vkiClearRect_null();
		init.rect = rect;
		init.baseArrayLayer = baseArrayLayer;
		init.layerCount = layerCount;
		return init;
	}

	static inline VkImageBlit vkiImageBlit_null()
	{
		VkImageBlit init = {0};
		return init;
	}

	static inline VkImageBlit vkiImageBlit(VkImageSubresourceLayers srcSubresource, VkImageSubresourceLayers dstSubresource)
	{
		VkImageBlit init = vkiImageBlit_null();
		init.srcSubresource = srcSubresource;
		init.dstSubresource = dstSubresource;
		return init;
	}

	static inline VkImageCopy vkiImageCopy_null()
	{
		VkImageCopy init = {0};
		return init;
	}

	static inline VkImageCopy vkiImageCopy(VkImageSubresourceLayers srcSubresource, VkOffset3D srcOffset, VkImageSubresourceLayers dstSubresource, VkOffset3D dstOffset, VkExtent3D extent)
	{
		VkImageCopy init = vkiImageCopy_null();
		init.srcSubresource = srcSubresource;
		init.srcOffset = srcOffset;
		init.dstSubresource = dstSubresource;
		init.dstOffset = dstOffset;
		init.extent = extent;
		return init;
	}

	static inline VkImageResolve vkiImageResolve_null()
	{
		VkImageResolve init = {0};
		return init;
	}

	static inline VkImageResolve vkiImageResolve(VkImageSubresourceLayers srcSubresource, VkOffset3D srcOffset, VkImageSubresourceLayers dstSubresource, VkOffset3D dstOffset, VkExtent3D extent)
	{
		VkImageResolve init = vkiImageResolve_null();
		init.srcSubresource = srcSubresource;
		init.srcOffset = srcOffset;
		init.dstSubresource = dstSubresource;
		init.dstOffset = dstOffset;
		init.extent = extent;
		return init;
	}

	static inline VkRenderPassBeginInfo vkiRenderPassBeginInfo_null()
	{
		VkRenderPassBeginInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
		return init;
	}

	static inline VkRenderPassBeginInfo vkiRenderPassBeginInfo(VkRenderPass renderPass, VkFramebuffer framebuffer, VkRect2D renderArea, uint32_t clearValueCount, const VkClearValue *pClearValues)
	{
		VkRenderPassBeginInfo init = vkiRenderPassBeginInfo_null();
		init.renderPass = renderPass;
		init.framebuffer = framebuffer;
		init.renderArea = renderArea;
		init.clearValueCount = clearValueCount;
		init.pClearValues = pClearValues;
		return init;
	}

	static inline VkPhysicalDeviceSubgroupProperties vkiPhysicalDeviceSubgroupProperties_null()
	{
		VkPhysicalDeviceSubgroupProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceSubgroupProperties vkiPhysicalDeviceSubgroupProperties(uint32_t subgroupSize, VkShaderStageFlags supportedStages, VkSubgroupFeatureFlags supportedOperations, VkBool32 quadOperationsInAllStages)
	{
		VkPhysicalDeviceSubgroupProperties init = vkiPhysicalDeviceSubgroupProperties_null();
		init.subgroupSize = subgroupSize;
		init.supportedStages = supportedStages;
		init.supportedOperations = supportedOperations;
		init.quadOperationsInAllStages = quadOperationsInAllStages;
		return init;
	}

	static inline VkBindBufferMemoryInfo vkiBindBufferMemoryInfo_null()
	{
		VkBindBufferMemoryInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO;
		return init;
	}

	static inline VkBindBufferMemoryInfo vkiBindBufferMemoryInfo(VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
	{
		VkBindBufferMemoryInfo init = vkiBindBufferMemoryInfo_null();
		init.buffer = buffer;
		init.memory = memory;
		init.memoryOffset = memoryOffset;
		return init;
	}

	static inline VkBindImageMemoryInfo vkiBindImageMemoryInfo_null()
	{
		VkBindImageMemoryInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO;
		return init;
	}

	static inline VkBindImageMemoryInfo vkiBindImageMemoryInfo(VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
	{
		VkBindImageMemoryInfo init = vkiBindImageMemoryInfo_null();
		init.image = image;
		init.memory = memory;
		init.memoryOffset = memoryOffset;
		return init;
	}

	static inline VkPhysicalDevice16BitStorageFeatures vkiPhysicalDevice16BitStorageFeatures_null()
	{
		VkPhysicalDevice16BitStorageFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES;
		return init;
	}

	static inline VkPhysicalDevice16BitStorageFeatures vkiPhysicalDevice16BitStorageFeatures(VkBool32 storageBuffer16BitAccess, VkBool32 uniformAndStorageBuffer16BitAccess, VkBool32 storagePushConstant16, VkBool32 storageInputOutput16)
	{
		VkPhysicalDevice16BitStorageFeatures init = vkiPhysicalDevice16BitStorageFeatures_null();
		init.storageBuffer16BitAccess = storageBuffer16BitAccess;
		init.uniformAndStorageBuffer16BitAccess = uniformAndStorageBuffer16BitAccess;
		init.storagePushConstant16 = storagePushConstant16;
		init.storageInputOutput16 = storageInputOutput16;
		return init;
	}

	static inline VkMemoryDedicatedRequirements vkiMemoryDedicatedRequirements_null()
	{
		VkMemoryDedicatedRequirements init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS;
		return init;
	}

	static inline VkMemoryDedicatedRequirements vkiMemoryDedicatedRequirements(VkBool32 prefersDedicatedAllocation, VkBool32 requiresDedicatedAllocation)
	{
		VkMemoryDedicatedRequirements init = vkiMemoryDedicatedRequirements_null();
		init.prefersDedicatedAllocation = prefersDedicatedAllocation;
		init.requiresDedicatedAllocation = requiresDedicatedAllocation;
		return init;
	}

	static inline VkMemoryDedicatedAllocateInfo vkiMemoryDedicatedAllocateInfo_null()
	{
		VkMemoryDedicatedAllocateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO;
		return init;
	}

	static inline VkMemoryDedicatedAllocateInfo vkiMemoryDedicatedAllocateInfo(VkImage image, VkBuffer buffer)
	{
		VkMemoryDedicatedAllocateInfo init = vkiMemoryDedicatedAllocateInfo_null();
		init.image = image;
		init.buffer = buffer;
		return init;
	}

	static inline VkMemoryAllocateFlagsInfo vkiMemoryAllocateFlagsInfo_null()
	{
		VkMemoryAllocateFlagsInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO;
		return init;
	}

	static inline VkMemoryAllocateFlagsInfo vkiMemoryAllocateFlagsInfo(uint32_t deviceMask)
	{
		VkMemoryAllocateFlagsInfo init = vkiMemoryAllocateFlagsInfo_null();
		init.deviceMask = deviceMask;
		return init;
	}

	static inline VkDeviceGroupRenderPassBeginInfo vkiDeviceGroupRenderPassBeginInfo_null()
	{
		VkDeviceGroupRenderPassBeginInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO;
		return init;
	}

	static inline VkDeviceGroupRenderPassBeginInfo vkiDeviceGroupRenderPassBeginInfo(uint32_t deviceMask, uint32_t deviceRenderAreaCount, const VkRect2D *pDeviceRenderAreas)
	{
		VkDeviceGroupRenderPassBeginInfo init = vkiDeviceGroupRenderPassBeginInfo_null();
		init.deviceMask = deviceMask;
		init.deviceRenderAreaCount = deviceRenderAreaCount;
		init.pDeviceRenderAreas = pDeviceRenderAreas;
		return init;
	}

	static inline VkDeviceGroupCommandBufferBeginInfo vkiDeviceGroupCommandBufferBeginInfo_null()
	{
		VkDeviceGroupCommandBufferBeginInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO;
		return init;
	}

	static inline VkDeviceGroupCommandBufferBeginInfo vkiDeviceGroupCommandBufferBeginInfo(uint32_t deviceMask)
	{
		VkDeviceGroupCommandBufferBeginInfo init = vkiDeviceGroupCommandBufferBeginInfo_null();
		init.deviceMask = deviceMask;
		return init;
	}

	static inline VkDeviceGroupSubmitInfo vkiDeviceGroupSubmitInfo_null()
	{
		VkDeviceGroupSubmitInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO;
		return init;
	}

	static inline VkDeviceGroupSubmitInfo vkiDeviceGroupSubmitInfo(uint32_t waitSemaphoreCount, const uint32_t *pWaitSemaphoreDeviceIndices, uint32_t commandBufferCount, const uint32_t *pCommandBufferDeviceMasks, uint32_t signalSemaphoreCount, const uint32_t *pSignalSemaphoreDeviceIndices)
	{
		VkDeviceGroupSubmitInfo init = vkiDeviceGroupSubmitInfo_null();
		init.waitSemaphoreCount = waitSemaphoreCount;
		init.pWaitSemaphoreDeviceIndices = pWaitSemaphoreDeviceIndices;
		init.commandBufferCount = commandBufferCount;
		init.pCommandBufferDeviceMasks = pCommandBufferDeviceMasks;
		init.signalSemaphoreCount = signalSemaphoreCount;
		init.pSignalSemaphoreDeviceIndices = pSignalSemaphoreDeviceIndices;
		return init;
	}

	static inline VkDeviceGroupBindSparseInfo vkiDeviceGroupBindSparseInfo_null()
	{
		VkDeviceGroupBindSparseInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO;
		return init;
	}

	static inline VkDeviceGroupBindSparseInfo vkiDeviceGroupBindSparseInfo(uint32_t resourceDeviceIndex, uint32_t memoryDeviceIndex)
	{
		VkDeviceGroupBindSparseInfo init = vkiDeviceGroupBindSparseInfo_null();
		init.resourceDeviceIndex = resourceDeviceIndex;
		init.memoryDeviceIndex = memoryDeviceIndex;
		return init;
	}

	static inline VkBindBufferMemoryDeviceGroupInfo vkiBindBufferMemoryDeviceGroupInfo_null()
	{
		VkBindBufferMemoryDeviceGroupInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO;
		return init;
	}

	static inline VkBindBufferMemoryDeviceGroupInfo vkiBindBufferMemoryDeviceGroupInfo(uint32_t deviceIndexCount, const uint32_t *pDeviceIndices)
	{
		VkBindBufferMemoryDeviceGroupInfo init = vkiBindBufferMemoryDeviceGroupInfo_null();
		init.deviceIndexCount = deviceIndexCount;
		init.pDeviceIndices = pDeviceIndices;
		return init;
	}

	static inline VkBindImageMemoryDeviceGroupInfo vkiBindImageMemoryDeviceGroupInfo_null()
	{
		VkBindImageMemoryDeviceGroupInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO;
		return init;
	}

	static inline VkBindImageMemoryDeviceGroupInfo vkiBindImageMemoryDeviceGroupInfo(uint32_t deviceIndexCount, const uint32_t *pDeviceIndices, uint32_t splitInstanceBindRegionCount, const VkRect2D *pSplitInstanceBindRegions)
	{
		VkBindImageMemoryDeviceGroupInfo init = vkiBindImageMemoryDeviceGroupInfo_null();
		init.deviceIndexCount = deviceIndexCount;
		init.pDeviceIndices = pDeviceIndices;
		init.splitInstanceBindRegionCount = splitInstanceBindRegionCount;
		init.pSplitInstanceBindRegions = pSplitInstanceBindRegions;
		return init;
	}

	static inline VkPhysicalDeviceGroupProperties vkiPhysicalDeviceGroupProperties_null()
	{
		VkPhysicalDeviceGroupProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceGroupProperties vkiPhysicalDeviceGroupProperties(uint32_t physicalDeviceCount, VkBool32 subsetAllocation)
	{
		VkPhysicalDeviceGroupProperties init = vkiPhysicalDeviceGroupProperties_null();
		init.physicalDeviceCount = physicalDeviceCount;
		init.subsetAllocation = subsetAllocation;
		return init;
	}

	static inline VkDeviceGroupDeviceCreateInfo vkiDeviceGroupDeviceCreateInfo_null()
	{
		VkDeviceGroupDeviceCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO;
		return init;
	}

	static inline VkDeviceGroupDeviceCreateInfo vkiDeviceGroupDeviceCreateInfo(uint32_t physicalDeviceCount, const VkPhysicalDevice *pPhysicalDevices)
	{
		VkDeviceGroupDeviceCreateInfo init = vkiDeviceGroupDeviceCreateInfo_null();
		init.physicalDeviceCount = physicalDeviceCount;
		init.pPhysicalDevices = pPhysicalDevices;
		return init;
	}

	static inline VkBufferMemoryRequirementsInfo2 vkiBufferMemoryRequirementsInfo2_null()
	{
		VkBufferMemoryRequirementsInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2;
		return init;
	}

	static inline VkBufferMemoryRequirementsInfo2 vkiBufferMemoryRequirementsInfo2(VkBuffer buffer)
	{
		VkBufferMemoryRequirementsInfo2 init = vkiBufferMemoryRequirementsInfo2_null();
		init.buffer = buffer;
		return init;
	}

	static inline VkImageMemoryRequirementsInfo2 vkiImageMemoryRequirementsInfo2_null()
	{
		VkImageMemoryRequirementsInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2;
		return init;
	}

	static inline VkImageMemoryRequirementsInfo2 vkiImageMemoryRequirementsInfo2(VkImage image)
	{
		VkImageMemoryRequirementsInfo2 init = vkiImageMemoryRequirementsInfo2_null();
		init.image = image;
		return init;
	}

	static inline VkImageSparseMemoryRequirementsInfo2 vkiImageSparseMemoryRequirementsInfo2_null()
	{
		VkImageSparseMemoryRequirementsInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2;
		return init;
	}

	static inline VkImageSparseMemoryRequirementsInfo2 vkiImageSparseMemoryRequirementsInfo2(VkImage image)
	{
		VkImageSparseMemoryRequirementsInfo2 init = vkiImageSparseMemoryRequirementsInfo2_null();
		init.image = image;
		return init;
	}

	static inline VkMemoryRequirements2 vkiMemoryRequirements2_null()
	{
		VkMemoryRequirements2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2;
		return init;
	}

	static inline VkMemoryRequirements2 vkiMemoryRequirements2(VkMemoryRequirements memoryRequirements)
	{
		VkMemoryRequirements2 init = vkiMemoryRequirements2_null();
		init.memoryRequirements = memoryRequirements;
		return init;
	}

	static inline VkSparseImageMemoryRequirements2 vkiSparseImageMemoryRequirements2_null()
	{
		VkSparseImageMemoryRequirements2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2;
		return init;
	}

	static inline VkSparseImageMemoryRequirements2 vkiSparseImageMemoryRequirements2(VkSparseImageMemoryRequirements memoryRequirements)
	{
		VkSparseImageMemoryRequirements2 init = vkiSparseImageMemoryRequirements2_null();
		init.memoryRequirements = memoryRequirements;
		return init;
	}

	static inline VkPhysicalDeviceFeatures2 vkiPhysicalDeviceFeatures2_null()
	{
		VkPhysicalDeviceFeatures2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
		return init;
	}

	static inline VkPhysicalDeviceFeatures2 vkiPhysicalDeviceFeatures2(VkPhysicalDeviceFeatures features)
	{
		VkPhysicalDeviceFeatures2 init = vkiPhysicalDeviceFeatures2_null();
		init.features = features;
		return init;
	}

	static inline VkPhysicalDeviceProperties2 vkiPhysicalDeviceProperties2_null()
	{
		VkPhysicalDeviceProperties2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
		return init;
	}

	static inline VkPhysicalDeviceProperties2 vkiPhysicalDeviceProperties2(VkPhysicalDeviceProperties properties)
	{
		VkPhysicalDeviceProperties2 init = vkiPhysicalDeviceProperties2_null();
		init.properties = properties;
		return init;
	}

	static inline VkFormatProperties2 vkiFormatProperties2_null()
	{
		VkFormatProperties2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2;
		return init;
	}

	static inline VkFormatProperties2 vkiFormatProperties2(VkFormatProperties formatProperties)
	{
		VkFormatProperties2 init = vkiFormatProperties2_null();
		init.formatProperties = formatProperties;
		return init;
	}

	static inline VkImageFormatProperties2 vkiImageFormatProperties2_null()
	{
		VkImageFormatProperties2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2;
		return init;
	}

	static inline VkImageFormatProperties2 vkiImageFormatProperties2(VkImageFormatProperties imageFormatProperties)
	{
		VkImageFormatProperties2 init = vkiImageFormatProperties2_null();
		init.imageFormatProperties = imageFormatProperties;
		return init;
	}

	static inline VkPhysicalDeviceImageFormatInfo2 vkiPhysicalDeviceImageFormatInfo2_null()
	{
		VkPhysicalDeviceImageFormatInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2;
		return init;
	}

	static inline VkPhysicalDeviceImageFormatInfo2 vkiPhysicalDeviceImageFormatInfo2(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage)
	{
		VkPhysicalDeviceImageFormatInfo2 init = vkiPhysicalDeviceImageFormatInfo2_null();
		init.format = format;
		init.type = type;
		init.tiling = tiling;
		init.usage = usage;
		return init;
	}

	static inline VkQueueFamilyProperties2 vkiQueueFamilyProperties2_null()
	{
		VkQueueFamilyProperties2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2;
		return init;
	}

	static inline VkQueueFamilyProperties2 vkiQueueFamilyProperties2(VkQueueFamilyProperties queueFamilyProperties)
	{
		VkQueueFamilyProperties2 init = vkiQueueFamilyProperties2_null();
		init.queueFamilyProperties = queueFamilyProperties;
		return init;
	}

	static inline VkPhysicalDeviceMemoryProperties2 vkiPhysicalDeviceMemoryProperties2_null()
	{
		VkPhysicalDeviceMemoryProperties2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2;
		return init;
	}

	static inline VkPhysicalDeviceMemoryProperties2 vkiPhysicalDeviceMemoryProperties2(VkPhysicalDeviceMemoryProperties memoryProperties)
	{
		VkPhysicalDeviceMemoryProperties2 init = vkiPhysicalDeviceMemoryProperties2_null();
		init.memoryProperties = memoryProperties;
		return init;
	}

	static inline VkSparseImageFormatProperties2 vkiSparseImageFormatProperties2_null()
	{
		VkSparseImageFormatProperties2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2;
		return init;
	}

	static inline VkSparseImageFormatProperties2 vkiSparseImageFormatProperties2(VkSparseImageFormatProperties properties)
	{
		VkSparseImageFormatProperties2 init = vkiSparseImageFormatProperties2_null();
		init.properties = properties;
		return init;
	}

	static inline VkPhysicalDeviceSparseImageFormatInfo2 vkiPhysicalDeviceSparseImageFormatInfo2_null()
	{
		VkPhysicalDeviceSparseImageFormatInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2;
		return init;
	}

	static inline VkPhysicalDeviceSparseImageFormatInfo2 vkiPhysicalDeviceSparseImageFormatInfo2(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling)
	{
		VkPhysicalDeviceSparseImageFormatInfo2 init = vkiPhysicalDeviceSparseImageFormatInfo2_null();
		init.format = format;
		init.type = type;
		init.samples = samples;
		init.usage = usage;
		init.tiling = tiling;
		return init;
	}

	static inline VkPhysicalDevicePointClippingProperties vkiPhysicalDevicePointClippingProperties_null()
	{
		VkPhysicalDevicePointClippingProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDevicePointClippingProperties vkiPhysicalDevicePointClippingProperties(VkPointClippingBehavior pointClippingBehavior)
	{
		VkPhysicalDevicePointClippingProperties init = vkiPhysicalDevicePointClippingProperties_null();
		init.pointClippingBehavior = pointClippingBehavior;
		return init;
	}

	static inline VkInputAttachmentAspectReference vkiInputAttachmentAspectReference_null()
	{
		VkInputAttachmentAspectReference init = {0};
		return init;
	}

	static inline VkInputAttachmentAspectReference vkiInputAttachmentAspectReference(uint32_t subpass, uint32_t inputAttachmentIndex, VkImageAspectFlags aspectMask)
	{
		VkInputAttachmentAspectReference init = vkiInputAttachmentAspectReference_null();
		init.subpass = subpass;
		init.inputAttachmentIndex = inputAttachmentIndex;
		init.aspectMask = aspectMask;
		return init;
	}

	static inline VkRenderPassInputAttachmentAspectCreateInfo vkiRenderPassInputAttachmentAspectCreateInfo_null()
	{
		VkRenderPassInputAttachmentAspectCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO;
		return init;
	}

	static inline VkRenderPassInputAttachmentAspectCreateInfo vkiRenderPassInputAttachmentAspectCreateInfo(uint32_t aspectReferenceCount, const VkInputAttachmentAspectReference *pAspectReferences)
	{
		VkRenderPassInputAttachmentAspectCreateInfo init = vkiRenderPassInputAttachmentAspectCreateInfo_null();
		init.aspectReferenceCount = aspectReferenceCount;
		init.pAspectReferences = pAspectReferences;
		return init;
	}

	static inline VkImageViewUsageCreateInfo vkiImageViewUsageCreateInfo_null()
	{
		VkImageViewUsageCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO;
		return init;
	}

	static inline VkImageViewUsageCreateInfo vkiImageViewUsageCreateInfo(VkImageUsageFlags usage)
	{
		VkImageViewUsageCreateInfo init = vkiImageViewUsageCreateInfo_null();
		init.usage = usage;
		return init;
	}

	static inline VkPipelineTessellationDomainOriginStateCreateInfo vkiPipelineTessellationDomainOriginStateCreateInfo_null()
	{
		VkPipelineTessellationDomainOriginStateCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO;
		return init;
	}

	static inline VkPipelineTessellationDomainOriginStateCreateInfo vkiPipelineTessellationDomainOriginStateCreateInfo(VkTessellationDomainOrigin domainOrigin)
	{
		VkPipelineTessellationDomainOriginStateCreateInfo init = vkiPipelineTessellationDomainOriginStateCreateInfo_null();
		init.domainOrigin = domainOrigin;
		return init;
	}

	static inline VkRenderPassMultiviewCreateInfo vkiRenderPassMultiviewCreateInfo_null()
	{
		VkRenderPassMultiviewCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO;
		return init;
	}

	static inline VkRenderPassMultiviewCreateInfo vkiRenderPassMultiviewCreateInfo(uint32_t subpassCount, const uint32_t *pViewMasks, uint32_t dependencyCount, const int32_t *pViewOffsets, uint32_t correlationMaskCount, const uint32_t *pCorrelationMasks)
	{
		VkRenderPassMultiviewCreateInfo init = vkiRenderPassMultiviewCreateInfo_null();
		init.subpassCount = subpassCount;
		init.pViewMasks = pViewMasks;
		init.dependencyCount = dependencyCount;
		init.pViewOffsets = pViewOffsets;
		init.correlationMaskCount = correlationMaskCount;
		init.pCorrelationMasks = pCorrelationMasks;
		return init;
	}

	static inline VkPhysicalDeviceMultiviewFeatures vkiPhysicalDeviceMultiviewFeatures_null()
	{
		VkPhysicalDeviceMultiviewFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceMultiviewFeatures vkiPhysicalDeviceMultiviewFeatures(VkBool32 multiview, VkBool32 multiviewGeometryShader, VkBool32 multiviewTessellationShader)
	{
		VkPhysicalDeviceMultiviewFeatures init = vkiPhysicalDeviceMultiviewFeatures_null();
		init.multiview = multiview;
		init.multiviewGeometryShader = multiviewGeometryShader;
		init.multiviewTessellationShader = multiviewTessellationShader;
		return init;
	}

	static inline VkPhysicalDeviceMultiviewProperties vkiPhysicalDeviceMultiviewProperties_null()
	{
		VkPhysicalDeviceMultiviewProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceMultiviewProperties vkiPhysicalDeviceMultiviewProperties(uint32_t maxMultiviewViewCount, uint32_t maxMultiviewInstanceIndex)
	{
		VkPhysicalDeviceMultiviewProperties init = vkiPhysicalDeviceMultiviewProperties_null();
		init.maxMultiviewViewCount = maxMultiviewViewCount;
		init.maxMultiviewInstanceIndex = maxMultiviewInstanceIndex;
		return init;
	}

	static inline VkPhysicalDeviceVariablePointersFeatures vkiPhysicalDeviceVariablePointersFeatures_null()
	{
		VkPhysicalDeviceVariablePointersFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceVariablePointersFeatures vkiPhysicalDeviceVariablePointersFeatures(VkBool32 variablePointersStorageBuffer, VkBool32 variablePointers)
	{
		VkPhysicalDeviceVariablePointersFeatures init = vkiPhysicalDeviceVariablePointersFeatures_null();
		init.variablePointersStorageBuffer = variablePointersStorageBuffer;
		init.variablePointers = variablePointers;
		return init;
	}

	static inline VkPhysicalDeviceProtectedMemoryFeatures vkiPhysicalDeviceProtectedMemoryFeatures_null()
	{
		VkPhysicalDeviceProtectedMemoryFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceProtectedMemoryFeatures vkiPhysicalDeviceProtectedMemoryFeatures(VkBool32 protectedMemory)
	{
		VkPhysicalDeviceProtectedMemoryFeatures init = vkiPhysicalDeviceProtectedMemoryFeatures_null();
		init.protectedMemory = protectedMemory;
		return init;
	}

	static inline VkPhysicalDeviceProtectedMemoryProperties vkiPhysicalDeviceProtectedMemoryProperties_null()
	{
		VkPhysicalDeviceProtectedMemoryProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceProtectedMemoryProperties vkiPhysicalDeviceProtectedMemoryProperties(VkBool32 protectedNoFault)
	{
		VkPhysicalDeviceProtectedMemoryProperties init = vkiPhysicalDeviceProtectedMemoryProperties_null();
		init.protectedNoFault = protectedNoFault;
		return init;
	}

	static inline VkDeviceQueueInfo2 vkiDeviceQueueInfo2_null()
	{
		VkDeviceQueueInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2;
		return init;
	}

	static inline VkDeviceQueueInfo2 vkiDeviceQueueInfo2(uint32_t queueFamilyIndex, uint32_t queueIndex)
	{
		VkDeviceQueueInfo2 init = vkiDeviceQueueInfo2_null();
		init.queueFamilyIndex = queueFamilyIndex;
		init.queueIndex = queueIndex;
		return init;
	}

	static inline VkProtectedSubmitInfo vkiProtectedSubmitInfo_null()
	{
		VkProtectedSubmitInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO;
		return init;
	}

	static inline VkProtectedSubmitInfo vkiProtectedSubmitInfo(VkBool32 protectedSubmit)
	{
		VkProtectedSubmitInfo init = vkiProtectedSubmitInfo_null();
		init.protectedSubmit = protectedSubmit;
		return init;
	}

	static inline VkSamplerYcbcrConversionCreateInfo vkiSamplerYcbcrConversionCreateInfo_null()
	{
		VkSamplerYcbcrConversionCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO;
		return init;
	}

	static inline VkSamplerYcbcrConversionCreateInfo vkiSamplerYcbcrConversionCreateInfo(VkFormat format, VkSamplerYcbcrModelConversion ycbcrModel, VkSamplerYcbcrRange ycbcrRange, VkComponentMapping components, VkChromaLocation xChromaOffset, VkChromaLocation yChromaOffset, VkFilter chromaFilter, VkBool32 forceExplicitReconstruction)
	{
		VkSamplerYcbcrConversionCreateInfo init = vkiSamplerYcbcrConversionCreateInfo_null();
		init.format = format;
		init.ycbcrModel = ycbcrModel;
		init.ycbcrRange = ycbcrRange;
		init.components = components;
		init.xChromaOffset = xChromaOffset;
		init.yChromaOffset = yChromaOffset;
		init.chromaFilter = chromaFilter;
		init.forceExplicitReconstruction = forceExplicitReconstruction;
		return init;
	}

	static inline VkSamplerYcbcrConversionInfo vkiSamplerYcbcrConversionInfo_null()
	{
		VkSamplerYcbcrConversionInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO;
		return init;
	}

	static inline VkSamplerYcbcrConversionInfo vkiSamplerYcbcrConversionInfo(VkSamplerYcbcrConversion conversion)
	{
		VkSamplerYcbcrConversionInfo init = vkiSamplerYcbcrConversionInfo_null();
		init.conversion = conversion;
		return init;
	}

	static inline VkBindImagePlaneMemoryInfo vkiBindImagePlaneMemoryInfo_null()
	{
		VkBindImagePlaneMemoryInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO;
		return init;
	}

	static inline VkBindImagePlaneMemoryInfo vkiBindImagePlaneMemoryInfo(VkImageAspectFlagBits planeAspect)
	{
		VkBindImagePlaneMemoryInfo init = vkiBindImagePlaneMemoryInfo_null();
		init.planeAspect = planeAspect;
		return init;
	}

	static inline VkImagePlaneMemoryRequirementsInfo vkiImagePlaneMemoryRequirementsInfo_null()
	{
		VkImagePlaneMemoryRequirementsInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO;
		return init;
	}

	static inline VkImagePlaneMemoryRequirementsInfo vkiImagePlaneMemoryRequirementsInfo(VkImageAspectFlagBits planeAspect)
	{
		VkImagePlaneMemoryRequirementsInfo init = vkiImagePlaneMemoryRequirementsInfo_null();
		init.planeAspect = planeAspect;
		return init;
	}

	static inline VkPhysicalDeviceSamplerYcbcrConversionFeatures vkiPhysicalDeviceSamplerYcbcrConversionFeatures_null()
	{
		VkPhysicalDeviceSamplerYcbcrConversionFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceSamplerYcbcrConversionFeatures vkiPhysicalDeviceSamplerYcbcrConversionFeatures(VkBool32 samplerYcbcrConversion)
	{
		VkPhysicalDeviceSamplerYcbcrConversionFeatures init = vkiPhysicalDeviceSamplerYcbcrConversionFeatures_null();
		init.samplerYcbcrConversion = samplerYcbcrConversion;
		return init;
	}

	static inline VkSamplerYcbcrConversionImageFormatProperties vkiSamplerYcbcrConversionImageFormatProperties_null()
	{
		VkSamplerYcbcrConversionImageFormatProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES;
		return init;
	}

	static inline VkSamplerYcbcrConversionImageFormatProperties vkiSamplerYcbcrConversionImageFormatProperties(uint32_t combinedImageSamplerDescriptorCount)
	{
		VkSamplerYcbcrConversionImageFormatProperties init = vkiSamplerYcbcrConversionImageFormatProperties_null();
		init.combinedImageSamplerDescriptorCount = combinedImageSamplerDescriptorCount;
		return init;
	}

	static inline VkDescriptorUpdateTemplateEntry vkiDescriptorUpdateTemplateEntry_null()
	{
		VkDescriptorUpdateTemplateEntry init = {0};
		return init;
	}

	static inline VkDescriptorUpdateTemplateEntry vkiDescriptorUpdateTemplateEntry(uint32_t dstBinding, uint32_t dstArrayElement, uint32_t descriptorCount, VkDescriptorType descriptorType, size_t offset, size_t stride)
	{
		VkDescriptorUpdateTemplateEntry init = vkiDescriptorUpdateTemplateEntry_null();
		init.dstBinding = dstBinding;
		init.dstArrayElement = dstArrayElement;
		init.descriptorCount = descriptorCount;
		init.descriptorType = descriptorType;
		init.offset = offset;
		init.stride = stride;
		return init;
	}

	static inline VkDescriptorUpdateTemplateCreateInfo vkiDescriptorUpdateTemplateCreateInfo_null()
	{
		VkDescriptorUpdateTemplateCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO;
		return init;
	}

	static inline VkDescriptorUpdateTemplateCreateInfo vkiDescriptorUpdateTemplateCreateInfo(uint32_t descriptorUpdateEntryCount, const VkDescriptorUpdateTemplateEntry *pDescriptorUpdateEntries, VkDescriptorUpdateTemplateType templateType, VkDescriptorSetLayout descriptorSetLayout, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout pipelineLayout, uint32_t set)
	{
		VkDescriptorUpdateTemplateCreateInfo init = vkiDescriptorUpdateTemplateCreateInfo_null();
		init.descriptorUpdateEntryCount = descriptorUpdateEntryCount;
		init.pDescriptorUpdateEntries = pDescriptorUpdateEntries;
		init.templateType = templateType;
		init.descriptorSetLayout = descriptorSetLayout;
		init.pipelineBindPoint = pipelineBindPoint;
		init.pipelineLayout = pipelineLayout;
		init.set = set;
		return init;
	}

	static inline VkExternalMemoryProperties vkiExternalMemoryProperties_null()
	{
		VkExternalMemoryProperties init = {0};
		return init;
	}

	static inline VkExternalMemoryProperties vkiExternalMemoryProperties(VkExternalMemoryFeatureFlags externalMemoryFeatures, VkExternalMemoryHandleTypeFlags exportFromImportedHandleTypes, VkExternalMemoryHandleTypeFlags compatibleHandleTypes)
	{
		VkExternalMemoryProperties init = vkiExternalMemoryProperties_null();
		init.externalMemoryFeatures = externalMemoryFeatures;
		init.exportFromImportedHandleTypes = exportFromImportedHandleTypes;
		init.compatibleHandleTypes = compatibleHandleTypes;
		return init;
	}

	static inline VkPhysicalDeviceExternalImageFormatInfo vkiPhysicalDeviceExternalImageFormatInfo_null()
	{
		VkPhysicalDeviceExternalImageFormatInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO;
		return init;
	}

	static inline VkPhysicalDeviceExternalImageFormatInfo vkiPhysicalDeviceExternalImageFormatInfo(VkExternalMemoryHandleTypeFlagBits handleType)
	{
		VkPhysicalDeviceExternalImageFormatInfo init = vkiPhysicalDeviceExternalImageFormatInfo_null();
		init.handleType = handleType;
		return init;
	}

	static inline VkExternalImageFormatProperties vkiExternalImageFormatProperties_null()
	{
		VkExternalImageFormatProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES;
		return init;
	}

	static inline VkExternalImageFormatProperties vkiExternalImageFormatProperties(VkExternalMemoryProperties externalMemoryProperties)
	{
		VkExternalImageFormatProperties init = vkiExternalImageFormatProperties_null();
		init.externalMemoryProperties = externalMemoryProperties;
		return init;
	}

	static inline VkPhysicalDeviceExternalBufferInfo vkiPhysicalDeviceExternalBufferInfo_null()
	{
		VkPhysicalDeviceExternalBufferInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO;
		return init;
	}

	static inline VkPhysicalDeviceExternalBufferInfo vkiPhysicalDeviceExternalBufferInfo(VkBufferUsageFlags usage, VkExternalMemoryHandleTypeFlagBits handleType)
	{
		VkPhysicalDeviceExternalBufferInfo init = vkiPhysicalDeviceExternalBufferInfo_null();
		init.usage = usage;
		init.handleType = handleType;
		return init;
	}

	static inline VkExternalBufferProperties vkiExternalBufferProperties_null()
	{
		VkExternalBufferProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES;
		return init;
	}

	static inline VkExternalBufferProperties vkiExternalBufferProperties(VkExternalMemoryProperties externalMemoryProperties)
	{
		VkExternalBufferProperties init = vkiExternalBufferProperties_null();
		init.externalMemoryProperties = externalMemoryProperties;
		return init;
	}

	static inline VkPhysicalDeviceIDProperties vkiPhysicalDeviceIDProperties_null()
	{
		VkPhysicalDeviceIDProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceIDProperties vkiPhysicalDeviceIDProperties(uint32_t deviceNodeMask, VkBool32 deviceLUIDValid)
	{
		VkPhysicalDeviceIDProperties init = vkiPhysicalDeviceIDProperties_null();
		init.deviceNodeMask = deviceNodeMask;
		init.deviceLUIDValid = deviceLUIDValid;
		return init;
	}

	static inline VkExternalMemoryImageCreateInfo vkiExternalMemoryImageCreateInfo_null()
	{
		VkExternalMemoryImageCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO;
		return init;
	}

	static inline VkExternalMemoryImageCreateInfo vkiExternalMemoryImageCreateInfo(VkExternalMemoryHandleTypeFlags handleTypes)
	{
		VkExternalMemoryImageCreateInfo init = vkiExternalMemoryImageCreateInfo_null();
		init.handleTypes = handleTypes;
		return init;
	}

	static inline VkExternalMemoryBufferCreateInfo vkiExternalMemoryBufferCreateInfo_null()
	{
		VkExternalMemoryBufferCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO;
		return init;
	}

	static inline VkExternalMemoryBufferCreateInfo vkiExternalMemoryBufferCreateInfo(VkExternalMemoryHandleTypeFlags handleTypes)
	{
		VkExternalMemoryBufferCreateInfo init = vkiExternalMemoryBufferCreateInfo_null();
		init.handleTypes = handleTypes;
		return init;
	}

	static inline VkExportMemoryAllocateInfo vkiExportMemoryAllocateInfo_null()
	{
		VkExportMemoryAllocateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO;
		return init;
	}

	static inline VkExportMemoryAllocateInfo vkiExportMemoryAllocateInfo(VkExternalMemoryHandleTypeFlags handleTypes)
	{
		VkExportMemoryAllocateInfo init = vkiExportMemoryAllocateInfo_null();
		init.handleTypes = handleTypes;
		return init;
	}

	static inline VkPhysicalDeviceExternalFenceInfo vkiPhysicalDeviceExternalFenceInfo_null()
	{
		VkPhysicalDeviceExternalFenceInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO;
		return init;
	}

	static inline VkPhysicalDeviceExternalFenceInfo vkiPhysicalDeviceExternalFenceInfo(VkExternalFenceHandleTypeFlagBits handleType)
	{
		VkPhysicalDeviceExternalFenceInfo init = vkiPhysicalDeviceExternalFenceInfo_null();
		init.handleType = handleType;
		return init;
	}

	static inline VkExternalFenceProperties vkiExternalFenceProperties_null()
	{
		VkExternalFenceProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES;
		return init;
	}

	static inline VkExternalFenceProperties vkiExternalFenceProperties(VkExternalFenceHandleTypeFlags exportFromImportedHandleTypes, VkExternalFenceHandleTypeFlags compatibleHandleTypes, VkExternalFenceFeatureFlags externalFenceFeatures)
	{
		VkExternalFenceProperties init = vkiExternalFenceProperties_null();
		init.exportFromImportedHandleTypes = exportFromImportedHandleTypes;
		init.compatibleHandleTypes = compatibleHandleTypes;
		init.externalFenceFeatures = externalFenceFeatures;
		return init;
	}

	static inline VkExportFenceCreateInfo vkiExportFenceCreateInfo_null()
	{
		VkExportFenceCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO;
		return init;
	}

	static inline VkExportFenceCreateInfo vkiExportFenceCreateInfo(VkExternalFenceHandleTypeFlags handleTypes)
	{
		VkExportFenceCreateInfo init = vkiExportFenceCreateInfo_null();
		init.handleTypes = handleTypes;
		return init;
	}

	static inline VkExportSemaphoreCreateInfo vkiExportSemaphoreCreateInfo_null()
	{
		VkExportSemaphoreCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO;
		return init;
	}

	static inline VkExportSemaphoreCreateInfo vkiExportSemaphoreCreateInfo(VkExternalSemaphoreHandleTypeFlags handleTypes)
	{
		VkExportSemaphoreCreateInfo init = vkiExportSemaphoreCreateInfo_null();
		init.handleTypes = handleTypes;
		return init;
	}

	static inline VkPhysicalDeviceExternalSemaphoreInfo vkiPhysicalDeviceExternalSemaphoreInfo_null()
	{
		VkPhysicalDeviceExternalSemaphoreInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO;
		return init;
	}

	static inline VkPhysicalDeviceExternalSemaphoreInfo vkiPhysicalDeviceExternalSemaphoreInfo(VkExternalSemaphoreHandleTypeFlagBits handleType)
	{
		VkPhysicalDeviceExternalSemaphoreInfo init = vkiPhysicalDeviceExternalSemaphoreInfo_null();
		init.handleType = handleType;
		return init;
	}

	static inline VkExternalSemaphoreProperties vkiExternalSemaphoreProperties_null()
	{
		VkExternalSemaphoreProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES;
		return init;
	}

	static inline VkExternalSemaphoreProperties vkiExternalSemaphoreProperties(VkExternalSemaphoreHandleTypeFlags exportFromImportedHandleTypes, VkExternalSemaphoreHandleTypeFlags compatibleHandleTypes, VkExternalSemaphoreFeatureFlags externalSemaphoreFeatures)
	{
		VkExternalSemaphoreProperties init = vkiExternalSemaphoreProperties_null();
		init.exportFromImportedHandleTypes = exportFromImportedHandleTypes;
		init.compatibleHandleTypes = compatibleHandleTypes;
		init.externalSemaphoreFeatures = externalSemaphoreFeatures;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance3Properties vkiPhysicalDeviceMaintenance3Properties_null()
	{
		VkPhysicalDeviceMaintenance3Properties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance3Properties vkiPhysicalDeviceMaintenance3Properties(uint32_t maxPerSetDescriptors, VkDeviceSize maxMemoryAllocationSize)
	{
		VkPhysicalDeviceMaintenance3Properties init = vkiPhysicalDeviceMaintenance3Properties_null();
		init.maxPerSetDescriptors = maxPerSetDescriptors;
		init.maxMemoryAllocationSize = maxMemoryAllocationSize;
		return init;
	}

	static inline VkDescriptorSetLayoutSupport vkiDescriptorSetLayoutSupport_null()
	{
		VkDescriptorSetLayoutSupport init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT;
		return init;
	}

	static inline VkDescriptorSetLayoutSupport vkiDescriptorSetLayoutSupport(VkBool32 supported)
	{
		VkDescriptorSetLayoutSupport init = vkiDescriptorSetLayoutSupport_null();
		init.supported = supported;
		return init;
	}

	static inline VkPhysicalDeviceShaderDrawParametersFeatures vkiPhysicalDeviceShaderDrawParametersFeatures_null()
	{
		VkPhysicalDeviceShaderDrawParametersFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceShaderDrawParametersFeatures vkiPhysicalDeviceShaderDrawParametersFeatures(VkBool32 shaderDrawParameters)
	{
		VkPhysicalDeviceShaderDrawParametersFeatures init = vkiPhysicalDeviceShaderDrawParametersFeatures_null();
		init.shaderDrawParameters = shaderDrawParameters;
		return init;
	}

	static inline VkPhysicalDeviceVulkan11Features vkiPhysicalDeviceVulkan11Features_null()
	{
		VkPhysicalDeviceVulkan11Features init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceVulkan11Features vkiPhysicalDeviceVulkan11Features(VkBool32 storageBuffer16BitAccess, VkBool32 uniformAndStorageBuffer16BitAccess, VkBool32 storagePushConstant16, VkBool32 storageInputOutput16, VkBool32 multiview, VkBool32 multiviewGeometryShader, VkBool32 multiviewTessellationShader, VkBool32 variablePointersStorageBuffer, VkBool32 variablePointers, VkBool32 protectedMemory, VkBool32 samplerYcbcrConversion, VkBool32 shaderDrawParameters)
	{
		VkPhysicalDeviceVulkan11Features init = vkiPhysicalDeviceVulkan11Features_null();
		init.storageBuffer16BitAccess = storageBuffer16BitAccess;
		init.uniformAndStorageBuffer16BitAccess = uniformAndStorageBuffer16BitAccess;
		init.storagePushConstant16 = storagePushConstant16;
		init.storageInputOutput16 = storageInputOutput16;
		init.multiview = multiview;
		init.multiviewGeometryShader = multiviewGeometryShader;
		init.multiviewTessellationShader = multiviewTessellationShader;
		init.variablePointersStorageBuffer = variablePointersStorageBuffer;
		init.variablePointers = variablePointers;
		init.protectedMemory = protectedMemory;
		init.samplerYcbcrConversion = samplerYcbcrConversion;
		init.shaderDrawParameters = shaderDrawParameters;
		return init;
	}

	static inline VkPhysicalDeviceVulkan11Properties vkiPhysicalDeviceVulkan11Properties_null()
	{
		VkPhysicalDeviceVulkan11Properties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceVulkan11Properties vkiPhysicalDeviceVulkan11Properties(uint32_t deviceNodeMask, VkBool32 deviceLUIDValid, uint32_t subgroupSize, VkShaderStageFlags subgroupSupportedStages, VkSubgroupFeatureFlags subgroupSupportedOperations, VkBool32 subgroupQuadOperationsInAllStages, VkPointClippingBehavior pointClippingBehavior, uint32_t maxMultiviewViewCount, uint32_t maxMultiviewInstanceIndex, VkBool32 protectedNoFault, uint32_t maxPerSetDescriptors, VkDeviceSize maxMemoryAllocationSize)
	{
		VkPhysicalDeviceVulkan11Properties init = vkiPhysicalDeviceVulkan11Properties_null();
		init.deviceNodeMask = deviceNodeMask;
		init.deviceLUIDValid = deviceLUIDValid;
		init.subgroupSize = subgroupSize;
		init.subgroupSupportedStages = subgroupSupportedStages;
		init.subgroupSupportedOperations = subgroupSupportedOperations;
		init.subgroupQuadOperationsInAllStages = subgroupQuadOperationsInAllStages;
		init.pointClippingBehavior = pointClippingBehavior;
		init.maxMultiviewViewCount = maxMultiviewViewCount;
		init.maxMultiviewInstanceIndex = maxMultiviewInstanceIndex;
		init.protectedNoFault = protectedNoFault;
		init.maxPerSetDescriptors = maxPerSetDescriptors;
		init.maxMemoryAllocationSize = maxMemoryAllocationSize;
		return init;
	}

	static inline VkPhysicalDeviceVulkan12Features vkiPhysicalDeviceVulkan12Features_null()
	{
		VkPhysicalDeviceVulkan12Features init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceVulkan12Features vkiPhysicalDeviceVulkan12Features(VkBool32 samplerMirrorClampToEdge, VkBool32 drawIndirectCount, VkBool32 storageBuffer8BitAccess, VkBool32 uniformAndStorageBuffer8BitAccess, VkBool32 storagePushConstant8, VkBool32 shaderBufferInt64Atomics, VkBool32 shaderSharedInt64Atomics, VkBool32 shaderFloat16, VkBool32 shaderInt8, VkBool32 descriptorIndexing, VkBool32 shaderInputAttachmentArrayDynamicIndexing, VkBool32 shaderUniformTexelBufferArrayDynamicIndexing, VkBool32 shaderStorageTexelBufferArrayDynamicIndexing, VkBool32 shaderUniformBufferArrayNonUniformIndexing, VkBool32 shaderSampledImageArrayNonUniformIndexing, VkBool32 shaderStorageBufferArrayNonUniformIndexing, VkBool32 shaderStorageImageArrayNonUniformIndexing, VkBool32 shaderInputAttachmentArrayNonUniformIndexing, VkBool32 shaderUniformTexelBufferArrayNonUniformIndexing, VkBool32 shaderStorageTexelBufferArrayNonUniformIndexing, VkBool32 descriptorBindingUniformBufferUpdateAfterBind, VkBool32 descriptorBindingSampledImageUpdateAfterBind, VkBool32 descriptorBindingStorageImageUpdateAfterBind, VkBool32 descriptorBindingStorageBufferUpdateAfterBind, VkBool32 descriptorBindingUniformTexelBufferUpdateAfterBind, VkBool32 descriptorBindingStorageTexelBufferUpdateAfterBind, VkBool32 descriptorBindingUpdateUnusedWhilePending, VkBool32 descriptorBindingPartiallyBound, VkBool32 descriptorBindingVariableDescriptorCount, VkBool32 runtimeDescriptorArray, VkBool32 samplerFilterMinmax, VkBool32 scalarBlockLayout, VkBool32 imagelessFramebuffer, VkBool32 uniformBufferStandardLayout, VkBool32 shaderSubgroupExtendedTypes, VkBool32 separateDepthStencilLayouts, VkBool32 hostQueryReset, VkBool32 timelineSemaphore, VkBool32 bufferDeviceAddress, VkBool32 bufferDeviceAddressCaptureReplay, VkBool32 bufferDeviceAddressMultiDevice, VkBool32 vulkanMemoryModel, VkBool32 vulkanMemoryModelDeviceScope, VkBool32 vulkanMemoryModelAvailabilityVisibilityChains, VkBool32 shaderOutputViewportIndex, VkBool32 shaderOutputLayer, VkBool32 subgroupBroadcastDynamicId)
	{
		VkPhysicalDeviceVulkan12Features init = vkiPhysicalDeviceVulkan12Features_null();
		init.samplerMirrorClampToEdge = samplerMirrorClampToEdge;
		init.drawIndirectCount = drawIndirectCount;
		init.storageBuffer8BitAccess = storageBuffer8BitAccess;
		init.uniformAndStorageBuffer8BitAccess = uniformAndStorageBuffer8BitAccess;
		init.storagePushConstant8 = storagePushConstant8;
		init.shaderBufferInt64Atomics = shaderBufferInt64Atomics;
		init.shaderSharedInt64Atomics = shaderSharedInt64Atomics;
		init.shaderFloat16 = shaderFloat16;
		init.shaderInt8 = shaderInt8;
		init.descriptorIndexing = descriptorIndexing;
		init.shaderInputAttachmentArrayDynamicIndexing = shaderInputAttachmentArrayDynamicIndexing;
		init.shaderUniformTexelBufferArrayDynamicIndexing = shaderUniformTexelBufferArrayDynamicIndexing;
		init.shaderStorageTexelBufferArrayDynamicIndexing = shaderStorageTexelBufferArrayDynamicIndexing;
		init.shaderUniformBufferArrayNonUniformIndexing = shaderUniformBufferArrayNonUniformIndexing;
		init.shaderSampledImageArrayNonUniformIndexing = shaderSampledImageArrayNonUniformIndexing;
		init.shaderStorageBufferArrayNonUniformIndexing = shaderStorageBufferArrayNonUniformIndexing;
		init.shaderStorageImageArrayNonUniformIndexing = shaderStorageImageArrayNonUniformIndexing;
		init.shaderInputAttachmentArrayNonUniformIndexing = shaderInputAttachmentArrayNonUniformIndexing;
		init.shaderUniformTexelBufferArrayNonUniformIndexing = shaderUniformTexelBufferArrayNonUniformIndexing;
		init.shaderStorageTexelBufferArrayNonUniformIndexing = shaderStorageTexelBufferArrayNonUniformIndexing;
		init.descriptorBindingUniformBufferUpdateAfterBind = descriptorBindingUniformBufferUpdateAfterBind;
		init.descriptorBindingSampledImageUpdateAfterBind = descriptorBindingSampledImageUpdateAfterBind;
		init.descriptorBindingStorageImageUpdateAfterBind = descriptorBindingStorageImageUpdateAfterBind;
		init.descriptorBindingStorageBufferUpdateAfterBind = descriptorBindingStorageBufferUpdateAfterBind;
		init.descriptorBindingUniformTexelBufferUpdateAfterBind = descriptorBindingUniformTexelBufferUpdateAfterBind;
		init.descriptorBindingStorageTexelBufferUpdateAfterBind = descriptorBindingStorageTexelBufferUpdateAfterBind;
		init.descriptorBindingUpdateUnusedWhilePending = descriptorBindingUpdateUnusedWhilePending;
		init.descriptorBindingPartiallyBound = descriptorBindingPartiallyBound;
		init.descriptorBindingVariableDescriptorCount = descriptorBindingVariableDescriptorCount;
		init.runtimeDescriptorArray = runtimeDescriptorArray;
		init.samplerFilterMinmax = samplerFilterMinmax;
		init.scalarBlockLayout = scalarBlockLayout;
		init.imagelessFramebuffer = imagelessFramebuffer;
		init.uniformBufferStandardLayout = uniformBufferStandardLayout;
		init.shaderSubgroupExtendedTypes = shaderSubgroupExtendedTypes;
		init.separateDepthStencilLayouts = separateDepthStencilLayouts;
		init.hostQueryReset = hostQueryReset;
		init.timelineSemaphore = timelineSemaphore;
		init.bufferDeviceAddress = bufferDeviceAddress;
		init.bufferDeviceAddressCaptureReplay = bufferDeviceAddressCaptureReplay;
		init.bufferDeviceAddressMultiDevice = bufferDeviceAddressMultiDevice;
		init.vulkanMemoryModel = vulkanMemoryModel;
		init.vulkanMemoryModelDeviceScope = vulkanMemoryModelDeviceScope;
		init.vulkanMemoryModelAvailabilityVisibilityChains = vulkanMemoryModelAvailabilityVisibilityChains;
		init.shaderOutputViewportIndex = shaderOutputViewportIndex;
		init.shaderOutputLayer = shaderOutputLayer;
		init.subgroupBroadcastDynamicId = subgroupBroadcastDynamicId;
		return init;
	}

	static inline VkConformanceVersion vkiConformanceVersion_null()
	{
		VkConformanceVersion init = {0};
		return init;
	}

	static inline VkConformanceVersion vkiConformanceVersion(uint8_t major, uint8_t minor, uint8_t subminor, uint8_t patch)
	{
		VkConformanceVersion init = vkiConformanceVersion_null();
		init.major = major;
		init.minor = minor;
		init.subminor = subminor;
		init.patch = patch;
		return init;
	}

	static inline VkPhysicalDeviceVulkan12Properties vkiPhysicalDeviceVulkan12Properties_null()
	{
		VkPhysicalDeviceVulkan12Properties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceVulkan12Properties vkiPhysicalDeviceVulkan12Properties(VkDriverId driverID, VkConformanceVersion conformanceVersion, VkShaderFloatControlsIndependence denormBehaviorIndependence, VkShaderFloatControlsIndependence roundingModeIndependence, VkBool32 shaderSignedZeroInfNanPreserveFloat16, VkBool32 shaderSignedZeroInfNanPreserveFloat32, VkBool32 shaderSignedZeroInfNanPreserveFloat64, VkBool32 shaderDenormPreserveFloat16, VkBool32 shaderDenormPreserveFloat32, VkBool32 shaderDenormPreserveFloat64, VkBool32 shaderDenormFlushToZeroFloat16, VkBool32 shaderDenormFlushToZeroFloat32, VkBool32 shaderDenormFlushToZeroFloat64, VkBool32 shaderRoundingModeRTEFloat16, VkBool32 shaderRoundingModeRTEFloat32, VkBool32 shaderRoundingModeRTEFloat64, VkBool32 shaderRoundingModeRTZFloat16, VkBool32 shaderRoundingModeRTZFloat32, VkBool32 shaderRoundingModeRTZFloat64, uint32_t maxUpdateAfterBindDescriptorsInAllPools, VkBool32 shaderUniformBufferArrayNonUniformIndexingNative, VkBool32 shaderSampledImageArrayNonUniformIndexingNative, VkBool32 shaderStorageBufferArrayNonUniformIndexingNative, VkBool32 shaderStorageImageArrayNonUniformIndexingNative, VkBool32 shaderInputAttachmentArrayNonUniformIndexingNative, VkBool32 robustBufferAccessUpdateAfterBind, VkBool32 quadDivergentImplicitLod, uint32_t maxPerStageDescriptorUpdateAfterBindSamplers, uint32_t maxPerStageDescriptorUpdateAfterBindUniformBuffers, uint32_t maxPerStageDescriptorUpdateAfterBindStorageBuffers, uint32_t maxPerStageDescriptorUpdateAfterBindSampledImages, uint32_t maxPerStageDescriptorUpdateAfterBindStorageImages, uint32_t maxPerStageDescriptorUpdateAfterBindInputAttachments, uint32_t maxPerStageUpdateAfterBindResources, uint32_t maxDescriptorSetUpdateAfterBindSamplers, uint32_t maxDescriptorSetUpdateAfterBindUniformBuffers, uint32_t maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, uint32_t maxDescriptorSetUpdateAfterBindStorageBuffers, uint32_t maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, uint32_t maxDescriptorSetUpdateAfterBindSampledImages, uint32_t maxDescriptorSetUpdateAfterBindStorageImages, uint32_t maxDescriptorSetUpdateAfterBindInputAttachments, VkResolveModeFlags supportedDepthResolveModes, VkResolveModeFlags supportedStencilResolveModes, VkBool32 independentResolveNone, VkBool32 independentResolve, VkBool32 filterMinmaxSingleComponentFormats, VkBool32 filterMinmaxImageComponentMapping, uint64_t maxTimelineSemaphoreValueDifference, VkSampleCountFlags framebufferIntegerColorSampleCounts)
	{
		VkPhysicalDeviceVulkan12Properties init = vkiPhysicalDeviceVulkan12Properties_null();
		init.driverID = driverID;
		init.conformanceVersion = conformanceVersion;
		init.denormBehaviorIndependence = denormBehaviorIndependence;
		init.roundingModeIndependence = roundingModeIndependence;
		init.shaderSignedZeroInfNanPreserveFloat16 = shaderSignedZeroInfNanPreserveFloat16;
		init.shaderSignedZeroInfNanPreserveFloat32 = shaderSignedZeroInfNanPreserveFloat32;
		init.shaderSignedZeroInfNanPreserveFloat64 = shaderSignedZeroInfNanPreserveFloat64;
		init.shaderDenormPreserveFloat16 = shaderDenormPreserveFloat16;
		init.shaderDenormPreserveFloat32 = shaderDenormPreserveFloat32;
		init.shaderDenormPreserveFloat64 = shaderDenormPreserveFloat64;
		init.shaderDenormFlushToZeroFloat16 = shaderDenormFlushToZeroFloat16;
		init.shaderDenormFlushToZeroFloat32 = shaderDenormFlushToZeroFloat32;
		init.shaderDenormFlushToZeroFloat64 = shaderDenormFlushToZeroFloat64;
		init.shaderRoundingModeRTEFloat16 = shaderRoundingModeRTEFloat16;
		init.shaderRoundingModeRTEFloat32 = shaderRoundingModeRTEFloat32;
		init.shaderRoundingModeRTEFloat64 = shaderRoundingModeRTEFloat64;
		init.shaderRoundingModeRTZFloat16 = shaderRoundingModeRTZFloat16;
		init.shaderRoundingModeRTZFloat32 = shaderRoundingModeRTZFloat32;
		init.shaderRoundingModeRTZFloat64 = shaderRoundingModeRTZFloat64;
		init.maxUpdateAfterBindDescriptorsInAllPools = maxUpdateAfterBindDescriptorsInAllPools;
		init.shaderUniformBufferArrayNonUniformIndexingNative = shaderUniformBufferArrayNonUniformIndexingNative;
		init.shaderSampledImageArrayNonUniformIndexingNative = shaderSampledImageArrayNonUniformIndexingNative;
		init.shaderStorageBufferArrayNonUniformIndexingNative = shaderStorageBufferArrayNonUniformIndexingNative;
		init.shaderStorageImageArrayNonUniformIndexingNative = shaderStorageImageArrayNonUniformIndexingNative;
		init.shaderInputAttachmentArrayNonUniformIndexingNative = shaderInputAttachmentArrayNonUniformIndexingNative;
		init.robustBufferAccessUpdateAfterBind = robustBufferAccessUpdateAfterBind;
		init.quadDivergentImplicitLod = quadDivergentImplicitLod;
		init.maxPerStageDescriptorUpdateAfterBindSamplers = maxPerStageDescriptorUpdateAfterBindSamplers;
		init.maxPerStageDescriptorUpdateAfterBindUniformBuffers = maxPerStageDescriptorUpdateAfterBindUniformBuffers;
		init.maxPerStageDescriptorUpdateAfterBindStorageBuffers = maxPerStageDescriptorUpdateAfterBindStorageBuffers;
		init.maxPerStageDescriptorUpdateAfterBindSampledImages = maxPerStageDescriptorUpdateAfterBindSampledImages;
		init.maxPerStageDescriptorUpdateAfterBindStorageImages = maxPerStageDescriptorUpdateAfterBindStorageImages;
		init.maxPerStageDescriptorUpdateAfterBindInputAttachments = maxPerStageDescriptorUpdateAfterBindInputAttachments;
		init.maxPerStageUpdateAfterBindResources = maxPerStageUpdateAfterBindResources;
		init.maxDescriptorSetUpdateAfterBindSamplers = maxDescriptorSetUpdateAfterBindSamplers;
		init.maxDescriptorSetUpdateAfterBindUniformBuffers = maxDescriptorSetUpdateAfterBindUniformBuffers;
		init.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic = maxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
		init.maxDescriptorSetUpdateAfterBindStorageBuffers = maxDescriptorSetUpdateAfterBindStorageBuffers;
		init.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic = maxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
		init.maxDescriptorSetUpdateAfterBindSampledImages = maxDescriptorSetUpdateAfterBindSampledImages;
		init.maxDescriptorSetUpdateAfterBindStorageImages = maxDescriptorSetUpdateAfterBindStorageImages;
		init.maxDescriptorSetUpdateAfterBindInputAttachments = maxDescriptorSetUpdateAfterBindInputAttachments;
		init.supportedDepthResolveModes = supportedDepthResolveModes;
		init.supportedStencilResolveModes = supportedStencilResolveModes;
		init.independentResolveNone = independentResolveNone;
		init.independentResolve = independentResolve;
		init.filterMinmaxSingleComponentFormats = filterMinmaxSingleComponentFormats;
		init.filterMinmaxImageComponentMapping = filterMinmaxImageComponentMapping;
		init.maxTimelineSemaphoreValueDifference = maxTimelineSemaphoreValueDifference;
		init.framebufferIntegerColorSampleCounts = framebufferIntegerColorSampleCounts;
		return init;
	}

	static inline VkImageFormatListCreateInfo vkiImageFormatListCreateInfo_null()
	{
		VkImageFormatListCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO;
		return init;
	}

	static inline VkImageFormatListCreateInfo vkiImageFormatListCreateInfo(uint32_t viewFormatCount, const VkFormat *pViewFormats)
	{
		VkImageFormatListCreateInfo init = vkiImageFormatListCreateInfo_null();
		init.viewFormatCount = viewFormatCount;
		init.pViewFormats = pViewFormats;
		return init;
	}

	static inline VkAttachmentDescription2 vkiAttachmentDescription2_null()
	{
		VkAttachmentDescription2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2;
		return init;
	}

	static inline VkAttachmentDescription2 vkiAttachmentDescription2(VkFormat format, VkSampleCountFlagBits samples, VkAttachmentLoadOp loadOp, VkAttachmentStoreOp storeOp, VkAttachmentLoadOp stencilLoadOp, VkAttachmentStoreOp stencilStoreOp, VkImageLayout initialLayout, VkImageLayout finalLayout)
	{
		VkAttachmentDescription2 init = vkiAttachmentDescription2_null();
		init.format = format;
		init.samples = samples;
		init.loadOp = loadOp;
		init.storeOp = storeOp;
		init.stencilLoadOp = stencilLoadOp;
		init.stencilStoreOp = stencilStoreOp;
		init.initialLayout = initialLayout;
		init.finalLayout = finalLayout;
		return init;
	}

	static inline VkAttachmentReference2 vkiAttachmentReference2_null()
	{
		VkAttachmentReference2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2;
		return init;
	}

	static inline VkAttachmentReference2 vkiAttachmentReference2(uint32_t attachment, VkImageLayout layout, VkImageAspectFlags aspectMask)
	{
		VkAttachmentReference2 init = vkiAttachmentReference2_null();
		init.attachment = attachment;
		init.layout = layout;
		init.aspectMask = aspectMask;
		return init;
	}

	static inline VkSubpassDescription2 vkiSubpassDescription2_null()
	{
		VkSubpassDescription2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2;
		return init;
	}

	static inline VkSubpassDescription2 vkiSubpassDescription2(VkPipelineBindPoint pipelineBindPoint, uint32_t viewMask, uint32_t inputAttachmentCount, const VkAttachmentReference2 *pInputAttachments, uint32_t colorAttachmentCount, const VkAttachmentReference2 *pColorAttachments, const VkAttachmentReference2 *pResolveAttachments, const VkAttachmentReference2 *pDepthStencilAttachment, uint32_t preserveAttachmentCount, const uint32_t *pPreserveAttachments)
	{
		VkSubpassDescription2 init = vkiSubpassDescription2_null();
		init.pipelineBindPoint = pipelineBindPoint;
		init.viewMask = viewMask;
		init.inputAttachmentCount = inputAttachmentCount;
		init.pInputAttachments = pInputAttachments;
		init.colorAttachmentCount = colorAttachmentCount;
		init.pColorAttachments = pColorAttachments;
		init.pResolveAttachments = pResolveAttachments;
		init.pDepthStencilAttachment = pDepthStencilAttachment;
		init.preserveAttachmentCount = preserveAttachmentCount;
		init.pPreserveAttachments = pPreserveAttachments;
		return init;
	}

	static inline VkSubpassDependency2 vkiSubpassDependency2_null()
	{
		VkSubpassDependency2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2;
		return init;
	}

	static inline VkSubpassDependency2 vkiSubpassDependency2(uint32_t srcSubpass, uint32_t dstSubpass, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask, VkDependencyFlags dependencyFlags, int32_t viewOffset)
	{
		VkSubpassDependency2 init = vkiSubpassDependency2_null();
		init.srcSubpass = srcSubpass;
		init.dstSubpass = dstSubpass;
		init.srcStageMask = srcStageMask;
		init.dstStageMask = dstStageMask;
		init.srcAccessMask = srcAccessMask;
		init.dstAccessMask = dstAccessMask;
		init.dependencyFlags = dependencyFlags;
		init.viewOffset = viewOffset;
		return init;
	}

	static inline VkRenderPassCreateInfo2 vkiRenderPassCreateInfo2_null()
	{
		VkRenderPassCreateInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2;
		return init;
	}

	static inline VkRenderPassCreateInfo2 vkiRenderPassCreateInfo2(uint32_t attachmentCount, const VkAttachmentDescription2 *pAttachments, uint32_t subpassCount, const VkSubpassDescription2 *pSubpasses, uint32_t dependencyCount, const VkSubpassDependency2 *pDependencies, uint32_t correlatedViewMaskCount, const uint32_t *pCorrelatedViewMasks)
	{
		VkRenderPassCreateInfo2 init = vkiRenderPassCreateInfo2_null();
		init.attachmentCount = attachmentCount;
		init.pAttachments = pAttachments;
		init.subpassCount = subpassCount;
		init.pSubpasses = pSubpasses;
		init.dependencyCount = dependencyCount;
		init.pDependencies = pDependencies;
		init.correlatedViewMaskCount = correlatedViewMaskCount;
		init.pCorrelatedViewMasks = pCorrelatedViewMasks;
		return init;
	}

	static inline VkSubpassBeginInfo vkiSubpassBeginInfo_null()
	{
		VkSubpassBeginInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO;
		return init;
	}

	static inline VkSubpassBeginInfo vkiSubpassBeginInfo(VkSubpassContents contents)
	{
		VkSubpassBeginInfo init = vkiSubpassBeginInfo_null();
		init.contents = contents;
		return init;
	}

	static inline VkSubpassEndInfo vkiSubpassEndInfo_null()
	{
		VkSubpassEndInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_SUBPASS_END_INFO;
		return init;
	}

	static inline VkSubpassEndInfo vkiSubpassEndInfo()
	{
		VkSubpassEndInfo init = vkiSubpassEndInfo_null();
		return init;
	}

	static inline VkPhysicalDevice8BitStorageFeatures vkiPhysicalDevice8BitStorageFeatures_null()
	{
		VkPhysicalDevice8BitStorageFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES;
		return init;
	}

	static inline VkPhysicalDevice8BitStorageFeatures vkiPhysicalDevice8BitStorageFeatures(VkBool32 storageBuffer8BitAccess, VkBool32 uniformAndStorageBuffer8BitAccess, VkBool32 storagePushConstant8)
	{
		VkPhysicalDevice8BitStorageFeatures init = vkiPhysicalDevice8BitStorageFeatures_null();
		init.storageBuffer8BitAccess = storageBuffer8BitAccess;
		init.uniformAndStorageBuffer8BitAccess = uniformAndStorageBuffer8BitAccess;
		init.storagePushConstant8 = storagePushConstant8;
		return init;
	}

	static inline VkPhysicalDeviceDriverProperties vkiPhysicalDeviceDriverProperties_null()
	{
		VkPhysicalDeviceDriverProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceDriverProperties vkiPhysicalDeviceDriverProperties(VkDriverId driverID, VkConformanceVersion conformanceVersion)
	{
		VkPhysicalDeviceDriverProperties init = vkiPhysicalDeviceDriverProperties_null();
		init.driverID = driverID;
		init.conformanceVersion = conformanceVersion;
		return init;
	}

	static inline VkPhysicalDeviceShaderAtomicInt64Features vkiPhysicalDeviceShaderAtomicInt64Features_null()
	{
		VkPhysicalDeviceShaderAtomicInt64Features init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceShaderAtomicInt64Features vkiPhysicalDeviceShaderAtomicInt64Features(VkBool32 shaderBufferInt64Atomics, VkBool32 shaderSharedInt64Atomics)
	{
		VkPhysicalDeviceShaderAtomicInt64Features init = vkiPhysicalDeviceShaderAtomicInt64Features_null();
		init.shaderBufferInt64Atomics = shaderBufferInt64Atomics;
		init.shaderSharedInt64Atomics = shaderSharedInt64Atomics;
		return init;
	}

	static inline VkPhysicalDeviceShaderFloat16Int8Features vkiPhysicalDeviceShaderFloat16Int8Features_null()
	{
		VkPhysicalDeviceShaderFloat16Int8Features init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceShaderFloat16Int8Features vkiPhysicalDeviceShaderFloat16Int8Features(VkBool32 shaderFloat16, VkBool32 shaderInt8)
	{
		VkPhysicalDeviceShaderFloat16Int8Features init = vkiPhysicalDeviceShaderFloat16Int8Features_null();
		init.shaderFloat16 = shaderFloat16;
		init.shaderInt8 = shaderInt8;
		return init;
	}

	static inline VkPhysicalDeviceFloatControlsProperties vkiPhysicalDeviceFloatControlsProperties_null()
	{
		VkPhysicalDeviceFloatControlsProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceFloatControlsProperties vkiPhysicalDeviceFloatControlsProperties(VkShaderFloatControlsIndependence denormBehaviorIndependence, VkShaderFloatControlsIndependence roundingModeIndependence, VkBool32 shaderSignedZeroInfNanPreserveFloat16, VkBool32 shaderSignedZeroInfNanPreserveFloat32, VkBool32 shaderSignedZeroInfNanPreserveFloat64, VkBool32 shaderDenormPreserveFloat16, VkBool32 shaderDenormPreserveFloat32, VkBool32 shaderDenormPreserveFloat64, VkBool32 shaderDenormFlushToZeroFloat16, VkBool32 shaderDenormFlushToZeroFloat32, VkBool32 shaderDenormFlushToZeroFloat64, VkBool32 shaderRoundingModeRTEFloat16, VkBool32 shaderRoundingModeRTEFloat32, VkBool32 shaderRoundingModeRTEFloat64, VkBool32 shaderRoundingModeRTZFloat16, VkBool32 shaderRoundingModeRTZFloat32, VkBool32 shaderRoundingModeRTZFloat64)
	{
		VkPhysicalDeviceFloatControlsProperties init = vkiPhysicalDeviceFloatControlsProperties_null();
		init.denormBehaviorIndependence = denormBehaviorIndependence;
		init.roundingModeIndependence = roundingModeIndependence;
		init.shaderSignedZeroInfNanPreserveFloat16 = shaderSignedZeroInfNanPreserveFloat16;
		init.shaderSignedZeroInfNanPreserveFloat32 = shaderSignedZeroInfNanPreserveFloat32;
		init.shaderSignedZeroInfNanPreserveFloat64 = shaderSignedZeroInfNanPreserveFloat64;
		init.shaderDenormPreserveFloat16 = shaderDenormPreserveFloat16;
		init.shaderDenormPreserveFloat32 = shaderDenormPreserveFloat32;
		init.shaderDenormPreserveFloat64 = shaderDenormPreserveFloat64;
		init.shaderDenormFlushToZeroFloat16 = shaderDenormFlushToZeroFloat16;
		init.shaderDenormFlushToZeroFloat32 = shaderDenormFlushToZeroFloat32;
		init.shaderDenormFlushToZeroFloat64 = shaderDenormFlushToZeroFloat64;
		init.shaderRoundingModeRTEFloat16 = shaderRoundingModeRTEFloat16;
		init.shaderRoundingModeRTEFloat32 = shaderRoundingModeRTEFloat32;
		init.shaderRoundingModeRTEFloat64 = shaderRoundingModeRTEFloat64;
		init.shaderRoundingModeRTZFloat16 = shaderRoundingModeRTZFloat16;
		init.shaderRoundingModeRTZFloat32 = shaderRoundingModeRTZFloat32;
		init.shaderRoundingModeRTZFloat64 = shaderRoundingModeRTZFloat64;
		return init;
	}

	static inline VkDescriptorSetLayoutBindingFlagsCreateInfo vkiDescriptorSetLayoutBindingFlagsCreateInfo_null()
	{
		VkDescriptorSetLayoutBindingFlagsCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO;
		return init;
	}

	static inline VkDescriptorSetLayoutBindingFlagsCreateInfo vkiDescriptorSetLayoutBindingFlagsCreateInfo(uint32_t bindingCount, const VkDescriptorBindingFlags *pBindingFlags)
	{
		VkDescriptorSetLayoutBindingFlagsCreateInfo init = vkiDescriptorSetLayoutBindingFlagsCreateInfo_null();
		init.bindingCount = bindingCount;
		init.pBindingFlags = pBindingFlags;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorIndexingFeatures vkiPhysicalDeviceDescriptorIndexingFeatures_null()
	{
		VkPhysicalDeviceDescriptorIndexingFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorIndexingFeatures vkiPhysicalDeviceDescriptorIndexingFeatures(VkBool32 shaderInputAttachmentArrayDynamicIndexing, VkBool32 shaderUniformTexelBufferArrayDynamicIndexing, VkBool32 shaderStorageTexelBufferArrayDynamicIndexing, VkBool32 shaderUniformBufferArrayNonUniformIndexing, VkBool32 shaderSampledImageArrayNonUniformIndexing, VkBool32 shaderStorageBufferArrayNonUniformIndexing, VkBool32 shaderStorageImageArrayNonUniformIndexing, VkBool32 shaderInputAttachmentArrayNonUniformIndexing, VkBool32 shaderUniformTexelBufferArrayNonUniformIndexing, VkBool32 shaderStorageTexelBufferArrayNonUniformIndexing, VkBool32 descriptorBindingUniformBufferUpdateAfterBind, VkBool32 descriptorBindingSampledImageUpdateAfterBind, VkBool32 descriptorBindingStorageImageUpdateAfterBind, VkBool32 descriptorBindingStorageBufferUpdateAfterBind, VkBool32 descriptorBindingUniformTexelBufferUpdateAfterBind, VkBool32 descriptorBindingStorageTexelBufferUpdateAfterBind, VkBool32 descriptorBindingUpdateUnusedWhilePending, VkBool32 descriptorBindingPartiallyBound, VkBool32 descriptorBindingVariableDescriptorCount, VkBool32 runtimeDescriptorArray)
	{
		VkPhysicalDeviceDescriptorIndexingFeatures init = vkiPhysicalDeviceDescriptorIndexingFeatures_null();
		init.shaderInputAttachmentArrayDynamicIndexing = shaderInputAttachmentArrayDynamicIndexing;
		init.shaderUniformTexelBufferArrayDynamicIndexing = shaderUniformTexelBufferArrayDynamicIndexing;
		init.shaderStorageTexelBufferArrayDynamicIndexing = shaderStorageTexelBufferArrayDynamicIndexing;
		init.shaderUniformBufferArrayNonUniformIndexing = shaderUniformBufferArrayNonUniformIndexing;
		init.shaderSampledImageArrayNonUniformIndexing = shaderSampledImageArrayNonUniformIndexing;
		init.shaderStorageBufferArrayNonUniformIndexing = shaderStorageBufferArrayNonUniformIndexing;
		init.shaderStorageImageArrayNonUniformIndexing = shaderStorageImageArrayNonUniformIndexing;
		init.shaderInputAttachmentArrayNonUniformIndexing = shaderInputAttachmentArrayNonUniformIndexing;
		init.shaderUniformTexelBufferArrayNonUniformIndexing = shaderUniformTexelBufferArrayNonUniformIndexing;
		init.shaderStorageTexelBufferArrayNonUniformIndexing = shaderStorageTexelBufferArrayNonUniformIndexing;
		init.descriptorBindingUniformBufferUpdateAfterBind = descriptorBindingUniformBufferUpdateAfterBind;
		init.descriptorBindingSampledImageUpdateAfterBind = descriptorBindingSampledImageUpdateAfterBind;
		init.descriptorBindingStorageImageUpdateAfterBind = descriptorBindingStorageImageUpdateAfterBind;
		init.descriptorBindingStorageBufferUpdateAfterBind = descriptorBindingStorageBufferUpdateAfterBind;
		init.descriptorBindingUniformTexelBufferUpdateAfterBind = descriptorBindingUniformTexelBufferUpdateAfterBind;
		init.descriptorBindingStorageTexelBufferUpdateAfterBind = descriptorBindingStorageTexelBufferUpdateAfterBind;
		init.descriptorBindingUpdateUnusedWhilePending = descriptorBindingUpdateUnusedWhilePending;
		init.descriptorBindingPartiallyBound = descriptorBindingPartiallyBound;
		init.descriptorBindingVariableDescriptorCount = descriptorBindingVariableDescriptorCount;
		init.runtimeDescriptorArray = runtimeDescriptorArray;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorIndexingProperties vkiPhysicalDeviceDescriptorIndexingProperties_null()
	{
		VkPhysicalDeviceDescriptorIndexingProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorIndexingProperties vkiPhysicalDeviceDescriptorIndexingProperties(uint32_t maxUpdateAfterBindDescriptorsInAllPools, VkBool32 shaderUniformBufferArrayNonUniformIndexingNative, VkBool32 shaderSampledImageArrayNonUniformIndexingNative, VkBool32 shaderStorageBufferArrayNonUniformIndexingNative, VkBool32 shaderStorageImageArrayNonUniformIndexingNative, VkBool32 shaderInputAttachmentArrayNonUniformIndexingNative, VkBool32 robustBufferAccessUpdateAfterBind, VkBool32 quadDivergentImplicitLod, uint32_t maxPerStageDescriptorUpdateAfterBindSamplers, uint32_t maxPerStageDescriptorUpdateAfterBindUniformBuffers, uint32_t maxPerStageDescriptorUpdateAfterBindStorageBuffers, uint32_t maxPerStageDescriptorUpdateAfterBindSampledImages, uint32_t maxPerStageDescriptorUpdateAfterBindStorageImages, uint32_t maxPerStageDescriptorUpdateAfterBindInputAttachments, uint32_t maxPerStageUpdateAfterBindResources, uint32_t maxDescriptorSetUpdateAfterBindSamplers, uint32_t maxDescriptorSetUpdateAfterBindUniformBuffers, uint32_t maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, uint32_t maxDescriptorSetUpdateAfterBindStorageBuffers, uint32_t maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, uint32_t maxDescriptorSetUpdateAfterBindSampledImages, uint32_t maxDescriptorSetUpdateAfterBindStorageImages, uint32_t maxDescriptorSetUpdateAfterBindInputAttachments)
	{
		VkPhysicalDeviceDescriptorIndexingProperties init = vkiPhysicalDeviceDescriptorIndexingProperties_null();
		init.maxUpdateAfterBindDescriptorsInAllPools = maxUpdateAfterBindDescriptorsInAllPools;
		init.shaderUniformBufferArrayNonUniformIndexingNative = shaderUniformBufferArrayNonUniformIndexingNative;
		init.shaderSampledImageArrayNonUniformIndexingNative = shaderSampledImageArrayNonUniformIndexingNative;
		init.shaderStorageBufferArrayNonUniformIndexingNative = shaderStorageBufferArrayNonUniformIndexingNative;
		init.shaderStorageImageArrayNonUniformIndexingNative = shaderStorageImageArrayNonUniformIndexingNative;
		init.shaderInputAttachmentArrayNonUniformIndexingNative = shaderInputAttachmentArrayNonUniformIndexingNative;
		init.robustBufferAccessUpdateAfterBind = robustBufferAccessUpdateAfterBind;
		init.quadDivergentImplicitLod = quadDivergentImplicitLod;
		init.maxPerStageDescriptorUpdateAfterBindSamplers = maxPerStageDescriptorUpdateAfterBindSamplers;
		init.maxPerStageDescriptorUpdateAfterBindUniformBuffers = maxPerStageDescriptorUpdateAfterBindUniformBuffers;
		init.maxPerStageDescriptorUpdateAfterBindStorageBuffers = maxPerStageDescriptorUpdateAfterBindStorageBuffers;
		init.maxPerStageDescriptorUpdateAfterBindSampledImages = maxPerStageDescriptorUpdateAfterBindSampledImages;
		init.maxPerStageDescriptorUpdateAfterBindStorageImages = maxPerStageDescriptorUpdateAfterBindStorageImages;
		init.maxPerStageDescriptorUpdateAfterBindInputAttachments = maxPerStageDescriptorUpdateAfterBindInputAttachments;
		init.maxPerStageUpdateAfterBindResources = maxPerStageUpdateAfterBindResources;
		init.maxDescriptorSetUpdateAfterBindSamplers = maxDescriptorSetUpdateAfterBindSamplers;
		init.maxDescriptorSetUpdateAfterBindUniformBuffers = maxDescriptorSetUpdateAfterBindUniformBuffers;
		init.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic = maxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
		init.maxDescriptorSetUpdateAfterBindStorageBuffers = maxDescriptorSetUpdateAfterBindStorageBuffers;
		init.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic = maxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
		init.maxDescriptorSetUpdateAfterBindSampledImages = maxDescriptorSetUpdateAfterBindSampledImages;
		init.maxDescriptorSetUpdateAfterBindStorageImages = maxDescriptorSetUpdateAfterBindStorageImages;
		init.maxDescriptorSetUpdateAfterBindInputAttachments = maxDescriptorSetUpdateAfterBindInputAttachments;
		return init;
	}

	static inline VkDescriptorSetVariableDescriptorCountAllocateInfo vkiDescriptorSetVariableDescriptorCountAllocateInfo_null()
	{
		VkDescriptorSetVariableDescriptorCountAllocateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO;
		return init;
	}

	static inline VkDescriptorSetVariableDescriptorCountAllocateInfo vkiDescriptorSetVariableDescriptorCountAllocateInfo(uint32_t descriptorSetCount, const uint32_t *pDescriptorCounts)
	{
		VkDescriptorSetVariableDescriptorCountAllocateInfo init = vkiDescriptorSetVariableDescriptorCountAllocateInfo_null();
		init.descriptorSetCount = descriptorSetCount;
		init.pDescriptorCounts = pDescriptorCounts;
		return init;
	}

	static inline VkDescriptorSetVariableDescriptorCountLayoutSupport vkiDescriptorSetVariableDescriptorCountLayoutSupport_null()
	{
		VkDescriptorSetVariableDescriptorCountLayoutSupport init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT;
		return init;
	}

	static inline VkDescriptorSetVariableDescriptorCountLayoutSupport vkiDescriptorSetVariableDescriptorCountLayoutSupport(uint32_t maxVariableDescriptorCount)
	{
		VkDescriptorSetVariableDescriptorCountLayoutSupport init = vkiDescriptorSetVariableDescriptorCountLayoutSupport_null();
		init.maxVariableDescriptorCount = maxVariableDescriptorCount;
		return init;
	}

	static inline VkSubpassDescriptionDepthStencilResolve vkiSubpassDescriptionDepthStencilResolve_null()
	{
		VkSubpassDescriptionDepthStencilResolve init = {0};
		init.sType = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE;
		return init;
	}

	static inline VkSubpassDescriptionDepthStencilResolve vkiSubpassDescriptionDepthStencilResolve(VkResolveModeFlagBits depthResolveMode, VkResolveModeFlagBits stencilResolveMode, const VkAttachmentReference2 *pDepthStencilResolveAttachment)
	{
		VkSubpassDescriptionDepthStencilResolve init = vkiSubpassDescriptionDepthStencilResolve_null();
		init.depthResolveMode = depthResolveMode;
		init.stencilResolveMode = stencilResolveMode;
		init.pDepthStencilResolveAttachment = pDepthStencilResolveAttachment;
		return init;
	}

	static inline VkPhysicalDeviceDepthStencilResolveProperties vkiPhysicalDeviceDepthStencilResolveProperties_null()
	{
		VkPhysicalDeviceDepthStencilResolveProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceDepthStencilResolveProperties vkiPhysicalDeviceDepthStencilResolveProperties(VkResolveModeFlags supportedDepthResolveModes, VkResolveModeFlags supportedStencilResolveModes, VkBool32 independentResolveNone, VkBool32 independentResolve)
	{
		VkPhysicalDeviceDepthStencilResolveProperties init = vkiPhysicalDeviceDepthStencilResolveProperties_null();
		init.supportedDepthResolveModes = supportedDepthResolveModes;
		init.supportedStencilResolveModes = supportedStencilResolveModes;
		init.independentResolveNone = independentResolveNone;
		init.independentResolve = independentResolve;
		return init;
	}

	static inline VkPhysicalDeviceScalarBlockLayoutFeatures vkiPhysicalDeviceScalarBlockLayoutFeatures_null()
	{
		VkPhysicalDeviceScalarBlockLayoutFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceScalarBlockLayoutFeatures vkiPhysicalDeviceScalarBlockLayoutFeatures(VkBool32 scalarBlockLayout)
	{
		VkPhysicalDeviceScalarBlockLayoutFeatures init = vkiPhysicalDeviceScalarBlockLayoutFeatures_null();
		init.scalarBlockLayout = scalarBlockLayout;
		return init;
	}

	static inline VkImageStencilUsageCreateInfo vkiImageStencilUsageCreateInfo_null()
	{
		VkImageStencilUsageCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO;
		return init;
	}

	static inline VkImageStencilUsageCreateInfo vkiImageStencilUsageCreateInfo(VkImageUsageFlags stencilUsage)
	{
		VkImageStencilUsageCreateInfo init = vkiImageStencilUsageCreateInfo_null();
		init.stencilUsage = stencilUsage;
		return init;
	}

	static inline VkSamplerReductionModeCreateInfo vkiSamplerReductionModeCreateInfo_null()
	{
		VkSamplerReductionModeCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO;
		return init;
	}

	static inline VkSamplerReductionModeCreateInfo vkiSamplerReductionModeCreateInfo(VkSamplerReductionMode reductionMode)
	{
		VkSamplerReductionModeCreateInfo init = vkiSamplerReductionModeCreateInfo_null();
		init.reductionMode = reductionMode;
		return init;
	}

	static inline VkPhysicalDeviceSamplerFilterMinmaxProperties vkiPhysicalDeviceSamplerFilterMinmaxProperties_null()
	{
		VkPhysicalDeviceSamplerFilterMinmaxProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceSamplerFilterMinmaxProperties vkiPhysicalDeviceSamplerFilterMinmaxProperties(VkBool32 filterMinmaxSingleComponentFormats, VkBool32 filterMinmaxImageComponentMapping)
	{
		VkPhysicalDeviceSamplerFilterMinmaxProperties init = vkiPhysicalDeviceSamplerFilterMinmaxProperties_null();
		init.filterMinmaxSingleComponentFormats = filterMinmaxSingleComponentFormats;
		init.filterMinmaxImageComponentMapping = filterMinmaxImageComponentMapping;
		return init;
	}

	static inline VkPhysicalDeviceVulkanMemoryModelFeatures vkiPhysicalDeviceVulkanMemoryModelFeatures_null()
	{
		VkPhysicalDeviceVulkanMemoryModelFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceVulkanMemoryModelFeatures vkiPhysicalDeviceVulkanMemoryModelFeatures(VkBool32 vulkanMemoryModel, VkBool32 vulkanMemoryModelDeviceScope, VkBool32 vulkanMemoryModelAvailabilityVisibilityChains)
	{
		VkPhysicalDeviceVulkanMemoryModelFeatures init = vkiPhysicalDeviceVulkanMemoryModelFeatures_null();
		init.vulkanMemoryModel = vulkanMemoryModel;
		init.vulkanMemoryModelDeviceScope = vulkanMemoryModelDeviceScope;
		init.vulkanMemoryModelAvailabilityVisibilityChains = vulkanMemoryModelAvailabilityVisibilityChains;
		return init;
	}

	static inline VkPhysicalDeviceImagelessFramebufferFeatures vkiPhysicalDeviceImagelessFramebufferFeatures_null()
	{
		VkPhysicalDeviceImagelessFramebufferFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceImagelessFramebufferFeatures vkiPhysicalDeviceImagelessFramebufferFeatures(VkBool32 imagelessFramebuffer)
	{
		VkPhysicalDeviceImagelessFramebufferFeatures init = vkiPhysicalDeviceImagelessFramebufferFeatures_null();
		init.imagelessFramebuffer = imagelessFramebuffer;
		return init;
	}

	static inline VkFramebufferAttachmentImageInfo vkiFramebufferAttachmentImageInfo_null()
	{
		VkFramebufferAttachmentImageInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO;
		return init;
	}

	static inline VkFramebufferAttachmentImageInfo vkiFramebufferAttachmentImageInfo(VkImageUsageFlags usage, uint32_t width, uint32_t height, uint32_t layerCount, uint32_t viewFormatCount, const VkFormat *pViewFormats)
	{
		VkFramebufferAttachmentImageInfo init = vkiFramebufferAttachmentImageInfo_null();
		init.usage = usage;
		init.width = width;
		init.height = height;
		init.layerCount = layerCount;
		init.viewFormatCount = viewFormatCount;
		init.pViewFormats = pViewFormats;
		return init;
	}

	static inline VkFramebufferAttachmentsCreateInfo vkiFramebufferAttachmentsCreateInfo_null()
	{
		VkFramebufferAttachmentsCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO;
		return init;
	}

	static inline VkFramebufferAttachmentsCreateInfo vkiFramebufferAttachmentsCreateInfo(uint32_t attachmentImageInfoCount, const VkFramebufferAttachmentImageInfo *pAttachmentImageInfos)
	{
		VkFramebufferAttachmentsCreateInfo init = vkiFramebufferAttachmentsCreateInfo_null();
		init.attachmentImageInfoCount = attachmentImageInfoCount;
		init.pAttachmentImageInfos = pAttachmentImageInfos;
		return init;
	}

	static inline VkRenderPassAttachmentBeginInfo vkiRenderPassAttachmentBeginInfo_null()
	{
		VkRenderPassAttachmentBeginInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO;
		return init;
	}

	static inline VkRenderPassAttachmentBeginInfo vkiRenderPassAttachmentBeginInfo(uint32_t attachmentCount, const VkImageView *pAttachments)
	{
		VkRenderPassAttachmentBeginInfo init = vkiRenderPassAttachmentBeginInfo_null();
		init.attachmentCount = attachmentCount;
		init.pAttachments = pAttachments;
		return init;
	}

	static inline VkPhysicalDeviceUniformBufferStandardLayoutFeatures vkiPhysicalDeviceUniformBufferStandardLayoutFeatures_null()
	{
		VkPhysicalDeviceUniformBufferStandardLayoutFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceUniformBufferStandardLayoutFeatures vkiPhysicalDeviceUniformBufferStandardLayoutFeatures(VkBool32 uniformBufferStandardLayout)
	{
		VkPhysicalDeviceUniformBufferStandardLayoutFeatures init = vkiPhysicalDeviceUniformBufferStandardLayoutFeatures_null();
		init.uniformBufferStandardLayout = uniformBufferStandardLayout;
		return init;
	}

	static inline VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures vkiPhysicalDeviceShaderSubgroupExtendedTypesFeatures_null()
	{
		VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures vkiPhysicalDeviceShaderSubgroupExtendedTypesFeatures(VkBool32 shaderSubgroupExtendedTypes)
	{
		VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures init = vkiPhysicalDeviceShaderSubgroupExtendedTypesFeatures_null();
		init.shaderSubgroupExtendedTypes = shaderSubgroupExtendedTypes;
		return init;
	}

	static inline VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures vkiPhysicalDeviceSeparateDepthStencilLayoutsFeatures_null()
	{
		VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures vkiPhysicalDeviceSeparateDepthStencilLayoutsFeatures(VkBool32 separateDepthStencilLayouts)
	{
		VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures init = vkiPhysicalDeviceSeparateDepthStencilLayoutsFeatures_null();
		init.separateDepthStencilLayouts = separateDepthStencilLayouts;
		return init;
	}

	static inline VkAttachmentReferenceStencilLayout vkiAttachmentReferenceStencilLayout_null()
	{
		VkAttachmentReferenceStencilLayout init = {0};
		init.sType = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT;
		return init;
	}

	static inline VkAttachmentReferenceStencilLayout vkiAttachmentReferenceStencilLayout(VkImageLayout stencilLayout)
	{
		VkAttachmentReferenceStencilLayout init = vkiAttachmentReferenceStencilLayout_null();
		init.stencilLayout = stencilLayout;
		return init;
	}

	static inline VkAttachmentDescriptionStencilLayout vkiAttachmentDescriptionStencilLayout_null()
	{
		VkAttachmentDescriptionStencilLayout init = {0};
		init.sType = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT;
		return init;
	}

	static inline VkAttachmentDescriptionStencilLayout vkiAttachmentDescriptionStencilLayout(VkImageLayout stencilInitialLayout, VkImageLayout stencilFinalLayout)
	{
		VkAttachmentDescriptionStencilLayout init = vkiAttachmentDescriptionStencilLayout_null();
		init.stencilInitialLayout = stencilInitialLayout;
		init.stencilFinalLayout = stencilFinalLayout;
		return init;
	}

	static inline VkPhysicalDeviceHostQueryResetFeatures vkiPhysicalDeviceHostQueryResetFeatures_null()
	{
		VkPhysicalDeviceHostQueryResetFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceHostQueryResetFeatures vkiPhysicalDeviceHostQueryResetFeatures(VkBool32 hostQueryReset)
	{
		VkPhysicalDeviceHostQueryResetFeatures init = vkiPhysicalDeviceHostQueryResetFeatures_null();
		init.hostQueryReset = hostQueryReset;
		return init;
	}

	static inline VkPhysicalDeviceTimelineSemaphoreFeatures vkiPhysicalDeviceTimelineSemaphoreFeatures_null()
	{
		VkPhysicalDeviceTimelineSemaphoreFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceTimelineSemaphoreFeatures vkiPhysicalDeviceTimelineSemaphoreFeatures(VkBool32 timelineSemaphore)
	{
		VkPhysicalDeviceTimelineSemaphoreFeatures init = vkiPhysicalDeviceTimelineSemaphoreFeatures_null();
		init.timelineSemaphore = timelineSemaphore;
		return init;
	}

	static inline VkPhysicalDeviceTimelineSemaphoreProperties vkiPhysicalDeviceTimelineSemaphoreProperties_null()
	{
		VkPhysicalDeviceTimelineSemaphoreProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceTimelineSemaphoreProperties vkiPhysicalDeviceTimelineSemaphoreProperties(uint64_t maxTimelineSemaphoreValueDifference)
	{
		VkPhysicalDeviceTimelineSemaphoreProperties init = vkiPhysicalDeviceTimelineSemaphoreProperties_null();
		init.maxTimelineSemaphoreValueDifference = maxTimelineSemaphoreValueDifference;
		return init;
	}

	static inline VkSemaphoreTypeCreateInfo vkiSemaphoreTypeCreateInfo_null()
	{
		VkSemaphoreTypeCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO;
		return init;
	}

	static inline VkSemaphoreTypeCreateInfo vkiSemaphoreTypeCreateInfo(VkSemaphoreType semaphoreType, uint64_t initialValue)
	{
		VkSemaphoreTypeCreateInfo init = vkiSemaphoreTypeCreateInfo_null();
		init.semaphoreType = semaphoreType;
		init.initialValue = initialValue;
		return init;
	}

	static inline VkTimelineSemaphoreSubmitInfo vkiTimelineSemaphoreSubmitInfo_null()
	{
		VkTimelineSemaphoreSubmitInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO;
		return init;
	}

	static inline VkTimelineSemaphoreSubmitInfo vkiTimelineSemaphoreSubmitInfo(uint32_t waitSemaphoreValueCount, const uint64_t *pWaitSemaphoreValues, uint32_t signalSemaphoreValueCount, const uint64_t *pSignalSemaphoreValues)
	{
		VkTimelineSemaphoreSubmitInfo init = vkiTimelineSemaphoreSubmitInfo_null();
		init.waitSemaphoreValueCount = waitSemaphoreValueCount;
		init.pWaitSemaphoreValues = pWaitSemaphoreValues;
		init.signalSemaphoreValueCount = signalSemaphoreValueCount;
		init.pSignalSemaphoreValues = pSignalSemaphoreValues;
		return init;
	}

	static inline VkSemaphoreWaitInfo vkiSemaphoreWaitInfo_null()
	{
		VkSemaphoreWaitInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO;
		return init;
	}

	static inline VkSemaphoreWaitInfo vkiSemaphoreWaitInfo(uint32_t semaphoreCount, const VkSemaphore *pSemaphores, const uint64_t *pValues)
	{
		VkSemaphoreWaitInfo init = vkiSemaphoreWaitInfo_null();
		init.semaphoreCount = semaphoreCount;
		init.pSemaphores = pSemaphores;
		init.pValues = pValues;
		return init;
	}

	static inline VkSemaphoreSignalInfo vkiSemaphoreSignalInfo_null()
	{
		VkSemaphoreSignalInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO;
		return init;
	}

	static inline VkSemaphoreSignalInfo vkiSemaphoreSignalInfo(VkSemaphore semaphore, uint64_t value)
	{
		VkSemaphoreSignalInfo init = vkiSemaphoreSignalInfo_null();
		init.semaphore = semaphore;
		init.value = value;
		return init;
	}

	static inline VkPhysicalDeviceBufferDeviceAddressFeatures vkiPhysicalDeviceBufferDeviceAddressFeatures_null()
	{
		VkPhysicalDeviceBufferDeviceAddressFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceBufferDeviceAddressFeatures vkiPhysicalDeviceBufferDeviceAddressFeatures(VkBool32 bufferDeviceAddress, VkBool32 bufferDeviceAddressCaptureReplay, VkBool32 bufferDeviceAddressMultiDevice)
	{
		VkPhysicalDeviceBufferDeviceAddressFeatures init = vkiPhysicalDeviceBufferDeviceAddressFeatures_null();
		init.bufferDeviceAddress = bufferDeviceAddress;
		init.bufferDeviceAddressCaptureReplay = bufferDeviceAddressCaptureReplay;
		init.bufferDeviceAddressMultiDevice = bufferDeviceAddressMultiDevice;
		return init;
	}

	static inline VkBufferDeviceAddressInfo vkiBufferDeviceAddressInfo_null()
	{
		VkBufferDeviceAddressInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO;
		return init;
	}

	static inline VkBufferDeviceAddressInfo vkiBufferDeviceAddressInfo(VkBuffer buffer)
	{
		VkBufferDeviceAddressInfo init = vkiBufferDeviceAddressInfo_null();
		init.buffer = buffer;
		return init;
	}

	static inline VkBufferOpaqueCaptureAddressCreateInfo vkiBufferOpaqueCaptureAddressCreateInfo_null()
	{
		VkBufferOpaqueCaptureAddressCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO;
		return init;
	}

	static inline VkBufferOpaqueCaptureAddressCreateInfo vkiBufferOpaqueCaptureAddressCreateInfo(uint64_t opaqueCaptureAddress)
	{
		VkBufferOpaqueCaptureAddressCreateInfo init = vkiBufferOpaqueCaptureAddressCreateInfo_null();
		init.opaqueCaptureAddress = opaqueCaptureAddress;
		return init;
	}

	static inline VkMemoryOpaqueCaptureAddressAllocateInfo vkiMemoryOpaqueCaptureAddressAllocateInfo_null()
	{
		VkMemoryOpaqueCaptureAddressAllocateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO;
		return init;
	}

	static inline VkMemoryOpaqueCaptureAddressAllocateInfo vkiMemoryOpaqueCaptureAddressAllocateInfo(uint64_t opaqueCaptureAddress)
	{
		VkMemoryOpaqueCaptureAddressAllocateInfo init = vkiMemoryOpaqueCaptureAddressAllocateInfo_null();
		init.opaqueCaptureAddress = opaqueCaptureAddress;
		return init;
	}

	static inline VkDeviceMemoryOpaqueCaptureAddressInfo vkiDeviceMemoryOpaqueCaptureAddressInfo_null()
	{
		VkDeviceMemoryOpaqueCaptureAddressInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO;
		return init;
	}

	static inline VkDeviceMemoryOpaqueCaptureAddressInfo vkiDeviceMemoryOpaqueCaptureAddressInfo(VkDeviceMemory memory)
	{
		VkDeviceMemoryOpaqueCaptureAddressInfo init = vkiDeviceMemoryOpaqueCaptureAddressInfo_null();
		init.memory = memory;
		return init;
	}

	static inline VkPhysicalDeviceVulkan13Features vkiPhysicalDeviceVulkan13Features_null()
	{
		VkPhysicalDeviceVulkan13Features init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceVulkan13Features vkiPhysicalDeviceVulkan13Features(VkBool32 robustImageAccess, VkBool32 inlineUniformBlock, VkBool32 descriptorBindingInlineUniformBlockUpdateAfterBind, VkBool32 pipelineCreationCacheControl, VkBool32 privateData, VkBool32 shaderDemoteToHelperInvocation, VkBool32 shaderTerminateInvocation, VkBool32 subgroupSizeControl, VkBool32 computeFullSubgroups, VkBool32 synchronization2, VkBool32 textureCompressionASTC_HDR, VkBool32 shaderZeroInitializeWorkgroupMemory, VkBool32 dynamicRendering, VkBool32 shaderIntegerDotProduct, VkBool32 maintenance4)
	{
		VkPhysicalDeviceVulkan13Features init = vkiPhysicalDeviceVulkan13Features_null();
		init.robustImageAccess = robustImageAccess;
		init.inlineUniformBlock = inlineUniformBlock;
		init.descriptorBindingInlineUniformBlockUpdateAfterBind = descriptorBindingInlineUniformBlockUpdateAfterBind;
		init.pipelineCreationCacheControl = pipelineCreationCacheControl;
		init.privateData = privateData;
		init.shaderDemoteToHelperInvocation = shaderDemoteToHelperInvocation;
		init.shaderTerminateInvocation = shaderTerminateInvocation;
		init.subgroupSizeControl = subgroupSizeControl;
		init.computeFullSubgroups = computeFullSubgroups;
		init.synchronization2 = synchronization2;
		init.textureCompressionASTC_HDR = textureCompressionASTC_HDR;
		init.shaderZeroInitializeWorkgroupMemory = shaderZeroInitializeWorkgroupMemory;
		init.dynamicRendering = dynamicRendering;
		init.shaderIntegerDotProduct = shaderIntegerDotProduct;
		init.maintenance4 = maintenance4;
		return init;
	}

	static inline VkPhysicalDeviceVulkan13Properties vkiPhysicalDeviceVulkan13Properties_null()
	{
		VkPhysicalDeviceVulkan13Properties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceVulkan13Properties vkiPhysicalDeviceVulkan13Properties(uint32_t minSubgroupSize, uint32_t maxSubgroupSize, uint32_t maxComputeWorkgroupSubgroups, VkShaderStageFlags requiredSubgroupSizeStages, uint32_t maxInlineUniformBlockSize, uint32_t maxPerStageDescriptorInlineUniformBlocks, uint32_t maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks, uint32_t maxDescriptorSetInlineUniformBlocks, uint32_t maxDescriptorSetUpdateAfterBindInlineUniformBlocks, uint32_t maxInlineUniformTotalSize, VkBool32 integerDotProduct8BitUnsignedAccelerated, VkBool32 integerDotProduct8BitSignedAccelerated, VkBool32 integerDotProduct8BitMixedSignednessAccelerated, VkBool32 integerDotProduct4x8BitPackedUnsignedAccelerated, VkBool32 integerDotProduct4x8BitPackedSignedAccelerated, VkBool32 integerDotProduct4x8BitPackedMixedSignednessAccelerated, VkBool32 integerDotProduct16BitUnsignedAccelerated, VkBool32 integerDotProduct16BitSignedAccelerated, VkBool32 integerDotProduct16BitMixedSignednessAccelerated, VkBool32 integerDotProduct32BitUnsignedAccelerated, VkBool32 integerDotProduct32BitSignedAccelerated, VkBool32 integerDotProduct32BitMixedSignednessAccelerated, VkBool32 integerDotProduct64BitUnsignedAccelerated, VkBool32 integerDotProduct64BitSignedAccelerated, VkBool32 integerDotProduct64BitMixedSignednessAccelerated, VkBool32 integerDotProductAccumulatingSaturating8BitUnsignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating8BitSignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated, VkBool32 integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated, VkBool32 integerDotProductAccumulatingSaturating16BitUnsignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating16BitSignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated, VkBool32 integerDotProductAccumulatingSaturating32BitUnsignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating32BitSignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated, VkBool32 integerDotProductAccumulatingSaturating64BitUnsignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating64BitSignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated, VkDeviceSize storageTexelBufferOffsetAlignmentBytes, VkBool32 storageTexelBufferOffsetSingleTexelAlignment, VkDeviceSize uniformTexelBufferOffsetAlignmentBytes, VkBool32 uniformTexelBufferOffsetSingleTexelAlignment, VkDeviceSize maxBufferSize)
	{
		VkPhysicalDeviceVulkan13Properties init = vkiPhysicalDeviceVulkan13Properties_null();
		init.minSubgroupSize = minSubgroupSize;
		init.maxSubgroupSize = maxSubgroupSize;
		init.maxComputeWorkgroupSubgroups = maxComputeWorkgroupSubgroups;
		init.requiredSubgroupSizeStages = requiredSubgroupSizeStages;
		init.maxInlineUniformBlockSize = maxInlineUniformBlockSize;
		init.maxPerStageDescriptorInlineUniformBlocks = maxPerStageDescriptorInlineUniformBlocks;
		init.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks = maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks;
		init.maxDescriptorSetInlineUniformBlocks = maxDescriptorSetInlineUniformBlocks;
		init.maxDescriptorSetUpdateAfterBindInlineUniformBlocks = maxDescriptorSetUpdateAfterBindInlineUniformBlocks;
		init.maxInlineUniformTotalSize = maxInlineUniformTotalSize;
		init.integerDotProduct8BitUnsignedAccelerated = integerDotProduct8BitUnsignedAccelerated;
		init.integerDotProduct8BitSignedAccelerated = integerDotProduct8BitSignedAccelerated;
		init.integerDotProduct8BitMixedSignednessAccelerated = integerDotProduct8BitMixedSignednessAccelerated;
		init.integerDotProduct4x8BitPackedUnsignedAccelerated = integerDotProduct4x8BitPackedUnsignedAccelerated;
		init.integerDotProduct4x8BitPackedSignedAccelerated = integerDotProduct4x8BitPackedSignedAccelerated;
		init.integerDotProduct4x8BitPackedMixedSignednessAccelerated = integerDotProduct4x8BitPackedMixedSignednessAccelerated;
		init.integerDotProduct16BitUnsignedAccelerated = integerDotProduct16BitUnsignedAccelerated;
		init.integerDotProduct16BitSignedAccelerated = integerDotProduct16BitSignedAccelerated;
		init.integerDotProduct16BitMixedSignednessAccelerated = integerDotProduct16BitMixedSignednessAccelerated;
		init.integerDotProduct32BitUnsignedAccelerated = integerDotProduct32BitUnsignedAccelerated;
		init.integerDotProduct32BitSignedAccelerated = integerDotProduct32BitSignedAccelerated;
		init.integerDotProduct32BitMixedSignednessAccelerated = integerDotProduct32BitMixedSignednessAccelerated;
		init.integerDotProduct64BitUnsignedAccelerated = integerDotProduct64BitUnsignedAccelerated;
		init.integerDotProduct64BitSignedAccelerated = integerDotProduct64BitSignedAccelerated;
		init.integerDotProduct64BitMixedSignednessAccelerated = integerDotProduct64BitMixedSignednessAccelerated;
		init.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated = integerDotProductAccumulatingSaturating8BitUnsignedAccelerated;
		init.integerDotProductAccumulatingSaturating8BitSignedAccelerated = integerDotProductAccumulatingSaturating8BitSignedAccelerated;
		init.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated = integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated;
		init.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated = integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated;
		init.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated = integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated;
		init.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated = integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated;
		init.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated = integerDotProductAccumulatingSaturating16BitUnsignedAccelerated;
		init.integerDotProductAccumulatingSaturating16BitSignedAccelerated = integerDotProductAccumulatingSaturating16BitSignedAccelerated;
		init.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated = integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated;
		init.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated = integerDotProductAccumulatingSaturating32BitUnsignedAccelerated;
		init.integerDotProductAccumulatingSaturating32BitSignedAccelerated = integerDotProductAccumulatingSaturating32BitSignedAccelerated;
		init.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated = integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated;
		init.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated = integerDotProductAccumulatingSaturating64BitUnsignedAccelerated;
		init.integerDotProductAccumulatingSaturating64BitSignedAccelerated = integerDotProductAccumulatingSaturating64BitSignedAccelerated;
		init.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated = integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated;
		init.storageTexelBufferOffsetAlignmentBytes = storageTexelBufferOffsetAlignmentBytes;
		init.storageTexelBufferOffsetSingleTexelAlignment = storageTexelBufferOffsetSingleTexelAlignment;
		init.uniformTexelBufferOffsetAlignmentBytes = uniformTexelBufferOffsetAlignmentBytes;
		init.uniformTexelBufferOffsetSingleTexelAlignment = uniformTexelBufferOffsetSingleTexelAlignment;
		init.maxBufferSize = maxBufferSize;
		return init;
	}

	static inline VkPipelineCreationFeedback vkiPipelineCreationFeedback_null()
	{
		VkPipelineCreationFeedback init = {0};
		return init;
	}

	static inline VkPipelineCreationFeedback vkiPipelineCreationFeedback(uint64_t duration)
	{
		VkPipelineCreationFeedback init = vkiPipelineCreationFeedback_null();
		init.duration = duration;
		return init;
	}

	static inline VkPipelineCreationFeedbackCreateInfo vkiPipelineCreationFeedbackCreateInfo_null()
	{
		VkPipelineCreationFeedbackCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO;
		return init;
	}

	static inline VkPipelineCreationFeedbackCreateInfo vkiPipelineCreationFeedbackCreateInfo(VkPipelineCreationFeedback *pPipelineCreationFeedback, uint32_t pipelineStageCreationFeedbackCount, VkPipelineCreationFeedback *pPipelineStageCreationFeedbacks)
	{
		VkPipelineCreationFeedbackCreateInfo init = vkiPipelineCreationFeedbackCreateInfo_null();
		init.pPipelineCreationFeedback = pPipelineCreationFeedback;
		init.pipelineStageCreationFeedbackCount = pipelineStageCreationFeedbackCount;
		init.pPipelineStageCreationFeedbacks = pPipelineStageCreationFeedbacks;
		return init;
	}

	static inline VkPhysicalDeviceShaderTerminateInvocationFeatures vkiPhysicalDeviceShaderTerminateInvocationFeatures_null()
	{
		VkPhysicalDeviceShaderTerminateInvocationFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceShaderTerminateInvocationFeatures vkiPhysicalDeviceShaderTerminateInvocationFeatures(VkBool32 shaderTerminateInvocation)
	{
		VkPhysicalDeviceShaderTerminateInvocationFeatures init = vkiPhysicalDeviceShaderTerminateInvocationFeatures_null();
		init.shaderTerminateInvocation = shaderTerminateInvocation;
		return init;
	}

	static inline VkPhysicalDeviceToolProperties vkiPhysicalDeviceToolProperties_null()
	{
		VkPhysicalDeviceToolProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceToolProperties vkiPhysicalDeviceToolProperties(VkToolPurposeFlags purposes)
	{
		VkPhysicalDeviceToolProperties init = vkiPhysicalDeviceToolProperties_null();
		init.purposes = purposes;
		return init;
	}

	static inline VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures vkiPhysicalDeviceShaderDemoteToHelperInvocationFeatures_null()
	{
		VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures vkiPhysicalDeviceShaderDemoteToHelperInvocationFeatures(VkBool32 shaderDemoteToHelperInvocation)
	{
		VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures init = vkiPhysicalDeviceShaderDemoteToHelperInvocationFeatures_null();
		init.shaderDemoteToHelperInvocation = shaderDemoteToHelperInvocation;
		return init;
	}

	static inline VkPhysicalDevicePrivateDataFeatures vkiPhysicalDevicePrivateDataFeatures_null()
	{
		VkPhysicalDevicePrivateDataFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES;
		return init;
	}

	static inline VkPhysicalDevicePrivateDataFeatures vkiPhysicalDevicePrivateDataFeatures(VkBool32 privateData)
	{
		VkPhysicalDevicePrivateDataFeatures init = vkiPhysicalDevicePrivateDataFeatures_null();
		init.privateData = privateData;
		return init;
	}

	static inline VkDevicePrivateDataCreateInfo vkiDevicePrivateDataCreateInfo_null()
	{
		VkDevicePrivateDataCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO;
		return init;
	}

	static inline VkDevicePrivateDataCreateInfo vkiDevicePrivateDataCreateInfo(uint32_t privateDataSlotRequestCount)
	{
		VkDevicePrivateDataCreateInfo init = vkiDevicePrivateDataCreateInfo_null();
		init.privateDataSlotRequestCount = privateDataSlotRequestCount;
		return init;
	}

	static inline VkPrivateDataSlotCreateInfo vkiPrivateDataSlotCreateInfo_null()
	{
		VkPrivateDataSlotCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO;
		return init;
	}

	static inline VkPrivateDataSlotCreateInfo vkiPrivateDataSlotCreateInfo()
	{
		VkPrivateDataSlotCreateInfo init = vkiPrivateDataSlotCreateInfo_null();
		return init;
	}

	static inline VkPhysicalDevicePipelineCreationCacheControlFeatures vkiPhysicalDevicePipelineCreationCacheControlFeatures_null()
	{
		VkPhysicalDevicePipelineCreationCacheControlFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES;
		return init;
	}

	static inline VkPhysicalDevicePipelineCreationCacheControlFeatures vkiPhysicalDevicePipelineCreationCacheControlFeatures(VkBool32 pipelineCreationCacheControl)
	{
		VkPhysicalDevicePipelineCreationCacheControlFeatures init = vkiPhysicalDevicePipelineCreationCacheControlFeatures_null();
		init.pipelineCreationCacheControl = pipelineCreationCacheControl;
		return init;
	}

	static inline VkMemoryBarrier2 vkiMemoryBarrier2_null()
	{
		VkMemoryBarrier2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER_2;
		return init;
	}

	static inline VkMemoryBarrier2 vkiMemoryBarrier2(VkPipelineStageFlags2 srcStageMask, VkAccessFlags2 srcAccessMask, VkPipelineStageFlags2 dstStageMask, VkAccessFlags2 dstAccessMask)
	{
		VkMemoryBarrier2 init = vkiMemoryBarrier2_null();
		init.srcStageMask = srcStageMask;
		init.srcAccessMask = srcAccessMask;
		init.dstStageMask = dstStageMask;
		init.dstAccessMask = dstAccessMask;
		return init;
	}

	static inline VkBufferMemoryBarrier2 vkiBufferMemoryBarrier2_null()
	{
		VkBufferMemoryBarrier2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2;
		return init;
	}

	static inline VkBufferMemoryBarrier2 vkiBufferMemoryBarrier2(VkPipelineStageFlags2 srcStageMask, VkAccessFlags2 srcAccessMask, VkPipelineStageFlags2 dstStageMask, VkAccessFlags2 dstAccessMask, uint32_t srcQueueFamilyIndex, uint32_t dstQueueFamilyIndex, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size)
	{
		VkBufferMemoryBarrier2 init = vkiBufferMemoryBarrier2_null();
		init.srcStageMask = srcStageMask;
		init.srcAccessMask = srcAccessMask;
		init.dstStageMask = dstStageMask;
		init.dstAccessMask = dstAccessMask;
		init.srcQueueFamilyIndex = srcQueueFamilyIndex;
		init.dstQueueFamilyIndex = dstQueueFamilyIndex;
		init.buffer = buffer;
		init.offset = offset;
		init.size = size;
		return init;
	}

	static inline VkImageMemoryBarrier2 vkiImageMemoryBarrier2_null()
	{
		VkImageMemoryBarrier2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2;
		return init;
	}

	static inline VkImageMemoryBarrier2 vkiImageMemoryBarrier2(VkPipelineStageFlags2 srcStageMask, VkAccessFlags2 srcAccessMask, VkPipelineStageFlags2 dstStageMask, VkAccessFlags2 dstAccessMask, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t srcQueueFamilyIndex, uint32_t dstQueueFamilyIndex, VkImage image, VkImageSubresourceRange subresourceRange)
	{
		VkImageMemoryBarrier2 init = vkiImageMemoryBarrier2_null();
		init.srcStageMask = srcStageMask;
		init.srcAccessMask = srcAccessMask;
		init.dstStageMask = dstStageMask;
		init.dstAccessMask = dstAccessMask;
		init.oldLayout = oldLayout;
		init.newLayout = newLayout;
		init.srcQueueFamilyIndex = srcQueueFamilyIndex;
		init.dstQueueFamilyIndex = dstQueueFamilyIndex;
		init.image = image;
		init.subresourceRange = subresourceRange;
		return init;
	}

	static inline VkDependencyInfo vkiDependencyInfo_null()
	{
		VkDependencyInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEPENDENCY_INFO;
		return init;
	}

	static inline VkDependencyInfo vkiDependencyInfo(VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier2 *pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier2 *pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier2 *pImageMemoryBarriers)
	{
		VkDependencyInfo init = vkiDependencyInfo_null();
		init.dependencyFlags = dependencyFlags;
		init.memoryBarrierCount = memoryBarrierCount;
		init.pMemoryBarriers = pMemoryBarriers;
		init.bufferMemoryBarrierCount = bufferMemoryBarrierCount;
		init.pBufferMemoryBarriers = pBufferMemoryBarriers;
		init.imageMemoryBarrierCount = imageMemoryBarrierCount;
		init.pImageMemoryBarriers = pImageMemoryBarriers;
		return init;
	}

	static inline VkSemaphoreSubmitInfo vkiSemaphoreSubmitInfo_null()
	{
		VkSemaphoreSubmitInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO;
		return init;
	}

	static inline VkSemaphoreSubmitInfo vkiSemaphoreSubmitInfo(VkSemaphore semaphore, uint64_t value, VkPipelineStageFlags2 stageMask, uint32_t deviceIndex)
	{
		VkSemaphoreSubmitInfo init = vkiSemaphoreSubmitInfo_null();
		init.semaphore = semaphore;
		init.value = value;
		init.stageMask = stageMask;
		init.deviceIndex = deviceIndex;
		return init;
	}

	static inline VkCommandBufferSubmitInfo vkiCommandBufferSubmitInfo_null()
	{
		VkCommandBufferSubmitInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO;
		return init;
	}

	static inline VkCommandBufferSubmitInfo vkiCommandBufferSubmitInfo(VkCommandBuffer commandBuffer, uint32_t deviceMask)
	{
		VkCommandBufferSubmitInfo init = vkiCommandBufferSubmitInfo_null();
		init.commandBuffer = commandBuffer;
		init.deviceMask = deviceMask;
		return init;
	}

	static inline VkSubmitInfo2 vkiSubmitInfo2_null()
	{
		VkSubmitInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO_2;
		return init;
	}

	static inline VkSubmitInfo2 vkiSubmitInfo2(uint32_t waitSemaphoreInfoCount, const VkSemaphoreSubmitInfo *pWaitSemaphoreInfos, uint32_t commandBufferInfoCount, const VkCommandBufferSubmitInfo *pCommandBufferInfos, uint32_t signalSemaphoreInfoCount, const VkSemaphoreSubmitInfo *pSignalSemaphoreInfos)
	{
		VkSubmitInfo2 init = vkiSubmitInfo2_null();
		init.waitSemaphoreInfoCount = waitSemaphoreInfoCount;
		init.pWaitSemaphoreInfos = pWaitSemaphoreInfos;
		init.commandBufferInfoCount = commandBufferInfoCount;
		init.pCommandBufferInfos = pCommandBufferInfos;
		init.signalSemaphoreInfoCount = signalSemaphoreInfoCount;
		init.pSignalSemaphoreInfos = pSignalSemaphoreInfos;
		return init;
	}

	static inline VkPhysicalDeviceSynchronization2Features vkiPhysicalDeviceSynchronization2Features_null()
	{
		VkPhysicalDeviceSynchronization2Features init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceSynchronization2Features vkiPhysicalDeviceSynchronization2Features(VkBool32 synchronization2)
	{
		VkPhysicalDeviceSynchronization2Features init = vkiPhysicalDeviceSynchronization2Features_null();
		init.synchronization2 = synchronization2;
		return init;
	}

	static inline VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures vkiPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures_null()
	{
		VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures vkiPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(VkBool32 shaderZeroInitializeWorkgroupMemory)
	{
		VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures init = vkiPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures_null();
		init.shaderZeroInitializeWorkgroupMemory = shaderZeroInitializeWorkgroupMemory;
		return init;
	}

	static inline VkPhysicalDeviceImageRobustnessFeatures vkiPhysicalDeviceImageRobustnessFeatures_null()
	{
		VkPhysicalDeviceImageRobustnessFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceImageRobustnessFeatures vkiPhysicalDeviceImageRobustnessFeatures(VkBool32 robustImageAccess)
	{
		VkPhysicalDeviceImageRobustnessFeatures init = vkiPhysicalDeviceImageRobustnessFeatures_null();
		init.robustImageAccess = robustImageAccess;
		return init;
	}

	static inline VkBufferCopy2 vkiBufferCopy2_null()
	{
		VkBufferCopy2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_BUFFER_COPY_2;
		return init;
	}

	static inline VkBufferCopy2 vkiBufferCopy2(VkDeviceSize srcOffset, VkDeviceSize dstOffset, VkDeviceSize size)
	{
		VkBufferCopy2 init = vkiBufferCopy2_null();
		init.srcOffset = srcOffset;
		init.dstOffset = dstOffset;
		init.size = size;
		return init;
	}

	static inline VkCopyBufferInfo2 vkiCopyBufferInfo2_null()
	{
		VkCopyBufferInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2;
		return init;
	}

	static inline VkCopyBufferInfo2 vkiCopyBufferInfo2(VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy2 *pRegions)
	{
		VkCopyBufferInfo2 init = vkiCopyBufferInfo2_null();
		init.srcBuffer = srcBuffer;
		init.dstBuffer = dstBuffer;
		init.regionCount = regionCount;
		init.pRegions = pRegions;
		return init;
	}

	static inline VkImageCopy2 vkiImageCopy2_null()
	{
		VkImageCopy2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_COPY_2;
		return init;
	}

	static inline VkImageCopy2 vkiImageCopy2(VkImageSubresourceLayers srcSubresource, VkOffset3D srcOffset, VkImageSubresourceLayers dstSubresource, VkOffset3D dstOffset, VkExtent3D extent)
	{
		VkImageCopy2 init = vkiImageCopy2_null();
		init.srcSubresource = srcSubresource;
		init.srcOffset = srcOffset;
		init.dstSubresource = dstSubresource;
		init.dstOffset = dstOffset;
		init.extent = extent;
		return init;
	}

	static inline VkCopyImageInfo2 vkiCopyImageInfo2_null()
	{
		VkCopyImageInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2;
		return init;
	}

	static inline VkCopyImageInfo2 vkiCopyImageInfo2(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy2 *pRegions)
	{
		VkCopyImageInfo2 init = vkiCopyImageInfo2_null();
		init.srcImage = srcImage;
		init.srcImageLayout = srcImageLayout;
		init.dstImage = dstImage;
		init.dstImageLayout = dstImageLayout;
		init.regionCount = regionCount;
		init.pRegions = pRegions;
		return init;
	}

	static inline VkBufferImageCopy2 vkiBufferImageCopy2_null()
	{
		VkBufferImageCopy2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2;
		return init;
	}

	static inline VkBufferImageCopy2 vkiBufferImageCopy2(VkDeviceSize bufferOffset, uint32_t bufferRowLength, uint32_t bufferImageHeight, VkImageSubresourceLayers imageSubresource, VkOffset3D imageOffset, VkExtent3D imageExtent)
	{
		VkBufferImageCopy2 init = vkiBufferImageCopy2_null();
		init.bufferOffset = bufferOffset;
		init.bufferRowLength = bufferRowLength;
		init.bufferImageHeight = bufferImageHeight;
		init.imageSubresource = imageSubresource;
		init.imageOffset = imageOffset;
		init.imageExtent = imageExtent;
		return init;
	}

	static inline VkCopyBufferToImageInfo2 vkiCopyBufferToImageInfo2_null()
	{
		VkCopyBufferToImageInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2;
		return init;
	}

	static inline VkCopyBufferToImageInfo2 vkiCopyBufferToImageInfo2(VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy2 *pRegions)
	{
		VkCopyBufferToImageInfo2 init = vkiCopyBufferToImageInfo2_null();
		init.srcBuffer = srcBuffer;
		init.dstImage = dstImage;
		init.dstImageLayout = dstImageLayout;
		init.regionCount = regionCount;
		init.pRegions = pRegions;
		return init;
	}

	static inline VkCopyImageToBufferInfo2 vkiCopyImageToBufferInfo2_null()
	{
		VkCopyImageToBufferInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2;
		return init;
	}

	static inline VkCopyImageToBufferInfo2 vkiCopyImageToBufferInfo2(VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy2 *pRegions)
	{
		VkCopyImageToBufferInfo2 init = vkiCopyImageToBufferInfo2_null();
		init.srcImage = srcImage;
		init.srcImageLayout = srcImageLayout;
		init.dstBuffer = dstBuffer;
		init.regionCount = regionCount;
		init.pRegions = pRegions;
		return init;
	}

	static inline VkImageBlit2 vkiImageBlit2_null()
	{
		VkImageBlit2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_BLIT_2;
		return init;
	}

	static inline VkImageBlit2 vkiImageBlit2(VkImageSubresourceLayers srcSubresource, VkImageSubresourceLayers dstSubresource)
	{
		VkImageBlit2 init = vkiImageBlit2_null();
		init.srcSubresource = srcSubresource;
		init.dstSubresource = dstSubresource;
		return init;
	}

	static inline VkBlitImageInfo2 vkiBlitImageInfo2_null()
	{
		VkBlitImageInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2;
		return init;
	}

	static inline VkBlitImageInfo2 vkiBlitImageInfo2(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit2 *pRegions, VkFilter filter)
	{
		VkBlitImageInfo2 init = vkiBlitImageInfo2_null();
		init.srcImage = srcImage;
		init.srcImageLayout = srcImageLayout;
		init.dstImage = dstImage;
		init.dstImageLayout = dstImageLayout;
		init.regionCount = regionCount;
		init.pRegions = pRegions;
		init.filter = filter;
		return init;
	}

	static inline VkImageResolve2 vkiImageResolve2_null()
	{
		VkImageResolve2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2;
		return init;
	}

	static inline VkImageResolve2 vkiImageResolve2(VkImageSubresourceLayers srcSubresource, VkOffset3D srcOffset, VkImageSubresourceLayers dstSubresource, VkOffset3D dstOffset, VkExtent3D extent)
	{
		VkImageResolve2 init = vkiImageResolve2_null();
		init.srcSubresource = srcSubresource;
		init.srcOffset = srcOffset;
		init.dstSubresource = dstSubresource;
		init.dstOffset = dstOffset;
		init.extent = extent;
		return init;
	}

	static inline VkResolveImageInfo2 vkiResolveImageInfo2_null()
	{
		VkResolveImageInfo2 init = {0};
		init.sType = VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2;
		return init;
	}

	static inline VkResolveImageInfo2 vkiResolveImageInfo2(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve2 *pRegions)
	{
		VkResolveImageInfo2 init = vkiResolveImageInfo2_null();
		init.srcImage = srcImage;
		init.srcImageLayout = srcImageLayout;
		init.dstImage = dstImage;
		init.dstImageLayout = dstImageLayout;
		init.regionCount = regionCount;
		init.pRegions = pRegions;
		return init;
	}

	static inline VkPhysicalDeviceSubgroupSizeControlFeatures vkiPhysicalDeviceSubgroupSizeControlFeatures_null()
	{
		VkPhysicalDeviceSubgroupSizeControlFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceSubgroupSizeControlFeatures vkiPhysicalDeviceSubgroupSizeControlFeatures(VkBool32 subgroupSizeControl, VkBool32 computeFullSubgroups)
	{
		VkPhysicalDeviceSubgroupSizeControlFeatures init = vkiPhysicalDeviceSubgroupSizeControlFeatures_null();
		init.subgroupSizeControl = subgroupSizeControl;
		init.computeFullSubgroups = computeFullSubgroups;
		return init;
	}

	static inline VkPhysicalDeviceSubgroupSizeControlProperties vkiPhysicalDeviceSubgroupSizeControlProperties_null()
	{
		VkPhysicalDeviceSubgroupSizeControlProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceSubgroupSizeControlProperties vkiPhysicalDeviceSubgroupSizeControlProperties(uint32_t minSubgroupSize, uint32_t maxSubgroupSize, uint32_t maxComputeWorkgroupSubgroups, VkShaderStageFlags requiredSubgroupSizeStages)
	{
		VkPhysicalDeviceSubgroupSizeControlProperties init = vkiPhysicalDeviceSubgroupSizeControlProperties_null();
		init.minSubgroupSize = minSubgroupSize;
		init.maxSubgroupSize = maxSubgroupSize;
		init.maxComputeWorkgroupSubgroups = maxComputeWorkgroupSubgroups;
		init.requiredSubgroupSizeStages = requiredSubgroupSizeStages;
		return init;
	}

	static inline VkPipelineShaderStageRequiredSubgroupSizeCreateInfo vkiPipelineShaderStageRequiredSubgroupSizeCreateInfo_null()
	{
		VkPipelineShaderStageRequiredSubgroupSizeCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO;
		return init;
	}

	static inline VkPipelineShaderStageRequiredSubgroupSizeCreateInfo vkiPipelineShaderStageRequiredSubgroupSizeCreateInfo(uint32_t requiredSubgroupSize)
	{
		VkPipelineShaderStageRequiredSubgroupSizeCreateInfo init = vkiPipelineShaderStageRequiredSubgroupSizeCreateInfo_null();
		init.requiredSubgroupSize = requiredSubgroupSize;
		return init;
	}

	static inline VkPhysicalDeviceInlineUniformBlockFeatures vkiPhysicalDeviceInlineUniformBlockFeatures_null()
	{
		VkPhysicalDeviceInlineUniformBlockFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceInlineUniformBlockFeatures vkiPhysicalDeviceInlineUniformBlockFeatures(VkBool32 inlineUniformBlock, VkBool32 descriptorBindingInlineUniformBlockUpdateAfterBind)
	{
		VkPhysicalDeviceInlineUniformBlockFeatures init = vkiPhysicalDeviceInlineUniformBlockFeatures_null();
		init.inlineUniformBlock = inlineUniformBlock;
		init.descriptorBindingInlineUniformBlockUpdateAfterBind = descriptorBindingInlineUniformBlockUpdateAfterBind;
		return init;
	}

	static inline VkPhysicalDeviceInlineUniformBlockProperties vkiPhysicalDeviceInlineUniformBlockProperties_null()
	{
		VkPhysicalDeviceInlineUniformBlockProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceInlineUniformBlockProperties vkiPhysicalDeviceInlineUniformBlockProperties(uint32_t maxInlineUniformBlockSize, uint32_t maxPerStageDescriptorInlineUniformBlocks, uint32_t maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks, uint32_t maxDescriptorSetInlineUniformBlocks, uint32_t maxDescriptorSetUpdateAfterBindInlineUniformBlocks)
	{
		VkPhysicalDeviceInlineUniformBlockProperties init = vkiPhysicalDeviceInlineUniformBlockProperties_null();
		init.maxInlineUniformBlockSize = maxInlineUniformBlockSize;
		init.maxPerStageDescriptorInlineUniformBlocks = maxPerStageDescriptorInlineUniformBlocks;
		init.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks = maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks;
		init.maxDescriptorSetInlineUniformBlocks = maxDescriptorSetInlineUniformBlocks;
		init.maxDescriptorSetUpdateAfterBindInlineUniformBlocks = maxDescriptorSetUpdateAfterBindInlineUniformBlocks;
		return init;
	}

	static inline VkWriteDescriptorSetInlineUniformBlock vkiWriteDescriptorSetInlineUniformBlock_null()
	{
		VkWriteDescriptorSetInlineUniformBlock init = {0};
		init.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK;
		return init;
	}

	static inline VkWriteDescriptorSetInlineUniformBlock vkiWriteDescriptorSetInlineUniformBlock(uint32_t dataSize, const void *pData)
	{
		VkWriteDescriptorSetInlineUniformBlock init = vkiWriteDescriptorSetInlineUniformBlock_null();
		init.dataSize = dataSize;
		init.pData = pData;
		return init;
	}

	static inline VkDescriptorPoolInlineUniformBlockCreateInfo vkiDescriptorPoolInlineUniformBlockCreateInfo_null()
	{
		VkDescriptorPoolInlineUniformBlockCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO;
		return init;
	}

	static inline VkDescriptorPoolInlineUniformBlockCreateInfo vkiDescriptorPoolInlineUniformBlockCreateInfo(uint32_t maxInlineUniformBlockBindings)
	{
		VkDescriptorPoolInlineUniformBlockCreateInfo init = vkiDescriptorPoolInlineUniformBlockCreateInfo_null();
		init.maxInlineUniformBlockBindings = maxInlineUniformBlockBindings;
		return init;
	}

	static inline VkPhysicalDeviceTextureCompressionASTCHDRFeatures vkiPhysicalDeviceTextureCompressionASTCHDRFeatures_null()
	{
		VkPhysicalDeviceTextureCompressionASTCHDRFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceTextureCompressionASTCHDRFeatures vkiPhysicalDeviceTextureCompressionASTCHDRFeatures(VkBool32 textureCompressionASTC_HDR)
	{
		VkPhysicalDeviceTextureCompressionASTCHDRFeatures init = vkiPhysicalDeviceTextureCompressionASTCHDRFeatures_null();
		init.textureCompressionASTC_HDR = textureCompressionASTC_HDR;
		return init;
	}

	static inline VkRenderingAttachmentInfo vkiRenderingAttachmentInfo_null()
	{
		VkRenderingAttachmentInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO;
		return init;
	}

	static inline VkRenderingAttachmentInfo vkiRenderingAttachmentInfo(VkImageView imageView, VkImageLayout imageLayout, VkResolveModeFlagBits resolveMode, VkImageView resolveImageView, VkImageLayout resolveImageLayout, VkAttachmentLoadOp loadOp, VkAttachmentStoreOp storeOp, VkClearValue clearValue)
	{
		VkRenderingAttachmentInfo init = vkiRenderingAttachmentInfo_null();
		init.imageView = imageView;
		init.imageLayout = imageLayout;
		init.resolveMode = resolveMode;
		init.resolveImageView = resolveImageView;
		init.resolveImageLayout = resolveImageLayout;
		init.loadOp = loadOp;
		init.storeOp = storeOp;
		init.clearValue = clearValue;
		return init;
	}

	static inline VkRenderingInfo vkiRenderingInfo_null()
	{
		VkRenderingInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDERING_INFO;
		return init;
	}

	static inline VkRenderingInfo vkiRenderingInfo(VkRect2D renderArea, uint32_t layerCount, uint32_t viewMask, uint32_t colorAttachmentCount, const VkRenderingAttachmentInfo *pColorAttachments, const VkRenderingAttachmentInfo *pDepthAttachment, const VkRenderingAttachmentInfo *pStencilAttachment)
	{
		VkRenderingInfo init = vkiRenderingInfo_null();
		init.renderArea = renderArea;
		init.layerCount = layerCount;
		init.viewMask = viewMask;
		init.colorAttachmentCount = colorAttachmentCount;
		init.pColorAttachments = pColorAttachments;
		init.pDepthAttachment = pDepthAttachment;
		init.pStencilAttachment = pStencilAttachment;
		return init;
	}

	static inline VkPipelineRenderingCreateInfo vkiPipelineRenderingCreateInfo_null()
	{
		VkPipelineRenderingCreateInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO;
		return init;
	}

	static inline VkPipelineRenderingCreateInfo vkiPipelineRenderingCreateInfo(uint32_t viewMask, uint32_t colorAttachmentCount, const VkFormat *pColorAttachmentFormats, VkFormat depthAttachmentFormat, VkFormat stencilAttachmentFormat)
	{
		VkPipelineRenderingCreateInfo init = vkiPipelineRenderingCreateInfo_null();
		init.viewMask = viewMask;
		init.colorAttachmentCount = colorAttachmentCount;
		init.pColorAttachmentFormats = pColorAttachmentFormats;
		init.depthAttachmentFormat = depthAttachmentFormat;
		init.stencilAttachmentFormat = stencilAttachmentFormat;
		return init;
	}

	static inline VkPhysicalDeviceDynamicRenderingFeatures vkiPhysicalDeviceDynamicRenderingFeatures_null()
	{
		VkPhysicalDeviceDynamicRenderingFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceDynamicRenderingFeatures vkiPhysicalDeviceDynamicRenderingFeatures(VkBool32 dynamicRendering)
	{
		VkPhysicalDeviceDynamicRenderingFeatures init = vkiPhysicalDeviceDynamicRenderingFeatures_null();
		init.dynamicRendering = dynamicRendering;
		return init;
	}

	static inline VkCommandBufferInheritanceRenderingInfo vkiCommandBufferInheritanceRenderingInfo_null()
	{
		VkCommandBufferInheritanceRenderingInfo init = {0};
		init.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO;
		return init;
	}

	static inline VkCommandBufferInheritanceRenderingInfo vkiCommandBufferInheritanceRenderingInfo(uint32_t viewMask, uint32_t colorAttachmentCount, const VkFormat *pColorAttachmentFormats, VkFormat depthAttachmentFormat, VkFormat stencilAttachmentFormat, VkSampleCountFlagBits rasterizationSamples)
	{
		VkCommandBufferInheritanceRenderingInfo init = vkiCommandBufferInheritanceRenderingInfo_null();
		init.viewMask = viewMask;
		init.colorAttachmentCount = colorAttachmentCount;
		init.pColorAttachmentFormats = pColorAttachmentFormats;
		init.depthAttachmentFormat = depthAttachmentFormat;
		init.stencilAttachmentFormat = stencilAttachmentFormat;
		init.rasterizationSamples = rasterizationSamples;
		return init;
	}

	static inline VkPhysicalDeviceShaderIntegerDotProductFeatures vkiPhysicalDeviceShaderIntegerDotProductFeatures_null()
	{
		VkPhysicalDeviceShaderIntegerDotProductFeatures init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceShaderIntegerDotProductFeatures vkiPhysicalDeviceShaderIntegerDotProductFeatures(VkBool32 shaderIntegerDotProduct)
	{
		VkPhysicalDeviceShaderIntegerDotProductFeatures init = vkiPhysicalDeviceShaderIntegerDotProductFeatures_null();
		init.shaderIntegerDotProduct = shaderIntegerDotProduct;
		return init;
	}

	static inline VkPhysicalDeviceShaderIntegerDotProductProperties vkiPhysicalDeviceShaderIntegerDotProductProperties_null()
	{
		VkPhysicalDeviceShaderIntegerDotProductProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceShaderIntegerDotProductProperties vkiPhysicalDeviceShaderIntegerDotProductProperties(VkBool32 integerDotProduct8BitUnsignedAccelerated, VkBool32 integerDotProduct8BitSignedAccelerated, VkBool32 integerDotProduct8BitMixedSignednessAccelerated, VkBool32 integerDotProduct4x8BitPackedUnsignedAccelerated, VkBool32 integerDotProduct4x8BitPackedSignedAccelerated, VkBool32 integerDotProduct4x8BitPackedMixedSignednessAccelerated, VkBool32 integerDotProduct16BitUnsignedAccelerated, VkBool32 integerDotProduct16BitSignedAccelerated, VkBool32 integerDotProduct16BitMixedSignednessAccelerated, VkBool32 integerDotProduct32BitUnsignedAccelerated, VkBool32 integerDotProduct32BitSignedAccelerated, VkBool32 integerDotProduct32BitMixedSignednessAccelerated, VkBool32 integerDotProduct64BitUnsignedAccelerated, VkBool32 integerDotProduct64BitSignedAccelerated, VkBool32 integerDotProduct64BitMixedSignednessAccelerated, VkBool32 integerDotProductAccumulatingSaturating8BitUnsignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating8BitSignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated, VkBool32 integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated, VkBool32 integerDotProductAccumulatingSaturating16BitUnsignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating16BitSignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated, VkBool32 integerDotProductAccumulatingSaturating32BitUnsignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating32BitSignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated, VkBool32 integerDotProductAccumulatingSaturating64BitUnsignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating64BitSignedAccelerated, VkBool32 integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated)
	{
		VkPhysicalDeviceShaderIntegerDotProductProperties init = vkiPhysicalDeviceShaderIntegerDotProductProperties_null();
		init.integerDotProduct8BitUnsignedAccelerated = integerDotProduct8BitUnsignedAccelerated;
		init.integerDotProduct8BitSignedAccelerated = integerDotProduct8BitSignedAccelerated;
		init.integerDotProduct8BitMixedSignednessAccelerated = integerDotProduct8BitMixedSignednessAccelerated;
		init.integerDotProduct4x8BitPackedUnsignedAccelerated = integerDotProduct4x8BitPackedUnsignedAccelerated;
		init.integerDotProduct4x8BitPackedSignedAccelerated = integerDotProduct4x8BitPackedSignedAccelerated;
		init.integerDotProduct4x8BitPackedMixedSignednessAccelerated = integerDotProduct4x8BitPackedMixedSignednessAccelerated;
		init.integerDotProduct16BitUnsignedAccelerated = integerDotProduct16BitUnsignedAccelerated;
		init.integerDotProduct16BitSignedAccelerated = integerDotProduct16BitSignedAccelerated;
		init.integerDotProduct16BitMixedSignednessAccelerated = integerDotProduct16BitMixedSignednessAccelerated;
		init.integerDotProduct32BitUnsignedAccelerated = integerDotProduct32BitUnsignedAccelerated;
		init.integerDotProduct32BitSignedAccelerated = integerDotProduct32BitSignedAccelerated;
		init.integerDotProduct32BitMixedSignednessAccelerated = integerDotProduct32BitMixedSignednessAccelerated;
		init.integerDotProduct64BitUnsignedAccelerated = integerDotProduct64BitUnsignedAccelerated;
		init.integerDotProduct64BitSignedAccelerated = integerDotProduct64BitSignedAccelerated;
		init.integerDotProduct64BitMixedSignednessAccelerated = integerDotProduct64BitMixedSignednessAccelerated;
		init.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated = integerDotProductAccumulatingSaturating8BitUnsignedAccelerated;
		init.integerDotProductAccumulatingSaturating8BitSignedAccelerated = integerDotProductAccumulatingSaturating8BitSignedAccelerated;
		init.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated = integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated;
		init.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated = integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated;
		init.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated = integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated;
		init.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated = integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated;
		init.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated = integerDotProductAccumulatingSaturating16BitUnsignedAccelerated;
		init.integerDotProductAccumulatingSaturating16BitSignedAccelerated = integerDotProductAccumulatingSaturating16BitSignedAccelerated;
		init.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated = integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated;
		init.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated = integerDotProductAccumulatingSaturating32BitUnsignedAccelerated;
		init.integerDotProductAccumulatingSaturating32BitSignedAccelerated = integerDotProductAccumulatingSaturating32BitSignedAccelerated;
		init.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated = integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated;
		init.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated = integerDotProductAccumulatingSaturating64BitUnsignedAccelerated;
		init.integerDotProductAccumulatingSaturating64BitSignedAccelerated = integerDotProductAccumulatingSaturating64BitSignedAccelerated;
		init.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated = integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated;
		return init;
	}

	static inline VkPhysicalDeviceTexelBufferAlignmentProperties vkiPhysicalDeviceTexelBufferAlignmentProperties_null()
	{
		VkPhysicalDeviceTexelBufferAlignmentProperties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceTexelBufferAlignmentProperties vkiPhysicalDeviceTexelBufferAlignmentProperties(VkDeviceSize storageTexelBufferOffsetAlignmentBytes, VkBool32 storageTexelBufferOffsetSingleTexelAlignment, VkDeviceSize uniformTexelBufferOffsetAlignmentBytes, VkBool32 uniformTexelBufferOffsetSingleTexelAlignment)
	{
		VkPhysicalDeviceTexelBufferAlignmentProperties init = vkiPhysicalDeviceTexelBufferAlignmentProperties_null();
		init.storageTexelBufferOffsetAlignmentBytes = storageTexelBufferOffsetAlignmentBytes;
		init.storageTexelBufferOffsetSingleTexelAlignment = storageTexelBufferOffsetSingleTexelAlignment;
		init.uniformTexelBufferOffsetAlignmentBytes = uniformTexelBufferOffsetAlignmentBytes;
		init.uniformTexelBufferOffsetSingleTexelAlignment = uniformTexelBufferOffsetSingleTexelAlignment;
		return init;
	}

	static inline VkFormatProperties3 vkiFormatProperties3_null()
	{
		VkFormatProperties3 init = {0};
		init.sType = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3;
		return init;
	}

	static inline VkFormatProperties3 vkiFormatProperties3(VkFormatFeatureFlags2 linearTilingFeatures, VkFormatFeatureFlags2 optimalTilingFeatures, VkFormatFeatureFlags2 bufferFeatures)
	{
		VkFormatProperties3 init = vkiFormatProperties3_null();
		init.linearTilingFeatures = linearTilingFeatures;
		init.optimalTilingFeatures = optimalTilingFeatures;
		init.bufferFeatures = bufferFeatures;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance4Features vkiPhysicalDeviceMaintenance4Features_null()
	{
		VkPhysicalDeviceMaintenance4Features init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance4Features vkiPhysicalDeviceMaintenance4Features(VkBool32 maintenance4)
	{
		VkPhysicalDeviceMaintenance4Features init = vkiPhysicalDeviceMaintenance4Features_null();
		init.maintenance4 = maintenance4;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance4Properties vkiPhysicalDeviceMaintenance4Properties_null()
	{
		VkPhysicalDeviceMaintenance4Properties init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance4Properties vkiPhysicalDeviceMaintenance4Properties(VkDeviceSize maxBufferSize)
	{
		VkPhysicalDeviceMaintenance4Properties init = vkiPhysicalDeviceMaintenance4Properties_null();
		init.maxBufferSize = maxBufferSize;
		return init;
	}

	static inline VkDeviceBufferMemoryRequirements vkiDeviceBufferMemoryRequirements_null()
	{
		VkDeviceBufferMemoryRequirements init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS;
		return init;
	}

	static inline VkDeviceBufferMemoryRequirements vkiDeviceBufferMemoryRequirements(const VkBufferCreateInfo *pCreateInfo)
	{
		VkDeviceBufferMemoryRequirements init = vkiDeviceBufferMemoryRequirements_null();
		init.pCreateInfo = pCreateInfo;
		return init;
	}

	static inline VkDeviceImageMemoryRequirements vkiDeviceImageMemoryRequirements_null()
	{
		VkDeviceImageMemoryRequirements init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS;
		return init;
	}

	static inline VkDeviceImageMemoryRequirements vkiDeviceImageMemoryRequirements(const VkImageCreateInfo *pCreateInfo, VkImageAspectFlagBits planeAspect)
	{
		VkDeviceImageMemoryRequirements init = vkiDeviceImageMemoryRequirements_null();
		init.pCreateInfo = pCreateInfo;
		init.planeAspect = planeAspect;
		return init;
	}

	static inline VkSurfaceCapabilitiesKHR vkiSurfaceCapabilitiesKHR_null()
	{
		VkSurfaceCapabilitiesKHR init = {0};
		return init;
	}

	static inline VkSurfaceCapabilitiesKHR vkiSurfaceCapabilitiesKHR(uint32_t minImageCount, uint32_t maxImageCount, VkExtent2D currentExtent, VkExtent2D minImageExtent, VkExtent2D maxImageExtent, uint32_t maxImageArrayLayers, VkSurfaceTransformFlagsKHR supportedTransforms, VkSurfaceTransformFlagBitsKHR currentTransform, VkCompositeAlphaFlagsKHR supportedCompositeAlpha, VkImageUsageFlags supportedUsageFlags)
	{
		VkSurfaceCapabilitiesKHR init = vkiSurfaceCapabilitiesKHR_null();
		init.minImageCount = minImageCount;
		init.maxImageCount = maxImageCount;
		init.currentExtent = currentExtent;
		init.minImageExtent = minImageExtent;
		init.maxImageExtent = maxImageExtent;
		init.maxImageArrayLayers = maxImageArrayLayers;
		init.supportedTransforms = supportedTransforms;
		init.currentTransform = currentTransform;
		init.supportedCompositeAlpha = supportedCompositeAlpha;
		init.supportedUsageFlags = supportedUsageFlags;
		return init;
	}

	static inline VkSurfaceFormatKHR vkiSurfaceFormatKHR_null()
	{
		VkSurfaceFormatKHR init = {0};
		return init;
	}

	static inline VkSurfaceFormatKHR vkiSurfaceFormatKHR(VkFormat format, VkColorSpaceKHR colorSpace)
	{
		VkSurfaceFormatKHR init = vkiSurfaceFormatKHR_null();
		init.format = format;
		init.colorSpace = colorSpace;
		return init;
	}

	static inline VkSwapchainCreateInfoKHR vkiSwapchainCreateInfoKHR_null()
	{
		VkSwapchainCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		return init;
	}

	static inline VkSwapchainCreateInfoKHR vkiSwapchainCreateInfoKHR(VkSurfaceKHR surface, uint32_t minImageCount, VkFormat imageFormat, VkColorSpaceKHR imageColorSpace, VkExtent2D imageExtent, uint32_t imageArrayLayers, VkImageUsageFlags imageUsage, VkSharingMode imageSharingMode, uint32_t queueFamilyIndexCount, const uint32_t *pQueueFamilyIndices, VkSurfaceTransformFlagBitsKHR preTransform, VkCompositeAlphaFlagBitsKHR compositeAlpha, VkPresentModeKHR presentMode, VkBool32 clipped, VkSwapchainKHR oldSwapchain)
	{
		VkSwapchainCreateInfoKHR init = vkiSwapchainCreateInfoKHR_null();
		init.surface = surface;
		init.minImageCount = minImageCount;
		init.imageFormat = imageFormat;
		init.imageColorSpace = imageColorSpace;
		init.imageExtent = imageExtent;
		init.imageArrayLayers = imageArrayLayers;
		init.imageUsage = imageUsage;
		init.imageSharingMode = imageSharingMode;
		init.queueFamilyIndexCount = queueFamilyIndexCount;
		init.pQueueFamilyIndices = pQueueFamilyIndices;
		init.preTransform = preTransform;
		init.compositeAlpha = compositeAlpha;
		init.presentMode = presentMode;
		init.clipped = clipped;
		init.oldSwapchain = oldSwapchain;
		return init;
	}

	static inline VkPresentInfoKHR vkiPresentInfoKHR_null()
	{
		VkPresentInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
		return init;
	}

	static inline VkPresentInfoKHR vkiPresentInfoKHR(uint32_t waitSemaphoreCount, const VkSemaphore *pWaitSemaphores, uint32_t swapchainCount, const VkSwapchainKHR *pSwapchains, const uint32_t *pImageIndices, VkResult *pResults)
	{
		VkPresentInfoKHR init = vkiPresentInfoKHR_null();
		init.waitSemaphoreCount = waitSemaphoreCount;
		init.pWaitSemaphores = pWaitSemaphores;
		init.swapchainCount = swapchainCount;
		init.pSwapchains = pSwapchains;
		init.pImageIndices = pImageIndices;
		init.pResults = pResults;
		return init;
	}

	static inline VkImageSwapchainCreateInfoKHR vkiImageSwapchainCreateInfoKHR_null()
	{
		VkImageSwapchainCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR;
		return init;
	}

	static inline VkImageSwapchainCreateInfoKHR vkiImageSwapchainCreateInfoKHR(VkSwapchainKHR swapchain)
	{
		VkImageSwapchainCreateInfoKHR init = vkiImageSwapchainCreateInfoKHR_null();
		init.swapchain = swapchain;
		return init;
	}

	static inline VkBindImageMemorySwapchainInfoKHR vkiBindImageMemorySwapchainInfoKHR_null()
	{
		VkBindImageMemorySwapchainInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR;
		return init;
	}

	static inline VkBindImageMemorySwapchainInfoKHR vkiBindImageMemorySwapchainInfoKHR(VkSwapchainKHR swapchain, uint32_t imageIndex)
	{
		VkBindImageMemorySwapchainInfoKHR init = vkiBindImageMemorySwapchainInfoKHR_null();
		init.swapchain = swapchain;
		init.imageIndex = imageIndex;
		return init;
	}

	static inline VkAcquireNextImageInfoKHR vkiAcquireNextImageInfoKHR_null()
	{
		VkAcquireNextImageInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR;
		return init;
	}

	static inline VkAcquireNextImageInfoKHR vkiAcquireNextImageInfoKHR(VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t deviceMask)
	{
		VkAcquireNextImageInfoKHR init = vkiAcquireNextImageInfoKHR_null();
		init.swapchain = swapchain;
		init.timeout = timeout;
		init.semaphore = semaphore;
		init.fence = fence;
		init.deviceMask = deviceMask;
		return init;
	}

	static inline VkDeviceGroupPresentCapabilitiesKHR vkiDeviceGroupPresentCapabilitiesKHR_null()
	{
		VkDeviceGroupPresentCapabilitiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR;
		return init;
	}

	static inline VkDeviceGroupPresentCapabilitiesKHR vkiDeviceGroupPresentCapabilitiesKHR(VkDeviceGroupPresentModeFlagsKHR modes)
	{
		VkDeviceGroupPresentCapabilitiesKHR init = vkiDeviceGroupPresentCapabilitiesKHR_null();
		init.modes = modes;
		return init;
	}

	static inline VkDeviceGroupPresentInfoKHR vkiDeviceGroupPresentInfoKHR_null()
	{
		VkDeviceGroupPresentInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR;
		return init;
	}

	static inline VkDeviceGroupPresentInfoKHR vkiDeviceGroupPresentInfoKHR(uint32_t swapchainCount, const uint32_t *pDeviceMasks, VkDeviceGroupPresentModeFlagBitsKHR mode)
	{
		VkDeviceGroupPresentInfoKHR init = vkiDeviceGroupPresentInfoKHR_null();
		init.swapchainCount = swapchainCount;
		init.pDeviceMasks = pDeviceMasks;
		init.mode = mode;
		return init;
	}

	static inline VkDeviceGroupSwapchainCreateInfoKHR vkiDeviceGroupSwapchainCreateInfoKHR_null()
	{
		VkDeviceGroupSwapchainCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR;
		return init;
	}

	static inline VkDeviceGroupSwapchainCreateInfoKHR vkiDeviceGroupSwapchainCreateInfoKHR(VkDeviceGroupPresentModeFlagsKHR modes)
	{
		VkDeviceGroupSwapchainCreateInfoKHR init = vkiDeviceGroupSwapchainCreateInfoKHR_null();
		init.modes = modes;
		return init;
	}

	static inline VkDisplayModeParametersKHR vkiDisplayModeParametersKHR_null()
	{
		VkDisplayModeParametersKHR init = {0};
		return init;
	}

	static inline VkDisplayModeParametersKHR vkiDisplayModeParametersKHR(VkExtent2D visibleRegion, uint32_t refreshRate)
	{
		VkDisplayModeParametersKHR init = vkiDisplayModeParametersKHR_null();
		init.visibleRegion = visibleRegion;
		init.refreshRate = refreshRate;
		return init;
	}

	static inline VkDisplayModeCreateInfoKHR vkiDisplayModeCreateInfoKHR_null()
	{
		VkDisplayModeCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR;
		return init;
	}

	static inline VkDisplayModeCreateInfoKHR vkiDisplayModeCreateInfoKHR(VkDisplayModeParametersKHR parameters)
	{
		VkDisplayModeCreateInfoKHR init = vkiDisplayModeCreateInfoKHR_null();
		init.parameters = parameters;
		return init;
	}

	static inline VkDisplayModePropertiesKHR vkiDisplayModePropertiesKHR_null()
	{
		VkDisplayModePropertiesKHR init = {0};
		return init;
	}

	static inline VkDisplayModePropertiesKHR vkiDisplayModePropertiesKHR(VkDisplayModeKHR displayMode, VkDisplayModeParametersKHR parameters)
	{
		VkDisplayModePropertiesKHR init = vkiDisplayModePropertiesKHR_null();
		init.displayMode = displayMode;
		init.parameters = parameters;
		return init;
	}

	static inline VkDisplayPlaneCapabilitiesKHR vkiDisplayPlaneCapabilitiesKHR_null()
	{
		VkDisplayPlaneCapabilitiesKHR init = {0};
		return init;
	}

	static inline VkDisplayPlaneCapabilitiesKHR vkiDisplayPlaneCapabilitiesKHR(VkDisplayPlaneAlphaFlagsKHR supportedAlpha, VkOffset2D minSrcPosition, VkOffset2D maxSrcPosition, VkExtent2D minSrcExtent, VkExtent2D maxSrcExtent, VkOffset2D minDstPosition, VkOffset2D maxDstPosition, VkExtent2D minDstExtent, VkExtent2D maxDstExtent)
	{
		VkDisplayPlaneCapabilitiesKHR init = vkiDisplayPlaneCapabilitiesKHR_null();
		init.supportedAlpha = supportedAlpha;
		init.minSrcPosition = minSrcPosition;
		init.maxSrcPosition = maxSrcPosition;
		init.minSrcExtent = minSrcExtent;
		init.maxSrcExtent = maxSrcExtent;
		init.minDstPosition = minDstPosition;
		init.maxDstPosition = maxDstPosition;
		init.minDstExtent = minDstExtent;
		init.maxDstExtent = maxDstExtent;
		return init;
	}

	static inline VkDisplayPlanePropertiesKHR vkiDisplayPlanePropertiesKHR_null()
	{
		VkDisplayPlanePropertiesKHR init = {0};
		return init;
	}

	static inline VkDisplayPlanePropertiesKHR vkiDisplayPlanePropertiesKHR(VkDisplayKHR currentDisplay, uint32_t currentStackIndex)
	{
		VkDisplayPlanePropertiesKHR init = vkiDisplayPlanePropertiesKHR_null();
		init.currentDisplay = currentDisplay;
		init.currentStackIndex = currentStackIndex;
		return init;
	}

	static inline VkDisplayPropertiesKHR vkiDisplayPropertiesKHR_null()
	{
		VkDisplayPropertiesKHR init = {0};
		return init;
	}

	static inline VkDisplayPropertiesKHR vkiDisplayPropertiesKHR(VkDisplayKHR display, const char *displayName, VkExtent2D physicalDimensions, VkExtent2D physicalResolution, VkSurfaceTransformFlagsKHR supportedTransforms, VkBool32 planeReorderPossible, VkBool32 persistentContent)
	{
		VkDisplayPropertiesKHR init = vkiDisplayPropertiesKHR_null();
		init.display = display;
		init.displayName = displayName;
		init.physicalDimensions = physicalDimensions;
		init.physicalResolution = physicalResolution;
		init.supportedTransforms = supportedTransforms;
		init.planeReorderPossible = planeReorderPossible;
		init.persistentContent = persistentContent;
		return init;
	}

	static inline VkDisplaySurfaceCreateInfoKHR vkiDisplaySurfaceCreateInfoKHR_null()
	{
		VkDisplaySurfaceCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR;
		return init;
	}

	static inline VkDisplaySurfaceCreateInfoKHR vkiDisplaySurfaceCreateInfoKHR(VkDisplayModeKHR displayMode, uint32_t planeIndex, uint32_t planeStackIndex, VkSurfaceTransformFlagBitsKHR transform, float globalAlpha, VkDisplayPlaneAlphaFlagBitsKHR alphaMode, VkExtent2D imageExtent)
	{
		VkDisplaySurfaceCreateInfoKHR init = vkiDisplaySurfaceCreateInfoKHR_null();
		init.displayMode = displayMode;
		init.planeIndex = planeIndex;
		init.planeStackIndex = planeStackIndex;
		init.transform = transform;
		init.globalAlpha = globalAlpha;
		init.alphaMode = alphaMode;
		init.imageExtent = imageExtent;
		return init;
	}

	static inline VkDisplayPresentInfoKHR vkiDisplayPresentInfoKHR_null()
	{
		VkDisplayPresentInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR;
		return init;
	}

	static inline VkDisplayPresentInfoKHR vkiDisplayPresentInfoKHR(VkRect2D srcRect, VkRect2D dstRect, VkBool32 persistent)
	{
		VkDisplayPresentInfoKHR init = vkiDisplayPresentInfoKHR_null();
		init.srcRect = srcRect;
		init.dstRect = dstRect;
		init.persistent = persistent;
		return init;
	}

	static inline VkQueueFamilyQueryResultStatusPropertiesKHR vkiQueueFamilyQueryResultStatusPropertiesKHR_null()
	{
		VkQueueFamilyQueryResultStatusPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR;
		return init;
	}

	static inline VkQueueFamilyQueryResultStatusPropertiesKHR vkiQueueFamilyQueryResultStatusPropertiesKHR(VkBool32 queryResultStatusSupport)
	{
		VkQueueFamilyQueryResultStatusPropertiesKHR init = vkiQueueFamilyQueryResultStatusPropertiesKHR_null();
		init.queryResultStatusSupport = queryResultStatusSupport;
		return init;
	}

	static inline VkQueueFamilyVideoPropertiesKHR vkiQueueFamilyVideoPropertiesKHR_null()
	{
		VkQueueFamilyVideoPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR;
		return init;
	}

	static inline VkQueueFamilyVideoPropertiesKHR vkiQueueFamilyVideoPropertiesKHR(VkVideoCodecOperationFlagsKHR videoCodecOperations)
	{
		VkQueueFamilyVideoPropertiesKHR init = vkiQueueFamilyVideoPropertiesKHR_null();
		init.videoCodecOperations = videoCodecOperations;
		return init;
	}

	static inline VkVideoProfileInfoKHR vkiVideoProfileInfoKHR_null()
	{
		VkVideoProfileInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR;
		return init;
	}

	static inline VkVideoProfileInfoKHR vkiVideoProfileInfoKHR(VkVideoCodecOperationFlagBitsKHR videoCodecOperation, VkVideoChromaSubsamplingFlagsKHR chromaSubsampling, VkVideoComponentBitDepthFlagsKHR lumaBitDepth, VkVideoComponentBitDepthFlagsKHR chromaBitDepth)
	{
		VkVideoProfileInfoKHR init = vkiVideoProfileInfoKHR_null();
		init.videoCodecOperation = videoCodecOperation;
		init.chromaSubsampling = chromaSubsampling;
		init.lumaBitDepth = lumaBitDepth;
		init.chromaBitDepth = chromaBitDepth;
		return init;
	}

	static inline VkVideoProfileListInfoKHR vkiVideoProfileListInfoKHR_null()
	{
		VkVideoProfileListInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR;
		return init;
	}

	static inline VkVideoProfileListInfoKHR vkiVideoProfileListInfoKHR(uint32_t profileCount, const VkVideoProfileInfoKHR *pProfiles)
	{
		VkVideoProfileListInfoKHR init = vkiVideoProfileListInfoKHR_null();
		init.profileCount = profileCount;
		init.pProfiles = pProfiles;
		return init;
	}

	static inline VkVideoCapabilitiesKHR vkiVideoCapabilitiesKHR_null()
	{
		VkVideoCapabilitiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR;
		return init;
	}

	static inline VkVideoCapabilitiesKHR vkiVideoCapabilitiesKHR(VkDeviceSize minBitstreamBufferOffsetAlignment, VkDeviceSize minBitstreamBufferSizeAlignment, VkExtent2D pictureAccessGranularity, VkExtent2D minCodedExtent, VkExtent2D maxCodedExtent, uint32_t maxDpbSlots, uint32_t maxActiveReferencePictures, VkExtensionProperties stdHeaderVersion)
	{
		VkVideoCapabilitiesKHR init = vkiVideoCapabilitiesKHR_null();
		init.minBitstreamBufferOffsetAlignment = minBitstreamBufferOffsetAlignment;
		init.minBitstreamBufferSizeAlignment = minBitstreamBufferSizeAlignment;
		init.pictureAccessGranularity = pictureAccessGranularity;
		init.minCodedExtent = minCodedExtent;
		init.maxCodedExtent = maxCodedExtent;
		init.maxDpbSlots = maxDpbSlots;
		init.maxActiveReferencePictures = maxActiveReferencePictures;
		init.stdHeaderVersion = stdHeaderVersion;
		return init;
	}

	static inline VkPhysicalDeviceVideoFormatInfoKHR vkiPhysicalDeviceVideoFormatInfoKHR_null()
	{
		VkPhysicalDeviceVideoFormatInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR;
		return init;
	}

	static inline VkPhysicalDeviceVideoFormatInfoKHR vkiPhysicalDeviceVideoFormatInfoKHR(VkImageUsageFlags imageUsage)
	{
		VkPhysicalDeviceVideoFormatInfoKHR init = vkiPhysicalDeviceVideoFormatInfoKHR_null();
		init.imageUsage = imageUsage;
		return init;
	}

	static inline VkVideoFormatPropertiesKHR vkiVideoFormatPropertiesKHR_null()
	{
		VkVideoFormatPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR;
		return init;
	}

	static inline VkVideoFormatPropertiesKHR vkiVideoFormatPropertiesKHR(VkFormat format, VkComponentMapping componentMapping, VkImageCreateFlags imageCreateFlags, VkImageType imageType, VkImageTiling imageTiling, VkImageUsageFlags imageUsageFlags)
	{
		VkVideoFormatPropertiesKHR init = vkiVideoFormatPropertiesKHR_null();
		init.format = format;
		init.componentMapping = componentMapping;
		init.imageCreateFlags = imageCreateFlags;
		init.imageType = imageType;
		init.imageTiling = imageTiling;
		init.imageUsageFlags = imageUsageFlags;
		return init;
	}

	static inline VkVideoPictureResourceInfoKHR vkiVideoPictureResourceInfoKHR_null()
	{
		VkVideoPictureResourceInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR;
		return init;
	}

	static inline VkVideoPictureResourceInfoKHR vkiVideoPictureResourceInfoKHR(VkOffset2D codedOffset, VkExtent2D codedExtent, uint32_t baseArrayLayer, VkImageView imageViewBinding)
	{
		VkVideoPictureResourceInfoKHR init = vkiVideoPictureResourceInfoKHR_null();
		init.codedOffset = codedOffset;
		init.codedExtent = codedExtent;
		init.baseArrayLayer = baseArrayLayer;
		init.imageViewBinding = imageViewBinding;
		return init;
	}

	static inline VkVideoReferenceSlotInfoKHR vkiVideoReferenceSlotInfoKHR_null()
	{
		VkVideoReferenceSlotInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR;
		return init;
	}

	static inline VkVideoReferenceSlotInfoKHR vkiVideoReferenceSlotInfoKHR(int32_t slotIndex, const VkVideoPictureResourceInfoKHR *pPictureResource)
	{
		VkVideoReferenceSlotInfoKHR init = vkiVideoReferenceSlotInfoKHR_null();
		init.slotIndex = slotIndex;
		init.pPictureResource = pPictureResource;
		return init;
	}

	static inline VkVideoSessionMemoryRequirementsKHR vkiVideoSessionMemoryRequirementsKHR_null()
	{
		VkVideoSessionMemoryRequirementsKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR;
		return init;
	}

	static inline VkVideoSessionMemoryRequirementsKHR vkiVideoSessionMemoryRequirementsKHR(uint32_t memoryBindIndex, VkMemoryRequirements memoryRequirements)
	{
		VkVideoSessionMemoryRequirementsKHR init = vkiVideoSessionMemoryRequirementsKHR_null();
		init.memoryBindIndex = memoryBindIndex;
		init.memoryRequirements = memoryRequirements;
		return init;
	}

	static inline VkBindVideoSessionMemoryInfoKHR vkiBindVideoSessionMemoryInfoKHR_null()
	{
		VkBindVideoSessionMemoryInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR;
		return init;
	}

	static inline VkBindVideoSessionMemoryInfoKHR vkiBindVideoSessionMemoryInfoKHR(uint32_t memoryBindIndex, VkDeviceMemory memory, VkDeviceSize memoryOffset, VkDeviceSize memorySize)
	{
		VkBindVideoSessionMemoryInfoKHR init = vkiBindVideoSessionMemoryInfoKHR_null();
		init.memoryBindIndex = memoryBindIndex;
		init.memory = memory;
		init.memoryOffset = memoryOffset;
		init.memorySize = memorySize;
		return init;
	}

	static inline VkVideoSessionCreateInfoKHR vkiVideoSessionCreateInfoKHR_null()
	{
		VkVideoSessionCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR;
		return init;
	}

	static inline VkVideoSessionCreateInfoKHR vkiVideoSessionCreateInfoKHR(uint32_t queueFamilyIndex, const VkVideoProfileInfoKHR *pVideoProfile, VkFormat pictureFormat, VkExtent2D maxCodedExtent, VkFormat referencePictureFormat, uint32_t maxDpbSlots, uint32_t maxActiveReferencePictures, const VkExtensionProperties *pStdHeaderVersion)
	{
		VkVideoSessionCreateInfoKHR init = vkiVideoSessionCreateInfoKHR_null();
		init.queueFamilyIndex = queueFamilyIndex;
		init.pVideoProfile = pVideoProfile;
		init.pictureFormat = pictureFormat;
		init.maxCodedExtent = maxCodedExtent;
		init.referencePictureFormat = referencePictureFormat;
		init.maxDpbSlots = maxDpbSlots;
		init.maxActiveReferencePictures = maxActiveReferencePictures;
		init.pStdHeaderVersion = pStdHeaderVersion;
		return init;
	}

	static inline VkVideoSessionParametersCreateInfoKHR vkiVideoSessionParametersCreateInfoKHR_null()
	{
		VkVideoSessionParametersCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR;
		return init;
	}

	static inline VkVideoSessionParametersCreateInfoKHR vkiVideoSessionParametersCreateInfoKHR(VkVideoSessionParametersKHR videoSessionParametersTemplate, VkVideoSessionKHR videoSession)
	{
		VkVideoSessionParametersCreateInfoKHR init = vkiVideoSessionParametersCreateInfoKHR_null();
		init.videoSessionParametersTemplate = videoSessionParametersTemplate;
		init.videoSession = videoSession;
		return init;
	}

	static inline VkVideoSessionParametersUpdateInfoKHR vkiVideoSessionParametersUpdateInfoKHR_null()
	{
		VkVideoSessionParametersUpdateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR;
		return init;
	}

	static inline VkVideoSessionParametersUpdateInfoKHR vkiVideoSessionParametersUpdateInfoKHR(uint32_t updateSequenceCount)
	{
		VkVideoSessionParametersUpdateInfoKHR init = vkiVideoSessionParametersUpdateInfoKHR_null();
		init.updateSequenceCount = updateSequenceCount;
		return init;
	}

	static inline VkVideoBeginCodingInfoKHR vkiVideoBeginCodingInfoKHR_null()
	{
		VkVideoBeginCodingInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR;
		return init;
	}

	static inline VkVideoBeginCodingInfoKHR vkiVideoBeginCodingInfoKHR(VkVideoSessionKHR videoSession, VkVideoSessionParametersKHR videoSessionParameters, uint32_t referenceSlotCount, const VkVideoReferenceSlotInfoKHR *pReferenceSlots)
	{
		VkVideoBeginCodingInfoKHR init = vkiVideoBeginCodingInfoKHR_null();
		init.videoSession = videoSession;
		init.videoSessionParameters = videoSessionParameters;
		init.referenceSlotCount = referenceSlotCount;
		init.pReferenceSlots = pReferenceSlots;
		return init;
	}

	static inline VkVideoEndCodingInfoKHR vkiVideoEndCodingInfoKHR_null()
	{
		VkVideoEndCodingInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR;
		return init;
	}

	static inline VkVideoEndCodingInfoKHR vkiVideoEndCodingInfoKHR()
	{
		VkVideoEndCodingInfoKHR init = vkiVideoEndCodingInfoKHR_null();
		return init;
	}

	static inline VkVideoCodingControlInfoKHR vkiVideoCodingControlInfoKHR_null()
	{
		VkVideoCodingControlInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR;
		return init;
	}

	static inline VkVideoCodingControlInfoKHR vkiVideoCodingControlInfoKHR()
	{
		VkVideoCodingControlInfoKHR init = vkiVideoCodingControlInfoKHR_null();
		return init;
	}

	static inline VkVideoDecodeCapabilitiesKHR vkiVideoDecodeCapabilitiesKHR_null()
	{
		VkVideoDecodeCapabilitiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR;
		return init;
	}

	static inline VkVideoDecodeCapabilitiesKHR vkiVideoDecodeCapabilitiesKHR()
	{
		VkVideoDecodeCapabilitiesKHR init = vkiVideoDecodeCapabilitiesKHR_null();
		return init;
	}

	static inline VkVideoDecodeUsageInfoKHR vkiVideoDecodeUsageInfoKHR_null()
	{
		VkVideoDecodeUsageInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeUsageInfoKHR vkiVideoDecodeUsageInfoKHR(VkVideoDecodeUsageFlagsKHR videoUsageHints)
	{
		VkVideoDecodeUsageInfoKHR init = vkiVideoDecodeUsageInfoKHR_null();
		init.videoUsageHints = videoUsageHints;
		return init;
	}

	static inline VkVideoDecodeInfoKHR vkiVideoDecodeInfoKHR_null()
	{
		VkVideoDecodeInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeInfoKHR vkiVideoDecodeInfoKHR(VkBuffer srcBuffer, VkDeviceSize srcBufferOffset, VkDeviceSize srcBufferRange, VkVideoPictureResourceInfoKHR dstPictureResource, const VkVideoReferenceSlotInfoKHR *pSetupReferenceSlot, uint32_t referenceSlotCount, const VkVideoReferenceSlotInfoKHR *pReferenceSlots)
	{
		VkVideoDecodeInfoKHR init = vkiVideoDecodeInfoKHR_null();
		init.srcBuffer = srcBuffer;
		init.srcBufferOffset = srcBufferOffset;
		init.srcBufferRange = srcBufferRange;
		init.dstPictureResource = dstPictureResource;
		init.pSetupReferenceSlot = pSetupReferenceSlot;
		init.referenceSlotCount = referenceSlotCount;
		init.pReferenceSlots = pReferenceSlots;
		return init;
	}

	static inline VkVideoEncodeH264CapabilitiesKHR vkiVideoEncodeH264CapabilitiesKHR_null()
	{
		VkVideoEncodeH264CapabilitiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR;
		return init;
	}

	static inline VkVideoEncodeH264CapabilitiesKHR vkiVideoEncodeH264CapabilitiesKHR(StdVideoH264LevelIdc maxLevelIdc, uint32_t maxSliceCount, uint32_t maxPPictureL0ReferenceCount, uint32_t maxBPictureL0ReferenceCount, uint32_t maxL1ReferenceCount, uint32_t maxTemporalLayerCount, VkBool32 expectDyadicTemporalLayerPattern, int32_t minQp, int32_t maxQp, VkBool32 prefersGopRemainingFrames, VkBool32 requiresGopRemainingFrames, VkVideoEncodeH264StdFlagsKHR stdSyntaxFlags)
	{
		VkVideoEncodeH264CapabilitiesKHR init = vkiVideoEncodeH264CapabilitiesKHR_null();
		init.maxLevelIdc = maxLevelIdc;
		init.maxSliceCount = maxSliceCount;
		init.maxPPictureL0ReferenceCount = maxPPictureL0ReferenceCount;
		init.maxBPictureL0ReferenceCount = maxBPictureL0ReferenceCount;
		init.maxL1ReferenceCount = maxL1ReferenceCount;
		init.maxTemporalLayerCount = maxTemporalLayerCount;
		init.expectDyadicTemporalLayerPattern = expectDyadicTemporalLayerPattern;
		init.minQp = minQp;
		init.maxQp = maxQp;
		init.prefersGopRemainingFrames = prefersGopRemainingFrames;
		init.requiresGopRemainingFrames = requiresGopRemainingFrames;
		init.stdSyntaxFlags = stdSyntaxFlags;
		return init;
	}

	static inline VkVideoEncodeH264QpKHR vkiVideoEncodeH264QpKHR_null()
	{
		VkVideoEncodeH264QpKHR init = {0};
		return init;
	}

	static inline VkVideoEncodeH264QpKHR vkiVideoEncodeH264QpKHR(int32_t qpI, int32_t qpP, int32_t qpB)
	{
		VkVideoEncodeH264QpKHR init = vkiVideoEncodeH264QpKHR_null();
		init.qpI = qpI;
		init.qpP = qpP;
		init.qpB = qpB;
		return init;
	}

	static inline VkVideoEncodeH264QualityLevelPropertiesKHR vkiVideoEncodeH264QualityLevelPropertiesKHR_null()
	{
		VkVideoEncodeH264QualityLevelPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR;
		return init;
	}

	static inline VkVideoEncodeH264QualityLevelPropertiesKHR vkiVideoEncodeH264QualityLevelPropertiesKHR(VkVideoEncodeH264RateControlFlagsKHR preferredRateControlFlags, uint32_t preferredGopFrameCount, uint32_t preferredIdrPeriod, uint32_t preferredConsecutiveBFrameCount, uint32_t preferredTemporalLayerCount, VkVideoEncodeH264QpKHR preferredConstantQp, uint32_t preferredMaxL0ReferenceCount, uint32_t preferredMaxL1ReferenceCount, VkBool32 preferredStdEntropyCodingModeFlag)
	{
		VkVideoEncodeH264QualityLevelPropertiesKHR init = vkiVideoEncodeH264QualityLevelPropertiesKHR_null();
		init.preferredRateControlFlags = preferredRateControlFlags;
		init.preferredGopFrameCount = preferredGopFrameCount;
		init.preferredIdrPeriod = preferredIdrPeriod;
		init.preferredConsecutiveBFrameCount = preferredConsecutiveBFrameCount;
		init.preferredTemporalLayerCount = preferredTemporalLayerCount;
		init.preferredConstantQp = preferredConstantQp;
		init.preferredMaxL0ReferenceCount = preferredMaxL0ReferenceCount;
		init.preferredMaxL1ReferenceCount = preferredMaxL1ReferenceCount;
		init.preferredStdEntropyCodingModeFlag = preferredStdEntropyCodingModeFlag;
		return init;
	}

	static inline VkVideoEncodeH264SessionCreateInfoKHR vkiVideoEncodeH264SessionCreateInfoKHR_null()
	{
		VkVideoEncodeH264SessionCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH264SessionCreateInfoKHR vkiVideoEncodeH264SessionCreateInfoKHR(VkBool32 useMaxLevelIdc, StdVideoH264LevelIdc maxLevelIdc)
	{
		VkVideoEncodeH264SessionCreateInfoKHR init = vkiVideoEncodeH264SessionCreateInfoKHR_null();
		init.useMaxLevelIdc = useMaxLevelIdc;
		init.maxLevelIdc = maxLevelIdc;
		return init;
	}

	static inline VkVideoEncodeH264SessionParametersAddInfoKHR vkiVideoEncodeH264SessionParametersAddInfoKHR_null()
	{
		VkVideoEncodeH264SessionParametersAddInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH264SessionParametersAddInfoKHR vkiVideoEncodeH264SessionParametersAddInfoKHR(uint32_t stdSPSCount, const StdVideoH264SequenceParameterSet *pStdSPSs, uint32_t stdPPSCount, const StdVideoH264PictureParameterSet *pStdPPSs)
	{
		VkVideoEncodeH264SessionParametersAddInfoKHR init = vkiVideoEncodeH264SessionParametersAddInfoKHR_null();
		init.stdSPSCount = stdSPSCount;
		init.pStdSPSs = pStdSPSs;
		init.stdPPSCount = stdPPSCount;
		init.pStdPPSs = pStdPPSs;
		return init;
	}

	static inline VkVideoEncodeH264SessionParametersCreateInfoKHR vkiVideoEncodeH264SessionParametersCreateInfoKHR_null()
	{
		VkVideoEncodeH264SessionParametersCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH264SessionParametersCreateInfoKHR vkiVideoEncodeH264SessionParametersCreateInfoKHR(uint32_t maxStdSPSCount, uint32_t maxStdPPSCount, const VkVideoEncodeH264SessionParametersAddInfoKHR *pParametersAddInfo)
	{
		VkVideoEncodeH264SessionParametersCreateInfoKHR init = vkiVideoEncodeH264SessionParametersCreateInfoKHR_null();
		init.maxStdSPSCount = maxStdSPSCount;
		init.maxStdPPSCount = maxStdPPSCount;
		init.pParametersAddInfo = pParametersAddInfo;
		return init;
	}

	static inline VkVideoEncodeH264SessionParametersGetInfoKHR vkiVideoEncodeH264SessionParametersGetInfoKHR_null()
	{
		VkVideoEncodeH264SessionParametersGetInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH264SessionParametersGetInfoKHR vkiVideoEncodeH264SessionParametersGetInfoKHR(VkBool32 writeStdSPS, VkBool32 writeStdPPS, uint32_t stdSPSId, uint32_t stdPPSId)
	{
		VkVideoEncodeH264SessionParametersGetInfoKHR init = vkiVideoEncodeH264SessionParametersGetInfoKHR_null();
		init.writeStdSPS = writeStdSPS;
		init.writeStdPPS = writeStdPPS;
		init.stdSPSId = stdSPSId;
		init.stdPPSId = stdPPSId;
		return init;
	}

	static inline VkVideoEncodeH264SessionParametersFeedbackInfoKHR vkiVideoEncodeH264SessionParametersFeedbackInfoKHR_null()
	{
		VkVideoEncodeH264SessionParametersFeedbackInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH264SessionParametersFeedbackInfoKHR vkiVideoEncodeH264SessionParametersFeedbackInfoKHR(VkBool32 hasStdSPSOverrides, VkBool32 hasStdPPSOverrides)
	{
		VkVideoEncodeH264SessionParametersFeedbackInfoKHR init = vkiVideoEncodeH264SessionParametersFeedbackInfoKHR_null();
		init.hasStdSPSOverrides = hasStdSPSOverrides;
		init.hasStdPPSOverrides = hasStdPPSOverrides;
		return init;
	}

	static inline VkVideoEncodeH264NaluSliceInfoKHR vkiVideoEncodeH264NaluSliceInfoKHR_null()
	{
		VkVideoEncodeH264NaluSliceInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH264NaluSliceInfoKHR vkiVideoEncodeH264NaluSliceInfoKHR(int32_t constantQp, const StdVideoEncodeH264SliceHeader *pStdSliceHeader)
	{
		VkVideoEncodeH264NaluSliceInfoKHR init = vkiVideoEncodeH264NaluSliceInfoKHR_null();
		init.constantQp = constantQp;
		init.pStdSliceHeader = pStdSliceHeader;
		return init;
	}

	static inline VkVideoEncodeH264PictureInfoKHR vkiVideoEncodeH264PictureInfoKHR_null()
	{
		VkVideoEncodeH264PictureInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH264PictureInfoKHR vkiVideoEncodeH264PictureInfoKHR(uint32_t naluSliceEntryCount, const VkVideoEncodeH264NaluSliceInfoKHR *pNaluSliceEntries, const StdVideoEncodeH264PictureInfo *pStdPictureInfo, VkBool32 generatePrefixNalu)
	{
		VkVideoEncodeH264PictureInfoKHR init = vkiVideoEncodeH264PictureInfoKHR_null();
		init.naluSliceEntryCount = naluSliceEntryCount;
		init.pNaluSliceEntries = pNaluSliceEntries;
		init.pStdPictureInfo = pStdPictureInfo;
		init.generatePrefixNalu = generatePrefixNalu;
		return init;
	}

	static inline VkVideoEncodeH264DpbSlotInfoKHR vkiVideoEncodeH264DpbSlotInfoKHR_null()
	{
		VkVideoEncodeH264DpbSlotInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH264DpbSlotInfoKHR vkiVideoEncodeH264DpbSlotInfoKHR(const StdVideoEncodeH264ReferenceInfo *pStdReferenceInfo)
	{
		VkVideoEncodeH264DpbSlotInfoKHR init = vkiVideoEncodeH264DpbSlotInfoKHR_null();
		init.pStdReferenceInfo = pStdReferenceInfo;
		return init;
	}

	static inline VkVideoEncodeH264ProfileInfoKHR vkiVideoEncodeH264ProfileInfoKHR_null()
	{
		VkVideoEncodeH264ProfileInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH264ProfileInfoKHR vkiVideoEncodeH264ProfileInfoKHR(StdVideoH264ProfileIdc stdProfileIdc)
	{
		VkVideoEncodeH264ProfileInfoKHR init = vkiVideoEncodeH264ProfileInfoKHR_null();
		init.stdProfileIdc = stdProfileIdc;
		return init;
	}

	static inline VkVideoEncodeH264RateControlInfoKHR vkiVideoEncodeH264RateControlInfoKHR_null()
	{
		VkVideoEncodeH264RateControlInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH264RateControlInfoKHR vkiVideoEncodeH264RateControlInfoKHR(uint32_t gopFrameCount, uint32_t idrPeriod, uint32_t consecutiveBFrameCount, uint32_t temporalLayerCount)
	{
		VkVideoEncodeH264RateControlInfoKHR init = vkiVideoEncodeH264RateControlInfoKHR_null();
		init.gopFrameCount = gopFrameCount;
		init.idrPeriod = idrPeriod;
		init.consecutiveBFrameCount = consecutiveBFrameCount;
		init.temporalLayerCount = temporalLayerCount;
		return init;
	}

	static inline VkVideoEncodeH264FrameSizeKHR vkiVideoEncodeH264FrameSizeKHR_null()
	{
		VkVideoEncodeH264FrameSizeKHR init = {0};
		return init;
	}

	static inline VkVideoEncodeH264FrameSizeKHR vkiVideoEncodeH264FrameSizeKHR(uint32_t frameISize, uint32_t framePSize, uint32_t frameBSize)
	{
		VkVideoEncodeH264FrameSizeKHR init = vkiVideoEncodeH264FrameSizeKHR_null();
		init.frameISize = frameISize;
		init.framePSize = framePSize;
		init.frameBSize = frameBSize;
		return init;
	}

	static inline VkVideoEncodeH264RateControlLayerInfoKHR vkiVideoEncodeH264RateControlLayerInfoKHR_null()
	{
		VkVideoEncodeH264RateControlLayerInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH264RateControlLayerInfoKHR vkiVideoEncodeH264RateControlLayerInfoKHR(VkBool32 useMinQp, VkVideoEncodeH264QpKHR minQp, VkBool32 useMaxQp, VkVideoEncodeH264QpKHR maxQp, VkBool32 useMaxFrameSize, VkVideoEncodeH264FrameSizeKHR maxFrameSize)
	{
		VkVideoEncodeH264RateControlLayerInfoKHR init = vkiVideoEncodeH264RateControlLayerInfoKHR_null();
		init.useMinQp = useMinQp;
		init.minQp = minQp;
		init.useMaxQp = useMaxQp;
		init.maxQp = maxQp;
		init.useMaxFrameSize = useMaxFrameSize;
		init.maxFrameSize = maxFrameSize;
		return init;
	}

	static inline VkVideoEncodeH264GopRemainingFrameInfoKHR vkiVideoEncodeH264GopRemainingFrameInfoKHR_null()
	{
		VkVideoEncodeH264GopRemainingFrameInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH264GopRemainingFrameInfoKHR vkiVideoEncodeH264GopRemainingFrameInfoKHR(VkBool32 useGopRemainingFrames, uint32_t gopRemainingI, uint32_t gopRemainingP, uint32_t gopRemainingB)
	{
		VkVideoEncodeH264GopRemainingFrameInfoKHR init = vkiVideoEncodeH264GopRemainingFrameInfoKHR_null();
		init.useGopRemainingFrames = useGopRemainingFrames;
		init.gopRemainingI = gopRemainingI;
		init.gopRemainingP = gopRemainingP;
		init.gopRemainingB = gopRemainingB;
		return init;
	}

	static inline VkVideoEncodeH265CapabilitiesKHR vkiVideoEncodeH265CapabilitiesKHR_null()
	{
		VkVideoEncodeH265CapabilitiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR;
		return init;
	}

	static inline VkVideoEncodeH265CapabilitiesKHR vkiVideoEncodeH265CapabilitiesKHR(StdVideoH265LevelIdc maxLevelIdc, uint32_t maxSliceSegmentCount, VkExtent2D maxTiles, VkVideoEncodeH265CtbSizeFlagsKHR ctbSizes, VkVideoEncodeH265TransformBlockSizeFlagsKHR transformBlockSizes, uint32_t maxPPictureL0ReferenceCount, uint32_t maxBPictureL0ReferenceCount, uint32_t maxL1ReferenceCount, uint32_t maxSubLayerCount, VkBool32 expectDyadicTemporalSubLayerPattern, int32_t minQp, int32_t maxQp, VkBool32 prefersGopRemainingFrames, VkBool32 requiresGopRemainingFrames, VkVideoEncodeH265StdFlagsKHR stdSyntaxFlags)
	{
		VkVideoEncodeH265CapabilitiesKHR init = vkiVideoEncodeH265CapabilitiesKHR_null();
		init.maxLevelIdc = maxLevelIdc;
		init.maxSliceSegmentCount = maxSliceSegmentCount;
		init.maxTiles = maxTiles;
		init.ctbSizes = ctbSizes;
		init.transformBlockSizes = transformBlockSizes;
		init.maxPPictureL0ReferenceCount = maxPPictureL0ReferenceCount;
		init.maxBPictureL0ReferenceCount = maxBPictureL0ReferenceCount;
		init.maxL1ReferenceCount = maxL1ReferenceCount;
		init.maxSubLayerCount = maxSubLayerCount;
		init.expectDyadicTemporalSubLayerPattern = expectDyadicTemporalSubLayerPattern;
		init.minQp = minQp;
		init.maxQp = maxQp;
		init.prefersGopRemainingFrames = prefersGopRemainingFrames;
		init.requiresGopRemainingFrames = requiresGopRemainingFrames;
		init.stdSyntaxFlags = stdSyntaxFlags;
		return init;
	}

	static inline VkVideoEncodeH265SessionCreateInfoKHR vkiVideoEncodeH265SessionCreateInfoKHR_null()
	{
		VkVideoEncodeH265SessionCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH265SessionCreateInfoKHR vkiVideoEncodeH265SessionCreateInfoKHR(VkBool32 useMaxLevelIdc, StdVideoH265LevelIdc maxLevelIdc)
	{
		VkVideoEncodeH265SessionCreateInfoKHR init = vkiVideoEncodeH265SessionCreateInfoKHR_null();
		init.useMaxLevelIdc = useMaxLevelIdc;
		init.maxLevelIdc = maxLevelIdc;
		return init;
	}

	static inline VkVideoEncodeH265QpKHR vkiVideoEncodeH265QpKHR_null()
	{
		VkVideoEncodeH265QpKHR init = {0};
		return init;
	}

	static inline VkVideoEncodeH265QpKHR vkiVideoEncodeH265QpKHR(int32_t qpI, int32_t qpP, int32_t qpB)
	{
		VkVideoEncodeH265QpKHR init = vkiVideoEncodeH265QpKHR_null();
		init.qpI = qpI;
		init.qpP = qpP;
		init.qpB = qpB;
		return init;
	}

	static inline VkVideoEncodeH265QualityLevelPropertiesKHR vkiVideoEncodeH265QualityLevelPropertiesKHR_null()
	{
		VkVideoEncodeH265QualityLevelPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR;
		return init;
	}

	static inline VkVideoEncodeH265QualityLevelPropertiesKHR vkiVideoEncodeH265QualityLevelPropertiesKHR(VkVideoEncodeH265RateControlFlagsKHR preferredRateControlFlags, uint32_t preferredGopFrameCount, uint32_t preferredIdrPeriod, uint32_t preferredConsecutiveBFrameCount, uint32_t preferredSubLayerCount, VkVideoEncodeH265QpKHR preferredConstantQp, uint32_t preferredMaxL0ReferenceCount, uint32_t preferredMaxL1ReferenceCount)
	{
		VkVideoEncodeH265QualityLevelPropertiesKHR init = vkiVideoEncodeH265QualityLevelPropertiesKHR_null();
		init.preferredRateControlFlags = preferredRateControlFlags;
		init.preferredGopFrameCount = preferredGopFrameCount;
		init.preferredIdrPeriod = preferredIdrPeriod;
		init.preferredConsecutiveBFrameCount = preferredConsecutiveBFrameCount;
		init.preferredSubLayerCount = preferredSubLayerCount;
		init.preferredConstantQp = preferredConstantQp;
		init.preferredMaxL0ReferenceCount = preferredMaxL0ReferenceCount;
		init.preferredMaxL1ReferenceCount = preferredMaxL1ReferenceCount;
		return init;
	}

	static inline VkVideoEncodeH265SessionParametersAddInfoKHR vkiVideoEncodeH265SessionParametersAddInfoKHR_null()
	{
		VkVideoEncodeH265SessionParametersAddInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH265SessionParametersAddInfoKHR vkiVideoEncodeH265SessionParametersAddInfoKHR(uint32_t stdVPSCount, const StdVideoH265VideoParameterSet *pStdVPSs, uint32_t stdSPSCount, const StdVideoH265SequenceParameterSet *pStdSPSs, uint32_t stdPPSCount, const StdVideoH265PictureParameterSet *pStdPPSs)
	{
		VkVideoEncodeH265SessionParametersAddInfoKHR init = vkiVideoEncodeH265SessionParametersAddInfoKHR_null();
		init.stdVPSCount = stdVPSCount;
		init.pStdVPSs = pStdVPSs;
		init.stdSPSCount = stdSPSCount;
		init.pStdSPSs = pStdSPSs;
		init.stdPPSCount = stdPPSCount;
		init.pStdPPSs = pStdPPSs;
		return init;
	}

	static inline VkVideoEncodeH265SessionParametersCreateInfoKHR vkiVideoEncodeH265SessionParametersCreateInfoKHR_null()
	{
		VkVideoEncodeH265SessionParametersCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH265SessionParametersCreateInfoKHR vkiVideoEncodeH265SessionParametersCreateInfoKHR(uint32_t maxStdVPSCount, uint32_t maxStdSPSCount, uint32_t maxStdPPSCount, const VkVideoEncodeH265SessionParametersAddInfoKHR *pParametersAddInfo)
	{
		VkVideoEncodeH265SessionParametersCreateInfoKHR init = vkiVideoEncodeH265SessionParametersCreateInfoKHR_null();
		init.maxStdVPSCount = maxStdVPSCount;
		init.maxStdSPSCount = maxStdSPSCount;
		init.maxStdPPSCount = maxStdPPSCount;
		init.pParametersAddInfo = pParametersAddInfo;
		return init;
	}

	static inline VkVideoEncodeH265SessionParametersGetInfoKHR vkiVideoEncodeH265SessionParametersGetInfoKHR_null()
	{
		VkVideoEncodeH265SessionParametersGetInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH265SessionParametersGetInfoKHR vkiVideoEncodeH265SessionParametersGetInfoKHR(VkBool32 writeStdVPS, VkBool32 writeStdSPS, VkBool32 writeStdPPS, uint32_t stdVPSId, uint32_t stdSPSId, uint32_t stdPPSId)
	{
		VkVideoEncodeH265SessionParametersGetInfoKHR init = vkiVideoEncodeH265SessionParametersGetInfoKHR_null();
		init.writeStdVPS = writeStdVPS;
		init.writeStdSPS = writeStdSPS;
		init.writeStdPPS = writeStdPPS;
		init.stdVPSId = stdVPSId;
		init.stdSPSId = stdSPSId;
		init.stdPPSId = stdPPSId;
		return init;
	}

	static inline VkVideoEncodeH265SessionParametersFeedbackInfoKHR vkiVideoEncodeH265SessionParametersFeedbackInfoKHR_null()
	{
		VkVideoEncodeH265SessionParametersFeedbackInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH265SessionParametersFeedbackInfoKHR vkiVideoEncodeH265SessionParametersFeedbackInfoKHR(VkBool32 hasStdVPSOverrides, VkBool32 hasStdSPSOverrides, VkBool32 hasStdPPSOverrides)
	{
		VkVideoEncodeH265SessionParametersFeedbackInfoKHR init = vkiVideoEncodeH265SessionParametersFeedbackInfoKHR_null();
		init.hasStdVPSOverrides = hasStdVPSOverrides;
		init.hasStdSPSOverrides = hasStdSPSOverrides;
		init.hasStdPPSOverrides = hasStdPPSOverrides;
		return init;
	}

	static inline VkVideoEncodeH265NaluSliceSegmentInfoKHR vkiVideoEncodeH265NaluSliceSegmentInfoKHR_null()
	{
		VkVideoEncodeH265NaluSliceSegmentInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH265NaluSliceSegmentInfoKHR vkiVideoEncodeH265NaluSliceSegmentInfoKHR(int32_t constantQp, const StdVideoEncodeH265SliceSegmentHeader *pStdSliceSegmentHeader)
	{
		VkVideoEncodeH265NaluSliceSegmentInfoKHR init = vkiVideoEncodeH265NaluSliceSegmentInfoKHR_null();
		init.constantQp = constantQp;
		init.pStdSliceSegmentHeader = pStdSliceSegmentHeader;
		return init;
	}

	static inline VkVideoEncodeH265PictureInfoKHR vkiVideoEncodeH265PictureInfoKHR_null()
	{
		VkVideoEncodeH265PictureInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH265PictureInfoKHR vkiVideoEncodeH265PictureInfoKHR(uint32_t naluSliceSegmentEntryCount, const VkVideoEncodeH265NaluSliceSegmentInfoKHR *pNaluSliceSegmentEntries, const StdVideoEncodeH265PictureInfo *pStdPictureInfo)
	{
		VkVideoEncodeH265PictureInfoKHR init = vkiVideoEncodeH265PictureInfoKHR_null();
		init.naluSliceSegmentEntryCount = naluSliceSegmentEntryCount;
		init.pNaluSliceSegmentEntries = pNaluSliceSegmentEntries;
		init.pStdPictureInfo = pStdPictureInfo;
		return init;
	}

	static inline VkVideoEncodeH265DpbSlotInfoKHR vkiVideoEncodeH265DpbSlotInfoKHR_null()
	{
		VkVideoEncodeH265DpbSlotInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH265DpbSlotInfoKHR vkiVideoEncodeH265DpbSlotInfoKHR(const StdVideoEncodeH265ReferenceInfo *pStdReferenceInfo)
	{
		VkVideoEncodeH265DpbSlotInfoKHR init = vkiVideoEncodeH265DpbSlotInfoKHR_null();
		init.pStdReferenceInfo = pStdReferenceInfo;
		return init;
	}

	static inline VkVideoEncodeH265ProfileInfoKHR vkiVideoEncodeH265ProfileInfoKHR_null()
	{
		VkVideoEncodeH265ProfileInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH265ProfileInfoKHR vkiVideoEncodeH265ProfileInfoKHR(StdVideoH265ProfileIdc stdProfileIdc)
	{
		VkVideoEncodeH265ProfileInfoKHR init = vkiVideoEncodeH265ProfileInfoKHR_null();
		init.stdProfileIdc = stdProfileIdc;
		return init;
	}

	static inline VkVideoEncodeH265RateControlInfoKHR vkiVideoEncodeH265RateControlInfoKHR_null()
	{
		VkVideoEncodeH265RateControlInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH265RateControlInfoKHR vkiVideoEncodeH265RateControlInfoKHR(uint32_t gopFrameCount, uint32_t idrPeriod, uint32_t consecutiveBFrameCount, uint32_t subLayerCount)
	{
		VkVideoEncodeH265RateControlInfoKHR init = vkiVideoEncodeH265RateControlInfoKHR_null();
		init.gopFrameCount = gopFrameCount;
		init.idrPeriod = idrPeriod;
		init.consecutiveBFrameCount = consecutiveBFrameCount;
		init.subLayerCount = subLayerCount;
		return init;
	}

	static inline VkVideoEncodeH265FrameSizeKHR vkiVideoEncodeH265FrameSizeKHR_null()
	{
		VkVideoEncodeH265FrameSizeKHR init = {0};
		return init;
	}

	static inline VkVideoEncodeH265FrameSizeKHR vkiVideoEncodeH265FrameSizeKHR(uint32_t frameISize, uint32_t framePSize, uint32_t frameBSize)
	{
		VkVideoEncodeH265FrameSizeKHR init = vkiVideoEncodeH265FrameSizeKHR_null();
		init.frameISize = frameISize;
		init.framePSize = framePSize;
		init.frameBSize = frameBSize;
		return init;
	}

	static inline VkVideoEncodeH265RateControlLayerInfoKHR vkiVideoEncodeH265RateControlLayerInfoKHR_null()
	{
		VkVideoEncodeH265RateControlLayerInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH265RateControlLayerInfoKHR vkiVideoEncodeH265RateControlLayerInfoKHR(VkBool32 useMinQp, VkVideoEncodeH265QpKHR minQp, VkBool32 useMaxQp, VkVideoEncodeH265QpKHR maxQp, VkBool32 useMaxFrameSize, VkVideoEncodeH265FrameSizeKHR maxFrameSize)
	{
		VkVideoEncodeH265RateControlLayerInfoKHR init = vkiVideoEncodeH265RateControlLayerInfoKHR_null();
		init.useMinQp = useMinQp;
		init.minQp = minQp;
		init.useMaxQp = useMaxQp;
		init.maxQp = maxQp;
		init.useMaxFrameSize = useMaxFrameSize;
		init.maxFrameSize = maxFrameSize;
		return init;
	}

	static inline VkVideoEncodeH265GopRemainingFrameInfoKHR vkiVideoEncodeH265GopRemainingFrameInfoKHR_null()
	{
		VkVideoEncodeH265GopRemainingFrameInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeH265GopRemainingFrameInfoKHR vkiVideoEncodeH265GopRemainingFrameInfoKHR(VkBool32 useGopRemainingFrames, uint32_t gopRemainingI, uint32_t gopRemainingP, uint32_t gopRemainingB)
	{
		VkVideoEncodeH265GopRemainingFrameInfoKHR init = vkiVideoEncodeH265GopRemainingFrameInfoKHR_null();
		init.useGopRemainingFrames = useGopRemainingFrames;
		init.gopRemainingI = gopRemainingI;
		init.gopRemainingP = gopRemainingP;
		init.gopRemainingB = gopRemainingB;
		return init;
	}

	static inline VkVideoDecodeH264ProfileInfoKHR vkiVideoDecodeH264ProfileInfoKHR_null()
	{
		VkVideoDecodeH264ProfileInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeH264ProfileInfoKHR vkiVideoDecodeH264ProfileInfoKHR(StdVideoH264ProfileIdc stdProfileIdc, VkVideoDecodeH264PictureLayoutFlagBitsKHR pictureLayout)
	{
		VkVideoDecodeH264ProfileInfoKHR init = vkiVideoDecodeH264ProfileInfoKHR_null();
		init.stdProfileIdc = stdProfileIdc;
		init.pictureLayout = pictureLayout;
		return init;
	}

	static inline VkVideoDecodeH264CapabilitiesKHR vkiVideoDecodeH264CapabilitiesKHR_null()
	{
		VkVideoDecodeH264CapabilitiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR;
		return init;
	}

	static inline VkVideoDecodeH264CapabilitiesKHR vkiVideoDecodeH264CapabilitiesKHR(StdVideoH264LevelIdc maxLevelIdc, VkOffset2D fieldOffsetGranularity)
	{
		VkVideoDecodeH264CapabilitiesKHR init = vkiVideoDecodeH264CapabilitiesKHR_null();
		init.maxLevelIdc = maxLevelIdc;
		init.fieldOffsetGranularity = fieldOffsetGranularity;
		return init;
	}

	static inline VkVideoDecodeH264SessionParametersAddInfoKHR vkiVideoDecodeH264SessionParametersAddInfoKHR_null()
	{
		VkVideoDecodeH264SessionParametersAddInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeH264SessionParametersAddInfoKHR vkiVideoDecodeH264SessionParametersAddInfoKHR(uint32_t stdSPSCount, const StdVideoH264SequenceParameterSet *pStdSPSs, uint32_t stdPPSCount, const StdVideoH264PictureParameterSet *pStdPPSs)
	{
		VkVideoDecodeH264SessionParametersAddInfoKHR init = vkiVideoDecodeH264SessionParametersAddInfoKHR_null();
		init.stdSPSCount = stdSPSCount;
		init.pStdSPSs = pStdSPSs;
		init.stdPPSCount = stdPPSCount;
		init.pStdPPSs = pStdPPSs;
		return init;
	}

	static inline VkVideoDecodeH264SessionParametersCreateInfoKHR vkiVideoDecodeH264SessionParametersCreateInfoKHR_null()
	{
		VkVideoDecodeH264SessionParametersCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeH264SessionParametersCreateInfoKHR vkiVideoDecodeH264SessionParametersCreateInfoKHR(uint32_t maxStdSPSCount, uint32_t maxStdPPSCount, const VkVideoDecodeH264SessionParametersAddInfoKHR *pParametersAddInfo)
	{
		VkVideoDecodeH264SessionParametersCreateInfoKHR init = vkiVideoDecodeH264SessionParametersCreateInfoKHR_null();
		init.maxStdSPSCount = maxStdSPSCount;
		init.maxStdPPSCount = maxStdPPSCount;
		init.pParametersAddInfo = pParametersAddInfo;
		return init;
	}

	static inline VkVideoDecodeH264PictureInfoKHR vkiVideoDecodeH264PictureInfoKHR_null()
	{
		VkVideoDecodeH264PictureInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeH264PictureInfoKHR vkiVideoDecodeH264PictureInfoKHR(const StdVideoDecodeH264PictureInfo *pStdPictureInfo, uint32_t sliceCount, const uint32_t *pSliceOffsets)
	{
		VkVideoDecodeH264PictureInfoKHR init = vkiVideoDecodeH264PictureInfoKHR_null();
		init.pStdPictureInfo = pStdPictureInfo;
		init.sliceCount = sliceCount;
		init.pSliceOffsets = pSliceOffsets;
		return init;
	}

	static inline VkVideoDecodeH264DpbSlotInfoKHR vkiVideoDecodeH264DpbSlotInfoKHR_null()
	{
		VkVideoDecodeH264DpbSlotInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeH264DpbSlotInfoKHR vkiVideoDecodeH264DpbSlotInfoKHR(const StdVideoDecodeH264ReferenceInfo *pStdReferenceInfo)
	{
		VkVideoDecodeH264DpbSlotInfoKHR init = vkiVideoDecodeH264DpbSlotInfoKHR_null();
		init.pStdReferenceInfo = pStdReferenceInfo;
		return init;
	}

	static inline VkRenderingFragmentShadingRateAttachmentInfoKHR vkiRenderingFragmentShadingRateAttachmentInfoKHR_null()
	{
		VkRenderingFragmentShadingRateAttachmentInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR;
		return init;
	}

	static inline VkRenderingFragmentShadingRateAttachmentInfoKHR vkiRenderingFragmentShadingRateAttachmentInfoKHR(VkImageView imageView, VkImageLayout imageLayout, VkExtent2D shadingRateAttachmentTexelSize)
	{
		VkRenderingFragmentShadingRateAttachmentInfoKHR init = vkiRenderingFragmentShadingRateAttachmentInfoKHR_null();
		init.imageView = imageView;
		init.imageLayout = imageLayout;
		init.shadingRateAttachmentTexelSize = shadingRateAttachmentTexelSize;
		return init;
	}

	static inline VkRenderingFragmentDensityMapAttachmentInfoEXT vkiRenderingFragmentDensityMapAttachmentInfoEXT_null()
	{
		VkRenderingFragmentDensityMapAttachmentInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT;
		return init;
	}

	static inline VkRenderingFragmentDensityMapAttachmentInfoEXT vkiRenderingFragmentDensityMapAttachmentInfoEXT(VkImageView imageView, VkImageLayout imageLayout)
	{
		VkRenderingFragmentDensityMapAttachmentInfoEXT init = vkiRenderingFragmentDensityMapAttachmentInfoEXT_null();
		init.imageView = imageView;
		init.imageLayout = imageLayout;
		return init;
	}

	static inline VkAttachmentSampleCountInfoAMD vkiAttachmentSampleCountInfoAMD_null()
	{
		VkAttachmentSampleCountInfoAMD init = {0};
		init.sType = VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD;
		return init;
	}

	static inline VkAttachmentSampleCountInfoAMD vkiAttachmentSampleCountInfoAMD(uint32_t colorAttachmentCount, const VkSampleCountFlagBits *pColorAttachmentSamples, VkSampleCountFlagBits depthStencilAttachmentSamples)
	{
		VkAttachmentSampleCountInfoAMD init = vkiAttachmentSampleCountInfoAMD_null();
		init.colorAttachmentCount = colorAttachmentCount;
		init.pColorAttachmentSamples = pColorAttachmentSamples;
		init.depthStencilAttachmentSamples = depthStencilAttachmentSamples;
		return init;
	}

	static inline VkMultiviewPerViewAttributesInfoNVX vkiMultiviewPerViewAttributesInfoNVX_null()
	{
		VkMultiviewPerViewAttributesInfoNVX init = {0};
		init.sType = VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX;
		return init;
	}

	static inline VkMultiviewPerViewAttributesInfoNVX vkiMultiviewPerViewAttributesInfoNVX(VkBool32 perViewAttributes, VkBool32 perViewAttributesPositionXOnly)
	{
		VkMultiviewPerViewAttributesInfoNVX init = vkiMultiviewPerViewAttributesInfoNVX_null();
		init.perViewAttributes = perViewAttributes;
		init.perViewAttributesPositionXOnly = perViewAttributesPositionXOnly;
		return init;
	}

	static inline VkImportMemoryFdInfoKHR vkiImportMemoryFdInfoKHR_null()
	{
		VkImportMemoryFdInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR;
		return init;
	}

	static inline VkImportMemoryFdInfoKHR vkiImportMemoryFdInfoKHR(VkExternalMemoryHandleTypeFlagBits handleType, int fd)
	{
		VkImportMemoryFdInfoKHR init = vkiImportMemoryFdInfoKHR_null();
		init.handleType = handleType;
		init.fd = fd;
		return init;
	}

	static inline VkMemoryFdPropertiesKHR vkiMemoryFdPropertiesKHR_null()
	{
		VkMemoryFdPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR;
		return init;
	}

	static inline VkMemoryFdPropertiesKHR vkiMemoryFdPropertiesKHR(uint32_t memoryTypeBits)
	{
		VkMemoryFdPropertiesKHR init = vkiMemoryFdPropertiesKHR_null();
		init.memoryTypeBits = memoryTypeBits;
		return init;
	}

	static inline VkMemoryGetFdInfoKHR vkiMemoryGetFdInfoKHR_null()
	{
		VkMemoryGetFdInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR;
		return init;
	}

	static inline VkMemoryGetFdInfoKHR vkiMemoryGetFdInfoKHR(VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagBits handleType)
	{
		VkMemoryGetFdInfoKHR init = vkiMemoryGetFdInfoKHR_null();
		init.memory = memory;
		init.handleType = handleType;
		return init;
	}

	static inline VkImportSemaphoreFdInfoKHR vkiImportSemaphoreFdInfoKHR_null()
	{
		VkImportSemaphoreFdInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR;
		return init;
	}

	static inline VkImportSemaphoreFdInfoKHR vkiImportSemaphoreFdInfoKHR(VkSemaphore semaphore, VkExternalSemaphoreHandleTypeFlagBits handleType, int fd)
	{
		VkImportSemaphoreFdInfoKHR init = vkiImportSemaphoreFdInfoKHR_null();
		init.semaphore = semaphore;
		init.handleType = handleType;
		init.fd = fd;
		return init;
	}

	static inline VkSemaphoreGetFdInfoKHR vkiSemaphoreGetFdInfoKHR_null()
	{
		VkSemaphoreGetFdInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR;
		return init;
	}

	static inline VkSemaphoreGetFdInfoKHR vkiSemaphoreGetFdInfoKHR(VkSemaphore semaphore, VkExternalSemaphoreHandleTypeFlagBits handleType)
	{
		VkSemaphoreGetFdInfoKHR init = vkiSemaphoreGetFdInfoKHR_null();
		init.semaphore = semaphore;
		init.handleType = handleType;
		return init;
	}

	static inline VkPhysicalDevicePushDescriptorPropertiesKHR vkiPhysicalDevicePushDescriptorPropertiesKHR_null()
	{
		VkPhysicalDevicePushDescriptorPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR;
		return init;
	}

	static inline VkPhysicalDevicePushDescriptorPropertiesKHR vkiPhysicalDevicePushDescriptorPropertiesKHR(uint32_t maxPushDescriptors)
	{
		VkPhysicalDevicePushDescriptorPropertiesKHR init = vkiPhysicalDevicePushDescriptorPropertiesKHR_null();
		init.maxPushDescriptors = maxPushDescriptors;
		return init;
	}

	static inline VkRectLayerKHR vkiRectLayerKHR_null()
	{
		VkRectLayerKHR init = {0};
		return init;
	}

	static inline VkRectLayerKHR vkiRectLayerKHR(VkOffset2D offset, VkExtent2D extent, uint32_t layer)
	{
		VkRectLayerKHR init = vkiRectLayerKHR_null();
		init.offset = offset;
		init.extent = extent;
		init.layer = layer;
		return init;
	}

	static inline VkPresentRegionKHR vkiPresentRegionKHR_null()
	{
		VkPresentRegionKHR init = {0};
		return init;
	}

	static inline VkPresentRegionKHR vkiPresentRegionKHR(uint32_t rectangleCount, const VkRectLayerKHR *pRectangles)
	{
		VkPresentRegionKHR init = vkiPresentRegionKHR_null();
		init.rectangleCount = rectangleCount;
		init.pRectangles = pRectangles;
		return init;
	}

	static inline VkPresentRegionsKHR vkiPresentRegionsKHR_null()
	{
		VkPresentRegionsKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR;
		return init;
	}

	static inline VkPresentRegionsKHR vkiPresentRegionsKHR(uint32_t swapchainCount, const VkPresentRegionKHR *pRegions)
	{
		VkPresentRegionsKHR init = vkiPresentRegionsKHR_null();
		init.swapchainCount = swapchainCount;
		init.pRegions = pRegions;
		return init;
	}

	static inline VkSharedPresentSurfaceCapabilitiesKHR vkiSharedPresentSurfaceCapabilitiesKHR_null()
	{
		VkSharedPresentSurfaceCapabilitiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR;
		return init;
	}

	static inline VkSharedPresentSurfaceCapabilitiesKHR vkiSharedPresentSurfaceCapabilitiesKHR(VkImageUsageFlags sharedPresentSupportedUsageFlags)
	{
		VkSharedPresentSurfaceCapabilitiesKHR init = vkiSharedPresentSurfaceCapabilitiesKHR_null();
		init.sharedPresentSupportedUsageFlags = sharedPresentSupportedUsageFlags;
		return init;
	}

	static inline VkImportFenceFdInfoKHR vkiImportFenceFdInfoKHR_null()
	{
		VkImportFenceFdInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR;
		return init;
	}

	static inline VkImportFenceFdInfoKHR vkiImportFenceFdInfoKHR(VkFence fence, VkExternalFenceHandleTypeFlagBits handleType, int fd)
	{
		VkImportFenceFdInfoKHR init = vkiImportFenceFdInfoKHR_null();
		init.fence = fence;
		init.handleType = handleType;
		init.fd = fd;
		return init;
	}

	static inline VkFenceGetFdInfoKHR vkiFenceGetFdInfoKHR_null()
	{
		VkFenceGetFdInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR;
		return init;
	}

	static inline VkFenceGetFdInfoKHR vkiFenceGetFdInfoKHR(VkFence fence, VkExternalFenceHandleTypeFlagBits handleType)
	{
		VkFenceGetFdInfoKHR init = vkiFenceGetFdInfoKHR_null();
		init.fence = fence;
		init.handleType = handleType;
		return init;
	}

	static inline VkPhysicalDevicePerformanceQueryFeaturesKHR vkiPhysicalDevicePerformanceQueryFeaturesKHR_null()
	{
		VkPhysicalDevicePerformanceQueryFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDevicePerformanceQueryFeaturesKHR vkiPhysicalDevicePerformanceQueryFeaturesKHR(VkBool32 performanceCounterQueryPools, VkBool32 performanceCounterMultipleQueryPools)
	{
		VkPhysicalDevicePerformanceQueryFeaturesKHR init = vkiPhysicalDevicePerformanceQueryFeaturesKHR_null();
		init.performanceCounterQueryPools = performanceCounterQueryPools;
		init.performanceCounterMultipleQueryPools = performanceCounterMultipleQueryPools;
		return init;
	}

	static inline VkPhysicalDevicePerformanceQueryPropertiesKHR vkiPhysicalDevicePerformanceQueryPropertiesKHR_null()
	{
		VkPhysicalDevicePerformanceQueryPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR;
		return init;
	}

	static inline VkPhysicalDevicePerformanceQueryPropertiesKHR vkiPhysicalDevicePerformanceQueryPropertiesKHR(VkBool32 allowCommandBufferQueryCopies)
	{
		VkPhysicalDevicePerformanceQueryPropertiesKHR init = vkiPhysicalDevicePerformanceQueryPropertiesKHR_null();
		init.allowCommandBufferQueryCopies = allowCommandBufferQueryCopies;
		return init;
	}

	static inline VkPerformanceCounterKHR vkiPerformanceCounterKHR_null()
	{
		VkPerformanceCounterKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR;
		return init;
	}

	static inline VkPerformanceCounterKHR vkiPerformanceCounterKHR(VkPerformanceCounterUnitKHR unit, VkPerformanceCounterScopeKHR scope, VkPerformanceCounterStorageKHR storage)
	{
		VkPerformanceCounterKHR init = vkiPerformanceCounterKHR_null();
		init.unit = unit;
		init.scope = scope;
		init.storage = storage;
		return init;
	}

	static inline VkPerformanceCounterDescriptionKHR vkiPerformanceCounterDescriptionKHR_null()
	{
		VkPerformanceCounterDescriptionKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR;
		return init;
	}

	static inline VkPerformanceCounterDescriptionKHR vkiPerformanceCounterDescriptionKHR()
	{
		VkPerformanceCounterDescriptionKHR init = vkiPerformanceCounterDescriptionKHR_null();
		return init;
	}

	static inline VkQueryPoolPerformanceCreateInfoKHR vkiQueryPoolPerformanceCreateInfoKHR_null()
	{
		VkQueryPoolPerformanceCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR;
		return init;
	}

	static inline VkQueryPoolPerformanceCreateInfoKHR vkiQueryPoolPerformanceCreateInfoKHR(uint32_t queueFamilyIndex, uint32_t counterIndexCount, const uint32_t *pCounterIndices)
	{
		VkQueryPoolPerformanceCreateInfoKHR init = vkiQueryPoolPerformanceCreateInfoKHR_null();
		init.queueFamilyIndex = queueFamilyIndex;
		init.counterIndexCount = counterIndexCount;
		init.pCounterIndices = pCounterIndices;
		return init;
	}

	static inline VkAcquireProfilingLockInfoKHR vkiAcquireProfilingLockInfoKHR_null()
	{
		VkAcquireProfilingLockInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR;
		return init;
	}

	static inline VkAcquireProfilingLockInfoKHR vkiAcquireProfilingLockInfoKHR(uint64_t timeout)
	{
		VkAcquireProfilingLockInfoKHR init = vkiAcquireProfilingLockInfoKHR_null();
		init.timeout = timeout;
		return init;
	}

	static inline VkPerformanceQuerySubmitInfoKHR vkiPerformanceQuerySubmitInfoKHR_null()
	{
		VkPerformanceQuerySubmitInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR;
		return init;
	}

	static inline VkPerformanceQuerySubmitInfoKHR vkiPerformanceQuerySubmitInfoKHR(uint32_t counterPassIndex)
	{
		VkPerformanceQuerySubmitInfoKHR init = vkiPerformanceQuerySubmitInfoKHR_null();
		init.counterPassIndex = counterPassIndex;
		return init;
	}

	static inline VkPhysicalDeviceSurfaceInfo2KHR vkiPhysicalDeviceSurfaceInfo2KHR_null()
	{
		VkPhysicalDeviceSurfaceInfo2KHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
		return init;
	}

	static inline VkPhysicalDeviceSurfaceInfo2KHR vkiPhysicalDeviceSurfaceInfo2KHR(VkSurfaceKHR surface)
	{
		VkPhysicalDeviceSurfaceInfo2KHR init = vkiPhysicalDeviceSurfaceInfo2KHR_null();
		init.surface = surface;
		return init;
	}

	static inline VkSurfaceCapabilities2KHR vkiSurfaceCapabilities2KHR_null()
	{
		VkSurfaceCapabilities2KHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR;
		return init;
	}

	static inline VkSurfaceCapabilities2KHR vkiSurfaceCapabilities2KHR(VkSurfaceCapabilitiesKHR surfaceCapabilities)
	{
		VkSurfaceCapabilities2KHR init = vkiSurfaceCapabilities2KHR_null();
		init.surfaceCapabilities = surfaceCapabilities;
		return init;
	}

	static inline VkSurfaceFormat2KHR vkiSurfaceFormat2KHR_null()
	{
		VkSurfaceFormat2KHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR;
		return init;
	}

	static inline VkSurfaceFormat2KHR vkiSurfaceFormat2KHR(VkSurfaceFormatKHR surfaceFormat)
	{
		VkSurfaceFormat2KHR init = vkiSurfaceFormat2KHR_null();
		init.surfaceFormat = surfaceFormat;
		return init;
	}

	static inline VkDisplayProperties2KHR vkiDisplayProperties2KHR_null()
	{
		VkDisplayProperties2KHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR;
		return init;
	}

	static inline VkDisplayProperties2KHR vkiDisplayProperties2KHR(VkDisplayPropertiesKHR displayProperties)
	{
		VkDisplayProperties2KHR init = vkiDisplayProperties2KHR_null();
		init.displayProperties = displayProperties;
		return init;
	}

	static inline VkDisplayPlaneProperties2KHR vkiDisplayPlaneProperties2KHR_null()
	{
		VkDisplayPlaneProperties2KHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR;
		return init;
	}

	static inline VkDisplayPlaneProperties2KHR vkiDisplayPlaneProperties2KHR(VkDisplayPlanePropertiesKHR displayPlaneProperties)
	{
		VkDisplayPlaneProperties2KHR init = vkiDisplayPlaneProperties2KHR_null();
		init.displayPlaneProperties = displayPlaneProperties;
		return init;
	}

	static inline VkDisplayModeProperties2KHR vkiDisplayModeProperties2KHR_null()
	{
		VkDisplayModeProperties2KHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR;
		return init;
	}

	static inline VkDisplayModeProperties2KHR vkiDisplayModeProperties2KHR(VkDisplayModePropertiesKHR displayModeProperties)
	{
		VkDisplayModeProperties2KHR init = vkiDisplayModeProperties2KHR_null();
		init.displayModeProperties = displayModeProperties;
		return init;
	}

	static inline VkDisplayPlaneInfo2KHR vkiDisplayPlaneInfo2KHR_null()
	{
		VkDisplayPlaneInfo2KHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR;
		return init;
	}

	static inline VkDisplayPlaneInfo2KHR vkiDisplayPlaneInfo2KHR(VkDisplayModeKHR mode, uint32_t planeIndex)
	{
		VkDisplayPlaneInfo2KHR init = vkiDisplayPlaneInfo2KHR_null();
		init.mode = mode;
		init.planeIndex = planeIndex;
		return init;
	}

	static inline VkDisplayPlaneCapabilities2KHR vkiDisplayPlaneCapabilities2KHR_null()
	{
		VkDisplayPlaneCapabilities2KHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR;
		return init;
	}

	static inline VkDisplayPlaneCapabilities2KHR vkiDisplayPlaneCapabilities2KHR(VkDisplayPlaneCapabilitiesKHR capabilities)
	{
		VkDisplayPlaneCapabilities2KHR init = vkiDisplayPlaneCapabilities2KHR_null();
		init.capabilities = capabilities;
		return init;
	}

	static inline VkPhysicalDeviceShaderClockFeaturesKHR vkiPhysicalDeviceShaderClockFeaturesKHR_null()
	{
		VkPhysicalDeviceShaderClockFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceShaderClockFeaturesKHR vkiPhysicalDeviceShaderClockFeaturesKHR(VkBool32 shaderSubgroupClock, VkBool32 shaderDeviceClock)
	{
		VkPhysicalDeviceShaderClockFeaturesKHR init = vkiPhysicalDeviceShaderClockFeaturesKHR_null();
		init.shaderSubgroupClock = shaderSubgroupClock;
		init.shaderDeviceClock = shaderDeviceClock;
		return init;
	}

	static inline VkVideoDecodeH265ProfileInfoKHR vkiVideoDecodeH265ProfileInfoKHR_null()
	{
		VkVideoDecodeH265ProfileInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeH265ProfileInfoKHR vkiVideoDecodeH265ProfileInfoKHR(StdVideoH265ProfileIdc stdProfileIdc)
	{
		VkVideoDecodeH265ProfileInfoKHR init = vkiVideoDecodeH265ProfileInfoKHR_null();
		init.stdProfileIdc = stdProfileIdc;
		return init;
	}

	static inline VkVideoDecodeH265CapabilitiesKHR vkiVideoDecodeH265CapabilitiesKHR_null()
	{
		VkVideoDecodeH265CapabilitiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR;
		return init;
	}

	static inline VkVideoDecodeH265CapabilitiesKHR vkiVideoDecodeH265CapabilitiesKHR(StdVideoH265LevelIdc maxLevelIdc)
	{
		VkVideoDecodeH265CapabilitiesKHR init = vkiVideoDecodeH265CapabilitiesKHR_null();
		init.maxLevelIdc = maxLevelIdc;
		return init;
	}

	static inline VkVideoDecodeH265SessionParametersAddInfoKHR vkiVideoDecodeH265SessionParametersAddInfoKHR_null()
	{
		VkVideoDecodeH265SessionParametersAddInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeH265SessionParametersAddInfoKHR vkiVideoDecodeH265SessionParametersAddInfoKHR(uint32_t stdVPSCount, const StdVideoH265VideoParameterSet *pStdVPSs, uint32_t stdSPSCount, const StdVideoH265SequenceParameterSet *pStdSPSs, uint32_t stdPPSCount, const StdVideoH265PictureParameterSet *pStdPPSs)
	{
		VkVideoDecodeH265SessionParametersAddInfoKHR init = vkiVideoDecodeH265SessionParametersAddInfoKHR_null();
		init.stdVPSCount = stdVPSCount;
		init.pStdVPSs = pStdVPSs;
		init.stdSPSCount = stdSPSCount;
		init.pStdSPSs = pStdSPSs;
		init.stdPPSCount = stdPPSCount;
		init.pStdPPSs = pStdPPSs;
		return init;
	}

	static inline VkVideoDecodeH265SessionParametersCreateInfoKHR vkiVideoDecodeH265SessionParametersCreateInfoKHR_null()
	{
		VkVideoDecodeH265SessionParametersCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeH265SessionParametersCreateInfoKHR vkiVideoDecodeH265SessionParametersCreateInfoKHR(uint32_t maxStdVPSCount, uint32_t maxStdSPSCount, uint32_t maxStdPPSCount, const VkVideoDecodeH265SessionParametersAddInfoKHR *pParametersAddInfo)
	{
		VkVideoDecodeH265SessionParametersCreateInfoKHR init = vkiVideoDecodeH265SessionParametersCreateInfoKHR_null();
		init.maxStdVPSCount = maxStdVPSCount;
		init.maxStdSPSCount = maxStdSPSCount;
		init.maxStdPPSCount = maxStdPPSCount;
		init.pParametersAddInfo = pParametersAddInfo;
		return init;
	}

	static inline VkVideoDecodeH265PictureInfoKHR vkiVideoDecodeH265PictureInfoKHR_null()
	{
		VkVideoDecodeH265PictureInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeH265PictureInfoKHR vkiVideoDecodeH265PictureInfoKHR(const StdVideoDecodeH265PictureInfo *pStdPictureInfo, uint32_t sliceSegmentCount, const uint32_t *pSliceSegmentOffsets)
	{
		VkVideoDecodeH265PictureInfoKHR init = vkiVideoDecodeH265PictureInfoKHR_null();
		init.pStdPictureInfo = pStdPictureInfo;
		init.sliceSegmentCount = sliceSegmentCount;
		init.pSliceSegmentOffsets = pSliceSegmentOffsets;
		return init;
	}

	static inline VkVideoDecodeH265DpbSlotInfoKHR vkiVideoDecodeH265DpbSlotInfoKHR_null()
	{
		VkVideoDecodeH265DpbSlotInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeH265DpbSlotInfoKHR vkiVideoDecodeH265DpbSlotInfoKHR(const StdVideoDecodeH265ReferenceInfo *pStdReferenceInfo)
	{
		VkVideoDecodeH265DpbSlotInfoKHR init = vkiVideoDecodeH265DpbSlotInfoKHR_null();
		init.pStdReferenceInfo = pStdReferenceInfo;
		return init;
	}

	static inline VkDeviceQueueGlobalPriorityCreateInfoKHR vkiDeviceQueueGlobalPriorityCreateInfoKHR_null()
	{
		VkDeviceQueueGlobalPriorityCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR;
		return init;
	}

	static inline VkDeviceQueueGlobalPriorityCreateInfoKHR vkiDeviceQueueGlobalPriorityCreateInfoKHR(VkQueueGlobalPriorityKHR globalPriority)
	{
		VkDeviceQueueGlobalPriorityCreateInfoKHR init = vkiDeviceQueueGlobalPriorityCreateInfoKHR_null();
		init.globalPriority = globalPriority;
		return init;
	}

	static inline VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR vkiPhysicalDeviceGlobalPriorityQueryFeaturesKHR_null()
	{
		VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR vkiPhysicalDeviceGlobalPriorityQueryFeaturesKHR(VkBool32 globalPriorityQuery)
	{
		VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR init = vkiPhysicalDeviceGlobalPriorityQueryFeaturesKHR_null();
		init.globalPriorityQuery = globalPriorityQuery;
		return init;
	}

	static inline VkQueueFamilyGlobalPriorityPropertiesKHR vkiQueueFamilyGlobalPriorityPropertiesKHR_null()
	{
		VkQueueFamilyGlobalPriorityPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR;
		return init;
	}

	static inline VkQueueFamilyGlobalPriorityPropertiesKHR vkiQueueFamilyGlobalPriorityPropertiesKHR(uint32_t priorityCount)
	{
		VkQueueFamilyGlobalPriorityPropertiesKHR init = vkiQueueFamilyGlobalPriorityPropertiesKHR_null();
		init.priorityCount = priorityCount;
		return init;
	}

	static inline VkFragmentShadingRateAttachmentInfoKHR vkiFragmentShadingRateAttachmentInfoKHR_null()
	{
		VkFragmentShadingRateAttachmentInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR;
		return init;
	}

	static inline VkFragmentShadingRateAttachmentInfoKHR vkiFragmentShadingRateAttachmentInfoKHR(const VkAttachmentReference2 *pFragmentShadingRateAttachment, VkExtent2D shadingRateAttachmentTexelSize)
	{
		VkFragmentShadingRateAttachmentInfoKHR init = vkiFragmentShadingRateAttachmentInfoKHR_null();
		init.pFragmentShadingRateAttachment = pFragmentShadingRateAttachment;
		init.shadingRateAttachmentTexelSize = shadingRateAttachmentTexelSize;
		return init;
	}

	static inline VkPipelineFragmentShadingRateStateCreateInfoKHR vkiPipelineFragmentShadingRateStateCreateInfoKHR_null()
	{
		VkPipelineFragmentShadingRateStateCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR;
		return init;
	}

	static inline VkPipelineFragmentShadingRateStateCreateInfoKHR vkiPipelineFragmentShadingRateStateCreateInfoKHR(VkExtent2D fragmentSize)
	{
		VkPipelineFragmentShadingRateStateCreateInfoKHR init = vkiPipelineFragmentShadingRateStateCreateInfoKHR_null();
		init.fragmentSize = fragmentSize;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShadingRateFeaturesKHR vkiPhysicalDeviceFragmentShadingRateFeaturesKHR_null()
	{
		VkPhysicalDeviceFragmentShadingRateFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShadingRateFeaturesKHR vkiPhysicalDeviceFragmentShadingRateFeaturesKHR(VkBool32 pipelineFragmentShadingRate, VkBool32 primitiveFragmentShadingRate, VkBool32 attachmentFragmentShadingRate)
	{
		VkPhysicalDeviceFragmentShadingRateFeaturesKHR init = vkiPhysicalDeviceFragmentShadingRateFeaturesKHR_null();
		init.pipelineFragmentShadingRate = pipelineFragmentShadingRate;
		init.primitiveFragmentShadingRate = primitiveFragmentShadingRate;
		init.attachmentFragmentShadingRate = attachmentFragmentShadingRate;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShadingRatePropertiesKHR vkiPhysicalDeviceFragmentShadingRatePropertiesKHR_null()
	{
		VkPhysicalDeviceFragmentShadingRatePropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShadingRatePropertiesKHR vkiPhysicalDeviceFragmentShadingRatePropertiesKHR(VkExtent2D minFragmentShadingRateAttachmentTexelSize, VkExtent2D maxFragmentShadingRateAttachmentTexelSize, uint32_t maxFragmentShadingRateAttachmentTexelSizeAspectRatio, VkBool32 primitiveFragmentShadingRateWithMultipleViewports, VkBool32 layeredShadingRateAttachments, VkBool32 fragmentShadingRateNonTrivialCombinerOps, VkExtent2D maxFragmentSize, uint32_t maxFragmentSizeAspectRatio, uint32_t maxFragmentShadingRateCoverageSamples, VkSampleCountFlagBits maxFragmentShadingRateRasterizationSamples, VkBool32 fragmentShadingRateWithShaderDepthStencilWrites, VkBool32 fragmentShadingRateWithSampleMask, VkBool32 fragmentShadingRateWithShaderSampleMask, VkBool32 fragmentShadingRateWithConservativeRasterization, VkBool32 fragmentShadingRateWithFragmentShaderInterlock, VkBool32 fragmentShadingRateWithCustomSampleLocations, VkBool32 fragmentShadingRateStrictMultiplyCombiner)
	{
		VkPhysicalDeviceFragmentShadingRatePropertiesKHR init = vkiPhysicalDeviceFragmentShadingRatePropertiesKHR_null();
		init.minFragmentShadingRateAttachmentTexelSize = minFragmentShadingRateAttachmentTexelSize;
		init.maxFragmentShadingRateAttachmentTexelSize = maxFragmentShadingRateAttachmentTexelSize;
		init.maxFragmentShadingRateAttachmentTexelSizeAspectRatio = maxFragmentShadingRateAttachmentTexelSizeAspectRatio;
		init.primitiveFragmentShadingRateWithMultipleViewports = primitiveFragmentShadingRateWithMultipleViewports;
		init.layeredShadingRateAttachments = layeredShadingRateAttachments;
		init.fragmentShadingRateNonTrivialCombinerOps = fragmentShadingRateNonTrivialCombinerOps;
		init.maxFragmentSize = maxFragmentSize;
		init.maxFragmentSizeAspectRatio = maxFragmentSizeAspectRatio;
		init.maxFragmentShadingRateCoverageSamples = maxFragmentShadingRateCoverageSamples;
		init.maxFragmentShadingRateRasterizationSamples = maxFragmentShadingRateRasterizationSamples;
		init.fragmentShadingRateWithShaderDepthStencilWrites = fragmentShadingRateWithShaderDepthStencilWrites;
		init.fragmentShadingRateWithSampleMask = fragmentShadingRateWithSampleMask;
		init.fragmentShadingRateWithShaderSampleMask = fragmentShadingRateWithShaderSampleMask;
		init.fragmentShadingRateWithConservativeRasterization = fragmentShadingRateWithConservativeRasterization;
		init.fragmentShadingRateWithFragmentShaderInterlock = fragmentShadingRateWithFragmentShaderInterlock;
		init.fragmentShadingRateWithCustomSampleLocations = fragmentShadingRateWithCustomSampleLocations;
		init.fragmentShadingRateStrictMultiplyCombiner = fragmentShadingRateStrictMultiplyCombiner;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShadingRateKHR vkiPhysicalDeviceFragmentShadingRateKHR_null()
	{
		VkPhysicalDeviceFragmentShadingRateKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShadingRateKHR vkiPhysicalDeviceFragmentShadingRateKHR(VkSampleCountFlags sampleCounts, VkExtent2D fragmentSize)
	{
		VkPhysicalDeviceFragmentShadingRateKHR init = vkiPhysicalDeviceFragmentShadingRateKHR_null();
		init.sampleCounts = sampleCounts;
		init.fragmentSize = fragmentSize;
		return init;
	}

	static inline VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR vkiPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR_null()
	{
		VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR vkiPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR(VkBool32 dynamicRenderingLocalRead)
	{
		VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR init = vkiPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR_null();
		init.dynamicRenderingLocalRead = dynamicRenderingLocalRead;
		return init;
	}

	static inline VkRenderingAttachmentLocationInfoKHR vkiRenderingAttachmentLocationInfoKHR_null()
	{
		VkRenderingAttachmentLocationInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO_KHR;
		return init;
	}

	static inline VkRenderingAttachmentLocationInfoKHR vkiRenderingAttachmentLocationInfoKHR(uint32_t colorAttachmentCount, const uint32_t *pColorAttachmentLocations)
	{
		VkRenderingAttachmentLocationInfoKHR init = vkiRenderingAttachmentLocationInfoKHR_null();
		init.colorAttachmentCount = colorAttachmentCount;
		init.pColorAttachmentLocations = pColorAttachmentLocations;
		return init;
	}

	static inline VkRenderingInputAttachmentIndexInfoKHR vkiRenderingInputAttachmentIndexInfoKHR_null()
	{
		VkRenderingInputAttachmentIndexInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO_KHR;
		return init;
	}

	static inline VkRenderingInputAttachmentIndexInfoKHR vkiRenderingInputAttachmentIndexInfoKHR(uint32_t colorAttachmentCount, const uint32_t *pColorAttachmentInputIndices, const uint32_t *pDepthInputAttachmentIndex, const uint32_t *pStencilInputAttachmentIndex)
	{
		VkRenderingInputAttachmentIndexInfoKHR init = vkiRenderingInputAttachmentIndexInfoKHR_null();
		init.colorAttachmentCount = colorAttachmentCount;
		init.pColorAttachmentInputIndices = pColorAttachmentInputIndices;
		init.pDepthInputAttachmentIndex = pDepthInputAttachmentIndex;
		init.pStencilInputAttachmentIndex = pStencilInputAttachmentIndex;
		return init;
	}

	static inline VkPhysicalDeviceShaderQuadControlFeaturesKHR vkiPhysicalDeviceShaderQuadControlFeaturesKHR_null()
	{
		VkPhysicalDeviceShaderQuadControlFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceShaderQuadControlFeaturesKHR vkiPhysicalDeviceShaderQuadControlFeaturesKHR(VkBool32 shaderQuadControl)
	{
		VkPhysicalDeviceShaderQuadControlFeaturesKHR init = vkiPhysicalDeviceShaderQuadControlFeaturesKHR_null();
		init.shaderQuadControl = shaderQuadControl;
		return init;
	}

	static inline VkSurfaceProtectedCapabilitiesKHR vkiSurfaceProtectedCapabilitiesKHR_null()
	{
		VkSurfaceProtectedCapabilitiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR;
		return init;
	}

	static inline VkSurfaceProtectedCapabilitiesKHR vkiSurfaceProtectedCapabilitiesKHR(VkBool32 supportsProtected)
	{
		VkSurfaceProtectedCapabilitiesKHR init = vkiSurfaceProtectedCapabilitiesKHR_null();
		init.supportsProtected = supportsProtected;
		return init;
	}

	static inline VkPhysicalDevicePresentWaitFeaturesKHR vkiPhysicalDevicePresentWaitFeaturesKHR_null()
	{
		VkPhysicalDevicePresentWaitFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDevicePresentWaitFeaturesKHR vkiPhysicalDevicePresentWaitFeaturesKHR(VkBool32 presentWait)
	{
		VkPhysicalDevicePresentWaitFeaturesKHR init = vkiPhysicalDevicePresentWaitFeaturesKHR_null();
		init.presentWait = presentWait;
		return init;
	}

	static inline VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR vkiPhysicalDevicePipelineExecutablePropertiesFeaturesKHR_null()
	{
		VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR vkiPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(VkBool32 pipelineExecutableInfo)
	{
		VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR init = vkiPhysicalDevicePipelineExecutablePropertiesFeaturesKHR_null();
		init.pipelineExecutableInfo = pipelineExecutableInfo;
		return init;
	}

	static inline VkPipelineInfoKHR vkiPipelineInfoKHR_null()
	{
		VkPipelineInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR;
		return init;
	}

	static inline VkPipelineInfoKHR vkiPipelineInfoKHR(VkPipeline pipeline)
	{
		VkPipelineInfoKHR init = vkiPipelineInfoKHR_null();
		init.pipeline = pipeline;
		return init;
	}

	static inline VkPipelineExecutablePropertiesKHR vkiPipelineExecutablePropertiesKHR_null()
	{
		VkPipelineExecutablePropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR;
		return init;
	}

	static inline VkPipelineExecutablePropertiesKHR vkiPipelineExecutablePropertiesKHR(VkShaderStageFlags stages, uint32_t subgroupSize)
	{
		VkPipelineExecutablePropertiesKHR init = vkiPipelineExecutablePropertiesKHR_null();
		init.stages = stages;
		init.subgroupSize = subgroupSize;
		return init;
	}

	static inline VkPipelineExecutableInfoKHR vkiPipelineExecutableInfoKHR_null()
	{
		VkPipelineExecutableInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR;
		return init;
	}

	static inline VkPipelineExecutableInfoKHR vkiPipelineExecutableInfoKHR(VkPipeline pipeline, uint32_t executableIndex)
	{
		VkPipelineExecutableInfoKHR init = vkiPipelineExecutableInfoKHR_null();
		init.pipeline = pipeline;
		init.executableIndex = executableIndex;
		return init;
	}

	static inline VkPipelineExecutableStatisticKHR vkiPipelineExecutableStatisticKHR_null()
	{
		VkPipelineExecutableStatisticKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR;
		return init;
	}

	static inline VkPipelineExecutableStatisticKHR vkiPipelineExecutableStatisticKHR(VkPipelineExecutableStatisticFormatKHR format, VkPipelineExecutableStatisticValueKHR value)
	{
		VkPipelineExecutableStatisticKHR init = vkiPipelineExecutableStatisticKHR_null();
		init.format = format;
		init.value = value;
		return init;
	}

	static inline VkPipelineExecutableInternalRepresentationKHR vkiPipelineExecutableInternalRepresentationKHR_null()
	{
		VkPipelineExecutableInternalRepresentationKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR;
		return init;
	}

	static inline VkPipelineExecutableInternalRepresentationKHR vkiPipelineExecutableInternalRepresentationKHR(VkBool32 isText, size_t dataSize, void *pData)
	{
		VkPipelineExecutableInternalRepresentationKHR init = vkiPipelineExecutableInternalRepresentationKHR_null();
		init.isText = isText;
		init.dataSize = dataSize;
		init.pData = pData;
		return init;
	}

	static inline VkMemoryMapInfoKHR vkiMemoryMapInfoKHR_null()
	{
		VkMemoryMapInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_MAP_INFO_KHR;
		return init;
	}

	static inline VkMemoryMapInfoKHR vkiMemoryMapInfoKHR(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size)
	{
		VkMemoryMapInfoKHR init = vkiMemoryMapInfoKHR_null();
		init.memory = memory;
		init.offset = offset;
		init.size = size;
		return init;
	}

	static inline VkMemoryUnmapInfoKHR vkiMemoryUnmapInfoKHR_null()
	{
		VkMemoryUnmapInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO_KHR;
		return init;
	}

	static inline VkMemoryUnmapInfoKHR vkiMemoryUnmapInfoKHR(VkDeviceMemory memory)
	{
		VkMemoryUnmapInfoKHR init = vkiMemoryUnmapInfoKHR_null();
		init.memory = memory;
		return init;
	}

	static inline VkPipelineLibraryCreateInfoKHR vkiPipelineLibraryCreateInfoKHR_null()
	{
		VkPipelineLibraryCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR;
		return init;
	}

	static inline VkPipelineLibraryCreateInfoKHR vkiPipelineLibraryCreateInfoKHR(uint32_t libraryCount, const VkPipeline *pLibraries)
	{
		VkPipelineLibraryCreateInfoKHR init = vkiPipelineLibraryCreateInfoKHR_null();
		init.libraryCount = libraryCount;
		init.pLibraries = pLibraries;
		return init;
	}

	static inline VkPresentIdKHR vkiPresentIdKHR_null()
	{
		VkPresentIdKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PRESENT_ID_KHR;
		return init;
	}

	static inline VkPresentIdKHR vkiPresentIdKHR(uint32_t swapchainCount, const uint64_t *pPresentIds)
	{
		VkPresentIdKHR init = vkiPresentIdKHR_null();
		init.swapchainCount = swapchainCount;
		init.pPresentIds = pPresentIds;
		return init;
	}

	static inline VkPhysicalDevicePresentIdFeaturesKHR vkiPhysicalDevicePresentIdFeaturesKHR_null()
	{
		VkPhysicalDevicePresentIdFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDevicePresentIdFeaturesKHR vkiPhysicalDevicePresentIdFeaturesKHR(VkBool32 presentId)
	{
		VkPhysicalDevicePresentIdFeaturesKHR init = vkiPhysicalDevicePresentIdFeaturesKHR_null();
		init.presentId = presentId;
		return init;
	}

	static inline VkVideoEncodeInfoKHR vkiVideoEncodeInfoKHR_null()
	{
		VkVideoEncodeInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeInfoKHR vkiVideoEncodeInfoKHR(VkBuffer dstBuffer, VkDeviceSize dstBufferOffset, VkDeviceSize dstBufferRange, VkVideoPictureResourceInfoKHR srcPictureResource, const VkVideoReferenceSlotInfoKHR *pSetupReferenceSlot, uint32_t referenceSlotCount, const VkVideoReferenceSlotInfoKHR *pReferenceSlots, uint32_t precedingExternallyEncodedBytes)
	{
		VkVideoEncodeInfoKHR init = vkiVideoEncodeInfoKHR_null();
		init.dstBuffer = dstBuffer;
		init.dstBufferOffset = dstBufferOffset;
		init.dstBufferRange = dstBufferRange;
		init.srcPictureResource = srcPictureResource;
		init.pSetupReferenceSlot = pSetupReferenceSlot;
		init.referenceSlotCount = referenceSlotCount;
		init.pReferenceSlots = pReferenceSlots;
		init.precedingExternallyEncodedBytes = precedingExternallyEncodedBytes;
		return init;
	}

	static inline VkVideoEncodeCapabilitiesKHR vkiVideoEncodeCapabilitiesKHR_null()
	{
		VkVideoEncodeCapabilitiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR;
		return init;
	}

	static inline VkVideoEncodeCapabilitiesKHR vkiVideoEncodeCapabilitiesKHR(VkVideoEncodeRateControlModeFlagsKHR rateControlModes, uint32_t maxRateControlLayers, uint64_t maxBitrate, uint32_t maxQualityLevels, VkExtent2D encodeInputPictureGranularity, VkVideoEncodeFeedbackFlagsKHR supportedEncodeFeedbackFlags)
	{
		VkVideoEncodeCapabilitiesKHR init = vkiVideoEncodeCapabilitiesKHR_null();
		init.rateControlModes = rateControlModes;
		init.maxRateControlLayers = maxRateControlLayers;
		init.maxBitrate = maxBitrate;
		init.maxQualityLevels = maxQualityLevels;
		init.encodeInputPictureGranularity = encodeInputPictureGranularity;
		init.supportedEncodeFeedbackFlags = supportedEncodeFeedbackFlags;
		return init;
	}

	static inline VkQueryPoolVideoEncodeFeedbackCreateInfoKHR vkiQueryPoolVideoEncodeFeedbackCreateInfoKHR_null()
	{
		VkQueryPoolVideoEncodeFeedbackCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR;
		return init;
	}

	static inline VkQueryPoolVideoEncodeFeedbackCreateInfoKHR vkiQueryPoolVideoEncodeFeedbackCreateInfoKHR(VkVideoEncodeFeedbackFlagsKHR encodeFeedbackFlags)
	{
		VkQueryPoolVideoEncodeFeedbackCreateInfoKHR init = vkiQueryPoolVideoEncodeFeedbackCreateInfoKHR_null();
		init.encodeFeedbackFlags = encodeFeedbackFlags;
		return init;
	}

	static inline VkVideoEncodeUsageInfoKHR vkiVideoEncodeUsageInfoKHR_null()
	{
		VkVideoEncodeUsageInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeUsageInfoKHR vkiVideoEncodeUsageInfoKHR(VkVideoEncodeUsageFlagsKHR videoUsageHints, VkVideoEncodeContentFlagsKHR videoContentHints, VkVideoEncodeTuningModeKHR tuningMode)
	{
		VkVideoEncodeUsageInfoKHR init = vkiVideoEncodeUsageInfoKHR_null();
		init.videoUsageHints = videoUsageHints;
		init.videoContentHints = videoContentHints;
		init.tuningMode = tuningMode;
		return init;
	}

	static inline VkVideoEncodeRateControlLayerInfoKHR vkiVideoEncodeRateControlLayerInfoKHR_null()
	{
		VkVideoEncodeRateControlLayerInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeRateControlLayerInfoKHR vkiVideoEncodeRateControlLayerInfoKHR(uint64_t averageBitrate, uint64_t maxBitrate, uint32_t frameRateNumerator, uint32_t frameRateDenominator)
	{
		VkVideoEncodeRateControlLayerInfoKHR init = vkiVideoEncodeRateControlLayerInfoKHR_null();
		init.averageBitrate = averageBitrate;
		init.maxBitrate = maxBitrate;
		init.frameRateNumerator = frameRateNumerator;
		init.frameRateDenominator = frameRateDenominator;
		return init;
	}

	static inline VkVideoEncodeRateControlInfoKHR vkiVideoEncodeRateControlInfoKHR_null()
	{
		VkVideoEncodeRateControlInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeRateControlInfoKHR vkiVideoEncodeRateControlInfoKHR(VkVideoEncodeRateControlModeFlagBitsKHR rateControlMode, uint32_t layerCount, const VkVideoEncodeRateControlLayerInfoKHR *pLayers, uint32_t virtualBufferSizeInMs, uint32_t initialVirtualBufferSizeInMs)
	{
		VkVideoEncodeRateControlInfoKHR init = vkiVideoEncodeRateControlInfoKHR_null();
		init.rateControlMode = rateControlMode;
		init.layerCount = layerCount;
		init.pLayers = pLayers;
		init.virtualBufferSizeInMs = virtualBufferSizeInMs;
		init.initialVirtualBufferSizeInMs = initialVirtualBufferSizeInMs;
		return init;
	}

	static inline VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR vkiPhysicalDeviceVideoEncodeQualityLevelInfoKHR_null()
	{
		VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR;
		return init;
	}

	static inline VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR vkiPhysicalDeviceVideoEncodeQualityLevelInfoKHR(const VkVideoProfileInfoKHR *pVideoProfile, uint32_t qualityLevel)
	{
		VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR init = vkiPhysicalDeviceVideoEncodeQualityLevelInfoKHR_null();
		init.pVideoProfile = pVideoProfile;
		init.qualityLevel = qualityLevel;
		return init;
	}

	static inline VkVideoEncodeQualityLevelPropertiesKHR vkiVideoEncodeQualityLevelPropertiesKHR_null()
	{
		VkVideoEncodeQualityLevelPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR;
		return init;
	}

	static inline VkVideoEncodeQualityLevelPropertiesKHR vkiVideoEncodeQualityLevelPropertiesKHR(VkVideoEncodeRateControlModeFlagBitsKHR preferredRateControlMode, uint32_t preferredRateControlLayerCount)
	{
		VkVideoEncodeQualityLevelPropertiesKHR init = vkiVideoEncodeQualityLevelPropertiesKHR_null();
		init.preferredRateControlMode = preferredRateControlMode;
		init.preferredRateControlLayerCount = preferredRateControlLayerCount;
		return init;
	}

	static inline VkVideoEncodeQualityLevelInfoKHR vkiVideoEncodeQualityLevelInfoKHR_null()
	{
		VkVideoEncodeQualityLevelInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeQualityLevelInfoKHR vkiVideoEncodeQualityLevelInfoKHR(uint32_t qualityLevel)
	{
		VkVideoEncodeQualityLevelInfoKHR init = vkiVideoEncodeQualityLevelInfoKHR_null();
		init.qualityLevel = qualityLevel;
		return init;
	}

	static inline VkVideoEncodeSessionParametersGetInfoKHR vkiVideoEncodeSessionParametersGetInfoKHR_null()
	{
		VkVideoEncodeSessionParametersGetInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeSessionParametersGetInfoKHR vkiVideoEncodeSessionParametersGetInfoKHR(VkVideoSessionParametersKHR videoSessionParameters)
	{
		VkVideoEncodeSessionParametersGetInfoKHR init = vkiVideoEncodeSessionParametersGetInfoKHR_null();
		init.videoSessionParameters = videoSessionParameters;
		return init;
	}

	static inline VkVideoEncodeSessionParametersFeedbackInfoKHR vkiVideoEncodeSessionParametersFeedbackInfoKHR_null()
	{
		VkVideoEncodeSessionParametersFeedbackInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR;
		return init;
	}

	static inline VkVideoEncodeSessionParametersFeedbackInfoKHR vkiVideoEncodeSessionParametersFeedbackInfoKHR(VkBool32 hasOverrides)
	{
		VkVideoEncodeSessionParametersFeedbackInfoKHR init = vkiVideoEncodeSessionParametersFeedbackInfoKHR_null();
		init.hasOverrides = hasOverrides;
		return init;
	}

	static inline VkQueueFamilyCheckpointProperties2NV vkiQueueFamilyCheckpointProperties2NV_null()
	{
		VkQueueFamilyCheckpointProperties2NV init = {0};
		init.sType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV;
		return init;
	}

	static inline VkQueueFamilyCheckpointProperties2NV vkiQueueFamilyCheckpointProperties2NV(VkPipelineStageFlags2 checkpointExecutionStageMask)
	{
		VkQueueFamilyCheckpointProperties2NV init = vkiQueueFamilyCheckpointProperties2NV_null();
		init.checkpointExecutionStageMask = checkpointExecutionStageMask;
		return init;
	}

	static inline VkCheckpointData2NV vkiCheckpointData2NV_null()
	{
		VkCheckpointData2NV init = {0};
		init.sType = VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV;
		return init;
	}

	static inline VkCheckpointData2NV vkiCheckpointData2NV(VkPipelineStageFlags2 stage, void *pCheckpointMarker)
	{
		VkCheckpointData2NV init = vkiCheckpointData2NV_null();
		init.stage = stage;
		init.pCheckpointMarker = pCheckpointMarker;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR vkiPhysicalDeviceFragmentShaderBarycentricFeaturesKHR_null()
	{
		VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR vkiPhysicalDeviceFragmentShaderBarycentricFeaturesKHR(VkBool32 fragmentShaderBarycentric)
	{
		VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR init = vkiPhysicalDeviceFragmentShaderBarycentricFeaturesKHR_null();
		init.fragmentShaderBarycentric = fragmentShaderBarycentric;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR vkiPhysicalDeviceFragmentShaderBarycentricPropertiesKHR_null()
	{
		VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR vkiPhysicalDeviceFragmentShaderBarycentricPropertiesKHR(VkBool32 triStripVertexOrderIndependentOfProvokingVertex)
	{
		VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR init = vkiPhysicalDeviceFragmentShaderBarycentricPropertiesKHR_null();
		init.triStripVertexOrderIndependentOfProvokingVertex = triStripVertexOrderIndependentOfProvokingVertex;
		return init;
	}

	static inline VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR vkiPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR_null()
	{
		VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR vkiPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(VkBool32 shaderSubgroupUniformControlFlow)
	{
		VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR init = vkiPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR_null();
		init.shaderSubgroupUniformControlFlow = shaderSubgroupUniformControlFlow;
		return init;
	}

	static inline VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR vkiPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_null()
	{
		VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR vkiPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(VkBool32 workgroupMemoryExplicitLayout, VkBool32 workgroupMemoryExplicitLayoutScalarBlockLayout, VkBool32 workgroupMemoryExplicitLayout8BitAccess, VkBool32 workgroupMemoryExplicitLayout16BitAccess)
	{
		VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR init = vkiPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR_null();
		init.workgroupMemoryExplicitLayout = workgroupMemoryExplicitLayout;
		init.workgroupMemoryExplicitLayoutScalarBlockLayout = workgroupMemoryExplicitLayoutScalarBlockLayout;
		init.workgroupMemoryExplicitLayout8BitAccess = workgroupMemoryExplicitLayout8BitAccess;
		init.workgroupMemoryExplicitLayout16BitAccess = workgroupMemoryExplicitLayout16BitAccess;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR vkiPhysicalDeviceRayTracingMaintenance1FeaturesKHR_null()
	{
		VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR vkiPhysicalDeviceRayTracingMaintenance1FeaturesKHR(VkBool32 rayTracingMaintenance1, VkBool32 rayTracingPipelineTraceRaysIndirect2)
	{
		VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR init = vkiPhysicalDeviceRayTracingMaintenance1FeaturesKHR_null();
		init.rayTracingMaintenance1 = rayTracingMaintenance1;
		init.rayTracingPipelineTraceRaysIndirect2 = rayTracingPipelineTraceRaysIndirect2;
		return init;
	}

	static inline VkTraceRaysIndirectCommand2KHR vkiTraceRaysIndirectCommand2KHR_null()
	{
		VkTraceRaysIndirectCommand2KHR init = {0};
		return init;
	}

	static inline VkTraceRaysIndirectCommand2KHR vkiTraceRaysIndirectCommand2KHR(VkDeviceAddress raygenShaderRecordAddress, VkDeviceSize raygenShaderRecordSize, VkDeviceAddress missShaderBindingTableAddress, VkDeviceSize missShaderBindingTableSize, VkDeviceSize missShaderBindingTableStride, VkDeviceAddress hitShaderBindingTableAddress, VkDeviceSize hitShaderBindingTableSize, VkDeviceSize hitShaderBindingTableStride, VkDeviceAddress callableShaderBindingTableAddress, VkDeviceSize callableShaderBindingTableSize, VkDeviceSize callableShaderBindingTableStride, uint32_t width, uint32_t height, uint32_t depth)
	{
		VkTraceRaysIndirectCommand2KHR init = vkiTraceRaysIndirectCommand2KHR_null();
		init.raygenShaderRecordAddress = raygenShaderRecordAddress;
		init.raygenShaderRecordSize = raygenShaderRecordSize;
		init.missShaderBindingTableAddress = missShaderBindingTableAddress;
		init.missShaderBindingTableSize = missShaderBindingTableSize;
		init.missShaderBindingTableStride = missShaderBindingTableStride;
		init.hitShaderBindingTableAddress = hitShaderBindingTableAddress;
		init.hitShaderBindingTableSize = hitShaderBindingTableSize;
		init.hitShaderBindingTableStride = hitShaderBindingTableStride;
		init.callableShaderBindingTableAddress = callableShaderBindingTableAddress;
		init.callableShaderBindingTableSize = callableShaderBindingTableSize;
		init.callableShaderBindingTableStride = callableShaderBindingTableStride;
		init.width = width;
		init.height = height;
		init.depth = depth;
		return init;
	}

	static inline VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR vkiPhysicalDeviceShaderSubgroupRotateFeaturesKHR_null()
	{
		VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR vkiPhysicalDeviceShaderSubgroupRotateFeaturesKHR(VkBool32 shaderSubgroupRotate, VkBool32 shaderSubgroupRotateClustered)
	{
		VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR init = vkiPhysicalDeviceShaderSubgroupRotateFeaturesKHR_null();
		init.shaderSubgroupRotate = shaderSubgroupRotate;
		init.shaderSubgroupRotateClustered = shaderSubgroupRotateClustered;
		return init;
	}

	static inline VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR vkiPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR_null()
	{
		VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR vkiPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR(VkBool32 shaderMaximalReconvergence)
	{
		VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR init = vkiPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR_null();
		init.shaderMaximalReconvergence = shaderMaximalReconvergence;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance5FeaturesKHR vkiPhysicalDeviceMaintenance5FeaturesKHR_null()
	{
		VkPhysicalDeviceMaintenance5FeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance5FeaturesKHR vkiPhysicalDeviceMaintenance5FeaturesKHR(VkBool32 maintenance5)
	{
		VkPhysicalDeviceMaintenance5FeaturesKHR init = vkiPhysicalDeviceMaintenance5FeaturesKHR_null();
		init.maintenance5 = maintenance5;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance5PropertiesKHR vkiPhysicalDeviceMaintenance5PropertiesKHR_null()
	{
		VkPhysicalDeviceMaintenance5PropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance5PropertiesKHR vkiPhysicalDeviceMaintenance5PropertiesKHR(VkBool32 earlyFragmentMultisampleCoverageAfterSampleCounting, VkBool32 earlyFragmentSampleMaskTestBeforeSampleCounting, VkBool32 depthStencilSwizzleOneSupport, VkBool32 polygonModePointSize, VkBool32 nonStrictSinglePixelWideLinesUseParallelogram, VkBool32 nonStrictWideLinesUseParallelogram)
	{
		VkPhysicalDeviceMaintenance5PropertiesKHR init = vkiPhysicalDeviceMaintenance5PropertiesKHR_null();
		init.earlyFragmentMultisampleCoverageAfterSampleCounting = earlyFragmentMultisampleCoverageAfterSampleCounting;
		init.earlyFragmentSampleMaskTestBeforeSampleCounting = earlyFragmentSampleMaskTestBeforeSampleCounting;
		init.depthStencilSwizzleOneSupport = depthStencilSwizzleOneSupport;
		init.polygonModePointSize = polygonModePointSize;
		init.nonStrictSinglePixelWideLinesUseParallelogram = nonStrictSinglePixelWideLinesUseParallelogram;
		init.nonStrictWideLinesUseParallelogram = nonStrictWideLinesUseParallelogram;
		return init;
	}

	static inline VkRenderingAreaInfoKHR vkiRenderingAreaInfoKHR_null()
	{
		VkRenderingAreaInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDERING_AREA_INFO_KHR;
		return init;
	}

	static inline VkRenderingAreaInfoKHR vkiRenderingAreaInfoKHR(uint32_t viewMask, uint32_t colorAttachmentCount, const VkFormat *pColorAttachmentFormats, VkFormat depthAttachmentFormat, VkFormat stencilAttachmentFormat)
	{
		VkRenderingAreaInfoKHR init = vkiRenderingAreaInfoKHR_null();
		init.viewMask = viewMask;
		init.colorAttachmentCount = colorAttachmentCount;
		init.pColorAttachmentFormats = pColorAttachmentFormats;
		init.depthAttachmentFormat = depthAttachmentFormat;
		init.stencilAttachmentFormat = stencilAttachmentFormat;
		return init;
	}

	static inline VkImageSubresource2KHR vkiImageSubresource2KHR_null()
	{
		VkImageSubresource2KHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_KHR;
		return init;
	}

	static inline VkImageSubresource2KHR vkiImageSubresource2KHR(VkImageSubresource imageSubresource)
	{
		VkImageSubresource2KHR init = vkiImageSubresource2KHR_null();
		init.imageSubresource = imageSubresource;
		return init;
	}

	static inline VkDeviceImageSubresourceInfoKHR vkiDeviceImageSubresourceInfoKHR_null()
	{
		VkDeviceImageSubresourceInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO_KHR;
		return init;
	}

	static inline VkDeviceImageSubresourceInfoKHR vkiDeviceImageSubresourceInfoKHR(const VkImageCreateInfo *pCreateInfo, const VkImageSubresource2KHR *pSubresource)
	{
		VkDeviceImageSubresourceInfoKHR init = vkiDeviceImageSubresourceInfoKHR_null();
		init.pCreateInfo = pCreateInfo;
		init.pSubresource = pSubresource;
		return init;
	}

	static inline VkSubresourceLayout2KHR vkiSubresourceLayout2KHR_null()
	{
		VkSubresourceLayout2KHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR;
		return init;
	}

	static inline VkSubresourceLayout2KHR vkiSubresourceLayout2KHR(VkSubresourceLayout subresourceLayout)
	{
		VkSubresourceLayout2KHR init = vkiSubresourceLayout2KHR_null();
		init.subresourceLayout = subresourceLayout;
		return init;
	}

	static inline VkPipelineCreateFlags2CreateInfoKHR vkiPipelineCreateFlags2CreateInfoKHR_null()
	{
		VkPipelineCreateFlags2CreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR;
		return init;
	}

	static inline VkPipelineCreateFlags2CreateInfoKHR vkiPipelineCreateFlags2CreateInfoKHR()
	{
		VkPipelineCreateFlags2CreateInfoKHR init = vkiPipelineCreateFlags2CreateInfoKHR_null();
		return init;
	}

	static inline VkBufferUsageFlags2CreateInfoKHR vkiBufferUsageFlags2CreateInfoKHR_null()
	{
		VkBufferUsageFlags2CreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR;
		return init;
	}

	static inline VkBufferUsageFlags2CreateInfoKHR vkiBufferUsageFlags2CreateInfoKHR(VkBufferUsageFlags2KHR usage)
	{
		VkBufferUsageFlags2CreateInfoKHR init = vkiBufferUsageFlags2CreateInfoKHR_null();
		init.usage = usage;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR vkiPhysicalDeviceRayTracingPositionFetchFeaturesKHR_null()
	{
		VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR vkiPhysicalDeviceRayTracingPositionFetchFeaturesKHR(VkBool32 rayTracingPositionFetch)
	{
		VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR init = vkiPhysicalDeviceRayTracingPositionFetchFeaturesKHR_null();
		init.rayTracingPositionFetch = rayTracingPositionFetch;
		return init;
	}

	static inline VkCooperativeMatrixPropertiesKHR vkiCooperativeMatrixPropertiesKHR_null()
	{
		VkCooperativeMatrixPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR;
		return init;
	}

	static inline VkCooperativeMatrixPropertiesKHR vkiCooperativeMatrixPropertiesKHR(uint32_t MSize, uint32_t NSize, uint32_t KSize, VkComponentTypeKHR AType, VkComponentTypeKHR BType, VkComponentTypeKHR CType, VkComponentTypeKHR ResultType, VkBool32 saturatingAccumulation, VkScopeKHR scope)
	{
		VkCooperativeMatrixPropertiesKHR init = vkiCooperativeMatrixPropertiesKHR_null();
		init.MSize = MSize;
		init.NSize = NSize;
		init.KSize = KSize;
		init.AType = AType;
		init.BType = BType;
		init.CType = CType;
		init.ResultType = ResultType;
		init.saturatingAccumulation = saturatingAccumulation;
		init.scope = scope;
		return init;
	}

	static inline VkPhysicalDeviceCooperativeMatrixFeaturesKHR vkiPhysicalDeviceCooperativeMatrixFeaturesKHR_null()
	{
		VkPhysicalDeviceCooperativeMatrixFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceCooperativeMatrixFeaturesKHR vkiPhysicalDeviceCooperativeMatrixFeaturesKHR(VkBool32 cooperativeMatrix, VkBool32 cooperativeMatrixRobustBufferAccess)
	{
		VkPhysicalDeviceCooperativeMatrixFeaturesKHR init = vkiPhysicalDeviceCooperativeMatrixFeaturesKHR_null();
		init.cooperativeMatrix = cooperativeMatrix;
		init.cooperativeMatrixRobustBufferAccess = cooperativeMatrixRobustBufferAccess;
		return init;
	}

	static inline VkPhysicalDeviceCooperativeMatrixPropertiesKHR vkiPhysicalDeviceCooperativeMatrixPropertiesKHR_null()
	{
		VkPhysicalDeviceCooperativeMatrixPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceCooperativeMatrixPropertiesKHR vkiPhysicalDeviceCooperativeMatrixPropertiesKHR(VkShaderStageFlags cooperativeMatrixSupportedStages)
	{
		VkPhysicalDeviceCooperativeMatrixPropertiesKHR init = vkiPhysicalDeviceCooperativeMatrixPropertiesKHR_null();
		init.cooperativeMatrixSupportedStages = cooperativeMatrixSupportedStages;
		return init;
	}

	static inline VkVideoDecodeAV1ProfileInfoKHR vkiVideoDecodeAV1ProfileInfoKHR_null()
	{
		VkVideoDecodeAV1ProfileInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeAV1ProfileInfoKHR vkiVideoDecodeAV1ProfileInfoKHR(StdVideoAV1Profile stdProfile, VkBool32 filmGrainSupport)
	{
		VkVideoDecodeAV1ProfileInfoKHR init = vkiVideoDecodeAV1ProfileInfoKHR_null();
		init.stdProfile = stdProfile;
		init.filmGrainSupport = filmGrainSupport;
		return init;
	}

	static inline VkVideoDecodeAV1CapabilitiesKHR vkiVideoDecodeAV1CapabilitiesKHR_null()
	{
		VkVideoDecodeAV1CapabilitiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR;
		return init;
	}

	static inline VkVideoDecodeAV1CapabilitiesKHR vkiVideoDecodeAV1CapabilitiesKHR(StdVideoAV1Level maxLevel)
	{
		VkVideoDecodeAV1CapabilitiesKHR init = vkiVideoDecodeAV1CapabilitiesKHR_null();
		init.maxLevel = maxLevel;
		return init;
	}

	static inline VkVideoDecodeAV1SessionParametersCreateInfoKHR vkiVideoDecodeAV1SessionParametersCreateInfoKHR_null()
	{
		VkVideoDecodeAV1SessionParametersCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeAV1SessionParametersCreateInfoKHR vkiVideoDecodeAV1SessionParametersCreateInfoKHR(const StdVideoAV1SequenceHeader *pStdSequenceHeader)
	{
		VkVideoDecodeAV1SessionParametersCreateInfoKHR init = vkiVideoDecodeAV1SessionParametersCreateInfoKHR_null();
		init.pStdSequenceHeader = pStdSequenceHeader;
		return init;
	}

	static inline VkVideoDecodeAV1PictureInfoKHR vkiVideoDecodeAV1PictureInfoKHR_null()
	{
		VkVideoDecodeAV1PictureInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeAV1PictureInfoKHR vkiVideoDecodeAV1PictureInfoKHR(const StdVideoDecodeAV1PictureInfo *pStdPictureInfo, uint32_t frameHeaderOffset, uint32_t tileCount, const uint32_t *pTileOffsets, const uint32_t *pTileSizes)
	{
		VkVideoDecodeAV1PictureInfoKHR init = vkiVideoDecodeAV1PictureInfoKHR_null();
		init.pStdPictureInfo = pStdPictureInfo;
		init.frameHeaderOffset = frameHeaderOffset;
		init.tileCount = tileCount;
		init.pTileOffsets = pTileOffsets;
		init.pTileSizes = pTileSizes;
		return init;
	}

	static inline VkVideoDecodeAV1DpbSlotInfoKHR vkiVideoDecodeAV1DpbSlotInfoKHR_null()
	{
		VkVideoDecodeAV1DpbSlotInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR;
		return init;
	}

	static inline VkVideoDecodeAV1DpbSlotInfoKHR vkiVideoDecodeAV1DpbSlotInfoKHR(const StdVideoDecodeAV1ReferenceInfo *pStdReferenceInfo)
	{
		VkVideoDecodeAV1DpbSlotInfoKHR init = vkiVideoDecodeAV1DpbSlotInfoKHR_null();
		init.pStdReferenceInfo = pStdReferenceInfo;
		return init;
	}

	static inline VkPhysicalDeviceVideoMaintenance1FeaturesKHR vkiPhysicalDeviceVideoMaintenance1FeaturesKHR_null()
	{
		VkPhysicalDeviceVideoMaintenance1FeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceVideoMaintenance1FeaturesKHR vkiPhysicalDeviceVideoMaintenance1FeaturesKHR(VkBool32 videoMaintenance1)
	{
		VkPhysicalDeviceVideoMaintenance1FeaturesKHR init = vkiPhysicalDeviceVideoMaintenance1FeaturesKHR_null();
		init.videoMaintenance1 = videoMaintenance1;
		return init;
	}

	static inline VkVideoInlineQueryInfoKHR vkiVideoInlineQueryInfoKHR_null()
	{
		VkVideoInlineQueryInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR;
		return init;
	}

	static inline VkVideoInlineQueryInfoKHR vkiVideoInlineQueryInfoKHR(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
	{
		VkVideoInlineQueryInfoKHR init = vkiVideoInlineQueryInfoKHR_null();
		init.queryPool = queryPool;
		init.firstQuery = firstQuery;
		init.queryCount = queryCount;
		return init;
	}

	static inline VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR vkiPhysicalDeviceVertexAttributeDivisorPropertiesKHR_null()
	{
		VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR vkiPhysicalDeviceVertexAttributeDivisorPropertiesKHR(uint32_t maxVertexAttribDivisor, VkBool32 supportsNonZeroFirstInstance)
	{
		VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR init = vkiPhysicalDeviceVertexAttributeDivisorPropertiesKHR_null();
		init.maxVertexAttribDivisor = maxVertexAttribDivisor;
		init.supportsNonZeroFirstInstance = supportsNonZeroFirstInstance;
		return init;
	}

	static inline VkVertexInputBindingDivisorDescriptionKHR vkiVertexInputBindingDivisorDescriptionKHR_null()
	{
		VkVertexInputBindingDivisorDescriptionKHR init = {0};
		return init;
	}

	static inline VkVertexInputBindingDivisorDescriptionKHR vkiVertexInputBindingDivisorDescriptionKHR(uint32_t binding, uint32_t divisor)
	{
		VkVertexInputBindingDivisorDescriptionKHR init = vkiVertexInputBindingDivisorDescriptionKHR_null();
		init.binding = binding;
		init.divisor = divisor;
		return init;
	}

	static inline VkPipelineVertexInputDivisorStateCreateInfoKHR vkiPipelineVertexInputDivisorStateCreateInfoKHR_null()
	{
		VkPipelineVertexInputDivisorStateCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR;
		return init;
	}

	static inline VkPipelineVertexInputDivisorStateCreateInfoKHR vkiPipelineVertexInputDivisorStateCreateInfoKHR(uint32_t vertexBindingDivisorCount, const VkVertexInputBindingDivisorDescriptionKHR *pVertexBindingDivisors)
	{
		VkPipelineVertexInputDivisorStateCreateInfoKHR init = vkiPipelineVertexInputDivisorStateCreateInfoKHR_null();
		init.vertexBindingDivisorCount = vertexBindingDivisorCount;
		init.pVertexBindingDivisors = pVertexBindingDivisors;
		return init;
	}

	static inline VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR vkiPhysicalDeviceVertexAttributeDivisorFeaturesKHR_null()
	{
		VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR vkiPhysicalDeviceVertexAttributeDivisorFeaturesKHR(VkBool32 vertexAttributeInstanceRateDivisor, VkBool32 vertexAttributeInstanceRateZeroDivisor)
	{
		VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR init = vkiPhysicalDeviceVertexAttributeDivisorFeaturesKHR_null();
		init.vertexAttributeInstanceRateDivisor = vertexAttributeInstanceRateDivisor;
		init.vertexAttributeInstanceRateZeroDivisor = vertexAttributeInstanceRateZeroDivisor;
		return init;
	}

	static inline VkPhysicalDeviceShaderFloatControls2FeaturesKHR vkiPhysicalDeviceShaderFloatControls2FeaturesKHR_null()
	{
		VkPhysicalDeviceShaderFloatControls2FeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceShaderFloatControls2FeaturesKHR vkiPhysicalDeviceShaderFloatControls2FeaturesKHR(VkBool32 shaderFloatControls2)
	{
		VkPhysicalDeviceShaderFloatControls2FeaturesKHR init = vkiPhysicalDeviceShaderFloatControls2FeaturesKHR_null();
		init.shaderFloatControls2 = shaderFloatControls2;
		return init;
	}

	static inline VkPhysicalDeviceIndexTypeUint8FeaturesKHR vkiPhysicalDeviceIndexTypeUint8FeaturesKHR_null()
	{
		VkPhysicalDeviceIndexTypeUint8FeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceIndexTypeUint8FeaturesKHR vkiPhysicalDeviceIndexTypeUint8FeaturesKHR(VkBool32 indexTypeUint8)
	{
		VkPhysicalDeviceIndexTypeUint8FeaturesKHR init = vkiPhysicalDeviceIndexTypeUint8FeaturesKHR_null();
		init.indexTypeUint8 = indexTypeUint8;
		return init;
	}

	static inline VkPhysicalDeviceLineRasterizationFeaturesKHR vkiPhysicalDeviceLineRasterizationFeaturesKHR_null()
	{
		VkPhysicalDeviceLineRasterizationFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceLineRasterizationFeaturesKHR vkiPhysicalDeviceLineRasterizationFeaturesKHR(VkBool32 rectangularLines, VkBool32 bresenhamLines, VkBool32 smoothLines, VkBool32 stippledRectangularLines, VkBool32 stippledBresenhamLines, VkBool32 stippledSmoothLines)
	{
		VkPhysicalDeviceLineRasterizationFeaturesKHR init = vkiPhysicalDeviceLineRasterizationFeaturesKHR_null();
		init.rectangularLines = rectangularLines;
		init.bresenhamLines = bresenhamLines;
		init.smoothLines = smoothLines;
		init.stippledRectangularLines = stippledRectangularLines;
		init.stippledBresenhamLines = stippledBresenhamLines;
		init.stippledSmoothLines = stippledSmoothLines;
		return init;
	}

	static inline VkPhysicalDeviceLineRasterizationPropertiesKHR vkiPhysicalDeviceLineRasterizationPropertiesKHR_null()
	{
		VkPhysicalDeviceLineRasterizationPropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceLineRasterizationPropertiesKHR vkiPhysicalDeviceLineRasterizationPropertiesKHR(uint32_t lineSubPixelPrecisionBits)
	{
		VkPhysicalDeviceLineRasterizationPropertiesKHR init = vkiPhysicalDeviceLineRasterizationPropertiesKHR_null();
		init.lineSubPixelPrecisionBits = lineSubPixelPrecisionBits;
		return init;
	}

	static inline VkPipelineRasterizationLineStateCreateInfoKHR vkiPipelineRasterizationLineStateCreateInfoKHR_null()
	{
		VkPipelineRasterizationLineStateCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_KHR;
		return init;
	}

	static inline VkPipelineRasterizationLineStateCreateInfoKHR vkiPipelineRasterizationLineStateCreateInfoKHR(VkLineRasterizationModeKHR lineRasterizationMode, VkBool32 stippledLineEnable, uint32_t lineStippleFactor, uint16_t lineStipplePattern)
	{
		VkPipelineRasterizationLineStateCreateInfoKHR init = vkiPipelineRasterizationLineStateCreateInfoKHR_null();
		init.lineRasterizationMode = lineRasterizationMode;
		init.stippledLineEnable = stippledLineEnable;
		init.lineStippleFactor = lineStippleFactor;
		init.lineStipplePattern = lineStipplePattern;
		return init;
	}

	static inline VkCalibratedTimestampInfoKHR vkiCalibratedTimestampInfoKHR_null()
	{
		VkCalibratedTimestampInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR;
		return init;
	}

	static inline VkCalibratedTimestampInfoKHR vkiCalibratedTimestampInfoKHR(VkTimeDomainKHR timeDomain)
	{
		VkCalibratedTimestampInfoKHR init = vkiCalibratedTimestampInfoKHR_null();
		init.timeDomain = timeDomain;
		return init;
	}

	static inline VkPhysicalDeviceShaderExpectAssumeFeaturesKHR vkiPhysicalDeviceShaderExpectAssumeFeaturesKHR_null()
	{
		VkPhysicalDeviceShaderExpectAssumeFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceShaderExpectAssumeFeaturesKHR vkiPhysicalDeviceShaderExpectAssumeFeaturesKHR(VkBool32 shaderExpectAssume)
	{
		VkPhysicalDeviceShaderExpectAssumeFeaturesKHR init = vkiPhysicalDeviceShaderExpectAssumeFeaturesKHR_null();
		init.shaderExpectAssume = shaderExpectAssume;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance6FeaturesKHR vkiPhysicalDeviceMaintenance6FeaturesKHR_null()
	{
		VkPhysicalDeviceMaintenance6FeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance6FeaturesKHR vkiPhysicalDeviceMaintenance6FeaturesKHR(VkBool32 maintenance6)
	{
		VkPhysicalDeviceMaintenance6FeaturesKHR init = vkiPhysicalDeviceMaintenance6FeaturesKHR_null();
		init.maintenance6 = maintenance6;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance6PropertiesKHR vkiPhysicalDeviceMaintenance6PropertiesKHR_null()
	{
		VkPhysicalDeviceMaintenance6PropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceMaintenance6PropertiesKHR vkiPhysicalDeviceMaintenance6PropertiesKHR(VkBool32 blockTexelViewCompatibleMultipleLayers, uint32_t maxCombinedImageSamplerDescriptorCount, VkBool32 fragmentShadingRateClampCombinerInputs)
	{
		VkPhysicalDeviceMaintenance6PropertiesKHR init = vkiPhysicalDeviceMaintenance6PropertiesKHR_null();
		init.blockTexelViewCompatibleMultipleLayers = blockTexelViewCompatibleMultipleLayers;
		init.maxCombinedImageSamplerDescriptorCount = maxCombinedImageSamplerDescriptorCount;
		init.fragmentShadingRateClampCombinerInputs = fragmentShadingRateClampCombinerInputs;
		return init;
	}

	static inline VkBindMemoryStatusKHR vkiBindMemoryStatusKHR_null()
	{
		VkBindMemoryStatusKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS_KHR;
		return init;
	}

	static inline VkBindMemoryStatusKHR vkiBindMemoryStatusKHR(VkResult *pResult)
	{
		VkBindMemoryStatusKHR init = vkiBindMemoryStatusKHR_null();
		init.pResult = pResult;
		return init;
	}

	static inline VkBindDescriptorSetsInfoKHR vkiBindDescriptorSetsInfoKHR_null()
	{
		VkBindDescriptorSetsInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO_KHR;
		return init;
	}

	static inline VkBindDescriptorSetsInfoKHR vkiBindDescriptorSetsInfoKHR(VkShaderStageFlags stageFlags, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet *pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t *pDynamicOffsets)
	{
		VkBindDescriptorSetsInfoKHR init = vkiBindDescriptorSetsInfoKHR_null();
		init.stageFlags = stageFlags;
		init.layout = layout;
		init.firstSet = firstSet;
		init.descriptorSetCount = descriptorSetCount;
		init.pDescriptorSets = pDescriptorSets;
		init.dynamicOffsetCount = dynamicOffsetCount;
		init.pDynamicOffsets = pDynamicOffsets;
		return init;
	}

	static inline VkPushConstantsInfoKHR vkiPushConstantsInfoKHR_null()
	{
		VkPushConstantsInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO_KHR;
		return init;
	}

	static inline VkPushConstantsInfoKHR vkiPushConstantsInfoKHR(VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void *pValues)
	{
		VkPushConstantsInfoKHR init = vkiPushConstantsInfoKHR_null();
		init.layout = layout;
		init.stageFlags = stageFlags;
		init.offset = offset;
		init.size = size;
		init.pValues = pValues;
		return init;
	}

	static inline VkPushDescriptorSetInfoKHR vkiPushDescriptorSetInfoKHR_null()
	{
		VkPushDescriptorSetInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO_KHR;
		return init;
	}

	static inline VkPushDescriptorSetInfoKHR vkiPushDescriptorSetInfoKHR(VkShaderStageFlags stageFlags, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet *pDescriptorWrites)
	{
		VkPushDescriptorSetInfoKHR init = vkiPushDescriptorSetInfoKHR_null();
		init.stageFlags = stageFlags;
		init.layout = layout;
		init.set = set;
		init.descriptorWriteCount = descriptorWriteCount;
		init.pDescriptorWrites = pDescriptorWrites;
		return init;
	}

	static inline VkPushDescriptorSetWithTemplateInfoKHR vkiPushDescriptorSetWithTemplateInfoKHR_null()
	{
		VkPushDescriptorSetWithTemplateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO_KHR;
		return init;
	}

	static inline VkPushDescriptorSetWithTemplateInfoKHR vkiPushDescriptorSetWithTemplateInfoKHR(VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void *pData)
	{
		VkPushDescriptorSetWithTemplateInfoKHR init = vkiPushDescriptorSetWithTemplateInfoKHR_null();
		init.descriptorUpdateTemplate = descriptorUpdateTemplate;
		init.layout = layout;
		init.set = set;
		init.pData = pData;
		return init;
	}

	static inline VkSetDescriptorBufferOffsetsInfoEXT vkiSetDescriptorBufferOffsetsInfoEXT_null()
	{
		VkSetDescriptorBufferOffsetsInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT;
		return init;
	}

	static inline VkSetDescriptorBufferOffsetsInfoEXT vkiSetDescriptorBufferOffsetsInfoEXT(VkShaderStageFlags stageFlags, VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount, const uint32_t *pBufferIndices, const VkDeviceSize *pOffsets)
	{
		VkSetDescriptorBufferOffsetsInfoEXT init = vkiSetDescriptorBufferOffsetsInfoEXT_null();
		init.stageFlags = stageFlags;
		init.layout = layout;
		init.firstSet = firstSet;
		init.setCount = setCount;
		init.pBufferIndices = pBufferIndices;
		init.pOffsets = pOffsets;
		return init;
	}

	static inline VkBindDescriptorBufferEmbeddedSamplersInfoEXT vkiBindDescriptorBufferEmbeddedSamplersInfoEXT_null()
	{
		VkBindDescriptorBufferEmbeddedSamplersInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT;
		return init;
	}

	static inline VkBindDescriptorBufferEmbeddedSamplersInfoEXT vkiBindDescriptorBufferEmbeddedSamplersInfoEXT(VkShaderStageFlags stageFlags, VkPipelineLayout layout, uint32_t set)
	{
		VkBindDescriptorBufferEmbeddedSamplersInfoEXT init = vkiBindDescriptorBufferEmbeddedSamplersInfoEXT_null();
		init.stageFlags = stageFlags;
		init.layout = layout;
		init.set = set;
		return init;
	}

	static inline VkDebugReportCallbackCreateInfoEXT vkiDebugReportCallbackCreateInfoEXT_null()
	{
		VkDebugReportCallbackCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
		return init;
	}

	static inline VkDebugReportCallbackCreateInfoEXT vkiDebugReportCallbackCreateInfoEXT(PFN_vkDebugReportCallbackEXT pfnCallback, void *pUserData)
	{
		VkDebugReportCallbackCreateInfoEXT init = vkiDebugReportCallbackCreateInfoEXT_null();
		init.pfnCallback = pfnCallback;
		init.pUserData = pUserData;
		return init;
	}

	static inline VkPipelineRasterizationStateRasterizationOrderAMD vkiPipelineRasterizationStateRasterizationOrderAMD_null()
	{
		VkPipelineRasterizationStateRasterizationOrderAMD init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD;
		return init;
	}

	static inline VkPipelineRasterizationStateRasterizationOrderAMD vkiPipelineRasterizationStateRasterizationOrderAMD(VkRasterizationOrderAMD rasterizationOrder)
	{
		VkPipelineRasterizationStateRasterizationOrderAMD init = vkiPipelineRasterizationStateRasterizationOrderAMD_null();
		init.rasterizationOrder = rasterizationOrder;
		return init;
	}

	static inline VkDebugMarkerObjectNameInfoEXT vkiDebugMarkerObjectNameInfoEXT_null()
	{
		VkDebugMarkerObjectNameInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT;
		return init;
	}

	static inline VkDebugMarkerObjectNameInfoEXT vkiDebugMarkerObjectNameInfoEXT(VkDebugReportObjectTypeEXT objectType, uint64_t object, const char *pObjectName)
	{
		VkDebugMarkerObjectNameInfoEXT init = vkiDebugMarkerObjectNameInfoEXT_null();
		init.objectType = objectType;
		init.object = object;
		init.pObjectName = pObjectName;
		return init;
	}

	static inline VkDebugMarkerObjectTagInfoEXT vkiDebugMarkerObjectTagInfoEXT_null()
	{
		VkDebugMarkerObjectTagInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT;
		return init;
	}

	static inline VkDebugMarkerObjectTagInfoEXT vkiDebugMarkerObjectTagInfoEXT(VkDebugReportObjectTypeEXT objectType, uint64_t object, uint64_t tagName, size_t tagSize, const void *pTag)
	{
		VkDebugMarkerObjectTagInfoEXT init = vkiDebugMarkerObjectTagInfoEXT_null();
		init.objectType = objectType;
		init.object = object;
		init.tagName = tagName;
		init.tagSize = tagSize;
		init.pTag = pTag;
		return init;
	}

	static inline VkDebugMarkerMarkerInfoEXT vkiDebugMarkerMarkerInfoEXT_null()
	{
		VkDebugMarkerMarkerInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT;
		return init;
	}

	static inline VkDebugMarkerMarkerInfoEXT vkiDebugMarkerMarkerInfoEXT(const char *pMarkerName)
	{
		VkDebugMarkerMarkerInfoEXT init = vkiDebugMarkerMarkerInfoEXT_null();
		init.pMarkerName = pMarkerName;
		return init;
	}

	static inline VkDedicatedAllocationImageCreateInfoNV vkiDedicatedAllocationImageCreateInfoNV_null()
	{
		VkDedicatedAllocationImageCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV;
		return init;
	}

	static inline VkDedicatedAllocationImageCreateInfoNV vkiDedicatedAllocationImageCreateInfoNV(VkBool32 dedicatedAllocation)
	{
		VkDedicatedAllocationImageCreateInfoNV init = vkiDedicatedAllocationImageCreateInfoNV_null();
		init.dedicatedAllocation = dedicatedAllocation;
		return init;
	}

	static inline VkDedicatedAllocationBufferCreateInfoNV vkiDedicatedAllocationBufferCreateInfoNV_null()
	{
		VkDedicatedAllocationBufferCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV;
		return init;
	}

	static inline VkDedicatedAllocationBufferCreateInfoNV vkiDedicatedAllocationBufferCreateInfoNV(VkBool32 dedicatedAllocation)
	{
		VkDedicatedAllocationBufferCreateInfoNV init = vkiDedicatedAllocationBufferCreateInfoNV_null();
		init.dedicatedAllocation = dedicatedAllocation;
		return init;
	}

	static inline VkDedicatedAllocationMemoryAllocateInfoNV vkiDedicatedAllocationMemoryAllocateInfoNV_null()
	{
		VkDedicatedAllocationMemoryAllocateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV;
		return init;
	}

	static inline VkDedicatedAllocationMemoryAllocateInfoNV vkiDedicatedAllocationMemoryAllocateInfoNV(VkImage image, VkBuffer buffer)
	{
		VkDedicatedAllocationMemoryAllocateInfoNV init = vkiDedicatedAllocationMemoryAllocateInfoNV_null();
		init.image = image;
		init.buffer = buffer;
		return init;
	}

	static inline VkPhysicalDeviceTransformFeedbackFeaturesEXT vkiPhysicalDeviceTransformFeedbackFeaturesEXT_null()
	{
		VkPhysicalDeviceTransformFeedbackFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceTransformFeedbackFeaturesEXT vkiPhysicalDeviceTransformFeedbackFeaturesEXT(VkBool32 transformFeedback, VkBool32 geometryStreams)
	{
		VkPhysicalDeviceTransformFeedbackFeaturesEXT init = vkiPhysicalDeviceTransformFeedbackFeaturesEXT_null();
		init.transformFeedback = transformFeedback;
		init.geometryStreams = geometryStreams;
		return init;
	}

	static inline VkPhysicalDeviceTransformFeedbackPropertiesEXT vkiPhysicalDeviceTransformFeedbackPropertiesEXT_null()
	{
		VkPhysicalDeviceTransformFeedbackPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceTransformFeedbackPropertiesEXT vkiPhysicalDeviceTransformFeedbackPropertiesEXT(uint32_t maxTransformFeedbackStreams, uint32_t maxTransformFeedbackBuffers, VkDeviceSize maxTransformFeedbackBufferSize, uint32_t maxTransformFeedbackStreamDataSize, uint32_t maxTransformFeedbackBufferDataSize, uint32_t maxTransformFeedbackBufferDataStride, VkBool32 transformFeedbackQueries, VkBool32 transformFeedbackStreamsLinesTriangles, VkBool32 transformFeedbackRasterizationStreamSelect, VkBool32 transformFeedbackDraw)
	{
		VkPhysicalDeviceTransformFeedbackPropertiesEXT init = vkiPhysicalDeviceTransformFeedbackPropertiesEXT_null();
		init.maxTransformFeedbackStreams = maxTransformFeedbackStreams;
		init.maxTransformFeedbackBuffers = maxTransformFeedbackBuffers;
		init.maxTransformFeedbackBufferSize = maxTransformFeedbackBufferSize;
		init.maxTransformFeedbackStreamDataSize = maxTransformFeedbackStreamDataSize;
		init.maxTransformFeedbackBufferDataSize = maxTransformFeedbackBufferDataSize;
		init.maxTransformFeedbackBufferDataStride = maxTransformFeedbackBufferDataStride;
		init.transformFeedbackQueries = transformFeedbackQueries;
		init.transformFeedbackStreamsLinesTriangles = transformFeedbackStreamsLinesTriangles;
		init.transformFeedbackRasterizationStreamSelect = transformFeedbackRasterizationStreamSelect;
		init.transformFeedbackDraw = transformFeedbackDraw;
		return init;
	}

	static inline VkPipelineRasterizationStateStreamCreateInfoEXT vkiPipelineRasterizationStateStreamCreateInfoEXT_null()
	{
		VkPipelineRasterizationStateStreamCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT;
		return init;
	}

	static inline VkPipelineRasterizationStateStreamCreateInfoEXT vkiPipelineRasterizationStateStreamCreateInfoEXT(uint32_t rasterizationStream)
	{
		VkPipelineRasterizationStateStreamCreateInfoEXT init = vkiPipelineRasterizationStateStreamCreateInfoEXT_null();
		init.rasterizationStream = rasterizationStream;
		return init;
	}

	static inline VkCuModuleCreateInfoNVX vkiCuModuleCreateInfoNVX_null()
	{
		VkCuModuleCreateInfoNVX init = {0};
		init.sType = VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX;
		return init;
	}

	static inline VkCuModuleCreateInfoNVX vkiCuModuleCreateInfoNVX(size_t dataSize, const void *pData)
	{
		VkCuModuleCreateInfoNVX init = vkiCuModuleCreateInfoNVX_null();
		init.dataSize = dataSize;
		init.pData = pData;
		return init;
	}

	static inline VkCuFunctionCreateInfoNVX vkiCuFunctionCreateInfoNVX_null()
	{
		VkCuFunctionCreateInfoNVX init = {0};
		init.sType = VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX;
		return init;
	}

	static inline VkCuFunctionCreateInfoNVX vkiCuFunctionCreateInfoNVX(VkCuModuleNVX module, const char *pName)
	{
		VkCuFunctionCreateInfoNVX init = vkiCuFunctionCreateInfoNVX_null();
		init.module = module;
		init.pName = pName;
		return init;
	}

	static inline VkCuLaunchInfoNVX vkiCuLaunchInfoNVX_null()
	{
		VkCuLaunchInfoNVX init = {0};
		init.sType = VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX;
		return init;
	}

	static inline VkCuLaunchInfoNVX vkiCuLaunchInfoNVX(VkCuFunctionNVX function, uint32_t gridDimX, uint32_t gridDimY, uint32_t gridDimZ, uint32_t blockDimX, uint32_t blockDimY, uint32_t blockDimZ, uint32_t sharedMemBytes, size_t paramCount, const void *const *pParams, size_t extraCount, const void *const *pExtras)
	{
		VkCuLaunchInfoNVX init = vkiCuLaunchInfoNVX_null();
		init.function = function;
		init.gridDimX = gridDimX;
		init.gridDimY = gridDimY;
		init.gridDimZ = gridDimZ;
		init.blockDimX = blockDimX;
		init.blockDimY = blockDimY;
		init.blockDimZ = blockDimZ;
		init.sharedMemBytes = sharedMemBytes;
		init.paramCount = paramCount;
		init.pParams = pParams;
		init.extraCount = extraCount;
		init.pExtras = pExtras;
		return init;
	}

	static inline VkImageViewHandleInfoNVX vkiImageViewHandleInfoNVX_null()
	{
		VkImageViewHandleInfoNVX init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX;
		return init;
	}

	static inline VkImageViewHandleInfoNVX vkiImageViewHandleInfoNVX(VkImageView imageView, VkDescriptorType descriptorType, VkSampler sampler)
	{
		VkImageViewHandleInfoNVX init = vkiImageViewHandleInfoNVX_null();
		init.imageView = imageView;
		init.descriptorType = descriptorType;
		init.sampler = sampler;
		return init;
	}

	static inline VkImageViewAddressPropertiesNVX vkiImageViewAddressPropertiesNVX_null()
	{
		VkImageViewAddressPropertiesNVX init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX;
		return init;
	}

	static inline VkImageViewAddressPropertiesNVX vkiImageViewAddressPropertiesNVX(VkDeviceAddress deviceAddress, VkDeviceSize size)
	{
		VkImageViewAddressPropertiesNVX init = vkiImageViewAddressPropertiesNVX_null();
		init.deviceAddress = deviceAddress;
		init.size = size;
		return init;
	}

	static inline VkTextureLODGatherFormatPropertiesAMD vkiTextureLODGatherFormatPropertiesAMD_null()
	{
		VkTextureLODGatherFormatPropertiesAMD init = {0};
		init.sType = VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD;
		return init;
	}

	static inline VkTextureLODGatherFormatPropertiesAMD vkiTextureLODGatherFormatPropertiesAMD(VkBool32 supportsTextureGatherLODBiasAMD)
	{
		VkTextureLODGatherFormatPropertiesAMD init = vkiTextureLODGatherFormatPropertiesAMD_null();
		init.supportsTextureGatherLODBiasAMD = supportsTextureGatherLODBiasAMD;
		return init;
	}

	static inline VkShaderResourceUsageAMD vkiShaderResourceUsageAMD_null()
	{
		VkShaderResourceUsageAMD init = {0};
		return init;
	}

	static inline VkShaderResourceUsageAMD vkiShaderResourceUsageAMD(uint32_t numUsedVgprs, uint32_t numUsedSgprs, uint32_t ldsSizePerLocalWorkGroup, size_t ldsUsageSizeInBytes, size_t scratchMemUsageInBytes)
	{
		VkShaderResourceUsageAMD init = vkiShaderResourceUsageAMD_null();
		init.numUsedVgprs = numUsedVgprs;
		init.numUsedSgprs = numUsedSgprs;
		init.ldsSizePerLocalWorkGroup = ldsSizePerLocalWorkGroup;
		init.ldsUsageSizeInBytes = ldsUsageSizeInBytes;
		init.scratchMemUsageInBytes = scratchMemUsageInBytes;
		return init;
	}

	static inline VkShaderStatisticsInfoAMD vkiShaderStatisticsInfoAMD_null()
	{
		VkShaderStatisticsInfoAMD init = {0};
		return init;
	}

	static inline VkShaderStatisticsInfoAMD vkiShaderStatisticsInfoAMD(VkShaderStageFlags shaderStageMask, VkShaderResourceUsageAMD resourceUsage, uint32_t numPhysicalVgprs, uint32_t numPhysicalSgprs, uint32_t numAvailableVgprs, uint32_t numAvailableSgprs)
	{
		VkShaderStatisticsInfoAMD init = vkiShaderStatisticsInfoAMD_null();
		init.shaderStageMask = shaderStageMask;
		init.resourceUsage = resourceUsage;
		init.numPhysicalVgprs = numPhysicalVgprs;
		init.numPhysicalSgprs = numPhysicalSgprs;
		init.numAvailableVgprs = numAvailableVgprs;
		init.numAvailableSgprs = numAvailableSgprs;
		return init;
	}

	static inline VkPhysicalDeviceCornerSampledImageFeaturesNV vkiPhysicalDeviceCornerSampledImageFeaturesNV_null()
	{
		VkPhysicalDeviceCornerSampledImageFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceCornerSampledImageFeaturesNV vkiPhysicalDeviceCornerSampledImageFeaturesNV(VkBool32 cornerSampledImage)
	{
		VkPhysicalDeviceCornerSampledImageFeaturesNV init = vkiPhysicalDeviceCornerSampledImageFeaturesNV_null();
		init.cornerSampledImage = cornerSampledImage;
		return init;
	}

	static inline VkExternalImageFormatPropertiesNV vkiExternalImageFormatPropertiesNV_null()
	{
		VkExternalImageFormatPropertiesNV init = {0};
		return init;
	}

	static inline VkExternalImageFormatPropertiesNV vkiExternalImageFormatPropertiesNV(VkImageFormatProperties imageFormatProperties, VkExternalMemoryFeatureFlagsNV externalMemoryFeatures, VkExternalMemoryHandleTypeFlagsNV exportFromImportedHandleTypes, VkExternalMemoryHandleTypeFlagsNV compatibleHandleTypes)
	{
		VkExternalImageFormatPropertiesNV init = vkiExternalImageFormatPropertiesNV_null();
		init.imageFormatProperties = imageFormatProperties;
		init.externalMemoryFeatures = externalMemoryFeatures;
		init.exportFromImportedHandleTypes = exportFromImportedHandleTypes;
		init.compatibleHandleTypes = compatibleHandleTypes;
		return init;
	}

	static inline VkExternalMemoryImageCreateInfoNV vkiExternalMemoryImageCreateInfoNV_null()
	{
		VkExternalMemoryImageCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV;
		return init;
	}

	static inline VkExternalMemoryImageCreateInfoNV vkiExternalMemoryImageCreateInfoNV(VkExternalMemoryHandleTypeFlagsNV handleTypes)
	{
		VkExternalMemoryImageCreateInfoNV init = vkiExternalMemoryImageCreateInfoNV_null();
		init.handleTypes = handleTypes;
		return init;
	}

	static inline VkExportMemoryAllocateInfoNV vkiExportMemoryAllocateInfoNV_null()
	{
		VkExportMemoryAllocateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV;
		return init;
	}

	static inline VkExportMemoryAllocateInfoNV vkiExportMemoryAllocateInfoNV(VkExternalMemoryHandleTypeFlagsNV handleTypes)
	{
		VkExportMemoryAllocateInfoNV init = vkiExportMemoryAllocateInfoNV_null();
		init.handleTypes = handleTypes;
		return init;
	}

	static inline VkValidationFlagsEXT vkiValidationFlagsEXT_null()
	{
		VkValidationFlagsEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT;
		return init;
	}

	static inline VkValidationFlagsEXT vkiValidationFlagsEXT(uint32_t disabledValidationCheckCount, const VkValidationCheckEXT *pDisabledValidationChecks)
	{
		VkValidationFlagsEXT init = vkiValidationFlagsEXT_null();
		init.disabledValidationCheckCount = disabledValidationCheckCount;
		init.pDisabledValidationChecks = pDisabledValidationChecks;
		return init;
	}

	static inline VkImageViewASTCDecodeModeEXT vkiImageViewASTCDecodeModeEXT_null()
	{
		VkImageViewASTCDecodeModeEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT;
		return init;
	}

	static inline VkImageViewASTCDecodeModeEXT vkiImageViewASTCDecodeModeEXT(VkFormat decodeMode)
	{
		VkImageViewASTCDecodeModeEXT init = vkiImageViewASTCDecodeModeEXT_null();
		init.decodeMode = decodeMode;
		return init;
	}

	static inline VkPhysicalDeviceASTCDecodeFeaturesEXT vkiPhysicalDeviceASTCDecodeFeaturesEXT_null()
	{
		VkPhysicalDeviceASTCDecodeFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceASTCDecodeFeaturesEXT vkiPhysicalDeviceASTCDecodeFeaturesEXT(VkBool32 decodeModeSharedExponent)
	{
		VkPhysicalDeviceASTCDecodeFeaturesEXT init = vkiPhysicalDeviceASTCDecodeFeaturesEXT_null();
		init.decodeModeSharedExponent = decodeModeSharedExponent;
		return init;
	}

	static inline VkPhysicalDevicePipelineRobustnessFeaturesEXT vkiPhysicalDevicePipelineRobustnessFeaturesEXT_null()
	{
		VkPhysicalDevicePipelineRobustnessFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDevicePipelineRobustnessFeaturesEXT vkiPhysicalDevicePipelineRobustnessFeaturesEXT(VkBool32 pipelineRobustness)
	{
		VkPhysicalDevicePipelineRobustnessFeaturesEXT init = vkiPhysicalDevicePipelineRobustnessFeaturesEXT_null();
		init.pipelineRobustness = pipelineRobustness;
		return init;
	}

	static inline VkPhysicalDevicePipelineRobustnessPropertiesEXT vkiPhysicalDevicePipelineRobustnessPropertiesEXT_null()
	{
		VkPhysicalDevicePipelineRobustnessPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDevicePipelineRobustnessPropertiesEXT vkiPhysicalDevicePipelineRobustnessPropertiesEXT(VkPipelineRobustnessBufferBehaviorEXT defaultRobustnessStorageBuffers, VkPipelineRobustnessBufferBehaviorEXT defaultRobustnessUniformBuffers, VkPipelineRobustnessBufferBehaviorEXT defaultRobustnessVertexInputs, VkPipelineRobustnessImageBehaviorEXT defaultRobustnessImages)
	{
		VkPhysicalDevicePipelineRobustnessPropertiesEXT init = vkiPhysicalDevicePipelineRobustnessPropertiesEXT_null();
		init.defaultRobustnessStorageBuffers = defaultRobustnessStorageBuffers;
		init.defaultRobustnessUniformBuffers = defaultRobustnessUniformBuffers;
		init.defaultRobustnessVertexInputs = defaultRobustnessVertexInputs;
		init.defaultRobustnessImages = defaultRobustnessImages;
		return init;
	}

	static inline VkPipelineRobustnessCreateInfoEXT vkiPipelineRobustnessCreateInfoEXT_null()
	{
		VkPipelineRobustnessCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT;
		return init;
	}

	static inline VkPipelineRobustnessCreateInfoEXT vkiPipelineRobustnessCreateInfoEXT(VkPipelineRobustnessBufferBehaviorEXT storageBuffers, VkPipelineRobustnessBufferBehaviorEXT uniformBuffers, VkPipelineRobustnessBufferBehaviorEXT vertexInputs, VkPipelineRobustnessImageBehaviorEXT images)
	{
		VkPipelineRobustnessCreateInfoEXT init = vkiPipelineRobustnessCreateInfoEXT_null();
		init.storageBuffers = storageBuffers;
		init.uniformBuffers = uniformBuffers;
		init.vertexInputs = vertexInputs;
		init.images = images;
		return init;
	}

	static inline VkConditionalRenderingBeginInfoEXT vkiConditionalRenderingBeginInfoEXT_null()
	{
		VkConditionalRenderingBeginInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT;
		return init;
	}

	static inline VkConditionalRenderingBeginInfoEXT vkiConditionalRenderingBeginInfoEXT(VkBuffer buffer, VkDeviceSize offset)
	{
		VkConditionalRenderingBeginInfoEXT init = vkiConditionalRenderingBeginInfoEXT_null();
		init.buffer = buffer;
		init.offset = offset;
		return init;
	}

	static inline VkPhysicalDeviceConditionalRenderingFeaturesEXT vkiPhysicalDeviceConditionalRenderingFeaturesEXT_null()
	{
		VkPhysicalDeviceConditionalRenderingFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceConditionalRenderingFeaturesEXT vkiPhysicalDeviceConditionalRenderingFeaturesEXT(VkBool32 conditionalRendering, VkBool32 inheritedConditionalRendering)
	{
		VkPhysicalDeviceConditionalRenderingFeaturesEXT init = vkiPhysicalDeviceConditionalRenderingFeaturesEXT_null();
		init.conditionalRendering = conditionalRendering;
		init.inheritedConditionalRendering = inheritedConditionalRendering;
		return init;
	}

	static inline VkCommandBufferInheritanceConditionalRenderingInfoEXT vkiCommandBufferInheritanceConditionalRenderingInfoEXT_null()
	{
		VkCommandBufferInheritanceConditionalRenderingInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT;
		return init;
	}

	static inline VkCommandBufferInheritanceConditionalRenderingInfoEXT vkiCommandBufferInheritanceConditionalRenderingInfoEXT(VkBool32 conditionalRenderingEnable)
	{
		VkCommandBufferInheritanceConditionalRenderingInfoEXT init = vkiCommandBufferInheritanceConditionalRenderingInfoEXT_null();
		init.conditionalRenderingEnable = conditionalRenderingEnable;
		return init;
	}

	static inline VkViewportWScalingNV vkiViewportWScalingNV_null()
	{
		VkViewportWScalingNV init = {0};
		return init;
	}

	static inline VkViewportWScalingNV vkiViewportWScalingNV(float xcoeff, float ycoeff)
	{
		VkViewportWScalingNV init = vkiViewportWScalingNV_null();
		init.xcoeff = xcoeff;
		init.ycoeff = ycoeff;
		return init;
	}

	static inline VkPipelineViewportWScalingStateCreateInfoNV vkiPipelineViewportWScalingStateCreateInfoNV_null()
	{
		VkPipelineViewportWScalingStateCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV;
		return init;
	}

	static inline VkPipelineViewportWScalingStateCreateInfoNV vkiPipelineViewportWScalingStateCreateInfoNV(VkBool32 viewportWScalingEnable, uint32_t viewportCount, const VkViewportWScalingNV *pViewportWScalings)
	{
		VkPipelineViewportWScalingStateCreateInfoNV init = vkiPipelineViewportWScalingStateCreateInfoNV_null();
		init.viewportWScalingEnable = viewportWScalingEnable;
		init.viewportCount = viewportCount;
		init.pViewportWScalings = pViewportWScalings;
		return init;
	}

	static inline VkSurfaceCapabilities2EXT vkiSurfaceCapabilities2EXT_null()
	{
		VkSurfaceCapabilities2EXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT;
		return init;
	}

	static inline VkSurfaceCapabilities2EXT vkiSurfaceCapabilities2EXT(uint32_t minImageCount, uint32_t maxImageCount, VkExtent2D currentExtent, VkExtent2D minImageExtent, VkExtent2D maxImageExtent, uint32_t maxImageArrayLayers, VkSurfaceTransformFlagsKHR supportedTransforms, VkSurfaceTransformFlagBitsKHR currentTransform, VkCompositeAlphaFlagsKHR supportedCompositeAlpha, VkImageUsageFlags supportedUsageFlags, VkSurfaceCounterFlagsEXT supportedSurfaceCounters)
	{
		VkSurfaceCapabilities2EXT init = vkiSurfaceCapabilities2EXT_null();
		init.minImageCount = minImageCount;
		init.maxImageCount = maxImageCount;
		init.currentExtent = currentExtent;
		init.minImageExtent = minImageExtent;
		init.maxImageExtent = maxImageExtent;
		init.maxImageArrayLayers = maxImageArrayLayers;
		init.supportedTransforms = supportedTransforms;
		init.currentTransform = currentTransform;
		init.supportedCompositeAlpha = supportedCompositeAlpha;
		init.supportedUsageFlags = supportedUsageFlags;
		init.supportedSurfaceCounters = supportedSurfaceCounters;
		return init;
	}

	static inline VkDisplayPowerInfoEXT vkiDisplayPowerInfoEXT_null()
	{
		VkDisplayPowerInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT;
		return init;
	}

	static inline VkDisplayPowerInfoEXT vkiDisplayPowerInfoEXT(VkDisplayPowerStateEXT powerState)
	{
		VkDisplayPowerInfoEXT init = vkiDisplayPowerInfoEXT_null();
		init.powerState = powerState;
		return init;
	}

	static inline VkDeviceEventInfoEXT vkiDeviceEventInfoEXT_null()
	{
		VkDeviceEventInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT;
		return init;
	}

	static inline VkDeviceEventInfoEXT vkiDeviceEventInfoEXT(VkDeviceEventTypeEXT deviceEvent)
	{
		VkDeviceEventInfoEXT init = vkiDeviceEventInfoEXT_null();
		init.deviceEvent = deviceEvent;
		return init;
	}

	static inline VkDisplayEventInfoEXT vkiDisplayEventInfoEXT_null()
	{
		VkDisplayEventInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT;
		return init;
	}

	static inline VkDisplayEventInfoEXT vkiDisplayEventInfoEXT(VkDisplayEventTypeEXT displayEvent)
	{
		VkDisplayEventInfoEXT init = vkiDisplayEventInfoEXT_null();
		init.displayEvent = displayEvent;
		return init;
	}

	static inline VkSwapchainCounterCreateInfoEXT vkiSwapchainCounterCreateInfoEXT_null()
	{
		VkSwapchainCounterCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT;
		return init;
	}

	static inline VkSwapchainCounterCreateInfoEXT vkiSwapchainCounterCreateInfoEXT(VkSurfaceCounterFlagsEXT surfaceCounters)
	{
		VkSwapchainCounterCreateInfoEXT init = vkiSwapchainCounterCreateInfoEXT_null();
		init.surfaceCounters = surfaceCounters;
		return init;
	}

	static inline VkRefreshCycleDurationGOOGLE vkiRefreshCycleDurationGOOGLE_null()
	{
		VkRefreshCycleDurationGOOGLE init = {0};
		return init;
	}

	static inline VkRefreshCycleDurationGOOGLE vkiRefreshCycleDurationGOOGLE(uint64_t refreshDuration)
	{
		VkRefreshCycleDurationGOOGLE init = vkiRefreshCycleDurationGOOGLE_null();
		init.refreshDuration = refreshDuration;
		return init;
	}

	static inline VkPastPresentationTimingGOOGLE vkiPastPresentationTimingGOOGLE_null()
	{
		VkPastPresentationTimingGOOGLE init = {0};
		return init;
	}

	static inline VkPastPresentationTimingGOOGLE vkiPastPresentationTimingGOOGLE(uint32_t presentID, uint64_t desiredPresentTime, uint64_t actualPresentTime, uint64_t earliestPresentTime, uint64_t presentMargin)
	{
		VkPastPresentationTimingGOOGLE init = vkiPastPresentationTimingGOOGLE_null();
		init.presentID = presentID;
		init.desiredPresentTime = desiredPresentTime;
		init.actualPresentTime = actualPresentTime;
		init.earliestPresentTime = earliestPresentTime;
		init.presentMargin = presentMargin;
		return init;
	}

	static inline VkPresentTimeGOOGLE vkiPresentTimeGOOGLE_null()
	{
		VkPresentTimeGOOGLE init = {0};
		return init;
	}

	static inline VkPresentTimeGOOGLE vkiPresentTimeGOOGLE(uint32_t presentID, uint64_t desiredPresentTime)
	{
		VkPresentTimeGOOGLE init = vkiPresentTimeGOOGLE_null();
		init.presentID = presentID;
		init.desiredPresentTime = desiredPresentTime;
		return init;
	}

	static inline VkPresentTimesInfoGOOGLE vkiPresentTimesInfoGOOGLE_null()
	{
		VkPresentTimesInfoGOOGLE init = {0};
		init.sType = VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE;
		return init;
	}

	static inline VkPresentTimesInfoGOOGLE vkiPresentTimesInfoGOOGLE(uint32_t swapchainCount, const VkPresentTimeGOOGLE *pTimes)
	{
		VkPresentTimesInfoGOOGLE init = vkiPresentTimesInfoGOOGLE_null();
		init.swapchainCount = swapchainCount;
		init.pTimes = pTimes;
		return init;
	}

	static inline VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX vkiPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX_null()
	{
		VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX;
		return init;
	}

	static inline VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX vkiPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(VkBool32 perViewPositionAllComponents)
	{
		VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX init = vkiPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX_null();
		init.perViewPositionAllComponents = perViewPositionAllComponents;
		return init;
	}

	static inline VkViewportSwizzleNV vkiViewportSwizzleNV_null()
	{
		VkViewportSwizzleNV init = {0};
		return init;
	}

	static inline VkViewportSwizzleNV vkiViewportSwizzleNV(VkViewportCoordinateSwizzleNV x, VkViewportCoordinateSwizzleNV y, VkViewportCoordinateSwizzleNV z, VkViewportCoordinateSwizzleNV w)
	{
		VkViewportSwizzleNV init = vkiViewportSwizzleNV_null();
		init.x = x;
		init.y = y;
		init.z = z;
		init.w = w;
		return init;
	}

	static inline VkPipelineViewportSwizzleStateCreateInfoNV vkiPipelineViewportSwizzleStateCreateInfoNV_null()
	{
		VkPipelineViewportSwizzleStateCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV;
		return init;
	}

	static inline VkPipelineViewportSwizzleStateCreateInfoNV vkiPipelineViewportSwizzleStateCreateInfoNV(uint32_t viewportCount, const VkViewportSwizzleNV *pViewportSwizzles)
	{
		VkPipelineViewportSwizzleStateCreateInfoNV init = vkiPipelineViewportSwizzleStateCreateInfoNV_null();
		init.viewportCount = viewportCount;
		init.pViewportSwizzles = pViewportSwizzles;
		return init;
	}

	static inline VkPhysicalDeviceDiscardRectanglePropertiesEXT vkiPhysicalDeviceDiscardRectanglePropertiesEXT_null()
	{
		VkPhysicalDeviceDiscardRectanglePropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceDiscardRectanglePropertiesEXT vkiPhysicalDeviceDiscardRectanglePropertiesEXT(uint32_t maxDiscardRectangles)
	{
		VkPhysicalDeviceDiscardRectanglePropertiesEXT init = vkiPhysicalDeviceDiscardRectanglePropertiesEXT_null();
		init.maxDiscardRectangles = maxDiscardRectangles;
		return init;
	}

	static inline VkPipelineDiscardRectangleStateCreateInfoEXT vkiPipelineDiscardRectangleStateCreateInfoEXT_null()
	{
		VkPipelineDiscardRectangleStateCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT;
		return init;
	}

	static inline VkPipelineDiscardRectangleStateCreateInfoEXT vkiPipelineDiscardRectangleStateCreateInfoEXT(VkDiscardRectangleModeEXT discardRectangleMode, uint32_t discardRectangleCount, const VkRect2D *pDiscardRectangles)
	{
		VkPipelineDiscardRectangleStateCreateInfoEXT init = vkiPipelineDiscardRectangleStateCreateInfoEXT_null();
		init.discardRectangleMode = discardRectangleMode;
		init.discardRectangleCount = discardRectangleCount;
		init.pDiscardRectangles = pDiscardRectangles;
		return init;
	}

	static inline VkPhysicalDeviceConservativeRasterizationPropertiesEXT vkiPhysicalDeviceConservativeRasterizationPropertiesEXT_null()
	{
		VkPhysicalDeviceConservativeRasterizationPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceConservativeRasterizationPropertiesEXT vkiPhysicalDeviceConservativeRasterizationPropertiesEXT(float primitiveOverestimationSize, float maxExtraPrimitiveOverestimationSize, float extraPrimitiveOverestimationSizeGranularity, VkBool32 primitiveUnderestimation, VkBool32 conservativePointAndLineRasterization, VkBool32 degenerateTrianglesRasterized, VkBool32 degenerateLinesRasterized, VkBool32 fullyCoveredFragmentShaderInputVariable, VkBool32 conservativeRasterizationPostDepthCoverage)
	{
		VkPhysicalDeviceConservativeRasterizationPropertiesEXT init = vkiPhysicalDeviceConservativeRasterizationPropertiesEXT_null();
		init.primitiveOverestimationSize = primitiveOverestimationSize;
		init.maxExtraPrimitiveOverestimationSize = maxExtraPrimitiveOverestimationSize;
		init.extraPrimitiveOverestimationSizeGranularity = extraPrimitiveOverestimationSizeGranularity;
		init.primitiveUnderestimation = primitiveUnderestimation;
		init.conservativePointAndLineRasterization = conservativePointAndLineRasterization;
		init.degenerateTrianglesRasterized = degenerateTrianglesRasterized;
		init.degenerateLinesRasterized = degenerateLinesRasterized;
		init.fullyCoveredFragmentShaderInputVariable = fullyCoveredFragmentShaderInputVariable;
		init.conservativeRasterizationPostDepthCoverage = conservativeRasterizationPostDepthCoverage;
		return init;
	}

	static inline VkPipelineRasterizationConservativeStateCreateInfoEXT vkiPipelineRasterizationConservativeStateCreateInfoEXT_null()
	{
		VkPipelineRasterizationConservativeStateCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT;
		return init;
	}

	static inline VkPipelineRasterizationConservativeStateCreateInfoEXT vkiPipelineRasterizationConservativeStateCreateInfoEXT(VkConservativeRasterizationModeEXT conservativeRasterizationMode, float extraPrimitiveOverestimationSize)
	{
		VkPipelineRasterizationConservativeStateCreateInfoEXT init = vkiPipelineRasterizationConservativeStateCreateInfoEXT_null();
		init.conservativeRasterizationMode = conservativeRasterizationMode;
		init.extraPrimitiveOverestimationSize = extraPrimitiveOverestimationSize;
		return init;
	}

	static inline VkPhysicalDeviceDepthClipEnableFeaturesEXT vkiPhysicalDeviceDepthClipEnableFeaturesEXT_null()
	{
		VkPhysicalDeviceDepthClipEnableFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceDepthClipEnableFeaturesEXT vkiPhysicalDeviceDepthClipEnableFeaturesEXT(VkBool32 depthClipEnable)
	{
		VkPhysicalDeviceDepthClipEnableFeaturesEXT init = vkiPhysicalDeviceDepthClipEnableFeaturesEXT_null();
		init.depthClipEnable = depthClipEnable;
		return init;
	}

	static inline VkPipelineRasterizationDepthClipStateCreateInfoEXT vkiPipelineRasterizationDepthClipStateCreateInfoEXT_null()
	{
		VkPipelineRasterizationDepthClipStateCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT;
		return init;
	}

	static inline VkPipelineRasterizationDepthClipStateCreateInfoEXT vkiPipelineRasterizationDepthClipStateCreateInfoEXT(VkBool32 depthClipEnable)
	{
		VkPipelineRasterizationDepthClipStateCreateInfoEXT init = vkiPipelineRasterizationDepthClipStateCreateInfoEXT_null();
		init.depthClipEnable = depthClipEnable;
		return init;
	}

	static inline VkXYColorEXT vkiXYColorEXT_null()
	{
		VkXYColorEXT init = {0};
		return init;
	}

	static inline VkXYColorEXT vkiXYColorEXT(float x, float y)
	{
		VkXYColorEXT init = vkiXYColorEXT_null();
		init.x = x;
		init.y = y;
		return init;
	}

	static inline VkHdrMetadataEXT vkiHdrMetadataEXT_null()
	{
		VkHdrMetadataEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_HDR_METADATA_EXT;
		return init;
	}

	static inline VkHdrMetadataEXT vkiHdrMetadataEXT(VkXYColorEXT displayPrimaryRed, VkXYColorEXT displayPrimaryGreen, VkXYColorEXT displayPrimaryBlue, VkXYColorEXT whitePoint, float maxLuminance, float minLuminance, float maxContentLightLevel, float maxFrameAverageLightLevel)
	{
		VkHdrMetadataEXT init = vkiHdrMetadataEXT_null();
		init.displayPrimaryRed = displayPrimaryRed;
		init.displayPrimaryGreen = displayPrimaryGreen;
		init.displayPrimaryBlue = displayPrimaryBlue;
		init.whitePoint = whitePoint;
		init.maxLuminance = maxLuminance;
		init.minLuminance = minLuminance;
		init.maxContentLightLevel = maxContentLightLevel;
		init.maxFrameAverageLightLevel = maxFrameAverageLightLevel;
		return init;
	}

	static inline VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG vkiPhysicalDeviceRelaxedLineRasterizationFeaturesIMG_null()
	{
		VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG;
		return init;
	}

	static inline VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG vkiPhysicalDeviceRelaxedLineRasterizationFeaturesIMG(VkBool32 relaxedLineRasterization)
	{
		VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG init = vkiPhysicalDeviceRelaxedLineRasterizationFeaturesIMG_null();
		init.relaxedLineRasterization = relaxedLineRasterization;
		return init;
	}

	static inline VkDebugUtilsLabelEXT vkiDebugUtilsLabelEXT_null()
	{
		VkDebugUtilsLabelEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT;
		return init;
	}

	static inline VkDebugUtilsLabelEXT vkiDebugUtilsLabelEXT(const char *pLabelName)
	{
		VkDebugUtilsLabelEXT init = vkiDebugUtilsLabelEXT_null();
		init.pLabelName = pLabelName;
		return init;
	}

	static inline VkDebugUtilsObjectNameInfoEXT vkiDebugUtilsObjectNameInfoEXT_null()
	{
		VkDebugUtilsObjectNameInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT;
		return init;
	}

	static inline VkDebugUtilsObjectNameInfoEXT vkiDebugUtilsObjectNameInfoEXT(VkObjectType objectType, uint64_t objectHandle, const char *pObjectName)
	{
		VkDebugUtilsObjectNameInfoEXT init = vkiDebugUtilsObjectNameInfoEXT_null();
		init.objectType = objectType;
		init.objectHandle = objectHandle;
		init.pObjectName = pObjectName;
		return init;
	}

	static inline VkDebugUtilsMessengerCallbackDataEXT vkiDebugUtilsMessengerCallbackDataEXT_null()
	{
		VkDebugUtilsMessengerCallbackDataEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT;
		return init;
	}

	static inline VkDebugUtilsMessengerCallbackDataEXT vkiDebugUtilsMessengerCallbackDataEXT(const char *pMessageIdName, int32_t messageIdNumber, const char *pMessage, uint32_t queueLabelCount, const VkDebugUtilsLabelEXT *pQueueLabels, uint32_t cmdBufLabelCount, const VkDebugUtilsLabelEXT *pCmdBufLabels, uint32_t objectCount, const VkDebugUtilsObjectNameInfoEXT *pObjects)
	{
		VkDebugUtilsMessengerCallbackDataEXT init = vkiDebugUtilsMessengerCallbackDataEXT_null();
		init.pMessageIdName = pMessageIdName;
		init.messageIdNumber = messageIdNumber;
		init.pMessage = pMessage;
		init.queueLabelCount = queueLabelCount;
		init.pQueueLabels = pQueueLabels;
		init.cmdBufLabelCount = cmdBufLabelCount;
		init.pCmdBufLabels = pCmdBufLabels;
		init.objectCount = objectCount;
		init.pObjects = pObjects;
		return init;
	}

	static inline VkDebugUtilsMessengerCreateInfoEXT vkiDebugUtilsMessengerCreateInfoEXT_null()
	{
		VkDebugUtilsMessengerCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		return init;
	}

	static inline VkDebugUtilsMessengerCreateInfoEXT vkiDebugUtilsMessengerCreateInfoEXT(VkDebugUtilsMessageSeverityFlagsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, PFN_vkDebugUtilsMessengerCallbackEXT pfnUserCallback, void *pUserData)
	{
		VkDebugUtilsMessengerCreateInfoEXT init = vkiDebugUtilsMessengerCreateInfoEXT_null();
		init.messageSeverity = messageSeverity;
		init.messageType = messageType;
		init.pfnUserCallback = pfnUserCallback;
		init.pUserData = pUserData;
		return init;
	}

	static inline VkDebugUtilsObjectTagInfoEXT vkiDebugUtilsObjectTagInfoEXT_null()
	{
		VkDebugUtilsObjectTagInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT;
		return init;
	}

	static inline VkDebugUtilsObjectTagInfoEXT vkiDebugUtilsObjectTagInfoEXT(VkObjectType objectType, uint64_t objectHandle, uint64_t tagName, size_t tagSize, const void *pTag)
	{
		VkDebugUtilsObjectTagInfoEXT init = vkiDebugUtilsObjectTagInfoEXT_null();
		init.objectType = objectType;
		init.objectHandle = objectHandle;
		init.tagName = tagName;
		init.tagSize = tagSize;
		init.pTag = pTag;
		return init;
	}

	static inline VkSampleLocationEXT vkiSampleLocationEXT_null()
	{
		VkSampleLocationEXT init = {0};
		return init;
	}

	static inline VkSampleLocationEXT vkiSampleLocationEXT(float x, float y)
	{
		VkSampleLocationEXT init = vkiSampleLocationEXT_null();
		init.x = x;
		init.y = y;
		return init;
	}

	static inline VkSampleLocationsInfoEXT vkiSampleLocationsInfoEXT_null()
	{
		VkSampleLocationsInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT;
		return init;
	}

	static inline VkSampleLocationsInfoEXT vkiSampleLocationsInfoEXT(VkSampleCountFlagBits sampleLocationsPerPixel, VkExtent2D sampleLocationGridSize, uint32_t sampleLocationsCount, const VkSampleLocationEXT *pSampleLocations)
	{
		VkSampleLocationsInfoEXT init = vkiSampleLocationsInfoEXT_null();
		init.sampleLocationsPerPixel = sampleLocationsPerPixel;
		init.sampleLocationGridSize = sampleLocationGridSize;
		init.sampleLocationsCount = sampleLocationsCount;
		init.pSampleLocations = pSampleLocations;
		return init;
	}

	static inline VkAttachmentSampleLocationsEXT vkiAttachmentSampleLocationsEXT_null()
	{
		VkAttachmentSampleLocationsEXT init = {0};
		return init;
	}

	static inline VkAttachmentSampleLocationsEXT vkiAttachmentSampleLocationsEXT(uint32_t attachmentIndex, VkSampleLocationsInfoEXT sampleLocationsInfo)
	{
		VkAttachmentSampleLocationsEXT init = vkiAttachmentSampleLocationsEXT_null();
		init.attachmentIndex = attachmentIndex;
		init.sampleLocationsInfo = sampleLocationsInfo;
		return init;
	}

	static inline VkSubpassSampleLocationsEXT vkiSubpassSampleLocationsEXT_null()
	{
		VkSubpassSampleLocationsEXT init = {0};
		return init;
	}

	static inline VkSubpassSampleLocationsEXT vkiSubpassSampleLocationsEXT(uint32_t subpassIndex, VkSampleLocationsInfoEXT sampleLocationsInfo)
	{
		VkSubpassSampleLocationsEXT init = vkiSubpassSampleLocationsEXT_null();
		init.subpassIndex = subpassIndex;
		init.sampleLocationsInfo = sampleLocationsInfo;
		return init;
	}

	static inline VkRenderPassSampleLocationsBeginInfoEXT vkiRenderPassSampleLocationsBeginInfoEXT_null()
	{
		VkRenderPassSampleLocationsBeginInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT;
		return init;
	}

	static inline VkRenderPassSampleLocationsBeginInfoEXT vkiRenderPassSampleLocationsBeginInfoEXT(uint32_t attachmentInitialSampleLocationsCount, const VkAttachmentSampleLocationsEXT *pAttachmentInitialSampleLocations, uint32_t postSubpassSampleLocationsCount, const VkSubpassSampleLocationsEXT *pPostSubpassSampleLocations)
	{
		VkRenderPassSampleLocationsBeginInfoEXT init = vkiRenderPassSampleLocationsBeginInfoEXT_null();
		init.attachmentInitialSampleLocationsCount = attachmentInitialSampleLocationsCount;
		init.pAttachmentInitialSampleLocations = pAttachmentInitialSampleLocations;
		init.postSubpassSampleLocationsCount = postSubpassSampleLocationsCount;
		init.pPostSubpassSampleLocations = pPostSubpassSampleLocations;
		return init;
	}

	static inline VkPipelineSampleLocationsStateCreateInfoEXT vkiPipelineSampleLocationsStateCreateInfoEXT_null()
	{
		VkPipelineSampleLocationsStateCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT;
		return init;
	}

	static inline VkPipelineSampleLocationsStateCreateInfoEXT vkiPipelineSampleLocationsStateCreateInfoEXT(VkBool32 sampleLocationsEnable, VkSampleLocationsInfoEXT sampleLocationsInfo)
	{
		VkPipelineSampleLocationsStateCreateInfoEXT init = vkiPipelineSampleLocationsStateCreateInfoEXT_null();
		init.sampleLocationsEnable = sampleLocationsEnable;
		init.sampleLocationsInfo = sampleLocationsInfo;
		return init;
	}

	static inline VkPhysicalDeviceSampleLocationsPropertiesEXT vkiPhysicalDeviceSampleLocationsPropertiesEXT_null()
	{
		VkPhysicalDeviceSampleLocationsPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceSampleLocationsPropertiesEXT vkiPhysicalDeviceSampleLocationsPropertiesEXT(VkSampleCountFlags sampleLocationSampleCounts, VkExtent2D maxSampleLocationGridSize, uint32_t sampleLocationSubPixelBits, VkBool32 variableSampleLocations)
	{
		VkPhysicalDeviceSampleLocationsPropertiesEXT init = vkiPhysicalDeviceSampleLocationsPropertiesEXT_null();
		init.sampleLocationSampleCounts = sampleLocationSampleCounts;
		init.maxSampleLocationGridSize = maxSampleLocationGridSize;
		init.sampleLocationSubPixelBits = sampleLocationSubPixelBits;
		init.variableSampleLocations = variableSampleLocations;
		return init;
	}

	static inline VkMultisamplePropertiesEXT vkiMultisamplePropertiesEXT_null()
	{
		VkMultisamplePropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT;
		return init;
	}

	static inline VkMultisamplePropertiesEXT vkiMultisamplePropertiesEXT(VkExtent2D maxSampleLocationGridSize)
	{
		VkMultisamplePropertiesEXT init = vkiMultisamplePropertiesEXT_null();
		init.maxSampleLocationGridSize = maxSampleLocationGridSize;
		return init;
	}

	static inline VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT vkiPhysicalDeviceBlendOperationAdvancedFeaturesEXT_null()
	{
		VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT vkiPhysicalDeviceBlendOperationAdvancedFeaturesEXT(VkBool32 advancedBlendCoherentOperations)
	{
		VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT init = vkiPhysicalDeviceBlendOperationAdvancedFeaturesEXT_null();
		init.advancedBlendCoherentOperations = advancedBlendCoherentOperations;
		return init;
	}

	static inline VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT vkiPhysicalDeviceBlendOperationAdvancedPropertiesEXT_null()
	{
		VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT vkiPhysicalDeviceBlendOperationAdvancedPropertiesEXT(uint32_t advancedBlendMaxColorAttachments, VkBool32 advancedBlendIndependentBlend, VkBool32 advancedBlendNonPremultipliedSrcColor, VkBool32 advancedBlendNonPremultipliedDstColor, VkBool32 advancedBlendCorrelatedOverlap, VkBool32 advancedBlendAllOperations)
	{
		VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT init = vkiPhysicalDeviceBlendOperationAdvancedPropertiesEXT_null();
		init.advancedBlendMaxColorAttachments = advancedBlendMaxColorAttachments;
		init.advancedBlendIndependentBlend = advancedBlendIndependentBlend;
		init.advancedBlendNonPremultipliedSrcColor = advancedBlendNonPremultipliedSrcColor;
		init.advancedBlendNonPremultipliedDstColor = advancedBlendNonPremultipliedDstColor;
		init.advancedBlendCorrelatedOverlap = advancedBlendCorrelatedOverlap;
		init.advancedBlendAllOperations = advancedBlendAllOperations;
		return init;
	}

	static inline VkPipelineColorBlendAdvancedStateCreateInfoEXT vkiPipelineColorBlendAdvancedStateCreateInfoEXT_null()
	{
		VkPipelineColorBlendAdvancedStateCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT;
		return init;
	}

	static inline VkPipelineColorBlendAdvancedStateCreateInfoEXT vkiPipelineColorBlendAdvancedStateCreateInfoEXT(VkBool32 srcPremultiplied, VkBool32 dstPremultiplied, VkBlendOverlapEXT blendOverlap)
	{
		VkPipelineColorBlendAdvancedStateCreateInfoEXT init = vkiPipelineColorBlendAdvancedStateCreateInfoEXT_null();
		init.srcPremultiplied = srcPremultiplied;
		init.dstPremultiplied = dstPremultiplied;
		init.blendOverlap = blendOverlap;
		return init;
	}

	static inline VkPipelineCoverageToColorStateCreateInfoNV vkiPipelineCoverageToColorStateCreateInfoNV_null()
	{
		VkPipelineCoverageToColorStateCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV;
		return init;
	}

	static inline VkPipelineCoverageToColorStateCreateInfoNV vkiPipelineCoverageToColorStateCreateInfoNV(VkBool32 coverageToColorEnable, uint32_t coverageToColorLocation)
	{
		VkPipelineCoverageToColorStateCreateInfoNV init = vkiPipelineCoverageToColorStateCreateInfoNV_null();
		init.coverageToColorEnable = coverageToColorEnable;
		init.coverageToColorLocation = coverageToColorLocation;
		return init;
	}

	static inline VkPipelineCoverageModulationStateCreateInfoNV vkiPipelineCoverageModulationStateCreateInfoNV_null()
	{
		VkPipelineCoverageModulationStateCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV;
		return init;
	}

	static inline VkPipelineCoverageModulationStateCreateInfoNV vkiPipelineCoverageModulationStateCreateInfoNV(VkCoverageModulationModeNV coverageModulationMode, VkBool32 coverageModulationTableEnable, uint32_t coverageModulationTableCount, const float *pCoverageModulationTable)
	{
		VkPipelineCoverageModulationStateCreateInfoNV init = vkiPipelineCoverageModulationStateCreateInfoNV_null();
		init.coverageModulationMode = coverageModulationMode;
		init.coverageModulationTableEnable = coverageModulationTableEnable;
		init.coverageModulationTableCount = coverageModulationTableCount;
		init.pCoverageModulationTable = pCoverageModulationTable;
		return init;
	}

	static inline VkPhysicalDeviceShaderSMBuiltinsPropertiesNV vkiPhysicalDeviceShaderSMBuiltinsPropertiesNV_null()
	{
		VkPhysicalDeviceShaderSMBuiltinsPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV;
		return init;
	}

	static inline VkPhysicalDeviceShaderSMBuiltinsPropertiesNV vkiPhysicalDeviceShaderSMBuiltinsPropertiesNV(uint32_t shaderSMCount, uint32_t shaderWarpsPerSM)
	{
		VkPhysicalDeviceShaderSMBuiltinsPropertiesNV init = vkiPhysicalDeviceShaderSMBuiltinsPropertiesNV_null();
		init.shaderSMCount = shaderSMCount;
		init.shaderWarpsPerSM = shaderWarpsPerSM;
		return init;
	}

	static inline VkPhysicalDeviceShaderSMBuiltinsFeaturesNV vkiPhysicalDeviceShaderSMBuiltinsFeaturesNV_null()
	{
		VkPhysicalDeviceShaderSMBuiltinsFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceShaderSMBuiltinsFeaturesNV vkiPhysicalDeviceShaderSMBuiltinsFeaturesNV(VkBool32 shaderSMBuiltins)
	{
		VkPhysicalDeviceShaderSMBuiltinsFeaturesNV init = vkiPhysicalDeviceShaderSMBuiltinsFeaturesNV_null();
		init.shaderSMBuiltins = shaderSMBuiltins;
		return init;
	}

	static inline VkDrmFormatModifierPropertiesEXT vkiDrmFormatModifierPropertiesEXT_null()
	{
		VkDrmFormatModifierPropertiesEXT init = {0};
		return init;
	}

	static inline VkDrmFormatModifierPropertiesEXT vkiDrmFormatModifierPropertiesEXT(uint64_t drmFormatModifier, uint32_t drmFormatModifierPlaneCount, VkFormatFeatureFlags drmFormatModifierTilingFeatures)
	{
		VkDrmFormatModifierPropertiesEXT init = vkiDrmFormatModifierPropertiesEXT_null();
		init.drmFormatModifier = drmFormatModifier;
		init.drmFormatModifierPlaneCount = drmFormatModifierPlaneCount;
		init.drmFormatModifierTilingFeatures = drmFormatModifierTilingFeatures;
		return init;
	}

	static inline VkDrmFormatModifierPropertiesListEXT vkiDrmFormatModifierPropertiesListEXT_null()
	{
		VkDrmFormatModifierPropertiesListEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT;
		return init;
	}

	static inline VkDrmFormatModifierPropertiesListEXT vkiDrmFormatModifierPropertiesListEXT(uint32_t drmFormatModifierCount, VkDrmFormatModifierPropertiesEXT *pDrmFormatModifierProperties)
	{
		VkDrmFormatModifierPropertiesListEXT init = vkiDrmFormatModifierPropertiesListEXT_null();
		init.drmFormatModifierCount = drmFormatModifierCount;
		init.pDrmFormatModifierProperties = pDrmFormatModifierProperties;
		return init;
	}

	static inline VkPhysicalDeviceImageDrmFormatModifierInfoEXT vkiPhysicalDeviceImageDrmFormatModifierInfoEXT_null()
	{
		VkPhysicalDeviceImageDrmFormatModifierInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT;
		return init;
	}

	static inline VkPhysicalDeviceImageDrmFormatModifierInfoEXT vkiPhysicalDeviceImageDrmFormatModifierInfoEXT(uint64_t drmFormatModifier, VkSharingMode sharingMode, uint32_t queueFamilyIndexCount, const uint32_t *pQueueFamilyIndices)
	{
		VkPhysicalDeviceImageDrmFormatModifierInfoEXT init = vkiPhysicalDeviceImageDrmFormatModifierInfoEXT_null();
		init.drmFormatModifier = drmFormatModifier;
		init.sharingMode = sharingMode;
		init.queueFamilyIndexCount = queueFamilyIndexCount;
		init.pQueueFamilyIndices = pQueueFamilyIndices;
		return init;
	}

	static inline VkImageDrmFormatModifierListCreateInfoEXT vkiImageDrmFormatModifierListCreateInfoEXT_null()
	{
		VkImageDrmFormatModifierListCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT;
		return init;
	}

	static inline VkImageDrmFormatModifierListCreateInfoEXT vkiImageDrmFormatModifierListCreateInfoEXT(uint32_t drmFormatModifierCount, const uint64_t *pDrmFormatModifiers)
	{
		VkImageDrmFormatModifierListCreateInfoEXT init = vkiImageDrmFormatModifierListCreateInfoEXT_null();
		init.drmFormatModifierCount = drmFormatModifierCount;
		init.pDrmFormatModifiers = pDrmFormatModifiers;
		return init;
	}

	static inline VkImageDrmFormatModifierExplicitCreateInfoEXT vkiImageDrmFormatModifierExplicitCreateInfoEXT_null()
	{
		VkImageDrmFormatModifierExplicitCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT;
		return init;
	}

	static inline VkImageDrmFormatModifierExplicitCreateInfoEXT vkiImageDrmFormatModifierExplicitCreateInfoEXT(uint64_t drmFormatModifier, uint32_t drmFormatModifierPlaneCount, const VkSubresourceLayout *pPlaneLayouts)
	{
		VkImageDrmFormatModifierExplicitCreateInfoEXT init = vkiImageDrmFormatModifierExplicitCreateInfoEXT_null();
		init.drmFormatModifier = drmFormatModifier;
		init.drmFormatModifierPlaneCount = drmFormatModifierPlaneCount;
		init.pPlaneLayouts = pPlaneLayouts;
		return init;
	}

	static inline VkImageDrmFormatModifierPropertiesEXT vkiImageDrmFormatModifierPropertiesEXT_null()
	{
		VkImageDrmFormatModifierPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT;
		return init;
	}

	static inline VkImageDrmFormatModifierPropertiesEXT vkiImageDrmFormatModifierPropertiesEXT(uint64_t drmFormatModifier)
	{
		VkImageDrmFormatModifierPropertiesEXT init = vkiImageDrmFormatModifierPropertiesEXT_null();
		init.drmFormatModifier = drmFormatModifier;
		return init;
	}

	static inline VkDrmFormatModifierProperties2EXT vkiDrmFormatModifierProperties2EXT_null()
	{
		VkDrmFormatModifierProperties2EXT init = {0};
		return init;
	}

	static inline VkDrmFormatModifierProperties2EXT vkiDrmFormatModifierProperties2EXT(uint64_t drmFormatModifier, uint32_t drmFormatModifierPlaneCount, VkFormatFeatureFlags2 drmFormatModifierTilingFeatures)
	{
		VkDrmFormatModifierProperties2EXT init = vkiDrmFormatModifierProperties2EXT_null();
		init.drmFormatModifier = drmFormatModifier;
		init.drmFormatModifierPlaneCount = drmFormatModifierPlaneCount;
		init.drmFormatModifierTilingFeatures = drmFormatModifierTilingFeatures;
		return init;
	}

	static inline VkDrmFormatModifierPropertiesList2EXT vkiDrmFormatModifierPropertiesList2EXT_null()
	{
		VkDrmFormatModifierPropertiesList2EXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT;
		return init;
	}

	static inline VkDrmFormatModifierPropertiesList2EXT vkiDrmFormatModifierPropertiesList2EXT(uint32_t drmFormatModifierCount, VkDrmFormatModifierProperties2EXT *pDrmFormatModifierProperties)
	{
		VkDrmFormatModifierPropertiesList2EXT init = vkiDrmFormatModifierPropertiesList2EXT_null();
		init.drmFormatModifierCount = drmFormatModifierCount;
		init.pDrmFormatModifierProperties = pDrmFormatModifierProperties;
		return init;
	}

	static inline VkValidationCacheCreateInfoEXT vkiValidationCacheCreateInfoEXT_null()
	{
		VkValidationCacheCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT;
		return init;
	}

	static inline VkValidationCacheCreateInfoEXT vkiValidationCacheCreateInfoEXT(size_t initialDataSize, const void *pInitialData)
	{
		VkValidationCacheCreateInfoEXT init = vkiValidationCacheCreateInfoEXT_null();
		init.initialDataSize = initialDataSize;
		init.pInitialData = pInitialData;
		return init;
	}

	static inline VkShaderModuleValidationCacheCreateInfoEXT vkiShaderModuleValidationCacheCreateInfoEXT_null()
	{
		VkShaderModuleValidationCacheCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT;
		return init;
	}

	static inline VkShaderModuleValidationCacheCreateInfoEXT vkiShaderModuleValidationCacheCreateInfoEXT(VkValidationCacheEXT validationCache)
	{
		VkShaderModuleValidationCacheCreateInfoEXT init = vkiShaderModuleValidationCacheCreateInfoEXT_null();
		init.validationCache = validationCache;
		return init;
	}

	static inline VkShadingRatePaletteNV vkiShadingRatePaletteNV_null()
	{
		VkShadingRatePaletteNV init = {0};
		return init;
	}

	static inline VkShadingRatePaletteNV vkiShadingRatePaletteNV(uint32_t shadingRatePaletteEntryCount, const VkShadingRatePaletteEntryNV *pShadingRatePaletteEntries)
	{
		VkShadingRatePaletteNV init = vkiShadingRatePaletteNV_null();
		init.shadingRatePaletteEntryCount = shadingRatePaletteEntryCount;
		init.pShadingRatePaletteEntries = pShadingRatePaletteEntries;
		return init;
	}

	static inline VkPipelineViewportShadingRateImageStateCreateInfoNV vkiPipelineViewportShadingRateImageStateCreateInfoNV_null()
	{
		VkPipelineViewportShadingRateImageStateCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV;
		return init;
	}

	static inline VkPipelineViewportShadingRateImageStateCreateInfoNV vkiPipelineViewportShadingRateImageStateCreateInfoNV(VkBool32 shadingRateImageEnable, uint32_t viewportCount, const VkShadingRatePaletteNV *pShadingRatePalettes)
	{
		VkPipelineViewportShadingRateImageStateCreateInfoNV init = vkiPipelineViewportShadingRateImageStateCreateInfoNV_null();
		init.shadingRateImageEnable = shadingRateImageEnable;
		init.viewportCount = viewportCount;
		init.pShadingRatePalettes = pShadingRatePalettes;
		return init;
	}

	static inline VkPhysicalDeviceShadingRateImageFeaturesNV vkiPhysicalDeviceShadingRateImageFeaturesNV_null()
	{
		VkPhysicalDeviceShadingRateImageFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceShadingRateImageFeaturesNV vkiPhysicalDeviceShadingRateImageFeaturesNV(VkBool32 shadingRateImage, VkBool32 shadingRateCoarseSampleOrder)
	{
		VkPhysicalDeviceShadingRateImageFeaturesNV init = vkiPhysicalDeviceShadingRateImageFeaturesNV_null();
		init.shadingRateImage = shadingRateImage;
		init.shadingRateCoarseSampleOrder = shadingRateCoarseSampleOrder;
		return init;
	}

	static inline VkPhysicalDeviceShadingRateImagePropertiesNV vkiPhysicalDeviceShadingRateImagePropertiesNV_null()
	{
		VkPhysicalDeviceShadingRateImagePropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV;
		return init;
	}

	static inline VkPhysicalDeviceShadingRateImagePropertiesNV vkiPhysicalDeviceShadingRateImagePropertiesNV(VkExtent2D shadingRateTexelSize, uint32_t shadingRatePaletteSize, uint32_t shadingRateMaxCoarseSamples)
	{
		VkPhysicalDeviceShadingRateImagePropertiesNV init = vkiPhysicalDeviceShadingRateImagePropertiesNV_null();
		init.shadingRateTexelSize = shadingRateTexelSize;
		init.shadingRatePaletteSize = shadingRatePaletteSize;
		init.shadingRateMaxCoarseSamples = shadingRateMaxCoarseSamples;
		return init;
	}

	static inline VkCoarseSampleLocationNV vkiCoarseSampleLocationNV_null()
	{
		VkCoarseSampleLocationNV init = {0};
		return init;
	}

	static inline VkCoarseSampleLocationNV vkiCoarseSampleLocationNV(uint32_t pixelX, uint32_t pixelY, uint32_t sample)
	{
		VkCoarseSampleLocationNV init = vkiCoarseSampleLocationNV_null();
		init.pixelX = pixelX;
		init.pixelY = pixelY;
		init.sample = sample;
		return init;
	}

	static inline VkCoarseSampleOrderCustomNV vkiCoarseSampleOrderCustomNV_null()
	{
		VkCoarseSampleOrderCustomNV init = {0};
		return init;
	}

	static inline VkCoarseSampleOrderCustomNV vkiCoarseSampleOrderCustomNV(VkShadingRatePaletteEntryNV shadingRate, uint32_t sampleCount, uint32_t sampleLocationCount, const VkCoarseSampleLocationNV *pSampleLocations)
	{
		VkCoarseSampleOrderCustomNV init = vkiCoarseSampleOrderCustomNV_null();
		init.shadingRate = shadingRate;
		init.sampleCount = sampleCount;
		init.sampleLocationCount = sampleLocationCount;
		init.pSampleLocations = pSampleLocations;
		return init;
	}

	static inline VkPipelineViewportCoarseSampleOrderStateCreateInfoNV vkiPipelineViewportCoarseSampleOrderStateCreateInfoNV_null()
	{
		VkPipelineViewportCoarseSampleOrderStateCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV;
		return init;
	}

	static inline VkPipelineViewportCoarseSampleOrderStateCreateInfoNV vkiPipelineViewportCoarseSampleOrderStateCreateInfoNV(VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV *pCustomSampleOrders)
	{
		VkPipelineViewportCoarseSampleOrderStateCreateInfoNV init = vkiPipelineViewportCoarseSampleOrderStateCreateInfoNV_null();
		init.sampleOrderType = sampleOrderType;
		init.customSampleOrderCount = customSampleOrderCount;
		init.pCustomSampleOrders = pCustomSampleOrders;
		return init;
	}

	static inline VkRayTracingShaderGroupCreateInfoNV vkiRayTracingShaderGroupCreateInfoNV_null()
	{
		VkRayTracingShaderGroupCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV;
		return init;
	}

	static inline VkRayTracingShaderGroupCreateInfoNV vkiRayTracingShaderGroupCreateInfoNV(VkRayTracingShaderGroupTypeKHR type, uint32_t generalShader, uint32_t closestHitShader, uint32_t anyHitShader, uint32_t intersectionShader)
	{
		VkRayTracingShaderGroupCreateInfoNV init = vkiRayTracingShaderGroupCreateInfoNV_null();
		init.type = type;
		init.generalShader = generalShader;
		init.closestHitShader = closestHitShader;
		init.anyHitShader = anyHitShader;
		init.intersectionShader = intersectionShader;
		return init;
	}

	static inline VkRayTracingPipelineCreateInfoNV vkiRayTracingPipelineCreateInfoNV_null()
	{
		VkRayTracingPipelineCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV;
		return init;
	}

	static inline VkRayTracingPipelineCreateInfoNV vkiRayTracingPipelineCreateInfoNV(uint32_t stageCount, const VkPipelineShaderStageCreateInfo *pStages, uint32_t groupCount, const VkRayTracingShaderGroupCreateInfoNV *pGroups, uint32_t maxRecursionDepth, VkPipelineLayout layout, VkPipeline basePipelineHandle, int32_t basePipelineIndex)
	{
		VkRayTracingPipelineCreateInfoNV init = vkiRayTracingPipelineCreateInfoNV_null();
		init.stageCount = stageCount;
		init.pStages = pStages;
		init.groupCount = groupCount;
		init.pGroups = pGroups;
		init.maxRecursionDepth = maxRecursionDepth;
		init.layout = layout;
		init.basePipelineHandle = basePipelineHandle;
		init.basePipelineIndex = basePipelineIndex;
		return init;
	}

	static inline VkGeometryTrianglesNV vkiGeometryTrianglesNV_null()
	{
		VkGeometryTrianglesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV;
		return init;
	}

	static inline VkGeometryTrianglesNV vkiGeometryTrianglesNV(VkBuffer vertexData, VkDeviceSize vertexOffset, uint32_t vertexCount, VkDeviceSize vertexStride, VkFormat vertexFormat, VkBuffer indexData, VkDeviceSize indexOffset, uint32_t indexCount, VkIndexType indexType, VkBuffer transformData, VkDeviceSize transformOffset)
	{
		VkGeometryTrianglesNV init = vkiGeometryTrianglesNV_null();
		init.vertexData = vertexData;
		init.vertexOffset = vertexOffset;
		init.vertexCount = vertexCount;
		init.vertexStride = vertexStride;
		init.vertexFormat = vertexFormat;
		init.indexData = indexData;
		init.indexOffset = indexOffset;
		init.indexCount = indexCount;
		init.indexType = indexType;
		init.transformData = transformData;
		init.transformOffset = transformOffset;
		return init;
	}

	static inline VkGeometryAABBNV vkiGeometryAABBNV_null()
	{
		VkGeometryAABBNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV;
		return init;
	}

	static inline VkGeometryAABBNV vkiGeometryAABBNV(VkBuffer aabbData, uint32_t numAABBs, uint32_t stride, VkDeviceSize offset)
	{
		VkGeometryAABBNV init = vkiGeometryAABBNV_null();
		init.aabbData = aabbData;
		init.numAABBs = numAABBs;
		init.stride = stride;
		init.offset = offset;
		return init;
	}

	static inline VkGeometryDataNV vkiGeometryDataNV_null()
	{
		VkGeometryDataNV init = {0};
		return init;
	}

	static inline VkGeometryDataNV vkiGeometryDataNV(VkGeometryTrianglesNV triangles, VkGeometryAABBNV aabbs)
	{
		VkGeometryDataNV init = vkiGeometryDataNV_null();
		init.triangles = triangles;
		init.aabbs = aabbs;
		return init;
	}

	static inline VkGeometryNV vkiGeometryNV_null()
	{
		VkGeometryNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_GEOMETRY_NV;
		return init;
	}

	static inline VkGeometryNV vkiGeometryNV(VkGeometryTypeKHR geometryType, VkGeometryDataNV geometry)
	{
		VkGeometryNV init = vkiGeometryNV_null();
		init.geometryType = geometryType;
		init.geometry = geometry;
		return init;
	}

	static inline VkAccelerationStructureInfoNV vkiAccelerationStructureInfoNV_null()
	{
		VkAccelerationStructureInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV;
		return init;
	}

	static inline VkAccelerationStructureInfoNV vkiAccelerationStructureInfoNV(VkAccelerationStructureTypeNV type, uint32_t instanceCount, uint32_t geometryCount, const VkGeometryNV *pGeometries)
	{
		VkAccelerationStructureInfoNV init = vkiAccelerationStructureInfoNV_null();
		init.type = type;
		init.instanceCount = instanceCount;
		init.geometryCount = geometryCount;
		init.pGeometries = pGeometries;
		return init;
	}

	static inline VkAccelerationStructureCreateInfoNV vkiAccelerationStructureCreateInfoNV_null()
	{
		VkAccelerationStructureCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV;
		return init;
	}

	static inline VkAccelerationStructureCreateInfoNV vkiAccelerationStructureCreateInfoNV(VkDeviceSize compactedSize, VkAccelerationStructureInfoNV info)
	{
		VkAccelerationStructureCreateInfoNV init = vkiAccelerationStructureCreateInfoNV_null();
		init.compactedSize = compactedSize;
		init.info = info;
		return init;
	}

	static inline VkBindAccelerationStructureMemoryInfoNV vkiBindAccelerationStructureMemoryInfoNV_null()
	{
		VkBindAccelerationStructureMemoryInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV;
		return init;
	}

	static inline VkBindAccelerationStructureMemoryInfoNV vkiBindAccelerationStructureMemoryInfoNV(VkAccelerationStructureNV accelerationStructure, VkDeviceMemory memory, VkDeviceSize memoryOffset, uint32_t deviceIndexCount, const uint32_t *pDeviceIndices)
	{
		VkBindAccelerationStructureMemoryInfoNV init = vkiBindAccelerationStructureMemoryInfoNV_null();
		init.accelerationStructure = accelerationStructure;
		init.memory = memory;
		init.memoryOffset = memoryOffset;
		init.deviceIndexCount = deviceIndexCount;
		init.pDeviceIndices = pDeviceIndices;
		return init;
	}

	static inline VkWriteDescriptorSetAccelerationStructureNV vkiWriteDescriptorSetAccelerationStructureNV_null()
	{
		VkWriteDescriptorSetAccelerationStructureNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV;
		return init;
	}

	static inline VkWriteDescriptorSetAccelerationStructureNV vkiWriteDescriptorSetAccelerationStructureNV(uint32_t accelerationStructureCount, const VkAccelerationStructureNV *pAccelerationStructures)
	{
		VkWriteDescriptorSetAccelerationStructureNV init = vkiWriteDescriptorSetAccelerationStructureNV_null();
		init.accelerationStructureCount = accelerationStructureCount;
		init.pAccelerationStructures = pAccelerationStructures;
		return init;
	}

	static inline VkAccelerationStructureMemoryRequirementsInfoNV vkiAccelerationStructureMemoryRequirementsInfoNV_null()
	{
		VkAccelerationStructureMemoryRequirementsInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV;
		return init;
	}

	static inline VkAccelerationStructureMemoryRequirementsInfoNV vkiAccelerationStructureMemoryRequirementsInfoNV(VkAccelerationStructureMemoryRequirementsTypeNV type, VkAccelerationStructureNV accelerationStructure)
	{
		VkAccelerationStructureMemoryRequirementsInfoNV init = vkiAccelerationStructureMemoryRequirementsInfoNV_null();
		init.type = type;
		init.accelerationStructure = accelerationStructure;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingPropertiesNV vkiPhysicalDeviceRayTracingPropertiesNV_null()
	{
		VkPhysicalDeviceRayTracingPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingPropertiesNV vkiPhysicalDeviceRayTracingPropertiesNV(uint32_t shaderGroupHandleSize, uint32_t maxRecursionDepth, uint32_t maxShaderGroupStride, uint32_t shaderGroupBaseAlignment, uint64_t maxGeometryCount, uint64_t maxInstanceCount, uint64_t maxTriangleCount, uint32_t maxDescriptorSetAccelerationStructures)
	{
		VkPhysicalDeviceRayTracingPropertiesNV init = vkiPhysicalDeviceRayTracingPropertiesNV_null();
		init.shaderGroupHandleSize = shaderGroupHandleSize;
		init.maxRecursionDepth = maxRecursionDepth;
		init.maxShaderGroupStride = maxShaderGroupStride;
		init.shaderGroupBaseAlignment = shaderGroupBaseAlignment;
		init.maxGeometryCount = maxGeometryCount;
		init.maxInstanceCount = maxInstanceCount;
		init.maxTriangleCount = maxTriangleCount;
		init.maxDescriptorSetAccelerationStructures = maxDescriptorSetAccelerationStructures;
		return init;
	}

	static inline VkTransformMatrixKHR vkiTransformMatrixKHR_null()
	{
		VkTransformMatrixKHR init = {0};
		return init;
	}

	static inline VkTransformMatrixKHR vkiTransformMatrixKHR()
	{
		VkTransformMatrixKHR init = vkiTransformMatrixKHR_null();
		return init;
	}

	static inline VkAabbPositionsKHR vkiAabbPositionsKHR_null()
	{
		VkAabbPositionsKHR init = {0};
		return init;
	}

	static inline VkAabbPositionsKHR vkiAabbPositionsKHR(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
	{
		VkAabbPositionsKHR init = vkiAabbPositionsKHR_null();
		init.minX = minX;
		init.minY = minY;
		init.minZ = minZ;
		init.maxX = maxX;
		init.maxY = maxY;
		init.maxZ = maxZ;
		return init;
	}

	static inline VkAccelerationStructureInstanceKHR vkiAccelerationStructureInstanceKHR_null()
	{
		VkAccelerationStructureInstanceKHR init = {0};
		return init;
	}

	static inline VkAccelerationStructureInstanceKHR vkiAccelerationStructureInstanceKHR(VkTransformMatrixKHR transform, uint64_t accelerationStructureReference)
	{
		VkAccelerationStructureInstanceKHR init = vkiAccelerationStructureInstanceKHR_null();
		init.transform = transform;
		init.accelerationStructureReference = accelerationStructureReference;
		return init;
	}

	static inline VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV vkiPhysicalDeviceRepresentativeFragmentTestFeaturesNV_null()
	{
		VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV vkiPhysicalDeviceRepresentativeFragmentTestFeaturesNV(VkBool32 representativeFragmentTest)
	{
		VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV init = vkiPhysicalDeviceRepresentativeFragmentTestFeaturesNV_null();
		init.representativeFragmentTest = representativeFragmentTest;
		return init;
	}

	static inline VkPipelineRepresentativeFragmentTestStateCreateInfoNV vkiPipelineRepresentativeFragmentTestStateCreateInfoNV_null()
	{
		VkPipelineRepresentativeFragmentTestStateCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV;
		return init;
	}

	static inline VkPipelineRepresentativeFragmentTestStateCreateInfoNV vkiPipelineRepresentativeFragmentTestStateCreateInfoNV(VkBool32 representativeFragmentTestEnable)
	{
		VkPipelineRepresentativeFragmentTestStateCreateInfoNV init = vkiPipelineRepresentativeFragmentTestStateCreateInfoNV_null();
		init.representativeFragmentTestEnable = representativeFragmentTestEnable;
		return init;
	}

	static inline VkPhysicalDeviceImageViewImageFormatInfoEXT vkiPhysicalDeviceImageViewImageFormatInfoEXT_null()
	{
		VkPhysicalDeviceImageViewImageFormatInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT;
		return init;
	}

	static inline VkPhysicalDeviceImageViewImageFormatInfoEXT vkiPhysicalDeviceImageViewImageFormatInfoEXT(VkImageViewType imageViewType)
	{
		VkPhysicalDeviceImageViewImageFormatInfoEXT init = vkiPhysicalDeviceImageViewImageFormatInfoEXT_null();
		init.imageViewType = imageViewType;
		return init;
	}

	static inline VkFilterCubicImageViewImageFormatPropertiesEXT vkiFilterCubicImageViewImageFormatPropertiesEXT_null()
	{
		VkFilterCubicImageViewImageFormatPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT;
		return init;
	}

	static inline VkFilterCubicImageViewImageFormatPropertiesEXT vkiFilterCubicImageViewImageFormatPropertiesEXT(VkBool32 filterCubic, VkBool32 filterCubicMinmax)
	{
		VkFilterCubicImageViewImageFormatPropertiesEXT init = vkiFilterCubicImageViewImageFormatPropertiesEXT_null();
		init.filterCubic = filterCubic;
		init.filterCubicMinmax = filterCubicMinmax;
		return init;
	}

	static inline VkImportMemoryHostPointerInfoEXT vkiImportMemoryHostPointerInfoEXT_null()
	{
		VkImportMemoryHostPointerInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT;
		return init;
	}

	static inline VkImportMemoryHostPointerInfoEXT vkiImportMemoryHostPointerInfoEXT(VkExternalMemoryHandleTypeFlagBits handleType, void *pHostPointer)
	{
		VkImportMemoryHostPointerInfoEXT init = vkiImportMemoryHostPointerInfoEXT_null();
		init.handleType = handleType;
		init.pHostPointer = pHostPointer;
		return init;
	}

	static inline VkMemoryHostPointerPropertiesEXT vkiMemoryHostPointerPropertiesEXT_null()
	{
		VkMemoryHostPointerPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT;
		return init;
	}

	static inline VkMemoryHostPointerPropertiesEXT vkiMemoryHostPointerPropertiesEXT(uint32_t memoryTypeBits)
	{
		VkMemoryHostPointerPropertiesEXT init = vkiMemoryHostPointerPropertiesEXT_null();
		init.memoryTypeBits = memoryTypeBits;
		return init;
	}

	static inline VkPhysicalDeviceExternalMemoryHostPropertiesEXT vkiPhysicalDeviceExternalMemoryHostPropertiesEXT_null()
	{
		VkPhysicalDeviceExternalMemoryHostPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceExternalMemoryHostPropertiesEXT vkiPhysicalDeviceExternalMemoryHostPropertiesEXT(VkDeviceSize minImportedHostPointerAlignment)
	{
		VkPhysicalDeviceExternalMemoryHostPropertiesEXT init = vkiPhysicalDeviceExternalMemoryHostPropertiesEXT_null();
		init.minImportedHostPointerAlignment = minImportedHostPointerAlignment;
		return init;
	}

	static inline VkPipelineCompilerControlCreateInfoAMD vkiPipelineCompilerControlCreateInfoAMD_null()
	{
		VkPipelineCompilerControlCreateInfoAMD init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD;
		return init;
	}

	static inline VkPipelineCompilerControlCreateInfoAMD vkiPipelineCompilerControlCreateInfoAMD(VkPipelineCompilerControlFlagsAMD compilerControlFlags)
	{
		VkPipelineCompilerControlCreateInfoAMD init = vkiPipelineCompilerControlCreateInfoAMD_null();
		init.compilerControlFlags = compilerControlFlags;
		return init;
	}

	static inline VkPhysicalDeviceShaderCorePropertiesAMD vkiPhysicalDeviceShaderCorePropertiesAMD_null()
	{
		VkPhysicalDeviceShaderCorePropertiesAMD init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD;
		return init;
	}

	static inline VkPhysicalDeviceShaderCorePropertiesAMD vkiPhysicalDeviceShaderCorePropertiesAMD(uint32_t shaderEngineCount, uint32_t shaderArraysPerEngineCount, uint32_t computeUnitsPerShaderArray, uint32_t simdPerComputeUnit, uint32_t wavefrontsPerSimd, uint32_t wavefrontSize, uint32_t sgprsPerSimd, uint32_t minSgprAllocation, uint32_t maxSgprAllocation, uint32_t sgprAllocationGranularity, uint32_t vgprsPerSimd, uint32_t minVgprAllocation, uint32_t maxVgprAllocation, uint32_t vgprAllocationGranularity)
	{
		VkPhysicalDeviceShaderCorePropertiesAMD init = vkiPhysicalDeviceShaderCorePropertiesAMD_null();
		init.shaderEngineCount = shaderEngineCount;
		init.shaderArraysPerEngineCount = shaderArraysPerEngineCount;
		init.computeUnitsPerShaderArray = computeUnitsPerShaderArray;
		init.simdPerComputeUnit = simdPerComputeUnit;
		init.wavefrontsPerSimd = wavefrontsPerSimd;
		init.wavefrontSize = wavefrontSize;
		init.sgprsPerSimd = sgprsPerSimd;
		init.minSgprAllocation = minSgprAllocation;
		init.maxSgprAllocation = maxSgprAllocation;
		init.sgprAllocationGranularity = sgprAllocationGranularity;
		init.vgprsPerSimd = vgprsPerSimd;
		init.minVgprAllocation = minVgprAllocation;
		init.maxVgprAllocation = maxVgprAllocation;
		init.vgprAllocationGranularity = vgprAllocationGranularity;
		return init;
	}

	static inline VkDeviceMemoryOverallocationCreateInfoAMD vkiDeviceMemoryOverallocationCreateInfoAMD_null()
	{
		VkDeviceMemoryOverallocationCreateInfoAMD init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD;
		return init;
	}

	static inline VkDeviceMemoryOverallocationCreateInfoAMD vkiDeviceMemoryOverallocationCreateInfoAMD(VkMemoryOverallocationBehaviorAMD overallocationBehavior)
	{
		VkDeviceMemoryOverallocationCreateInfoAMD init = vkiDeviceMemoryOverallocationCreateInfoAMD_null();
		init.overallocationBehavior = overallocationBehavior;
		return init;
	}

	static inline VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT vkiPhysicalDeviceVertexAttributeDivisorPropertiesEXT_null()
	{
		VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT vkiPhysicalDeviceVertexAttributeDivisorPropertiesEXT(uint32_t maxVertexAttribDivisor)
	{
		VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT init = vkiPhysicalDeviceVertexAttributeDivisorPropertiesEXT_null();
		init.maxVertexAttribDivisor = maxVertexAttribDivisor;
		return init;
	}

	static inline VkPhysicalDeviceComputeShaderDerivativesFeaturesNV vkiPhysicalDeviceComputeShaderDerivativesFeaturesNV_null()
	{
		VkPhysicalDeviceComputeShaderDerivativesFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceComputeShaderDerivativesFeaturesNV vkiPhysicalDeviceComputeShaderDerivativesFeaturesNV(VkBool32 computeDerivativeGroupQuads, VkBool32 computeDerivativeGroupLinear)
	{
		VkPhysicalDeviceComputeShaderDerivativesFeaturesNV init = vkiPhysicalDeviceComputeShaderDerivativesFeaturesNV_null();
		init.computeDerivativeGroupQuads = computeDerivativeGroupQuads;
		init.computeDerivativeGroupLinear = computeDerivativeGroupLinear;
		return init;
	}

	static inline VkPhysicalDeviceMeshShaderFeaturesNV vkiPhysicalDeviceMeshShaderFeaturesNV_null()
	{
		VkPhysicalDeviceMeshShaderFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceMeshShaderFeaturesNV vkiPhysicalDeviceMeshShaderFeaturesNV(VkBool32 taskShader, VkBool32 meshShader)
	{
		VkPhysicalDeviceMeshShaderFeaturesNV init = vkiPhysicalDeviceMeshShaderFeaturesNV_null();
		init.taskShader = taskShader;
		init.meshShader = meshShader;
		return init;
	}

	static inline VkPhysicalDeviceMeshShaderPropertiesNV vkiPhysicalDeviceMeshShaderPropertiesNV_null()
	{
		VkPhysicalDeviceMeshShaderPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV;
		return init;
	}

	static inline VkPhysicalDeviceMeshShaderPropertiesNV vkiPhysicalDeviceMeshShaderPropertiesNV(uint32_t maxDrawMeshTasksCount, uint32_t maxTaskWorkGroupInvocations, uint32_t maxTaskTotalMemorySize, uint32_t maxTaskOutputCount, uint32_t maxMeshWorkGroupInvocations, uint32_t maxMeshTotalMemorySize, uint32_t maxMeshOutputVertices, uint32_t maxMeshOutputPrimitives, uint32_t maxMeshMultiviewViewCount, uint32_t meshOutputPerVertexGranularity, uint32_t meshOutputPerPrimitiveGranularity)
	{
		VkPhysicalDeviceMeshShaderPropertiesNV init = vkiPhysicalDeviceMeshShaderPropertiesNV_null();
		init.maxDrawMeshTasksCount = maxDrawMeshTasksCount;
		init.maxTaskWorkGroupInvocations = maxTaskWorkGroupInvocations;
		init.maxTaskTotalMemorySize = maxTaskTotalMemorySize;
		init.maxTaskOutputCount = maxTaskOutputCount;
		init.maxMeshWorkGroupInvocations = maxMeshWorkGroupInvocations;
		init.maxMeshTotalMemorySize = maxMeshTotalMemorySize;
		init.maxMeshOutputVertices = maxMeshOutputVertices;
		init.maxMeshOutputPrimitives = maxMeshOutputPrimitives;
		init.maxMeshMultiviewViewCount = maxMeshMultiviewViewCount;
		init.meshOutputPerVertexGranularity = meshOutputPerVertexGranularity;
		init.meshOutputPerPrimitiveGranularity = meshOutputPerPrimitiveGranularity;
		return init;
	}

	static inline VkDrawMeshTasksIndirectCommandNV vkiDrawMeshTasksIndirectCommandNV_null()
	{
		VkDrawMeshTasksIndirectCommandNV init = {0};
		return init;
	}

	static inline VkDrawMeshTasksIndirectCommandNV vkiDrawMeshTasksIndirectCommandNV(uint32_t taskCount, uint32_t firstTask)
	{
		VkDrawMeshTasksIndirectCommandNV init = vkiDrawMeshTasksIndirectCommandNV_null();
		init.taskCount = taskCount;
		init.firstTask = firstTask;
		return init;
	}

	static inline VkPhysicalDeviceShaderImageFootprintFeaturesNV vkiPhysicalDeviceShaderImageFootprintFeaturesNV_null()
	{
		VkPhysicalDeviceShaderImageFootprintFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceShaderImageFootprintFeaturesNV vkiPhysicalDeviceShaderImageFootprintFeaturesNV(VkBool32 imageFootprint)
	{
		VkPhysicalDeviceShaderImageFootprintFeaturesNV init = vkiPhysicalDeviceShaderImageFootprintFeaturesNV_null();
		init.imageFootprint = imageFootprint;
		return init;
	}

	static inline VkPipelineViewportExclusiveScissorStateCreateInfoNV vkiPipelineViewportExclusiveScissorStateCreateInfoNV_null()
	{
		VkPipelineViewportExclusiveScissorStateCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV;
		return init;
	}

	static inline VkPipelineViewportExclusiveScissorStateCreateInfoNV vkiPipelineViewportExclusiveScissorStateCreateInfoNV(uint32_t exclusiveScissorCount, const VkRect2D *pExclusiveScissors)
	{
		VkPipelineViewportExclusiveScissorStateCreateInfoNV init = vkiPipelineViewportExclusiveScissorStateCreateInfoNV_null();
		init.exclusiveScissorCount = exclusiveScissorCount;
		init.pExclusiveScissors = pExclusiveScissors;
		return init;
	}

	static inline VkPhysicalDeviceExclusiveScissorFeaturesNV vkiPhysicalDeviceExclusiveScissorFeaturesNV_null()
	{
		VkPhysicalDeviceExclusiveScissorFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceExclusiveScissorFeaturesNV vkiPhysicalDeviceExclusiveScissorFeaturesNV(VkBool32 exclusiveScissor)
	{
		VkPhysicalDeviceExclusiveScissorFeaturesNV init = vkiPhysicalDeviceExclusiveScissorFeaturesNV_null();
		init.exclusiveScissor = exclusiveScissor;
		return init;
	}

	static inline VkQueueFamilyCheckpointPropertiesNV vkiQueueFamilyCheckpointPropertiesNV_null()
	{
		VkQueueFamilyCheckpointPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV;
		return init;
	}

	static inline VkQueueFamilyCheckpointPropertiesNV vkiQueueFamilyCheckpointPropertiesNV(VkPipelineStageFlags checkpointExecutionStageMask)
	{
		VkQueueFamilyCheckpointPropertiesNV init = vkiQueueFamilyCheckpointPropertiesNV_null();
		init.checkpointExecutionStageMask = checkpointExecutionStageMask;
		return init;
	}

	static inline VkCheckpointDataNV vkiCheckpointDataNV_null()
	{
		VkCheckpointDataNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV;
		return init;
	}

	static inline VkCheckpointDataNV vkiCheckpointDataNV(VkPipelineStageFlagBits stage, void *pCheckpointMarker)
	{
		VkCheckpointDataNV init = vkiCheckpointDataNV_null();
		init.stage = stage;
		init.pCheckpointMarker = pCheckpointMarker;
		return init;
	}

	static inline VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL vkiPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL_null()
	{
		VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL;
		return init;
	}

	static inline VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL vkiPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(VkBool32 shaderIntegerFunctions2)
	{
		VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL init = vkiPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL_null();
		init.shaderIntegerFunctions2 = shaderIntegerFunctions2;
		return init;
	}

	static inline VkPerformanceValueINTEL vkiPerformanceValueINTEL_null()
	{
		VkPerformanceValueINTEL init = {0};
		return init;
	}

	static inline VkPerformanceValueINTEL vkiPerformanceValueINTEL(VkPerformanceValueTypeINTEL type, VkPerformanceValueDataINTEL data)
	{
		VkPerformanceValueINTEL init = vkiPerformanceValueINTEL_null();
		init.type = type;
		init.data = data;
		return init;
	}

	static inline VkInitializePerformanceApiInfoINTEL vkiInitializePerformanceApiInfoINTEL_null()
	{
		VkInitializePerformanceApiInfoINTEL init = {0};
		init.sType = VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL;
		return init;
	}

	static inline VkInitializePerformanceApiInfoINTEL vkiInitializePerformanceApiInfoINTEL(void *pUserData)
	{
		VkInitializePerformanceApiInfoINTEL init = vkiInitializePerformanceApiInfoINTEL_null();
		init.pUserData = pUserData;
		return init;
	}

	static inline VkQueryPoolPerformanceQueryCreateInfoINTEL vkiQueryPoolPerformanceQueryCreateInfoINTEL_null()
	{
		VkQueryPoolPerformanceQueryCreateInfoINTEL init = {0};
		init.sType = VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL;
		return init;
	}

	static inline VkQueryPoolPerformanceQueryCreateInfoINTEL vkiQueryPoolPerformanceQueryCreateInfoINTEL(VkQueryPoolSamplingModeINTEL performanceCountersSampling)
	{
		VkQueryPoolPerformanceQueryCreateInfoINTEL init = vkiQueryPoolPerformanceQueryCreateInfoINTEL_null();
		init.performanceCountersSampling = performanceCountersSampling;
		return init;
	}

	static inline VkPerformanceMarkerInfoINTEL vkiPerformanceMarkerInfoINTEL_null()
	{
		VkPerformanceMarkerInfoINTEL init = {0};
		init.sType = VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL;
		return init;
	}

	static inline VkPerformanceMarkerInfoINTEL vkiPerformanceMarkerInfoINTEL(uint64_t marker)
	{
		VkPerformanceMarkerInfoINTEL init = vkiPerformanceMarkerInfoINTEL_null();
		init.marker = marker;
		return init;
	}

	static inline VkPerformanceStreamMarkerInfoINTEL vkiPerformanceStreamMarkerInfoINTEL_null()
	{
		VkPerformanceStreamMarkerInfoINTEL init = {0};
		init.sType = VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL;
		return init;
	}

	static inline VkPerformanceStreamMarkerInfoINTEL vkiPerformanceStreamMarkerInfoINTEL(uint32_t marker)
	{
		VkPerformanceStreamMarkerInfoINTEL init = vkiPerformanceStreamMarkerInfoINTEL_null();
		init.marker = marker;
		return init;
	}

	static inline VkPerformanceOverrideInfoINTEL vkiPerformanceOverrideInfoINTEL_null()
	{
		VkPerformanceOverrideInfoINTEL init = {0};
		init.sType = VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL;
		return init;
	}

	static inline VkPerformanceOverrideInfoINTEL vkiPerformanceOverrideInfoINTEL(VkPerformanceOverrideTypeINTEL type, VkBool32 enable, uint64_t parameter)
	{
		VkPerformanceOverrideInfoINTEL init = vkiPerformanceOverrideInfoINTEL_null();
		init.type = type;
		init.enable = enable;
		init.parameter = parameter;
		return init;
	}

	static inline VkPerformanceConfigurationAcquireInfoINTEL vkiPerformanceConfigurationAcquireInfoINTEL_null()
	{
		VkPerformanceConfigurationAcquireInfoINTEL init = {0};
		init.sType = VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL;
		return init;
	}

	static inline VkPerformanceConfigurationAcquireInfoINTEL vkiPerformanceConfigurationAcquireInfoINTEL(VkPerformanceConfigurationTypeINTEL type)
	{
		VkPerformanceConfigurationAcquireInfoINTEL init = vkiPerformanceConfigurationAcquireInfoINTEL_null();
		init.type = type;
		return init;
	}

	static inline VkPhysicalDevicePCIBusInfoPropertiesEXT vkiPhysicalDevicePCIBusInfoPropertiesEXT_null()
	{
		VkPhysicalDevicePCIBusInfoPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDevicePCIBusInfoPropertiesEXT vkiPhysicalDevicePCIBusInfoPropertiesEXT(uint32_t pciDomain, uint32_t pciBus, uint32_t pciDevice, uint32_t pciFunction)
	{
		VkPhysicalDevicePCIBusInfoPropertiesEXT init = vkiPhysicalDevicePCIBusInfoPropertiesEXT_null();
		init.pciDomain = pciDomain;
		init.pciBus = pciBus;
		init.pciDevice = pciDevice;
		init.pciFunction = pciFunction;
		return init;
	}

	static inline VkDisplayNativeHdrSurfaceCapabilitiesAMD vkiDisplayNativeHdrSurfaceCapabilitiesAMD_null()
	{
		VkDisplayNativeHdrSurfaceCapabilitiesAMD init = {0};
		init.sType = VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD;
		return init;
	}

	static inline VkDisplayNativeHdrSurfaceCapabilitiesAMD vkiDisplayNativeHdrSurfaceCapabilitiesAMD(VkBool32 localDimmingSupport)
	{
		VkDisplayNativeHdrSurfaceCapabilitiesAMD init = vkiDisplayNativeHdrSurfaceCapabilitiesAMD_null();
		init.localDimmingSupport = localDimmingSupport;
		return init;
	}

	static inline VkSwapchainDisplayNativeHdrCreateInfoAMD vkiSwapchainDisplayNativeHdrCreateInfoAMD_null()
	{
		VkSwapchainDisplayNativeHdrCreateInfoAMD init = {0};
		init.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD;
		return init;
	}

	static inline VkSwapchainDisplayNativeHdrCreateInfoAMD vkiSwapchainDisplayNativeHdrCreateInfoAMD(VkBool32 localDimmingEnable)
	{
		VkSwapchainDisplayNativeHdrCreateInfoAMD init = vkiSwapchainDisplayNativeHdrCreateInfoAMD_null();
		init.localDimmingEnable = localDimmingEnable;
		return init;
	}

	static inline VkPhysicalDeviceFragmentDensityMapFeaturesEXT vkiPhysicalDeviceFragmentDensityMapFeaturesEXT_null()
	{
		VkPhysicalDeviceFragmentDensityMapFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceFragmentDensityMapFeaturesEXT vkiPhysicalDeviceFragmentDensityMapFeaturesEXT(VkBool32 fragmentDensityMap, VkBool32 fragmentDensityMapDynamic, VkBool32 fragmentDensityMapNonSubsampledImages)
	{
		VkPhysicalDeviceFragmentDensityMapFeaturesEXT init = vkiPhysicalDeviceFragmentDensityMapFeaturesEXT_null();
		init.fragmentDensityMap = fragmentDensityMap;
		init.fragmentDensityMapDynamic = fragmentDensityMapDynamic;
		init.fragmentDensityMapNonSubsampledImages = fragmentDensityMapNonSubsampledImages;
		return init;
	}

	static inline VkPhysicalDeviceFragmentDensityMapPropertiesEXT vkiPhysicalDeviceFragmentDensityMapPropertiesEXT_null()
	{
		VkPhysicalDeviceFragmentDensityMapPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceFragmentDensityMapPropertiesEXT vkiPhysicalDeviceFragmentDensityMapPropertiesEXT(VkExtent2D minFragmentDensityTexelSize, VkExtent2D maxFragmentDensityTexelSize, VkBool32 fragmentDensityInvocations)
	{
		VkPhysicalDeviceFragmentDensityMapPropertiesEXT init = vkiPhysicalDeviceFragmentDensityMapPropertiesEXT_null();
		init.minFragmentDensityTexelSize = minFragmentDensityTexelSize;
		init.maxFragmentDensityTexelSize = maxFragmentDensityTexelSize;
		init.fragmentDensityInvocations = fragmentDensityInvocations;
		return init;
	}

	static inline VkRenderPassFragmentDensityMapCreateInfoEXT vkiRenderPassFragmentDensityMapCreateInfoEXT_null()
	{
		VkRenderPassFragmentDensityMapCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT;
		return init;
	}

	static inline VkRenderPassFragmentDensityMapCreateInfoEXT vkiRenderPassFragmentDensityMapCreateInfoEXT(VkAttachmentReference fragmentDensityMapAttachment)
	{
		VkRenderPassFragmentDensityMapCreateInfoEXT init = vkiRenderPassFragmentDensityMapCreateInfoEXT_null();
		init.fragmentDensityMapAttachment = fragmentDensityMapAttachment;
		return init;
	}

	static inline VkPhysicalDeviceShaderCoreProperties2AMD vkiPhysicalDeviceShaderCoreProperties2AMD_null()
	{
		VkPhysicalDeviceShaderCoreProperties2AMD init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD;
		return init;
	}

	static inline VkPhysicalDeviceShaderCoreProperties2AMD vkiPhysicalDeviceShaderCoreProperties2AMD(VkShaderCorePropertiesFlagsAMD shaderCoreFeatures, uint32_t activeComputeUnitCount)
	{
		VkPhysicalDeviceShaderCoreProperties2AMD init = vkiPhysicalDeviceShaderCoreProperties2AMD_null();
		init.shaderCoreFeatures = shaderCoreFeatures;
		init.activeComputeUnitCount = activeComputeUnitCount;
		return init;
	}

	static inline VkPhysicalDeviceCoherentMemoryFeaturesAMD vkiPhysicalDeviceCoherentMemoryFeaturesAMD_null()
	{
		VkPhysicalDeviceCoherentMemoryFeaturesAMD init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD;
		return init;
	}

	static inline VkPhysicalDeviceCoherentMemoryFeaturesAMD vkiPhysicalDeviceCoherentMemoryFeaturesAMD(VkBool32 deviceCoherentMemory)
	{
		VkPhysicalDeviceCoherentMemoryFeaturesAMD init = vkiPhysicalDeviceCoherentMemoryFeaturesAMD_null();
		init.deviceCoherentMemory = deviceCoherentMemory;
		return init;
	}

	static inline VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT vkiPhysicalDeviceShaderImageAtomicInt64FeaturesEXT_null()
	{
		VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT vkiPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(VkBool32 shaderImageInt64Atomics, VkBool32 sparseImageInt64Atomics)
	{
		VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT init = vkiPhysicalDeviceShaderImageAtomicInt64FeaturesEXT_null();
		init.shaderImageInt64Atomics = shaderImageInt64Atomics;
		init.sparseImageInt64Atomics = sparseImageInt64Atomics;
		return init;
	}

	static inline VkPhysicalDeviceMemoryBudgetPropertiesEXT vkiPhysicalDeviceMemoryBudgetPropertiesEXT_null()
	{
		VkPhysicalDeviceMemoryBudgetPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceMemoryBudgetPropertiesEXT vkiPhysicalDeviceMemoryBudgetPropertiesEXT()
	{
		VkPhysicalDeviceMemoryBudgetPropertiesEXT init = vkiPhysicalDeviceMemoryBudgetPropertiesEXT_null();
		return init;
	}

	static inline VkPhysicalDeviceMemoryPriorityFeaturesEXT vkiPhysicalDeviceMemoryPriorityFeaturesEXT_null()
	{
		VkPhysicalDeviceMemoryPriorityFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceMemoryPriorityFeaturesEXT vkiPhysicalDeviceMemoryPriorityFeaturesEXT(VkBool32 memoryPriority)
	{
		VkPhysicalDeviceMemoryPriorityFeaturesEXT init = vkiPhysicalDeviceMemoryPriorityFeaturesEXT_null();
		init.memoryPriority = memoryPriority;
		return init;
	}

	static inline VkMemoryPriorityAllocateInfoEXT vkiMemoryPriorityAllocateInfoEXT_null()
	{
		VkMemoryPriorityAllocateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT;
		return init;
	}

	static inline VkMemoryPriorityAllocateInfoEXT vkiMemoryPriorityAllocateInfoEXT(float priority)
	{
		VkMemoryPriorityAllocateInfoEXT init = vkiMemoryPriorityAllocateInfoEXT_null();
		init.priority = priority;
		return init;
	}

	static inline VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV vkiPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV_null()
	{
		VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV vkiPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(VkBool32 dedicatedAllocationImageAliasing)
	{
		VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV init = vkiPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV_null();
		init.dedicatedAllocationImageAliasing = dedicatedAllocationImageAliasing;
		return init;
	}

	static inline VkPhysicalDeviceBufferDeviceAddressFeaturesEXT vkiPhysicalDeviceBufferDeviceAddressFeaturesEXT_null()
	{
		VkPhysicalDeviceBufferDeviceAddressFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceBufferDeviceAddressFeaturesEXT vkiPhysicalDeviceBufferDeviceAddressFeaturesEXT(VkBool32 bufferDeviceAddress, VkBool32 bufferDeviceAddressCaptureReplay, VkBool32 bufferDeviceAddressMultiDevice)
	{
		VkPhysicalDeviceBufferDeviceAddressFeaturesEXT init = vkiPhysicalDeviceBufferDeviceAddressFeaturesEXT_null();
		init.bufferDeviceAddress = bufferDeviceAddress;
		init.bufferDeviceAddressCaptureReplay = bufferDeviceAddressCaptureReplay;
		init.bufferDeviceAddressMultiDevice = bufferDeviceAddressMultiDevice;
		return init;
	}

	static inline VkBufferDeviceAddressCreateInfoEXT vkiBufferDeviceAddressCreateInfoEXT_null()
	{
		VkBufferDeviceAddressCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT;
		return init;
	}

	static inline VkBufferDeviceAddressCreateInfoEXT vkiBufferDeviceAddressCreateInfoEXT(VkDeviceAddress deviceAddress)
	{
		VkBufferDeviceAddressCreateInfoEXT init = vkiBufferDeviceAddressCreateInfoEXT_null();
		init.deviceAddress = deviceAddress;
		return init;
	}

	static inline VkValidationFeaturesEXT vkiValidationFeaturesEXT_null()
	{
		VkValidationFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
		return init;
	}

	static inline VkValidationFeaturesEXT vkiValidationFeaturesEXT(uint32_t enabledValidationFeatureCount, const VkValidationFeatureEnableEXT *pEnabledValidationFeatures, uint32_t disabledValidationFeatureCount, const VkValidationFeatureDisableEXT *pDisabledValidationFeatures)
	{
		VkValidationFeaturesEXT init = vkiValidationFeaturesEXT_null();
		init.enabledValidationFeatureCount = enabledValidationFeatureCount;
		init.pEnabledValidationFeatures = pEnabledValidationFeatures;
		init.disabledValidationFeatureCount = disabledValidationFeatureCount;
		init.pDisabledValidationFeatures = pDisabledValidationFeatures;
		return init;
	}

	static inline VkCooperativeMatrixPropertiesNV vkiCooperativeMatrixPropertiesNV_null()
	{
		VkCooperativeMatrixPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV;
		return init;
	}

	static inline VkCooperativeMatrixPropertiesNV vkiCooperativeMatrixPropertiesNV(uint32_t MSize, uint32_t NSize, uint32_t KSize, VkComponentTypeNV AType, VkComponentTypeNV BType, VkComponentTypeNV CType, VkComponentTypeNV DType, VkScopeNV scope)
	{
		VkCooperativeMatrixPropertiesNV init = vkiCooperativeMatrixPropertiesNV_null();
		init.MSize = MSize;
		init.NSize = NSize;
		init.KSize = KSize;
		init.AType = AType;
		init.BType = BType;
		init.CType = CType;
		init.DType = DType;
		init.scope = scope;
		return init;
	}

	static inline VkPhysicalDeviceCooperativeMatrixFeaturesNV vkiPhysicalDeviceCooperativeMatrixFeaturesNV_null()
	{
		VkPhysicalDeviceCooperativeMatrixFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceCooperativeMatrixFeaturesNV vkiPhysicalDeviceCooperativeMatrixFeaturesNV(VkBool32 cooperativeMatrix, VkBool32 cooperativeMatrixRobustBufferAccess)
	{
		VkPhysicalDeviceCooperativeMatrixFeaturesNV init = vkiPhysicalDeviceCooperativeMatrixFeaturesNV_null();
		init.cooperativeMatrix = cooperativeMatrix;
		init.cooperativeMatrixRobustBufferAccess = cooperativeMatrixRobustBufferAccess;
		return init;
	}

	static inline VkPhysicalDeviceCooperativeMatrixPropertiesNV vkiPhysicalDeviceCooperativeMatrixPropertiesNV_null()
	{
		VkPhysicalDeviceCooperativeMatrixPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV;
		return init;
	}

	static inline VkPhysicalDeviceCooperativeMatrixPropertiesNV vkiPhysicalDeviceCooperativeMatrixPropertiesNV(VkShaderStageFlags cooperativeMatrixSupportedStages)
	{
		VkPhysicalDeviceCooperativeMatrixPropertiesNV init = vkiPhysicalDeviceCooperativeMatrixPropertiesNV_null();
		init.cooperativeMatrixSupportedStages = cooperativeMatrixSupportedStages;
		return init;
	}

	static inline VkPhysicalDeviceCoverageReductionModeFeaturesNV vkiPhysicalDeviceCoverageReductionModeFeaturesNV_null()
	{
		VkPhysicalDeviceCoverageReductionModeFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceCoverageReductionModeFeaturesNV vkiPhysicalDeviceCoverageReductionModeFeaturesNV(VkBool32 coverageReductionMode)
	{
		VkPhysicalDeviceCoverageReductionModeFeaturesNV init = vkiPhysicalDeviceCoverageReductionModeFeaturesNV_null();
		init.coverageReductionMode = coverageReductionMode;
		return init;
	}

	static inline VkPipelineCoverageReductionStateCreateInfoNV vkiPipelineCoverageReductionStateCreateInfoNV_null()
	{
		VkPipelineCoverageReductionStateCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV;
		return init;
	}

	static inline VkPipelineCoverageReductionStateCreateInfoNV vkiPipelineCoverageReductionStateCreateInfoNV(VkCoverageReductionModeNV coverageReductionMode)
	{
		VkPipelineCoverageReductionStateCreateInfoNV init = vkiPipelineCoverageReductionStateCreateInfoNV_null();
		init.coverageReductionMode = coverageReductionMode;
		return init;
	}

	static inline VkFramebufferMixedSamplesCombinationNV vkiFramebufferMixedSamplesCombinationNV_null()
	{
		VkFramebufferMixedSamplesCombinationNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV;
		return init;
	}

	static inline VkFramebufferMixedSamplesCombinationNV vkiFramebufferMixedSamplesCombinationNV(VkCoverageReductionModeNV coverageReductionMode, VkSampleCountFlagBits rasterizationSamples, VkSampleCountFlags depthStencilSamples, VkSampleCountFlags colorSamples)
	{
		VkFramebufferMixedSamplesCombinationNV init = vkiFramebufferMixedSamplesCombinationNV_null();
		init.coverageReductionMode = coverageReductionMode;
		init.rasterizationSamples = rasterizationSamples;
		init.depthStencilSamples = depthStencilSamples;
		init.colorSamples = colorSamples;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT vkiPhysicalDeviceFragmentShaderInterlockFeaturesEXT_null()
	{
		VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT vkiPhysicalDeviceFragmentShaderInterlockFeaturesEXT(VkBool32 fragmentShaderSampleInterlock, VkBool32 fragmentShaderPixelInterlock, VkBool32 fragmentShaderShadingRateInterlock)
	{
		VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT init = vkiPhysicalDeviceFragmentShaderInterlockFeaturesEXT_null();
		init.fragmentShaderSampleInterlock = fragmentShaderSampleInterlock;
		init.fragmentShaderPixelInterlock = fragmentShaderPixelInterlock;
		init.fragmentShaderShadingRateInterlock = fragmentShaderShadingRateInterlock;
		return init;
	}

	static inline VkPhysicalDeviceYcbcrImageArraysFeaturesEXT vkiPhysicalDeviceYcbcrImageArraysFeaturesEXT_null()
	{
		VkPhysicalDeviceYcbcrImageArraysFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceYcbcrImageArraysFeaturesEXT vkiPhysicalDeviceYcbcrImageArraysFeaturesEXT(VkBool32 ycbcrImageArrays)
	{
		VkPhysicalDeviceYcbcrImageArraysFeaturesEXT init = vkiPhysicalDeviceYcbcrImageArraysFeaturesEXT_null();
		init.ycbcrImageArrays = ycbcrImageArrays;
		return init;
	}

	static inline VkPhysicalDeviceProvokingVertexFeaturesEXT vkiPhysicalDeviceProvokingVertexFeaturesEXT_null()
	{
		VkPhysicalDeviceProvokingVertexFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceProvokingVertexFeaturesEXT vkiPhysicalDeviceProvokingVertexFeaturesEXT(VkBool32 provokingVertexLast, VkBool32 transformFeedbackPreservesProvokingVertex)
	{
		VkPhysicalDeviceProvokingVertexFeaturesEXT init = vkiPhysicalDeviceProvokingVertexFeaturesEXT_null();
		init.provokingVertexLast = provokingVertexLast;
		init.transformFeedbackPreservesProvokingVertex = transformFeedbackPreservesProvokingVertex;
		return init;
	}

	static inline VkPhysicalDeviceProvokingVertexPropertiesEXT vkiPhysicalDeviceProvokingVertexPropertiesEXT_null()
	{
		VkPhysicalDeviceProvokingVertexPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceProvokingVertexPropertiesEXT vkiPhysicalDeviceProvokingVertexPropertiesEXT(VkBool32 provokingVertexModePerPipeline, VkBool32 transformFeedbackPreservesTriangleFanProvokingVertex)
	{
		VkPhysicalDeviceProvokingVertexPropertiesEXT init = vkiPhysicalDeviceProvokingVertexPropertiesEXT_null();
		init.provokingVertexModePerPipeline = provokingVertexModePerPipeline;
		init.transformFeedbackPreservesTriangleFanProvokingVertex = transformFeedbackPreservesTriangleFanProvokingVertex;
		return init;
	}

	static inline VkPipelineRasterizationProvokingVertexStateCreateInfoEXT vkiPipelineRasterizationProvokingVertexStateCreateInfoEXT_null()
	{
		VkPipelineRasterizationProvokingVertexStateCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT;
		return init;
	}

	static inline VkPipelineRasterizationProvokingVertexStateCreateInfoEXT vkiPipelineRasterizationProvokingVertexStateCreateInfoEXT(VkProvokingVertexModeEXT provokingVertexMode)
	{
		VkPipelineRasterizationProvokingVertexStateCreateInfoEXT init = vkiPipelineRasterizationProvokingVertexStateCreateInfoEXT_null();
		init.provokingVertexMode = provokingVertexMode;
		return init;
	}

	static inline VkHeadlessSurfaceCreateInfoEXT vkiHeadlessSurfaceCreateInfoEXT_null()
	{
		VkHeadlessSurfaceCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT;
		return init;
	}

	static inline VkHeadlessSurfaceCreateInfoEXT vkiHeadlessSurfaceCreateInfoEXT()
	{
		VkHeadlessSurfaceCreateInfoEXT init = vkiHeadlessSurfaceCreateInfoEXT_null();
		return init;
	}

	static inline VkPhysicalDeviceShaderAtomicFloatFeaturesEXT vkiPhysicalDeviceShaderAtomicFloatFeaturesEXT_null()
	{
		VkPhysicalDeviceShaderAtomicFloatFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceShaderAtomicFloatFeaturesEXT vkiPhysicalDeviceShaderAtomicFloatFeaturesEXT(VkBool32 shaderBufferFloat32Atomics, VkBool32 shaderBufferFloat32AtomicAdd, VkBool32 shaderBufferFloat64Atomics, VkBool32 shaderBufferFloat64AtomicAdd, VkBool32 shaderSharedFloat32Atomics, VkBool32 shaderSharedFloat32AtomicAdd, VkBool32 shaderSharedFloat64Atomics, VkBool32 shaderSharedFloat64AtomicAdd, VkBool32 shaderImageFloat32Atomics, VkBool32 shaderImageFloat32AtomicAdd, VkBool32 sparseImageFloat32Atomics, VkBool32 sparseImageFloat32AtomicAdd)
	{
		VkPhysicalDeviceShaderAtomicFloatFeaturesEXT init = vkiPhysicalDeviceShaderAtomicFloatFeaturesEXT_null();
		init.shaderBufferFloat32Atomics = shaderBufferFloat32Atomics;
		init.shaderBufferFloat32AtomicAdd = shaderBufferFloat32AtomicAdd;
		init.shaderBufferFloat64Atomics = shaderBufferFloat64Atomics;
		init.shaderBufferFloat64AtomicAdd = shaderBufferFloat64AtomicAdd;
		init.shaderSharedFloat32Atomics = shaderSharedFloat32Atomics;
		init.shaderSharedFloat32AtomicAdd = shaderSharedFloat32AtomicAdd;
		init.shaderSharedFloat64Atomics = shaderSharedFloat64Atomics;
		init.shaderSharedFloat64AtomicAdd = shaderSharedFloat64AtomicAdd;
		init.shaderImageFloat32Atomics = shaderImageFloat32Atomics;
		init.shaderImageFloat32AtomicAdd = shaderImageFloat32AtomicAdd;
		init.sparseImageFloat32Atomics = sparseImageFloat32Atomics;
		init.sparseImageFloat32AtomicAdd = sparseImageFloat32AtomicAdd;
		return init;
	}

	static inline VkPhysicalDeviceExtendedDynamicStateFeaturesEXT vkiPhysicalDeviceExtendedDynamicStateFeaturesEXT_null()
	{
		VkPhysicalDeviceExtendedDynamicStateFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceExtendedDynamicStateFeaturesEXT vkiPhysicalDeviceExtendedDynamicStateFeaturesEXT(VkBool32 extendedDynamicState)
	{
		VkPhysicalDeviceExtendedDynamicStateFeaturesEXT init = vkiPhysicalDeviceExtendedDynamicStateFeaturesEXT_null();
		init.extendedDynamicState = extendedDynamicState;
		return init;
	}

	static inline VkPhysicalDeviceHostImageCopyFeaturesEXT vkiPhysicalDeviceHostImageCopyFeaturesEXT_null()
	{
		VkPhysicalDeviceHostImageCopyFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceHostImageCopyFeaturesEXT vkiPhysicalDeviceHostImageCopyFeaturesEXT(VkBool32 hostImageCopy)
	{
		VkPhysicalDeviceHostImageCopyFeaturesEXT init = vkiPhysicalDeviceHostImageCopyFeaturesEXT_null();
		init.hostImageCopy = hostImageCopy;
		return init;
	}

	static inline VkPhysicalDeviceHostImageCopyPropertiesEXT vkiPhysicalDeviceHostImageCopyPropertiesEXT_null()
	{
		VkPhysicalDeviceHostImageCopyPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceHostImageCopyPropertiesEXT vkiPhysicalDeviceHostImageCopyPropertiesEXT(uint32_t copySrcLayoutCount, VkImageLayout *pCopySrcLayouts, uint32_t copyDstLayoutCount, VkImageLayout *pCopyDstLayouts, VkBool32 identicalMemoryTypeRequirements)
	{
		VkPhysicalDeviceHostImageCopyPropertiesEXT init = vkiPhysicalDeviceHostImageCopyPropertiesEXT_null();
		init.copySrcLayoutCount = copySrcLayoutCount;
		init.pCopySrcLayouts = pCopySrcLayouts;
		init.copyDstLayoutCount = copyDstLayoutCount;
		init.pCopyDstLayouts = pCopyDstLayouts;
		init.identicalMemoryTypeRequirements = identicalMemoryTypeRequirements;
		return init;
	}

	static inline VkMemoryToImageCopyEXT vkiMemoryToImageCopyEXT_null()
	{
		VkMemoryToImageCopyEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY_EXT;
		return init;
	}

	static inline VkMemoryToImageCopyEXT vkiMemoryToImageCopyEXT(const void *pHostPointer, uint32_t memoryRowLength, uint32_t memoryImageHeight, VkImageSubresourceLayers imageSubresource, VkOffset3D imageOffset, VkExtent3D imageExtent)
	{
		VkMemoryToImageCopyEXT init = vkiMemoryToImageCopyEXT_null();
		init.pHostPointer = pHostPointer;
		init.memoryRowLength = memoryRowLength;
		init.memoryImageHeight = memoryImageHeight;
		init.imageSubresource = imageSubresource;
		init.imageOffset = imageOffset;
		init.imageExtent = imageExtent;
		return init;
	}

	static inline VkImageToMemoryCopyEXT vkiImageToMemoryCopyEXT_null()
	{
		VkImageToMemoryCopyEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY_EXT;
		return init;
	}

	static inline VkImageToMemoryCopyEXT vkiImageToMemoryCopyEXT(void *pHostPointer, uint32_t memoryRowLength, uint32_t memoryImageHeight, VkImageSubresourceLayers imageSubresource, VkOffset3D imageOffset, VkExtent3D imageExtent)
	{
		VkImageToMemoryCopyEXT init = vkiImageToMemoryCopyEXT_null();
		init.pHostPointer = pHostPointer;
		init.memoryRowLength = memoryRowLength;
		init.memoryImageHeight = memoryImageHeight;
		init.imageSubresource = imageSubresource;
		init.imageOffset = imageOffset;
		init.imageExtent = imageExtent;
		return init;
	}

	static inline VkCopyMemoryToImageInfoEXT vkiCopyMemoryToImageInfoEXT_null()
	{
		VkCopyMemoryToImageInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO_EXT;
		return init;
	}

	static inline VkCopyMemoryToImageInfoEXT vkiCopyMemoryToImageInfoEXT(VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkMemoryToImageCopyEXT *pRegions)
	{
		VkCopyMemoryToImageInfoEXT init = vkiCopyMemoryToImageInfoEXT_null();
		init.dstImage = dstImage;
		init.dstImageLayout = dstImageLayout;
		init.regionCount = regionCount;
		init.pRegions = pRegions;
		return init;
	}

	static inline VkCopyImageToMemoryInfoEXT vkiCopyImageToMemoryInfoEXT_null()
	{
		VkCopyImageToMemoryInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO_EXT;
		return init;
	}

	static inline VkCopyImageToMemoryInfoEXT vkiCopyImageToMemoryInfoEXT(VkImage srcImage, VkImageLayout srcImageLayout, uint32_t regionCount, const VkImageToMemoryCopyEXT *pRegions)
	{
		VkCopyImageToMemoryInfoEXT init = vkiCopyImageToMemoryInfoEXT_null();
		init.srcImage = srcImage;
		init.srcImageLayout = srcImageLayout;
		init.regionCount = regionCount;
		init.pRegions = pRegions;
		return init;
	}

	static inline VkCopyImageToImageInfoEXT vkiCopyImageToImageInfoEXT_null()
	{
		VkCopyImageToImageInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO_EXT;
		return init;
	}

	static inline VkCopyImageToImageInfoEXT vkiCopyImageToImageInfoEXT(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy2 *pRegions)
	{
		VkCopyImageToImageInfoEXT init = vkiCopyImageToImageInfoEXT_null();
		init.srcImage = srcImage;
		init.srcImageLayout = srcImageLayout;
		init.dstImage = dstImage;
		init.dstImageLayout = dstImageLayout;
		init.regionCount = regionCount;
		init.pRegions = pRegions;
		return init;
	}

	static inline VkHostImageLayoutTransitionInfoEXT vkiHostImageLayoutTransitionInfoEXT_null()
	{
		VkHostImageLayoutTransitionInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT;
		return init;
	}

	static inline VkHostImageLayoutTransitionInfoEXT vkiHostImageLayoutTransitionInfoEXT(VkImage image, VkImageLayout oldLayout, VkImageLayout newLayout, VkImageSubresourceRange subresourceRange)
	{
		VkHostImageLayoutTransitionInfoEXT init = vkiHostImageLayoutTransitionInfoEXT_null();
		init.image = image;
		init.oldLayout = oldLayout;
		init.newLayout = newLayout;
		init.subresourceRange = subresourceRange;
		return init;
	}

	static inline VkSubresourceHostMemcpySizeEXT vkiSubresourceHostMemcpySizeEXT_null()
	{
		VkSubresourceHostMemcpySizeEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE_EXT;
		return init;
	}

	static inline VkSubresourceHostMemcpySizeEXT vkiSubresourceHostMemcpySizeEXT(VkDeviceSize size)
	{
		VkSubresourceHostMemcpySizeEXT init = vkiSubresourceHostMemcpySizeEXT_null();
		init.size = size;
		return init;
	}

	static inline VkHostImageCopyDevicePerformanceQueryEXT vkiHostImageCopyDevicePerformanceQueryEXT_null()
	{
		VkHostImageCopyDevicePerformanceQueryEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT;
		return init;
	}

	static inline VkHostImageCopyDevicePerformanceQueryEXT vkiHostImageCopyDevicePerformanceQueryEXT(VkBool32 optimalDeviceAccess, VkBool32 identicalMemoryLayout)
	{
		VkHostImageCopyDevicePerformanceQueryEXT init = vkiHostImageCopyDevicePerformanceQueryEXT_null();
		init.optimalDeviceAccess = optimalDeviceAccess;
		init.identicalMemoryLayout = identicalMemoryLayout;
		return init;
	}

	static inline VkPhysicalDeviceMapMemoryPlacedFeaturesEXT vkiPhysicalDeviceMapMemoryPlacedFeaturesEXT_null()
	{
		VkPhysicalDeviceMapMemoryPlacedFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceMapMemoryPlacedFeaturesEXT vkiPhysicalDeviceMapMemoryPlacedFeaturesEXT(VkBool32 memoryMapPlaced, VkBool32 memoryMapRangePlaced, VkBool32 memoryUnmapReserve)
	{
		VkPhysicalDeviceMapMemoryPlacedFeaturesEXT init = vkiPhysicalDeviceMapMemoryPlacedFeaturesEXT_null();
		init.memoryMapPlaced = memoryMapPlaced;
		init.memoryMapRangePlaced = memoryMapRangePlaced;
		init.memoryUnmapReserve = memoryUnmapReserve;
		return init;
	}

	static inline VkPhysicalDeviceMapMemoryPlacedPropertiesEXT vkiPhysicalDeviceMapMemoryPlacedPropertiesEXT_null()
	{
		VkPhysicalDeviceMapMemoryPlacedPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceMapMemoryPlacedPropertiesEXT vkiPhysicalDeviceMapMemoryPlacedPropertiesEXT(VkDeviceSize minPlacedMemoryMapAlignment)
	{
		VkPhysicalDeviceMapMemoryPlacedPropertiesEXT init = vkiPhysicalDeviceMapMemoryPlacedPropertiesEXT_null();
		init.minPlacedMemoryMapAlignment = minPlacedMemoryMapAlignment;
		return init;
	}

	static inline VkMemoryMapPlacedInfoEXT vkiMemoryMapPlacedInfoEXT_null()
	{
		VkMemoryMapPlacedInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT;
		return init;
	}

	static inline VkMemoryMapPlacedInfoEXT vkiMemoryMapPlacedInfoEXT(void *pPlacedAddress)
	{
		VkMemoryMapPlacedInfoEXT init = vkiMemoryMapPlacedInfoEXT_null();
		init.pPlacedAddress = pPlacedAddress;
		return init;
	}

	static inline VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT vkiPhysicalDeviceShaderAtomicFloat2FeaturesEXT_null()
	{
		VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT vkiPhysicalDeviceShaderAtomicFloat2FeaturesEXT(VkBool32 shaderBufferFloat16Atomics, VkBool32 shaderBufferFloat16AtomicAdd, VkBool32 shaderBufferFloat16AtomicMinMax, VkBool32 shaderBufferFloat32AtomicMinMax, VkBool32 shaderBufferFloat64AtomicMinMax, VkBool32 shaderSharedFloat16Atomics, VkBool32 shaderSharedFloat16AtomicAdd, VkBool32 shaderSharedFloat16AtomicMinMax, VkBool32 shaderSharedFloat32AtomicMinMax, VkBool32 shaderSharedFloat64AtomicMinMax, VkBool32 shaderImageFloat32AtomicMinMax, VkBool32 sparseImageFloat32AtomicMinMax)
	{
		VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT init = vkiPhysicalDeviceShaderAtomicFloat2FeaturesEXT_null();
		init.shaderBufferFloat16Atomics = shaderBufferFloat16Atomics;
		init.shaderBufferFloat16AtomicAdd = shaderBufferFloat16AtomicAdd;
		init.shaderBufferFloat16AtomicMinMax = shaderBufferFloat16AtomicMinMax;
		init.shaderBufferFloat32AtomicMinMax = shaderBufferFloat32AtomicMinMax;
		init.shaderBufferFloat64AtomicMinMax = shaderBufferFloat64AtomicMinMax;
		init.shaderSharedFloat16Atomics = shaderSharedFloat16Atomics;
		init.shaderSharedFloat16AtomicAdd = shaderSharedFloat16AtomicAdd;
		init.shaderSharedFloat16AtomicMinMax = shaderSharedFloat16AtomicMinMax;
		init.shaderSharedFloat32AtomicMinMax = shaderSharedFloat32AtomicMinMax;
		init.shaderSharedFloat64AtomicMinMax = shaderSharedFloat64AtomicMinMax;
		init.shaderImageFloat32AtomicMinMax = shaderImageFloat32AtomicMinMax;
		init.sparseImageFloat32AtomicMinMax = sparseImageFloat32AtomicMinMax;
		return init;
	}

	static inline VkSurfacePresentModeEXT vkiSurfacePresentModeEXT_null()
	{
		VkSurfacePresentModeEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT;
		return init;
	}

	static inline VkSurfacePresentModeEXT vkiSurfacePresentModeEXT(VkPresentModeKHR presentMode)
	{
		VkSurfacePresentModeEXT init = vkiSurfacePresentModeEXT_null();
		init.presentMode = presentMode;
		return init;
	}

	static inline VkSurfacePresentScalingCapabilitiesEXT vkiSurfacePresentScalingCapabilitiesEXT_null()
	{
		VkSurfacePresentScalingCapabilitiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT;
		return init;
	}

	static inline VkSurfacePresentScalingCapabilitiesEXT vkiSurfacePresentScalingCapabilitiesEXT(VkPresentScalingFlagsEXT supportedPresentScaling, VkPresentGravityFlagsEXT supportedPresentGravityX, VkPresentGravityFlagsEXT supportedPresentGravityY, VkExtent2D minScaledImageExtent, VkExtent2D maxScaledImageExtent)
	{
		VkSurfacePresentScalingCapabilitiesEXT init = vkiSurfacePresentScalingCapabilitiesEXT_null();
		init.supportedPresentScaling = supportedPresentScaling;
		init.supportedPresentGravityX = supportedPresentGravityX;
		init.supportedPresentGravityY = supportedPresentGravityY;
		init.minScaledImageExtent = minScaledImageExtent;
		init.maxScaledImageExtent = maxScaledImageExtent;
		return init;
	}

	static inline VkSurfacePresentModeCompatibilityEXT vkiSurfacePresentModeCompatibilityEXT_null()
	{
		VkSurfacePresentModeCompatibilityEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT;
		return init;
	}

	static inline VkSurfacePresentModeCompatibilityEXT vkiSurfacePresentModeCompatibilityEXT(uint32_t presentModeCount, VkPresentModeKHR *pPresentModes)
	{
		VkSurfacePresentModeCompatibilityEXT init = vkiSurfacePresentModeCompatibilityEXT_null();
		init.presentModeCount = presentModeCount;
		init.pPresentModes = pPresentModes;
		return init;
	}

	static inline VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT vkiPhysicalDeviceSwapchainMaintenance1FeaturesEXT_null()
	{
		VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT vkiPhysicalDeviceSwapchainMaintenance1FeaturesEXT(VkBool32 swapchainMaintenance1)
	{
		VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT init = vkiPhysicalDeviceSwapchainMaintenance1FeaturesEXT_null();
		init.swapchainMaintenance1 = swapchainMaintenance1;
		return init;
	}

	static inline VkSwapchainPresentFenceInfoEXT vkiSwapchainPresentFenceInfoEXT_null()
	{
		VkSwapchainPresentFenceInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT;
		return init;
	}

	static inline VkSwapchainPresentFenceInfoEXT vkiSwapchainPresentFenceInfoEXT(uint32_t swapchainCount, const VkFence *pFences)
	{
		VkSwapchainPresentFenceInfoEXT init = vkiSwapchainPresentFenceInfoEXT_null();
		init.swapchainCount = swapchainCount;
		init.pFences = pFences;
		return init;
	}

	static inline VkSwapchainPresentModesCreateInfoEXT vkiSwapchainPresentModesCreateInfoEXT_null()
	{
		VkSwapchainPresentModesCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT;
		return init;
	}

	static inline VkSwapchainPresentModesCreateInfoEXT vkiSwapchainPresentModesCreateInfoEXT(uint32_t presentModeCount, const VkPresentModeKHR *pPresentModes)
	{
		VkSwapchainPresentModesCreateInfoEXT init = vkiSwapchainPresentModesCreateInfoEXT_null();
		init.presentModeCount = presentModeCount;
		init.pPresentModes = pPresentModes;
		return init;
	}

	static inline VkSwapchainPresentModeInfoEXT vkiSwapchainPresentModeInfoEXT_null()
	{
		VkSwapchainPresentModeInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT;
		return init;
	}

	static inline VkSwapchainPresentModeInfoEXT vkiSwapchainPresentModeInfoEXT(uint32_t swapchainCount, const VkPresentModeKHR *pPresentModes)
	{
		VkSwapchainPresentModeInfoEXT init = vkiSwapchainPresentModeInfoEXT_null();
		init.swapchainCount = swapchainCount;
		init.pPresentModes = pPresentModes;
		return init;
	}

	static inline VkSwapchainPresentScalingCreateInfoEXT vkiSwapchainPresentScalingCreateInfoEXT_null()
	{
		VkSwapchainPresentScalingCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT;
		return init;
	}

	static inline VkSwapchainPresentScalingCreateInfoEXT vkiSwapchainPresentScalingCreateInfoEXT(VkPresentScalingFlagsEXT scalingBehavior, VkPresentGravityFlagsEXT presentGravityX, VkPresentGravityFlagsEXT presentGravityY)
	{
		VkSwapchainPresentScalingCreateInfoEXT init = vkiSwapchainPresentScalingCreateInfoEXT_null();
		init.scalingBehavior = scalingBehavior;
		init.presentGravityX = presentGravityX;
		init.presentGravityY = presentGravityY;
		return init;
	}

	static inline VkReleaseSwapchainImagesInfoEXT vkiReleaseSwapchainImagesInfoEXT_null()
	{
		VkReleaseSwapchainImagesInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT;
		return init;
	}

	static inline VkReleaseSwapchainImagesInfoEXT vkiReleaseSwapchainImagesInfoEXT(VkSwapchainKHR swapchain, uint32_t imageIndexCount, const uint32_t *pImageIndices)
	{
		VkReleaseSwapchainImagesInfoEXT init = vkiReleaseSwapchainImagesInfoEXT_null();
		init.swapchain = swapchain;
		init.imageIndexCount = imageIndexCount;
		init.pImageIndices = pImageIndices;
		return init;
	}

	static inline VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV vkiPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_null()
	{
		VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV;
		return init;
	}

	static inline VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV vkiPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(uint32_t maxGraphicsShaderGroupCount, uint32_t maxIndirectSequenceCount, uint32_t maxIndirectCommandsTokenCount, uint32_t maxIndirectCommandsStreamCount, uint32_t maxIndirectCommandsTokenOffset, uint32_t maxIndirectCommandsStreamStride, uint32_t minSequencesCountBufferOffsetAlignment, uint32_t minSequencesIndexBufferOffsetAlignment, uint32_t minIndirectCommandsBufferOffsetAlignment)
	{
		VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV init = vkiPhysicalDeviceDeviceGeneratedCommandsPropertiesNV_null();
		init.maxGraphicsShaderGroupCount = maxGraphicsShaderGroupCount;
		init.maxIndirectSequenceCount = maxIndirectSequenceCount;
		init.maxIndirectCommandsTokenCount = maxIndirectCommandsTokenCount;
		init.maxIndirectCommandsStreamCount = maxIndirectCommandsStreamCount;
		init.maxIndirectCommandsTokenOffset = maxIndirectCommandsTokenOffset;
		init.maxIndirectCommandsStreamStride = maxIndirectCommandsStreamStride;
		init.minSequencesCountBufferOffsetAlignment = minSequencesCountBufferOffsetAlignment;
		init.minSequencesIndexBufferOffsetAlignment = minSequencesIndexBufferOffsetAlignment;
		init.minIndirectCommandsBufferOffsetAlignment = minIndirectCommandsBufferOffsetAlignment;
		return init;
	}

	static inline VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV vkiPhysicalDeviceDeviceGeneratedCommandsFeaturesNV_null()
	{
		VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV vkiPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(VkBool32 deviceGeneratedCommands)
	{
		VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV init = vkiPhysicalDeviceDeviceGeneratedCommandsFeaturesNV_null();
		init.deviceGeneratedCommands = deviceGeneratedCommands;
		return init;
	}

	static inline VkGraphicsShaderGroupCreateInfoNV vkiGraphicsShaderGroupCreateInfoNV_null()
	{
		VkGraphicsShaderGroupCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV;
		return init;
	}

	static inline VkGraphicsShaderGroupCreateInfoNV vkiGraphicsShaderGroupCreateInfoNV(uint32_t stageCount, const VkPipelineShaderStageCreateInfo *pStages, const VkPipelineVertexInputStateCreateInfo *pVertexInputState, const VkPipelineTessellationStateCreateInfo *pTessellationState)
	{
		VkGraphicsShaderGroupCreateInfoNV init = vkiGraphicsShaderGroupCreateInfoNV_null();
		init.stageCount = stageCount;
		init.pStages = pStages;
		init.pVertexInputState = pVertexInputState;
		init.pTessellationState = pTessellationState;
		return init;
	}

	static inline VkGraphicsPipelineShaderGroupsCreateInfoNV vkiGraphicsPipelineShaderGroupsCreateInfoNV_null()
	{
		VkGraphicsPipelineShaderGroupsCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV;
		return init;
	}

	static inline VkGraphicsPipelineShaderGroupsCreateInfoNV vkiGraphicsPipelineShaderGroupsCreateInfoNV(uint32_t groupCount, const VkGraphicsShaderGroupCreateInfoNV *pGroups, uint32_t pipelineCount, const VkPipeline *pPipelines)
	{
		VkGraphicsPipelineShaderGroupsCreateInfoNV init = vkiGraphicsPipelineShaderGroupsCreateInfoNV_null();
		init.groupCount = groupCount;
		init.pGroups = pGroups;
		init.pipelineCount = pipelineCount;
		init.pPipelines = pPipelines;
		return init;
	}

	static inline VkBindShaderGroupIndirectCommandNV vkiBindShaderGroupIndirectCommandNV_null()
	{
		VkBindShaderGroupIndirectCommandNV init = {0};
		return init;
	}

	static inline VkBindShaderGroupIndirectCommandNV vkiBindShaderGroupIndirectCommandNV(uint32_t groupIndex)
	{
		VkBindShaderGroupIndirectCommandNV init = vkiBindShaderGroupIndirectCommandNV_null();
		init.groupIndex = groupIndex;
		return init;
	}

	static inline VkBindIndexBufferIndirectCommandNV vkiBindIndexBufferIndirectCommandNV_null()
	{
		VkBindIndexBufferIndirectCommandNV init = {0};
		return init;
	}

	static inline VkBindIndexBufferIndirectCommandNV vkiBindIndexBufferIndirectCommandNV(VkDeviceAddress bufferAddress, uint32_t size, VkIndexType indexType)
	{
		VkBindIndexBufferIndirectCommandNV init = vkiBindIndexBufferIndirectCommandNV_null();
		init.bufferAddress = bufferAddress;
		init.size = size;
		init.indexType = indexType;
		return init;
	}

	static inline VkBindVertexBufferIndirectCommandNV vkiBindVertexBufferIndirectCommandNV_null()
	{
		VkBindVertexBufferIndirectCommandNV init = {0};
		return init;
	}

	static inline VkBindVertexBufferIndirectCommandNV vkiBindVertexBufferIndirectCommandNV(VkDeviceAddress bufferAddress, uint32_t size, uint32_t stride)
	{
		VkBindVertexBufferIndirectCommandNV init = vkiBindVertexBufferIndirectCommandNV_null();
		init.bufferAddress = bufferAddress;
		init.size = size;
		init.stride = stride;
		return init;
	}

	static inline VkSetStateFlagsIndirectCommandNV vkiSetStateFlagsIndirectCommandNV_null()
	{
		VkSetStateFlagsIndirectCommandNV init = {0};
		return init;
	}

	static inline VkSetStateFlagsIndirectCommandNV vkiSetStateFlagsIndirectCommandNV(uint32_t data)
	{
		VkSetStateFlagsIndirectCommandNV init = vkiSetStateFlagsIndirectCommandNV_null();
		init.data = data;
		return init;
	}

	static inline VkIndirectCommandsStreamNV vkiIndirectCommandsStreamNV_null()
	{
		VkIndirectCommandsStreamNV init = {0};
		return init;
	}

	static inline VkIndirectCommandsStreamNV vkiIndirectCommandsStreamNV(VkBuffer buffer, VkDeviceSize offset)
	{
		VkIndirectCommandsStreamNV init = vkiIndirectCommandsStreamNV_null();
		init.buffer = buffer;
		init.offset = offset;
		return init;
	}

	static inline VkIndirectCommandsLayoutTokenNV vkiIndirectCommandsLayoutTokenNV_null()
	{
		VkIndirectCommandsLayoutTokenNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV;
		return init;
	}

	static inline VkIndirectCommandsLayoutTokenNV vkiIndirectCommandsLayoutTokenNV(VkIndirectCommandsTokenTypeNV tokenType, uint32_t stream, uint32_t offset, uint32_t vertexBindingUnit, VkBool32 vertexDynamicStride, VkPipelineLayout pushconstantPipelineLayout, VkShaderStageFlags pushconstantShaderStageFlags, uint32_t pushconstantOffset, uint32_t pushconstantSize, VkIndirectStateFlagsNV indirectStateFlags, uint32_t indexTypeCount, const VkIndexType *pIndexTypes, const uint32_t *pIndexTypeValues)
	{
		VkIndirectCommandsLayoutTokenNV init = vkiIndirectCommandsLayoutTokenNV_null();
		init.tokenType = tokenType;
		init.stream = stream;
		init.offset = offset;
		init.vertexBindingUnit = vertexBindingUnit;
		init.vertexDynamicStride = vertexDynamicStride;
		init.pushconstantPipelineLayout = pushconstantPipelineLayout;
		init.pushconstantShaderStageFlags = pushconstantShaderStageFlags;
		init.pushconstantOffset = pushconstantOffset;
		init.pushconstantSize = pushconstantSize;
		init.indirectStateFlags = indirectStateFlags;
		init.indexTypeCount = indexTypeCount;
		init.pIndexTypes = pIndexTypes;
		init.pIndexTypeValues = pIndexTypeValues;
		return init;
	}

	static inline VkIndirectCommandsLayoutCreateInfoNV vkiIndirectCommandsLayoutCreateInfoNV_null()
	{
		VkIndirectCommandsLayoutCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV;
		return init;
	}

	static inline VkIndirectCommandsLayoutCreateInfoNV vkiIndirectCommandsLayoutCreateInfoNV(VkPipelineBindPoint pipelineBindPoint, uint32_t tokenCount, const VkIndirectCommandsLayoutTokenNV *pTokens, uint32_t streamCount, const uint32_t *pStreamStrides)
	{
		VkIndirectCommandsLayoutCreateInfoNV init = vkiIndirectCommandsLayoutCreateInfoNV_null();
		init.pipelineBindPoint = pipelineBindPoint;
		init.tokenCount = tokenCount;
		init.pTokens = pTokens;
		init.streamCount = streamCount;
		init.pStreamStrides = pStreamStrides;
		return init;
	}

	static inline VkGeneratedCommandsInfoNV vkiGeneratedCommandsInfoNV_null()
	{
		VkGeneratedCommandsInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV;
		return init;
	}

	static inline VkGeneratedCommandsInfoNV vkiGeneratedCommandsInfoNV(VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, VkIndirectCommandsLayoutNV indirectCommandsLayout, uint32_t streamCount, const VkIndirectCommandsStreamNV *pStreams, uint32_t sequencesCount, VkBuffer preprocessBuffer, VkDeviceSize preprocessOffset, VkDeviceSize preprocessSize, VkBuffer sequencesCountBuffer, VkDeviceSize sequencesCountOffset, VkBuffer sequencesIndexBuffer, VkDeviceSize sequencesIndexOffset)
	{
		VkGeneratedCommandsInfoNV init = vkiGeneratedCommandsInfoNV_null();
		init.pipelineBindPoint = pipelineBindPoint;
		init.pipeline = pipeline;
		init.indirectCommandsLayout = indirectCommandsLayout;
		init.streamCount = streamCount;
		init.pStreams = pStreams;
		init.sequencesCount = sequencesCount;
		init.preprocessBuffer = preprocessBuffer;
		init.preprocessOffset = preprocessOffset;
		init.preprocessSize = preprocessSize;
		init.sequencesCountBuffer = sequencesCountBuffer;
		init.sequencesCountOffset = sequencesCountOffset;
		init.sequencesIndexBuffer = sequencesIndexBuffer;
		init.sequencesIndexOffset = sequencesIndexOffset;
		return init;
	}

	static inline VkGeneratedCommandsMemoryRequirementsInfoNV vkiGeneratedCommandsMemoryRequirementsInfoNV_null()
	{
		VkGeneratedCommandsMemoryRequirementsInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV;
		return init;
	}

	static inline VkGeneratedCommandsMemoryRequirementsInfoNV vkiGeneratedCommandsMemoryRequirementsInfoNV(VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, VkIndirectCommandsLayoutNV indirectCommandsLayout, uint32_t maxSequencesCount)
	{
		VkGeneratedCommandsMemoryRequirementsInfoNV init = vkiGeneratedCommandsMemoryRequirementsInfoNV_null();
		init.pipelineBindPoint = pipelineBindPoint;
		init.pipeline = pipeline;
		init.indirectCommandsLayout = indirectCommandsLayout;
		init.maxSequencesCount = maxSequencesCount;
		return init;
	}

	static inline VkPhysicalDeviceInheritedViewportScissorFeaturesNV vkiPhysicalDeviceInheritedViewportScissorFeaturesNV_null()
	{
		VkPhysicalDeviceInheritedViewportScissorFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceInheritedViewportScissorFeaturesNV vkiPhysicalDeviceInheritedViewportScissorFeaturesNV(VkBool32 inheritedViewportScissor2D)
	{
		VkPhysicalDeviceInheritedViewportScissorFeaturesNV init = vkiPhysicalDeviceInheritedViewportScissorFeaturesNV_null();
		init.inheritedViewportScissor2D = inheritedViewportScissor2D;
		return init;
	}

	static inline VkCommandBufferInheritanceViewportScissorInfoNV vkiCommandBufferInheritanceViewportScissorInfoNV_null()
	{
		VkCommandBufferInheritanceViewportScissorInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV;
		return init;
	}

	static inline VkCommandBufferInheritanceViewportScissorInfoNV vkiCommandBufferInheritanceViewportScissorInfoNV(VkBool32 viewportScissor2D, uint32_t viewportDepthCount, const VkViewport *pViewportDepths)
	{
		VkCommandBufferInheritanceViewportScissorInfoNV init = vkiCommandBufferInheritanceViewportScissorInfoNV_null();
		init.viewportScissor2D = viewportScissor2D;
		init.viewportDepthCount = viewportDepthCount;
		init.pViewportDepths = pViewportDepths;
		return init;
	}

	static inline VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT vkiPhysicalDeviceTexelBufferAlignmentFeaturesEXT_null()
	{
		VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT vkiPhysicalDeviceTexelBufferAlignmentFeaturesEXT(VkBool32 texelBufferAlignment)
	{
		VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT init = vkiPhysicalDeviceTexelBufferAlignmentFeaturesEXT_null();
		init.texelBufferAlignment = texelBufferAlignment;
		return init;
	}

	static inline VkRenderPassTransformBeginInfoQCOM vkiRenderPassTransformBeginInfoQCOM_null()
	{
		VkRenderPassTransformBeginInfoQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM;
		return init;
	}

	static inline VkRenderPassTransformBeginInfoQCOM vkiRenderPassTransformBeginInfoQCOM(VkSurfaceTransformFlagBitsKHR transform)
	{
		VkRenderPassTransformBeginInfoQCOM init = vkiRenderPassTransformBeginInfoQCOM_null();
		init.transform = transform;
		return init;
	}

	static inline VkCommandBufferInheritanceRenderPassTransformInfoQCOM vkiCommandBufferInheritanceRenderPassTransformInfoQCOM_null()
	{
		VkCommandBufferInheritanceRenderPassTransformInfoQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM;
		return init;
	}

	static inline VkCommandBufferInheritanceRenderPassTransformInfoQCOM vkiCommandBufferInheritanceRenderPassTransformInfoQCOM(VkSurfaceTransformFlagBitsKHR transform, VkRect2D renderArea)
	{
		VkCommandBufferInheritanceRenderPassTransformInfoQCOM init = vkiCommandBufferInheritanceRenderPassTransformInfoQCOM_null();
		init.transform = transform;
		init.renderArea = renderArea;
		return init;
	}

	static inline VkPhysicalDeviceDepthBiasControlFeaturesEXT vkiPhysicalDeviceDepthBiasControlFeaturesEXT_null()
	{
		VkPhysicalDeviceDepthBiasControlFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceDepthBiasControlFeaturesEXT vkiPhysicalDeviceDepthBiasControlFeaturesEXT(VkBool32 depthBiasControl, VkBool32 leastRepresentableValueForceUnormRepresentation, VkBool32 floatRepresentation, VkBool32 depthBiasExact)
	{
		VkPhysicalDeviceDepthBiasControlFeaturesEXT init = vkiPhysicalDeviceDepthBiasControlFeaturesEXT_null();
		init.depthBiasControl = depthBiasControl;
		init.leastRepresentableValueForceUnormRepresentation = leastRepresentableValueForceUnormRepresentation;
		init.floatRepresentation = floatRepresentation;
		init.depthBiasExact = depthBiasExact;
		return init;
	}

	static inline VkDepthBiasInfoEXT vkiDepthBiasInfoEXT_null()
	{
		VkDepthBiasInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT;
		return init;
	}

	static inline VkDepthBiasInfoEXT vkiDepthBiasInfoEXT(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor)
	{
		VkDepthBiasInfoEXT init = vkiDepthBiasInfoEXT_null();
		init.depthBiasConstantFactor = depthBiasConstantFactor;
		init.depthBiasClamp = depthBiasClamp;
		init.depthBiasSlopeFactor = depthBiasSlopeFactor;
		return init;
	}

	static inline VkDepthBiasRepresentationInfoEXT vkiDepthBiasRepresentationInfoEXT_null()
	{
		VkDepthBiasRepresentationInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT;
		return init;
	}

	static inline VkDepthBiasRepresentationInfoEXT vkiDepthBiasRepresentationInfoEXT(VkDepthBiasRepresentationEXT depthBiasRepresentation, VkBool32 depthBiasExact)
	{
		VkDepthBiasRepresentationInfoEXT init = vkiDepthBiasRepresentationInfoEXT_null();
		init.depthBiasRepresentation = depthBiasRepresentation;
		init.depthBiasExact = depthBiasExact;
		return init;
	}

	static inline VkPhysicalDeviceDeviceMemoryReportFeaturesEXT vkiPhysicalDeviceDeviceMemoryReportFeaturesEXT_null()
	{
		VkPhysicalDeviceDeviceMemoryReportFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceDeviceMemoryReportFeaturesEXT vkiPhysicalDeviceDeviceMemoryReportFeaturesEXT(VkBool32 deviceMemoryReport)
	{
		VkPhysicalDeviceDeviceMemoryReportFeaturesEXT init = vkiPhysicalDeviceDeviceMemoryReportFeaturesEXT_null();
		init.deviceMemoryReport = deviceMemoryReport;
		return init;
	}

	static inline VkDeviceMemoryReportCallbackDataEXT vkiDeviceMemoryReportCallbackDataEXT_null()
	{
		VkDeviceMemoryReportCallbackDataEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT;
		return init;
	}

	static inline VkDeviceMemoryReportCallbackDataEXT vkiDeviceMemoryReportCallbackDataEXT(VkDeviceMemoryReportEventTypeEXT type, uint64_t memoryObjectId, VkDeviceSize size, VkObjectType objectType, uint64_t objectHandle, uint32_t heapIndex)
	{
		VkDeviceMemoryReportCallbackDataEXT init = vkiDeviceMemoryReportCallbackDataEXT_null();
		init.type = type;
		init.memoryObjectId = memoryObjectId;
		init.size = size;
		init.objectType = objectType;
		init.objectHandle = objectHandle;
		init.heapIndex = heapIndex;
		return init;
	}

	static inline VkDeviceDeviceMemoryReportCreateInfoEXT vkiDeviceDeviceMemoryReportCreateInfoEXT_null()
	{
		VkDeviceDeviceMemoryReportCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT;
		return init;
	}

	static inline VkDeviceDeviceMemoryReportCreateInfoEXT vkiDeviceDeviceMemoryReportCreateInfoEXT(PFN_vkDeviceMemoryReportCallbackEXT pfnUserCallback, void *pUserData)
	{
		VkDeviceDeviceMemoryReportCreateInfoEXT init = vkiDeviceDeviceMemoryReportCreateInfoEXT_null();
		init.pfnUserCallback = pfnUserCallback;
		init.pUserData = pUserData;
		return init;
	}

	static inline VkPhysicalDeviceRobustness2FeaturesEXT vkiPhysicalDeviceRobustness2FeaturesEXT_null()
	{
		VkPhysicalDeviceRobustness2FeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceRobustness2FeaturesEXT vkiPhysicalDeviceRobustness2FeaturesEXT(VkBool32 robustBufferAccess2, VkBool32 robustImageAccess2, VkBool32 nullDescriptor)
	{
		VkPhysicalDeviceRobustness2FeaturesEXT init = vkiPhysicalDeviceRobustness2FeaturesEXT_null();
		init.robustBufferAccess2 = robustBufferAccess2;
		init.robustImageAccess2 = robustImageAccess2;
		init.nullDescriptor = nullDescriptor;
		return init;
	}

	static inline VkPhysicalDeviceRobustness2PropertiesEXT vkiPhysicalDeviceRobustness2PropertiesEXT_null()
	{
		VkPhysicalDeviceRobustness2PropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceRobustness2PropertiesEXT vkiPhysicalDeviceRobustness2PropertiesEXT(VkDeviceSize robustStorageBufferAccessSizeAlignment, VkDeviceSize robustUniformBufferAccessSizeAlignment)
	{
		VkPhysicalDeviceRobustness2PropertiesEXT init = vkiPhysicalDeviceRobustness2PropertiesEXT_null();
		init.robustStorageBufferAccessSizeAlignment = robustStorageBufferAccessSizeAlignment;
		init.robustUniformBufferAccessSizeAlignment = robustUniformBufferAccessSizeAlignment;
		return init;
	}

	static inline VkSamplerCustomBorderColorCreateInfoEXT vkiSamplerCustomBorderColorCreateInfoEXT_null()
	{
		VkSamplerCustomBorderColorCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT;
		return init;
	}

	static inline VkSamplerCustomBorderColorCreateInfoEXT vkiSamplerCustomBorderColorCreateInfoEXT(VkClearColorValue customBorderColor, VkFormat format)
	{
		VkSamplerCustomBorderColorCreateInfoEXT init = vkiSamplerCustomBorderColorCreateInfoEXT_null();
		init.customBorderColor = customBorderColor;
		init.format = format;
		return init;
	}

	static inline VkPhysicalDeviceCustomBorderColorPropertiesEXT vkiPhysicalDeviceCustomBorderColorPropertiesEXT_null()
	{
		VkPhysicalDeviceCustomBorderColorPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceCustomBorderColorPropertiesEXT vkiPhysicalDeviceCustomBorderColorPropertiesEXT(uint32_t maxCustomBorderColorSamplers)
	{
		VkPhysicalDeviceCustomBorderColorPropertiesEXT init = vkiPhysicalDeviceCustomBorderColorPropertiesEXT_null();
		init.maxCustomBorderColorSamplers = maxCustomBorderColorSamplers;
		return init;
	}

	static inline VkPhysicalDeviceCustomBorderColorFeaturesEXT vkiPhysicalDeviceCustomBorderColorFeaturesEXT_null()
	{
		VkPhysicalDeviceCustomBorderColorFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceCustomBorderColorFeaturesEXT vkiPhysicalDeviceCustomBorderColorFeaturesEXT(VkBool32 customBorderColors, VkBool32 customBorderColorWithoutFormat)
	{
		VkPhysicalDeviceCustomBorderColorFeaturesEXT init = vkiPhysicalDeviceCustomBorderColorFeaturesEXT_null();
		init.customBorderColors = customBorderColors;
		init.customBorderColorWithoutFormat = customBorderColorWithoutFormat;
		return init;
	}

	static inline VkPhysicalDevicePresentBarrierFeaturesNV vkiPhysicalDevicePresentBarrierFeaturesNV_null()
	{
		VkPhysicalDevicePresentBarrierFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDevicePresentBarrierFeaturesNV vkiPhysicalDevicePresentBarrierFeaturesNV(VkBool32 presentBarrier)
	{
		VkPhysicalDevicePresentBarrierFeaturesNV init = vkiPhysicalDevicePresentBarrierFeaturesNV_null();
		init.presentBarrier = presentBarrier;
		return init;
	}

	static inline VkSurfaceCapabilitiesPresentBarrierNV vkiSurfaceCapabilitiesPresentBarrierNV_null()
	{
		VkSurfaceCapabilitiesPresentBarrierNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV;
		return init;
	}

	static inline VkSurfaceCapabilitiesPresentBarrierNV vkiSurfaceCapabilitiesPresentBarrierNV(VkBool32 presentBarrierSupported)
	{
		VkSurfaceCapabilitiesPresentBarrierNV init = vkiSurfaceCapabilitiesPresentBarrierNV_null();
		init.presentBarrierSupported = presentBarrierSupported;
		return init;
	}

	static inline VkSwapchainPresentBarrierCreateInfoNV vkiSwapchainPresentBarrierCreateInfoNV_null()
	{
		VkSwapchainPresentBarrierCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV;
		return init;
	}

	static inline VkSwapchainPresentBarrierCreateInfoNV vkiSwapchainPresentBarrierCreateInfoNV(VkBool32 presentBarrierEnable)
	{
		VkSwapchainPresentBarrierCreateInfoNV init = vkiSwapchainPresentBarrierCreateInfoNV_null();
		init.presentBarrierEnable = presentBarrierEnable;
		return init;
	}

	static inline VkPhysicalDeviceDiagnosticsConfigFeaturesNV vkiPhysicalDeviceDiagnosticsConfigFeaturesNV_null()
	{
		VkPhysicalDeviceDiagnosticsConfigFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceDiagnosticsConfigFeaturesNV vkiPhysicalDeviceDiagnosticsConfigFeaturesNV(VkBool32 diagnosticsConfig)
	{
		VkPhysicalDeviceDiagnosticsConfigFeaturesNV init = vkiPhysicalDeviceDiagnosticsConfigFeaturesNV_null();
		init.diagnosticsConfig = diagnosticsConfig;
		return init;
	}

	static inline VkDeviceDiagnosticsConfigCreateInfoNV vkiDeviceDiagnosticsConfigCreateInfoNV_null()
	{
		VkDeviceDiagnosticsConfigCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV;
		return init;
	}

	static inline VkDeviceDiagnosticsConfigCreateInfoNV vkiDeviceDiagnosticsConfigCreateInfoNV()
	{
		VkDeviceDiagnosticsConfigCreateInfoNV init = vkiDeviceDiagnosticsConfigCreateInfoNV_null();
		return init;
	}

	static inline VkCudaModuleCreateInfoNV vkiCudaModuleCreateInfoNV_null()
	{
		VkCudaModuleCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV;
		return init;
	}

	static inline VkCudaModuleCreateInfoNV vkiCudaModuleCreateInfoNV(size_t dataSize, const void *pData)
	{
		VkCudaModuleCreateInfoNV init = vkiCudaModuleCreateInfoNV_null();
		init.dataSize = dataSize;
		init.pData = pData;
		return init;
	}

	static inline VkCudaFunctionCreateInfoNV vkiCudaFunctionCreateInfoNV_null()
	{
		VkCudaFunctionCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV;
		return init;
	}

	static inline VkCudaFunctionCreateInfoNV vkiCudaFunctionCreateInfoNV(VkCudaModuleNV module, const char *pName)
	{
		VkCudaFunctionCreateInfoNV init = vkiCudaFunctionCreateInfoNV_null();
		init.module = module;
		init.pName = pName;
		return init;
	}

	static inline VkCudaLaunchInfoNV vkiCudaLaunchInfoNV_null()
	{
		VkCudaLaunchInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV;
		return init;
	}

	static inline VkCudaLaunchInfoNV vkiCudaLaunchInfoNV(VkCudaFunctionNV function, uint32_t gridDimX, uint32_t gridDimY, uint32_t gridDimZ, uint32_t blockDimX, uint32_t blockDimY, uint32_t blockDimZ, uint32_t sharedMemBytes, size_t paramCount, const void *const *pParams, size_t extraCount, const void *const *pExtras)
	{
		VkCudaLaunchInfoNV init = vkiCudaLaunchInfoNV_null();
		init.function = function;
		init.gridDimX = gridDimX;
		init.gridDimY = gridDimY;
		init.gridDimZ = gridDimZ;
		init.blockDimX = blockDimX;
		init.blockDimY = blockDimY;
		init.blockDimZ = blockDimZ;
		init.sharedMemBytes = sharedMemBytes;
		init.paramCount = paramCount;
		init.pParams = pParams;
		init.extraCount = extraCount;
		init.pExtras = pExtras;
		return init;
	}

	static inline VkPhysicalDeviceCudaKernelLaunchFeaturesNV vkiPhysicalDeviceCudaKernelLaunchFeaturesNV_null()
	{
		VkPhysicalDeviceCudaKernelLaunchFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceCudaKernelLaunchFeaturesNV vkiPhysicalDeviceCudaKernelLaunchFeaturesNV(VkBool32 cudaKernelLaunchFeatures)
	{
		VkPhysicalDeviceCudaKernelLaunchFeaturesNV init = vkiPhysicalDeviceCudaKernelLaunchFeaturesNV_null();
		init.cudaKernelLaunchFeatures = cudaKernelLaunchFeatures;
		return init;
	}

	static inline VkPhysicalDeviceCudaKernelLaunchPropertiesNV vkiPhysicalDeviceCudaKernelLaunchPropertiesNV_null()
	{
		VkPhysicalDeviceCudaKernelLaunchPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV;
		return init;
	}

	static inline VkPhysicalDeviceCudaKernelLaunchPropertiesNV vkiPhysicalDeviceCudaKernelLaunchPropertiesNV(uint32_t computeCapabilityMinor, uint32_t computeCapabilityMajor)
	{
		VkPhysicalDeviceCudaKernelLaunchPropertiesNV init = vkiPhysicalDeviceCudaKernelLaunchPropertiesNV_null();
		init.computeCapabilityMinor = computeCapabilityMinor;
		init.computeCapabilityMajor = computeCapabilityMajor;
		return init;
	}

	static inline VkQueryLowLatencySupportNV vkiQueryLowLatencySupportNV_null()
	{
		VkQueryLowLatencySupportNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV;
		return init;
	}

	static inline VkQueryLowLatencySupportNV vkiQueryLowLatencySupportNV(void *pQueriedLowLatencyData)
	{
		VkQueryLowLatencySupportNV init = vkiQueryLowLatencySupportNV_null();
		init.pQueriedLowLatencyData = pQueriedLowLatencyData;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorBufferPropertiesEXT vkiPhysicalDeviceDescriptorBufferPropertiesEXT_null()
	{
		VkPhysicalDeviceDescriptorBufferPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorBufferPropertiesEXT vkiPhysicalDeviceDescriptorBufferPropertiesEXT(VkBool32 combinedImageSamplerDescriptorSingleArray, VkBool32 bufferlessPushDescriptors, VkBool32 allowSamplerImageViewPostSubmitCreation, VkDeviceSize descriptorBufferOffsetAlignment, uint32_t maxDescriptorBufferBindings, uint32_t maxResourceDescriptorBufferBindings, uint32_t maxSamplerDescriptorBufferBindings, uint32_t maxEmbeddedImmutableSamplerBindings, uint32_t maxEmbeddedImmutableSamplers, size_t bufferCaptureReplayDescriptorDataSize, size_t imageCaptureReplayDescriptorDataSize, size_t imageViewCaptureReplayDescriptorDataSize, size_t samplerCaptureReplayDescriptorDataSize, size_t accelerationStructureCaptureReplayDescriptorDataSize, size_t samplerDescriptorSize, size_t combinedImageSamplerDescriptorSize, size_t sampledImageDescriptorSize, size_t storageImageDescriptorSize, size_t uniformTexelBufferDescriptorSize, size_t robustUniformTexelBufferDescriptorSize, size_t storageTexelBufferDescriptorSize, size_t robustStorageTexelBufferDescriptorSize, size_t uniformBufferDescriptorSize, size_t robustUniformBufferDescriptorSize, size_t storageBufferDescriptorSize, size_t robustStorageBufferDescriptorSize, size_t inputAttachmentDescriptorSize, size_t accelerationStructureDescriptorSize, VkDeviceSize maxSamplerDescriptorBufferRange, VkDeviceSize maxResourceDescriptorBufferRange, VkDeviceSize samplerDescriptorBufferAddressSpaceSize, VkDeviceSize resourceDescriptorBufferAddressSpaceSize, VkDeviceSize descriptorBufferAddressSpaceSize)
	{
		VkPhysicalDeviceDescriptorBufferPropertiesEXT init = vkiPhysicalDeviceDescriptorBufferPropertiesEXT_null();
		init.combinedImageSamplerDescriptorSingleArray = combinedImageSamplerDescriptorSingleArray;
		init.bufferlessPushDescriptors = bufferlessPushDescriptors;
		init.allowSamplerImageViewPostSubmitCreation = allowSamplerImageViewPostSubmitCreation;
		init.descriptorBufferOffsetAlignment = descriptorBufferOffsetAlignment;
		init.maxDescriptorBufferBindings = maxDescriptorBufferBindings;
		init.maxResourceDescriptorBufferBindings = maxResourceDescriptorBufferBindings;
		init.maxSamplerDescriptorBufferBindings = maxSamplerDescriptorBufferBindings;
		init.maxEmbeddedImmutableSamplerBindings = maxEmbeddedImmutableSamplerBindings;
		init.maxEmbeddedImmutableSamplers = maxEmbeddedImmutableSamplers;
		init.bufferCaptureReplayDescriptorDataSize = bufferCaptureReplayDescriptorDataSize;
		init.imageCaptureReplayDescriptorDataSize = imageCaptureReplayDescriptorDataSize;
		init.imageViewCaptureReplayDescriptorDataSize = imageViewCaptureReplayDescriptorDataSize;
		init.samplerCaptureReplayDescriptorDataSize = samplerCaptureReplayDescriptorDataSize;
		init.accelerationStructureCaptureReplayDescriptorDataSize = accelerationStructureCaptureReplayDescriptorDataSize;
		init.samplerDescriptorSize = samplerDescriptorSize;
		init.combinedImageSamplerDescriptorSize = combinedImageSamplerDescriptorSize;
		init.sampledImageDescriptorSize = sampledImageDescriptorSize;
		init.storageImageDescriptorSize = storageImageDescriptorSize;
		init.uniformTexelBufferDescriptorSize = uniformTexelBufferDescriptorSize;
		init.robustUniformTexelBufferDescriptorSize = robustUniformTexelBufferDescriptorSize;
		init.storageTexelBufferDescriptorSize = storageTexelBufferDescriptorSize;
		init.robustStorageTexelBufferDescriptorSize = robustStorageTexelBufferDescriptorSize;
		init.uniformBufferDescriptorSize = uniformBufferDescriptorSize;
		init.robustUniformBufferDescriptorSize = robustUniformBufferDescriptorSize;
		init.storageBufferDescriptorSize = storageBufferDescriptorSize;
		init.robustStorageBufferDescriptorSize = robustStorageBufferDescriptorSize;
		init.inputAttachmentDescriptorSize = inputAttachmentDescriptorSize;
		init.accelerationStructureDescriptorSize = accelerationStructureDescriptorSize;
		init.maxSamplerDescriptorBufferRange = maxSamplerDescriptorBufferRange;
		init.maxResourceDescriptorBufferRange = maxResourceDescriptorBufferRange;
		init.samplerDescriptorBufferAddressSpaceSize = samplerDescriptorBufferAddressSpaceSize;
		init.resourceDescriptorBufferAddressSpaceSize = resourceDescriptorBufferAddressSpaceSize;
		init.descriptorBufferAddressSpaceSize = descriptorBufferAddressSpaceSize;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT vkiPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT_null()
	{
		VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT vkiPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT(size_t combinedImageSamplerDensityMapDescriptorSize)
	{
		VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT init = vkiPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT_null();
		init.combinedImageSamplerDensityMapDescriptorSize = combinedImageSamplerDensityMapDescriptorSize;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorBufferFeaturesEXT vkiPhysicalDeviceDescriptorBufferFeaturesEXT_null()
	{
		VkPhysicalDeviceDescriptorBufferFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorBufferFeaturesEXT vkiPhysicalDeviceDescriptorBufferFeaturesEXT(VkBool32 descriptorBuffer, VkBool32 descriptorBufferCaptureReplay, VkBool32 descriptorBufferImageLayoutIgnored, VkBool32 descriptorBufferPushDescriptors)
	{
		VkPhysicalDeviceDescriptorBufferFeaturesEXT init = vkiPhysicalDeviceDescriptorBufferFeaturesEXT_null();
		init.descriptorBuffer = descriptorBuffer;
		init.descriptorBufferCaptureReplay = descriptorBufferCaptureReplay;
		init.descriptorBufferImageLayoutIgnored = descriptorBufferImageLayoutIgnored;
		init.descriptorBufferPushDescriptors = descriptorBufferPushDescriptors;
		return init;
	}

	static inline VkDescriptorAddressInfoEXT vkiDescriptorAddressInfoEXT_null()
	{
		VkDescriptorAddressInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT;
		return init;
	}

	static inline VkDescriptorAddressInfoEXT vkiDescriptorAddressInfoEXT(VkDeviceAddress address, VkDeviceSize range, VkFormat format)
	{
		VkDescriptorAddressInfoEXT init = vkiDescriptorAddressInfoEXT_null();
		init.address = address;
		init.range = range;
		init.format = format;
		return init;
	}

	static inline VkDescriptorBufferBindingInfoEXT vkiDescriptorBufferBindingInfoEXT_null()
	{
		VkDescriptorBufferBindingInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT;
		return init;
	}

	static inline VkDescriptorBufferBindingInfoEXT vkiDescriptorBufferBindingInfoEXT(VkDeviceAddress address, VkBufferUsageFlags usage)
	{
		VkDescriptorBufferBindingInfoEXT init = vkiDescriptorBufferBindingInfoEXT_null();
		init.address = address;
		init.usage = usage;
		return init;
	}

	static inline VkDescriptorBufferBindingPushDescriptorBufferHandleEXT vkiDescriptorBufferBindingPushDescriptorBufferHandleEXT_null()
	{
		VkDescriptorBufferBindingPushDescriptorBufferHandleEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT;
		return init;
	}

	static inline VkDescriptorBufferBindingPushDescriptorBufferHandleEXT vkiDescriptorBufferBindingPushDescriptorBufferHandleEXT(VkBuffer buffer)
	{
		VkDescriptorBufferBindingPushDescriptorBufferHandleEXT init = vkiDescriptorBufferBindingPushDescriptorBufferHandleEXT_null();
		init.buffer = buffer;
		return init;
	}

	static inline VkDescriptorGetInfoEXT vkiDescriptorGetInfoEXT_null()
	{
		VkDescriptorGetInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT;
		return init;
	}

	static inline VkDescriptorGetInfoEXT vkiDescriptorGetInfoEXT(VkDescriptorType type, VkDescriptorDataEXT data)
	{
		VkDescriptorGetInfoEXT init = vkiDescriptorGetInfoEXT_null();
		init.type = type;
		init.data = data;
		return init;
	}

	static inline VkBufferCaptureDescriptorDataInfoEXT vkiBufferCaptureDescriptorDataInfoEXT_null()
	{
		VkBufferCaptureDescriptorDataInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT;
		return init;
	}

	static inline VkBufferCaptureDescriptorDataInfoEXT vkiBufferCaptureDescriptorDataInfoEXT(VkBuffer buffer)
	{
		VkBufferCaptureDescriptorDataInfoEXT init = vkiBufferCaptureDescriptorDataInfoEXT_null();
		init.buffer = buffer;
		return init;
	}

	static inline VkImageCaptureDescriptorDataInfoEXT vkiImageCaptureDescriptorDataInfoEXT_null()
	{
		VkImageCaptureDescriptorDataInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT;
		return init;
	}

	static inline VkImageCaptureDescriptorDataInfoEXT vkiImageCaptureDescriptorDataInfoEXT(VkImage image)
	{
		VkImageCaptureDescriptorDataInfoEXT init = vkiImageCaptureDescriptorDataInfoEXT_null();
		init.image = image;
		return init;
	}

	static inline VkImageViewCaptureDescriptorDataInfoEXT vkiImageViewCaptureDescriptorDataInfoEXT_null()
	{
		VkImageViewCaptureDescriptorDataInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT;
		return init;
	}

	static inline VkImageViewCaptureDescriptorDataInfoEXT vkiImageViewCaptureDescriptorDataInfoEXT(VkImageView imageView)
	{
		VkImageViewCaptureDescriptorDataInfoEXT init = vkiImageViewCaptureDescriptorDataInfoEXT_null();
		init.imageView = imageView;
		return init;
	}

	static inline VkSamplerCaptureDescriptorDataInfoEXT vkiSamplerCaptureDescriptorDataInfoEXT_null()
	{
		VkSamplerCaptureDescriptorDataInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT;
		return init;
	}

	static inline VkSamplerCaptureDescriptorDataInfoEXT vkiSamplerCaptureDescriptorDataInfoEXT(VkSampler sampler)
	{
		VkSamplerCaptureDescriptorDataInfoEXT init = vkiSamplerCaptureDescriptorDataInfoEXT_null();
		init.sampler = sampler;
		return init;
	}

	static inline VkOpaqueCaptureDescriptorDataCreateInfoEXT vkiOpaqueCaptureDescriptorDataCreateInfoEXT_null()
	{
		VkOpaqueCaptureDescriptorDataCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT;
		return init;
	}

	static inline VkOpaqueCaptureDescriptorDataCreateInfoEXT vkiOpaqueCaptureDescriptorDataCreateInfoEXT(const void *opaqueCaptureDescriptorData)
	{
		VkOpaqueCaptureDescriptorDataCreateInfoEXT init = vkiOpaqueCaptureDescriptorDataCreateInfoEXT_null();
		init.opaqueCaptureDescriptorData = opaqueCaptureDescriptorData;
		return init;
	}

	static inline VkAccelerationStructureCaptureDescriptorDataInfoEXT vkiAccelerationStructureCaptureDescriptorDataInfoEXT_null()
	{
		VkAccelerationStructureCaptureDescriptorDataInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT;
		return init;
	}

	static inline VkAccelerationStructureCaptureDescriptorDataInfoEXT vkiAccelerationStructureCaptureDescriptorDataInfoEXT(VkAccelerationStructureKHR accelerationStructure, VkAccelerationStructureNV accelerationStructureNV)
	{
		VkAccelerationStructureCaptureDescriptorDataInfoEXT init = vkiAccelerationStructureCaptureDescriptorDataInfoEXT_null();
		init.accelerationStructure = accelerationStructure;
		init.accelerationStructureNV = accelerationStructureNV;
		return init;
	}

	static inline VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT vkiPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT_null()
	{
		VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT vkiPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(VkBool32 graphicsPipelineLibrary)
	{
		VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT init = vkiPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT_null();
		init.graphicsPipelineLibrary = graphicsPipelineLibrary;
		return init;
	}

	static inline VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT vkiPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT_null()
	{
		VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT vkiPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT(VkBool32 graphicsPipelineLibraryFastLinking, VkBool32 graphicsPipelineLibraryIndependentInterpolationDecoration)
	{
		VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT init = vkiPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT_null();
		init.graphicsPipelineLibraryFastLinking = graphicsPipelineLibraryFastLinking;
		init.graphicsPipelineLibraryIndependentInterpolationDecoration = graphicsPipelineLibraryIndependentInterpolationDecoration;
		return init;
	}

	static inline VkGraphicsPipelineLibraryCreateInfoEXT vkiGraphicsPipelineLibraryCreateInfoEXT_null()
	{
		VkGraphicsPipelineLibraryCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT;
		return init;
	}

	static inline VkGraphicsPipelineLibraryCreateInfoEXT vkiGraphicsPipelineLibraryCreateInfoEXT()
	{
		VkGraphicsPipelineLibraryCreateInfoEXT init = vkiGraphicsPipelineLibraryCreateInfoEXT_null();
		return init;
	}

	static inline VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD vkiPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD_null()
	{
		VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD;
		return init;
	}

	static inline VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD vkiPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(VkBool32 shaderEarlyAndLateFragmentTests)
	{
		VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD init = vkiPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD_null();
		init.shaderEarlyAndLateFragmentTests = shaderEarlyAndLateFragmentTests;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV vkiPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_null()
	{
		VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV vkiPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(VkBool32 fragmentShadingRateEnums, VkBool32 supersampleFragmentShadingRates, VkBool32 noInvocationFragmentShadingRates)
	{
		VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV init = vkiPhysicalDeviceFragmentShadingRateEnumsFeaturesNV_null();
		init.fragmentShadingRateEnums = fragmentShadingRateEnums;
		init.supersampleFragmentShadingRates = supersampleFragmentShadingRates;
		init.noInvocationFragmentShadingRates = noInvocationFragmentShadingRates;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV vkiPhysicalDeviceFragmentShadingRateEnumsPropertiesNV_null()
	{
		VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV;
		return init;
	}

	static inline VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV vkiPhysicalDeviceFragmentShadingRateEnumsPropertiesNV(VkSampleCountFlagBits maxFragmentShadingRateInvocationCount)
	{
		VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV init = vkiPhysicalDeviceFragmentShadingRateEnumsPropertiesNV_null();
		init.maxFragmentShadingRateInvocationCount = maxFragmentShadingRateInvocationCount;
		return init;
	}

	static inline VkPipelineFragmentShadingRateEnumStateCreateInfoNV vkiPipelineFragmentShadingRateEnumStateCreateInfoNV_null()
	{
		VkPipelineFragmentShadingRateEnumStateCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV;
		return init;
	}

	static inline VkPipelineFragmentShadingRateEnumStateCreateInfoNV vkiPipelineFragmentShadingRateEnumStateCreateInfoNV(VkFragmentShadingRateTypeNV shadingRateType, VkFragmentShadingRateNV shadingRate)
	{
		VkPipelineFragmentShadingRateEnumStateCreateInfoNV init = vkiPipelineFragmentShadingRateEnumStateCreateInfoNV_null();
		init.shadingRateType = shadingRateType;
		init.shadingRate = shadingRate;
		return init;
	}

	static inline VkAccelerationStructureGeometryMotionTrianglesDataNV vkiAccelerationStructureGeometryMotionTrianglesDataNV_null()
	{
		VkAccelerationStructureGeometryMotionTrianglesDataNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV;
		return init;
	}

	static inline VkAccelerationStructureGeometryMotionTrianglesDataNV vkiAccelerationStructureGeometryMotionTrianglesDataNV(VkDeviceOrHostAddressConstKHR vertexData)
	{
		VkAccelerationStructureGeometryMotionTrianglesDataNV init = vkiAccelerationStructureGeometryMotionTrianglesDataNV_null();
		init.vertexData = vertexData;
		return init;
	}

	static inline VkAccelerationStructureMotionInfoNV vkiAccelerationStructureMotionInfoNV_null()
	{
		VkAccelerationStructureMotionInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV;
		return init;
	}

	static inline VkAccelerationStructureMotionInfoNV vkiAccelerationStructureMotionInfoNV(uint32_t maxInstances)
	{
		VkAccelerationStructureMotionInfoNV init = vkiAccelerationStructureMotionInfoNV_null();
		init.maxInstances = maxInstances;
		return init;
	}

	static inline VkAccelerationStructureMatrixMotionInstanceNV vkiAccelerationStructureMatrixMotionInstanceNV_null()
	{
		VkAccelerationStructureMatrixMotionInstanceNV init = {0};
		return init;
	}

	static inline VkAccelerationStructureMatrixMotionInstanceNV vkiAccelerationStructureMatrixMotionInstanceNV(VkTransformMatrixKHR transformT0, VkTransformMatrixKHR transformT1, uint64_t accelerationStructureReference)
	{
		VkAccelerationStructureMatrixMotionInstanceNV init = vkiAccelerationStructureMatrixMotionInstanceNV_null();
		init.transformT0 = transformT0;
		init.transformT1 = transformT1;
		init.accelerationStructureReference = accelerationStructureReference;
		return init;
	}

	static inline VkSRTDataNV vkiSRTDataNV_null()
	{
		VkSRTDataNV init = {0};
		return init;
	}

	static inline VkSRTDataNV vkiSRTDataNV(float sx, float a, float b, float pvx, float sy, float c, float pvy, float sz, float pvz, float qx, float qy, float qz, float qw, float tx, float ty, float tz)
	{
		VkSRTDataNV init = vkiSRTDataNV_null();
		init.sx = sx;
		init.a = a;
		init.b = b;
		init.pvx = pvx;
		init.sy = sy;
		init.c = c;
		init.pvy = pvy;
		init.sz = sz;
		init.pvz = pvz;
		init.qx = qx;
		init.qy = qy;
		init.qz = qz;
		init.qw = qw;
		init.tx = tx;
		init.ty = ty;
		init.tz = tz;
		return init;
	}

	static inline VkAccelerationStructureSRTMotionInstanceNV vkiAccelerationStructureSRTMotionInstanceNV_null()
	{
		VkAccelerationStructureSRTMotionInstanceNV init = {0};
		return init;
	}

	static inline VkAccelerationStructureSRTMotionInstanceNV vkiAccelerationStructureSRTMotionInstanceNV(VkSRTDataNV transformT0, VkSRTDataNV transformT1, uint64_t accelerationStructureReference)
	{
		VkAccelerationStructureSRTMotionInstanceNV init = vkiAccelerationStructureSRTMotionInstanceNV_null();
		init.transformT0 = transformT0;
		init.transformT1 = transformT1;
		init.accelerationStructureReference = accelerationStructureReference;
		return init;
	}

	static inline VkAccelerationStructureMotionInstanceNV vkiAccelerationStructureMotionInstanceNV_null()
	{
		VkAccelerationStructureMotionInstanceNV init = {0};
		return init;
	}

	static inline VkAccelerationStructureMotionInstanceNV vkiAccelerationStructureMotionInstanceNV(VkAccelerationStructureMotionInstanceTypeNV type, VkAccelerationStructureMotionInstanceDataNV data)
	{
		VkAccelerationStructureMotionInstanceNV init = vkiAccelerationStructureMotionInstanceNV_null();
		init.type = type;
		init.data = data;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingMotionBlurFeaturesNV vkiPhysicalDeviceRayTracingMotionBlurFeaturesNV_null()
	{
		VkPhysicalDeviceRayTracingMotionBlurFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingMotionBlurFeaturesNV vkiPhysicalDeviceRayTracingMotionBlurFeaturesNV(VkBool32 rayTracingMotionBlur, VkBool32 rayTracingMotionBlurPipelineTraceRaysIndirect)
	{
		VkPhysicalDeviceRayTracingMotionBlurFeaturesNV init = vkiPhysicalDeviceRayTracingMotionBlurFeaturesNV_null();
		init.rayTracingMotionBlur = rayTracingMotionBlur;
		init.rayTracingMotionBlurPipelineTraceRaysIndirect = rayTracingMotionBlurPipelineTraceRaysIndirect;
		return init;
	}

	static inline VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT vkiPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT_null()
	{
		VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT vkiPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(VkBool32 ycbcr2plane444Formats)
	{
		VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT init = vkiPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT_null();
		init.ycbcr2plane444Formats = ycbcr2plane444Formats;
		return init;
	}

	static inline VkPhysicalDeviceFragmentDensityMap2FeaturesEXT vkiPhysicalDeviceFragmentDensityMap2FeaturesEXT_null()
	{
		VkPhysicalDeviceFragmentDensityMap2FeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceFragmentDensityMap2FeaturesEXT vkiPhysicalDeviceFragmentDensityMap2FeaturesEXT(VkBool32 fragmentDensityMapDeferred)
	{
		VkPhysicalDeviceFragmentDensityMap2FeaturesEXT init = vkiPhysicalDeviceFragmentDensityMap2FeaturesEXT_null();
		init.fragmentDensityMapDeferred = fragmentDensityMapDeferred;
		return init;
	}

	static inline VkPhysicalDeviceFragmentDensityMap2PropertiesEXT vkiPhysicalDeviceFragmentDensityMap2PropertiesEXT_null()
	{
		VkPhysicalDeviceFragmentDensityMap2PropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceFragmentDensityMap2PropertiesEXT vkiPhysicalDeviceFragmentDensityMap2PropertiesEXT(VkBool32 subsampledLoads, VkBool32 subsampledCoarseReconstructionEarlyAccess, uint32_t maxSubsampledArrayLayers, uint32_t maxDescriptorSetSubsampledSamplers)
	{
		VkPhysicalDeviceFragmentDensityMap2PropertiesEXT init = vkiPhysicalDeviceFragmentDensityMap2PropertiesEXT_null();
		init.subsampledLoads = subsampledLoads;
		init.subsampledCoarseReconstructionEarlyAccess = subsampledCoarseReconstructionEarlyAccess;
		init.maxSubsampledArrayLayers = maxSubsampledArrayLayers;
		init.maxDescriptorSetSubsampledSamplers = maxDescriptorSetSubsampledSamplers;
		return init;
	}

	static inline VkCopyCommandTransformInfoQCOM vkiCopyCommandTransformInfoQCOM_null()
	{
		VkCopyCommandTransformInfoQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM;
		return init;
	}

	static inline VkCopyCommandTransformInfoQCOM vkiCopyCommandTransformInfoQCOM(VkSurfaceTransformFlagBitsKHR transform)
	{
		VkCopyCommandTransformInfoQCOM init = vkiCopyCommandTransformInfoQCOM_null();
		init.transform = transform;
		return init;
	}

	static inline VkPhysicalDeviceImageCompressionControlFeaturesEXT vkiPhysicalDeviceImageCompressionControlFeaturesEXT_null()
	{
		VkPhysicalDeviceImageCompressionControlFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceImageCompressionControlFeaturesEXT vkiPhysicalDeviceImageCompressionControlFeaturesEXT(VkBool32 imageCompressionControl)
	{
		VkPhysicalDeviceImageCompressionControlFeaturesEXT init = vkiPhysicalDeviceImageCompressionControlFeaturesEXT_null();
		init.imageCompressionControl = imageCompressionControl;
		return init;
	}

	static inline VkImageCompressionControlEXT vkiImageCompressionControlEXT_null()
	{
		VkImageCompressionControlEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT;
		return init;
	}

	static inline VkImageCompressionControlEXT vkiImageCompressionControlEXT(uint32_t compressionControlPlaneCount, VkImageCompressionFixedRateFlagsEXT *pFixedRateFlags)
	{
		VkImageCompressionControlEXT init = vkiImageCompressionControlEXT_null();
		init.compressionControlPlaneCount = compressionControlPlaneCount;
		init.pFixedRateFlags = pFixedRateFlags;
		return init;
	}

	static inline VkImageCompressionPropertiesEXT vkiImageCompressionPropertiesEXT_null()
	{
		VkImageCompressionPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT;
		return init;
	}

	static inline VkImageCompressionPropertiesEXT vkiImageCompressionPropertiesEXT(VkImageCompressionFlagsEXT imageCompressionFlags, VkImageCompressionFixedRateFlagsEXT imageCompressionFixedRateFlags)
	{
		VkImageCompressionPropertiesEXT init = vkiImageCompressionPropertiesEXT_null();
		init.imageCompressionFlags = imageCompressionFlags;
		init.imageCompressionFixedRateFlags = imageCompressionFixedRateFlags;
		return init;
	}

	static inline VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT vkiPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT_null()
	{
		VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT vkiPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(VkBool32 attachmentFeedbackLoopLayout)
	{
		VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT init = vkiPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT_null();
		init.attachmentFeedbackLoopLayout = attachmentFeedbackLoopLayout;
		return init;
	}

	static inline VkPhysicalDevice4444FormatsFeaturesEXT vkiPhysicalDevice4444FormatsFeaturesEXT_null()
	{
		VkPhysicalDevice4444FormatsFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDevice4444FormatsFeaturesEXT vkiPhysicalDevice4444FormatsFeaturesEXT(VkBool32 formatA4R4G4B4, VkBool32 formatA4B4G4R4)
	{
		VkPhysicalDevice4444FormatsFeaturesEXT init = vkiPhysicalDevice4444FormatsFeaturesEXT_null();
		init.formatA4R4G4B4 = formatA4R4G4B4;
		init.formatA4B4G4R4 = formatA4B4G4R4;
		return init;
	}

	static inline VkPhysicalDeviceFaultFeaturesEXT vkiPhysicalDeviceFaultFeaturesEXT_null()
	{
		VkPhysicalDeviceFaultFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceFaultFeaturesEXT vkiPhysicalDeviceFaultFeaturesEXT(VkBool32 deviceFault, VkBool32 deviceFaultVendorBinary)
	{
		VkPhysicalDeviceFaultFeaturesEXT init = vkiPhysicalDeviceFaultFeaturesEXT_null();
		init.deviceFault = deviceFault;
		init.deviceFaultVendorBinary = deviceFaultVendorBinary;
		return init;
	}

	static inline VkDeviceFaultCountsEXT vkiDeviceFaultCountsEXT_null()
	{
		VkDeviceFaultCountsEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT;
		return init;
	}

	static inline VkDeviceFaultCountsEXT vkiDeviceFaultCountsEXT(uint32_t addressInfoCount, uint32_t vendorInfoCount, VkDeviceSize vendorBinarySize)
	{
		VkDeviceFaultCountsEXT init = vkiDeviceFaultCountsEXT_null();
		init.addressInfoCount = addressInfoCount;
		init.vendorInfoCount = vendorInfoCount;
		init.vendorBinarySize = vendorBinarySize;
		return init;
	}

	static inline VkDeviceFaultAddressInfoEXT vkiDeviceFaultAddressInfoEXT_null()
	{
		VkDeviceFaultAddressInfoEXT init = {0};
		return init;
	}

	static inline VkDeviceFaultAddressInfoEXT vkiDeviceFaultAddressInfoEXT(VkDeviceFaultAddressTypeEXT addressType, VkDeviceAddress reportedAddress, VkDeviceSize addressPrecision)
	{
		VkDeviceFaultAddressInfoEXT init = vkiDeviceFaultAddressInfoEXT_null();
		init.addressType = addressType;
		init.reportedAddress = reportedAddress;
		init.addressPrecision = addressPrecision;
		return init;
	}

	static inline VkDeviceFaultVendorInfoEXT vkiDeviceFaultVendorInfoEXT_null()
	{
		VkDeviceFaultVendorInfoEXT init = {0};
		return init;
	}

	static inline VkDeviceFaultVendorInfoEXT vkiDeviceFaultVendorInfoEXT(uint64_t vendorFaultCode, uint64_t vendorFaultData)
	{
		VkDeviceFaultVendorInfoEXT init = vkiDeviceFaultVendorInfoEXT_null();
		init.vendorFaultCode = vendorFaultCode;
		init.vendorFaultData = vendorFaultData;
		return init;
	}

	static inline VkDeviceFaultInfoEXT vkiDeviceFaultInfoEXT_null()
	{
		VkDeviceFaultInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT;
		return init;
	}

	static inline VkDeviceFaultInfoEXT vkiDeviceFaultInfoEXT(VkDeviceFaultAddressInfoEXT *pAddressInfos, VkDeviceFaultVendorInfoEXT *pVendorInfos, void *pVendorBinaryData)
	{
		VkDeviceFaultInfoEXT init = vkiDeviceFaultInfoEXT_null();
		init.pAddressInfos = pAddressInfos;
		init.pVendorInfos = pVendorInfos;
		init.pVendorBinaryData = pVendorBinaryData;
		return init;
	}

	static inline VkDeviceFaultVendorBinaryHeaderVersionOneEXT vkiDeviceFaultVendorBinaryHeaderVersionOneEXT_null()
	{
		VkDeviceFaultVendorBinaryHeaderVersionOneEXT init = {0};
		return init;
	}

	static inline VkDeviceFaultVendorBinaryHeaderVersionOneEXT vkiDeviceFaultVendorBinaryHeaderVersionOneEXT(uint32_t headerSize, VkDeviceFaultVendorBinaryHeaderVersionEXT headerVersion, uint32_t vendorID, uint32_t deviceID, uint32_t driverVersion, uint32_t applicationNameOffset, uint32_t applicationVersion, uint32_t engineNameOffset, uint32_t engineVersion, uint32_t apiVersion)
	{
		VkDeviceFaultVendorBinaryHeaderVersionOneEXT init = vkiDeviceFaultVendorBinaryHeaderVersionOneEXT_null();
		init.headerSize = headerSize;
		init.headerVersion = headerVersion;
		init.vendorID = vendorID;
		init.deviceID = deviceID;
		init.driverVersion = driverVersion;
		init.applicationNameOffset = applicationNameOffset;
		init.applicationVersion = applicationVersion;
		init.engineNameOffset = engineNameOffset;
		init.engineVersion = engineVersion;
		init.apiVersion = apiVersion;
		return init;
	}

	static inline VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT vkiPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_null()
	{
		VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT vkiPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(VkBool32 rasterizationOrderColorAttachmentAccess, VkBool32 rasterizationOrderDepthAttachmentAccess, VkBool32 rasterizationOrderStencilAttachmentAccess)
	{
		VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT init = vkiPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT_null();
		init.rasterizationOrderColorAttachmentAccess = rasterizationOrderColorAttachmentAccess;
		init.rasterizationOrderDepthAttachmentAccess = rasterizationOrderDepthAttachmentAccess;
		init.rasterizationOrderStencilAttachmentAccess = rasterizationOrderStencilAttachmentAccess;
		return init;
	}

	static inline VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT vkiPhysicalDeviceRGBA10X6FormatsFeaturesEXT_null()
	{
		VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT vkiPhysicalDeviceRGBA10X6FormatsFeaturesEXT(VkBool32 formatRgba10x6WithoutYCbCrSampler)
	{
		VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT init = vkiPhysicalDeviceRGBA10X6FormatsFeaturesEXT_null();
		init.formatRgba10x6WithoutYCbCrSampler = formatRgba10x6WithoutYCbCrSampler;
		return init;
	}

	static inline VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT vkiPhysicalDeviceMutableDescriptorTypeFeaturesEXT_null()
	{
		VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT vkiPhysicalDeviceMutableDescriptorTypeFeaturesEXT(VkBool32 mutableDescriptorType)
	{
		VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT init = vkiPhysicalDeviceMutableDescriptorTypeFeaturesEXT_null();
		init.mutableDescriptorType = mutableDescriptorType;
		return init;
	}

	static inline VkMutableDescriptorTypeListEXT vkiMutableDescriptorTypeListEXT_null()
	{
		VkMutableDescriptorTypeListEXT init = {0};
		return init;
	}

	static inline VkMutableDescriptorTypeListEXT vkiMutableDescriptorTypeListEXT(uint32_t descriptorTypeCount, const VkDescriptorType *pDescriptorTypes)
	{
		VkMutableDescriptorTypeListEXT init = vkiMutableDescriptorTypeListEXT_null();
		init.descriptorTypeCount = descriptorTypeCount;
		init.pDescriptorTypes = pDescriptorTypes;
		return init;
	}

	static inline VkMutableDescriptorTypeCreateInfoEXT vkiMutableDescriptorTypeCreateInfoEXT_null()
	{
		VkMutableDescriptorTypeCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT;
		return init;
	}

	static inline VkMutableDescriptorTypeCreateInfoEXT vkiMutableDescriptorTypeCreateInfoEXT(uint32_t mutableDescriptorTypeListCount, const VkMutableDescriptorTypeListEXT *pMutableDescriptorTypeLists)
	{
		VkMutableDescriptorTypeCreateInfoEXT init = vkiMutableDescriptorTypeCreateInfoEXT_null();
		init.mutableDescriptorTypeListCount = mutableDescriptorTypeListCount;
		init.pMutableDescriptorTypeLists = pMutableDescriptorTypeLists;
		return init;
	}

	static inline VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT vkiPhysicalDeviceVertexInputDynamicStateFeaturesEXT_null()
	{
		VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT vkiPhysicalDeviceVertexInputDynamicStateFeaturesEXT(VkBool32 vertexInputDynamicState)
	{
		VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT init = vkiPhysicalDeviceVertexInputDynamicStateFeaturesEXT_null();
		init.vertexInputDynamicState = vertexInputDynamicState;
		return init;
	}

	static inline VkVertexInputBindingDescription2EXT vkiVertexInputBindingDescription2EXT_null()
	{
		VkVertexInputBindingDescription2EXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT;
		return init;
	}

	static inline VkVertexInputBindingDescription2EXT vkiVertexInputBindingDescription2EXT(uint32_t binding, uint32_t stride, VkVertexInputRate inputRate, uint32_t divisor)
	{
		VkVertexInputBindingDescription2EXT init = vkiVertexInputBindingDescription2EXT_null();
		init.binding = binding;
		init.stride = stride;
		init.inputRate = inputRate;
		init.divisor = divisor;
		return init;
	}

	static inline VkVertexInputAttributeDescription2EXT vkiVertexInputAttributeDescription2EXT_null()
	{
		VkVertexInputAttributeDescription2EXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT;
		return init;
	}

	static inline VkVertexInputAttributeDescription2EXT vkiVertexInputAttributeDescription2EXT(uint32_t location, uint32_t binding, VkFormat format, uint32_t offset)
	{
		VkVertexInputAttributeDescription2EXT init = vkiVertexInputAttributeDescription2EXT_null();
		init.location = location;
		init.binding = binding;
		init.format = format;
		init.offset = offset;
		return init;
	}

	static inline VkPhysicalDeviceDrmPropertiesEXT vkiPhysicalDeviceDrmPropertiesEXT_null()
	{
		VkPhysicalDeviceDrmPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceDrmPropertiesEXT vkiPhysicalDeviceDrmPropertiesEXT(VkBool32 hasPrimary, VkBool32 hasRender, int64_t primaryMajor, int64_t primaryMinor, int64_t renderMajor, int64_t renderMinor)
	{
		VkPhysicalDeviceDrmPropertiesEXT init = vkiPhysicalDeviceDrmPropertiesEXT_null();
		init.hasPrimary = hasPrimary;
		init.hasRender = hasRender;
		init.primaryMajor = primaryMajor;
		init.primaryMinor = primaryMinor;
		init.renderMajor = renderMajor;
		init.renderMinor = renderMinor;
		return init;
	}

	static inline VkPhysicalDeviceAddressBindingReportFeaturesEXT vkiPhysicalDeviceAddressBindingReportFeaturesEXT_null()
	{
		VkPhysicalDeviceAddressBindingReportFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceAddressBindingReportFeaturesEXT vkiPhysicalDeviceAddressBindingReportFeaturesEXT(VkBool32 reportAddressBinding)
	{
		VkPhysicalDeviceAddressBindingReportFeaturesEXT init = vkiPhysicalDeviceAddressBindingReportFeaturesEXT_null();
		init.reportAddressBinding = reportAddressBinding;
		return init;
	}

	static inline VkDeviceAddressBindingCallbackDataEXT vkiDeviceAddressBindingCallbackDataEXT_null()
	{
		VkDeviceAddressBindingCallbackDataEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT;
		return init;
	}

	static inline VkDeviceAddressBindingCallbackDataEXT vkiDeviceAddressBindingCallbackDataEXT(VkDeviceAddress baseAddress, VkDeviceSize size, VkDeviceAddressBindingTypeEXT bindingType)
	{
		VkDeviceAddressBindingCallbackDataEXT init = vkiDeviceAddressBindingCallbackDataEXT_null();
		init.baseAddress = baseAddress;
		init.size = size;
		init.bindingType = bindingType;
		return init;
	}

	static inline VkPhysicalDeviceDepthClipControlFeaturesEXT vkiPhysicalDeviceDepthClipControlFeaturesEXT_null()
	{
		VkPhysicalDeviceDepthClipControlFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceDepthClipControlFeaturesEXT vkiPhysicalDeviceDepthClipControlFeaturesEXT(VkBool32 depthClipControl)
	{
		VkPhysicalDeviceDepthClipControlFeaturesEXT init = vkiPhysicalDeviceDepthClipControlFeaturesEXT_null();
		init.depthClipControl = depthClipControl;
		return init;
	}

	static inline VkPipelineViewportDepthClipControlCreateInfoEXT vkiPipelineViewportDepthClipControlCreateInfoEXT_null()
	{
		VkPipelineViewportDepthClipControlCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT;
		return init;
	}

	static inline VkPipelineViewportDepthClipControlCreateInfoEXT vkiPipelineViewportDepthClipControlCreateInfoEXT(VkBool32 negativeOneToOne)
	{
		VkPipelineViewportDepthClipControlCreateInfoEXT init = vkiPipelineViewportDepthClipControlCreateInfoEXT_null();
		init.negativeOneToOne = negativeOneToOne;
		return init;
	}

	static inline VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT vkiPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT_null()
	{
		VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT vkiPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(VkBool32 primitiveTopologyListRestart, VkBool32 primitiveTopologyPatchListRestart)
	{
		VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT init = vkiPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT_null();
		init.primitiveTopologyListRestart = primitiveTopologyListRestart;
		init.primitiveTopologyPatchListRestart = primitiveTopologyPatchListRestart;
		return init;
	}

	static inline VkSubpassShadingPipelineCreateInfoHUAWEI vkiSubpassShadingPipelineCreateInfoHUAWEI_null()
	{
		VkSubpassShadingPipelineCreateInfoHUAWEI init = {0};
		init.sType = VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI;
		return init;
	}

	static inline VkSubpassShadingPipelineCreateInfoHUAWEI vkiSubpassShadingPipelineCreateInfoHUAWEI(VkRenderPass renderPass, uint32_t subpass)
	{
		VkSubpassShadingPipelineCreateInfoHUAWEI init = vkiSubpassShadingPipelineCreateInfoHUAWEI_null();
		init.renderPass = renderPass;
		init.subpass = subpass;
		return init;
	}

	static inline VkPhysicalDeviceSubpassShadingFeaturesHUAWEI vkiPhysicalDeviceSubpassShadingFeaturesHUAWEI_null()
	{
		VkPhysicalDeviceSubpassShadingFeaturesHUAWEI init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI;
		return init;
	}

	static inline VkPhysicalDeviceSubpassShadingFeaturesHUAWEI vkiPhysicalDeviceSubpassShadingFeaturesHUAWEI(VkBool32 subpassShading)
	{
		VkPhysicalDeviceSubpassShadingFeaturesHUAWEI init = vkiPhysicalDeviceSubpassShadingFeaturesHUAWEI_null();
		init.subpassShading = subpassShading;
		return init;
	}

	static inline VkPhysicalDeviceSubpassShadingPropertiesHUAWEI vkiPhysicalDeviceSubpassShadingPropertiesHUAWEI_null()
	{
		VkPhysicalDeviceSubpassShadingPropertiesHUAWEI init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI;
		return init;
	}

	static inline VkPhysicalDeviceSubpassShadingPropertiesHUAWEI vkiPhysicalDeviceSubpassShadingPropertiesHUAWEI(uint32_t maxSubpassShadingWorkgroupSizeAspectRatio)
	{
		VkPhysicalDeviceSubpassShadingPropertiesHUAWEI init = vkiPhysicalDeviceSubpassShadingPropertiesHUAWEI_null();
		init.maxSubpassShadingWorkgroupSizeAspectRatio = maxSubpassShadingWorkgroupSizeAspectRatio;
		return init;
	}

	static inline VkPhysicalDeviceInvocationMaskFeaturesHUAWEI vkiPhysicalDeviceInvocationMaskFeaturesHUAWEI_null()
	{
		VkPhysicalDeviceInvocationMaskFeaturesHUAWEI init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI;
		return init;
	}

	static inline VkPhysicalDeviceInvocationMaskFeaturesHUAWEI vkiPhysicalDeviceInvocationMaskFeaturesHUAWEI(VkBool32 invocationMask)
	{
		VkPhysicalDeviceInvocationMaskFeaturesHUAWEI init = vkiPhysicalDeviceInvocationMaskFeaturesHUAWEI_null();
		init.invocationMask = invocationMask;
		return init;
	}

	static inline VkMemoryGetRemoteAddressInfoNV vkiMemoryGetRemoteAddressInfoNV_null()
	{
		VkMemoryGetRemoteAddressInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV;
		return init;
	}

	static inline VkMemoryGetRemoteAddressInfoNV vkiMemoryGetRemoteAddressInfoNV(VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagBits handleType)
	{
		VkMemoryGetRemoteAddressInfoNV init = vkiMemoryGetRemoteAddressInfoNV_null();
		init.memory = memory;
		init.handleType = handleType;
		return init;
	}

	static inline VkPhysicalDeviceExternalMemoryRDMAFeaturesNV vkiPhysicalDeviceExternalMemoryRDMAFeaturesNV_null()
	{
		VkPhysicalDeviceExternalMemoryRDMAFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceExternalMemoryRDMAFeaturesNV vkiPhysicalDeviceExternalMemoryRDMAFeaturesNV(VkBool32 externalMemoryRDMA)
	{
		VkPhysicalDeviceExternalMemoryRDMAFeaturesNV init = vkiPhysicalDeviceExternalMemoryRDMAFeaturesNV_null();
		init.externalMemoryRDMA = externalMemoryRDMA;
		return init;
	}

	static inline VkPipelinePropertiesIdentifierEXT vkiPipelinePropertiesIdentifierEXT_null()
	{
		VkPipelinePropertiesIdentifierEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT;
		return init;
	}

	static inline VkPipelinePropertiesIdentifierEXT vkiPipelinePropertiesIdentifierEXT()
	{
		VkPipelinePropertiesIdentifierEXT init = vkiPipelinePropertiesIdentifierEXT_null();
		return init;
	}

	static inline VkPhysicalDevicePipelinePropertiesFeaturesEXT vkiPhysicalDevicePipelinePropertiesFeaturesEXT_null()
	{
		VkPhysicalDevicePipelinePropertiesFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDevicePipelinePropertiesFeaturesEXT vkiPhysicalDevicePipelinePropertiesFeaturesEXT(VkBool32 pipelinePropertiesIdentifier)
	{
		VkPhysicalDevicePipelinePropertiesFeaturesEXT init = vkiPhysicalDevicePipelinePropertiesFeaturesEXT_null();
		init.pipelinePropertiesIdentifier = pipelinePropertiesIdentifier;
		return init;
	}

	static inline VkPhysicalDeviceFrameBoundaryFeaturesEXT vkiPhysicalDeviceFrameBoundaryFeaturesEXT_null()
	{
		VkPhysicalDeviceFrameBoundaryFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceFrameBoundaryFeaturesEXT vkiPhysicalDeviceFrameBoundaryFeaturesEXT(VkBool32 frameBoundary)
	{
		VkPhysicalDeviceFrameBoundaryFeaturesEXT init = vkiPhysicalDeviceFrameBoundaryFeaturesEXT_null();
		init.frameBoundary = frameBoundary;
		return init;
	}

	static inline VkFrameBoundaryEXT vkiFrameBoundaryEXT_null()
	{
		VkFrameBoundaryEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT;
		return init;
	}

	static inline VkFrameBoundaryEXT vkiFrameBoundaryEXT(uint64_t frameID, uint32_t imageCount, const VkImage *pImages, uint32_t bufferCount, const VkBuffer *pBuffers, uint64_t tagName, size_t tagSize, const void *pTag)
	{
		VkFrameBoundaryEXT init = vkiFrameBoundaryEXT_null();
		init.frameID = frameID;
		init.imageCount = imageCount;
		init.pImages = pImages;
		init.bufferCount = bufferCount;
		init.pBuffers = pBuffers;
		init.tagName = tagName;
		init.tagSize = tagSize;
		init.pTag = pTag;
		return init;
	}

	static inline VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT vkiPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT_null()
	{
		VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT vkiPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(VkBool32 multisampledRenderToSingleSampled)
	{
		VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT init = vkiPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT_null();
		init.multisampledRenderToSingleSampled = multisampledRenderToSingleSampled;
		return init;
	}

	static inline VkSubpassResolvePerformanceQueryEXT vkiSubpassResolvePerformanceQueryEXT_null()
	{
		VkSubpassResolvePerformanceQueryEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT;
		return init;
	}

	static inline VkSubpassResolvePerformanceQueryEXT vkiSubpassResolvePerformanceQueryEXT(VkBool32 optimal)
	{
		VkSubpassResolvePerformanceQueryEXT init = vkiSubpassResolvePerformanceQueryEXT_null();
		init.optimal = optimal;
		return init;
	}

	static inline VkMultisampledRenderToSingleSampledInfoEXT vkiMultisampledRenderToSingleSampledInfoEXT_null()
	{
		VkMultisampledRenderToSingleSampledInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT;
		return init;
	}

	static inline VkMultisampledRenderToSingleSampledInfoEXT vkiMultisampledRenderToSingleSampledInfoEXT(VkBool32 multisampledRenderToSingleSampledEnable, VkSampleCountFlagBits rasterizationSamples)
	{
		VkMultisampledRenderToSingleSampledInfoEXT init = vkiMultisampledRenderToSingleSampledInfoEXT_null();
		init.multisampledRenderToSingleSampledEnable = multisampledRenderToSingleSampledEnable;
		init.rasterizationSamples = rasterizationSamples;
		return init;
	}

	static inline VkPhysicalDeviceExtendedDynamicState2FeaturesEXT vkiPhysicalDeviceExtendedDynamicState2FeaturesEXT_null()
	{
		VkPhysicalDeviceExtendedDynamicState2FeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceExtendedDynamicState2FeaturesEXT vkiPhysicalDeviceExtendedDynamicState2FeaturesEXT(VkBool32 extendedDynamicState2, VkBool32 extendedDynamicState2LogicOp, VkBool32 extendedDynamicState2PatchControlPoints)
	{
		VkPhysicalDeviceExtendedDynamicState2FeaturesEXT init = vkiPhysicalDeviceExtendedDynamicState2FeaturesEXT_null();
		init.extendedDynamicState2 = extendedDynamicState2;
		init.extendedDynamicState2LogicOp = extendedDynamicState2LogicOp;
		init.extendedDynamicState2PatchControlPoints = extendedDynamicState2PatchControlPoints;
		return init;
	}

	static inline VkPhysicalDeviceColorWriteEnableFeaturesEXT vkiPhysicalDeviceColorWriteEnableFeaturesEXT_null()
	{
		VkPhysicalDeviceColorWriteEnableFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceColorWriteEnableFeaturesEXT vkiPhysicalDeviceColorWriteEnableFeaturesEXT(VkBool32 colorWriteEnable)
	{
		VkPhysicalDeviceColorWriteEnableFeaturesEXT init = vkiPhysicalDeviceColorWriteEnableFeaturesEXT_null();
		init.colorWriteEnable = colorWriteEnable;
		return init;
	}

	static inline VkPipelineColorWriteCreateInfoEXT vkiPipelineColorWriteCreateInfoEXT_null()
	{
		VkPipelineColorWriteCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT;
		return init;
	}

	static inline VkPipelineColorWriteCreateInfoEXT vkiPipelineColorWriteCreateInfoEXT(uint32_t attachmentCount, const VkBool32 *pColorWriteEnables)
	{
		VkPipelineColorWriteCreateInfoEXT init = vkiPipelineColorWriteCreateInfoEXT_null();
		init.attachmentCount = attachmentCount;
		init.pColorWriteEnables = pColorWriteEnables;
		return init;
	}

	static inline VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT vkiPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_null()
	{
		VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT vkiPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(VkBool32 primitivesGeneratedQuery, VkBool32 primitivesGeneratedQueryWithRasterizerDiscard, VkBool32 primitivesGeneratedQueryWithNonZeroStreams)
	{
		VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT init = vkiPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT_null();
		init.primitivesGeneratedQuery = primitivesGeneratedQuery;
		init.primitivesGeneratedQueryWithRasterizerDiscard = primitivesGeneratedQueryWithRasterizerDiscard;
		init.primitivesGeneratedQueryWithNonZeroStreams = primitivesGeneratedQueryWithNonZeroStreams;
		return init;
	}

	static inline VkPhysicalDeviceImageViewMinLodFeaturesEXT vkiPhysicalDeviceImageViewMinLodFeaturesEXT_null()
	{
		VkPhysicalDeviceImageViewMinLodFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceImageViewMinLodFeaturesEXT vkiPhysicalDeviceImageViewMinLodFeaturesEXT(VkBool32 minLod)
	{
		VkPhysicalDeviceImageViewMinLodFeaturesEXT init = vkiPhysicalDeviceImageViewMinLodFeaturesEXT_null();
		init.minLod = minLod;
		return init;
	}

	static inline VkImageViewMinLodCreateInfoEXT vkiImageViewMinLodCreateInfoEXT_null()
	{
		VkImageViewMinLodCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT;
		return init;
	}

	static inline VkImageViewMinLodCreateInfoEXT vkiImageViewMinLodCreateInfoEXT(float minLod)
	{
		VkImageViewMinLodCreateInfoEXT init = vkiImageViewMinLodCreateInfoEXT_null();
		init.minLod = minLod;
		return init;
	}

	static inline VkPhysicalDeviceMultiDrawFeaturesEXT vkiPhysicalDeviceMultiDrawFeaturesEXT_null()
	{
		VkPhysicalDeviceMultiDrawFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceMultiDrawFeaturesEXT vkiPhysicalDeviceMultiDrawFeaturesEXT(VkBool32 multiDraw)
	{
		VkPhysicalDeviceMultiDrawFeaturesEXT init = vkiPhysicalDeviceMultiDrawFeaturesEXT_null();
		init.multiDraw = multiDraw;
		return init;
	}

	static inline VkPhysicalDeviceMultiDrawPropertiesEXT vkiPhysicalDeviceMultiDrawPropertiesEXT_null()
	{
		VkPhysicalDeviceMultiDrawPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceMultiDrawPropertiesEXT vkiPhysicalDeviceMultiDrawPropertiesEXT(uint32_t maxMultiDrawCount)
	{
		VkPhysicalDeviceMultiDrawPropertiesEXT init = vkiPhysicalDeviceMultiDrawPropertiesEXT_null();
		init.maxMultiDrawCount = maxMultiDrawCount;
		return init;
	}

	static inline VkMultiDrawInfoEXT vkiMultiDrawInfoEXT_null()
	{
		VkMultiDrawInfoEXT init = {0};
		return init;
	}

	static inline VkMultiDrawInfoEXT vkiMultiDrawInfoEXT(uint32_t firstVertex, uint32_t vertexCount)
	{
		VkMultiDrawInfoEXT init = vkiMultiDrawInfoEXT_null();
		init.firstVertex = firstVertex;
		init.vertexCount = vertexCount;
		return init;
	}

	static inline VkMultiDrawIndexedInfoEXT vkiMultiDrawIndexedInfoEXT_null()
	{
		VkMultiDrawIndexedInfoEXT init = {0};
		return init;
	}

	static inline VkMultiDrawIndexedInfoEXT vkiMultiDrawIndexedInfoEXT(uint32_t firstIndex, uint32_t indexCount, int32_t vertexOffset)
	{
		VkMultiDrawIndexedInfoEXT init = vkiMultiDrawIndexedInfoEXT_null();
		init.firstIndex = firstIndex;
		init.indexCount = indexCount;
		init.vertexOffset = vertexOffset;
		return init;
	}

	static inline VkPhysicalDeviceImage2DViewOf3DFeaturesEXT vkiPhysicalDeviceImage2DViewOf3DFeaturesEXT_null()
	{
		VkPhysicalDeviceImage2DViewOf3DFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceImage2DViewOf3DFeaturesEXT vkiPhysicalDeviceImage2DViewOf3DFeaturesEXT(VkBool32 image2DViewOf3D, VkBool32 sampler2DViewOf3D)
	{
		VkPhysicalDeviceImage2DViewOf3DFeaturesEXT init = vkiPhysicalDeviceImage2DViewOf3DFeaturesEXT_null();
		init.image2DViewOf3D = image2DViewOf3D;
		init.sampler2DViewOf3D = sampler2DViewOf3D;
		return init;
	}

	static inline VkPhysicalDeviceShaderTileImageFeaturesEXT vkiPhysicalDeviceShaderTileImageFeaturesEXT_null()
	{
		VkPhysicalDeviceShaderTileImageFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceShaderTileImageFeaturesEXT vkiPhysicalDeviceShaderTileImageFeaturesEXT(VkBool32 shaderTileImageColorReadAccess, VkBool32 shaderTileImageDepthReadAccess, VkBool32 shaderTileImageStencilReadAccess)
	{
		VkPhysicalDeviceShaderTileImageFeaturesEXT init = vkiPhysicalDeviceShaderTileImageFeaturesEXT_null();
		init.shaderTileImageColorReadAccess = shaderTileImageColorReadAccess;
		init.shaderTileImageDepthReadAccess = shaderTileImageDepthReadAccess;
		init.shaderTileImageStencilReadAccess = shaderTileImageStencilReadAccess;
		return init;
	}

	static inline VkPhysicalDeviceShaderTileImagePropertiesEXT vkiPhysicalDeviceShaderTileImagePropertiesEXT_null()
	{
		VkPhysicalDeviceShaderTileImagePropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceShaderTileImagePropertiesEXT vkiPhysicalDeviceShaderTileImagePropertiesEXT(VkBool32 shaderTileImageCoherentReadAccelerated, VkBool32 shaderTileImageReadSampleFromPixelRateInvocation, VkBool32 shaderTileImageReadFromHelperInvocation)
	{
		VkPhysicalDeviceShaderTileImagePropertiesEXT init = vkiPhysicalDeviceShaderTileImagePropertiesEXT_null();
		init.shaderTileImageCoherentReadAccelerated = shaderTileImageCoherentReadAccelerated;
		init.shaderTileImageReadSampleFromPixelRateInvocation = shaderTileImageReadSampleFromPixelRateInvocation;
		init.shaderTileImageReadFromHelperInvocation = shaderTileImageReadFromHelperInvocation;
		return init;
	}

	static inline VkMicromapUsageEXT vkiMicromapUsageEXT_null()
	{
		VkMicromapUsageEXT init = {0};
		return init;
	}

	static inline VkMicromapUsageEXT vkiMicromapUsageEXT(uint32_t count, uint32_t subdivisionLevel, uint32_t format)
	{
		VkMicromapUsageEXT init = vkiMicromapUsageEXT_null();
		init.count = count;
		init.subdivisionLevel = subdivisionLevel;
		init.format = format;
		return init;
	}

	static inline VkMicromapBuildInfoEXT vkiMicromapBuildInfoEXT_null()
	{
		VkMicromapBuildInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT;
		return init;
	}

	static inline VkMicromapBuildInfoEXT vkiMicromapBuildInfoEXT(VkMicromapTypeEXT type, VkBuildMicromapModeEXT mode, VkMicromapEXT dstMicromap, uint32_t usageCountsCount, const VkMicromapUsageEXT *pUsageCounts, const VkMicromapUsageEXT *const *ppUsageCounts, VkDeviceOrHostAddressConstKHR data, VkDeviceOrHostAddressKHR scratchData, VkDeviceOrHostAddressConstKHR triangleArray, VkDeviceSize triangleArrayStride)
	{
		VkMicromapBuildInfoEXT init = vkiMicromapBuildInfoEXT_null();
		init.type = type;
		init.mode = mode;
		init.dstMicromap = dstMicromap;
		init.usageCountsCount = usageCountsCount;
		init.pUsageCounts = pUsageCounts;
		init.ppUsageCounts = ppUsageCounts;
		init.data = data;
		init.scratchData = scratchData;
		init.triangleArray = triangleArray;
		init.triangleArrayStride = triangleArrayStride;
		return init;
	}

	static inline VkMicromapCreateInfoEXT vkiMicromapCreateInfoEXT_null()
	{
		VkMicromapCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT;
		return init;
	}

	static inline VkMicromapCreateInfoEXT vkiMicromapCreateInfoEXT(VkMicromapCreateFlagsEXT createFlags, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkMicromapTypeEXT type, VkDeviceAddress deviceAddress)
	{
		VkMicromapCreateInfoEXT init = vkiMicromapCreateInfoEXT_null();
		init.createFlags = createFlags;
		init.buffer = buffer;
		init.offset = offset;
		init.size = size;
		init.type = type;
		init.deviceAddress = deviceAddress;
		return init;
	}

	static inline VkPhysicalDeviceOpacityMicromapFeaturesEXT vkiPhysicalDeviceOpacityMicromapFeaturesEXT_null()
	{
		VkPhysicalDeviceOpacityMicromapFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceOpacityMicromapFeaturesEXT vkiPhysicalDeviceOpacityMicromapFeaturesEXT(VkBool32 micromap, VkBool32 micromapCaptureReplay, VkBool32 micromapHostCommands)
	{
		VkPhysicalDeviceOpacityMicromapFeaturesEXT init = vkiPhysicalDeviceOpacityMicromapFeaturesEXT_null();
		init.micromap = micromap;
		init.micromapCaptureReplay = micromapCaptureReplay;
		init.micromapHostCommands = micromapHostCommands;
		return init;
	}

	static inline VkPhysicalDeviceOpacityMicromapPropertiesEXT vkiPhysicalDeviceOpacityMicromapPropertiesEXT_null()
	{
		VkPhysicalDeviceOpacityMicromapPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceOpacityMicromapPropertiesEXT vkiPhysicalDeviceOpacityMicromapPropertiesEXT(uint32_t maxOpacity2StateSubdivisionLevel, uint32_t maxOpacity4StateSubdivisionLevel)
	{
		VkPhysicalDeviceOpacityMicromapPropertiesEXT init = vkiPhysicalDeviceOpacityMicromapPropertiesEXT_null();
		init.maxOpacity2StateSubdivisionLevel = maxOpacity2StateSubdivisionLevel;
		init.maxOpacity4StateSubdivisionLevel = maxOpacity4StateSubdivisionLevel;
		return init;
	}

	static inline VkMicromapVersionInfoEXT vkiMicromapVersionInfoEXT_null()
	{
		VkMicromapVersionInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT;
		return init;
	}

	static inline VkMicromapVersionInfoEXT vkiMicromapVersionInfoEXT(const uint8_t *pVersionData)
	{
		VkMicromapVersionInfoEXT init = vkiMicromapVersionInfoEXT_null();
		init.pVersionData = pVersionData;
		return init;
	}

	static inline VkCopyMicromapToMemoryInfoEXT vkiCopyMicromapToMemoryInfoEXT_null()
	{
		VkCopyMicromapToMemoryInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT;
		return init;
	}

	static inline VkCopyMicromapToMemoryInfoEXT vkiCopyMicromapToMemoryInfoEXT(VkMicromapEXT src, VkDeviceOrHostAddressKHR dst, VkCopyMicromapModeEXT mode)
	{
		VkCopyMicromapToMemoryInfoEXT init = vkiCopyMicromapToMemoryInfoEXT_null();
		init.src = src;
		init.dst = dst;
		init.mode = mode;
		return init;
	}

	static inline VkCopyMemoryToMicromapInfoEXT vkiCopyMemoryToMicromapInfoEXT_null()
	{
		VkCopyMemoryToMicromapInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT;
		return init;
	}

	static inline VkCopyMemoryToMicromapInfoEXT vkiCopyMemoryToMicromapInfoEXT(VkDeviceOrHostAddressConstKHR src, VkMicromapEXT dst, VkCopyMicromapModeEXT mode)
	{
		VkCopyMemoryToMicromapInfoEXT init = vkiCopyMemoryToMicromapInfoEXT_null();
		init.src = src;
		init.dst = dst;
		init.mode = mode;
		return init;
	}

	static inline VkCopyMicromapInfoEXT vkiCopyMicromapInfoEXT_null()
	{
		VkCopyMicromapInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT;
		return init;
	}

	static inline VkCopyMicromapInfoEXT vkiCopyMicromapInfoEXT(VkMicromapEXT src, VkMicromapEXT dst, VkCopyMicromapModeEXT mode)
	{
		VkCopyMicromapInfoEXT init = vkiCopyMicromapInfoEXT_null();
		init.src = src;
		init.dst = dst;
		init.mode = mode;
		return init;
	}

	static inline VkMicromapBuildSizesInfoEXT vkiMicromapBuildSizesInfoEXT_null()
	{
		VkMicromapBuildSizesInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT;
		return init;
	}

	static inline VkMicromapBuildSizesInfoEXT vkiMicromapBuildSizesInfoEXT(VkDeviceSize micromapSize, VkDeviceSize buildScratchSize, VkBool32 discardable)
	{
		VkMicromapBuildSizesInfoEXT init = vkiMicromapBuildSizesInfoEXT_null();
		init.micromapSize = micromapSize;
		init.buildScratchSize = buildScratchSize;
		init.discardable = discardable;
		return init;
	}

	static inline VkAccelerationStructureTrianglesOpacityMicromapEXT vkiAccelerationStructureTrianglesOpacityMicromapEXT_null()
	{
		VkAccelerationStructureTrianglesOpacityMicromapEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT;
		return init;
	}

	static inline VkAccelerationStructureTrianglesOpacityMicromapEXT vkiAccelerationStructureTrianglesOpacityMicromapEXT(VkIndexType indexType, VkDeviceOrHostAddressConstKHR indexBuffer, VkDeviceSize indexStride, uint32_t baseTriangle, uint32_t usageCountsCount, const VkMicromapUsageEXT *pUsageCounts, const VkMicromapUsageEXT *const *ppUsageCounts, VkMicromapEXT micromap)
	{
		VkAccelerationStructureTrianglesOpacityMicromapEXT init = vkiAccelerationStructureTrianglesOpacityMicromapEXT_null();
		init.indexType = indexType;
		init.indexBuffer = indexBuffer;
		init.indexStride = indexStride;
		init.baseTriangle = baseTriangle;
		init.usageCountsCount = usageCountsCount;
		init.pUsageCounts = pUsageCounts;
		init.ppUsageCounts = ppUsageCounts;
		init.micromap = micromap;
		return init;
	}

	static inline VkMicromapTriangleEXT vkiMicromapTriangleEXT_null()
	{
		VkMicromapTriangleEXT init = {0};
		return init;
	}

	static inline VkMicromapTriangleEXT vkiMicromapTriangleEXT(uint32_t dataOffset, uint16_t subdivisionLevel, uint16_t format)
	{
		VkMicromapTriangleEXT init = vkiMicromapTriangleEXT_null();
		init.dataOffset = dataOffset;
		init.subdivisionLevel = subdivisionLevel;
		init.format = format;
		return init;
	}

	static inline VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI vkiPhysicalDeviceClusterCullingShaderFeaturesHUAWEI_null()
	{
		VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI;
		return init;
	}

	static inline VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI vkiPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(VkBool32 clustercullingShader, VkBool32 multiviewClusterCullingShader)
	{
		VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI init = vkiPhysicalDeviceClusterCullingShaderFeaturesHUAWEI_null();
		init.clustercullingShader = clustercullingShader;
		init.multiviewClusterCullingShader = multiviewClusterCullingShader;
		return init;
	}

	static inline VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI vkiPhysicalDeviceClusterCullingShaderPropertiesHUAWEI_null()
	{
		VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI;
		return init;
	}

	static inline VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI vkiPhysicalDeviceClusterCullingShaderPropertiesHUAWEI(uint32_t maxOutputClusterCount, VkDeviceSize indirectBufferOffsetAlignment)
	{
		VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI init = vkiPhysicalDeviceClusterCullingShaderPropertiesHUAWEI_null();
		init.maxOutputClusterCount = maxOutputClusterCount;
		init.indirectBufferOffsetAlignment = indirectBufferOffsetAlignment;
		return init;
	}

	static inline VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI vkiPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI_null()
	{
		VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI;
		return init;
	}

	static inline VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI vkiPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI(VkBool32 clusterShadingRate)
	{
		VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI init = vkiPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI_null();
		init.clusterShadingRate = clusterShadingRate;
		return init;
	}

	static inline VkPhysicalDeviceBorderColorSwizzleFeaturesEXT vkiPhysicalDeviceBorderColorSwizzleFeaturesEXT_null()
	{
		VkPhysicalDeviceBorderColorSwizzleFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceBorderColorSwizzleFeaturesEXT vkiPhysicalDeviceBorderColorSwizzleFeaturesEXT(VkBool32 borderColorSwizzle, VkBool32 borderColorSwizzleFromImage)
	{
		VkPhysicalDeviceBorderColorSwizzleFeaturesEXT init = vkiPhysicalDeviceBorderColorSwizzleFeaturesEXT_null();
		init.borderColorSwizzle = borderColorSwizzle;
		init.borderColorSwizzleFromImage = borderColorSwizzleFromImage;
		return init;
	}

	static inline VkSamplerBorderColorComponentMappingCreateInfoEXT vkiSamplerBorderColorComponentMappingCreateInfoEXT_null()
	{
		VkSamplerBorderColorComponentMappingCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT;
		return init;
	}

	static inline VkSamplerBorderColorComponentMappingCreateInfoEXT vkiSamplerBorderColorComponentMappingCreateInfoEXT(VkComponentMapping components, VkBool32 srgb)
	{
		VkSamplerBorderColorComponentMappingCreateInfoEXT init = vkiSamplerBorderColorComponentMappingCreateInfoEXT_null();
		init.components = components;
		init.srgb = srgb;
		return init;
	}

	static inline VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT vkiPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT_null()
	{
		VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT vkiPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(VkBool32 pageableDeviceLocalMemory)
	{
		VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT init = vkiPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT_null();
		init.pageableDeviceLocalMemory = pageableDeviceLocalMemory;
		return init;
	}

	static inline VkPhysicalDeviceShaderCorePropertiesARM vkiPhysicalDeviceShaderCorePropertiesARM_null()
	{
		VkPhysicalDeviceShaderCorePropertiesARM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM;
		return init;
	}

	static inline VkPhysicalDeviceShaderCorePropertiesARM vkiPhysicalDeviceShaderCorePropertiesARM(uint32_t pixelRate, uint32_t texelRate, uint32_t fmaRate)
	{
		VkPhysicalDeviceShaderCorePropertiesARM init = vkiPhysicalDeviceShaderCorePropertiesARM_null();
		init.pixelRate = pixelRate;
		init.texelRate = texelRate;
		init.fmaRate = fmaRate;
		return init;
	}

	static inline VkDeviceQueueShaderCoreControlCreateInfoARM vkiDeviceQueueShaderCoreControlCreateInfoARM_null()
	{
		VkDeviceQueueShaderCoreControlCreateInfoARM init = {0};
		init.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM;
		return init;
	}

	static inline VkDeviceQueueShaderCoreControlCreateInfoARM vkiDeviceQueueShaderCoreControlCreateInfoARM(uint32_t shaderCoreCount)
	{
		VkDeviceQueueShaderCoreControlCreateInfoARM init = vkiDeviceQueueShaderCoreControlCreateInfoARM_null();
		init.shaderCoreCount = shaderCoreCount;
		return init;
	}

	static inline VkPhysicalDeviceSchedulingControlsFeaturesARM vkiPhysicalDeviceSchedulingControlsFeaturesARM_null()
	{
		VkPhysicalDeviceSchedulingControlsFeaturesARM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM;
		return init;
	}

	static inline VkPhysicalDeviceSchedulingControlsFeaturesARM vkiPhysicalDeviceSchedulingControlsFeaturesARM(VkBool32 schedulingControls)
	{
		VkPhysicalDeviceSchedulingControlsFeaturesARM init = vkiPhysicalDeviceSchedulingControlsFeaturesARM_null();
		init.schedulingControls = schedulingControls;
		return init;
	}

	static inline VkPhysicalDeviceSchedulingControlsPropertiesARM vkiPhysicalDeviceSchedulingControlsPropertiesARM_null()
	{
		VkPhysicalDeviceSchedulingControlsPropertiesARM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM;
		return init;
	}

	static inline VkPhysicalDeviceSchedulingControlsPropertiesARM vkiPhysicalDeviceSchedulingControlsPropertiesARM(VkPhysicalDeviceSchedulingControlsFlagsARM schedulingControlsFlags)
	{
		VkPhysicalDeviceSchedulingControlsPropertiesARM init = vkiPhysicalDeviceSchedulingControlsPropertiesARM_null();
		init.schedulingControlsFlags = schedulingControlsFlags;
		return init;
	}

	static inline VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT vkiPhysicalDeviceImageSlicedViewOf3DFeaturesEXT_null()
	{
		VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT vkiPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(VkBool32 imageSlicedViewOf3D)
	{
		VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT init = vkiPhysicalDeviceImageSlicedViewOf3DFeaturesEXT_null();
		init.imageSlicedViewOf3D = imageSlicedViewOf3D;
		return init;
	}

	static inline VkImageViewSlicedCreateInfoEXT vkiImageViewSlicedCreateInfoEXT_null()
	{
		VkImageViewSlicedCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT;
		return init;
	}

	static inline VkImageViewSlicedCreateInfoEXT vkiImageViewSlicedCreateInfoEXT(uint32_t sliceOffset, uint32_t sliceCount)
	{
		VkImageViewSlicedCreateInfoEXT init = vkiImageViewSlicedCreateInfoEXT_null();
		init.sliceOffset = sliceOffset;
		init.sliceCount = sliceCount;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE vkiPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE_null()
	{
		VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE vkiPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(VkBool32 descriptorSetHostMapping)
	{
		VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE init = vkiPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE_null();
		init.descriptorSetHostMapping = descriptorSetHostMapping;
		return init;
	}

	static inline VkDescriptorSetBindingReferenceVALVE vkiDescriptorSetBindingReferenceVALVE_null()
	{
		VkDescriptorSetBindingReferenceVALVE init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE;
		return init;
	}

	static inline VkDescriptorSetBindingReferenceVALVE vkiDescriptorSetBindingReferenceVALVE(VkDescriptorSetLayout descriptorSetLayout, uint32_t binding)
	{
		VkDescriptorSetBindingReferenceVALVE init = vkiDescriptorSetBindingReferenceVALVE_null();
		init.descriptorSetLayout = descriptorSetLayout;
		init.binding = binding;
		return init;
	}

	static inline VkDescriptorSetLayoutHostMappingInfoVALVE vkiDescriptorSetLayoutHostMappingInfoVALVE_null()
	{
		VkDescriptorSetLayoutHostMappingInfoVALVE init = {0};
		init.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE;
		return init;
	}

	static inline VkDescriptorSetLayoutHostMappingInfoVALVE vkiDescriptorSetLayoutHostMappingInfoVALVE(size_t descriptorOffset, uint32_t descriptorSize)
	{
		VkDescriptorSetLayoutHostMappingInfoVALVE init = vkiDescriptorSetLayoutHostMappingInfoVALVE_null();
		init.descriptorOffset = descriptorOffset;
		init.descriptorSize = descriptorSize;
		return init;
	}

	static inline VkPhysicalDeviceDepthClampZeroOneFeaturesEXT vkiPhysicalDeviceDepthClampZeroOneFeaturesEXT_null()
	{
		VkPhysicalDeviceDepthClampZeroOneFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceDepthClampZeroOneFeaturesEXT vkiPhysicalDeviceDepthClampZeroOneFeaturesEXT(VkBool32 depthClampZeroOne)
	{
		VkPhysicalDeviceDepthClampZeroOneFeaturesEXT init = vkiPhysicalDeviceDepthClampZeroOneFeaturesEXT_null();
		init.depthClampZeroOne = depthClampZeroOne;
		return init;
	}

	static inline VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT vkiPhysicalDeviceNonSeamlessCubeMapFeaturesEXT_null()
	{
		VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT vkiPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(VkBool32 nonSeamlessCubeMap)
	{
		VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT init = vkiPhysicalDeviceNonSeamlessCubeMapFeaturesEXT_null();
		init.nonSeamlessCubeMap = nonSeamlessCubeMap;
		return init;
	}

	static inline VkPhysicalDeviceRenderPassStripedFeaturesARM vkiPhysicalDeviceRenderPassStripedFeaturesARM_null()
	{
		VkPhysicalDeviceRenderPassStripedFeaturesARM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM;
		return init;
	}

	static inline VkPhysicalDeviceRenderPassStripedFeaturesARM vkiPhysicalDeviceRenderPassStripedFeaturesARM(VkBool32 renderPassStriped)
	{
		VkPhysicalDeviceRenderPassStripedFeaturesARM init = vkiPhysicalDeviceRenderPassStripedFeaturesARM_null();
		init.renderPassStriped = renderPassStriped;
		return init;
	}

	static inline VkPhysicalDeviceRenderPassStripedPropertiesARM vkiPhysicalDeviceRenderPassStripedPropertiesARM_null()
	{
		VkPhysicalDeviceRenderPassStripedPropertiesARM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM;
		return init;
	}

	static inline VkPhysicalDeviceRenderPassStripedPropertiesARM vkiPhysicalDeviceRenderPassStripedPropertiesARM(VkExtent2D renderPassStripeGranularity, uint32_t maxRenderPassStripes)
	{
		VkPhysicalDeviceRenderPassStripedPropertiesARM init = vkiPhysicalDeviceRenderPassStripedPropertiesARM_null();
		init.renderPassStripeGranularity = renderPassStripeGranularity;
		init.maxRenderPassStripes = maxRenderPassStripes;
		return init;
	}

	static inline VkRenderPassStripeInfoARM vkiRenderPassStripeInfoARM_null()
	{
		VkRenderPassStripeInfoARM init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM;
		return init;
	}

	static inline VkRenderPassStripeInfoARM vkiRenderPassStripeInfoARM(VkRect2D stripeArea)
	{
		VkRenderPassStripeInfoARM init = vkiRenderPassStripeInfoARM_null();
		init.stripeArea = stripeArea;
		return init;
	}

	static inline VkRenderPassStripeBeginInfoARM vkiRenderPassStripeBeginInfoARM_null()
	{
		VkRenderPassStripeBeginInfoARM init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM;
		return init;
	}

	static inline VkRenderPassStripeBeginInfoARM vkiRenderPassStripeBeginInfoARM(uint32_t stripeInfoCount, const VkRenderPassStripeInfoARM *pStripeInfos)
	{
		VkRenderPassStripeBeginInfoARM init = vkiRenderPassStripeBeginInfoARM_null();
		init.stripeInfoCount = stripeInfoCount;
		init.pStripeInfos = pStripeInfos;
		return init;
	}

	static inline VkRenderPassStripeSubmitInfoARM vkiRenderPassStripeSubmitInfoARM_null()
	{
		VkRenderPassStripeSubmitInfoARM init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM;
		return init;
	}

	static inline VkRenderPassStripeSubmitInfoARM vkiRenderPassStripeSubmitInfoARM(uint32_t stripeSemaphoreInfoCount, const VkSemaphoreSubmitInfo *pStripeSemaphoreInfos)
	{
		VkRenderPassStripeSubmitInfoARM init = vkiRenderPassStripeSubmitInfoARM_null();
		init.stripeSemaphoreInfoCount = stripeSemaphoreInfoCount;
		init.pStripeSemaphoreInfos = pStripeSemaphoreInfos;
		return init;
	}

	static inline VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM vkiPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM_null()
	{
		VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM;
		return init;
	}

	static inline VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM vkiPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM(VkBool32 fragmentDensityMapOffset)
	{
		VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM init = vkiPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM_null();
		init.fragmentDensityMapOffset = fragmentDensityMapOffset;
		return init;
	}

	static inline VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM vkiPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM_null()
	{
		VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM;
		return init;
	}

	static inline VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM vkiPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM(VkExtent2D fragmentDensityOffsetGranularity)
	{
		VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM init = vkiPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM_null();
		init.fragmentDensityOffsetGranularity = fragmentDensityOffsetGranularity;
		return init;
	}

	static inline VkSubpassFragmentDensityMapOffsetEndInfoQCOM vkiSubpassFragmentDensityMapOffsetEndInfoQCOM_null()
	{
		VkSubpassFragmentDensityMapOffsetEndInfoQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM;
		return init;
	}

	static inline VkSubpassFragmentDensityMapOffsetEndInfoQCOM vkiSubpassFragmentDensityMapOffsetEndInfoQCOM(uint32_t fragmentDensityOffsetCount, const VkOffset2D *pFragmentDensityOffsets)
	{
		VkSubpassFragmentDensityMapOffsetEndInfoQCOM init = vkiSubpassFragmentDensityMapOffsetEndInfoQCOM_null();
		init.fragmentDensityOffsetCount = fragmentDensityOffsetCount;
		init.pFragmentDensityOffsets = pFragmentDensityOffsets;
		return init;
	}

	static inline VkCopyMemoryIndirectCommandNV vkiCopyMemoryIndirectCommandNV_null()
	{
		VkCopyMemoryIndirectCommandNV init = {0};
		return init;
	}

	static inline VkCopyMemoryIndirectCommandNV vkiCopyMemoryIndirectCommandNV(VkDeviceAddress srcAddress, VkDeviceAddress dstAddress, VkDeviceSize size)
	{
		VkCopyMemoryIndirectCommandNV init = vkiCopyMemoryIndirectCommandNV_null();
		init.srcAddress = srcAddress;
		init.dstAddress = dstAddress;
		init.size = size;
		return init;
	}

	static inline VkCopyMemoryToImageIndirectCommandNV vkiCopyMemoryToImageIndirectCommandNV_null()
	{
		VkCopyMemoryToImageIndirectCommandNV init = {0};
		return init;
	}

	static inline VkCopyMemoryToImageIndirectCommandNV vkiCopyMemoryToImageIndirectCommandNV(VkDeviceAddress srcAddress, uint32_t bufferRowLength, uint32_t bufferImageHeight, VkImageSubresourceLayers imageSubresource, VkOffset3D imageOffset, VkExtent3D imageExtent)
	{
		VkCopyMemoryToImageIndirectCommandNV init = vkiCopyMemoryToImageIndirectCommandNV_null();
		init.srcAddress = srcAddress;
		init.bufferRowLength = bufferRowLength;
		init.bufferImageHeight = bufferImageHeight;
		init.imageSubresource = imageSubresource;
		init.imageOffset = imageOffset;
		init.imageExtent = imageExtent;
		return init;
	}

	static inline VkPhysicalDeviceCopyMemoryIndirectFeaturesNV vkiPhysicalDeviceCopyMemoryIndirectFeaturesNV_null()
	{
		VkPhysicalDeviceCopyMemoryIndirectFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceCopyMemoryIndirectFeaturesNV vkiPhysicalDeviceCopyMemoryIndirectFeaturesNV(VkBool32 indirectCopy)
	{
		VkPhysicalDeviceCopyMemoryIndirectFeaturesNV init = vkiPhysicalDeviceCopyMemoryIndirectFeaturesNV_null();
		init.indirectCopy = indirectCopy;
		return init;
	}

	static inline VkPhysicalDeviceCopyMemoryIndirectPropertiesNV vkiPhysicalDeviceCopyMemoryIndirectPropertiesNV_null()
	{
		VkPhysicalDeviceCopyMemoryIndirectPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV;
		return init;
	}

	static inline VkPhysicalDeviceCopyMemoryIndirectPropertiesNV vkiPhysicalDeviceCopyMemoryIndirectPropertiesNV(VkQueueFlags supportedQueues)
	{
		VkPhysicalDeviceCopyMemoryIndirectPropertiesNV init = vkiPhysicalDeviceCopyMemoryIndirectPropertiesNV_null();
		init.supportedQueues = supportedQueues;
		return init;
	}

	static inline VkDecompressMemoryRegionNV vkiDecompressMemoryRegionNV_null()
	{
		VkDecompressMemoryRegionNV init = {0};
		return init;
	}

	static inline VkDecompressMemoryRegionNV vkiDecompressMemoryRegionNV(VkDeviceAddress srcAddress, VkDeviceAddress dstAddress, VkDeviceSize compressedSize, VkDeviceSize decompressedSize, VkMemoryDecompressionMethodFlagsNV decompressionMethod)
	{
		VkDecompressMemoryRegionNV init = vkiDecompressMemoryRegionNV_null();
		init.srcAddress = srcAddress;
		init.dstAddress = dstAddress;
		init.compressedSize = compressedSize;
		init.decompressedSize = decompressedSize;
		init.decompressionMethod = decompressionMethod;
		return init;
	}

	static inline VkPhysicalDeviceMemoryDecompressionFeaturesNV vkiPhysicalDeviceMemoryDecompressionFeaturesNV_null()
	{
		VkPhysicalDeviceMemoryDecompressionFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceMemoryDecompressionFeaturesNV vkiPhysicalDeviceMemoryDecompressionFeaturesNV(VkBool32 memoryDecompression)
	{
		VkPhysicalDeviceMemoryDecompressionFeaturesNV init = vkiPhysicalDeviceMemoryDecompressionFeaturesNV_null();
		init.memoryDecompression = memoryDecompression;
		return init;
	}

	static inline VkPhysicalDeviceMemoryDecompressionPropertiesNV vkiPhysicalDeviceMemoryDecompressionPropertiesNV_null()
	{
		VkPhysicalDeviceMemoryDecompressionPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV;
		return init;
	}

	static inline VkPhysicalDeviceMemoryDecompressionPropertiesNV vkiPhysicalDeviceMemoryDecompressionPropertiesNV(VkMemoryDecompressionMethodFlagsNV decompressionMethods, uint64_t maxDecompressionIndirectCount)
	{
		VkPhysicalDeviceMemoryDecompressionPropertiesNV init = vkiPhysicalDeviceMemoryDecompressionPropertiesNV_null();
		init.decompressionMethods = decompressionMethods;
		init.maxDecompressionIndirectCount = maxDecompressionIndirectCount;
		return init;
	}

	static inline VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV vkiPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV_null()
	{
		VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV vkiPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(VkBool32 deviceGeneratedCompute, VkBool32 deviceGeneratedComputePipelines, VkBool32 deviceGeneratedComputeCaptureReplay)
	{
		VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV init = vkiPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV_null();
		init.deviceGeneratedCompute = deviceGeneratedCompute;
		init.deviceGeneratedComputePipelines = deviceGeneratedComputePipelines;
		init.deviceGeneratedComputeCaptureReplay = deviceGeneratedComputeCaptureReplay;
		return init;
	}

	static inline VkComputePipelineIndirectBufferInfoNV vkiComputePipelineIndirectBufferInfoNV_null()
	{
		VkComputePipelineIndirectBufferInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV;
		return init;
	}

	static inline VkComputePipelineIndirectBufferInfoNV vkiComputePipelineIndirectBufferInfoNV(VkDeviceAddress deviceAddress, VkDeviceSize size, VkDeviceAddress pipelineDeviceAddressCaptureReplay)
	{
		VkComputePipelineIndirectBufferInfoNV init = vkiComputePipelineIndirectBufferInfoNV_null();
		init.deviceAddress = deviceAddress;
		init.size = size;
		init.pipelineDeviceAddressCaptureReplay = pipelineDeviceAddressCaptureReplay;
		return init;
	}

	static inline VkPipelineIndirectDeviceAddressInfoNV vkiPipelineIndirectDeviceAddressInfoNV_null()
	{
		VkPipelineIndirectDeviceAddressInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV;
		return init;
	}

	static inline VkPipelineIndirectDeviceAddressInfoNV vkiPipelineIndirectDeviceAddressInfoNV(VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline)
	{
		VkPipelineIndirectDeviceAddressInfoNV init = vkiPipelineIndirectDeviceAddressInfoNV_null();
		init.pipelineBindPoint = pipelineBindPoint;
		init.pipeline = pipeline;
		return init;
	}

	static inline VkBindPipelineIndirectCommandNV vkiBindPipelineIndirectCommandNV_null()
	{
		VkBindPipelineIndirectCommandNV init = {0};
		return init;
	}

	static inline VkBindPipelineIndirectCommandNV vkiBindPipelineIndirectCommandNV(VkDeviceAddress pipelineAddress)
	{
		VkBindPipelineIndirectCommandNV init = vkiBindPipelineIndirectCommandNV_null();
		init.pipelineAddress = pipelineAddress;
		return init;
	}

	static inline VkPhysicalDeviceLinearColorAttachmentFeaturesNV vkiPhysicalDeviceLinearColorAttachmentFeaturesNV_null()
	{
		VkPhysicalDeviceLinearColorAttachmentFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceLinearColorAttachmentFeaturesNV vkiPhysicalDeviceLinearColorAttachmentFeaturesNV(VkBool32 linearColorAttachment)
	{
		VkPhysicalDeviceLinearColorAttachmentFeaturesNV init = vkiPhysicalDeviceLinearColorAttachmentFeaturesNV_null();
		init.linearColorAttachment = linearColorAttachment;
		return init;
	}

	static inline VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT vkiPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT_null()
	{
		VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT vkiPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(VkBool32 imageCompressionControlSwapchain)
	{
		VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT init = vkiPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT_null();
		init.imageCompressionControlSwapchain = imageCompressionControlSwapchain;
		return init;
	}

	static inline VkImageViewSampleWeightCreateInfoQCOM vkiImageViewSampleWeightCreateInfoQCOM_null()
	{
		VkImageViewSampleWeightCreateInfoQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM;
		return init;
	}

	static inline VkImageViewSampleWeightCreateInfoQCOM vkiImageViewSampleWeightCreateInfoQCOM(VkOffset2D filterCenter, VkExtent2D filterSize, uint32_t numPhases)
	{
		VkImageViewSampleWeightCreateInfoQCOM init = vkiImageViewSampleWeightCreateInfoQCOM_null();
		init.filterCenter = filterCenter;
		init.filterSize = filterSize;
		init.numPhases = numPhases;
		return init;
	}

	static inline VkPhysicalDeviceImageProcessingFeaturesQCOM vkiPhysicalDeviceImageProcessingFeaturesQCOM_null()
	{
		VkPhysicalDeviceImageProcessingFeaturesQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM;
		return init;
	}

	static inline VkPhysicalDeviceImageProcessingFeaturesQCOM vkiPhysicalDeviceImageProcessingFeaturesQCOM(VkBool32 textureSampleWeighted, VkBool32 textureBoxFilter, VkBool32 textureBlockMatch)
	{
		VkPhysicalDeviceImageProcessingFeaturesQCOM init = vkiPhysicalDeviceImageProcessingFeaturesQCOM_null();
		init.textureSampleWeighted = textureSampleWeighted;
		init.textureBoxFilter = textureBoxFilter;
		init.textureBlockMatch = textureBlockMatch;
		return init;
	}

	static inline VkPhysicalDeviceImageProcessingPropertiesQCOM vkiPhysicalDeviceImageProcessingPropertiesQCOM_null()
	{
		VkPhysicalDeviceImageProcessingPropertiesQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM;
		return init;
	}

	static inline VkPhysicalDeviceImageProcessingPropertiesQCOM vkiPhysicalDeviceImageProcessingPropertiesQCOM(uint32_t maxWeightFilterPhases, VkExtent2D maxWeightFilterDimension, VkExtent2D maxBlockMatchRegion, VkExtent2D maxBoxFilterBlockSize)
	{
		VkPhysicalDeviceImageProcessingPropertiesQCOM init = vkiPhysicalDeviceImageProcessingPropertiesQCOM_null();
		init.maxWeightFilterPhases = maxWeightFilterPhases;
		init.maxWeightFilterDimension = maxWeightFilterDimension;
		init.maxBlockMatchRegion = maxBlockMatchRegion;
		init.maxBoxFilterBlockSize = maxBoxFilterBlockSize;
		return init;
	}

	static inline VkPhysicalDeviceNestedCommandBufferFeaturesEXT vkiPhysicalDeviceNestedCommandBufferFeaturesEXT_null()
	{
		VkPhysicalDeviceNestedCommandBufferFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceNestedCommandBufferFeaturesEXT vkiPhysicalDeviceNestedCommandBufferFeaturesEXT(VkBool32 nestedCommandBuffer, VkBool32 nestedCommandBufferRendering, VkBool32 nestedCommandBufferSimultaneousUse)
	{
		VkPhysicalDeviceNestedCommandBufferFeaturesEXT init = vkiPhysicalDeviceNestedCommandBufferFeaturesEXT_null();
		init.nestedCommandBuffer = nestedCommandBuffer;
		init.nestedCommandBufferRendering = nestedCommandBufferRendering;
		init.nestedCommandBufferSimultaneousUse = nestedCommandBufferSimultaneousUse;
		return init;
	}

	static inline VkPhysicalDeviceNestedCommandBufferPropertiesEXT vkiPhysicalDeviceNestedCommandBufferPropertiesEXT_null()
	{
		VkPhysicalDeviceNestedCommandBufferPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceNestedCommandBufferPropertiesEXT vkiPhysicalDeviceNestedCommandBufferPropertiesEXT(uint32_t maxCommandBufferNestingLevel)
	{
		VkPhysicalDeviceNestedCommandBufferPropertiesEXT init = vkiPhysicalDeviceNestedCommandBufferPropertiesEXT_null();
		init.maxCommandBufferNestingLevel = maxCommandBufferNestingLevel;
		return init;
	}

	static inline VkExternalMemoryAcquireUnmodifiedEXT vkiExternalMemoryAcquireUnmodifiedEXT_null()
	{
		VkExternalMemoryAcquireUnmodifiedEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT;
		return init;
	}

	static inline VkExternalMemoryAcquireUnmodifiedEXT vkiExternalMemoryAcquireUnmodifiedEXT(VkBool32 acquireUnmodifiedMemory)
	{
		VkExternalMemoryAcquireUnmodifiedEXT init = vkiExternalMemoryAcquireUnmodifiedEXT_null();
		init.acquireUnmodifiedMemory = acquireUnmodifiedMemory;
		return init;
	}

	static inline VkPhysicalDeviceExtendedDynamicState3FeaturesEXT vkiPhysicalDeviceExtendedDynamicState3FeaturesEXT_null()
	{
		VkPhysicalDeviceExtendedDynamicState3FeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceExtendedDynamicState3FeaturesEXT vkiPhysicalDeviceExtendedDynamicState3FeaturesEXT(VkBool32 extendedDynamicState3TessellationDomainOrigin, VkBool32 extendedDynamicState3DepthClampEnable, VkBool32 extendedDynamicState3PolygonMode, VkBool32 extendedDynamicState3RasterizationSamples, VkBool32 extendedDynamicState3SampleMask, VkBool32 extendedDynamicState3AlphaToCoverageEnable, VkBool32 extendedDynamicState3AlphaToOneEnable, VkBool32 extendedDynamicState3LogicOpEnable, VkBool32 extendedDynamicState3ColorBlendEnable, VkBool32 extendedDynamicState3ColorBlendEquation, VkBool32 extendedDynamicState3ColorWriteMask, VkBool32 extendedDynamicState3RasterizationStream, VkBool32 extendedDynamicState3ConservativeRasterizationMode, VkBool32 extendedDynamicState3ExtraPrimitiveOverestimationSize, VkBool32 extendedDynamicState3DepthClipEnable, VkBool32 extendedDynamicState3SampleLocationsEnable, VkBool32 extendedDynamicState3ColorBlendAdvanced, VkBool32 extendedDynamicState3ProvokingVertexMode, VkBool32 extendedDynamicState3LineRasterizationMode, VkBool32 extendedDynamicState3LineStippleEnable, VkBool32 extendedDynamicState3DepthClipNegativeOneToOne, VkBool32 extendedDynamicState3ViewportWScalingEnable, VkBool32 extendedDynamicState3ViewportSwizzle, VkBool32 extendedDynamicState3CoverageToColorEnable, VkBool32 extendedDynamicState3CoverageToColorLocation, VkBool32 extendedDynamicState3CoverageModulationMode, VkBool32 extendedDynamicState3CoverageModulationTableEnable, VkBool32 extendedDynamicState3CoverageModulationTable, VkBool32 extendedDynamicState3CoverageReductionMode, VkBool32 extendedDynamicState3RepresentativeFragmentTestEnable, VkBool32 extendedDynamicState3ShadingRateImageEnable)
	{
		VkPhysicalDeviceExtendedDynamicState3FeaturesEXT init = vkiPhysicalDeviceExtendedDynamicState3FeaturesEXT_null();
		init.extendedDynamicState3TessellationDomainOrigin = extendedDynamicState3TessellationDomainOrigin;
		init.extendedDynamicState3DepthClampEnable = extendedDynamicState3DepthClampEnable;
		init.extendedDynamicState3PolygonMode = extendedDynamicState3PolygonMode;
		init.extendedDynamicState3RasterizationSamples = extendedDynamicState3RasterizationSamples;
		init.extendedDynamicState3SampleMask = extendedDynamicState3SampleMask;
		init.extendedDynamicState3AlphaToCoverageEnable = extendedDynamicState3AlphaToCoverageEnable;
		init.extendedDynamicState3AlphaToOneEnable = extendedDynamicState3AlphaToOneEnable;
		init.extendedDynamicState3LogicOpEnable = extendedDynamicState3LogicOpEnable;
		init.extendedDynamicState3ColorBlendEnable = extendedDynamicState3ColorBlendEnable;
		init.extendedDynamicState3ColorBlendEquation = extendedDynamicState3ColorBlendEquation;
		init.extendedDynamicState3ColorWriteMask = extendedDynamicState3ColorWriteMask;
		init.extendedDynamicState3RasterizationStream = extendedDynamicState3RasterizationStream;
		init.extendedDynamicState3ConservativeRasterizationMode = extendedDynamicState3ConservativeRasterizationMode;
		init.extendedDynamicState3ExtraPrimitiveOverestimationSize = extendedDynamicState3ExtraPrimitiveOverestimationSize;
		init.extendedDynamicState3DepthClipEnable = extendedDynamicState3DepthClipEnable;
		init.extendedDynamicState3SampleLocationsEnable = extendedDynamicState3SampleLocationsEnable;
		init.extendedDynamicState3ColorBlendAdvanced = extendedDynamicState3ColorBlendAdvanced;
		init.extendedDynamicState3ProvokingVertexMode = extendedDynamicState3ProvokingVertexMode;
		init.extendedDynamicState3LineRasterizationMode = extendedDynamicState3LineRasterizationMode;
		init.extendedDynamicState3LineStippleEnable = extendedDynamicState3LineStippleEnable;
		init.extendedDynamicState3DepthClipNegativeOneToOne = extendedDynamicState3DepthClipNegativeOneToOne;
		init.extendedDynamicState3ViewportWScalingEnable = extendedDynamicState3ViewportWScalingEnable;
		init.extendedDynamicState3ViewportSwizzle = extendedDynamicState3ViewportSwizzle;
		init.extendedDynamicState3CoverageToColorEnable = extendedDynamicState3CoverageToColorEnable;
		init.extendedDynamicState3CoverageToColorLocation = extendedDynamicState3CoverageToColorLocation;
		init.extendedDynamicState3CoverageModulationMode = extendedDynamicState3CoverageModulationMode;
		init.extendedDynamicState3CoverageModulationTableEnable = extendedDynamicState3CoverageModulationTableEnable;
		init.extendedDynamicState3CoverageModulationTable = extendedDynamicState3CoverageModulationTable;
		init.extendedDynamicState3CoverageReductionMode = extendedDynamicState3CoverageReductionMode;
		init.extendedDynamicState3RepresentativeFragmentTestEnable = extendedDynamicState3RepresentativeFragmentTestEnable;
		init.extendedDynamicState3ShadingRateImageEnable = extendedDynamicState3ShadingRateImageEnable;
		return init;
	}

	static inline VkPhysicalDeviceExtendedDynamicState3PropertiesEXT vkiPhysicalDeviceExtendedDynamicState3PropertiesEXT_null()
	{
		VkPhysicalDeviceExtendedDynamicState3PropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceExtendedDynamicState3PropertiesEXT vkiPhysicalDeviceExtendedDynamicState3PropertiesEXT(VkBool32 dynamicPrimitiveTopologyUnrestricted)
	{
		VkPhysicalDeviceExtendedDynamicState3PropertiesEXT init = vkiPhysicalDeviceExtendedDynamicState3PropertiesEXT_null();
		init.dynamicPrimitiveTopologyUnrestricted = dynamicPrimitiveTopologyUnrestricted;
		return init;
	}

	static inline VkColorBlendEquationEXT vkiColorBlendEquationEXT_null()
	{
		VkColorBlendEquationEXT init = {0};
		return init;
	}

	static inline VkColorBlendEquationEXT vkiColorBlendEquationEXT(VkBlendFactor srcColorBlendFactor, VkBlendFactor dstColorBlendFactor, VkBlendOp colorBlendOp, VkBlendFactor srcAlphaBlendFactor, VkBlendFactor dstAlphaBlendFactor, VkBlendOp alphaBlendOp)
	{
		VkColorBlendEquationEXT init = vkiColorBlendEquationEXT_null();
		init.srcColorBlendFactor = srcColorBlendFactor;
		init.dstColorBlendFactor = dstColorBlendFactor;
		init.colorBlendOp = colorBlendOp;
		init.srcAlphaBlendFactor = srcAlphaBlendFactor;
		init.dstAlphaBlendFactor = dstAlphaBlendFactor;
		init.alphaBlendOp = alphaBlendOp;
		return init;
	}

	static inline VkColorBlendAdvancedEXT vkiColorBlendAdvancedEXT_null()
	{
		VkColorBlendAdvancedEXT init = {0};
		return init;
	}

	static inline VkColorBlendAdvancedEXT vkiColorBlendAdvancedEXT(VkBlendOp advancedBlendOp, VkBool32 srcPremultiplied, VkBool32 dstPremultiplied, VkBlendOverlapEXT blendOverlap, VkBool32 clampResults)
	{
		VkColorBlendAdvancedEXT init = vkiColorBlendAdvancedEXT_null();
		init.advancedBlendOp = advancedBlendOp;
		init.srcPremultiplied = srcPremultiplied;
		init.dstPremultiplied = dstPremultiplied;
		init.blendOverlap = blendOverlap;
		init.clampResults = clampResults;
		return init;
	}

	static inline VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT vkiPhysicalDeviceSubpassMergeFeedbackFeaturesEXT_null()
	{
		VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT vkiPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(VkBool32 subpassMergeFeedback)
	{
		VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT init = vkiPhysicalDeviceSubpassMergeFeedbackFeaturesEXT_null();
		init.subpassMergeFeedback = subpassMergeFeedback;
		return init;
	}

	static inline VkRenderPassCreationControlEXT vkiRenderPassCreationControlEXT_null()
	{
		VkRenderPassCreationControlEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT;
		return init;
	}

	static inline VkRenderPassCreationControlEXT vkiRenderPassCreationControlEXT(VkBool32 disallowMerging)
	{
		VkRenderPassCreationControlEXT init = vkiRenderPassCreationControlEXT_null();
		init.disallowMerging = disallowMerging;
		return init;
	}

	static inline VkRenderPassCreationFeedbackInfoEXT vkiRenderPassCreationFeedbackInfoEXT_null()
	{
		VkRenderPassCreationFeedbackInfoEXT init = {0};
		return init;
	}

	static inline VkRenderPassCreationFeedbackInfoEXT vkiRenderPassCreationFeedbackInfoEXT(uint32_t postMergeSubpassCount)
	{
		VkRenderPassCreationFeedbackInfoEXT init = vkiRenderPassCreationFeedbackInfoEXT_null();
		init.postMergeSubpassCount = postMergeSubpassCount;
		return init;
	}

	static inline VkRenderPassCreationFeedbackCreateInfoEXT vkiRenderPassCreationFeedbackCreateInfoEXT_null()
	{
		VkRenderPassCreationFeedbackCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT;
		return init;
	}

	static inline VkRenderPassCreationFeedbackCreateInfoEXT vkiRenderPassCreationFeedbackCreateInfoEXT(VkRenderPassCreationFeedbackInfoEXT *pRenderPassFeedback)
	{
		VkRenderPassCreationFeedbackCreateInfoEXT init = vkiRenderPassCreationFeedbackCreateInfoEXT_null();
		init.pRenderPassFeedback = pRenderPassFeedback;
		return init;
	}

	static inline VkRenderPassSubpassFeedbackInfoEXT vkiRenderPassSubpassFeedbackInfoEXT_null()
	{
		VkRenderPassSubpassFeedbackInfoEXT init = {0};
		return init;
	}

	static inline VkRenderPassSubpassFeedbackInfoEXT vkiRenderPassSubpassFeedbackInfoEXT(VkSubpassMergeStatusEXT subpassMergeStatus, uint32_t postMergeIndex)
	{
		VkRenderPassSubpassFeedbackInfoEXT init = vkiRenderPassSubpassFeedbackInfoEXT_null();
		init.subpassMergeStatus = subpassMergeStatus;
		init.postMergeIndex = postMergeIndex;
		return init;
	}

	static inline VkRenderPassSubpassFeedbackCreateInfoEXT vkiRenderPassSubpassFeedbackCreateInfoEXT_null()
	{
		VkRenderPassSubpassFeedbackCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT;
		return init;
	}

	static inline VkRenderPassSubpassFeedbackCreateInfoEXT vkiRenderPassSubpassFeedbackCreateInfoEXT(VkRenderPassSubpassFeedbackInfoEXT *pSubpassFeedback)
	{
		VkRenderPassSubpassFeedbackCreateInfoEXT init = vkiRenderPassSubpassFeedbackCreateInfoEXT_null();
		init.pSubpassFeedback = pSubpassFeedback;
		return init;
	}

	static inline VkDirectDriverLoadingInfoLUNARG vkiDirectDriverLoadingInfoLUNARG_null()
	{
		VkDirectDriverLoadingInfoLUNARG init = {0};
		init.sType = VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG;
		return init;
	}

	static inline VkDirectDriverLoadingInfoLUNARG vkiDirectDriverLoadingInfoLUNARG(PFN_vkGetInstanceProcAddrLUNARG pfnGetInstanceProcAddr)
	{
		VkDirectDriverLoadingInfoLUNARG init = vkiDirectDriverLoadingInfoLUNARG_null();
		init.pfnGetInstanceProcAddr = pfnGetInstanceProcAddr;
		return init;
	}

	static inline VkDirectDriverLoadingListLUNARG vkiDirectDriverLoadingListLUNARG_null()
	{
		VkDirectDriverLoadingListLUNARG init = {0};
		init.sType = VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG;
		return init;
	}

	static inline VkDirectDriverLoadingListLUNARG vkiDirectDriverLoadingListLUNARG(VkDirectDriverLoadingModeLUNARG mode, uint32_t driverCount, const VkDirectDriverLoadingInfoLUNARG *pDrivers)
	{
		VkDirectDriverLoadingListLUNARG init = vkiDirectDriverLoadingListLUNARG_null();
		init.mode = mode;
		init.driverCount = driverCount;
		init.pDrivers = pDrivers;
		return init;
	}

	static inline VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT vkiPhysicalDeviceShaderModuleIdentifierFeaturesEXT_null()
	{
		VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT vkiPhysicalDeviceShaderModuleIdentifierFeaturesEXT(VkBool32 shaderModuleIdentifier)
	{
		VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT init = vkiPhysicalDeviceShaderModuleIdentifierFeaturesEXT_null();
		init.shaderModuleIdentifier = shaderModuleIdentifier;
		return init;
	}

	static inline VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT vkiPhysicalDeviceShaderModuleIdentifierPropertiesEXT_null()
	{
		VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT vkiPhysicalDeviceShaderModuleIdentifierPropertiesEXT()
	{
		VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT init = vkiPhysicalDeviceShaderModuleIdentifierPropertiesEXT_null();
		return init;
	}

	static inline VkPipelineShaderStageModuleIdentifierCreateInfoEXT vkiPipelineShaderStageModuleIdentifierCreateInfoEXT_null()
	{
		VkPipelineShaderStageModuleIdentifierCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT;
		return init;
	}

	static inline VkPipelineShaderStageModuleIdentifierCreateInfoEXT vkiPipelineShaderStageModuleIdentifierCreateInfoEXT(uint32_t identifierSize, const uint8_t *pIdentifier)
	{
		VkPipelineShaderStageModuleIdentifierCreateInfoEXT init = vkiPipelineShaderStageModuleIdentifierCreateInfoEXT_null();
		init.identifierSize = identifierSize;
		init.pIdentifier = pIdentifier;
		return init;
	}

	static inline VkShaderModuleIdentifierEXT vkiShaderModuleIdentifierEXT_null()
	{
		VkShaderModuleIdentifierEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT;
		return init;
	}

	static inline VkShaderModuleIdentifierEXT vkiShaderModuleIdentifierEXT(uint32_t identifierSize)
	{
		VkShaderModuleIdentifierEXT init = vkiShaderModuleIdentifierEXT_null();
		init.identifierSize = identifierSize;
		return init;
	}

	static inline VkPhysicalDeviceOpticalFlowFeaturesNV vkiPhysicalDeviceOpticalFlowFeaturesNV_null()
	{
		VkPhysicalDeviceOpticalFlowFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceOpticalFlowFeaturesNV vkiPhysicalDeviceOpticalFlowFeaturesNV(VkBool32 opticalFlow)
	{
		VkPhysicalDeviceOpticalFlowFeaturesNV init = vkiPhysicalDeviceOpticalFlowFeaturesNV_null();
		init.opticalFlow = opticalFlow;
		return init;
	}

	static inline VkPhysicalDeviceOpticalFlowPropertiesNV vkiPhysicalDeviceOpticalFlowPropertiesNV_null()
	{
		VkPhysicalDeviceOpticalFlowPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV;
		return init;
	}

	static inline VkPhysicalDeviceOpticalFlowPropertiesNV vkiPhysicalDeviceOpticalFlowPropertiesNV(VkOpticalFlowGridSizeFlagsNV supportedOutputGridSizes, VkOpticalFlowGridSizeFlagsNV supportedHintGridSizes, VkBool32 hintSupported, VkBool32 costSupported, VkBool32 bidirectionalFlowSupported, VkBool32 globalFlowSupported, uint32_t minWidth, uint32_t minHeight, uint32_t maxWidth, uint32_t maxHeight, uint32_t maxNumRegionsOfInterest)
	{
		VkPhysicalDeviceOpticalFlowPropertiesNV init = vkiPhysicalDeviceOpticalFlowPropertiesNV_null();
		init.supportedOutputGridSizes = supportedOutputGridSizes;
		init.supportedHintGridSizes = supportedHintGridSizes;
		init.hintSupported = hintSupported;
		init.costSupported = costSupported;
		init.bidirectionalFlowSupported = bidirectionalFlowSupported;
		init.globalFlowSupported = globalFlowSupported;
		init.minWidth = minWidth;
		init.minHeight = minHeight;
		init.maxWidth = maxWidth;
		init.maxHeight = maxHeight;
		init.maxNumRegionsOfInterest = maxNumRegionsOfInterest;
		return init;
	}

	static inline VkOpticalFlowImageFormatInfoNV vkiOpticalFlowImageFormatInfoNV_null()
	{
		VkOpticalFlowImageFormatInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV;
		return init;
	}

	static inline VkOpticalFlowImageFormatInfoNV vkiOpticalFlowImageFormatInfoNV(VkOpticalFlowUsageFlagsNV usage)
	{
		VkOpticalFlowImageFormatInfoNV init = vkiOpticalFlowImageFormatInfoNV_null();
		init.usage = usage;
		return init;
	}

	static inline VkOpticalFlowImageFormatPropertiesNV vkiOpticalFlowImageFormatPropertiesNV_null()
	{
		VkOpticalFlowImageFormatPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV;
		return init;
	}

	static inline VkOpticalFlowImageFormatPropertiesNV vkiOpticalFlowImageFormatPropertiesNV(VkFormat format)
	{
		VkOpticalFlowImageFormatPropertiesNV init = vkiOpticalFlowImageFormatPropertiesNV_null();
		init.format = format;
		return init;
	}

	static inline VkOpticalFlowSessionCreateInfoNV vkiOpticalFlowSessionCreateInfoNV_null()
	{
		VkOpticalFlowSessionCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV;
		return init;
	}

	static inline VkOpticalFlowSessionCreateInfoNV vkiOpticalFlowSessionCreateInfoNV(uint32_t width, uint32_t height, VkFormat imageFormat, VkFormat flowVectorFormat, VkFormat costFormat, VkOpticalFlowGridSizeFlagsNV outputGridSize, VkOpticalFlowGridSizeFlagsNV hintGridSize, VkOpticalFlowPerformanceLevelNV performanceLevel)
	{
		VkOpticalFlowSessionCreateInfoNV init = vkiOpticalFlowSessionCreateInfoNV_null();
		init.width = width;
		init.height = height;
		init.imageFormat = imageFormat;
		init.flowVectorFormat = flowVectorFormat;
		init.costFormat = costFormat;
		init.outputGridSize = outputGridSize;
		init.hintGridSize = hintGridSize;
		init.performanceLevel = performanceLevel;
		return init;
	}

	static inline VkOpticalFlowSessionCreatePrivateDataInfoNV vkiOpticalFlowSessionCreatePrivateDataInfoNV_null()
	{
		VkOpticalFlowSessionCreatePrivateDataInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV;
		return init;
	}

	static inline VkOpticalFlowSessionCreatePrivateDataInfoNV vkiOpticalFlowSessionCreatePrivateDataInfoNV(uint32_t id, uint32_t size, const void *pPrivateData)
	{
		VkOpticalFlowSessionCreatePrivateDataInfoNV init = vkiOpticalFlowSessionCreatePrivateDataInfoNV_null();
		init.id = id;
		init.size = size;
		init.pPrivateData = pPrivateData;
		return init;
	}

	static inline VkOpticalFlowExecuteInfoNV vkiOpticalFlowExecuteInfoNV_null()
	{
		VkOpticalFlowExecuteInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV;
		return init;
	}

	static inline VkOpticalFlowExecuteInfoNV vkiOpticalFlowExecuteInfoNV(uint32_t regionCount, const VkRect2D *pRegions)
	{
		VkOpticalFlowExecuteInfoNV init = vkiOpticalFlowExecuteInfoNV_null();
		init.regionCount = regionCount;
		init.pRegions = pRegions;
		return init;
	}

	static inline VkPhysicalDeviceLegacyDitheringFeaturesEXT vkiPhysicalDeviceLegacyDitheringFeaturesEXT_null()
	{
		VkPhysicalDeviceLegacyDitheringFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceLegacyDitheringFeaturesEXT vkiPhysicalDeviceLegacyDitheringFeaturesEXT(VkBool32 legacyDithering)
	{
		VkPhysicalDeviceLegacyDitheringFeaturesEXT init = vkiPhysicalDeviceLegacyDitheringFeaturesEXT_null();
		init.legacyDithering = legacyDithering;
		return init;
	}

	static inline VkPhysicalDevicePipelineProtectedAccessFeaturesEXT vkiPhysicalDevicePipelineProtectedAccessFeaturesEXT_null()
	{
		VkPhysicalDevicePipelineProtectedAccessFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDevicePipelineProtectedAccessFeaturesEXT vkiPhysicalDevicePipelineProtectedAccessFeaturesEXT(VkBool32 pipelineProtectedAccess)
	{
		VkPhysicalDevicePipelineProtectedAccessFeaturesEXT init = vkiPhysicalDevicePipelineProtectedAccessFeaturesEXT_null();
		init.pipelineProtectedAccess = pipelineProtectedAccess;
		return init;
	}

	static inline VkPhysicalDeviceShaderObjectFeaturesEXT vkiPhysicalDeviceShaderObjectFeaturesEXT_null()
	{
		VkPhysicalDeviceShaderObjectFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceShaderObjectFeaturesEXT vkiPhysicalDeviceShaderObjectFeaturesEXT(VkBool32 shaderObject)
	{
		VkPhysicalDeviceShaderObjectFeaturesEXT init = vkiPhysicalDeviceShaderObjectFeaturesEXT_null();
		init.shaderObject = shaderObject;
		return init;
	}

	static inline VkPhysicalDeviceShaderObjectPropertiesEXT vkiPhysicalDeviceShaderObjectPropertiesEXT_null()
	{
		VkPhysicalDeviceShaderObjectPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceShaderObjectPropertiesEXT vkiPhysicalDeviceShaderObjectPropertiesEXT(uint32_t shaderBinaryVersion)
	{
		VkPhysicalDeviceShaderObjectPropertiesEXT init = vkiPhysicalDeviceShaderObjectPropertiesEXT_null();
		init.shaderBinaryVersion = shaderBinaryVersion;
		return init;
	}

	static inline VkShaderCreateInfoEXT vkiShaderCreateInfoEXT_null()
	{
		VkShaderCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT;
		return init;
	}

	static inline VkShaderCreateInfoEXT vkiShaderCreateInfoEXT(VkShaderStageFlagBits stage, VkShaderStageFlags nextStage, VkShaderCodeTypeEXT codeType, size_t codeSize, const void *pCode, const char *pName, uint32_t setLayoutCount, const VkDescriptorSetLayout *pSetLayouts, uint32_t pushConstantRangeCount, const VkPushConstantRange *pPushConstantRanges, const VkSpecializationInfo *pSpecializationInfo)
	{
		VkShaderCreateInfoEXT init = vkiShaderCreateInfoEXT_null();
		init.stage = stage;
		init.nextStage = nextStage;
		init.codeType = codeType;
		init.codeSize = codeSize;
		init.pCode = pCode;
		init.pName = pName;
		init.setLayoutCount = setLayoutCount;
		init.pSetLayouts = pSetLayouts;
		init.pushConstantRangeCount = pushConstantRangeCount;
		init.pPushConstantRanges = pPushConstantRanges;
		init.pSpecializationInfo = pSpecializationInfo;
		return init;
	}

	static inline VkPhysicalDeviceTilePropertiesFeaturesQCOM vkiPhysicalDeviceTilePropertiesFeaturesQCOM_null()
	{
		VkPhysicalDeviceTilePropertiesFeaturesQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM;
		return init;
	}

	static inline VkPhysicalDeviceTilePropertiesFeaturesQCOM vkiPhysicalDeviceTilePropertiesFeaturesQCOM(VkBool32 tileProperties)
	{
		VkPhysicalDeviceTilePropertiesFeaturesQCOM init = vkiPhysicalDeviceTilePropertiesFeaturesQCOM_null();
		init.tileProperties = tileProperties;
		return init;
	}

	static inline VkTilePropertiesQCOM vkiTilePropertiesQCOM_null()
	{
		VkTilePropertiesQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM;
		return init;
	}

	static inline VkTilePropertiesQCOM vkiTilePropertiesQCOM(VkExtent3D tileSize, VkExtent2D apronSize, VkOffset2D origin)
	{
		VkTilePropertiesQCOM init = vkiTilePropertiesQCOM_null();
		init.tileSize = tileSize;
		init.apronSize = apronSize;
		init.origin = origin;
		return init;
	}

	static inline VkPhysicalDeviceAmigoProfilingFeaturesSEC vkiPhysicalDeviceAmigoProfilingFeaturesSEC_null()
	{
		VkPhysicalDeviceAmigoProfilingFeaturesSEC init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC;
		return init;
	}

	static inline VkPhysicalDeviceAmigoProfilingFeaturesSEC vkiPhysicalDeviceAmigoProfilingFeaturesSEC(VkBool32 amigoProfiling)
	{
		VkPhysicalDeviceAmigoProfilingFeaturesSEC init = vkiPhysicalDeviceAmigoProfilingFeaturesSEC_null();
		init.amigoProfiling = amigoProfiling;
		return init;
	}

	static inline VkAmigoProfilingSubmitInfoSEC vkiAmigoProfilingSubmitInfoSEC_null()
	{
		VkAmigoProfilingSubmitInfoSEC init = {0};
		init.sType = VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC;
		return init;
	}

	static inline VkAmigoProfilingSubmitInfoSEC vkiAmigoProfilingSubmitInfoSEC(uint64_t firstDrawTimestamp, uint64_t swapBufferTimestamp)
	{
		VkAmigoProfilingSubmitInfoSEC init = vkiAmigoProfilingSubmitInfoSEC_null();
		init.firstDrawTimestamp = firstDrawTimestamp;
		init.swapBufferTimestamp = swapBufferTimestamp;
		return init;
	}

	static inline VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM vkiPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM_null()
	{
		VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM;
		return init;
	}

	static inline VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM vkiPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(VkBool32 multiviewPerViewViewports)
	{
		VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM init = vkiPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM_null();
		init.multiviewPerViewViewports = multiviewPerViewViewports;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV vkiPhysicalDeviceRayTracingInvocationReorderPropertiesNV_null()
	{
		VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV vkiPhysicalDeviceRayTracingInvocationReorderPropertiesNV(VkRayTracingInvocationReorderModeNV rayTracingInvocationReorderReorderingHint)
	{
		VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV init = vkiPhysicalDeviceRayTracingInvocationReorderPropertiesNV_null();
		init.rayTracingInvocationReorderReorderingHint = rayTracingInvocationReorderReorderingHint;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV vkiPhysicalDeviceRayTracingInvocationReorderFeaturesNV_null()
	{
		VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV vkiPhysicalDeviceRayTracingInvocationReorderFeaturesNV(VkBool32 rayTracingInvocationReorder)
	{
		VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV init = vkiPhysicalDeviceRayTracingInvocationReorderFeaturesNV_null();
		init.rayTracingInvocationReorder = rayTracingInvocationReorder;
		return init;
	}

	static inline VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV vkiPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV_null()
	{
		VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV vkiPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(VkBool32 extendedSparseAddressSpace)
	{
		VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV init = vkiPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV_null();
		init.extendedSparseAddressSpace = extendedSparseAddressSpace;
		return init;
	}

	static inline VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV vkiPhysicalDeviceExtendedSparseAddressSpacePropertiesNV_null()
	{
		VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV;
		return init;
	}

	static inline VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV vkiPhysicalDeviceExtendedSparseAddressSpacePropertiesNV(VkDeviceSize extendedSparseAddressSpaceSize, VkImageUsageFlags extendedSparseImageUsageFlags, VkBufferUsageFlags extendedSparseBufferUsageFlags)
	{
		VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV init = vkiPhysicalDeviceExtendedSparseAddressSpacePropertiesNV_null();
		init.extendedSparseAddressSpaceSize = extendedSparseAddressSpaceSize;
		init.extendedSparseImageUsageFlags = extendedSparseImageUsageFlags;
		init.extendedSparseBufferUsageFlags = extendedSparseBufferUsageFlags;
		return init;
	}

	static inline VkLayerSettingEXT vkiLayerSettingEXT_null()
	{
		VkLayerSettingEXT init = {0};
		return init;
	}

	static inline VkLayerSettingEXT vkiLayerSettingEXT(const char *pLayerName, const char *pSettingName, VkLayerSettingTypeEXT type, uint32_t valueCount, const void *pValues)
	{
		VkLayerSettingEXT init = vkiLayerSettingEXT_null();
		init.pLayerName = pLayerName;
		init.pSettingName = pSettingName;
		init.type = type;
		init.valueCount = valueCount;
		init.pValues = pValues;
		return init;
	}

	static inline VkLayerSettingsCreateInfoEXT vkiLayerSettingsCreateInfoEXT_null()
	{
		VkLayerSettingsCreateInfoEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT;
		return init;
	}

	static inline VkLayerSettingsCreateInfoEXT vkiLayerSettingsCreateInfoEXT(uint32_t settingCount, const VkLayerSettingEXT *pSettings)
	{
		VkLayerSettingsCreateInfoEXT init = vkiLayerSettingsCreateInfoEXT_null();
		init.settingCount = settingCount;
		init.pSettings = pSettings;
		return init;
	}

	static inline VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM vkiPhysicalDeviceShaderCoreBuiltinsFeaturesARM_null()
	{
		VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM;
		return init;
	}

	static inline VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM vkiPhysicalDeviceShaderCoreBuiltinsFeaturesARM(VkBool32 shaderCoreBuiltins)
	{
		VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM init = vkiPhysicalDeviceShaderCoreBuiltinsFeaturesARM_null();
		init.shaderCoreBuiltins = shaderCoreBuiltins;
		return init;
	}

	static inline VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM vkiPhysicalDeviceShaderCoreBuiltinsPropertiesARM_null()
	{
		VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM;
		return init;
	}

	static inline VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM vkiPhysicalDeviceShaderCoreBuiltinsPropertiesARM(uint64_t shaderCoreMask, uint32_t shaderCoreCount, uint32_t shaderWarpsPerCore)
	{
		VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM init = vkiPhysicalDeviceShaderCoreBuiltinsPropertiesARM_null();
		init.shaderCoreMask = shaderCoreMask;
		init.shaderCoreCount = shaderCoreCount;
		init.shaderWarpsPerCore = shaderWarpsPerCore;
		return init;
	}

	static inline VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT vkiPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT_null()
	{
		VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT vkiPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(VkBool32 pipelineLibraryGroupHandles)
	{
		VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT init = vkiPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT_null();
		init.pipelineLibraryGroupHandles = pipelineLibraryGroupHandles;
		return init;
	}

	static inline VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT vkiPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT_null()
	{
		VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT vkiPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(VkBool32 dynamicRenderingUnusedAttachments)
	{
		VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT init = vkiPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT_null();
		init.dynamicRenderingUnusedAttachments = dynamicRenderingUnusedAttachments;
		return init;
	}

	static inline VkLatencySleepModeInfoNV vkiLatencySleepModeInfoNV_null()
	{
		VkLatencySleepModeInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV;
		return init;
	}

	static inline VkLatencySleepModeInfoNV vkiLatencySleepModeInfoNV(VkBool32 lowLatencyMode, VkBool32 lowLatencyBoost, uint32_t minimumIntervalUs)
	{
		VkLatencySleepModeInfoNV init = vkiLatencySleepModeInfoNV_null();
		init.lowLatencyMode = lowLatencyMode;
		init.lowLatencyBoost = lowLatencyBoost;
		init.minimumIntervalUs = minimumIntervalUs;
		return init;
	}

	static inline VkLatencySleepInfoNV vkiLatencySleepInfoNV_null()
	{
		VkLatencySleepInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV;
		return init;
	}

	static inline VkLatencySleepInfoNV vkiLatencySleepInfoNV(VkSemaphore signalSemaphore, uint64_t value)
	{
		VkLatencySleepInfoNV init = vkiLatencySleepInfoNV_null();
		init.signalSemaphore = signalSemaphore;
		init.value = value;
		return init;
	}

	static inline VkSetLatencyMarkerInfoNV vkiSetLatencyMarkerInfoNV_null()
	{
		VkSetLatencyMarkerInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV;
		return init;
	}

	static inline VkSetLatencyMarkerInfoNV vkiSetLatencyMarkerInfoNV(uint64_t presentID, VkLatencyMarkerNV marker)
	{
		VkSetLatencyMarkerInfoNV init = vkiSetLatencyMarkerInfoNV_null();
		init.presentID = presentID;
		init.marker = marker;
		return init;
	}

	static inline VkLatencyTimingsFrameReportNV vkiLatencyTimingsFrameReportNV_null()
	{
		VkLatencyTimingsFrameReportNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV;
		return init;
	}

	static inline VkLatencyTimingsFrameReportNV vkiLatencyTimingsFrameReportNV(uint64_t presentID, uint64_t inputSampleTimeUs, uint64_t simStartTimeUs, uint64_t simEndTimeUs, uint64_t renderSubmitStartTimeUs, uint64_t renderSubmitEndTimeUs, uint64_t presentStartTimeUs, uint64_t presentEndTimeUs, uint64_t driverStartTimeUs, uint64_t driverEndTimeUs, uint64_t osRenderQueueStartTimeUs, uint64_t osRenderQueueEndTimeUs, uint64_t gpuRenderStartTimeUs, uint64_t gpuRenderEndTimeUs)
	{
		VkLatencyTimingsFrameReportNV init = vkiLatencyTimingsFrameReportNV_null();
		init.presentID = presentID;
		init.inputSampleTimeUs = inputSampleTimeUs;
		init.simStartTimeUs = simStartTimeUs;
		init.simEndTimeUs = simEndTimeUs;
		init.renderSubmitStartTimeUs = renderSubmitStartTimeUs;
		init.renderSubmitEndTimeUs = renderSubmitEndTimeUs;
		init.presentStartTimeUs = presentStartTimeUs;
		init.presentEndTimeUs = presentEndTimeUs;
		init.driverStartTimeUs = driverStartTimeUs;
		init.driverEndTimeUs = driverEndTimeUs;
		init.osRenderQueueStartTimeUs = osRenderQueueStartTimeUs;
		init.osRenderQueueEndTimeUs = osRenderQueueEndTimeUs;
		init.gpuRenderStartTimeUs = gpuRenderStartTimeUs;
		init.gpuRenderEndTimeUs = gpuRenderEndTimeUs;
		return init;
	}

	static inline VkGetLatencyMarkerInfoNV vkiGetLatencyMarkerInfoNV_null()
	{
		VkGetLatencyMarkerInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV;
		return init;
	}

	static inline VkGetLatencyMarkerInfoNV vkiGetLatencyMarkerInfoNV(uint32_t timingCount, VkLatencyTimingsFrameReportNV *pTimings)
	{
		VkGetLatencyMarkerInfoNV init = vkiGetLatencyMarkerInfoNV_null();
		init.timingCount = timingCount;
		init.pTimings = pTimings;
		return init;
	}

	static inline VkLatencySubmissionPresentIdNV vkiLatencySubmissionPresentIdNV_null()
	{
		VkLatencySubmissionPresentIdNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV;
		return init;
	}

	static inline VkLatencySubmissionPresentIdNV vkiLatencySubmissionPresentIdNV(uint64_t presentID)
	{
		VkLatencySubmissionPresentIdNV init = vkiLatencySubmissionPresentIdNV_null();
		init.presentID = presentID;
		return init;
	}

	static inline VkSwapchainLatencyCreateInfoNV vkiSwapchainLatencyCreateInfoNV_null()
	{
		VkSwapchainLatencyCreateInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV;
		return init;
	}

	static inline VkSwapchainLatencyCreateInfoNV vkiSwapchainLatencyCreateInfoNV(VkBool32 latencyModeEnable)
	{
		VkSwapchainLatencyCreateInfoNV init = vkiSwapchainLatencyCreateInfoNV_null();
		init.latencyModeEnable = latencyModeEnable;
		return init;
	}

	static inline VkOutOfBandQueueTypeInfoNV vkiOutOfBandQueueTypeInfoNV_null()
	{
		VkOutOfBandQueueTypeInfoNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV;
		return init;
	}

	static inline VkOutOfBandQueueTypeInfoNV vkiOutOfBandQueueTypeInfoNV(VkOutOfBandQueueTypeNV queueType)
	{
		VkOutOfBandQueueTypeInfoNV init = vkiOutOfBandQueueTypeInfoNV_null();
		init.queueType = queueType;
		return init;
	}

	static inline VkLatencySurfaceCapabilitiesNV vkiLatencySurfaceCapabilitiesNV_null()
	{
		VkLatencySurfaceCapabilitiesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV;
		return init;
	}

	static inline VkLatencySurfaceCapabilitiesNV vkiLatencySurfaceCapabilitiesNV(uint32_t presentModeCount, VkPresentModeKHR *pPresentModes)
	{
		VkLatencySurfaceCapabilitiesNV init = vkiLatencySurfaceCapabilitiesNV_null();
		init.presentModeCount = presentModeCount;
		init.pPresentModes = pPresentModes;
		return init;
	}

	static inline VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM vkiPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM_null()
	{
		VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM;
		return init;
	}

	static inline VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM vkiPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(VkBool32 multiviewPerViewRenderAreas)
	{
		VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM init = vkiPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM_null();
		init.multiviewPerViewRenderAreas = multiviewPerViewRenderAreas;
		return init;
	}

	static inline VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM vkiMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM_null()
	{
		VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM;
		return init;
	}

	static inline VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM vkiMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM(uint32_t perViewRenderAreaCount, const VkRect2D *pPerViewRenderAreas)
	{
		VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM init = vkiMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM_null();
		init.perViewRenderAreaCount = perViewRenderAreaCount;
		init.pPerViewRenderAreas = pPerViewRenderAreas;
		return init;
	}

	static inline VkPhysicalDevicePerStageDescriptorSetFeaturesNV vkiPhysicalDevicePerStageDescriptorSetFeaturesNV_null()
	{
		VkPhysicalDevicePerStageDescriptorSetFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDevicePerStageDescriptorSetFeaturesNV vkiPhysicalDevicePerStageDescriptorSetFeaturesNV(VkBool32 perStageDescriptorSet, VkBool32 dynamicPipelineLayout)
	{
		VkPhysicalDevicePerStageDescriptorSetFeaturesNV init = vkiPhysicalDevicePerStageDescriptorSetFeaturesNV_null();
		init.perStageDescriptorSet = perStageDescriptorSet;
		init.dynamicPipelineLayout = dynamicPipelineLayout;
		return init;
	}

	static inline VkPhysicalDeviceImageProcessing2FeaturesQCOM vkiPhysicalDeviceImageProcessing2FeaturesQCOM_null()
	{
		VkPhysicalDeviceImageProcessing2FeaturesQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM;
		return init;
	}

	static inline VkPhysicalDeviceImageProcessing2FeaturesQCOM vkiPhysicalDeviceImageProcessing2FeaturesQCOM(VkBool32 textureBlockMatch2)
	{
		VkPhysicalDeviceImageProcessing2FeaturesQCOM init = vkiPhysicalDeviceImageProcessing2FeaturesQCOM_null();
		init.textureBlockMatch2 = textureBlockMatch2;
		return init;
	}

	static inline VkPhysicalDeviceImageProcessing2PropertiesQCOM vkiPhysicalDeviceImageProcessing2PropertiesQCOM_null()
	{
		VkPhysicalDeviceImageProcessing2PropertiesQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM;
		return init;
	}

	static inline VkPhysicalDeviceImageProcessing2PropertiesQCOM vkiPhysicalDeviceImageProcessing2PropertiesQCOM(VkExtent2D maxBlockMatchWindow)
	{
		VkPhysicalDeviceImageProcessing2PropertiesQCOM init = vkiPhysicalDeviceImageProcessing2PropertiesQCOM_null();
		init.maxBlockMatchWindow = maxBlockMatchWindow;
		return init;
	}

	static inline VkSamplerBlockMatchWindowCreateInfoQCOM vkiSamplerBlockMatchWindowCreateInfoQCOM_null()
	{
		VkSamplerBlockMatchWindowCreateInfoQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM;
		return init;
	}

	static inline VkSamplerBlockMatchWindowCreateInfoQCOM vkiSamplerBlockMatchWindowCreateInfoQCOM(VkExtent2D windowExtent, VkBlockMatchWindowCompareModeQCOM windowCompareMode)
	{
		VkSamplerBlockMatchWindowCreateInfoQCOM init = vkiSamplerBlockMatchWindowCreateInfoQCOM_null();
		init.windowExtent = windowExtent;
		init.windowCompareMode = windowCompareMode;
		return init;
	}

	static inline VkPhysicalDeviceCubicWeightsFeaturesQCOM vkiPhysicalDeviceCubicWeightsFeaturesQCOM_null()
	{
		VkPhysicalDeviceCubicWeightsFeaturesQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM;
		return init;
	}

	static inline VkPhysicalDeviceCubicWeightsFeaturesQCOM vkiPhysicalDeviceCubicWeightsFeaturesQCOM(VkBool32 selectableCubicWeights)
	{
		VkPhysicalDeviceCubicWeightsFeaturesQCOM init = vkiPhysicalDeviceCubicWeightsFeaturesQCOM_null();
		init.selectableCubicWeights = selectableCubicWeights;
		return init;
	}

	static inline VkSamplerCubicWeightsCreateInfoQCOM vkiSamplerCubicWeightsCreateInfoQCOM_null()
	{
		VkSamplerCubicWeightsCreateInfoQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM;
		return init;
	}

	static inline VkSamplerCubicWeightsCreateInfoQCOM vkiSamplerCubicWeightsCreateInfoQCOM(VkCubicFilterWeightsQCOM cubicWeights)
	{
		VkSamplerCubicWeightsCreateInfoQCOM init = vkiSamplerCubicWeightsCreateInfoQCOM_null();
		init.cubicWeights = cubicWeights;
		return init;
	}

	static inline VkBlitImageCubicWeightsInfoQCOM vkiBlitImageCubicWeightsInfoQCOM_null()
	{
		VkBlitImageCubicWeightsInfoQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM;
		return init;
	}

	static inline VkBlitImageCubicWeightsInfoQCOM vkiBlitImageCubicWeightsInfoQCOM(VkCubicFilterWeightsQCOM cubicWeights)
	{
		VkBlitImageCubicWeightsInfoQCOM init = vkiBlitImageCubicWeightsInfoQCOM_null();
		init.cubicWeights = cubicWeights;
		return init;
	}

	static inline VkPhysicalDeviceYcbcrDegammaFeaturesQCOM vkiPhysicalDeviceYcbcrDegammaFeaturesQCOM_null()
	{
		VkPhysicalDeviceYcbcrDegammaFeaturesQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM;
		return init;
	}

	static inline VkPhysicalDeviceYcbcrDegammaFeaturesQCOM vkiPhysicalDeviceYcbcrDegammaFeaturesQCOM(VkBool32 ycbcrDegamma)
	{
		VkPhysicalDeviceYcbcrDegammaFeaturesQCOM init = vkiPhysicalDeviceYcbcrDegammaFeaturesQCOM_null();
		init.ycbcrDegamma = ycbcrDegamma;
		return init;
	}

	static inline VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM vkiSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM_null()
	{
		VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM;
		return init;
	}

	static inline VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM vkiSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM(VkBool32 enableYDegamma, VkBool32 enableCbCrDegamma)
	{
		VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM init = vkiSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM_null();
		init.enableYDegamma = enableYDegamma;
		init.enableCbCrDegamma = enableCbCrDegamma;
		return init;
	}

	static inline VkPhysicalDeviceCubicClampFeaturesQCOM vkiPhysicalDeviceCubicClampFeaturesQCOM_null()
	{
		VkPhysicalDeviceCubicClampFeaturesQCOM init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM;
		return init;
	}

	static inline VkPhysicalDeviceCubicClampFeaturesQCOM vkiPhysicalDeviceCubicClampFeaturesQCOM(VkBool32 cubicRangeClamp)
	{
		VkPhysicalDeviceCubicClampFeaturesQCOM init = vkiPhysicalDeviceCubicClampFeaturesQCOM_null();
		init.cubicRangeClamp = cubicRangeClamp;
		return init;
	}

	static inline VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT vkiPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT_null()
	{
		VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT vkiPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(VkBool32 attachmentFeedbackLoopDynamicState)
	{
		VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT init = vkiPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT_null();
		init.attachmentFeedbackLoopDynamicState = attachmentFeedbackLoopDynamicState;
		return init;
	}

	static inline VkPhysicalDeviceLayeredDriverPropertiesMSFT vkiPhysicalDeviceLayeredDriverPropertiesMSFT_null()
	{
		VkPhysicalDeviceLayeredDriverPropertiesMSFT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT;
		return init;
	}

	static inline VkPhysicalDeviceLayeredDriverPropertiesMSFT vkiPhysicalDeviceLayeredDriverPropertiesMSFT(VkLayeredDriverUnderlyingApiMSFT underlyingAPI)
	{
		VkPhysicalDeviceLayeredDriverPropertiesMSFT init = vkiPhysicalDeviceLayeredDriverPropertiesMSFT_null();
		init.underlyingAPI = underlyingAPI;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV vkiPhysicalDeviceDescriptorPoolOverallocationFeaturesNV_null()
	{
		VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV vkiPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(VkBool32 descriptorPoolOverallocation)
	{
		VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV init = vkiPhysicalDeviceDescriptorPoolOverallocationFeaturesNV_null();
		init.descriptorPoolOverallocation = descriptorPoolOverallocation;
		return init;
	}

	static inline VkPhysicalDeviceRawAccessChainsFeaturesNV vkiPhysicalDeviceRawAccessChainsFeaturesNV_null()
	{
		VkPhysicalDeviceRawAccessChainsFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceRawAccessChainsFeaturesNV vkiPhysicalDeviceRawAccessChainsFeaturesNV(VkBool32 shaderRawAccessChains)
	{
		VkPhysicalDeviceRawAccessChainsFeaturesNV init = vkiPhysicalDeviceRawAccessChainsFeaturesNV_null();
		init.shaderRawAccessChains = shaderRawAccessChains;
		return init;
	}

	static inline VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV vkiPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV_null()
	{
		VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV vkiPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV(VkBool32 shaderFloat16VectorAtomics)
	{
		VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV init = vkiPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV_null();
		init.shaderFloat16VectorAtomics = shaderFloat16VectorAtomics;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingValidationFeaturesNV vkiPhysicalDeviceRayTracingValidationFeaturesNV_null()
	{
		VkPhysicalDeviceRayTracingValidationFeaturesNV init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingValidationFeaturesNV vkiPhysicalDeviceRayTracingValidationFeaturesNV(VkBool32 rayTracingValidation)
	{
		VkPhysicalDeviceRayTracingValidationFeaturesNV init = vkiPhysicalDeviceRayTracingValidationFeaturesNV_null();
		init.rayTracingValidation = rayTracingValidation;
		return init;
	}

	static inline VkAccelerationStructureBuildRangeInfoKHR vkiAccelerationStructureBuildRangeInfoKHR_null()
	{
		VkAccelerationStructureBuildRangeInfoKHR init = {0};
		return init;
	}

	static inline VkAccelerationStructureBuildRangeInfoKHR vkiAccelerationStructureBuildRangeInfoKHR(uint32_t primitiveCount, uint32_t primitiveOffset, uint32_t firstVertex, uint32_t transformOffset)
	{
		VkAccelerationStructureBuildRangeInfoKHR init = vkiAccelerationStructureBuildRangeInfoKHR_null();
		init.primitiveCount = primitiveCount;
		init.primitiveOffset = primitiveOffset;
		init.firstVertex = firstVertex;
		init.transformOffset = transformOffset;
		return init;
	}

	static inline VkAccelerationStructureGeometryTrianglesDataKHR vkiAccelerationStructureGeometryTrianglesDataKHR_null()
	{
		VkAccelerationStructureGeometryTrianglesDataKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR;
		return init;
	}

	static inline VkAccelerationStructureGeometryTrianglesDataKHR vkiAccelerationStructureGeometryTrianglesDataKHR(VkFormat vertexFormat, VkDeviceOrHostAddressConstKHR vertexData, VkDeviceSize vertexStride, uint32_t maxVertex, VkIndexType indexType, VkDeviceOrHostAddressConstKHR indexData, VkDeviceOrHostAddressConstKHR transformData)
	{
		VkAccelerationStructureGeometryTrianglesDataKHR init = vkiAccelerationStructureGeometryTrianglesDataKHR_null();
		init.vertexFormat = vertexFormat;
		init.vertexData = vertexData;
		init.vertexStride = vertexStride;
		init.maxVertex = maxVertex;
		init.indexType = indexType;
		init.indexData = indexData;
		init.transformData = transformData;
		return init;
	}

	static inline VkAccelerationStructureGeometryAabbsDataKHR vkiAccelerationStructureGeometryAabbsDataKHR_null()
	{
		VkAccelerationStructureGeometryAabbsDataKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR;
		return init;
	}

	static inline VkAccelerationStructureGeometryAabbsDataKHR vkiAccelerationStructureGeometryAabbsDataKHR(VkDeviceOrHostAddressConstKHR data, VkDeviceSize stride)
	{
		VkAccelerationStructureGeometryAabbsDataKHR init = vkiAccelerationStructureGeometryAabbsDataKHR_null();
		init.data = data;
		init.stride = stride;
		return init;
	}

	static inline VkAccelerationStructureGeometryInstancesDataKHR vkiAccelerationStructureGeometryInstancesDataKHR_null()
	{
		VkAccelerationStructureGeometryInstancesDataKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR;
		return init;
	}

	static inline VkAccelerationStructureGeometryInstancesDataKHR vkiAccelerationStructureGeometryInstancesDataKHR(VkBool32 arrayOfPointers, VkDeviceOrHostAddressConstKHR data)
	{
		VkAccelerationStructureGeometryInstancesDataKHR init = vkiAccelerationStructureGeometryInstancesDataKHR_null();
		init.arrayOfPointers = arrayOfPointers;
		init.data = data;
		return init;
	}

	static inline VkAccelerationStructureGeometryKHR vkiAccelerationStructureGeometryKHR_null()
	{
		VkAccelerationStructureGeometryKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR;
		return init;
	}

	static inline VkAccelerationStructureGeometryKHR vkiAccelerationStructureGeometryKHR(VkGeometryTypeKHR geometryType, VkAccelerationStructureGeometryDataKHR geometry)
	{
		VkAccelerationStructureGeometryKHR init = vkiAccelerationStructureGeometryKHR_null();
		init.geometryType = geometryType;
		init.geometry = geometry;
		return init;
	}

	static inline VkAccelerationStructureBuildGeometryInfoKHR vkiAccelerationStructureBuildGeometryInfoKHR_null()
	{
		VkAccelerationStructureBuildGeometryInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR;
		return init;
	}

	static inline VkAccelerationStructureBuildGeometryInfoKHR vkiAccelerationStructureBuildGeometryInfoKHR(VkAccelerationStructureTypeKHR type, VkBuildAccelerationStructureModeKHR mode, VkAccelerationStructureKHR srcAccelerationStructure, VkAccelerationStructureKHR dstAccelerationStructure, uint32_t geometryCount, const VkAccelerationStructureGeometryKHR *pGeometries, const VkAccelerationStructureGeometryKHR *const *ppGeometries, VkDeviceOrHostAddressKHR scratchData)
	{
		VkAccelerationStructureBuildGeometryInfoKHR init = vkiAccelerationStructureBuildGeometryInfoKHR_null();
		init.type = type;
		init.mode = mode;
		init.srcAccelerationStructure = srcAccelerationStructure;
		init.dstAccelerationStructure = dstAccelerationStructure;
		init.geometryCount = geometryCount;
		init.pGeometries = pGeometries;
		init.ppGeometries = ppGeometries;
		init.scratchData = scratchData;
		return init;
	}

	static inline VkAccelerationStructureCreateInfoKHR vkiAccelerationStructureCreateInfoKHR_null()
	{
		VkAccelerationStructureCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR;
		return init;
	}

	static inline VkAccelerationStructureCreateInfoKHR vkiAccelerationStructureCreateInfoKHR(VkAccelerationStructureCreateFlagsKHR createFlags, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkAccelerationStructureTypeKHR type, VkDeviceAddress deviceAddress)
	{
		VkAccelerationStructureCreateInfoKHR init = vkiAccelerationStructureCreateInfoKHR_null();
		init.createFlags = createFlags;
		init.buffer = buffer;
		init.offset = offset;
		init.size = size;
		init.type = type;
		init.deviceAddress = deviceAddress;
		return init;
	}

	static inline VkWriteDescriptorSetAccelerationStructureKHR vkiWriteDescriptorSetAccelerationStructureKHR_null()
	{
		VkWriteDescriptorSetAccelerationStructureKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR;
		return init;
	}

	static inline VkWriteDescriptorSetAccelerationStructureKHR vkiWriteDescriptorSetAccelerationStructureKHR(uint32_t accelerationStructureCount, const VkAccelerationStructureKHR *pAccelerationStructures)
	{
		VkWriteDescriptorSetAccelerationStructureKHR init = vkiWriteDescriptorSetAccelerationStructureKHR_null();
		init.accelerationStructureCount = accelerationStructureCount;
		init.pAccelerationStructures = pAccelerationStructures;
		return init;
	}

	static inline VkPhysicalDeviceAccelerationStructureFeaturesKHR vkiPhysicalDeviceAccelerationStructureFeaturesKHR_null()
	{
		VkPhysicalDeviceAccelerationStructureFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceAccelerationStructureFeaturesKHR vkiPhysicalDeviceAccelerationStructureFeaturesKHR(VkBool32 accelerationStructure, VkBool32 accelerationStructureCaptureReplay, VkBool32 accelerationStructureIndirectBuild, VkBool32 accelerationStructureHostCommands, VkBool32 descriptorBindingAccelerationStructureUpdateAfterBind)
	{
		VkPhysicalDeviceAccelerationStructureFeaturesKHR init = vkiPhysicalDeviceAccelerationStructureFeaturesKHR_null();
		init.accelerationStructure = accelerationStructure;
		init.accelerationStructureCaptureReplay = accelerationStructureCaptureReplay;
		init.accelerationStructureIndirectBuild = accelerationStructureIndirectBuild;
		init.accelerationStructureHostCommands = accelerationStructureHostCommands;
		init.descriptorBindingAccelerationStructureUpdateAfterBind = descriptorBindingAccelerationStructureUpdateAfterBind;
		return init;
	}

	static inline VkPhysicalDeviceAccelerationStructurePropertiesKHR vkiPhysicalDeviceAccelerationStructurePropertiesKHR_null()
	{
		VkPhysicalDeviceAccelerationStructurePropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceAccelerationStructurePropertiesKHR vkiPhysicalDeviceAccelerationStructurePropertiesKHR(uint64_t maxGeometryCount, uint64_t maxInstanceCount, uint64_t maxPrimitiveCount, uint32_t maxPerStageDescriptorAccelerationStructures, uint32_t maxPerStageDescriptorUpdateAfterBindAccelerationStructures, uint32_t maxDescriptorSetAccelerationStructures, uint32_t maxDescriptorSetUpdateAfterBindAccelerationStructures, uint32_t minAccelerationStructureScratchOffsetAlignment)
	{
		VkPhysicalDeviceAccelerationStructurePropertiesKHR init = vkiPhysicalDeviceAccelerationStructurePropertiesKHR_null();
		init.maxGeometryCount = maxGeometryCount;
		init.maxInstanceCount = maxInstanceCount;
		init.maxPrimitiveCount = maxPrimitiveCount;
		init.maxPerStageDescriptorAccelerationStructures = maxPerStageDescriptorAccelerationStructures;
		init.maxPerStageDescriptorUpdateAfterBindAccelerationStructures = maxPerStageDescriptorUpdateAfterBindAccelerationStructures;
		init.maxDescriptorSetAccelerationStructures = maxDescriptorSetAccelerationStructures;
		init.maxDescriptorSetUpdateAfterBindAccelerationStructures = maxDescriptorSetUpdateAfterBindAccelerationStructures;
		init.minAccelerationStructureScratchOffsetAlignment = minAccelerationStructureScratchOffsetAlignment;
		return init;
	}

	static inline VkAccelerationStructureDeviceAddressInfoKHR vkiAccelerationStructureDeviceAddressInfoKHR_null()
	{
		VkAccelerationStructureDeviceAddressInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR;
		return init;
	}

	static inline VkAccelerationStructureDeviceAddressInfoKHR vkiAccelerationStructureDeviceAddressInfoKHR(VkAccelerationStructureKHR accelerationStructure)
	{
		VkAccelerationStructureDeviceAddressInfoKHR init = vkiAccelerationStructureDeviceAddressInfoKHR_null();
		init.accelerationStructure = accelerationStructure;
		return init;
	}

	static inline VkAccelerationStructureVersionInfoKHR vkiAccelerationStructureVersionInfoKHR_null()
	{
		VkAccelerationStructureVersionInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR;
		return init;
	}

	static inline VkAccelerationStructureVersionInfoKHR vkiAccelerationStructureVersionInfoKHR(const uint8_t *pVersionData)
	{
		VkAccelerationStructureVersionInfoKHR init = vkiAccelerationStructureVersionInfoKHR_null();
		init.pVersionData = pVersionData;
		return init;
	}

	static inline VkCopyAccelerationStructureToMemoryInfoKHR vkiCopyAccelerationStructureToMemoryInfoKHR_null()
	{
		VkCopyAccelerationStructureToMemoryInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR;
		return init;
	}

	static inline VkCopyAccelerationStructureToMemoryInfoKHR vkiCopyAccelerationStructureToMemoryInfoKHR(VkAccelerationStructureKHR src, VkDeviceOrHostAddressKHR dst, VkCopyAccelerationStructureModeKHR mode)
	{
		VkCopyAccelerationStructureToMemoryInfoKHR init = vkiCopyAccelerationStructureToMemoryInfoKHR_null();
		init.src = src;
		init.dst = dst;
		init.mode = mode;
		return init;
	}

	static inline VkCopyMemoryToAccelerationStructureInfoKHR vkiCopyMemoryToAccelerationStructureInfoKHR_null()
	{
		VkCopyMemoryToAccelerationStructureInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR;
		return init;
	}

	static inline VkCopyMemoryToAccelerationStructureInfoKHR vkiCopyMemoryToAccelerationStructureInfoKHR(VkDeviceOrHostAddressConstKHR src, VkAccelerationStructureKHR dst, VkCopyAccelerationStructureModeKHR mode)
	{
		VkCopyMemoryToAccelerationStructureInfoKHR init = vkiCopyMemoryToAccelerationStructureInfoKHR_null();
		init.src = src;
		init.dst = dst;
		init.mode = mode;
		return init;
	}

	static inline VkCopyAccelerationStructureInfoKHR vkiCopyAccelerationStructureInfoKHR_null()
	{
		VkCopyAccelerationStructureInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR;
		return init;
	}

	static inline VkCopyAccelerationStructureInfoKHR vkiCopyAccelerationStructureInfoKHR(VkAccelerationStructureKHR src, VkAccelerationStructureKHR dst, VkCopyAccelerationStructureModeKHR mode)
	{
		VkCopyAccelerationStructureInfoKHR init = vkiCopyAccelerationStructureInfoKHR_null();
		init.src = src;
		init.dst = dst;
		init.mode = mode;
		return init;
	}

	static inline VkAccelerationStructureBuildSizesInfoKHR vkiAccelerationStructureBuildSizesInfoKHR_null()
	{
		VkAccelerationStructureBuildSizesInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR;
		return init;
	}

	static inline VkAccelerationStructureBuildSizesInfoKHR vkiAccelerationStructureBuildSizesInfoKHR(VkDeviceSize accelerationStructureSize, VkDeviceSize updateScratchSize, VkDeviceSize buildScratchSize)
	{
		VkAccelerationStructureBuildSizesInfoKHR init = vkiAccelerationStructureBuildSizesInfoKHR_null();
		init.accelerationStructureSize = accelerationStructureSize;
		init.updateScratchSize = updateScratchSize;
		init.buildScratchSize = buildScratchSize;
		return init;
	}

	static inline VkRayTracingShaderGroupCreateInfoKHR vkiRayTracingShaderGroupCreateInfoKHR_null()
	{
		VkRayTracingShaderGroupCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR;
		return init;
	}

	static inline VkRayTracingShaderGroupCreateInfoKHR vkiRayTracingShaderGroupCreateInfoKHR(VkRayTracingShaderGroupTypeKHR type, uint32_t generalShader, uint32_t closestHitShader, uint32_t anyHitShader, uint32_t intersectionShader, const void *pShaderGroupCaptureReplayHandle)
	{
		VkRayTracingShaderGroupCreateInfoKHR init = vkiRayTracingShaderGroupCreateInfoKHR_null();
		init.type = type;
		init.generalShader = generalShader;
		init.closestHitShader = closestHitShader;
		init.anyHitShader = anyHitShader;
		init.intersectionShader = intersectionShader;
		init.pShaderGroupCaptureReplayHandle = pShaderGroupCaptureReplayHandle;
		return init;
	}

	static inline VkRayTracingPipelineInterfaceCreateInfoKHR vkiRayTracingPipelineInterfaceCreateInfoKHR_null()
	{
		VkRayTracingPipelineInterfaceCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR;
		return init;
	}

	static inline VkRayTracingPipelineInterfaceCreateInfoKHR vkiRayTracingPipelineInterfaceCreateInfoKHR(uint32_t maxPipelineRayPayloadSize, uint32_t maxPipelineRayHitAttributeSize)
	{
		VkRayTracingPipelineInterfaceCreateInfoKHR init = vkiRayTracingPipelineInterfaceCreateInfoKHR_null();
		init.maxPipelineRayPayloadSize = maxPipelineRayPayloadSize;
		init.maxPipelineRayHitAttributeSize = maxPipelineRayHitAttributeSize;
		return init;
	}

	static inline VkRayTracingPipelineCreateInfoKHR vkiRayTracingPipelineCreateInfoKHR_null()
	{
		VkRayTracingPipelineCreateInfoKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR;
		return init;
	}

	static inline VkRayTracingPipelineCreateInfoKHR vkiRayTracingPipelineCreateInfoKHR(uint32_t stageCount, const VkPipelineShaderStageCreateInfo *pStages, uint32_t groupCount, const VkRayTracingShaderGroupCreateInfoKHR *pGroups, uint32_t maxPipelineRayRecursionDepth, const VkPipelineLibraryCreateInfoKHR *pLibraryInfo, const VkRayTracingPipelineInterfaceCreateInfoKHR *pLibraryInterface, const VkPipelineDynamicStateCreateInfo *pDynamicState, VkPipelineLayout layout, VkPipeline basePipelineHandle, int32_t basePipelineIndex)
	{
		VkRayTracingPipelineCreateInfoKHR init = vkiRayTracingPipelineCreateInfoKHR_null();
		init.stageCount = stageCount;
		init.pStages = pStages;
		init.groupCount = groupCount;
		init.pGroups = pGroups;
		init.maxPipelineRayRecursionDepth = maxPipelineRayRecursionDepth;
		init.pLibraryInfo = pLibraryInfo;
		init.pLibraryInterface = pLibraryInterface;
		init.pDynamicState = pDynamicState;
		init.layout = layout;
		init.basePipelineHandle = basePipelineHandle;
		init.basePipelineIndex = basePipelineIndex;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingPipelineFeaturesKHR vkiPhysicalDeviceRayTracingPipelineFeaturesKHR_null()
	{
		VkPhysicalDeviceRayTracingPipelineFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingPipelineFeaturesKHR vkiPhysicalDeviceRayTracingPipelineFeaturesKHR(VkBool32 rayTracingPipeline, VkBool32 rayTracingPipelineShaderGroupHandleCaptureReplay, VkBool32 rayTracingPipelineShaderGroupHandleCaptureReplayMixed, VkBool32 rayTracingPipelineTraceRaysIndirect, VkBool32 rayTraversalPrimitiveCulling)
	{
		VkPhysicalDeviceRayTracingPipelineFeaturesKHR init = vkiPhysicalDeviceRayTracingPipelineFeaturesKHR_null();
		init.rayTracingPipeline = rayTracingPipeline;
		init.rayTracingPipelineShaderGroupHandleCaptureReplay = rayTracingPipelineShaderGroupHandleCaptureReplay;
		init.rayTracingPipelineShaderGroupHandleCaptureReplayMixed = rayTracingPipelineShaderGroupHandleCaptureReplayMixed;
		init.rayTracingPipelineTraceRaysIndirect = rayTracingPipelineTraceRaysIndirect;
		init.rayTraversalPrimitiveCulling = rayTraversalPrimitiveCulling;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingPipelinePropertiesKHR vkiPhysicalDeviceRayTracingPipelinePropertiesKHR_null()
	{
		VkPhysicalDeviceRayTracingPipelinePropertiesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceRayTracingPipelinePropertiesKHR vkiPhysicalDeviceRayTracingPipelinePropertiesKHR(uint32_t shaderGroupHandleSize, uint32_t maxRayRecursionDepth, uint32_t maxShaderGroupStride, uint32_t shaderGroupBaseAlignment, uint32_t shaderGroupHandleCaptureReplaySize, uint32_t maxRayDispatchInvocationCount, uint32_t shaderGroupHandleAlignment, uint32_t maxRayHitAttributeSize)
	{
		VkPhysicalDeviceRayTracingPipelinePropertiesKHR init = vkiPhysicalDeviceRayTracingPipelinePropertiesKHR_null();
		init.shaderGroupHandleSize = shaderGroupHandleSize;
		init.maxRayRecursionDepth = maxRayRecursionDepth;
		init.maxShaderGroupStride = maxShaderGroupStride;
		init.shaderGroupBaseAlignment = shaderGroupBaseAlignment;
		init.shaderGroupHandleCaptureReplaySize = shaderGroupHandleCaptureReplaySize;
		init.maxRayDispatchInvocationCount = maxRayDispatchInvocationCount;
		init.shaderGroupHandleAlignment = shaderGroupHandleAlignment;
		init.maxRayHitAttributeSize = maxRayHitAttributeSize;
		return init;
	}

	static inline VkStridedDeviceAddressRegionKHR vkiStridedDeviceAddressRegionKHR_null()
	{
		VkStridedDeviceAddressRegionKHR init = {0};
		return init;
	}

	static inline VkStridedDeviceAddressRegionKHR vkiStridedDeviceAddressRegionKHR(VkDeviceAddress deviceAddress, VkDeviceSize stride, VkDeviceSize size)
	{
		VkStridedDeviceAddressRegionKHR init = vkiStridedDeviceAddressRegionKHR_null();
		init.deviceAddress = deviceAddress;
		init.stride = stride;
		init.size = size;
		return init;
	}

	static inline VkTraceRaysIndirectCommandKHR vkiTraceRaysIndirectCommandKHR_null()
	{
		VkTraceRaysIndirectCommandKHR init = {0};
		return init;
	}

	static inline VkTraceRaysIndirectCommandKHR vkiTraceRaysIndirectCommandKHR(uint32_t width, uint32_t height, uint32_t depth)
	{
		VkTraceRaysIndirectCommandKHR init = vkiTraceRaysIndirectCommandKHR_null();
		init.width = width;
		init.height = height;
		init.depth = depth;
		return init;
	}

	static inline VkPhysicalDeviceRayQueryFeaturesKHR vkiPhysicalDeviceRayQueryFeaturesKHR_null()
	{
		VkPhysicalDeviceRayQueryFeaturesKHR init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR;
		return init;
	}

	static inline VkPhysicalDeviceRayQueryFeaturesKHR vkiPhysicalDeviceRayQueryFeaturesKHR(VkBool32 rayQuery)
	{
		VkPhysicalDeviceRayQueryFeaturesKHR init = vkiPhysicalDeviceRayQueryFeaturesKHR_null();
		init.rayQuery = rayQuery;
		return init;
	}

	static inline VkPhysicalDeviceMeshShaderFeaturesEXT vkiPhysicalDeviceMeshShaderFeaturesEXT_null()
	{
		VkPhysicalDeviceMeshShaderFeaturesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceMeshShaderFeaturesEXT vkiPhysicalDeviceMeshShaderFeaturesEXT(VkBool32 taskShader, VkBool32 meshShader, VkBool32 multiviewMeshShader, VkBool32 primitiveFragmentShadingRateMeshShader, VkBool32 meshShaderQueries)
	{
		VkPhysicalDeviceMeshShaderFeaturesEXT init = vkiPhysicalDeviceMeshShaderFeaturesEXT_null();
		init.taskShader = taskShader;
		init.meshShader = meshShader;
		init.multiviewMeshShader = multiviewMeshShader;
		init.primitiveFragmentShadingRateMeshShader = primitiveFragmentShadingRateMeshShader;
		init.meshShaderQueries = meshShaderQueries;
		return init;
	}

	static inline VkPhysicalDeviceMeshShaderPropertiesEXT vkiPhysicalDeviceMeshShaderPropertiesEXT_null()
	{
		VkPhysicalDeviceMeshShaderPropertiesEXT init = {0};
		init.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT;
		return init;
	}

	static inline VkPhysicalDeviceMeshShaderPropertiesEXT vkiPhysicalDeviceMeshShaderPropertiesEXT(uint32_t maxTaskWorkGroupTotalCount, uint32_t maxTaskWorkGroupInvocations, uint32_t maxTaskPayloadSize, uint32_t maxTaskSharedMemorySize, uint32_t maxTaskPayloadAndSharedMemorySize, uint32_t maxMeshWorkGroupTotalCount, uint32_t maxMeshWorkGroupInvocations, uint32_t maxMeshSharedMemorySize, uint32_t maxMeshPayloadAndSharedMemorySize, uint32_t maxMeshOutputMemorySize, uint32_t maxMeshPayloadAndOutputMemorySize, uint32_t maxMeshOutputComponents, uint32_t maxMeshOutputVertices, uint32_t maxMeshOutputPrimitives, uint32_t maxMeshOutputLayers, uint32_t maxMeshMultiviewViewCount, uint32_t meshOutputPerVertexGranularity, uint32_t meshOutputPerPrimitiveGranularity, uint32_t maxPreferredTaskWorkGroupInvocations, uint32_t maxPreferredMeshWorkGroupInvocations, VkBool32 prefersLocalInvocationVertexOutput, VkBool32 prefersLocalInvocationPrimitiveOutput, VkBool32 prefersCompactVertexOutput, VkBool32 prefersCompactPrimitiveOutput)
	{
		VkPhysicalDeviceMeshShaderPropertiesEXT init = vkiPhysicalDeviceMeshShaderPropertiesEXT_null();
		init.maxTaskWorkGroupTotalCount = maxTaskWorkGroupTotalCount;
		init.maxTaskWorkGroupInvocations = maxTaskWorkGroupInvocations;
		init.maxTaskPayloadSize = maxTaskPayloadSize;
		init.maxTaskSharedMemorySize = maxTaskSharedMemorySize;
		init.maxTaskPayloadAndSharedMemorySize = maxTaskPayloadAndSharedMemorySize;
		init.maxMeshWorkGroupTotalCount = maxMeshWorkGroupTotalCount;
		init.maxMeshWorkGroupInvocations = maxMeshWorkGroupInvocations;
		init.maxMeshSharedMemorySize = maxMeshSharedMemorySize;
		init.maxMeshPayloadAndSharedMemorySize = maxMeshPayloadAndSharedMemorySize;
		init.maxMeshOutputMemorySize = maxMeshOutputMemorySize;
		init.maxMeshPayloadAndOutputMemorySize = maxMeshPayloadAndOutputMemorySize;
		init.maxMeshOutputComponents = maxMeshOutputComponents;
		init.maxMeshOutputVertices = maxMeshOutputVertices;
		init.maxMeshOutputPrimitives = maxMeshOutputPrimitives;
		init.maxMeshOutputLayers = maxMeshOutputLayers;
		init.maxMeshMultiviewViewCount = maxMeshMultiviewViewCount;
		init.meshOutputPerVertexGranularity = meshOutputPerVertexGranularity;
		init.meshOutputPerPrimitiveGranularity = meshOutputPerPrimitiveGranularity;
		init.maxPreferredTaskWorkGroupInvocations = maxPreferredTaskWorkGroupInvocations;
		init.maxPreferredMeshWorkGroupInvocations = maxPreferredMeshWorkGroupInvocations;
		init.prefersLocalInvocationVertexOutput = prefersLocalInvocationVertexOutput;
		init.prefersLocalInvocationPrimitiveOutput = prefersLocalInvocationPrimitiveOutput;
		init.prefersCompactVertexOutput = prefersCompactVertexOutput;
		init.prefersCompactPrimitiveOutput = prefersCompactPrimitiveOutput;
		return init;
	}

	static inline VkDrawMeshTasksIndirectCommandEXT vkiDrawMeshTasksIndirectCommandEXT_null()
	{
		VkDrawMeshTasksIndirectCommandEXT init = {0};
		return init;
	}

	static inline VkDrawMeshTasksIndirectCommandEXT vkiDrawMeshTasksIndirectCommandEXT(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ)
	{
		VkDrawMeshTasksIndirectCommandEXT init = vkiDrawMeshTasksIndirectCommandEXT_null();
		init.groupCountX = groupCountX;
		init.groupCountY = groupCountY;
		init.groupCountZ = groupCountZ;
		return init;
	}

#ifdef __cplusplus
}
#endif

#endif //__VKI_H__
