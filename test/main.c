#include <assert.h>
#include <math.h>
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
#include "cutils_math.h"

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

float scroll = 0.0f;

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    scroll += (float)xoffset + (float)yoffset;
}

#define fatal(...) {printf(__VA_ARGS__); exit(1);}
#define min(x, y) (((x) < (y)) ? (x) : (y))
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define clamp(x, low, up) min((up), max((x), (low)))

int main()
{
    printf("Program starting...\n");
    if (sc_set_log_callback(log_callback_fn) != 0) return 1;

    if (glfwInit() == GLFW_FALSE) fatal("failed to init glfw");
    const int width = 1600, height = 900;
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow *window = glfwCreateWindow(width, height, "Test", NULL, NULL);

    struct ScCoreInfo core_info = {0};
    core_info.window_width = width;
    core_info.window_height = height;
#ifdef __linux__
    core_info.os_specific.window = glfwGetX11Window(window);
    core_info.os_specific.dpy = glfwGetX11Display();
    core_info.os_specific.visual_id = XVisualIDFromVisual(DefaultVisual(core_info.os_specific.dpy, DefaultScreen(core_info.os_specific.dpy)));
#endif // __linux__
    struct ScCore *core = sc_init_core(&core_info);
    struct ScPipeline3dInfo pipeline_info = {0};
    pipeline_info.max_point_light = 10;
    struct ScPipeline *pipeline = sc_create_pipeline_3d(core, &pipeline_info);
    sc_attach_pipeline(core, pipeline);

    struct mat4f mat_id = mat4f_identity();
    struct mat4f mat_cam_perspective, mat_cam_view, mat_cam_total;
    mat4f_set_perspective(&mat_cam_perspective, (float)width / (float)height, 90.0f, 0.01f, 100.0f);
    mat4f_set_identity(&mat_cam_view);
    mat4f_set_mul(&mat_cam_perspective, &mat_cam_view, &mat_cam_total);
    sc_pipeline_3d_set_camera_data(pipeline, (const struct ScCameraData*)&mat_cam_total);
    struct ScAmbientLightData ambient_light = {0};
    ambient_light.color.r = 0.01f;
    ambient_light.color.g = 0.01f;
    ambient_light.color.b = 0.01f;
    sc_pipeline_3d_set_ambient_light(pipeline, &ambient_light);
    struct ScSunLightData sun_light_data = {0};
    sun_light_data.color.r = 0.0f;
    sun_light_data.color.g = 0.0f;
    sun_light_data.color.b = 0.0f;
    sun_light_data.direction.x = -10.0f;
    sun_light_data.direction.y = -10.0f;
    sun_light_data.direction.z = -10.0f;
    sc_pipeline_3d_set_sun_light(pipeline, &sun_light_data);
    struct ScPointLightData light_data_a = {0};
    light_data_a.color.r = 1.0f;
    light_data_a.color.g = 1.0f;
    light_data_a.color.b = 1.0f;
    light_data_a.position.x = 1.0f;
    light_data_a.position.y = -5.0f;
    light_data_a.position.z = 10.0f;
    light_data_a.power.v[0] = 100.0f;
    struct ScPointLight *light_a = sc_pipeline_3d_create_point_light(pipeline, &light_data_a);
    struct ScPointLightData light_data_b = {0};
    light_data_b.color.r = 0.0f;
    light_data_b.color.g = 0.0f;
    light_data_b.color.b = 1.0f;
    light_data_b.position.x = -10.0f;
    light_data_b.position.y = -5.0f;
    light_data_b.position.z = 0.0f;
    light_data_b.power.v[0] = 30.0f;
    struct ScPointLight *light_b = sc_pipeline_3d_create_point_light(pipeline, &light_data_b);

    struct ScAsset *asset = sc_load_asset("./res/anim-test.glb");
    for (size_t i = 0; i < sc_asset_get_mesh_count(asset); ++i)
    {
        printf("mesh name: %s\n", sc_asset_get_mesh_name(asset, i));
    }

    const struct ScNode *root_node = sc_asset_get_root_node(asset);
    for (size_t i = 0; i < sc_node_get_animation_count(root_node); ++i)
    {
        printf("%s\n", sc_node_get_animation_name(root_node, i));
    }

    size_t max_instance_per_mesh[] = {10, 10, 10, 10, 10};
    /*struct ScMeshPackInfo pack_info = {0};
    pack_info.mesh_count = 2;
    pack_info.vertex_data = vertices;
    pack_info.index_data = indices;
    pack_info.vertex_byte_size_per_mesh = vertex_byte_size_per_mesh;
    pack_info.index_count_per_mesh = index_count_per_mesh;
    pack_info.max_instance_per_mesh = max_instance_per_mesh;*/
    //struct ScMeshPack *pack = sc_create_mesh_pack(core,pipeline, &pack_info);
    struct ScMeshPack *pack = sc_create_mesh_pack_from_asset(core, pipeline, asset, max_instance_per_mesh);

    /*struct mat4f mat_a = mat4f_identity();
    mat4f_translate(&mat_a, 5.0f, 0.0f, 0.0f);
    struct mat4f mat_b = mat4f_identity();
    mat4f_translate(&mat_b, -5.0f, 0.0f, 0.0f);
    struct ScItem *item_a = sc_mesh_pack_create_item(pack, sc_asset_get_mesh_id(asset, "Sphere"), (const struct ScItemData*)mat_a.m);
    struct ScItem *item_b = sc_mesh_pack_create_item(pack, sc_asset_get_mesh_id(asset, "Cube"), (const struct ScItemData*)mat_b.m);*/

    struct ScItemPack *item_pack = sc_mesh_pack_create_item_pack_from_node(pack, root_node);
    size_t transform_count = sc_item_pack_get_item_count(item_pack);
    struct ScMat4f transforms[transform_count];
    struct ScMat4f identity = sc_mat4f_identity();
    /*for (size_t i = 0; i < transform_count; ++i)
    {
        transforms[i] = sc_mat4f_identity();
        sc_mat4f_translate(&transforms[i], 0, 0, i * 4);
    }*/
    sc_node_bake_animation(root_node, 0, 400.0f, transforms, &identity);
    sc_item_pack_set_data(item_pack, (const struct ScItemData*)transforms);

    glfwSetScrollCallback(window, scroll_callback);
    double cursor_xpos, cursor_ypos;
    glfwGetCursorPos(window, &cursor_xpos, &cursor_ypos);
    float roty = 0.0f, rotx = 0.0f;
    glfwShowWindow(window);

    float anim_evo = 42.0f;

    while(!glfwWindowShouldClose(window))
    {
        anim_evo += 5.0f;
        if (anim_evo >= 800.0f)
        {
            anim_evo = 42.0f;
        }
        light_data_a.color.g = light_data_a.color.b = anim_evo / 800.0f;
        sc_point_light_set_data(light_a, &light_data_a);

        sc_node_bake_animation(root_node, 0, anim_evo, transforms, &identity);
        sc_item_pack_set_data(item_pack, (const struct ScItemData*)transforms);

        /*if (translate > 30.0f && item_a != NULL)
        {
            sc_mesh_pack_destroy_item(pack, item_a);
            item_a = NULL;
            printf("item destroyed\n");
        }
        if (translate > 35.0f && item_a == NULL)
        {
            item_a = sc_mesh_pack_create_item(pack, 4, (const struct ScItemData*)&mat_a);
            printf("item created\n");
            translate = 0.0f;
        }
        if (item_a != NULL)
        {
            mat4f_set_identity(&mat_a);
            mat4f_translate(&mat_a, translate, 0.0f, 0.0f);
            sc_item_set_data(item_a, (const struct ScItemData*)&mat_a);
            }*/

        double new_cursor_xpos, new_cursor_ypos;
        glfwGetCursorPos(window, &new_cursor_xpos, &new_cursor_ypos);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
        {
            double cursor_xoffset = new_cursor_xpos - cursor_xpos, cursor_yoffset = new_cursor_ypos - cursor_ypos;
            roty += (float)cursor_xoffset / 300.0f;
            rotx -= (float)cursor_yoffset / 500.0f;
            roty = fmodf(roty, 2 * M_PI);
            rotx = clamp(rotx, -M_PI_2, M_PI_2);
        }
        cursor_xpos = new_cursor_xpos;
        cursor_ypos = new_cursor_ypos;
        if (scroll > 0.0f)
        {
            scroll = 0.0f;
        }

        mat4f_rot_y(mat4f_rot_x(mat4f_set_translation(&mat_cam_view, 0.0f, 0.0f, scroll), rotx), roty);
        mat4f_set_mul(&mat_cam_perspective, &mat_cam_view, &mat_cam_total);
        sc_pipeline_3d_set_camera_data(pipeline, (const struct ScCameraData*)&mat_cam_total);

        sc_update_core(core);
        glfwPollEvents();
    }

    sc_pipeline_3d_destroy_point_light(pipeline, light_b);
    sc_pipeline_3d_destroy_point_light(pipeline, light_a);
    sc_mesh_pack_destroy_item_pack(pack, item_pack);
    /*sc_mesh_pack_destroy_item(pack, item_b);
    if (item_a != NULL) sc_mesh_pack_destroy_item(pack, item_a);*/
    sc_destroy_mesh_pack(pack);
    sc_release_asset(asset);
    sc_detach_pipeline(core, pipeline);
    sc_destroy_pipeline_3d(pipeline);
    sc_end_core(core);
    glfwDestroyWindow(window);
    glfwTerminate();

    if (sc_set_log_callback(NULL) != 0) return 1;
    printf("Program ended succesfully!\n");
    return 0;
}
