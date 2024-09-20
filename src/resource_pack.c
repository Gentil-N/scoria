#include "common.h"
#include "ctools.h"
#include "log.h"

/* TEST DATA */
/*struct Data
{
    float vertices[36];
    uint32_t indices[6];
};
static struct Data DATA;
size_t VERTEX_SIZE = sizeof(float) * 9 * 4;
size_t INDEX_SIZE = sizeof(uint32_t) * 6;
uint32_t INDEX_COUNT = 6;*/
/* * */

#include <assimp/cimport.h>
#include <assimp/mesh.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/anim.h>
#include <string.h>

#define INSTANCE_SIZE sizeof(float) * 16

void init_mesh_infos(struct ScResourcePack *pack, const struct ScResourcePackInfo *info)
{
    pack->vertex_byte_offsets = list_create(size_t, info->mesh_count);
    pack->index_byte_offsets = list_create(size_t, info->mesh_count);
    pack->index_counts = list_create(size_t, info->mesh_count);
    pack->instance_offsets = list_create(size_t, info->mesh_count);
    pack->max_instances = list_create(size_t, info->mesh_count);
    pack->list_object_ptrs = list_create(List_ScObject_ptr, info->mesh_count);
    for_list(i, pack->max_instances)
    {
        pack->max_instances.data[i] = info->max_instance_per_mesh[i];
    }
    for_list(i, pack->list_object_ptrs)
    {
        pack->list_object_ptrs.data[i] = list_create(ScObject_ptr, 0);
    }
    for_list(i, pack->index_counts)
    {
        pack->index_counts.data[i] = info->index_count_per_mesh[i];
    }
    size_t offset = 0;
    for_list(i, pack->vertex_byte_offsets)
    {
        pack->vertex_byte_offsets.data[i] = offset;
        offset += info->vertex_byte_size_per_mesh[i];
    }
    for_list(i, pack->index_byte_offsets)
    {
        pack->index_byte_offsets.data[i] = offset;
        offset += pack->index_counts.data[i] * sizeof(uint32_t);
    }
    pack->total_mesh_byte_size = offset;
    for_list(i, pack->instance_offsets)
    {
        pack->instance_offsets.data[i] = offset;
        offset += INSTANCE_SIZE * pack->max_instances.data[i];
    }
}

void parse_node(const struct aiNode *node)
{
    for_loop(i, node->mNumChildren)
    {
        log_debug("parent (%s) node name %s (num meshes %d)", node->mName.data, node->mChildren[i]->mName.data, node->mChildren[i]->mNumMeshes);
        parse_node(node->mChildren[i]);
    }
}

void assimp_test(const char *filename)
{
    log_debug("assimp started");
    const struct aiScene *scene = aiImportFile(filename, aiProcess_Triangulate | aiProcess_GenNormals | aiProcess_OptimizeMeshes | aiProcess_JoinIdenticalVertices);
    if (scene == NULL) log_error("failed to load file %s", filename);
    log_debug("num meshes %d", scene->mNumMeshes);
    log_debug("num animations %d", scene->mNumAnimations);
    log_debug("root node name %s", scene->mRootNode->mName.data);
    parse_node(scene->mRootNode);
    for_loop(i, scene->mNumMeshes) log_debug("mesh name %s %d", scene->mMeshes[i]->mName.data, scene->mMeshes[i]->mNumBones);
    for_loop(i, scene->mNumAnimations)
    {
        log_debug("anim name %s", scene->mAnimations[i]->mName.data);
        for_loop(j, scene->mAnimations[i]->mNumChannels)
        {
            log_debug("channel name %s num rot %d", scene->mAnimations[i]->mChannels[j]->mNodeName.data, scene->mAnimations[i]->mChannels[j]->mNumRotationKeys);
        }
    }
    log_debug("assimp finished");
}

