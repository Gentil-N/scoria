#include "common.h"
#include "cutils_base.h"
#include "log.h"

#include <assimp/cimport.h>
#include <assimp/matrix4x4.h>
#include <assimp/mesh.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/anim.h>
#include <assimp/types.h>
#include <float.h>
#include <string.h>

char *aiStringCopy(const struct aiString *ai_str)
{
    char *copy = ram_malloc(ai_str->length);
    memcpy(copy, ai_str->data, ai_str->length);
    copy[ai_str->length] = '\0';
    return copy;
}

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

size_t find_mesh_id(const struct List_char_ptr *mesh_names, const char *mesh_name)
{
    for_list(i, (*mesh_names))
    {
        if (strcmp(mesh_name, mesh_names->data[i]) == 0) return i;
    }
    return SIZE_MAX;
}

void aiMatrix4x4ToScMat4f(const struct aiMatrix4x4 *ai_matrix, struct ScMat4f *mat)
{
    mat->m00 = ai_matrix->a1;
    mat->m01 = ai_matrix->b1;
    mat->m02 = ai_matrix->c1;
    mat->m03 = ai_matrix->d1;

    mat->m10 = ai_matrix->a2;
    mat->m11 = ai_matrix->b2;
    mat->m12 = ai_matrix->c2;
    mat->m13 = ai_matrix->d2;

    mat->m20 = ai_matrix->a3;
    mat->m21 = ai_matrix->b3;
    mat->m22 = ai_matrix->c3;
    mat->m23 = ai_matrix->d3;

    mat->m30 = ai_matrix->a4;
    mat->m31 = ai_matrix->b4;
    mat->m32 = ai_matrix->c4;
    mat->m33 = ai_matrix->d4;
}

struct ScNode *create_node(struct ScNode *parent, const struct aiNode *ainode)
{
    ram_alloc_init(struct ScNode, node);

    node->name = aiStringCopy(&ainode->mName);

    node->parent = parent;
    aiMatrix4x4ToScMat4f(&ainode->mTransformation, &node->base_transform);
    node->mesh_ids = list_create(size_t, ainode->mNumMeshes);
    for_list(i, node->mesh_ids)
    {
        node->mesh_ids.data[i] = ainode->mMeshes[i];
    }
    node->animations = list_create(ScAnimation, 0);
    node->children = list_create(ScNode_ptr, ainode->mNumChildren);
    for_list(i, node->children)
    {
        node->children.data[i] = create_node(node, ainode->mChildren[i]);
    }

    return node;
}

struct ScNode *find_node(struct ScNode *node, const char *name)
{
    if (strcmp(node->name, name) == 0) return node;
    for_list(i, node->children)
    {
        struct ScNode *subnode = find_node(node->children.data[i], name);
        if (subnode != NULL) return subnode;
    }
    return NULL;
}

const struct ScNode *find_node_const(const struct ScNode *node, const char *name)
{
    if (strcmp(node->name, name) == 0) return node;
    for_list(i, node->children)
    {
        struct ScNode *subnode = find_node(node->children.data[i], name);
        if (subnode != NULL) return subnode;
    }
    return NULL;
}

