#include "sim/grid/particle.hpp"
#include "sim/math/vector.hpp"

#include <vector>

namespace sim {
  class Block {
    public:
      Block() = default;

      void AddParticle(Particle & particle);

      [[nodiscard]] std::vector<Particle> & GetParticles();

      void CalcForces(const ParticlesData& particles_params);

      void CalcForcesWith(std::vector<Particle> & particles, const ParticlesData& particles_params);

    private:
      std::vector<Particle> particles_;
  };
}  // namespace sim