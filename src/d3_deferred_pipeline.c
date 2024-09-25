#include "common.h"

#include "ctools.h"
#include "log.h"
#include "shaders/forward.frag.c"
#include "shaders/forward.vert.c"
#include "shaders/offscreen.frag.c"
#include "shaders/offscreen.vert.c"

const size_t MAX_POINT_LIGHT = 10;

float data[4] = {0.7f, 0.5f, 0.2f, 0.05f};

struct
{
    float d[4];
} lights_count;

void pipeline_create_buffer_resources(struct ScPipeline *pipeline)
{
    size_t segment_count = 4;
    struct SubBufferSegmentInfo segment_infos[4];
    segment_infos[0].max_subbuffer = 1;
    segment_infos[0].subbuffer_size = sizeof(float) * 16;
    segment_infos[1].max_subbuffer = 1;
    segment_infos[1].subbuffer_size = sizeof(float) * 4;
    segment_infos[2].max_subbuffer = 1;
    segment_infos[2].subbuffer_size = sizeof(float) * 4;
    segment_infos[3].max_subbuffer = MAX_POINT_LIGHT;
    segment_infos[3].subbuffer_size = sizeof(float) * 4 * 3;
    pipeline->d3_deferred.sb_allocator = create_subbuffer_allocator(pipeline->automaton, AUTOMATON_QUEUE_TYPE_GRAPHICS, AUTOMATON_QUEUE_TYPE_GRAPHICS, VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, segment_count, segment_infos);
    pipeline->d3_deferred.sb_camera = allocate_subbuffer(&pipeline->d3_deferred.sb_allocator, 0);
    pipeline->d3_deferred.sb_ambient_light = allocate_subbuffer(&pipeline->d3_deferred.sb_allocator, 1);
    pipeline->d3_deferred.sb_light_count = allocate_subbuffer(&pipeline->d3_deferred.sb_allocator, 2);
    pipeline->d3_deferred.lights_count.d[0] = 1.0f;
    //pipeline->d3_deferred.lights_count.spot = 1.0f;
    //pipeline->d3_deferred.lights_count.sun = 1.0f;
    lights_count.d[0] = 1.0f;
    pipeline->d3_deferred.sb_light_count->data = lights_count.d;
    pipeline->d3_deferred.sb_light_count->updated = true;
}

void off_create_attachments(struct ScPipeline *pipeline)
{
    pipeline->d3_deferred.offscreen.position_res = automaton_create_image(pipeline->automaton, AUTOMATON_QUEUE_TYPE_GRAPHICS, pipeline->extent.width, pipeline->extent.height, 1, VK_FORMAT_R16G16B16A16_SFLOAT, VK_IMAGE_TYPE_2D, VK_IMAGE_VIEW_TYPE_2D, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_SAMPLED_BIT, VK_IMAGE_ASPECT_COLOR_BIT);
    pipeline->d3_deferred.offscreen.normal_res = automaton_create_image(pipeline->automaton, AUTOMATON_QUEUE_TYPE_GRAPHICS, pipeline->extent.width, pipeline->extent.height, 1, VK_FORMAT_R16G16B16A16_SFLOAT, VK_IMAGE_TYPE_2D, VK_IMAGE_VIEW_TYPE_2D, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_SAMPLED_BIT, VK_IMAGE_ASPECT_COLOR_BIT);
    pipeline->d3_deferred.offscreen.albedo_res = automaton_create_image(pipeline->automaton, AUTOMATON_QUEUE_TYPE_GRAPHICS, pipeline->extent.width, pipeline->extent.height, 1, VK_FORMAT_R8G8B8A8_UNORM, VK_IMAGE_TYPE_2D, VK_IMAGE_VIEW_TYPE_2D, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_SAMPLED_BIT, VK_IMAGE_ASPECT_COLOR_BIT);
    pipeline->d3_deferred.offscreen.depth_res = automaton_create_image(pipeline->automaton, AUTOMATON_QUEUE_TYPE_GRAPHICS, pipeline->extent.width, pipeline->extent.height, 1, pipeline->depth_format, VK_IMAGE_TYPE_2D, VK_IMAGE_VIEW_TYPE_2D, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT | VK_IMAGE_USAGE_SAMPLED_BIT, VK_IMAGE_ASPECT_DEPTH_BIT);
}

