#include "common.h"
#include "ctools.h"
#include "log.h"

#include <assimp/cimport.h>
#include <assimp/mesh.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/anim.h>
#include <string.h>

//void parse_node(const struct aiNode *node)
//{
//    for_loop(i, node->mNumChildren)
//    {
//        log_debug("parent (%s) node name %s (num meshes %d)", node->mName.data, node->mChildren[i]->mName.data, node->mChildren[i]->mNumMeshes);
//        parse_node(node->mChildren[i]);
//    }
//}

void load_individual_mesh(struct ScAsset *asset, const struct aiMesh *mesh, float *vertex_data, uint32_t *index_data)
{
    for_loop(i, mesh->mNumVertices)
    {
        vertex_data[i * 9 + 0] = mesh->mVertices[i].x;
        vertex_data[i * 9 + 1] = mesh->mVertices[i].y;
        vertex_data[i * 9 + 2] = mesh->mVertices[i].z;
        if (mesh->mNormals != NULL)
        {
            vertex_data[i * 9 + 3] = mesh->mNormals[i].x;
            vertex_data[i * 9 + 4] = mesh->mNormals[i].y;
            vertex_data[i * 9 + 5] = mesh->mNormals[i].z;
        }
        else
        {
            vertex_data[i * 9 + 3] = 1.0f;
            vertex_data[i * 9 + 4] = 0.0f;
            vertex_data[i * 9 + 5] = 0.0f;
        }
        if (mesh->mColors[0] != NULL)
        {
            vertex_data[i * 9 + 6] = mesh->mColors[0][i].r;
            vertex_data[i * 9 + 7] = mesh->mColors[0][i].g;
            vertex_data[i * 9 + 8] = mesh->mColors[0][i].b;
        }
        else
        {
            vertex_data[i * 9 + 6] = 1.0f;
            vertex_data[i * 9 + 7] = 1.0f;
            vertex_data[i * 9 + 8] = 1.0f;
        }
    }
    for_loop(i, mesh->mNumFaces)
    {
        if (mesh->mFaces[i].mNumIndices != 3)
        {
            log_error("polygons are not triangular");
            continue;
        }
        index_data[i * 3 + 0] = mesh->mFaces[i].mIndices[0];
        index_data[i * 3 + 1] = mesh->mFaces[i].mIndices[1];
        index_data[i * 3 + 2] = mesh->mFaces[i].mIndices[2];
    }
}

struct ScAsset *sc_load_asset(const char *filename)
{
    log_info("Asset %s loading...", filename);
    ram_alloc_init(struct ScAsset, asset);

    const struct aiScene *scene = aiImportFile(filename, aiProcess_Triangulate | aiProcess_GenNormals | aiProcess_OptimizeMeshes | aiProcess_JoinIdenticalVertices);
    if (scene == NULL) log_error("failed to load file %s", filename);

    asset->mesh_names = list_create(char_ptr, (size_t)scene->mNumMeshes);
    asset->vertex_byte_size_per_mesh = list_create(size_t, (size_t)scene->mNumMeshes);
    asset->index_count_per_mesh = list_create(size_t, (size_t)scene->mNumMeshes);
    for_list(i, asset->mesh_names)
    {
        register size_t length = (size_t)scene->mMeshes[0]->mName.length;
        asset->mesh_names.data[i] = ram_malloc(length);
        memcpy(asset->mesh_names.data[i], scene->mMeshes[i]->mName.data, length);
    }

    {
        size_t float_count = 0;
        size_t uint32_t_count = 0;
        for_loop(i, scene->mNumMeshes)
        {
            size_t current_float_count = scene->mMeshes[i]->mNumVertices * 3 * 3; // 3 float per vertex + 3 float per normal + 3 float per color
            size_t current_uint32_t_count = scene->mMeshes[i]->mNumFaces * 3; // assuming triangles
            asset->vertex_byte_size_per_mesh.data[i] = current_float_count * sizeof(float);
            asset->index_count_per_mesh.data[i] = current_uint32_t_count;
            float_count += current_float_count;
            uint32_t_count += current_uint32_t_count;
        }
        asset->vertices = list_create(float, float_count);
        asset->indices = list_create(uint32_t, uint32_t_count);
    }

