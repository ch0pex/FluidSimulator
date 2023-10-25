#include "grid.hpp"

#include "sim/utils/constants.hpp"

#include <cmath>
#include <iostream>

namespace sim {
  Grid::Grid(int np, double ppm, std::vector<Particle> & particles)
    : num_particles(np), particles_param_(ppm),
      grid_size_({std::floor((TOP_LIMIT.x - BOTTOM_LIMIT.x) / particles_param_.smoothing),
                  std::floor((TOP_LIMIT.y - BOTTOM_LIMIT.y) / particles_param_.smoothing),
                  std::floor((TOP_LIMIT.z - BOTTOM_LIMIT.z) / particles_param_.smoothing)}),
      block_size_({
        (TOP_LIMIT.x - BOTTOM_LIMIT.x) / static_cast<double>(grid_size_.x),
        (TOP_LIMIT.y - BOTTOM_LIMIT.y) / static_cast<double>(grid_size_.y),
        (TOP_LIMIT.z - BOTTOM_LIMIT.z) / static_cast<double>(grid_size_.z),
      }),
      num_blocks_(grid_size_.x * grid_size_.y * grid_size_.z), blocks_(num_blocks_),
      adjacent_blocks_(num_blocks_) {
    for (auto& particle : particles) {
      size_t const block_index = GetBlockIndex(particle.position);  // Coger la posicion de la particula comprobar en que bloque le toca
      blocks_[block_index].AddParticle(particle);  // Anadir la particula a dicho bloque
    }

    for (size_t i = 0; i < num_blocks_; ++i) {
      // Se calculan los bloques adjacentes para cada bloque
      CalculateAdjacentBlocks(i);
    }
    // InitMessage(); Comentado para que no moleste en los perf stat
  }

  void Grid::Repositioning() {
    std::vector<Block> aux(num_blocks_);

    for (auto & block : blocks_) {
      for (auto & particle : block.GetParticles()) {
        aux[GetBlockIndex(particle.position)].AddParticle(particle);
      }
    }
    blocks_ = std::move(aux);
  }

  void Grid::CalcForces() {
    // Las densisdes y aceleraciones no son copiadas en el grid auxiliar por lo que ya son 0
    for (size_t i = 0; i < num_blocks_; ++i) {
      // Se calculan la densidad y aceleracion entre las particulas de un mismo bloque
      blocks_[i].CalcDensities(particles_param_);
      for (auto & index : adjacent_blocks_[i]) {
        // Se calcula la densisdad y aceleracion entre las particulas de bloques adyacentes
        blocks_[i].CalcForcesWith(blocks_[index].GetParticles(), particles_param_);
      }
    }
  }

  void Grid::ProcessCollisions() { }

  void Grid::MoveParticles() { }

  void Grid::ProcessLimits() { }

  void Grid::InitMessage() const {
    std::cout << "Number of particles: " << num_particles << "\n";
    std::cout << "Particles per meter: " << particles_param_.particles_per_meter << "\n";
    std::cout << "Smoothing length: " <<  particles_param_.smoothing << "\n";
    std::cout << "Particles Mass: " << particles_param_.mass << "\n";
    std::cout << "Grid size: " << grid_size_ << "\n";
    std::cout << "Number of blocks: " << num_blocks_ << "\n";
    std::cout << "Block size: " << block_size_ << "\n";
  }

  /**
   * Obtiene el índice del bloque al que pertenece una partícula
   *
   * @param particle_pos posición de la partícula en coordenadas x,y,z
   * @return índice del bloque al que pertenece la partícula en la cuadrícula.
   */
  size_t Grid::GetBlockIndex(vec3d & particle_pos) const {
    // i,j,k posicion del bloque en la malla --> pasarlo al indice del bloque
    double pos_i = std::floor((particle_pos.x - BOTTOM_LIMIT.x) / block_size_.x);
    double pos_j = std::floor((particle_pos.y - BOTTOM_LIMIT.y) / block_size_.y);
    double pos_k = std::floor((particle_pos.z - BOTTOM_LIMIT.z) / block_size_.z);

    // Asegura que las coordenadas estén dentro de los límites de la cuadrícula
    if (pos_i < 0) {
      pos_i = 0;
    } else if (pos_i >= static_cast<double>(grid_size_.x)) {
      pos_i = static_cast<double>(grid_size_.x) - 1;
    }
    if (pos_j < 0) {
      pos_j = 0;
    } else if (pos_j >= static_cast<double>(grid_size_.y)) {
      pos_j = static_cast<double>(grid_size_.y) - 1;
    }
    if (pos_k < 0) {
      pos_k = 0;
    } else if (pos_k >= static_cast<double>(grid_size_.z)) {
      pos_k = static_cast<double>(grid_size_.z) - 1;
    }
    return (static_cast<size_t>(pos_i) + static_cast<size_t>(pos_j) * grid_size_.x +
            static_cast<size_t>(pos_k) * grid_size_.x * grid_size_.y);
  }

  void Grid::CalculateAdjacentBlocks(size_t index) {
    vec3<int> const block_pos = {index % grid_size_.x, (index / grid_size_.x) % grid_size_.y,
                                 index / (grid_size_.x * grid_size_.y)};

    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
        for (int k = -1; k <= 1; ++k) {
          if (i == 0 && j == 0 && k == 0) { continue; }
          vec3<int> const neighbor_pos = {block_pos.x + i, block_pos.y + j, block_pos.z + k};

          if (neighbor_pos.x >= 0 && static_cast<size_t>(neighbor_pos.x) < grid_size_.x &&
              neighbor_pos.y >= 0 && static_cast<size_t>(neighbor_pos.y) < grid_size_.y &&
              neighbor_pos.z >= 0 && static_cast<size_t>(neighbor_pos.z) < grid_size_.z) {
            size_t const neighbor_index = neighbor_pos.x + neighbor_pos.y * grid_size_.x +
                                          neighbor_pos.z * grid_size_.x * grid_size_.y;
            if (index < neighbor_index) {
              // Solo se anaden a la lista de vecinos los bloques con mas indice para asi no repetir calculos
              adjacent_blocks_[index].push_back( neighbor_index);
            }
          }
        }
      }
    }
  }

  int Grid::GetNumParticles() const {
    return num_particles;
  }

  double Grid::GetParticlesPerMeter() const {
    return particles_param_.particles_per_meter;
  }

  std::vector<Block> & Grid::GetBlocks() {
    return blocks_;
  }

  const ParticlesData& Grid::GetParameters() {
    return particles_param_;
  }
}  // namespace sim
