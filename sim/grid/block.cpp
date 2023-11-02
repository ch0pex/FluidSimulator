#include "block.hpp"


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
  void Block::CalcDensities(ParticlesData const & particles_params, std::vector<size_t>& adjacents, std::vector<Block>& blocks, size_t block_index) {
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
    }
  }

  void Block::CalcAccelerations(const ParticlesData& particles_params, std::vector<size_t>& adjacents, std::vector<Block>& blocks) {
    for (size_t i = 0; i < particles_.size(); ++i) {
      for (size_t j = i + 1; j < particles_.size(); ++j) {  // Evitamos repetir calculos entre particulas inicializando j=i+1
        Particle::IncrementAccelerations(particles_params, particles_[i], particles_[j]);
      }
      for (auto & adjacent_index : adjacents) {
        for (auto & particle_j : blocks[adjacent_index].GetParticles()) {
          Particle::IncrementAccelerations(particles_params, particles_[i], particle_j);
        }
      }
    }
  }

  void Block::ProcessCollisions(std::set<Limits>& limits) {
    for(auto& particle : particles_){
      CollisionsX(particle, limits);
      CollisionsY(particle, limits);
      CollisionsZ(particle, limits);
    }
  }

  void Block::MoveParticles() {
    for (auto& particle : particles_){
      particle.position += particle.hv * TIME_STEP + particle.acceleration * SQUARED_TIME_STEP;
      particle.velocity = particle.hv + ((particle.acceleration * TIME_STEP) / 2);
      particle.hv += particle.acceleration * TIME_STEP;
    }
  }

  void Block::CollisionsX(Particle& particle, std::set<Limits>& limits) {
    double x = 0.0;
    double x_diff = 0.0;
    if (limits.contains(CX0)) {
      x = particle.position.x + particle.hv.x * TIME_STEP;
      x_diff = PARTICLE_SIZE - (x - BOTTOM_LIMIT.x);
      if (x_diff > MIN_COLLISION_DIFF){
        particle.acceleration.x += COLLISION * x_diff - DAMPING * particle.velocity.x;
      }
    } else if (limits.contains(CXN)) {
      x = particle.position.x + particle.hv.x * TIME_STEP;
      x_diff = PARTICLE_SIZE - (TOP_LIMIT.x - x);
      if (x_diff > MIN_COLLISION_DIFF) {
        particle.acceleration.x -= COLLISION * x_diff + DAMPING * particle.velocity.x;
      }
    }
  }

  void Block::CollisionsY(Particle& particle, std::set<Limits> & limits) {
    double y = 0.0;
    double y_diff = 0.0;

    if (limits.contains(CY0)) {
      y = particle.position.y + particle.hv.y * TIME_STEP;
      y_diff = PARTICLE_SIZE - (y - BOTTOM_LIMIT.y);
      if (y_diff > MIN_COLLISION_DIFF) {
        particle.acceleration.y += COLLISION * y_diff - DAMPING * particle.velocity.y;
      }
    } else if (limits.contains(CYN)) {
      y = particle.position.y + particle.hv.y * TIME_STEP;
      y_diff = PARTICLE_SIZE - (TOP_LIMIT.y - y);
      if (y_diff > MIN_COLLISION_DIFF) {
        particle.acceleration.y -= COLLISION * y_diff + DAMPING * particle.velocity.y;
      }
    }
  }

  void Block::CollisionsZ(Particle& particle, std::set<Limits> & limits) {
    double z = 0.0;
    double z_diff = 0.0;
    if (limits.contains(CZ0)) {
      z = particle.position.z + particle.hv.z * TIME_STEP;
      z_diff = PARTICLE_SIZE - (z - BOTTOM_LIMIT.z);
      if (z_diff > MIN_COLLISION_DIFF) {
          particle.acceleration.z += COLLISION * z_diff - DAMPING * particle.velocity.z;
      }
    } else if (limits.contains(CZN)) {
      z = particle.position.z + particle.hv.z * TIME_STEP;
      z_diff = PARTICLE_SIZE - (TOP_LIMIT.z - z);
      if (z_diff > MIN_COLLISION_DIFF) {
            particle.acceleration.z -= COLLISION * z_diff + DAMPING * particle.velocity.z;
      }
    }
  }

  void Block::ProcessLimits(std::set<Limits> & limits) {
    for(auto& particle : particles_){
      LimitsX(particle, limits);
      LimitsY(particle, limits);
      LimitsZ(particle, limits);
    }
  }

  void Block::LimitsX(Particle & particle, std::set<Limits> & limits) {
    double dx = 0.0;
    if (limits.contains(CX0)) {
      dx = particle.position.x - BOTTOM_LIMIT.x;
      if (dx < 0) {
        particle.position.x = BOTTOM_LIMIT.x - dx;
        particle.velocity.x = -particle.velocity.x;
        particle.hv.x = -particle.hv.x;
      }
    } else if (limits.contains(CXN)) {
      dx = TOP_LIMIT.x - particle.position.x;
      if (dx < 0) {
        particle.position.x = TOP_LIMIT.x + dx;
        particle.velocity.x = -particle.velocity.x;
        particle.hv.x = -particle.hv.x;
      }
    }
  }

  void Block::LimitsY(Particle & particle, std::set<Limits> & limits) {
    double dy = 0.0;
    if (limits.contains(CY0)) {
      dy = particle.position.y - BOTTOM_LIMIT.y;
      if (dy < 0) {
        particle.position.y = BOTTOM_LIMIT.y - dy;
        particle.velocity.y = -particle.velocity.y;
        particle.hv.y = -particle.hv.y;
      }
    } else if (limits.contains(CYN)) {
      dy = TOP_LIMIT.y - particle.position.y;
      if (dy < 0) {
        particle.position.y = TOP_LIMIT.y + dy;
        particle.velocity.y = -particle.velocity.y;
        particle.hv.y = -particle.hv.y;
      }
    }
  }

  void Block::LimitsZ(Particle & particle, std::set<Limits> & limits) {
    double dz = 0.0;
    if (limits.contains(CZ0)) {
      dz = particle.position.z - BOTTOM_LIMIT.z;
      if (dz < 0) {
        particle.position.z = BOTTOM_LIMIT.z - dz;
        particle.velocity.z = -particle.velocity.z;
        particle.hv.z = -particle.hv.z;
      }
    } else if (limits.contains(CZN)) {
      dz = TOP_LIMIT.z - particle.position.z;
      if (dz < 0) {
        particle.position.z = TOP_LIMIT.z + dz;
        particle.velocity.z = -particle.velocity.z;
        particle.hv.z = -particle.hv.z;
      }
    }
  }


}  // namespace sim