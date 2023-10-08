#include <vector>

#include "sim/utils/vector.hpp"


namespace sim {
    class Block {
    public:
        Block();
        void AddParticle(size_t id, vec3& position, vec3& hv, vec3& velocity);
    private:
        bool is_computed;
        //Particles
        std::vector<size_t> ids_;
        std::vector<vec3> positions_;
        std::vector<vec3> hvs_;
        std::vector<vec3> velocities_;
    };
}