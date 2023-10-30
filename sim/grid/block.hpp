#include "sim/grid/particle.hpp"
#include "sim/math/vector.hpp"

#include <vector>

namespace sim {
  class Block {
    public:
      Block() = default;

      void AddParticle(Particle & particle);

      [[nodiscard]] std::vector<Particle> & GetParticles();

      void CalcDensitiesAndAccelerations(ParticlesData const & particles_params, std::vector<size_t>& adjacents, std::vector<Block>& blocks, size_t block_index);

    private:
      std::vector<Particle> particles_; //TODO; justificar porque creemos que es mejor usar esto que un soa, mejorar localidad espacial

  };
}  // namespace sim