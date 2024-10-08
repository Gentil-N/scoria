#ifndef __SC_H__
#define __SC_H__

#include <stdint.h>

#ifdef __linux__
#include <X11/Xlib.h>
#include <X11/X.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*
* MATH
*/

struct ScMat4f
{
    union
    {
        struct
        {
            float   m00, m01, m02, m03, // col #0
                    m10, m11, m12, m13, // col #1
                    m20, m21, m22, m23, // col #2
                    m30, m31, m32, m33; // col #3
        };
        float m[16];
    };
};

struct ScVec2f
{
    union
    {
        struct  { float x, y; };
        float v[2];
    };
};

struct ScVec3f
{
    union
    {
        struct { float x, y, z; };
        float v[3];
    };
};

struct ScVec4f
{
    union
    {
        struct { float x, y, z, w; };
        float v[4];
    };
};

struct ScColor4f
{
    union
    {
        struct { float r, g, b, a; };
        float c[4];
    };
};

struct ScQuatf
{
    union
    {
        struct { float w, x, y, z; };
        float q[4];
    };
};

static inline void sc_vec4f_set_zero(struct ScVec4f *vec)
{
    vec->x = vec->y = vec->z = vec->w = 0.0f;
}

static inline struct  ScVec4f sc_vec4f_zero()
{
    return (struct ScVec4f){0.0f, 0.0f, 0.0f, 0.0f};
}

static inline struct ScMat4f *sc_mat4f_set_zero(struct ScMat4f *mat)
{
    mat->m00 = mat->m01 = mat->m02 = mat->m03 = 0.0f;
    mat->m10 = mat->m11 = mat->m12 = mat->m13 = 0.0f;
    mat->m20 = mat->m21 = mat->m22 = mat->m23 = 0.0f;
    mat->m30 = mat->m31 = mat->m32 = mat->m33 = 0.0f;
    return mat;
}

static inline struct ScMat4f *sc_mat4f_set_identity(struct ScMat4f *mat)
{
    mat->m01 = mat->m02 = mat->m03 = 0.0f;
    mat->m10 = mat->m12 = mat->m13 = 0.0f;
    mat->m20 = mat->m21 = mat->m23 = 0.0f;
    mat->m30 = mat->m31 = mat->m32 = 0.0f;
    mat->m00 = mat->m11 = mat->m22 = mat->m33 = 1.0;
    return mat;
}

static inline struct ScMat4f sc_mat4f_identity()
{
    struct ScMat4f mat;
    sc_mat4f_set_identity(&mat);
    return mat;
}

static inline struct ScMat4f sc_mat4f_zero()
{
    return (struct ScMat4f){0};
}

void sc_mat4f_set_perspective(struct ScMat4f *mat, float aspect_ratio, float fov, float near_plane, float far_plane);

void sc_mat4f_set_mul(const struct ScMat4f *mat_a, const struct ScMat4f *mat_b, struct ScMat4f *mat_res);

static inline struct ScMat4f sc_mat4f_mul(const struct ScMat4f *mat_a, const struct ScMat4f *mat_b)
{
    struct ScMat4f mat;
    sc_mat4f_set_mul(mat_a, mat_b, &mat);
    return mat;
}

struct ScMat4f *sc_mat4f_set_rot_x(struct ScMat4f *mat, float alpha);

struct ScMat4f *sc_mat4f_set_rot_y(struct ScMat4f *mat, float alpha);

struct ScMat4f *sc_mat4f_set_rot_z(struct ScMat4f *mat, float alpha);

struct ScMat4f *sc_mat4f_rot_x(struct ScMat4f *mat, float alpha);

struct ScMat4f *sc_mat4f_rot_y(struct ScMat4f *mat, float alpha);

struct ScMat4f *sc_mat4f_rot_z(struct ScMat4f *mat, float alpha);

struct ScMat4f *sc_mat4f_rot_x_ahead(struct ScMat4f *mat, float alpha);

struct ScMat4f *sc_mat4f_rot_y_ahead(struct ScMat4f *mat, float alpha);

struct ScMat4f *sc_mat4f_rot_z_ahead(struct ScMat4f *mat, float alpha);

struct ScMat4f *sc_mat4f_set_translation(struct ScMat4f *mat, float x, float y, float z);

struct ScMat4f *sc_mat4f_translate(struct ScMat4f *mat, float x, float y, float z);

struct ScMat4f *sc_mat4f_translate_ahead(struct ScMat4f *mat, float x, float y, float z);

struct ScMat4f *sc_mat4f_set_scaling(struct ScMat4f *mat, float x, float y, float z);

struct ScQuatf *sc_quatf_interpolate(struct ScQuatf *quat_out, const struct ScQuatf *quat_start, const struct ScQuatf *quat_end, float factor);

struct ScMat4f *sc_quatf_to_mat4f(const struct ScQuatf *quat, struct ScMat4f *mat);

/*
*   BASE
*/

struct ScCore;
struct ScPipeline;
struct ScMeshPack;
struct ScItem;
struct ScPointLight;

struct ScCoreInfo
{
    unsigned int window_width;
    unsigned int window_height;
    struct
    {
#ifdef __linux__
        Display* dpy;
        Window window;
        VisualID visual_id;
#endif // __linux__
    } os_specific;
};

struct ScPipeline3dInfo
{
    size_t max_point_light;
};

