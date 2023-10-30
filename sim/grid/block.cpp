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

  /**
   *  TODO: docstring
   * Calcula las densidades de las partículas en el bloque en función de la distancia entre las partículas
   * y el radio de suavizado ('particles_params')
   * Permite acceder y manipular directamente las partículas contenidas en el bloque.
   * @return Una referencia al vector de partículas del bloque.
   */
  void Block::CalcDensitiesAndAccelerations(const ParticlesData& particles_params, std::vector<size_t>& adjacents, std::vector<Block>& blocks, size_t block_index) {
    for (size_t i = 0; i < particles_.size(); ++i) {
      for (size_t j = i + 1; j < particles_.size(); ++j) { // Evitamos repetir calculos entre particulas inicializando j=i+1
        Particle::IncrementDensities(particles_params, particles_[i], particles_[j]);
      }
      for(auto& adjacent_index : adjacents) {
        if(adjacent_index > block_index) { //Solo se hacen los calculos con los bloques adjacentes de mayor indice para evitar repetir calculos
          for(auto& particle_j : blocks[adjacent_index].GetParticles()){
            Particle::IncrementDensities(particles_params, particles_[i], particle_j);
          }
        }
      }
      particles_[i].TransformDenisty(particles_params);

      for (size_t j = i + 1; j < particles_.size(); ++j) {  // Evitamos repetir calculos entre particulas inicializando j=i+1
        Particle::IncrementAccelerations(particles_params, particles_[i], particles_[j]);
      }
      for(auto& adjacent_index : adjacents) {
        if(adjacent_index > block_index) { //Solo se hacen los calculos con los bloques adjacentes de mayor indice para evitar repetir calculos
          for(auto& particle_j : blocks[adjacent_index].GetParticles()){
            Particle::IncrementAccelerations(particles_params, particles_[i], particle_j);
          }
        }
      }
    }
  }

}  // namespace sim