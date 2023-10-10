#include "block.hpp"
#include <iostream>

namespace sim {
    Block::Block() : is_computed(false) { }
    /**
    * Agrega una partícula al bloque.
    *
    * @param id Identificador único de la partícula.
    * @param position Posición de la partícula en coordenadas 3D.
    * @param hv Vector de características (hv) de la partícula.
    * @param velocity Vector de velocidad de la partícula.
    */
    void Block::AddParticle(size_t id, vec3 &position, vec3 &hv, vec3 &velocity) {
        ids_.push_back(id);
        positions_.push_back(position);
        hvs_.push_back(hv);
        velocities_.push_back(velocity);
    }

}