void off_create_render_pass(struct ScPipeline *pipeline)
{
    VkAttachmentDescription descs[] = {
        vkiAttachmentDescription(VK_FORMAT_R16G16B16A16_SFLOAT, VK_SAMPLE_COUNT_1_BIT, VK_ATTACHMENT_LOAD_OP_CLEAR, VK_ATTACHMENT_STORE_OP_STORE, VK_ATTACHMENT_LOAD_OP_DONT_CARE, VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL),
        vkiAttachmentDescription(VK_FORMAT_R16G16B16A16_SFLOAT, VK_SAMPLE_COUNT_1_BIT, VK_ATTACHMENT_LOAD_OP_CLEAR, VK_ATTACHMENT_STORE_OP_STORE, VK_ATTACHMENT_LOAD_OP_DONT_CARE, VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL),
        vkiAttachmentDescription(VK_FORMAT_R8G8B8A8_UNORM, VK_SAMPLE_COUNT_1_BIT, VK_ATTACHMENT_LOAD_OP_CLEAR, VK_ATTACHMENT_STORE_OP_STORE, VK_ATTACHMENT_LOAD_OP_DONT_CARE, VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL),
        vkiAttachmentDescription(pipeline->depth_format, VK_SAMPLE_COUNT_1_BIT, VK_ATTACHMENT_LOAD_OP_CLEAR, VK_ATTACHMENT_STORE_OP_STORE, VK_ATTACHMENT_LOAD_OP_DONT_CARE, VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL)
    };

    VkAttachmentReference color_refs[] = {
        vkiAttachmentReference(0, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL),
        vkiAttachmentReference(1, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL),
        vkiAttachmentReference(2, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL)
    };

    VkAttachmentReference depth_ref = vkiAttachmentReference(3, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);

    VkSubpassDescription subpass = vkiSubpassDescription(VK_PIPELINE_BIND_POINT_GRAPHICS, 0, NULL, 3, color_refs, NULL, &depth_ref, 0, NULL);

    VkSubpassDependency subpass_deps[] = {
        vkiSubpassDependency(VK_SUBPASS_EXTERNAL, 0, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_ACCESS_MEMORY_READ_BIT, VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT, VK_DEPENDENCY_BY_REGION_BIT),
        vkiSubpassDependency(0, VK_SUBPASS_EXTERNAL, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT, VK_ACCESS_MEMORY_READ_BIT, VK_DEPENDENCY_BY_REGION_BIT)
    };

    VkRenderPassCreateInfo rpass_info = vkiRenderPassCreateInfo(4, descs, 1, &subpass, 2, subpass_deps);
    vkcheck(vkCreateRenderPass(pipeline->automaton->device, &rpass_info, NULL, &pipeline->d3_deferred.offscreen.rpass));
}

void off_create_framebuffers(struct ScPipeline *pipeline)
{
    VkImageView fbuf_atts[] = {
        pipeline->d3_deferred.offscreen.position_res.view,
        pipeline->d3_deferred.offscreen.normal_res.view,
        pipeline->d3_deferred.offscreen.albedo_res.view,
        pipeline->d3_deferred.offscreen.depth_res.view,
    };
    VkFramebufferCreateInfo fbuf_info = vkiFramebufferCreateInfo(pipeline->d3_deferred.offscreen.rpass, 4, fbuf_atts, pipeline->extent.width, pipeline->extent.height, 1);
    pipeline->d3_deferred.offscreen.fbufs = list_create(VkFramebuffer, pipeline->present_views->size);
    for_list(i, pipeline->d3_deferred.offscreen.fbufs)
    {
        vkcheck(vkCreateFramebuffer(pipeline->automaton->device, &fbuf_info, NULL, &pipeline->d3_deferred.offscreen.fbufs.data[i]));
    }
}

void off_create_sampler(struct ScPipeline *pipeline)
{
    VkSamplerCreateInfo sampler_info = vkiSamplerCreateInfo(VK_FILTER_NEAREST, VK_FILTER_NEAREST, VK_SAMPLER_MIPMAP_MODE_LINEAR, VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE, VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE, VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE, 0.0f, VK_FALSE, 1.0f, VK_FALSE, VK_COMPARE_OP_NEVER, 0.0f, 1.0f, VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE, VK_FALSE);
    vkcheck(vkCreateSampler(pipeline->automaton->device, &sampler_info, NULL, &pipeline->d3_deferred.offscreen.sampler));
}

void off_create_descriptor_set_layout(struct ScPipeline *pipeline)
{
    VkDescriptorSetLayoutBinding set_layout_binding = {0};
    set_layout_binding.binding = 0;
    set_layout_binding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    set_layout_binding.descriptorCount = 1;
    set_layout_binding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;
    set_layout_binding.pImmutableSamplers = NULL;
    VkDescriptorSetLayoutCreateInfo set_layout_info = {0};
    set_layout_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    set_layout_info.bindingCount = 1;
    set_layout_info.pBindings = &set_layout_binding;
    vkcheck(vkCreateDescriptorSetLayout(pipeline->automaton->device, &set_layout_info, NULL, &pipeline->d3_deferred.offscreen.setlay));
}

void off_create_pipeline_layout(struct ScPipeline *pipeline)
{
    VkPipelineLayoutCreateInfo pipl_info = {0};
    pipl_info.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipl_info.setLayoutCount = 1;
    pipl_info.pSetLayouts = &pipeline->d3_deferred.offscreen.setlay;
    pipl_info.pushConstantRangeCount = 0;

    vkcheck(vkCreatePipelineLayout(pipeline->automaton->device, &pipl_info, NULL, &pipeline->d3_deferred.offscreen.pipl));
}

