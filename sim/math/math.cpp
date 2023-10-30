#include "math.hpp"

#include <cmath>

namespace sim::math {

  double DensityIncrement(const ParticlesData& particles_params, double squared_distance) {
    return pow(particles_params.smoothing_pow_2 - squared_distance, 3);
  }

  /**
 * Esta función calcula el incremento de aceleración entre dos partículas, `particle_i` y `particle_j`,
 * en función de los parámetros especificados en `params`. El incremento de aceleración se calcula teniendo en cuenta
 * la distancia al cuadrado entre las partículas.
 *
 * @param params Los parámetros de las partículas y la simulación.
 * @param particle_i La primera partícula para la que se calculará el incremento de aceleración.
 * @param particle_j La segunda partícula para la que se calculará el incremento de aceleración.
 * @param squared_distance La distancia al cuadrado entre las partículas.
 * @return Un vector 3D que representa el incremento de aceleración entre las partículas.
   */
  vec3d AccelerationIncrement(ParticlesData const & params, Particle const & particle_i, Particle const & particle_j, double squared_distance) {
    double const distance = std::max(std::pow(squared_distance, SQUARED), MINIMUM_DISTANCE);

    vec3d const left = (particle_i.position - particle_j.position) *
                       (15 / (PI * params.smoothing_pow_6)) * ((3 * params.mass * PRESSURE) / 2) *
                       (std::sqrt(params.smoothing - distance) / distance) *
                       (particle_i.density + particle_j.density - 2 * DENSITY);

    vec3d const right = (particle_i.velocity - particle_j.velocity) *
                        (45 / (PI * params.smoothing_pow_6)) * GOO * params.mass;
    double const denominator = particle_i.density * particle_j.density;
    return (left + right) / denominator;
  }

}  // namespace sim