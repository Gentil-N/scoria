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
    vec4 ambient_light; // vec3 ambient_color, pad
    vec4 sun_light_color; // vec3 sun_color, pad
    vec4 sun_light_direction; // vec3 sun_light_direction, pad
    vec4 lights_count; // point_light_count, spot_light_count, sun_light_count, pad
    PointLight point_lights[MAX_LIGHT];
    //SpotLight spot_lights[MAX_LIGHT];
    //SunLight sun_lights[MAX_LIGHT];
} world;

vec3 calc_sun_light(vec4 sun_light_color, vec4 sun_light_direction, vec3 normal, vec3 albedo)
{
    float diff = max(dot(normal, normalize(sun_light_direction.xyz)), 0.0);
    vec3 diffuse = diff * sun_light_color.rgb;
    return diffuse * albedo;
}

vec3 calc_point_light(PointLight point_light, vec3 position, vec3 normal, vec3 albedo)
{
    vec3 light_direction = point_light.position.xyz - position;
    float distance = length(light_direction);
    float diff = max(dot(normal, normalize(light_direction)), 0.0);
    vec3 diffuse = diff * point_light.color.rgb * point_light.power_x_3pad.x / (distance * distance);
    return diffuse * albedo;
}

void main()
{
    // Get G-Buffer values
    vec3 position = texture(sampler_position, frag_uv).rgb;
    vec3 normal = texture(sampler_normal, frag_uv).rgb;
    vec3 albedo = texture(sampler_albedo, frag_uv).rgb;

    //vec3 ambient = vec3(1.0, 1.0, 1.0); // temp
    vec3 result = vec3(albedo.r * world.ambient_light.r, albedo.g * world.ambient_light.g, albedo.b * world.ambient_light.b);
    // Sun light
    result += calc_sun_light(world.sun_light_color, world.sun_light_direction, normal, albedo);
    // Point lights
    int point_light_count = int(round(world.lights_count.x));
    for (int i = 0; i < point_light_count; ++i)
    {
        result += calc_point_light(world.point_lights[i], position, normal, albedo);
    }

    out_color = vec4(result, 1.0);
}
