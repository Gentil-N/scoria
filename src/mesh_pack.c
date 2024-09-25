#include "common.h"
#include "ctools.h"
#include "log.h"

#include <assimp/cimport.h>
#include <assimp/mesh.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/anim.h>
#include <string.h>

#define INSTANCE_SIZE sizeof(float) * 16

void init_mesh_infos(struct ScMeshPack *pack, const struct ScMeshPackInfo *info)
{
    pack->vertex_byte_offsets = list_create(size_t, info->mesh_count);
    pack->index_byte_offsets = list_create(size_t, info->mesh_count);
    pack->index_counts = list_create(size_t, info->mesh_count);
    pack->instance_offsets = list_create(size_t, info->mesh_count);
    pack->max_instances = list_create(size_t, info->mesh_count);
    pack->list_item_ptrs = list_create(List_ScItem_ptr, info->mesh_count);
    for_list(i, pack->max_instances)
    {
        pack->max_instances.data[i] = info->max_instance_per_mesh[i];
    }
    for_list(i, pack->list_item_ptrs)
    {
        pack->list_item_ptrs.data[i] = list_create(ScItem_ptr, 0);
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

void create_buffer_resources(struct ScCore *core, struct ScMeshPack *pack, const struct ScMeshPackInfo *mesh_pack_info)
{
    void *mesh_data = ram_malloc(pack->total_mesh_byte_size);
    memcpy(mesh_data, mesh_pack_info->vertex_data, pack->index_byte_offsets.data[0]);
    memcpy((void*)((size_t)mesh_data + pack->index_byte_offsets.data[0]), mesh_pack_info->index_data, pack->total_mesh_byte_size - pack->index_byte_offsets.data[0]);

    size_t segment_count = mesh_pack_info->mesh_count + 1;
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

struct ScMeshPack *sc_create_mesh_pack(struct ScCore *core, struct ScPipeline *pipeline, const struct ScMeshPackInfo *mesh_pack_info)
{
    assert(mesh_pack_info->mesh_count > 0);
    ram_alloc_init(struct ScMeshPack, pack);
    init_mesh_infos(pack, mesh_pack_info);
    pack->pipeline = pipeline;
    create_buffer_resources(core, pack, mesh_pack_info);
    list_ScMeshPack_ptr_append(&pipeline->packs_ptrs, &pack);
    return pack;
}

void sc_destroy_mesh_pack(struct ScMeshPack *mesh_pack)
{
    size_t i = list_ScMeshPack_ptr_remove_on_finding(&mesh_pack->pipeline->packs_ptrs, &mesh_pack);
    if (i == SIZE_MAX) log_warn("unable to remove resource pack %p", mesh_pack);
    destroy_subbuffer_allocator(&mesh_pack->sb_allocator);
    list_size_t_destroy(&mesh_pack->vertex_byte_offsets);
    list_size_t_destroy(&mesh_pack->index_byte_offsets);
    list_size_t_destroy(&mesh_pack->index_counts);
    list_size_t_destroy(&mesh_pack->max_instances);
    list_size_t_destroy(&mesh_pack->instance_offsets);
    for_list(i, mesh_pack->list_item_ptrs)
    {
        list_ScItem_ptr_destroy(&mesh_pack->list_item_ptrs.data[i]);
    }
    list_List_ScItem_ptr_destroy(&mesh_pack->list_item_ptrs);
    ram_free(mesh_pack);
}

struct ScItem *sc_create_item(struct ScMeshPack *mesh_pack, size_t mesh_id, const void *item_data)
{
    assert_ndbg(mesh_id < mesh_pack->vertex_byte_offsets.size);
    ram_alloc_init(struct ScItem, item);
    item->subbuffer = allocate_subbuffer(&mesh_pack->sb_allocator, mesh_id + 1);
    item->subbuffer->data = item_data;
    list_ScItem_ptr_append(&mesh_pack->list_item_ptrs.data[mesh_id], &item);
    return item;
}

void sc_destroy_item(struct ScMeshPack *mesh_pack, struct ScItem *item)
{
    list_ScItem_ptr_remove_on_finding(&mesh_pack->list_item_ptrs.data[item->subbuffer->_segment_id - 1], &item);
    free_subbuffer(&mesh_pack->sb_allocator, item->subbuffer);
    ram_free(item);
}

void update_mesh_pack(struct ScMeshPack *mesh_pack)
{
    subbuffer_allocator_update(&mesh_pack->sb_allocator);
}

bool is_mesh_pack_empty(struct ScMeshPack *mesh_pack)
{
    for_list(i, mesh_pack->list_item_ptrs)
    {
        if (mesh_pack->list_item_ptrs.data[i].size != 0) return false;
    }
    return true;
}

size_t mesh_pack_get_mesh_count(struct ScMeshPack *mesh_pack)
{
    return mesh_pack->vertex_byte_offsets.size;
}

size_t mesh_pack_get_instance_count(struct ScMeshPack *mesh_pack, size_t mesh_id)
{
    assert(mesh_id < mesh_pack->list_item_ptrs.size);
    return mesh_pack->list_item_ptrs.data[mesh_id].size;
}

VkDeviceSize mesh_pack_get_mesh_vertex_offset(struct ScMeshPack *mesh_pack, size_t mesh_id)
{
    assert(mesh_id < mesh_pack->vertex_byte_offsets.size);
    return (VkDeviceSize)mesh_pack->vertex_byte_offsets.data[mesh_id];
}

VkDeviceSize mesh_pack_get_mesh_index_offset(struct ScMeshPack *mesh_pack, size_t mesh_id)
{
    assert(mesh_id < mesh_pack->index_byte_offsets.size);
    return (VkDeviceSize)mesh_pack->index_byte_offsets.data[mesh_id];
}

VkDeviceSize mesh_pack_get_mesh_instance_offset(struct ScMeshPack *mesh_pack, size_t mesh_id)
{
    assert(mesh_id < mesh_pack->instance_offsets.size);
    return (VkDeviceSize)mesh_pack->instance_offsets.data[mesh_id];
}

uint32_t mesh_pack_get_mesh_index_count(struct ScMeshPack *mesh_pack, size_t mesh_id)
{
    assert(mesh_id < mesh_pack->index_counts.size);
    return (uint32_t)mesh_pack->index_counts.data[mesh_id];
}

bool mesh_pack_is_mesh_empty(struct ScMeshPack *mesh_pack, size_t mesh_id)
{
    assert(mesh_id < mesh_pack->list_item_ptrs.size);
    return mesh_pack->list_item_ptrs.data[mesh_id].size == 0;
}

VkBuffer mesh_pack_get_vkbuffer(struct ScMeshPack *mesh_pack)
{
    return mesh_pack->sb_allocator.gpu_buffer.handle;
}
