#ifndef FLUID_CONSTANTS_HPP
#define FLUID_CONSTANTS_HPP

#include "sim/math/vector.hpp"

#include <array>
#include <chrono>
#include <iostream>
#include <string>

namespace sim {
  // CONSTANTES ESCALARES
  constexpr double MUL_RAD   = 1.695;    // r
  constexpr double DENSITY   = 1000.0;   // p
  constexpr double PRESSURE  = 3.0;      // p_s
  constexpr double COLLISION = 30000.0;  // s_c
  constexpr double DAMPING   = 128.0;    // d_v
  constexpr double GOO       = 0.4;      // NU
  constexpr double PARTICLE_SIZE    = 0.0002;   // d_r
  constexpr double TIME_STEP = 0.001;    // DELTA*t
  constexpr double SQUARED_TIME_STEP = TIME_STEP * TIME_STEP;
  constexpr double PI = std::numbers::pi;
  constexpr double MINIMUN_DISTANCE = 0.000000000001;

  // Aceleracion externa
  constexpr vec3d GRAVITY = {0.0, -9.8, 0.0};
  // Límite superior del recinto
  constexpr vec3d BOTTOM_LIMIT = {-0.065, -0.08, -0.065};
  // Límite inferior del recinto
  constexpr vec3d TOP_LIMIT = {0.065, 0.1, 0.065};

  constexpr vec3<int> AXIS_X = {1, 0, 0};
  constexpr vec3<int> AXIS_Y = {0, 1, 0};
  constexpr vec3<int> AXIS_Z = {0, 0, 1};

  enum Limits {
    CX0,
    CY0,
    CZ0,
    CXN,
    CYN,
    CZN
  };

  // Constantes fichero
  constexpr size_t SIZE_HEADER = 8;

  // particle components
  constexpr size_t PARTICLE_COMPONENTS = 9;
}  // namespace sim

#endif  // FLUID_CONSTANTS_HPP
