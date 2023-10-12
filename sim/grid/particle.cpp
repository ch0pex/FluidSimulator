//
// Created by alvaro on 11/10/23.
//

#include "particle.hpp"

namespace sim {
    Particle::Particle(size_t _id, vec3 &_position, vec3 &_hv, vec3 &_velocity)
            : id(_id),
              position(_position),
              hv(_hv),
              velocity(_velocity),
              acceleration({0.0, 0.0, 0.0})
              {
    }

    Particle::Particle(const sim::Particle &other)
            : id(other.id),
              position(other.position),
              hv(other.hv),
              velocity(other.velocity),
              acceleration({0.0, 0.0, 0.0})
              {
    }

    Particle& Particle::operator=(const Particle& other) {
        if(this != &other){
            id = other.id;
            position = other.position;
            hv = other.hv;
            velocity = other.velocity;
        }
        return *this;
    }
}