void off_create_pipeline(struct ScPipeline *pipeline)
{
    VkShaderModule svert = create_shader_module(pipeline->automaton->device, __src_shaders_offscreen_vert_spv_len, (const uint32_t *)__src_shaders_offscreen_vert_spv);
    VkShaderModule sfrag = create_shader_module(pipeline->automaton->device, __src_shaders_offscreen_frag_spv_len, (const uint32_t *)__src_shaders_offscreen_frag_spv);
    VkPipelineShaderStageCreateInfo vert_stage_info = init_pipeline_shader_stage_info(VK_SHADER_STAGE_VERTEX_BIT, svert, "main");
    VkPipelineShaderStageCreateInfo frag_stage_info = init_pipeline_shader_stage_info(VK_SHADER_STAGE_FRAGMENT_BIT, sfrag, "main");
    VkPipelineShaderStageCreateInfo shad_stages_info[] = {vert_stage_info, frag_stage_info};

    VkFormat per_vertex_formats[] = {VK_FORMAT_R32G32B32_SFLOAT, VK_FORMAT_R32G32B32_SFLOAT};
    VkFormat per_instance_formats[] = {VK_FORMAT_R32G32B32A32_SFLOAT, VK_FORMAT_R32G32B32A32_SFLOAT, VK_FORMAT_R32G32B32A32_SFLOAT, VK_FORMAT_R32G32B32A32_SFLOAT};
    VkVertexInputBindingDescription bindings[] = {
        vkiVertexInputBindingDescription(0, sizeof(float) * 3 + sizeof(float) * 3 + sizeof(float) * 3, VK_VERTEX_INPUT_RATE_VERTEX),
        vkiVertexInputBindingDescription(1, sizeof(float) * 16, VK_VERTEX_INPUT_RATE_INSTANCE)};
    VkVertexInputAttributeDescription attributes[] = {
        vkiVertexInputAttributeDescription(0, 0, VK_FORMAT_R32G32B32_SFLOAT, 0),
        vkiVertexInputAttributeDescription(1, 0, VK_FORMAT_R32G32B32_SFLOAT, sizeof(float) * 3),
        vkiVertexInputAttributeDescription(2, 0, VK_FORMAT_R32G32B32_SFLOAT, sizeof(float) * 6),
        vkiVertexInputAttributeDescription(3, 1, VK_FORMAT_R32G32B32A32_SFLOAT, 0),
        vkiVertexInputAttributeDescription(4, 1, VK_FORMAT_R32G32B32A32_SFLOAT, sizeof(float) * 4),
        vkiVertexInputAttributeDescription(5, 1, VK_FORMAT_R32G32B32A32_SFLOAT, sizeof(float) * 8),
        vkiVertexInputAttributeDescription(6, 1, VK_FORMAT_R32G32B32A32_SFLOAT, sizeof(float) * 12)};

    VkPipelineVertexInputStateCreateInfo vinput_info = vkiPipelineVertexInputStateCreateInfo(2, bindings, 7, attributes);
    VkPipelineInputAssemblyStateCreateInfo iass_info = vkiPipelineInputAssemblyStateCreateInfo(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST, VK_FALSE);
    VkPipelineViewportStateCreateInfo vstate_info = vkiPipelineViewportStateCreateInfo(1, NULL, 1, NULL);
    VkPipelineRasterizationStateCreateInfo rasterizer_info = vkiPipelineRasterizationStateCreateInfo(VK_FALSE, VK_FALSE, VK_POLYGON_MODE_FILL, VK_CULL_MODE_NONE /* temp */, VK_FRONT_FACE_CLOCKWISE, VK_FALSE, 0.0f, 0.0f, 0.0f, 1.0f);
    VkPipelineMultisampleStateCreateInfo multisampling = vkiPipelineMultisampleStateCreateInfo(VK_SAMPLE_COUNT_1_BIT, VK_FALSE, 0.0f, NULL, VK_FALSE, VK_FALSE);
    VkPipelineColorBlendAttachmentState color_atts[] = {
        vkiPipelineColorBlendAttachmentState(VK_FALSE, VK_BLEND_FACTOR_ZERO, VK_BLEND_FACTOR_ZERO, VK_BLEND_OP_ADD, VK_BLEND_FACTOR_ZERO, VK_BLEND_FACTOR_ZERO, VK_BLEND_OP_ADD, VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT),
        vkiPipelineColorBlendAttachmentState(VK_FALSE, VK_BLEND_FACTOR_ZERO, VK_BLEND_FACTOR_ZERO, VK_BLEND_OP_ADD, VK_BLEND_FACTOR_ZERO, VK_BLEND_FACTOR_ZERO, VK_BLEND_OP_ADD, VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT),
        vkiPipelineColorBlendAttachmentState(VK_FALSE, VK_BLEND_FACTOR_ZERO, VK_BLEND_FACTOR_ZERO, VK_BLEND_OP_ADD, VK_BLEND_FACTOR_ZERO, VK_BLEND_FACTOR_ZERO, VK_BLEND_OP_ADD, VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT)
    };
    VkPipelineColorBlendStateCreateInfo color_blend = vkiPipelineColorBlendStateCreateInfo(VK_FALSE, VK_LOGIC_OP_COPY, 3, color_atts);
    VkDynamicState dynamic_states[] = {
        VK_DYNAMIC_STATE_VIEWPORT,
        VK_DYNAMIC_STATE_SCISSOR};
    VkPipelineDynamicStateCreateInfo dynamic_state = vkiPipelineDynamicStateCreateInfo(2, dynamic_states);
    VkPipelineDepthStencilStateCreateInfo depth_stencil_state = vkiPipelineDepthStencilStateCreateInfo(VK_TRUE, VK_TRUE, VK_COMPARE_OP_LESS, VK_FALSE, VK_FALSE, vkiStencilOpState_null(), vkiStencilOpState_null(), 0.0f, 1.0f);

    VkGraphicsPipelineCreateInfo pip_info = vkiGraphicsPipelineCreateInfo(2, shad_stages_info, &vinput_info, &iass_info, NULL, &vstate_info, &rasterizer_info, &multisampling, &depth_stencil_state, &color_blend, &dynamic_state, pipeline->d3_deferred.offscreen.pipl, pipeline->d3_deferred.offscreen.rpass, 0, VK_NULL_HANDLE, 0);

    vkcheck(vkCreateGraphicsPipelines(pipeline->automaton->device, VK_NULL_HANDLE, 1, &pip_info, NULL, &pipeline->d3_deferred.offscreen.pip));

    vkDestroyShaderModule(pipeline->automaton->device, sfrag, NULL);
    vkDestroyShaderModule(pipeline->automaton->device, svert, NULL);
}

