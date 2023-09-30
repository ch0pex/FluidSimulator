#include <span>

#include "simulator.hpp"
#include "sim/proargs.hpp"

int main(int argc, const char* argv[]) {
  const std::span<const char*>  args_view{argv, static_cast<size_t>(argc)};
  Simulator fluid_sim = Simulator(args_view);
  int err = 0;
  //1- Comprobacion de argumentos
  err = fluid_sim.ParseArgs();
  if (err == 0)
  {
    //2- Inicializacion de la simulacion
    err = fluid_sim.InitSim();
    if (err == 0) {
      //3- Procesamiento de pasos de tiempo
      fluid_sim.ProcessSim();
      //4- Almacenamiento de resultados
      fluid_sim.StoreResults();
    }
  }
  return(err);
}