#include "fluid.hpp"

int main(int argc, char* argv[]) {
    int err;
    Fluid fluid_sim = Fluid(argc, argv);

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
