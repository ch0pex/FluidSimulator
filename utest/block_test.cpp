#include "sim/grid/block.hpp"
#include <gtest/gtest.h>
#include <set>

namespace sim {

  // Definición de constantes para la configuración inicial de partículas
const vec3d kInitialPositionOffset = vec3d(-0.06649009138345718, -0.07730470597743988, -0.059135954827070236);
const vec3d kHvVector = vec3d(4.0, 5.0, 6.0);
const vec3d kVelocityIncrement = vec3d(1.0, 8.0, 9.0);

  // Test para probar colisiones
  TEST(Block, TestCollisionZ) {
    // Creación de un bloque opcional y un conjunto de límites
    std::optional<Block> block;
    std::set<Limits> limits = {CZN};
    std::vector<Particle> particles;

    // Configuración de una partícula específica para el test
    size_t id = 1;
    vec3d position = kInitialPositionOffset;
    vec3d hv = kHvVector;
    vec3d velocity = kVelocityIncrement;
    particles.emplace_back(id, position, hv, velocity);
    Particle particle = particles[0];

    // Se establece una posición inusual para provocar una colisión en el eje z
    particle.position.z = 100;

    // Se añade la partícula al bloque y se procesan las colisiones
    block->AddParticle(particle);
    block->ProcessCollisions(limits);
    double cosas = block->GetParticles()[0].acceleration.z;
    ASSERT_EQ(cosas, -2999388.0000000005);
  }
  TEST(Block, TestCollisionX) {
    // Creación de un bloque opcional y un conjunto de límites
    std::optional<Block> block;
    std::set<Limits> limits = {CXN};
    std::vector<Particle> particles;

    // Configuración de una partícula específica para el test
    size_t id = 1;
    vec3d position = kInitialPositionOffset;
    vec3d hv = kHvVector;
    vec3d velocity = kVelocityIncrement;
    particles.emplace_back(id, position, hv, velocity);
    Particle particle = particles[0];

    // Se establece una posición inusual para provocar una colisión en el eje x
    particle.position.x = 100;

    // Se añade la partícula al bloque y se procesan las colisiones
    block->AddParticle(particle);
    block->ProcessCollisions(limits);
    double cosas = block->GetParticles()[0].acceleration.x;
    ASSERT_EQ(cosas, -2998304.0000000005);
  }
  TEST(Block, TestCollisionY) {
    // Creación de un bloque opcional y un conjunto de límites
    std::optional<Block> block;
    std::set<Limits> limits = {CYN};
    std::vector<Particle> particles;

    // Configuración de una partícula específica para el test
    size_t id = 1;
    vec3d position = kInitialPositionOffset;
    vec3d hv = kHvVector;
    vec3d velocity = kVelocityIncrement;
    particles.emplace_back(id, position, hv, velocity);
    Particle particle = particles[0];

    // Se establece una posición inusual para provocar una colisión en el eje Y
    particle.position.y = 100;

    // Se añade la partícula al bloque y se procesan las colisiones
    block->AddParticle(particle);
    block->ProcessCollisions(limits);
    double cosas = block->GetParticles()[0].acceleration.y;
    ASSERT_EQ(cosas, -2998189.8000000003);
  }

  // Test para probar los límites del bloque
  TEST(Block, TestLimitsZ) {
    // Creación de un bloque opcional y un conjunto de límites
    std::optional<Block> block;
    std::set<Limits> limits = {CZN};
    std::vector<Particle> particles;

    // Configuración de una partícula específica para el test
    size_t id = 1;
    vec3d position = kInitialPositionOffset;
    vec3d hv = kHvVector;
    vec3d velocity = kVelocityIncrement;
    particles.emplace_back(id, position, hv, velocity);
    Particle particle = particles[0];

    // Se establece una posición inusual para provocar una colisión en el eje z
    particle.position.z = 100;

    // Se añade la partícula al bloque y se procesan las colisiones
    block->AddParticle(particle);
    block->ProcessLimits(limits);
    double cosas = block->GetParticles()[0].position.z;
    ASSERT_EQ(cosas, -99.87);
  }
  TEST(Block, TestLimitsX) {
    // Creación de un bloque opcional y un conjunto de límites
    std::optional<Block> block;
    std::set<Limits> limits = {CXN};
    std::vector<Particle> particles;

    // Configuración de una partícula específica para el test
    size_t id = 1;
    vec3d position = kInitialPositionOffset;
    vec3d hv = kHvVector;
    vec3d velocity = kVelocityIncrement;
    particles.emplace_back(id, position, hv, velocity);
    Particle particle = particles[0];

    // Se establece una posición inusual para provocar una colisión en el eje x
    particle.position.x = 100;

    // Se añade la partícula al bloque y se procesan las colisiones
    block->AddParticle(particle);
    block->ProcessLimits(limits);
    double cosas = block->GetParticles()[0].position.x;
    ASSERT_EQ(cosas, -99.87);
  }
  TEST(Block, TestLimitsY) {
    // Creación de un bloque opcional y un conjunto de límites
    std::optional<Block> block;
    std::set<Limits> limits = {CYN};
    std::vector<Particle> particles;

    // Configuración de una partícula específica para el test
    size_t id = 1;
    vec3d position = kInitialPositionOffset;
    vec3d hv = kHvVector;
    vec3d velocity = kVelocityIncrement;
    particles.emplace_back(id, position, hv, velocity);
    Particle particle = particles[0];

    // Se establece una posición inusual para provocar una colisión en el eje Y
    particle.position.y = 100;

    // Se añade la partícula al bloque y se procesan las colisiones
    block->AddParticle(particle);
    block->ProcessLimits(limits);
    double cosas = block->GetParticles()[0].position.y;
    ASSERT_EQ(cosas, -99.800000000000011);
  }

} // namespace sim

