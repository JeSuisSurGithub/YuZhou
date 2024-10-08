#ifndef ZSLSHADER_HPP
#define ZSLSHADER_HPP

#include "common.hpp"

#include <fstream>
#include <vector>

namespace zsl
{
    namespace shader
    {
        typedef struct shader
        {
            shader(const shader &) = delete;
            shader &operator=(const shader &) = delete;
            shader(shader &&) = delete;
            shader &operator=(shader &&) = delete;

            GLuint m_id;

            shader(const std::string& vertpath, const std::string& fragpath, bool load_spirv);
            ~shader();
        }shader;

        void bind(shader& program);
        void update_matrix4(shader& program, GLint location, const glm::mat4& matrix);
        void update_vec2(shader& program, GLint location, const glm::vec2& vec_);
        void update_uint_array(shader& program, GLint location, GLuint* uintv, usz size);
        void update_int_array(shader& program, GLint location, GLint* intv, usz size);
        void update_uint(shader& program, GLint location, GLuint uint_);
        void update_int(shader& program, GLint location, GLint int_);
        void update_bool(shader& program, GLint location, bool bool_);
        void update_float(shader& program, GLint location, float float_);

        std::vector<u8> read_file(const std::string& filepath);
    }
}

#endif /* ZSLSHADER_HPP */