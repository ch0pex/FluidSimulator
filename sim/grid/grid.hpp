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

    private:
        void InitMessage() const;

        size_t GetBlockIndex(vec3 &particle_pos) const;

        double np_;
        double ppm_;
        double h_;
        double m_;
        vec3 grid_size_;   // n_x, n_y, n_z
        vec3 block_size_;  // s_x, s_y, s_z

        std::vector<Block> blocks_;
    };
}  // namespace sim

#endif  // ARQUICOMP_P1_GRID_HPP