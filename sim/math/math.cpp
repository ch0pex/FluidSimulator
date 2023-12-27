#include "math.hpp"

#include <cmath>

namespace sim::math {

  double DensityIncrement(ParticlesData const & particles_params, double const squared_distance) {
    return pow(particles_params.smoothing_pow_2 - squared_distance, 3);
  }

  /**
   * Esta función calcula el incremento de aceleración entre dos partículas, `particle_i` y
   * `particle_j`, en función de los parámetros especificados en `params`. El incremento de
   * aceleración se calcula teniendo en cuenta la distancia al cuadrado entre las partículas.
   *
   * @param params Los parámetros de las partículas y la simulación.
   * @param particle_i La primera partícula para la que se calculará el incremento de aceleración.
   * @param particle_j La segunda partícula para la que se calculará el incremento de aceleración.
   * @param squared_distance La distancia al cuadrado entre las partículas.
   * @return Un vector 3D que representa el incremento de aceleración entre las partículas.
   */
  vec3d AccelerationIncrement(ParticlesData const & params, Particle const & particle_i,
                              Particle const & particle_j, double squared_distance) {
    double const distance = sqrt(std::max(squared_distance, MINIMUN_DISTANCE));
    AVXvec3 preassure     = AVXsetvec3(params.mass_pressure_05);
    AVXvec3 f45_smooth_6  = AVXsetvec3(params.f45_pi_smooth_6);
    AVXvec3 densityi      = AVXsetvec3(particle_i.density);
    AVXvec3 densityj      = AVXsetvec3(particle_j.density);
    AVXvec3 AVXposi       = AVXLoadvec3(particle_i.position);
    AVXvec3 AVXposj       = AVXLoadvec3(particle_j.position);
    AVXvec3 AVXveli       = AVXLoadvec3(particle_i.velocity);
    AVXvec3 AVXvelj       = AVXLoadvec3(particle_j.velocity);
    AVXvec3 s2            = AVXsetvec3(2);
    AVXvec3 dens            = AVXsetvec3(DENSITY);
    AVXvec3 left          = (AVXposi - AVXposj) * preassure * (densityi + densityj - s2 * dens);
    left                  = left * (std::pow(params.smoothing - distance, 2) / distance);
    AVXvec3 const right   = (AVXvelj - AVXveli) * params.mass_goo;
    double const denominator = particle_i.density * particle_j.density;
    AVXvec3 den              = AVXsetvec3(denominator);
    AVXvec3 result           = ((left + right) * f45_smooth_6 / den);
    vec3d res                = AVXStorevec3(result);
    return res;
  }

}  // namespace sim::math