#include "grid.hpp"
#include "sim/utils/constants.hpp"

#include <iostream>
#include <cmath>


namespace sim {
    Grid::Grid(int np, double ppm, std::vector<vec3> &/*particles*/)
            : np_(np), ppm_(ppm),
              h_(MUL_RAD / ppm_),
              m_(DENSITY / pow(ppm_, 3)),
              grid_size_({
                                  std::floor((TOP_LIMIT.x - BOTTOM_LIMIT.x) / h_),
                                  std::floor((TOP_LIMIT.y - BOTTOM_LIMIT.y) / h_),
                                  std::floor((TOP_LIMIT.z - BOTTOM_LIMIT.z) / h_),
                          }),
              block_size_({
                                  (TOP_LIMIT.x - BOTTOM_LIMIT.x) / grid_size_.x,
                                  (TOP_LIMIT.y - BOTTOM_LIMIT.y) / grid_size_.y,
                                  (TOP_LIMIT.z - BOTTOM_LIMIT.z) / grid_size_.z,
                          }),
              blocks_(static_cast<size_t>(grid_size_.x * grid_size_.y * grid_size_.z)) {

        InitMessage();
    }

    void Grid::InitMessage() const {
        std::cout << "Number of particles: " << np_ << "\n";
        std::cout << "Particles per meter: " << ppm_ << "\n";
        std::cout << "Smoothing length: " << h_ << "\n";
        std::cout << "Particles Mass: " << m_ << "\n";
        std::cout << "Grid size: " << grid_size_ << "\n";
        std::cout << "Number of blocks: " << blocks_.size() << "\n";
        std::cout << "Block size: " << block_size_ << "\n";
    }
}