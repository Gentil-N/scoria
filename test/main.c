#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xutil.h>
#include <GLFW/glfw3.h>
#ifdef __linux__
#define GLFW_EXPOSE_NATIVE_X11
#endif // __linux__
#include <GLFW/glfw3native.h>
#include <time.h>

#include "../include/scoria.h"

const char *color_code[] = {"", "", "\033[92m", "\033[93m", "\033[91m"};
const char *level_strings[] = {"", "INFO", "DEBUG", "WARN", "ERROR"};

void log_callback_fn(int level, int code, const char *file, int line, const char *msg)
{
    assert(level <= 4 && level >= 0);
    const char *file_name = strrchr(file, '/') ? strrchr(file, '/') + 1 : file;
    printf("%s[%s](%s - %d): %s\033[39m\n", color_code[level], level_strings[level], file_name, line, msg);
    if (level >= 4)
    {
        exit(1);
    }
}

#define fatal(...) {printf(__VA_ARGS__); exit(1);}

float mat_inst_1[] =
    {1.0f, 0.0f, 0.0f, 0.0f,
     0.0f, 1.0f, 0.0f, 0.0f,
     0.0f, 0.0f, 1.0f, 0.0f,
     5.0f, 5.0f, -5.0f, 1.0f};
float mat_inst_2[] =
    {1.0f, 0.0f, 0.0f, 0.0f,
     0.0f, 1.0f, 0.0f, 0.0f,
     0.0f, 0.0f, 1.0f, 0.0f,
     -5.0f, 5.0f, -5.0f, 1.0f};
float mat_inst_3[] =
    {1.0f, 0.0f, 0.0f, 0.0f,
     0.0f, 1.0f, 0.0f, 0.0f,
     0.0f, 0.0f, 1.0f, 0.0f,
     10.0f, -5.0f, -5.0f, 1.0f};
float mat_inst_4[] =
    {1.0f, 0.0f, 0.0f, 0.0f,
     0.0f, 1.0f, 0.0f, 0.0f,
     0.0f, 0.0f, 1.0f, 0.0f,
     -5.0f, -5.0f, -5.0f, 1.0f};
float mat_id[] =
    {1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f};

int main()
{
    printf("Program starting...\n");
    if (sc_set_log_callback(log_callback_fn) != 0) return 1;

    if (glfwInit() == GLFW_FALSE) fatal("failed to init glfw");
    const int width = 1600, height = 900;
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow *window = glfwCreateWindow(width, height, "NoName", NULL, NULL);

    struct ScCoreInfo core_info = {0};
    core_info.window_width = width;
    core_info.window_height = height;
#ifdef __linux__
    core_info.os_specific.window = glfwGetX11Window(window);
    core_info.os_specific.dpy = glfwGetX11Display();
    core_info.os_specific.visual_id = XVisualIDFromVisual(DefaultVisual(core_info.os_specific.dpy, DefaultScreen(core_info.os_specific.dpy)));
#endif // __linux__
    struct ScCore *core = sc_init_core(&core_info);
    struct ScPipeline *pipeline = sc_create_pipeline(core, SC_PIPELINE_TYPE_3D_DEFERRED);
    sc_attach_pipeline(core, pipeline);

    float vertices[] = {-0.25f, -0.25f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.25f, -0.25f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.25f, 0.25f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, -0.25f, 0.25f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f};
    uint32_t indices[] = {0, 1, 2, 2, 3, 0, 0, 1, 2};
    size_t vertex_byte_size_per_mesh[] = {sizeof(float) * 3 * 3 * 4, sizeof(float) * 3 * 3 * 3};
    size_t index_count_per_mesh[] = {6, 3};
    size_t max_instance_per_mesh[] = {10, 10};

    struct ScAsset *asset = sc_load_asset("./res/anim-test.glb");

    struct ScMeshPackInfo pack_info = {0};
    pack_info.mesh_count = 2;
    pack_info.vertex_data = vertices;
    pack_info.index_data = indices;
    pack_info.vertex_byte_size_per_mesh = vertex_byte_size_per_mesh;
    pack_info.index_count_per_mesh = index_count_per_mesh;
    pack_info.max_instance_per_mesh = max_instance_per_mesh;
    struct ScMeshPack *pack = sc_create_mesh_pack(core,pipeline, &pack_info);
    struct ScCameraData camera_data =
        {{1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f}};
    sc_pipeline_update_camera(pipeline, &camera_data);
    struct ScItemData item_data =
        {{1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f}};
    struct ScItem *item_a = sc_create_item(pack, 0, &item_data);
    struct ScItem *item_b = sc_create_item(pack, 1, &item_data);

    glfwShowWindow(window);
    while(!glfwWindowShouldClose(window))
    {
        sc_update_core(core);
        glfwPollEvents();
    }

    sc_destroy_item(pack, item_b);
    sc_destroy_item(pack, item_a);
    sc_destroy_mesh_pack(pack);
    sc_release_asset(asset);
    sc_detach_pipeline(core, pipeline);
    sc_destroy_pipeline(pipeline);
    sc_end_core(core);
    glfwDestroyWindow(window);
    glfwTerminate();

    if (sc_set_log_callback(NULL) != 0) return 1;
    printf("Program ended succesfully!\n");
    return 0;
}
