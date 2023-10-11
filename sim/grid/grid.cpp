#include "grid.hpp"

#include "sim/utils/constants.hpp"

#include <cmath>
#include <iostream>

namespace sim {
    Grid::Grid(int np, double ppm, std::vector<Particle> &particles)
            : np_(np), ppm_(ppm), h_(MUL_RAD / ppm_), m_(DENSITY / pow(ppm_, 3)),
              grid_size_({std::floor((TOP_LIMIT.x - BOTTOM_LIMIT.x) / h_),
                          std::floor((TOP_LIMIT.y - BOTTOM_LIMIT.y) / h_),
                          std::floor((TOP_LIMIT.z - BOTTOM_LIMIT.z) / h_)}),
              block_size_({
                                  (TOP_LIMIT.x - BOTTOM_LIMIT.x) / grid_size_.x,
                                  (TOP_LIMIT.y - BOTTOM_LIMIT.y) / grid_size_.y,
                                  (TOP_LIMIT.z - BOTTOM_LIMIT.z) / grid_size_.z,
                          }),
              blocks_(static_cast<size_t>(grid_size_.x * grid_size_.y * grid_size_.z)) {
        InitMessage();
        for (auto &particle: particles) {
            size_t const block_index = GetBlockIndex(
                    particle.position);  // Coger la posicion de la particula comprobar en que bloque le toca
            blocks_[block_index].AddParticle(particle);  // Anadir la particula a dicho bloque
        }
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

    /**
    * Obtiene el índice del bloque al que pertenece una partícula
    *
    * @param particle_pos posición de la partícula en coordenadas x,y,z
    * @return índice del bloque al que pertenece la partícula en la cuadrícula.
    */
    size_t Grid::GetBlockIndex(vec3 &particle_pos) const {
        // i,j,k posicion del bloque en la malla --> pasarlo al indice del bloque
        double pos_i = std::floor((particle_pos.x - BOTTOM_LIMIT.x) / block_size_.x);
        double pos_j = std::floor((particle_pos.y - BOTTOM_LIMIT.y) / block_size_.y);
        double pos_k = std::floor((particle_pos.z - BOTTOM_LIMIT.z) / block_size_.z);

        // Asegura que las coordenadas estén dentro de los límites de la cuadrícula
        if (pos_i < 0) {
           pos_i = 0;
        } else if (pos_i >= grid_size_.x){
           pos_i = grid_size_.x - 1;
        }
        if (pos_j < 0) {
            pos_j = 0;
        } else if (pos_j >= grid_size_.y){
            pos_j = grid_size_.y - 1;
        }
        if (pos_k < 0) {
            pos_k = 0;
        } else if (pos_k >= grid_size_.z){
            pos_k = grid_size_.z - 1;
        }
        return (static_cast<size_t>(pos_i) +
                static_cast<size_t>(pos_j) * static_cast<size_t>(grid_size_.x) +
                static_cast<size_t>(pos_k) * static_cast<size_t>(grid_size_.x) * static_cast<size_t>(grid_size_.y));
    }

    int Grid::GetNumParticles() const {
        return np_;
    }

    double Grid::GetParticlesPerMeter() const {
        return ppm_;
    }

    std::vector<Block>& Grid::GetBlocks() {
        return blocks_;
    }
}  // namespace sim