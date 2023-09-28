#include "proargs.hpp"
#include <iostream>

namespace sim {
Proargs::Proargs(int argc, char **argv) : argc_(argc), argv_(argv){}

int Proargs::CheckCount() {
    if (argc_ != 4) {
        std::cout << "Error: Invalid number of arguments: " << argc_ << std::endl;
        return (-1);
    }
    return (0);
}

int Proargs::CheckNts(int& nts) {
    char* endPtr;
    long nts_long = std::strtol(argv_[1], &endPtr, 10); // Se usa strtol para mejor prevencion de errores

    if (*endPtr != '\0') {
        std::cout << "Error: time step must be numeric" << std::endl;
        return (-1);
    }
    if (nts_long <= 0) {
        std::cout << "Error: Invalid number of time steps" << std::endl;
        return (-2);
    }
    nts = static_cast<int>(nts_long);
    return (0);
}

int Proargs::CheckFiles(sim::ifld& init_file, sim::ofld& final_file) {
    if(!init_file) {
        std::cout << "Error: Cannot open " << argv_[2] << " for reading" << std::endl;
        return (-3);
    }

    if(!final_file) {
        std::cout << "Error: Cannot open " << argv_[3] << " for writing" << std::endl;
        return (-4);
    }
    return (0);
}
}