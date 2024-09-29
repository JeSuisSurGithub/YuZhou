#ifndef ZSLMODEL_HPP
#define ZSLMODEL_HPP

#include "common.hpp"

#include <unordered_map>

namespace std
{
    template<> struct hash<zsl::vertex>
    {
        std::size_t operator()(zsl::vertex const& vertex) const
        {
            return
                ((hash<glm::vec3>()(vertex.xyz) ^
                (hash<glm::vec3>()(vertex.normal) << 1)) >> 1) ^
                (hash<glm::vec2>()(vertex.uv) << 1);
        }
    };
}

namespace zsl
{
    namespace model
    {
        float default_height_filter(float pixel_value);

        typedef struct model
        {
            model(const model &) = delete;
            model &operator=(const model &) = delete;
            model(model &&) = delete;
            model &operator=(model &&) = delete;

            const std::string m_model_path;
            const std::string m_height_map_path;

            std::vector<vertex> m_vertices;
            std::vector<u32> m_indices;

            GLuint m_vbo;
            GLuint m_vao;
            GLuint m_ebo;

            model(
                const std::string& model_path
            );
            model(
                const std::string& model_path,
                const std::string& height_map_path,
                std::function<float(float)> height_filter = default_height_filter);
            ~model();

            void load_obj();
            void load_obj_to_gpu();
        }model;

        void draw(model& model_);
    }
}

#endif /* ZSLMODEL_HPP */