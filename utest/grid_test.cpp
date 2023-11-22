#include "sim/grid/grid.hpp"
#include "sim/grid/particle.hpp"

#include <gtest/gtest.h>

namespace sim {
  // setting the environment variables that will be used in testing
const size_t kParticleCount = 10;
const size_t kBlockSize = 10;
const double kParticlesPerMeter = 100.1;

const vec3d kInitialPositionOffset = vec3d(-0.06649009138345718, -0.07730470597743988, -0.059135954827070236);
const vec3d kHvVector = vec3d(4.0, 5.0, 6.0);
const vec3d kVelocityIncrement = vec3d(1.0, 8.0, 9.0);
const double kDensityMultiplier = 0.8571428571428572;
const double asserted_mass = 0.00099700599001497931;

// Test constructor and GetNumParticles method
  TEST(GridTest, TestDensity) {
    // Initialize the Grid with specific parameters and particles
    std::optional<Grid> grid;
    std::vector<Particle> particles;
    // Starting with a particle that is in block 1
    for (size_t i = 1; i <= kParticleCount; ++i) {
      const double j = kDensityMultiplier * i;
      const size_t id = i;
      vec3d position = kInitialPositionOffset - vec3d(j, 0.0, 0.0);
      vec3d hv = kHvVector;
      vec3d velocity = kVelocityIncrement * static_cast<double>(i);

      particles.emplace_back(id, position, hv, velocity);
    }
    grid.emplace(kBlockSize, kParticlesPerMeter, particles);

    grid->CalculateAccelerations();

    const double density = grid->GetBlocks().at(0).GetParticles().at(0).density;

    EXPECT_NE(particles.at(0).density, density);
  }

  TEST(GridTest, TestAcceleration) {
    // Initialize the Grid with specific parameters and particles
    std::optional<Grid> grid;
    std::vector<Particle> particles;
    // Starting with a particle that is in block 1
    for (size_t i = 1; i <= kParticleCount; ++i) {
      const double j = kDensityMultiplier * i;
      const size_t id = i;
      vec3d position = kInitialPositionOffset - vec3d(j, 0.0, 0.0);
      vec3d hv = kHvVector;
      vec3d velocity = kVelocityIncrement * static_cast<double>(i);

      particles.emplace_back(id, position, hv, velocity);
    }
    grid.emplace(kBlockSize, kParticlesPerMeter, particles);

    grid->ProcessCollisions();

    const double acceleration_x = grid->GetBlocks()[0].GetParticles()[0].acceleration.x;

    EXPECT_NE(particles[0].acceleration.x, acceleration_x);
  }

  TEST(GridTest, TestMoveParticles) {
    // Initialize the Grid with specific parameters and particles
    std::optional<Grid> grid;
    std::vector<Particle> particles;
    // Starting with a particle that is in block 1
    for (size_t i = 1; i <= kParticleCount; ++i) {
      const double j = kDensityMultiplier * i;
      const size_t id = i;
      vec3d position = kInitialPositionOffset - vec3d(j, 0.0, 0.0);
      vec3d hv = kHvVector;
      vec3d velocity = kVelocityIncrement * static_cast<double>(i);

      particles.emplace_back(id, position, hv, velocity);
    }
    grid.emplace(kBlockSize, kParticlesPerMeter, particles);

    grid->MoveParticles();

    const double position_x = grid->GetBlocks()[0].GetParticles()[0].position.x;

    EXPECT_NE(particles[0].position.x, position_x);
  }

  TEST(GridTest, TestRepositioning) {
    // Initialize the Grid with specific parameters and particles
    std::optional<Grid> grid;
    std::vector<Particle> particles;
    // Starting with a particle that is in block 1
    for (size_t i = 1; i <= kParticleCount; ++i) {
      const double j = kDensityMultiplier * i;
      const size_t id = i;
      vec3d position = kInitialPositionOffset - vec3d(j, 0.0, 0.0);
      vec3d hv = kHvVector;
      vec3d velocity = kVelocityIncrement * static_cast<double>(i);

      particles.emplace_back(id, position, hv, velocity);
    }
    grid.emplace(kBlockSize, kParticlesPerMeter, particles);

    grid->ProcessLimits();

    const double position_x = grid->GetBlocks()[0].GetParticles()[0].position.x;

    EXPECT_NE(particles[0].position.x, position_x);
  }

  TEST(GridTest, TestNumParticles) {
    // Initialize the Grid with specific parameters and particles
    std::optional<Grid> grid;
    std::vector<Particle> particles;
    // Starting with a particle that is in block 1
    for (size_t i = 1; i <= kParticleCount; ++i) {
      const double j = kDensityMultiplier * i;
      const size_t id = i;
      vec3d position = kInitialPositionOffset - vec3d(j, 0.0, 0.0);
      vec3d hv = kHvVector;
      vec3d velocity = kVelocityIncrement * static_cast<double>(i);

      particles.emplace_back(id, position, hv, velocity);
    }
    grid.emplace(kBlockSize, kParticlesPerMeter, particles);

    const int num_particles = grid->GetNumParticles();

    EXPECT_EQ(num_particles, kParticleCount);
  }

  TEST(GridTest, TestGetParticlesPerMeter) {
    // Initialize the Grid with specific parameters and particles
    std::optional<Grid> grid;
    std::vector<Particle> particles;
    // Starting with a particle that is in block 1
    for (size_t i = 1; i <= kParticleCount; ++i) {
      const double j = kDensityMultiplier * i;
      size_t id = i;
      vec3d position = kInitialPositionOffset - vec3d(j, 0.0, 0.0);
      vec3d hv = kHvVector;
      vec3d velocity = kVelocityIncrement * static_cast<double>(i);

      particles.emplace_back(id, position, hv, velocity);
    }
    grid.emplace(kBlockSize, kParticlesPerMeter, particles);

    const double num_particles = grid->GetParticlesPerMeter();

    EXPECT_EQ(num_particles, kParticlesPerMeter);
  }

  TEST(GridTest, TestParticlesData) {
    // Initialize the Grid with specific parameters and particles
    std::optional<Grid> grid;
    std::vector<Particle> particles;
    // Starting with a particle that is in block 1
    for (size_t i = 1; i <= kParticleCount; ++i) {
      const double j = kDensityMultiplier * i;
      size_t id = i;
      vec3d position = kInitialPositionOffset - vec3d(j, 0.0, 0.0);
      vec3d hv = kHvVector;
      vec3d velocity = kVelocityIncrement * static_cast<double>(i);

      particles.emplace_back(id, position, hv, velocity);
    }
    grid.emplace(kBlockSize, kParticlesPerMeter, particles);

    const ParticlesData& particles_data = grid->GetParameters();

    EXPECT_EQ(particles_data.mass, asserted_mass);
  }
}