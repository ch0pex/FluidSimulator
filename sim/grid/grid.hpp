#ifndef ARQUICOMP_P1_GRID_HPP
#define ARQUICOMP_P1_GRID_HPP

#include "block.hpp"
#include "sim/utils/vector.hpp"
#include "sim/grid/particle.hpp"

#include <vector>

namespace sim {
    class Grid {
    public:
        Grid(int np, double ppm, std::vector<Particle> &particles);

        void Repositioning();

        void CalcForces();

        void ProcessCollisions();

        void MoveParticles();

        void ProcessLimits();

        [[nodiscard]] int GetNumParticles() const;

        [[nodiscard]] double GetParticlesPerMeter() const;

        [[nodiscard]] std::vector<Block>& GetBlocks();

    private:
        void InitMessage() const;

        size_t GetBlockIndex(vec3 &particle_pos) const;

        int np_;
        double ppm_;
        double h_;
        double m_;
        vec3 grid_size_;   // n_x, n_y, n_z
        vec3 block_size_;  // s_x, s_y, s_z
        size_t num_blocks_;

        std::vector<Block> blocks_;
        std::vector<std::vector<size_t>> adjacent_blocks_;
    };
}  // namespace sim

#endif  // ARQUICOMP_P1_GRID_HPP
