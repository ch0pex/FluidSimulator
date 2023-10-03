#ifndef FLUID_SIMULATOR_HPP
#define FLUID_SIMULATOR_HPP

#include <span>
#include <optional>

#include "sim/error.hpp"
#include "sim/proargs.hpp"
#include "grid.hpp"


namespace sim {
    /**
     * Clase que representa al simulador de fluidos, contiene todos los metodos para ejecutar las distintas
     * fases de la simulaicon asi como el grid, los ficheros y el numero de iteraciones
     */
    class Simulator {
    public:
        explicit Simulator(std::span<const char *> args_view);

        sim::error_code ParseArgs();

        sim::error_code InitSim();

        sim::error_code ProcessSim();

        sim::error_code StoreResults();

    private:
        sim::Proargs args_parser_;
        sim::ifld init_file_;
        sim::ofld final_file_;
        std::optional<Grid> grid_;
        int nts_;
    };
}
#endif  // FLUID_SIMULATOR_HPP
