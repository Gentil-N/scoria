#version 450

//Vertex attributes
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec3 in_normal;
layout(location = 2) in vec3 in_color;

// Instanced attributes
layout(location = 3) in vec4 inst_mat_col_0;
layout(location = 4) in vec4 inst_mat_col_1;
layout(location = 5) in vec4 inst_mat_col_2;
layout(location = 6) in vec4 inst_mat_col_3;

layout(location = 0) out vec3 frag_position;
layout(location = 1) out vec3 frag_normal;
layout(location = 2) out vec3 frag_color;

layout(binding = 0) uniform World {
    mat4 view_proj;
} world;

vec2 positions[3] = vec2[](
        vec2(0.0, -0.5),
        vec2(0.5, 0.5),
        vec2(-0.5, 0.5)
    );

vec3 colors[3] = vec3[](
        vec3(1.0, 0.0, 0.0),
        vec3(0.0, 1.0, 0.0),
        vec3(0.0, 0.0, 1.0)
    );

void main()
{
    mat4 transform;
    //transform[0] = vec4(inst_mat_col_0.x, inst_mat_col_1.x, inst_mat_col_2.x, inst_mat_col_3.x);
    //transform[1] = vec4(inst_mat_col_0.y, inst_mat_col_1.y, inst_mat_col_2.y, inst_mat_col_3.y);
    //transform[2] = vec4(inst_mat_col_0.z, inst_mat_col_1.z, inst_mat_col_2.z, inst_mat_col_3.z);
    //transform[3] = vec4(inst_mat_col_0.w, inst_mat_col_1.w, inst_mat_col_2.w, inst_mat_col_3.w);
    transform[0] = inst_mat_col_0;
    transform[1] = inst_mat_col_1;
    transform[2] = inst_mat_col_2;
    transform[3] = inst_mat_col_3;
    vec4 tmp_position = transform * vec4(in_position, 1.0);
    gl_Position = world.view_proj * tmp_position;
    frag_position = tmp_position.rbg;
    frag_normal = normalize(mat3(transpose(inverse(transform))) * in_normal);
    frag_color = in_color;
    //vec3 temp = vec3(positions[gl_VertexIndex], 0.5);
    //gl_Position = vec4(temp, 1.0);
    //frag_position = temp;
    //frag_normal = vec3(1.0, 1.0, 1.0);
    //frag_color = colors[gl_VertexIndex];
}
