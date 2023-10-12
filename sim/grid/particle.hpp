#ifndef FLUID_PARTICLE_HPP
#define FLUID_PARTICLE_HPP

#include "sim/utils/vector.hpp"


namespace sim {
    struct Particle {

        Particle(size_t _id, vec3 &_position, vec3 &_hv, vec3 &_velocity);

        Particle(const Particle &);

        Particle& operator=(const Particle& other);

        size_t id;

        vec3 position;

        vec3 hv;

        vec3 velocity;

        vec3 acceleration;

        double density;
    };
}


#endif //FLUID_PARTICLE_HPP
