#include <vector>

#include "sim/utils/vector.hpp"


namespace sim {
    struct Block {
    public:
        Block();
        bool is_computed;
        //Particles
        std::vector<size_t> ids;
        std::vector<vec3> positions;
        std::vector<vec3> hvs;
        std::vector<vec3> velocities;
    };
}