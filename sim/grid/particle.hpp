#ifndef FLUID_PARTICLE_HPP
#define FLUID_PARTICLE_HPP

#include "sim/math/vector.hpp"

namespace sim {

  struct ParticlesData {
    ParticlesData(double ppm);
    double particles_per_meter;
    double smoothing;
    double smoothing_pow_2;
    double smoothing_pow_6;
    double smoothing_pow_9;
    double mass;
  };

  struct Particle {
      Particle(size_t _id, vec3d & _position, vec3d & _hv, vec3d & _velocity);

      Particle(Particle const &);

      void TransformDenisty(const ParticlesData& particles_params);

      Particle & operator=(Particle const & other);

      size_t id;

      vec3d position;

      vec3d hv;

      vec3d velocity;

      vec3d acceleration;

      double density;
  };
}  // namespace sim

#endif  // FLUID_PARTICLE_HPP
