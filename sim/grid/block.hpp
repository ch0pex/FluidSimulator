#include "sim/grid/particle.hpp"
#include "sim/math/vector.hpp"
#include "sim/utils/constants.hpp"

#include <vector>
#include <set>

namespace sim {
  class Block {
    public:
      Block() = default;

      void AddParticle(Particle & particle);

      [[nodiscard]] std::vector<Particle> & GetParticles();

      void CalcDensities(ParticlesData const & particles_params, std::vector<size_t>& adjacents, std::vector<Block>& blocks, size_t block_index);

      void CalcAccelerations(ParticlesData const & particles_params, std::vector<size_t>& adjacents, std::vector<Block>& blocks);

      void ProcessCollisions(std::set<Limits>& limits);

      void ProcessLimits(std::set<Limits>& limits);

      void MoveParticles();

    private:
      void CollisionsX(Particle& particle, std::set<Limits>& limits);

      void CollisionsY(Particle& particle, std::set<Limits>& limits);

      void CollisionsZ(Particle& particle, std::set<Limits>& limits);

      void LimitsX(Particle& particle, std::set<Limits>& limits);

      void LimitsY(Particle& particle, std::set<Limits>& limits);

      void LimitsZ(Particle& particle, std::set<Limits>& limits);

      std::vector<Particle> particles_; //TODO; justificar porque creemos que es mejor usar esto que un soa, mejorar localidad espacial

  };
}  // namespace sim