void off_create_descriptors(struct ScPipeline *pipeline)
{
    {
        VkDescriptorPoolSize pool_sizes[] = {
            vkiDescriptorPoolSize(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1)
        };
        VkDescriptorPoolCreateInfo info = vkiDescriptorPoolCreateInfo(1, 1, pool_sizes);
        vkcheck(vkCreateDescriptorPool(pipeline->automaton->device, &info, NULL, &pipeline->d3_deferred.offscreen.descpool));
    }
    {
        VkDescriptorSetAllocateInfo alloc_info = {0};
        alloc_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
        alloc_info.descriptorPool = pipeline->d3_deferred.offscreen.descpool;
        alloc_info.descriptorSetCount = 1;
        alloc_info.pSetLayouts = &pipeline->d3_deferred.offscreen.setlay;
        vkcheck(vkAllocateDescriptorSets(pipeline->automaton->device, &alloc_info, &pipeline->d3_deferred.offscreen.world_desc_set));

        VkDescriptorBufferInfo buffer_info = vkiDescriptorBufferInfo(pipeline->d3_deferred.sb_allocator.gpu_buffer.handle, pipeline->d3_deferred.sb_camera->_offset, get_subbuffer_size(&pipeline->d3_deferred.sb_allocator, pipeline->d3_deferred.sb_camera));
        VkWriteDescriptorSet write = vkiWriteDescriptorSet(pipeline->d3_deferred.offscreen.world_desc_set, 0, 0, 1, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, NULL, &buffer_info, NULL);
        vkUpdateDescriptorSets(pipeline->automaton->device, 1, &write, 0, NULL);
    }
}

void create_offscreen_resources(struct ScPipeline *pipeline)
{
    off_create_attachments(pipeline);
    off_create_render_pass(pipeline);
    off_create_framebuffers(pipeline);
    off_create_sampler(pipeline);
    off_create_descriptor_set_layout(pipeline);
    off_create_pipeline_layout(pipeline);
    off_create_pipeline(pipeline);
    off_create_descriptors(pipeline);
}

void for_create_render_pass(struct ScPipeline *pipeline)
{
    VkAttachmentDescription at_descs[2];
    at_descs[0] = vkiAttachmentDescription(pipeline->present_format, VK_SAMPLE_COUNT_1_BIT, VK_ATTACHMENT_LOAD_OP_CLEAR, VK_ATTACHMENT_STORE_OP_STORE, VK_ATTACHMENT_LOAD_OP_DONT_CARE, VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_PRESENT_SRC_KHR);
    at_descs[1] = vkiAttachmentDescription(pipeline->depth_format, VK_SAMPLE_COUNT_1_BIT, VK_ATTACHMENT_LOAD_OP_CLEAR, VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_ATTACHMENT_LOAD_OP_DONT_CARE, VK_ATTACHMENT_STORE_OP_DONT_CARE, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);

    VkAttachmentReference color_ref = {0};
    color_ref.attachment = 0;
    color_ref.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkAttachmentReference depth_ref = vkiAttachmentReference(1, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);

    VkSubpassDescription subpass = {0};
    subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount = 1;
    subpass.pColorAttachments = &color_ref;
    subpass.pDepthStencilAttachment = &depth_ref;

    VkSubpassDependency dependency = vkiSubpassDependency(VK_SUBPASS_EXTERNAL, 0, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, 0, VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT, 0);

    VkRenderPassCreateInfo info = {0};
    info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    info.attachmentCount = 2;
    info.pAttachments = at_descs;
    info.subpassCount = 1;
    info.pSubpasses = &subpass;
    info.dependencyCount = 1;
    info.pDependencies = &dependency;
    vkcheck(vkCreateRenderPass(pipeline->automaton->device, &info, NULL, &pipeline->d3_deferred.forward.rpass));
}

void for_create_framebuffers(struct ScPipeline *pipeline)
{
    pipeline->d3_deferred.forward.fbufs = list_create(VkFramebuffer, pipeline->present_views->size);
    VkFramebufferCreateInfo info = {0};
    info.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    info.renderPass = pipeline->d3_deferred.forward.rpass;
    info.width = pipeline->extent.width;
    info.height = pipeline->extent.height;
    info.layers = 1;
    for (uint32_t i = 0; i < pipeline->present_views->size; ++i)
    {
        VkImageView atts[] = {pipeline->present_views->data[i], pipeline->d3_deferred.forward.depth_res.view};
        info.attachmentCount = 2;
        info.pAttachments = atts;
        vkcheck(vkCreateFramebuffer(pipeline->automaton->device, &info, NULL, &pipeline->d3_deferred.forward.fbufs.data[i]));
    }
}

