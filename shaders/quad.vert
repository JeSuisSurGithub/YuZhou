#version 460 core

layout (location = 0) in vec2 in_xy;
layout (location = 1) in vec2 in_uv;

layout (location = 0) out vec2 out_uv;

void main()
{
    gl_Position = vec4(in_xy.x, in_xy.y, 0.0, 1.0);
    out_uv = in_uv;
}