void load_individual_channel(struct ScNode *node, const struct aiNodeAnim *node_anim, const struct aiString *animation_name, float duration)
{
    struct ScAnimation animation = {0};
    animation.name = aiStringCopy(animation_name);
    animation.duration = duration;
    animation.static_anim = false;
    animation.keys = list_create(AnimKey, 0);

    size_t pos_key_index = 0, rot_key_index = 0, scl_key_index = 0;
    bool pos_cond = pos_key_index < node_anim->mNumPositionKeys, rot_cond = rot_key_index < node_anim->mNumRotationKeys, scl_cond = scl_key_index < node_anim->mNumScalingKeys;
    struct ScVec3f temp_pos = {0};
    struct ScVec3f temp_scl = {0};
    struct ScQuatf temp_rot = {0};
    while(pos_cond || rot_cond || scl_cond)
    {
        double keytime = DBL_MAX;
        if (pos_cond) keytime = min(keytime, node_anim->mPositionKeys[pos_key_index].mTime);
        if (rot_cond) keytime = min(keytime, node_anim->mRotationKeys[rot_key_index].mTime);
        if (scl_cond) keytime = min(keytime, node_anim->mScalingKeys[scl_key_index].mTime);

        struct AnimKey anim_key = {0};
        anim_key.keytime = (float)keytime;
        log_debug("KEY TIME: %f", keytime);
        if (pos_cond && node_anim->mPositionKeys[pos_key_index].mTime == keytime)
        {
            temp_pos.x = node_anim->mPositionKeys[pos_key_index].mValue.x;
            temp_pos.y = node_anim->mPositionKeys[pos_key_index].mValue.y;
            temp_pos.z = node_anim->mPositionKeys[pos_key_index].mValue.z;
            pos_key_index += 1;
        }
        if (rot_cond && node_anim->mRotationKeys[rot_key_index].mTime == keytime)
        {
            temp_rot.w = node_anim->mRotationKeys[rot_key_index].mValue.w;
            temp_rot.x = node_anim->mRotationKeys[rot_key_index].mValue.x;
            temp_rot.y = node_anim->mRotationKeys[rot_key_index].mValue.y;
            temp_rot.z = node_anim->mRotationKeys[rot_key_index].mValue.z;
            rot_key_index += 1;
        }
        if (scl_cond && node_anim->mScalingKeys[scl_key_index].mTime == keytime)
        {
            temp_scl.x = node_anim->mScalingKeys[scl_key_index].mValue.x;
            temp_scl.y = node_anim->mScalingKeys[scl_key_index].mValue.y;
            temp_scl.z = node_anim->mScalingKeys[scl_key_index].mValue.z;
            scl_key_index += 1;
        }

        anim_key.position.x = temp_pos.x;
        anim_key.position.y = temp_pos.y;
        anim_key.position.z = temp_pos.z;

        log_debug("POS: %f %f %f", anim_key.position.x, anim_key.position.y, anim_key.position.z);

        anim_key.rotation.w = temp_rot.w;
        anim_key.rotation.x = temp_rot.x;
        anim_key.rotation.y = temp_rot.y;
        anim_key.rotation.z = temp_rot.z;

        log_debug("ROT: %f %f %f %f", anim_key.rotation.w, anim_key.rotation.x, anim_key.rotation.y, anim_key.rotation.z);

        anim_key.scale.x = temp_scl.x;
        anim_key.scale.y = temp_scl.y;
        anim_key.scale.z = temp_scl.z;

        log_debug("SCL: %f %f %f", anim_key.scale.x, anim_key.scale.y, anim_key.scale.z);

        pos_cond = pos_key_index < node_anim->mNumPositionKeys;
        rot_cond = rot_key_index < node_anim->mNumRotationKeys;
        scl_cond = scl_key_index < node_anim->mNumScalingKeys;
        list_AnimKey_append(&animation.keys, &anim_key);
    }
    list_ScAnimation_append(&node->animations, &animation);
}

void complete_animation(struct ScNode *current, size_t anim_id, const struct aiString *anim_name, float duration)
{
    if (current->animations.size <= anim_id)
    {
        struct ScAnimation animation = {0};
        animation.name = aiStringCopy(anim_name);
        animation.duration = duration;
        animation.static_anim = true;
        list_ScAnimation_append(&current->animations, &animation);
    }
    for_list(i, current->children)
    {
        complete_animation(current->children.data[i], anim_id, anim_name, duration);
    }
}

void load_individual_animation(struct aiAnimation *animation, struct ScNode *root_node, size_t animation_id)
{
    for_loop(i, animation->mNumChannels)
    {
        struct ScNode *node = find_node(root_node, animation->mChannels[i]->mNodeName.data);
        assert(node != NULL);
        load_individual_channel(node, animation->mChannels[i], &animation->mName, (float)animation->mDuration);
    }
    complete_animation(root_node, animation_id, &animation->mName, (float)animation->mDuration);
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
        asset->mesh_names.data[i] = aiStringCopy(&scene->mMeshes[i]->mName);
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

    asset->root_node = create_node(NULL, scene->mRootNode);

    for_loop(i, scene->mNumAnimations)
    {
        load_individual_animation(scene->mAnimations[i], asset->root_node, i);
    }

    aiReleaseImport(scene);
    log_info("Loaded successfully!");
    return asset;
}

void release_animation(struct ScAnimation *animation)
{
    list_AnimKey_destroy(&animation->keys);
    ram_free(animation->name);
}

void release_node(struct ScNode *node)
{
    for_list(i, node->children)
    {
        release_node(node->children.data[i]);
    }
    list_ScNode_ptr_destroy(&node->children);
    for_list(i, node->animations)
    {
        release_animation(&node->animations.data[i]);
    }
    list_ScAnimation_destroy(&node->animations);
    list_size_t_destroy(&node->mesh_ids);
    ram_free(node->name);
    ram_free(node);
}