void for_create_descriptor_set_layout(struct ScPipeline *pipeline)
{
    VkDescriptorSetLayoutBinding set_layout_bindings[] = {
        vkiDescriptorSetLayoutBinding(0, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1, VK_SHADER_STAGE_FRAGMENT_BIT, NULL),
        vkiDescriptorSetLayoutBinding(1, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1, VK_SHADER_STAGE_FRAGMENT_BIT, NULL),
        vkiDescriptorSetLayoutBinding(2, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1, VK_SHADER_STAGE_FRAGMENT_BIT, NULL),
        vkiDescriptorSetLayoutBinding(3, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1, VK_SHADER_STAGE_FRAGMENT_BIT, NULL),
    };
    VkDescriptorSetLayoutCreateInfo set_layout_info = vkiDescriptorSetLayoutCreateInfo(4, set_layout_bindings);
    vkcheck(vkCreateDescriptorSetLayout(pipeline->automaton->device, &set_layout_info, NULL, &pipeline->d3_deferred.forward.setlay));
    //set_layout_info = vkiDescriptorSetLayoutCreateInfo(1, &set_layout_bindings[3]);
    //vkcheck(vkCreateDescriptorSetLayout(pipeline->automaton->device, &set_layout_info, NULL, &pipeline->d3_deferred.forward.lights_setlay));
}

void for_create_pipeline_layout(struct ScPipeline *pipeline)
{
    VkDescriptorSetLayout setlays[] = {pipeline->d3_deferred.forward.setlay};
    VkPipelineLayoutCreateInfo pipl_info = vkiPipelineLayoutCreateInfo(1, setlays, 0, NULL);
    vkcheck(vkCreatePipelineLayout(pipeline->automaton->device, &pipl_info, NULL, &pipeline->d3_deferred.forward.pipl));
}

void for_create_pipeline(struct ScPipeline *pipeline)
{
    VkShaderModule svert = create_shader_module(pipeline->automaton->device, __src_shaders_forward_vert_spv_len, (const uint32_t *)__src_shaders_forward_vert_spv);
    VkShaderModule sfrag = create_shader_module(pipeline->automaton->device, __src_shaders_forward_frag_spv_len, (const uint32_t *)__src_shaders_forward_frag_spv);
    VkPipelineShaderStageCreateInfo vert_stage_info = init_pipeline_shader_stage_info(VK_SHADER_STAGE_VERTEX_BIT, svert, "main");
    VkPipelineShaderStageCreateInfo frag_stage_info = init_pipeline_shader_stage_info(VK_SHADER_STAGE_FRAGMENT_BIT, sfrag, "main");
    VkPipelineShaderStageCreateInfo shad_stages_info[] = {vert_stage_info, frag_stage_info};

    VkPipelineVertexInputStateCreateInfo vinput_info = vkiPipelineVertexInputStateCreateInfo_null();
    VkPipelineInputAssemblyStateCreateInfo iass_info = vkiPipelineInputAssemblyStateCreateInfo(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST, VK_FALSE);
    VkPipelineViewportStateCreateInfo vstate_info = vkiPipelineViewportStateCreateInfo(1, NULL, 1, NULL);
    VkPipelineRasterizationStateCreateInfo rasterizer_info = vkiPipelineRasterizationStateCreateInfo(VK_FALSE, VK_FALSE, VK_POLYGON_MODE_FILL, VK_CULL_MODE_BACK_BIT, VK_FRONT_FACE_CLOCKWISE, VK_FALSE, 0.0f, 0.0f, 0.0f, 1.0f);
    VkPipelineMultisampleStateCreateInfo multisampling = vkiPipelineMultisampleStateCreateInfo(VK_SAMPLE_COUNT_1_BIT, VK_FALSE, 0.0f, NULL, VK_FALSE, VK_FALSE);
    VkPipelineColorBlendAttachmentState color_att = vkiPipelineColorBlendAttachmentState(VK_FALSE, VK_BLEND_FACTOR_ZERO, VK_BLEND_FACTOR_ZERO, VK_BLEND_OP_ADD, VK_BLEND_FACTOR_ZERO, VK_BLEND_FACTOR_ZERO, VK_BLEND_OP_ADD, VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT);
    VkPipelineColorBlendStateCreateInfo color_blend = vkiPipelineColorBlendStateCreateInfo(VK_FALSE, VK_LOGIC_OP_COPY, 1, &color_att);
    color_blend.blendConstants[0] = 0.0f;
    color_blend.blendConstants[1] = 0.0f;
    color_blend.blendConstants[2] = 0.0f;
    color_blend.blendConstants[3] = 0.0f;
    VkDynamicState dynamic_states[] = {
        VK_DYNAMIC_STATE_VIEWPORT,
        VK_DYNAMIC_STATE_SCISSOR};
    VkPipelineDynamicStateCreateInfo dynamic_state = vkiPipelineDynamicStateCreateInfo(2, dynamic_states);
    VkPipelineDepthStencilStateCreateInfo depth_stencil_state = vkiPipelineDepthStencilStateCreateInfo(VK_TRUE, VK_TRUE, VK_COMPARE_OP_LESS, VK_FALSE, VK_FALSE, vkiStencilOpState_null(), vkiStencilOpState_null(), 0.0f, 1.0f);

    VkGraphicsPipelineCreateInfo pip_info = vkiGraphicsPipelineCreateInfo(2, shad_stages_info, &vinput_info, &iass_info, NULL, &vstate_info, &rasterizer_info, &multisampling, &depth_stencil_state, &color_blend, &dynamic_state, pipeline->d3_deferred.forward.pipl, pipeline->d3_deferred.forward.rpass, 0, VK_NULL_HANDLE, 0);
    log_debug("haha");
    vkcheck(vkCreateGraphicsPipelines(pipeline->automaton->device, VK_NULL_HANDLE, 1, &pip_info, NULL, &pipeline->d3_deferred.forward.pip));
    log_debug("haha");

    vkDestroyShaderModule(pipeline->automaton->device, sfrag, NULL);
    vkDestroyShaderModule(pipeline->automaton->device, svert, NULL);
}

