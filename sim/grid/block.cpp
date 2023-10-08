#include "block.hpp"
#include <iostream>

namespace sim {
    Block::Block() : is_computed(false) { }

    //TODO: comentar funcion
    void Block::AddParticle(size_t id, vec3 &position, vec3 &hv, vec3 &velocity) {
        ids_.push_back(id);
        positions_.push_back(position);
        hvs_.push_back(hv);
        velocities_.push_back(velocity);
    }

}
