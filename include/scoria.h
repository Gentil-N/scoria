#ifndef __SC_H__
#define __SC_H__

#include <X11/X.h>
#include <stdint.h>

#ifdef __linux__
#include <X11/Xlib.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

struct ScCore;
struct ScPipeline;
struct ScMeshPack;
struct ScItem;
struct ScPointLight;
struct ScAsset;
struct ScAnimaton;

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

union ScGlslVec4f
{
    struct { float x, y, z, w; };
    struct { float r, g, b, a; };
    float data[4];
};

struct ScSunLightData
{
    union ScGlslVec4f color;
    union ScGlslVec4f direction;
};

struct ScPointLightData
{
    union ScGlslVec4f position;
    union ScGlslVec4f color;
    union ScGlslVec4f power;
};

struct ScAmbientLightData
{
    union ScGlslVec4f color;
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
    float transform[16];
};

struct ScCameraData
{
    float view_proj[16];
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

struct ScAsset *sc_load_asset(const char *filename);

void sc_release_asset(struct ScAsset *asset);

size_t sc_asset_get_mesh_count(struct ScAsset *asset);

size_t sc_asset_get_mesh_id(struct ScAsset *asset, const char *mesh_name);

const char *sc_asset_get_mesh_name(struct ScAsset *asset, size_t mesh_id);

struct ScMeshPack *sc_create_mesh_pack(struct ScCore *core, struct ScPipeline *pipeline, const struct ScMeshPackInfo *mesh_pack_info);

struct ScMeshPack *sc_create_mesh_pack_from_asset(struct ScCore *core, struct ScPipeline *pipeline, struct ScAsset *asset, const size_t *max_instance_per_mesh);

void sc_destroy_mesh_pack(struct ScMeshPack *mesh_pack);

struct ScItem *sc_mesh_pack_create_item(struct ScMeshPack *mesh_pack, size_t mesh_id, const struct ScItemData *item_data);

void sc_mesh_pack_destroy_item(struct ScMeshPack *mesh_pack, struct ScItem *item);

void sc_item_set_data(struct ScItem *item, const struct ScItemData *item_data);

#ifdef __cplusplus
}
#endif

#endif // __SC_H__