void for_create_descriptors(struct ScPipeline *pipeline)
{
    VkDescriptorPoolSize pool_sizes[] = {
        vkiDescriptorPoolSize(VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1),
        vkiDescriptorPoolSize(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1)
    };
    VkDescriptorPoolCreateInfo info = vkiDescriptorPoolCreateInfo(1, 2, pool_sizes);
    vkcheck(vkCreateDescriptorPool(pipeline->automaton->device, &info, NULL, &pipeline->d3_deferred.forward.descpool));
    VkDescriptorSetAllocateInfo alloc_info = vkiDescriptorSetAllocateInfo(pipeline->d3_deferred.forward.descpool, 1, &pipeline->d3_deferred.forward.setlay);
    vkcheck(vkAllocateDescriptorSets(pipeline->automaton->device, &alloc_info, &pipeline->d3_deferred.forward.desc_set));

    VkDescriptorImageInfo image_infos[] = {
        vkiDescriptorImageInfo(pipeline->d3_deferred.offscreen.sampler, pipeline->d3_deferred.offscreen.position_res.view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL),
        vkiDescriptorImageInfo(pipeline->d3_deferred.offscreen.sampler, pipeline->d3_deferred.offscreen.normal_res.view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL),
        vkiDescriptorImageInfo(pipeline->d3_deferred.offscreen.sampler, pipeline->d3_deferred.offscreen.albedo_res.view, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL)
    };

    VkDescriptorBufferInfo buffer_info = vkiDescriptorBufferInfo(pipeline->d3_deferred.sb_allocator.gpu_buffer.handle, pipeline->d3_deferred.sb_ambient_light->_offset,  get_subbuffer_segment_max_size(&pipeline->d3_deferred.sb_allocator, 1) + get_subbuffer_segment_max_size(&pipeline->d3_deferred.sb_allocator, 2) + get_subbuffer_segment_max_size(&pipeline->d3_deferred.sb_allocator, 3));

    VkWriteDescriptorSet writes[] = {
        vkiWriteDescriptorSet(pipeline->d3_deferred.forward.desc_set, 0, 0, 1, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, &image_infos[0], NULL, NULL),
        vkiWriteDescriptorSet(pipeline->d3_deferred.forward.desc_set, 1, 0, 1, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, &image_infos[1], NULL, NULL),
        vkiWriteDescriptorSet(pipeline->d3_deferred.forward.desc_set, 2, 0, 1, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, &image_infos[2], NULL, NULL),
        vkiWriteDescriptorSet(pipeline->d3_deferred.forward.desc_set, 3, 0, 1, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, NULL, &buffer_info, NULL)
    };

    vkUpdateDescriptorSets(pipeline->automaton->device, 4, writes, 0, NULL);
}

void create_forward_resources(struct ScPipeline *pipeline)
{
    pipeline->d3_deferred.forward.depth_res = automaton_create_image(pipeline->automaton, AUTOMATON_QUEUE_TYPE_GRAPHICS, pipeline->extent.width, pipeline->extent.height, 1, pipeline->depth_format, VK_IMAGE_TYPE_2D, VK_IMAGE_VIEW_TYPE_2D, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, VK_IMAGE_ASPECT_DEPTH_BIT);
    for_create_render_pass(pipeline);
    for_create_framebuffers(pipeline);
    for_create_descriptor_set_layout(pipeline);
    for_create_pipeline_layout(pipeline);
    for_create_pipeline(pipeline);
    for_create_descriptors(pipeline);
}

struct ScPipeline create_pipeline_d3_deferred(struct Automaton *automaton, VkExtent2D extent, VkFormat present_format, VkFormat depth_format, const struct List_VkImageView *present_views)
{
    struct ScPipeline pipeline = {0};
    pipeline.type = SC_PIPELINE_TYPE_3D_DEFERRED;
    pipeline.automaton = automaton;
    pipeline.extent = extent;
    pipeline.present_format = present_format;
    pipeline.depth_format = depth_format;
    pipeline.present_views = present_views;
    pipeline.record_cmd_fn = pipeline_d3_deferred_record_cmd;
    pipeline.update_fn = pipeline_d3_deferred_update;
    pipeline_create_buffer_resources(&pipeline);
    create_offscreen_resources(&pipeline);
    create_forward_resources(&pipeline);
    pipeline.packs_ptrs = list_create(ScMeshPack_ptr, 0);
    return pipeline;
}

