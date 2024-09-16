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
struct ScResourcePack;
struct ScObject;

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

struct ScResourcePackInfo
{
    size_t max_point_light;
    size_t max_instances;
};

struct ScCameraData
{
    float view_proj[16];
};

struct ScObjectData
{
    float transform[16];
};

struct ScPointLightData
{
    union
    {
        struct { float x, y, z, _w/*pad*/; } coords;
        float data[4];
    } position;
    union
    {
        struct { float r, g, b, _a/*pad*/; } comps;
        float data[4];
    } color;
    float power;
};

enum ScLogLevel
{
    SC_LOG_LEVEL_INFO = 1,
    SC_LOG_LEVEL_DEBUG = 2,
    SC_LOG_LEVEL_WARN = 3,
    SC_LOG_LEVEL_ERROR = 4,
};

enum ScPipelineType
{
    SC_PIPELINE_TYPE_3D_DEFERRED = 1,
    SC_PIPELINE_TYPE_2D_UI = 2
};

typedef void (*sc_log_callback_fn)(int level, int code, const char *file, int line, const char *msg);

int sc_set_log_callback(sc_log_callback_fn fn);

struct ScCore *sc_init_core(const struct ScCoreInfo *core_info);

void sc_end_core(struct ScCore *core);

void sc_update_core(struct ScCore *core);

struct ScResourcePack *sc_create_resource_pack(struct ScCore *core, const struct ScResourcePackInfo *resource_pack_info, size_t filename_count, const char **filenames);

void sc_destroy_resource_pack(struct ScResourcePack *resource_pack);

void sc_pipeline_update_camera(struct ScCore *core, struct ScCameraData *camera_data);

struct ScObject *sc_create_object(struct ScResourcePack *resource_pack, size_t resource_id, const struct ScObjectData *object_data);

void sc_destroy_object(struct ScObject *object);

#ifdef __cplusplus
}
#endif

#endif // __SC_H__