    {
        size_t current_vertex_pos = 0;
        size_t current_index_pos = 0;
        for_loop(i, scene->mNumMeshes)
        {
            float *mesh_vertex_data = &asset->vertices.data[current_vertex_pos];
            uint32_t *mesh_index_data = &asset->indices.data[current_index_pos];
            current_vertex_pos += (size_t)(asset->vertex_byte_size_per_mesh.data[i] / sizeof(float));
            current_index_pos += asset->index_count_per_mesh.data[i];
            load_individual_mesh(asset, scene->mMeshes[i], mesh_vertex_data, mesh_index_data);
        }
    }

    //log_debug("num meshes %d", scene->mNumMeshes);
    //log_debug("num animations %d", scene->mNumAnimations);
    //log_debug("root node name %s", scene->mRootNode->mName.data);
    //parse_node(scene->mRootNode);
    //for_loop(i, scene->mNumMeshes) log_debug("mesh name %s %d", scene->mMeshes[i]->mName.data, scene->mMeshes[i]->mNumBones);
    ///*for_loop(i, scene->mNumAnimations)
    //{
    //    log_debug("anim name %s", scene->mAnimations[i]->mName.data);
    //    for_loop(j, scene->mAnimations[i]->mNumChannels)
    //    {
    //        log_debug("channel name %s num rot %d", scene->mAnimations[i]->mChannels[j]->mNodeName.data, scene->mAnimations[i]->mChannels[j]->mNumRotationKeys);
    //    }
    //}*/
    aiReleaseImport(scene);
    log_info("Asset %s loaded successfully", filename);
    return asset; // temp
}

void sc_release_asset(struct ScAsset *asset)
{
    list_uint32_t_destroy(&asset->indices);
    list_float_destroy(&asset->vertices);
    list_size_t_destroy(&asset->index_count_per_mesh);
    list_size_t_destroy(&asset->vertex_byte_size_per_mesh);
    for_list(i, asset->mesh_names)
    {
        ram_free(asset->mesh_names.data[i]);
    }
    list_char_ptr_destroy(&asset->mesh_names);
    ram_free(asset);
}

size_t sc_asset_get_mesh_count(struct ScAsset *asset)
{
    return asset->mesh_names.size;
}

size_t sc_asset_get_mesh_id(struct ScAsset *asset, const char *mesh_name)
{
    for_list(i, asset->mesh_names)
    {
        if (strcmp(mesh_name, asset->mesh_names.data[i]) == 0) return i;
    }
    return SIZE_MAX;
}

const char *sc_asset_get_mesh_name(struct ScAsset *asset, size_t mesh_id)
{
    assert(mesh_id < asset->mesh_names.size);
    return asset->mesh_names.data[mesh_id];
}

struct ScMeshPack *sc_create_mesh_pack_from_asset(struct ScCore *core, struct ScPipeline *pipeline, struct ScAsset *asset, const size_t *max_instance_per_mesh)
{
    struct ScMeshPackInfo pack_info = {0};
    pack_info.mesh_count = asset->mesh_names.size;
    if (pack_info.mesh_count == 0) return NULL;
    pack_info.vertex_data = asset->vertices.data;
    pack_info.index_data = asset->indices.data;
    pack_info.vertex_byte_size_per_mesh = asset->vertex_byte_size_per_mesh.data;
    pack_info.index_count_per_mesh = asset->index_count_per_mesh.data;
    pack_info.max_instance_per_mesh = (size_t*)max_instance_per_mesh; // "const" removed to avoid compiler warnings
    return sc_create_mesh_pack(core, pipeline, &pack_info);
}
