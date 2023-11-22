#include "sim/grid/block.hpp"
#include <gtest/gtest.h>
#include <set>

namespace sim {

  // Definición de constantes para la configuración inicial de partículas
const vec3d kInitialPositionOffset = vec3d(-0.06649009138345718, -0.07730470597743988, -0.059135954827070236);
const vec3d kHvVector = vec3d(4.0, 5.0, 6.0);
const vec3d kVelocityIncrement = vec3d(1.0, 8.0, 9.0);

  // Test para probar colisiones
  TEST(Block, TestCollision) {
    // Creación de un bloque opcional y un conjunto de límites
    std::optional<Block> block;
    std::set<Limits> limits = {CXN, CYN, CZN};
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
    particle.position.x = 100;
    particle.position.z = 100;

    // Se añade la partícula al bloque y se procesan las colisiones
    block->AddParticle(particle);
    block->ProcessCollisions(limits);
  }

  // Test para probar los límites del bloque
  TEST(Block, TestLimits) {
    // Creación de un bloque opcional y un conjunto de límites
    std::optional<Block> block;
    std::set<Limits> limits = {CXN, CYN, CZN};
    std::vector<Particle> particles;

    // Configuración de una partícula específica para el test
    size_t id = 1;
    vec3d position = kInitialPositionOffset;
    vec3d hv = kHvVector;
    vec3d velocity = kVelocityIncrement;
    particles.emplace_back(id, position, hv, velocity);
    Particle particle = particles[0];

    // Se establece una posición inusual para verificar el procesamiento de límites
    particle.position.y = 100;
    particle.position.x = 100;
    particle.position.z = 100;

    // Se añade la partícula al bloque y se procesan los límites
    block->AddParticle(particle);
    block->ProcessLimits(limits);
  }

} // namespace sim

