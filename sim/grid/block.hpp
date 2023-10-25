#include "sim/grid/particle.hpp"
#include "sim/math/vector.hpp"

#include <vector>

namespace sim {
  class Block {
    public:
      Block() = default;

      void AddParticle(Particle & particle);

      [[nodiscard]] std::vector<Particle> & GetParticles();

      void CalcDensities(ParticlesData const & particles_params);

      void CalcForcesWith(std::vector<Particle> & particles, const ParticlesData& particles_params);

    private:
      std::vector<Particle> particles_; //TODO; justificar porque creemos que es mejor usar esto que un soa, mejorar localidad espacial
      //std::vector ids
      //std::vector posiciones
      /*
       * struct particle {
       *  int id
       *  vec3 posicion
       *  }
       */

  };
}  // namespace sim