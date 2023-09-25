#ifndef FLUID_FLUID_HPP
#define FLUID_FLUID_HPP

#include <sim/proargs.hpp>

using namespace sim;

class Fluid {
public:
    Fluid(int argc, char* argv[]);
    int ParseArgs(); // 1- Check de argumentos
    int InitSim(); // 2- Inicializacion de la simulacion
    int ProcessSim(); // 3- Procesamiento de la simulacion
    int StoreResults(); // 4- Almacenamiento de resultados
private:
    Proargs args_parser_;
    std::ifstream init_file_;
    std::ofstream final_file_;
    int nts_;
};
#endif //FLUID_FLUID_HPP
