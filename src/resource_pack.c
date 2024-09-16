#include "common.h"
#include "ctools.h"
#include "log.h"

/* TEST DATA */
struct Data
{
    float vertices[36];
    uint32_t indices[6];
};
static struct Data DATA;
size_t VERTEX_SIZE = sizeof(float) * 9 * 4;
size_t INDEX_SIZE = sizeof(uint32_t) * 6;
uint32_t INDEX_COUNT = 6;
/* * */

#include <assimp/cimport.h>
#include <assimp/mesh.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/anim.h>

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
    DATA.vertices[0] = -0.25f;
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

    DATA.vertices[15] = 1.0f;
    DATA.vertices[16] = 0.0f;
    DATA.vertices[17] = 0.0f;

    DATA.vertices[18] = 0.25f;
    DATA.vertices[19] = 0.25f;
    DATA.vertices[20] = 0.0f;

    DATA.vertices[21] = 0.0f;
    DATA.vertices[22] = 0.0f;
    DATA.vertices[23] = 0.0f;

    DATA.vertices[24] = 1.0f;
    DATA.vertices[25] = 0.0f;
    DATA.vertices[26] = 0.0f;

    DATA.vertices[27] = -0.25f;
    DATA.vertices[28] = 0.25f;
    DATA.vertices[29] = 0.0f;
    
    DATA.vertices[30] = 0.0f;
    DATA.vertices[31] = 0.0f;
    DATA.vertices[32] = 0.0f;
    
    DATA.vertices[33] = 1.0f;
    DATA.vertices[34] = 0.0f;
    DATA.vertices[35] = 0.0f;

    DATA.indices[0] = 0;
    DATA.indices[1] = 1;
    DATA.indices[2] = 2;
    DATA.indices[3] = 2;
    DATA.indices[4] = 3;
    DATA.indices[5] = 0;

    size_t segment_count = 2;
    struct SubBufferSegmentInfo segment_infos[2];
    segment_infos[0].max_subbuffer = resource_pack_info->max_instances;
    segment_infos[0].subbuffer_size = sizeof(float) * 16;
    segment_infos[1].max_subbuffer = 1;
    segment_infos[1].subbuffer_size = VERTEX_SIZE + INDEX_SIZE;
    pack->sb_allocator = create_subbuffer_allocator(&core->automaton, AUTOMATON_QUEUE_TYPE_GRAPHICS, AUTOMATON_QUEUE_TYPE_GRAPHICS, VK_BUFFER_USAGE_INDEX_BUFFER_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT | VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, segment_count, segment_infos);
    pack->sb_mesh = allocate_subbuffer(&pack->sb_allocator, 1);
    pack->sb_mesh->data = &DATA;
}

struct ScResourcePack *sc_create_resource_pack(struct ScCore *core, const struct ScResourcePackInfo *resource_pack_info, size_t filename_count, const char **filenames)
{
    assimp_test(filenames[0]);
    ram_alloc_init(struct ScResourcePack, pack);
    pack->core = core;
    create_buffer_resources(core, pack, resource_pack_info);
    pack->object_ptrs = list_create(ScObject_ptr, 0);
    core->pipeline.d3_deferred.test_pack = pack; // temp
    return pack;
}

void sc_destroy_resource_pack(struct ScResourcePack *resource_pack)
{
    list_ScObject_ptr_destroy(&resource_pack->object_ptrs);
    destroy_subbuffer_allocator(&resource_pack->sb_allocator);
    ram_free(resource_pack);
}

struct ScObject *sc_create_object(struct ScResourcePack *resource_pack, size_t resource_id, const struct ScObjectData *object_data)
{
    ram_alloc_init(struct ScObject, object);
    object->resource_pack = resource_pack;
    object->subbuffer = allocate_subbuffer(&resource_pack->sb_allocator, 0);
    object->subbuffer->data = &object_data->transform[0];
    list_ScObject_ptr_append(&resource_pack->object_ptrs, &object);
    return object;
}

void sc_destroy_object(struct ScObject *object)
{
    for_list(i, object->resource_pack->object_ptrs)
    {
        if (object->resource_pack->object_ptrs.data[i] == object)
        {
            list_ScObject_ptr_remove(&object->resource_pack->object_ptrs, i);
            break;
        }
    }
    free_subbuffer(&object->resource_pack->sb_allocator, object->subbuffer);
    ram_free(object);
}

void update_resource_pack(struct ScResourcePack *resource_pack)
{
    subbuffer_allocator_update(&resource_pack->sb_allocator);
}
