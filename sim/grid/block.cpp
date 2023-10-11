#include "block.hpp"
#include <iostream>

namespace sim {

    /**
    * Agrega una partícula al bloque.
    *
    * @param id Identificador único de la partícula.
    * @param position Posición de la partícula en coordenadas 3D.
    * @param hv Vector de características (hv) de la partícula.
    * @param velocity Vector de velocidad de la partícula.
    */
    void Block::AddParticle(Particle &particle) {
        particles_.push_back(particle);
    }

    std::vector<Particle> & Block::GetParticles(){
        return particles_;
    }


}
