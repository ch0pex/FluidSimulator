#include <vector>

#include "sim/utils/vector.hpp"
#include "sim/grid/particle.hpp"


namespace sim {
    class Block {
    public:
        Block() = default;
        void AddParticle(Particle& particle);
        [[nodiscard]] std::vector<Particle>& GetParticles();
        void CalculateAdjacent(size_t index, std::array<size_t,3>& grid_size);

    private:
        std::vector<Particle> particles_;
        std::vector<size_t> adjacent_blocks_;
    };
}