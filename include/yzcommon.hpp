#ifndef YZCOMMON_HPP
#define YZCOMMON_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/hash.hpp>

#include <cstdint>
#include <iostream>
#include <string>

namespace yz
{
    typedef std::int32_t i32;
    typedef std::uint8_t u8;
    typedef std::uint32_t u32;

    const std::string WINDOW_NAME{"YuZhou"};
    constexpr u32 MAX_TEXTURE_COUNT{32};
    constexpr u32 MAX_POINT_LIGHT{32};

    typedef enum UNIFORM_LOCATIONS_
    {
        TEXTURE = 0,
        TEXTURE_INDEX = 32,
        TRANSFORM = 33,
        INVERSE_TRANSFORM = 34,
        COMBINE_MAIN_SCENE = 35,
        COMBINE_BLOOM = 36,
        BLUR_INPUT_IMAGE = 37,
        BLUR_HORIZONTAL = 38,
        TEXTURE_SCROLL_OFFSET = 40
    }UNIFORM_LOCATIONS;

    typedef struct vertex_
    {
        glm::vec3 xyz;
        glm::vec3 rgb;
        glm::vec2 uv;
        glm::vec3 normal;
        bool operator==(const struct vertex_& cmp) const
        {
            return (xyz == cmp.xyz && rgb == cmp.rgb && uv == cmp.uv && normal == cmp.normal);
        }
    }vertex;

    constexpr std::array<glm::vec3, 12> LIGHT_RANGES =
    {{
        glm::vec3(1.f, 0.7f, 1.8),
        glm::vec3(1.f, 0.35f, 0.44),
        glm::vec3(1.f, 0.22f, 0.20),
        glm::vec3(1.f, 0.14f, 0.07),
        glm::vec3(1.f, 0.09f, 0.032),
        glm::vec3(1.f, 0.07f, 0.017),
        glm::vec3(1.f, 0.045f, 0.0075),
        glm::vec3(1.f, 0.027f, 0.0028),
        glm::vec3(1.f, 0.022f, 0.0019),
        glm::vec3(1.f, 0.014f, 0.0007),
        glm::vec3(1.f, 0.007f, 0.0002),
        glm::vec3(1.f, 0.0014f, 0.000007),
    }};

    typedef struct ubo_point_light_
    {
        alignas(16) glm::vec3 position;
        alignas(16) glm::vec3 range;
        alignas(16) glm::vec3 color;
    }ubo_point_light;

    typedef struct ubo_shared_
    {
        alignas(64) glm::mat4 model;
        alignas(64) glm::mat4 view;
        alignas(64) glm::mat4 projection;
        alignas(16) glm::vec3 camera_xyz;
        ubo_point_light point_lights[MAX_POINT_LIGHT];
        alignas(4) GLint point_light_count;
    }ubo_shared;
}

#endif /* YZCOMMON_HPP */