void create_buffer_resources(struct ScCore *core, struct ScResourcePack *pack, const struct ScResourcePackInfo *resource_pack_info)
{
    /*DATA.vertices[0] = -0.25f;
    DATA.vertices[1] = -0.25f;
    DATA.vertices[2] = 0.0f;

    DATA.vertices[3] = 0.0f;
    DATA.vertices[4] = 0.0f;
    DATA.vertices[5] = 0.0f;

    DATA.vertices[6] = 1.0f;
    DATA.vertices[7] = 0.0f;
    DATA.vertices[8] = 0.0f;

    DATA.vertices[9] = 0.25f;
    DATA.vertices[10] = -0.25f;
    DATA.vertices[11] = 0.0f;

    DATA.vertices[12] = 0.0f;
    DATA.vertices[13] = 0.0f;
    DATA.vertices[14] = 0.0f;

    DATA.vertices[15] = 0.0f;
    DATA.vertices[16] = 1.0f;
    DATA.vertices[17] = 0.0f;

    DATA.vertices[18] = 0.25f;
    DATA.vertices[19] = 0.25f;
    DATA.vertices[20] = 0.0f;

    DATA.vertices[21] = 0.0f;
    DATA.vertices[22] = 0.0f;
    DATA.vertices[23] = 0.0f;

    DATA.vertices[24] = 0.0f;
    DATA.vertices[25] = 0.0f;
    DATA.vertices[26] = 1.0f;

    DATA.vertices[27] = -0.25f;
    DATA.vertices[28] = 0.25f;
    DATA.vertices[29] = 0.0f;

    DATA.vertices[30] = 0.0f;
    DATA.vertices[31] = 0.0f;
    DATA.vertices[32] = 0.0f;

    DATA.vertices[33] = 1.0f;
    DATA.vertices[34] = 0.0f;
    DATA.vertices[35] = 1.0f;

    DATA.indices[0] = 0;
    DATA.indices[1] = 1;
    DATA.indices[2] = 2;
    DATA.indices[3] = 2;
    DATA.indices[4] = 3;
    DATA.indices[5] = 0;*/

    void *mesh_data = ram_malloc(pack->total_mesh_byte_size);
    memcpy(mesh_data, resource_pack_info->vertex_data, pack->index_byte_offsets.data[0]);
    memcpy((void*)((size_t)mesh_data + pack->index_byte_offsets.data[0]), resource_pack_info->index_data, pack->total_mesh_byte_size - pack->index_byte_offsets.data[0]);

    size_t segment_count = resource_pack_info->mesh_count + 1;
    struct SubBufferSegmentInfo segment_infos[segment_count];
    segment_infos[0].max_subbuffer = 1;
    segment_infos[0].subbuffer_size = pack->total_mesh_byte_size;
    assert(segment_count - 1 == pack->max_instances.size);
    for (size_t i = 1; i < segment_count; ++i)
    {
        segment_infos[i].max_subbuffer = pack->max_instances.data[i - 1];
        segment_infos[i].subbuffer_size = INSTANCE_SIZE;
    }
    pack->sb_allocator = create_subbuffer_allocator(&core->automaton, AUTOMATON_QUEUE_TYPE_GRAPHICS, AUTOMATON_QUEUE_TYPE_GRAPHICS, VK_BUFFER_USAGE_INDEX_BUFFER_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT | VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, segment_count, segment_infos);
    pack->sb_mesh = allocate_subbuffer(&pack->sb_allocator, 0);
    pack->sb_mesh->data = mesh_data;
    pack->sb_mesh->free_on_copy = true;
}

struct ScResourcePack *sc_create_resource_pack(struct ScCore *core, struct ScPipeline *pipeline, const struct ScResourcePackInfo *resource_pack_info, size_t filename_count, const char **filenames)
{
    //assimp_test(filenames[0]);
    assert(resource_pack_info->mesh_count > 0);
    ram_alloc_init(struct ScResourcePack, pack);
    init_mesh_infos(pack, resource_pack_info);
    pack->pipeline = pipeline;
    create_buffer_resources(core, pack, resource_pack_info);
    list_ScResourcePack_ptr_append(&pipeline->d3_deferred.packs_ptrs, &pack);
    return pack;
}