void destroy_pipeline_d3_deferred(struct ScPipeline *pipeline)
{
    list_ScMeshPack_ptr_destroy(&pipeline->packs_ptrs);
    /// FORWARD
    automaton_collect_vkobject(pipeline->automaton, AUTOMATON_VK_OBJECT_TYPE_DESCRIPTOR_POOL, pipeline->d3_deferred.forward.descpool);
    automaton_collect_vkobject(pipeline->automaton, AUTOMATON_VK_OBJECT_TYPE_PIPELINE, pipeline->d3_deferred.forward.pip);
    automaton_collect_vkobject(pipeline->automaton, AUTOMATON_VK_OBJECT_TYPE_PIPELINE_LAYOUT, pipeline->d3_deferred.forward.pipl);
    automaton_collect_vkobject(pipeline->automaton, AUTOMATON_VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT, pipeline->d3_deferred.forward.setlay);
    for_list(i, pipeline->d3_deferred.forward.fbufs)
    {
        automaton_collect_vkobject(pipeline->automaton, AUTOMATON_VK_OBJECT_TYPE_FRAMEBUFFER, pipeline->d3_deferred.forward.fbufs.data[i]);
    }
    list_VkFramebuffer_destroy(&pipeline->d3_deferred.forward.fbufs);
    automaton_collect_vkobject(pipeline->automaton, AUTOMATON_VK_OBJECT_TYPE_RENDERPASS, pipeline->d3_deferred.forward.rpass);
    automaton_collect_image(pipeline->automaton, &pipeline->d3_deferred.forward.depth_res);
    /// OFFSCREEN
    automaton_collect_vkobject(pipeline->automaton, AUTOMATON_VK_OBJECT_TYPE_DESCRIPTOR_POOL, pipeline->d3_deferred.offscreen.descpool);
    automaton_collect_vkobject(pipeline->automaton, AUTOMATON_VK_OBJECT_TYPE_PIPELINE, pipeline->d3_deferred.offscreen.pip);
    automaton_collect_vkobject(pipeline->automaton, AUTOMATON_VK_OBJECT_TYPE_PIPELINE_LAYOUT, pipeline->d3_deferred.offscreen.pipl);
    automaton_collect_vkobject(pipeline->automaton, AUTOMATON_VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT, pipeline->d3_deferred.offscreen.setlay);
    automaton_collect_vkobject(pipeline->automaton, AUTOMATON_VK_OBJECT_TYPE_SAMPLER, pipeline->d3_deferred.offscreen.sampler);
    for_list(i, pipeline->d3_deferred.offscreen.fbufs)
    {
        automaton_collect_vkobject(pipeline->automaton, AUTOMATON_VK_OBJECT_TYPE_FRAMEBUFFER, pipeline->d3_deferred.offscreen.fbufs.data[i]);
    }
    list_VkFramebuffer_destroy(&pipeline->d3_deferred.offscreen.fbufs);
    automaton_collect_vkobject(pipeline->automaton, AUTOMATON_VK_OBJECT_TYPE_RENDERPASS, pipeline->d3_deferred.offscreen.rpass);
    automaton_collect_image(pipeline->automaton, &pipeline->d3_deferred.offscreen.depth_res);
    automaton_collect_image(pipeline->automaton, &pipeline->d3_deferred.offscreen.albedo_res);
    automaton_collect_image(pipeline->automaton, &pipeline->d3_deferred.offscreen.normal_res);
    automaton_collect_image(pipeline->automaton, &pipeline->d3_deferred.offscreen.position_res);
    /// BUFFER RESOURCES
    destroy_subbuffer_allocator(&pipeline->d3_deferred.sb_allocator);
}