struct ScMeshPackInfo
{
    size_t mesh_count;
    const void *vertex_data;
    const uint32_t *index_data;
    size_t *vertex_byte_size_per_mesh;
    size_t *index_count_per_mesh;
    size_t *max_instance_per_mesh;
};

struct ScSunLightData
{
    struct ScColor4f color;
    struct ScVec4f direction;
};

struct ScPointLightData
{
    struct ScVec4f position;
    struct ScColor4f color;
    struct ScVec4f power;
};

struct ScAmbientLightData
{
    struct ScColor4f color;
};

enum ScLogLevel
{
    SC_LOG_LEVEL_INFO = 1,
    SC_LOG_LEVEL_DEBUG = 2,
    SC_LOG_LEVEL_WARN = 3,
    SC_LOG_LEVEL_ERROR = 4,
};

struct ScItemData
{
    struct ScMat4f transform;
};

struct ScCameraData
{
    struct ScMat4f view_proj;
};

typedef void (*sc_log_callback_fn)(int level, int code, const char *file, int line, const char *msg);

int sc_set_log_callback(sc_log_callback_fn fn);

struct ScCore *sc_init_core(const struct ScCoreInfo *core_info);

void sc_end_core(struct ScCore *core);

void sc_update_core(struct ScCore *core);

struct ScPipeline *sc_create_pipeline_3d(struct ScCore *core, const struct ScPipeline3dInfo *pipeline_info);

void sc_destroy_pipeline_3d(struct ScPipeline *pipeline);

void sc_attach_pipeline(struct ScCore *core, struct ScPipeline *pipeline);

void sc_detach_pipeline(struct ScCore *core, struct ScPipeline *pipeline);

void sc_pipeline_3d_set_camera_data(struct ScPipeline *pipeline, const struct ScCameraData *camera_data);

struct ScPointLight *sc_pipeline_3d_create_point_light(struct ScPipeline *pipeline, const struct ScPointLightData *light_data);

void sc_pipeline_3d_destroy_point_light(struct ScPipeline *pipeline, struct ScPointLight *light);

void sc_point_light_set_data(struct ScPointLight *light, const struct ScPointLightData *light_data);

void sc_pipeline_3d_set_ambient_light(struct ScPipeline *pipeline, struct ScAmbientLightData *light_data);

void sc_pipeline_3d_set_sun_light(struct ScPipeline *pipeline, struct ScSunLightData *sun_light);

struct ScMeshPack *sc_create_mesh_pack(struct ScCore *core, struct ScPipeline *pipeline, const struct ScMeshPackInfo *mesh_pack_info);

void sc_destroy_mesh_pack(struct ScMeshPack *mesh_pack);

struct ScItem *sc_mesh_pack_create_item(struct ScMeshPack *mesh_pack, size_t mesh_id, const struct ScItemData *item_data);

void sc_mesh_pack_destroy_item(struct ScMeshPack *mesh_pack, struct ScItem *item);

void sc_item_set_data(struct ScItem *item, const struct ScItemData *item_data);

/*
* ASSET
*/

struct ScAsset;
struct ScNode;
struct ScItemPack;

struct ScAsset *sc_load_asset(const char *filename);

void sc_release_asset(struct ScAsset *asset);

size_t sc_asset_get_mesh_count(struct ScAsset *asset);

size_t sc_asset_get_mesh_id(struct ScAsset *asset, const char *mesh_name);

const char *sc_asset_get_mesh_name(struct ScAsset *asset, size_t mesh_id);

const struct ScNode *sc_asset_get_root_node(struct ScAsset *asset);

const struct ScNode *sc_node_find_node_by_name_iter(const struct ScNode *node, const char *name);

size_t sc_node_get_child_count(const struct ScNode *node);

const struct ScNode *sc_node_get_child(const struct ScNode *node, size_t child_node_id);

//size_t sc_node_get_mesh_count(const struct ScNode *node);

//size_t sc_node_get_mesh_count_iter(const struct ScNode *node);

size_t sc_node_get_animation_count(const struct ScNode *node);

size_t sc_node_get_animation_id(const struct ScNode *node, const char *animation_name);

const char *sc_node_get_animation_name(const struct ScNode *node, size_t animation_id);

struct ScMeshPack *sc_create_mesh_pack_from_asset(struct ScCore *core, struct ScPipeline *pipeline, struct ScAsset *asset, const size_t *max_instance_per_mesh);

/// 'ScItemPack' is basically a list of items with size 'sc_node_get_mesh_count_iter'
struct ScItemPack *sc_mesh_pack_create_item_pack_from_node(struct ScMeshPack *mesh_pack, const struct ScNode *node);

void sc_mesh_pack_destroy_item_pack(struct ScMeshPack *mesh_pack, struct ScItemPack *item_pack);

void sc_item_pack_set_data(struct ScItemPack *item_pack, const struct ScItemData *item_datas);

void sc_item_pack_set_data_separate(struct ScItemPack *item_pack, const struct ScItemData **item_datas);

size_t sc_item_pack_get_item_count(const struct ScItemPack *item_pack);

/// 'transforms' must have the size given by 'sc_node_get_mesh_count_iter'
void sc_node_bake_animation_separate(const struct ScNode *node, size_t animation_id, float frame, struct ScMat4f **transforms, const struct ScMat4f *parent_transform);

void sc_node_bake_animation(const struct ScNode *node, size_t animation_id, float frame, struct ScMat4f *transforms, const struct ScMat4f *parent_transform);

#ifdef __cplusplus
}
#endif

#endif // __SC_H__