void sc_destroy_resource_pack(struct ScResourcePack *resource_pack)
{
    assert(resource_pack->pipeline->type == SC_PIPELINE_TYPE_3D_DEFERRED);
    size_t i = list_ScResourcePack_ptr_remove_on_finding(&resource_pack->pipeline->d3_deferred.packs_ptrs, &resource_pack);
    if (i == SIZE_MAX) log_warn("unable to remove resource pack %p", resource_pack);
    destroy_subbuffer_allocator(&resource_pack->sb_allocator);
    list_size_t_destroy(&resource_pack->vertex_byte_offsets);
    list_size_t_destroy(&resource_pack->index_byte_offsets);
    list_size_t_destroy(&resource_pack->index_counts);
    list_size_t_destroy(&resource_pack->max_instances);
    list_size_t_destroy(&resource_pack->instance_offsets);
    for_list(i, resource_pack->list_object_ptrs)
    {
        list_ScObject_ptr_destroy(&resource_pack->list_object_ptrs.data[i]);
    }
    list_List_ScObject_ptr_destroy(&resource_pack->list_object_ptrs);
    ram_free(resource_pack);
}

struct ScObject *sc_create_object(struct ScResourcePack *resource_pack, size_t mesh_id, const struct ScObjectData *object_data)
{
    assert_ndbg(mesh_id < resource_pack->vertex_byte_offsets.size);
    ram_alloc_init(struct ScObject, object);
    object->subbuffer = allocate_subbuffer(&resource_pack->sb_allocator, mesh_id + 1);
    object->subbuffer->data = &object_data->transform[0];
    list_ScObject_ptr_append(&resource_pack->list_object_ptrs.data[mesh_id], &object);
    return object;
}

void sc_destroy_object(struct ScResourcePack *resource_pack, struct ScObject *object)
{
    list_ScObject_ptr_remove_on_finding(&resource_pack->list_object_ptrs.data[object->subbuffer->_segment_id - 1], &object);
    free_subbuffer(&resource_pack->sb_allocator, object->subbuffer);
    ram_free(object);
}

void update_resource_pack(struct ScResourcePack *resource_pack)
{
    subbuffer_allocator_update(&resource_pack->sb_allocator);
}

bool is_resource_pack_empty(struct ScResourcePack *resource_pack)
{
    for_list(i, resource_pack->list_object_ptrs)
    {
        if (resource_pack->list_object_ptrs.data[i].size != 0) return false;
    }
    return true;
}

size_t resource_pack_get_mesh_count(struct ScResourcePack *resource_pack)
{
    return resource_pack->vertex_byte_offsets.size;
}

size_t resource_pack_get_instance_count(struct ScResourcePack *resource_pack, size_t mesh_id)
{
    assert(mesh_id < resource_pack->list_object_ptrs.size);
    return resource_pack->list_object_ptrs.data[mesh_id].size;
}

VkDeviceSize resource_pack_get_mesh_vertex_offset(struct ScResourcePack *resource_pack, size_t mesh_id)
{
    assert(mesh_id < resource_pack->vertex_byte_offsets.size);
    return (VkDeviceSize)resource_pack->vertex_byte_offsets.data[mesh_id];
}

VkDeviceSize resource_pack_get_mesh_index_offset(struct ScResourcePack *resource_pack, size_t mesh_id)
{
    assert(mesh_id < resource_pack->index_byte_offsets.size);
    return (VkDeviceSize)resource_pack->index_byte_offsets.data[mesh_id];
}

VkDeviceSize resource_pack_get_mesh_instance_offset(struct ScResourcePack *resource_pack, size_t mesh_id)
{
    assert(mesh_id < resource_pack->instance_offsets.size);
    return (VkDeviceSize)resource_pack->instance_offsets.data[mesh_id];
}

uint32_t resource_pack_get_mesh_index_count(struct ScResourcePack *resource_pack, size_t mesh_id)
{
    assert(mesh_id < resource_pack->index_counts.size);
    return (uint32_t)resource_pack->index_counts.data[mesh_id];
}

bool resource_pack_is_mesh_empty(struct ScResourcePack *resource_pack, size_t mesh_id)
{
    assert(mesh_id < resource_pack->list_object_ptrs.size);
    return resource_pack->list_object_ptrs.data[mesh_id].size == 0;
}

VkBuffer resource_pack_get_vkbuffer(struct ScResourcePack *resource_pack)
{
    return resource_pack->sb_allocator.gpu_buffer.handle;
}
