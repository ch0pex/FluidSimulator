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
    double const distance = sqrt(std::max(squared_distance, MINIMUN_DISTANCE));
    vec3d const left = (particle_i.position - particle_j.position) *
                       (15 / (PI * params.smoothing_pow_6)) * ((3 * params.mass * PRESSURE) * 0.5) *
                       (std::pow(params.smoothing - distance, 2) / distance) *
                       (particle_i.density + particle_j.density - 2 * DENSITY);

    static const double right_scalar = (45 / (PI * params.smoothing_pow_6)) * GOO * params.mass;
    vec3d const right = (particle_j.velocity - particle_i.velocity) * right_scalar;
    double const denominator = particle_i.density * particle_j.density;
    return ((left + right) / denominator);
  }

}  // namespace sim