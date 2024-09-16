#version 450

layout(binding = 0) uniform sampler2D sampler_position;
layout(binding = 1) uniform sampler2D sampler_normal;
layout(binding = 2) uniform sampler2D sampler_albedo;

layout(location = 0) in vec2 frag_uv;

layout(location = 0) out vec4 out_color;

struct PointLight {
    vec4 position;
    vec4 color;
    vec4 power_x_3pad;
};

/*struct SpotLight {
    vec4 position;
    vec4 color;
    vec4 direction;
    vec4 cone_angle_x_power_x_2pad;
};

struct SunLight {
    vec4 direction;
    vec4 color;
    vec4 power_x_3pad;
};*/

#define MAX_LIGHT 100

layout(binding = 3) uniform World {
    vec4 ambient_color_x_ambient_power_x_2pad; // vec3 ambient_color, float ambient_strength
    vec4 lights_count; // point_light_count, spot_light_count, sun_light_count, pad
    PointLight point_lights[MAX_LIGHT];
    //SpotLight spot_lights[MAX_LIGHT];
    //SunLight sun_lights[MAX_LIGHT];
} world;

void main()
{
    // Get G-Buffer values
    vec3 position = texture(sampler_position, frag_uv).rgb;
    vec3 normal = texture(sampler_normal, frag_uv).rgb;
    vec3 albedo = texture(sampler_albedo, frag_uv).rgb;

    //vec3 ambient = vec3(world.ambient_color_x_ambient_power_x_2pad.rgb) * world.ambient_color_x_ambient_power_x_2pad.a;
    vec3 ambient = vec3(1.0, 1.0, 1.0); // temp
    vec3 result = albedo;
    // Point lights
    //int point_light_count = int(round(world.lights_count.x));
    //for (int i = 0; i < point_light_count; ++i)
    //{
    //    vec3 light_dir = normalize(world.point_lights[i].position.xyz - position);
    //    float diff = max(dot(normal, light_dir), 0.0);
    //    vec3 diffuse = diff * world.point_lights[i].color.rgb;
    //    result += diffuse * albedo;
    //}

    out_color = vec4(result, 1.0);
}
