#include "sim/grid/block.hpp"
#include <gtest/gtest.h>
#include <set>

namespace sim {
  // Definición de constantes para la configuración inicial de partículas
constexpr vec3d kInitialPositionOffset = vec3d(-0.06649009138345718, -0.07730470597743988, -0.059135954827070236);
constexpr vec3d kHvVector = vec3d(4.0, 5.0, 6.0);
constexpr vec3d kVelocityIncrement = vec3d(1.0, 8.0, 9.0);
constexpr double def_position = 100.0;

  // Test para probar colisiones
  TEST(Block, TestCollisionZ) {
    // Creación de un bloque opcional y un conjunto de límites
    Block block;
    std::set<Limits> limits = {CZN};
    constexpr double expected_acceleration = -2999388.0000000005;

    // Configuración de una partícula específica para el test
    constexpr size_t particle_id = 1;
    vec3d position = kInitialPositionOffset;
    vec3d vec_hv = kHvVector;
    vec3d velocity = kVelocityIncrement;
    Particle particle(particle_id, position, vec_hv, velocity);

    // Se establece una posición inusual para provocar una colisión en el eje z
    particle.position.z = def_position;

    // Se añade la partícula al bloque y se procesan las colisiones
    block.AddParticle(particle);
    block.ProcessCollisions(limits);
    const double new_acceleration = block.GetParticles()[0].acceleration.z;
    ASSERT_EQ(new_acceleration, expected_acceleration);
  }

  TEST(Block, TestCollisionX) {
    // Creación de un bloque opcional y un conjunto de límites
    Block block;
    std::set<Limits> limits = {CXN};
    constexpr double expected_acceleration = -2998304.0000000005;
    // Configuración de una partícula específica para el test
    constexpr size_t particle_id = 1;
    vec3d position = kInitialPositionOffset;
    vec3d vec_hv = kHvVector;
    vec3d velocity = kVelocityIncrement;
    Particle particle(particle_id, position, vec_hv, velocity);

    // Se establece una posición inusual para provocar una colisión en el eje x
    particle.position.x = def_position;

    // Se añade la partícula al bloque y se procesan las colisiones
    block.AddParticle(particle);
    block.ProcessCollisions(limits);
    const double new_acceleration = block.GetParticles()[0].acceleration.x;
    ASSERT_EQ(new_acceleration, expected_acceleration);
  }

  TEST(Block, TestCollisionY) {
    // Creación de un bloque opcional y un conjunto de límites
    Block block;
    std::set<Limits> limits = {CYN};
    constexpr double expected_acceleration = -2998189.8000000003;
    // Configuración de una partícula específica para el test
    constexpr size_t particle_id = 1;
    vec3d position = kInitialPositionOffset;
    vec3d vec_hv = kHvVector;
    vec3d velocity = kVelocityIncrement;
    Particle particle(particle_id, position, vec_hv, velocity);

    // Se establece una posición inusual para provocar una colisión en el eje Y
    particle.position.y = def_position;

    // Se añade la partícula al bloque y se procesan las colisiones
    block.AddParticle(particle);
    block.ProcessCollisions(limits);
    const double new_acceleration = block.GetParticles()[0].acceleration.y;
    ASSERT_EQ(new_acceleration, expected_acceleration);
  }

  // Test para probar los límites del bloque
  TEST(Block, TestLimitsZ) {
    // Creación de un bloque opcional y un conjunto de límites
    Block block;
    std::set<Limits> limits = {CZN};
    constexpr double position_expected = -99.87; // Posicion en Z esperada despues de ProcessLimits

    // Configuración de una partícula específica para el test
    constexpr size_t particle_id = 1;
    vec3d position = kInitialPositionOffset;
    vec3d vec_hv = kHvVector;
    vec3d velocity = kVelocityIncrement;
    Particle particle(particle_id, position, vec_hv, velocity);

    // Se establece una posición inusual para provocar una colisión en el eje z
    particle.position.z = def_position;

    // Se añade la partícula al bloque y se procesan las colisiones
    block.AddParticle(particle);
    block.ProcessLimits(limits);
    const double new_position = block.GetParticles()[0].position.z;
    ASSERT_EQ(new_position, position_expected);
  }

  TEST(Block, TestLimitsX) {
    // Creación de un bloque opcional y un conjunto de límites
    Block block;
    std::set<Limits> limits = {CXN};
    constexpr double position_expected = -99.87; // Posicion en X esperada despues de ProcessLimits
    // Configuración de una partícula específica para el test
    constexpr size_t particle_id = 1;
    vec3d position = kInitialPositionOffset;
    vec3d vec_hv = kHvVector;
    vec3d velocity = kVelocityIncrement;
    Particle particle(particle_id, position, vec_hv, velocity);

    // Se establece una posición inusual para provocar una colisión en el eje x
    particle.position.x = def_position;

    // Se añade la partícula al bloque y se procesan las colisiones
    block.AddParticle(particle);
    block.ProcessLimits(limits);
    const double new_position = block.GetParticles()[0].position.x;
    ASSERT_EQ(new_position, position_expected);
  }

  TEST(Block, TestLimitsY) {
    // Creación de un bloque opcional y un conjunto de límites
    Block block;
    std::set<Limits> limits = {CYN};
    constexpr double position_expected = -99.800000000000011; // Posicion en y esperada despues de ProcessLimits
    // Configuración de una partícula específica para el test
    constexpr size_t particle_id = 1;
    vec3d position = kInitialPositionOffset;
    vec3d vec_hv = kHvVector;
    vec3d velocity = kVelocityIncrement;
    Particle particle(particle_id, position, vec_hv, velocity);

    // Se establece una posición inusual para provocar una colisión en el eje Y
    particle.position.y = def_position;

    // Se añade la partícula al bloque y se procesan las colisiones
    block.AddParticle(particle);
    block.ProcessLimits(limits);
    const double new_position = block.GetParticles()[0].position.y;
    ASSERT_EQ(new_position, position_expected);
  }
} // namespace sim
