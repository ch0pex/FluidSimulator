#include <vector>

#include "sim/utils/vector.hpp"
#include "sim/grid/particle.hpp"


namespace sim {
    class Block {
    public:
        Block() = default;
        void AddParticle(Particle& particle);

    private:
        std::vector<Particle> particles_;

    };
}