void sc_release_asset(struct ScAsset *asset)
{
    release_node(asset->root_node);
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
    return find_mesh_id(&asset->mesh_names, mesh_name);
}

const char *sc_asset_get_mesh_name(struct ScAsset *asset, size_t mesh_id)
{
    assert(mesh_id < asset->mesh_names.size);
    return asset->mesh_names.data[mesh_id];
}

const struct ScNode *sc_asset_get_root_node(struct ScAsset *asset)
{
    return asset->root_node;
}

const struct ScNode *sc_node_find_node_by_name_iter(const struct ScNode *node, const char *name)
{
    return find_node_const(node, name);
}

size_t sc_node_get_child_count(const struct ScNode *node)
{
    return node->children.size;
}

const struct ScNode *sc_node_get_child(const struct ScNode *node, size_t child_node_id)
{
    assert(child_node_id < node->children.size);
    return node->children.data[child_node_id];
}

size_t sc_node_get_animation_count(const struct ScNode *node)
{
    return node->animations.size;
}

size_t sc_node_get_animation_id(const struct ScNode *node, const char *animation_name)
{
    for_list(i, node->animations)
    {
        if (strcmp(node->animations.data[i].name, animation_name)) return i;
    }
    return SIZE_MAX;
}

const char *sc_node_get_animation_name(const struct ScNode *node, size_t animation_id)
{
    assert(animation_id < node->animations.size);
    return node->animations.data[animation_id].name;
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

void fill_mesh_id_list(struct List_size_t *mesh_ids, const struct ScNode *node)
{
    for_list(i, node->mesh_ids)
    {
        list_size_t_append(mesh_ids, &node->mesh_ids.data[i]);
    }
    for_list(i, node->children)
    {
        fill_mesh_id_list(mesh_ids, node->children.data[i]);
    }
}

/// 'ScItemPack' is basically a list of items with size 'sc_node_get_mesh_count_iter'
struct ScItemPack *sc_mesh_pack_create_item_pack_from_node(struct ScMeshPack *mesh_pack, const struct ScNode *node)
{
    ram_alloc_init(struct ScItemPack, item_pack);
    struct List_size_t mesh_ids = list_create(size_t, 0);
    fill_mesh_id_list(&mesh_ids, node);
    item_pack->item_ptrs = list_create(ScItem_ptr, mesh_ids.size);
    for_list(i, item_pack->item_ptrs)
    {
        item_pack->item_ptrs.data[i] = sc_mesh_pack_create_item(mesh_pack, mesh_ids.data[i], NULL);
    }
    list_size_t_destroy(&mesh_ids);
    return item_pack;
}

void sc_mesh_pack_destroy_item_pack(struct ScMeshPack *mesh_pack, struct ScItemPack *item_pack)
{
    for_list(i, item_pack->item_ptrs)
    {
        sc_mesh_pack_destroy_item(mesh_pack, item_pack->item_ptrs.data[i]);
    }
    list_ScItem_ptr_destroy(&item_pack->item_ptrs);
    ram_free(item_pack);
}

void sc_item_pack_set_data_separate(struct ScItemPack *item_pack, const struct ScItemData **item_datas)
{
    for_list(i, item_pack->item_ptrs)
    {
        sc_item_set_data(item_pack->item_ptrs.data[i], item_datas[i]);
    }
}

void sc_item_pack_set_data(struct ScItemPack *item_pack, const struct ScItemData *item_datas)
{
    for_list(i, item_pack->item_ptrs)
    {
        sc_item_set_data(item_pack->item_ptrs.data[i], &item_datas[i]);
    }
}

size_t sc_item_pack_get_item_count(const struct ScItemPack *item_pack)
{
    return item_pack->item_ptrs.size;
}

struct ScMat4f get_transform_from_animation(const struct ScAnimation *animation, float frame, const struct ScMat4f *base_transform, const struct ScMat4f *parent_transform)
{
    AnimKey *start_key, *stop_key;
    float factor = 0.0f;

    if (animation->static_anim) return sc_mat4f_mul(parent_transform, base_transform);

    for_list(i, animation->keys)
    {
        log_debug("%f %f %f %f", animation->duration, animation->keys.data[i].keytime, animation->keys.data[i+1].keytime, frame);
        assert(i < animation->keys.size - 1); // usually, should be checked by animation's duration yet.
        if (frame <= animation->keys.data[i + 1].keytime && frame >= animation->keys.data[i].keytime)
        {
            start_key = &animation->keys.data[i];
            stop_key = &animation->keys.data[i + 1];
            factor = (frame - start_key->keytime) / (stop_key->keytime - start_key->keytime);
            break;
        }
    }
    struct ScVec3f interpolated_position = {0};
    interpolated_position.x = start_key->position.x + factor * (stop_key->position.x - start_key->position.x);
    interpolated_position.y = start_key->position.y + factor * (stop_key->position.y - start_key->position.y);
    interpolated_position.z = start_key->position.z + factor * (stop_key->position.z - start_key->position.z);
    struct ScVec3f interpolated_scale = {0};
    interpolated_scale.x = start_key->scale.x + factor * (stop_key->scale.x - start_key->scale.x);
    interpolated_scale.y = start_key->scale.y + factor * (stop_key->scale.y - start_key->scale.y);
    interpolated_scale.z = start_key->scale.z + factor * (stop_key->scale.z - start_key->scale.z);
    struct ScQuatf interpolated_quat = {0};
    sc_quatf_interpolate(&interpolated_quat, &start_key->rotation, &stop_key->rotation, factor);
    struct ScMat4f transform = sc_mat4f_identity();
    sc_mat4f_set_scaling(&transform, interpolated_scale.x, interpolated_scale.y, interpolated_scale.z);
    struct ScMat4f quat_mat = {0};
    sc_quatf_to_mat4f(&interpolated_quat, &quat_mat);
    transform = sc_mat4f_mul(&quat_mat, &transform);
    sc_mat4f_translate_ahead(&transform, interpolated_position.x, interpolated_position.y, interpolated_position.z);
    log_debug("%f %f %f", interpolated_scale.x, interpolated_scale.y, interpolated_scale.z);

    transform = sc_mat4f_mul(parent_transform, &transform); // not sure about the order!

    return transform;
}

/// 'transforms' must have the size given by 'sc_node_get_mesh_count_iter'
void sc_node_bake_animation_separate(const struct ScNode *node, size_t animation_id, float frame, struct ScMat4f **transforms, const struct ScMat4f *parent_transform)
{
    assert(animation_id < node->animations.size);
    const struct ScAnimation *animation = &node->animations.data[animation_id];
    assert(frame < animation->duration);
    //struct ScMat4f transform = get_transform_from_animation(animation, frame, &node->base_transform, &parent_transform);
    struct ScMat4f transform = sc_mat4f_mul(&node->base_transform, parent_transform);
    for_list(i, node->mesh_ids)
    {
        (*transforms[i]) = transform;
    }
    for_list(i, node->children)
    {
        sc_node_bake_animation_separate(node->children.data[i], animation_id, frame, &transforms[node->mesh_ids.size], &transform);
    }
}

size_t internal_node_bake_animation(const struct ScNode *node, size_t animation_id, float frame, struct ScMat4f *transforms, const struct ScMat4f *parent_transform)
{
    assert(animation_id < node->animations.size);
    const struct ScAnimation *animation = &node->animations.data[animation_id];
    assert(frame < animation->duration);
    struct ScMat4f transform = get_transform_from_animation(animation, frame, &node->base_transform, parent_transform);
    //struct ScMat4f transform = sc_mat4f_mul(parent_transform, &node->base_transform);
    for_list(i, node->mesh_ids)
    {
        /*transforms[i] = sc_mat4f_identity();
        log_debug("set transform %s %d", node->name, node->mesh_ids.data[i]);
        sc_mat4f_translate(&transforms[i], 0.0f, 0.0f, 4.0f * node->mesh_ids.data[i]);*/
        transforms[i] = transform;
    }
    size_t num_processed_meshes = node->mesh_ids.size;
    for_list(i, node->children)
    {
        log_debug("child of %s %d %d", node->name, i, node->mesh_ids.size);
        size_t shift_num_processed_meshes = internal_node_bake_animation(node->children.data[i], animation_id, frame, &transforms[num_processed_meshes], &transform);
        num_processed_meshes += shift_num_processed_meshes;
    }
    return num_processed_meshes;
}

void sc_node_bake_animation(const struct ScNode *node, size_t animation_id, float frame, struct ScMat4f *transforms, const struct ScMat4f *parent_transform)
{
    internal_node_bake_animation(node, animation_id, frame, transforms, parent_transform);
}