void pipeline_d3_deferred_record_cmd(struct ScPipeline *pipeline, VkCommandBuffer cmd, uint32_t image_index)
{
    bool empty_flag = true;
    for_list(i, pipeline->packs_ptrs)
    {
        if (is_mesh_pack_empty(pipeline->packs_ptrs.data[i]) != true)
        {
            empty_flag = false;
            break;
        }
    }
    if (empty_flag == true) return;

    /// OFFSCREEN

    VkRenderPassBeginInfo off_rpass_info = {0};
    off_rpass_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    off_rpass_info.renderPass = pipeline->d3_deferred.offscreen.rpass;
    off_rpass_info.framebuffer = pipeline->d3_deferred.offscreen.fbufs.data[image_index];
    off_rpass_info.renderArea.offset.x = 0;
    off_rpass_info.renderArea.offset.y = 0;
    off_rpass_info.renderArea.extent = pipeline->extent;
    VkClearValue clear_values[4];
    clear_values[0].color = (VkClearColorValue){ { 0.0f, 0.0f, 0.0f, 0.0f } };
    clear_values[1].color = (VkClearColorValue){ { 0.0f, 0.0f, 0.0f, 0.0f } };
    clear_values[2].color = (VkClearColorValue){ { 0.0f, 0.0f, 0.0f, 0.0f } };
    clear_values[3].depthStencil = vkiClearDepthStencilValue(1.0f, 0);
    off_rpass_info.clearValueCount = 4;
    off_rpass_info.pClearValues = clear_values;
    vkCmdBeginRenderPass(cmd, &off_rpass_info, VK_SUBPASS_CONTENTS_INLINE);
    vkCmdBindPipeline(cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline->d3_deferred.offscreen.pip);
    vkCmdBindDescriptorSets(cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline->d3_deferred.offscreen.pipl, 0, 1, &pipeline->d3_deferred.offscreen.world_desc_set, 0, NULL);
    VkViewport viewport = {0.0f, 0.0f, (float)pipeline->extent.width, (float)pipeline->extent.height, 0.0f, 1.0f};
    vkCmdSetViewport(cmd, 0, 1, &viewport);
    VkRect2D scissor = {{0, 0}, pipeline->extent};
    vkCmdSetScissor(cmd, 0, 1, &scissor);

    for_list(i, pipeline->packs_ptrs)
    {
        struct ScMeshPack *pack = pipeline->packs_ptrs.data[i];
        VkBuffer bigbuf[] = {mesh_pack_get_vkbuffer(pack)};
        for_loop(j, mesh_pack_get_mesh_count(pack))
        {
            size_t instance_count = mesh_pack_get_instance_count(pack, j);
            if (instance_count == 0) continue;
            VkDeviceSize vertex_offset[] = {mesh_pack_get_mesh_vertex_offset(pack, j)};
            VkDeviceSize index_offset = {mesh_pack_get_mesh_index_offset(pack, j)};
            VkDeviceSize instance_offset[] = {mesh_pack_get_mesh_instance_offset(pack, j)};
            vkCmdBindVertexBuffers(cmd, 0, 1, bigbuf, vertex_offset);
            vkCmdBindVertexBuffers(cmd, 1, 1, bigbuf, instance_offset);
            vkCmdBindIndexBuffer(cmd, bigbuf[0], index_offset, VK_INDEX_TYPE_UINT32);
            vkCmdDrawIndexed(cmd, mesh_pack_get_mesh_index_count(pack, j), instance_count, 0, 0, 0);
        }
    }
    //vkCmdDraw(core->cmds.data[core->current_frame_index], 3, 1, 0, 0);
    vkCmdEndRenderPass(cmd);

    /// FORWARD

    VkClearValue clearValues[2];
	clearValues[0].color = (VkClearColorValue){ { 0.0f, 0.0f, 0.0f, 1.0f } };
	clearValues[1].depthStencil = vkiClearDepthStencilValue(1.0f, 0);
	VkRenderPassBeginInfo for_rpass_info = vkiRenderPassBeginInfo(pipeline->d3_deferred.forward.rpass, pipeline->d3_deferred.forward.fbufs.data[image_index], (VkRect2D){(VkOffset2D){}, (VkExtent2D)pipeline->extent}, 2, clearValues);
	vkCmdBeginRenderPass(cmd, &for_rpass_info, VK_SUBPASS_CONTENTS_INLINE);
	vkCmdBindPipeline(cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline->d3_deferred.forward.pip);
    vkCmdBindDescriptorSets(cmd, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline->d3_deferred.forward.pipl, 0, 1, &pipeline->d3_deferred.forward.desc_set, 0, NULL);
    //VkViewport viewport = {0.0f, 0.0f, (float)core->sf_extent.width, (float)core->sf_extent.height, 0.0f, 1.0f};
    vkCmdSetViewport(cmd, 0, 1, &viewport);
    //VkRect2D scissor = {{0, 0}, core->sf_extent};
    vkCmdSetScissor(cmd, 0, 1, &scissor);
	vkCmdDraw(cmd, 3, 1, 0, 0);
	vkCmdEndRenderPass(cmd);
}

void sc_pipeline_update_camera(struct ScPipeline *pipeline, const void *camera_data)
{
    pipeline->d3_deferred.sb_camera->data = camera_data;
    pipeline->d3_deferred.sb_camera->updated = true;
}

void pipeline_d3_deferred_update(struct ScPipeline *pipeline)
{
    subbuffer_allocator_update(&pipeline->d3_deferred.sb_allocator);
    for_list(i, pipeline->packs_ptrs)
    {
        update_mesh_pack(pipeline->packs_ptrs.data[i]);
    }
}

struct ScPipeline *sc_create_pipeline(struct ScCore *core, enum ScPipelineType type)
{
    ram_alloc_init(struct ScPipeline, pipeline);
    switch (type)
    {
    case SC_PIPELINE_TYPE_3D_DEFERRED:
    *pipeline = create_pipeline_d3_deferred(&core->automaton, core->sf_extent, core->sf_format.format, core->depth_format, &core->sviews);
    break;
    default:
    log_error("pipeline not supported yet");
    break;
    }
    return pipeline;
}

void sc_destroy_pipeline(struct ScPipeline *pipeline)
{
    switch (pipeline->type)
    {
    case SC_PIPELINE_TYPE_3D_DEFERRED:
    destroy_pipeline_d3_deferred(pipeline);
    break;
    default:
    log_error("pipeline not supported yet");
    break;
    }
    ram_free(pipeline);
}

struct ScPointLight *sc_create_point_light(struct ScPipeline *pipeline, const struct ScPointLightData *light_data)
{
    ram_alloc_init(struct ScPointLight, light);
    light->subbuffer = allocate_subbuffer(&pipeline->d3_deferred.sb_allocator, 3);
    light->subbuffer->data = light_data;
    light->subbuffer->updated = true;
    //pipeline->d3_deferred.lights_count.d[0] += 1.0f;
    //pipeline->d3_deferred.sb_light_count->updated = true;
    return light;
}

void sc_destroy_point_light(struct ScPipeline *pipeline, struct ScPointLight *light)
{
    free_subbuffer(&pipeline->d3_deferred.sb_allocator, light->subbuffer);
    //pipeline->d3_deferred.lights_count.d[0] -= 1;
    //pipeline->d3_deferred.sb_light_count->updated = true;
    ram_free(light);
}

void sc_set_ambient_light(struct ScPipeline *pipeline, struct ScAmbientLightData *light_data)
{
    pipeline->d3_deferred.sb_ambient_light->data = light_data;
    pipeline->d3_deferred.sb_ambient_light->updated = true;
}
