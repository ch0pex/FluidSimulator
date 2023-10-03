#ifndef ARQUICOMP_P1_GRID_HPP
#define ARQUICOMP_P1_GRID_HPP

#include "block.hpp"

#include "constants.hpp"

namespace sim {
    class Grid {
    public:
        Grid(int np, double ppm);

        void ComputeBlocks();

    private:
        std::vector<Block> blocks_;
        double np_;
        double ppm_;
        double h_;
        double m_;
        vec3 num_blocks_;
        vec3 block_size_;
        double total_blocks_;
    };
}

#endif  // ARQUICOMP_P1_GRID_HPP
