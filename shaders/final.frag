#version 460 core

layout (location = 0) in vec2 in_uv;
layout (location = 0) out vec4 out_rgba;

layout (location = 35) uniform sampler2D main_image;
layout (location = 36) uniform sampler2D bloom;

const float GAMMA = 1.0;
const float EXPOSURE = 0.25;

void main()
{
    vec3 hdr_color = texture(main_image, in_uv).rgb;
    vec3 bloom_color = texture(bloom, in_uv).rgb;
    hdr_color = mix(hdr_color, bloom_color, 0.08);

    vec3 tone_mapped = vec3(1.0) - exp(-hdr_color * EXPOSURE);

    tone_mapped = pow(tone_mapped, vec3(1.0 / GAMMA));
    out_rgba = vec4(tone_mapped, texture(main_image, in_uv).a);
}