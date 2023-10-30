#ifndef ARQUICOMP_P1_GRID_HPP
#define ARQUICOMP_P1_GRID_HPP

#include "block.hpp"
#include "sim/grid/particle.hpp"
#include "sim/math/vector.hpp"

#include <vector>

namespace sim {
  class Grid {
    public:
      Grid(int np, double ppm, std::vector<Particle> & particles);

      void Repositioning();
      // Calcula las aceleraciones de las partículas.
      void CalculateAccelerations();
      // Procesa colisiones entre partículas.
      void ProcessCollisions();

      void MoveParticles();

      void ProcessLimits();

      [[nodiscard]] int GetNumParticles() const;

      [[nodiscard]] double GetParticlesPerMeter() const;

      [[nodiscard]] std::vector<Block> & GetBlocks();

      const ParticlesData& GetParameters();

    private:
      void InitMessage() const;

      size_t GetBlockIndex(vec3d & particle_pos) const;

      void CalculateAdjacentBlocks(size_t index);

      int num_particles;
      ParticlesData particles_param_;

      vec3<size_t> grid_size_;  // n_x, n_y, n_z
      vec3d block_size_;        // s_x, s_y, s_z
      size_t num_blocks_;

      std::vector<Block> blocks_;
      std::vector<std::vector<size_t>> adjacent_blocks_;
  };
}  // namespace sim

#endif  // ARQUICOMP_P1_GRID_HPP
