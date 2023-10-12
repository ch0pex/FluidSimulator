#include "particle.hpp"

#include <cmath>

#include "sim/utils/constants.hpp"

namespace sim {

  ParticlesData::ParticlesData(double ppm)
      : particles_per_meter(ppm), smoothing(MUL_RAD / ppm),
        smoothing_pow_2(pow(smoothing, 2)),
        smoothing_pow_6(pow(smoothing_pow_2, 3)),
        smoothing_pow_9(pow(smoothing, 9)),
        mass(DENSITY / pow(ppm, 3)) { }

  Particle::Particle(size_t _id, vec3d& _position, vec3d& _hv, vec3d& _velocity)
    : id(_id), position(_position), hv(_hv), velocity(_velocity),
      acceleration({0.0, 0.0, 0.0}), density(0) { }

  Particle::Particle(sim::Particle const & other)
    : id(other.id), position(other.position), hv(other.hv), velocity(other.velocity),
      acceleration({0.0, 0.0, 0.0}), density(0) { }

  Particle & Particle::operator=(Particle const & other) {
    if (this != &other) {
      id       = other.id;
      position = other.position;
      hv       = other.hv;
      velocity = other.velocity;
    }
    return *this;
  }

  void Particle::TransformDenisty(const ParticlesData& particles_params) {
    density = (density + particles_params.smoothing_pow_6) *
              (315.0 /(64.0 * PI * particles_params.smoothing_pow_9)) * particles_params.mass;
  }
}  // namespace sim
