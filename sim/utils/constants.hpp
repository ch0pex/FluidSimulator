#ifndef FLUID_CONSTANTS_HPP
#define FLUID_CONSTANTS_HPP

#include <array>
#include <chrono>
#include <iostream>
#include <string>

#include "vector.hpp"

namespace sim {
    // CONSTANTES ESCALARES
    constexpr double MUL_RAD = 1.695; //r
    constexpr double DENSITY = 1000.0; //p
    constexpr double PRESSURE = 3.0; //p_s
    constexpr double COLLISION = 30000.0;//s_c
    constexpr double DAMPING = 128.0; //d_v
    constexpr double GOO = 0.4; //NU
    constexpr double P_SIZE = 0.0002; //d_r
    constexpr double TIME_STEP = 0.001; //DELTA*t

    // Aceleracion externa
    constexpr vec3 GRAVITY = {0.0, 9.8, 0.0};
    // Límite superior del recinto
    constexpr vec3 BOTTOM_LIMIT = {-0.065, -0.08, -0.065};
    // Límite inferior del recinto
    constexpr vec3 TOP_LIMIT = {0.065, 0.1, 0.065};

    // Constantes fichero
    constexpr size_t SIZE_HEADER = 8;

    //particle components
    constexpr size_t PARTICLE_COMPONENTS = 9;
}

#endif //FLUID_CONSTANTS_HPP