#ifndef FLUID_SIMULATOR_HPP
#define FLUID_SIMULATOR_HPP

#include <sim/proargs.hpp>
#include <span>


class Simulator {
public:
    explicit Simulator(std::span<const char*> args_view);
    int ParseArgs(); // 1- Check de argumentos
    int InitSim(); // 2- Inicializacion de la simulacion
    int ProcessSim(); // 3- Procesamiento de la simulacion
    int StoreResults(); // 4- Almacenamiento de resultados
private:
    sim::Proargs args_parser_;
    sim::ifld init_file_;
    sim::ofld final_file_;
    int nts_;
};
#endif  // FLUID_SIMULATOR_HPP
