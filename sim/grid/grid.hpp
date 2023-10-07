#ifndef ARQUICOMP_P1_GRID_HPP
#define ARQUICOMP_P1_GRID_HPP

#include "block.hpp"
#include "sim/utils/vector.hpp"

#include <vector>

namespace sim {
    class Grid {
    public:

        Grid(int np, double ppm, std::vector<vec3> &particles);


        void ComputeBlocks();

    private:
        void InitMessage() const;
        double np_;
        double ppm_;
        double h_;
        double m_;
        vec3 grid_size_;
        vec3 block_size_;

        std::vector<Block> blocks_;
        //std::vector<Block> aux;
    };
}

#endif  // ARQUICOMP_P1_GRID_HPP
