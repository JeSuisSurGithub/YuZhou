#ifndef YZGEN_HPP
#define YZGEN_HPP

#include "yzcommon.hpp"
#include "rendergroups/planetgroup.hpp"
#include "rendergroups/stargroup.hpp"

namespace yz
{
    i32 lehmer_randrange(u32& state, i32 min, i32 max);
    float lehmer_randrange_flt(u32& state, float min, float max);
    glm::vec3 lehmer_randrange_vec3(u32& state, glm::vec3 min, glm::vec3 max);

    void generate(
        rendergroups::stargroup& stars,
        rendergroups::planetgroup& planets,
        u32 seed,
        usz count);
}

#endif /* YZGEN_HPP */