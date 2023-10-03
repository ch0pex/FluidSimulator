#include "grid.hpp"

#include <iostream>
#include <cmath>


namespace sim {
    Grid::Grid(int np, double ppm)
            : np_(np), ppm_(ppm),
              h_(MUL_RAD / ppm_),
              m_(DENSITY / pow(ppm_, 3)),
              num_blocks_({
                                  std::floor((TOP_LIMIT.x - BOTTOM_LIMIT.x) / h_),
                                  std::floor((TOP_LIMIT.y - BOTTOM_LIMIT.y) / h_),
                                  std::floor((TOP_LIMIT.z - BOTTOM_LIMIT.z) / h_),
                          }),
              block_size_({
                                  (TOP_LIMIT.x - BOTTOM_LIMIT.x) / num_blocks_.x,
                                  (TOP_LIMIT.y - BOTTOM_LIMIT.y) / num_blocks_.y,
                                  (TOP_LIMIT.z - BOTTOM_LIMIT.z) / num_blocks_.z,
                          }),
              total_blocks_(num_blocks_.x * num_blocks_.y * num_blocks_.z) {
        blocks_.reserve(static_cast<size_t>(total_blocks_));
        std::cout << "Number of particles: " << np_ << "\n";
        std::cout << "Particles per meter: " << ppm_ << "\n";
        std::cout << "Smoothing length: " << h_ << "\n";
        std::cout << "Particles Mass: " << m_ << "\n";
        std::cout << "Grid size: " << num_blocks_.x << " x " << num_blocks_.y << " x " << num_blocks_.z << "\n";
        std::cout << "Number of blocks: " << np_ << "\n";
        std::cout << "Block size: " << block_size_.x << " x " << block_size_.y << " x " << block_size_.z << "\n";
    }

    void Grid::ComputeBlocks() {

    }
}