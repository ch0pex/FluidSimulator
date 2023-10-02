#ifndef FLUID_SIMULATOR_HPP
#define FLUID_SIMULATOR_HPP

#include "sim/error.hpp"
#include "sim/proargs.hpp"

#include <span>
namespace sim {
  class Simulator {
  public:
    explicit Simulator(std::span<const char*> args_view);
    sim::error_code ParseArgs(); // 1- Check de argumentos
    sim::error_code InitSim(); // 2- Inicializacion de la simulacion
    sim::error_code ProcessSim(); // 3- Procesamiento de la simulacion
    sim::error_code StoreResults(); // 4- Almacenamiento de resultados
  private:
    sim::Proargs args_parser_;
    sim::ifld init_file_;
    sim::ofld final_file_;
    int nts_;
  };
}
#endif  // FLUID_SIMULATOR_HPP
