#include "block.hpp"

#include "sim/utils/constants.hpp"

#include <iostream>
#include <cmath>

namespace sim {

  /**
   * Agrega una partícula al bloque.
   *
   * @param id Identificador único de la partícula.
   * @param position Posición de la partícula en coordenadas 3D.
   * @param hv Vector de características (hv) de la partícula.
   * @param velocity Vector de velocidad de la partícula.
   */
  void Block::AddParticle(Particle & particle) {
    particles_.push_back(particle);
  }

  std::vector<Particle> & Block::GetParticles() {
    return particles_;
  }

  void Block::CalcDensities(ParticlesData const & particles_params, std::vector<size_t>& adjacents, std::vector<Block>& blocks) {
    // Evitamos repetir calculos entre particulask
    double squared_distance = 0.0;
    double density_incriment = 0.0;
    for (size_t i = 0; i < particles_.size(); ++i) {
      for (size_t j = i + 1; j < particles_.size(); ++j) {
        squared_distance = vec3d::SquaredDistance(particles_[i].position, particles_[j].position);
        if (squared_distance < particles_params.smoothing_pow_2){
          // Incremento de densidades
          density_incriment = pow(particles_params.smoothing_pow_2 - squared_distance, 3);
          // Tranformacion de densidad
          particles_[i].density += density_incriment;
          //particles_[i].TransformDenisty(particles_params);
          particles_[j].density += density_incriment;
          //particles_[j].TransformDenisty(particles_params);
          // Transferencia de la aceleracion
        }
      }
      for(auto& index : adjacents) {
        CalcForcesWith(blocks[index].GetParticles());
      }


      particles_[i].TransformDenisty(particles_params);
    }
  }

  void Block::CalcForcesWith(std::vector<Particle>& /*particles*/, const ParticlesData& /*particles_params*/) {

  }
}  // namespace sim