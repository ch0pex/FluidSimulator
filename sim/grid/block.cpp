#include "block.hpp"
#include <iostream>

namespace sim {

    /**
    * Agrega una partícula al bloque.
    *
    * @param id Identificador único de la partícula.
    * @param position Posición de la partícula en coordenadas 3D.
    * @param hv Vector de características (hv) de la partícula.
    * @param velocity Vector de velocidad de la partícula.
    */
    void Block::AddParticle(Particle &particle) {
        particles_.push_back(particle);
    }

    std::vector<Particle> &Block::GetParticles() {
        return particles_;
    }

    void Block::CalculateAdjacent(size_t index, std::array<size_t, 3> &grid_size) {
        const size_t block_x = index % grid_size[0];
        const size_t block_y = (index / grid_size[0]) % grid_size[1];
        const size_t block_z = index / (grid_size[0] * grid_size[1]);
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                for (int k = -1; k <= 1; ++k) {
                    if (i == 0 && j == 0 && k == 0) {
                        continue;
                    }
                    const int neighbor_x = static_cast<int>(block_x) + i;
                    const int neighbour_y = static_cast<int>(block_y) + j;
                    const int neighbour_z = static_cast<int>(block_z) + k;
                    if (neighbor_x >= 0 && static_cast<size_t>(neighbor_x) < grid_size[0] &&
                        neighbour_y >= 0 && static_cast<size_t>(neighbour_y) < grid_size[1]
                        && neighbour_z >= 0 && static_cast<size_t>(neighbour_z) < grid_size[2]) {
                        const size_t neighborIndex = neighbor_x + neighbour_y * grid_size[0] +
                                                     neighbour_z * grid_size[0] * grid_size[1];
                        adjacent_blocks_.push_back(neighborIndex);
                    }
                }
            }
        }
    }
}