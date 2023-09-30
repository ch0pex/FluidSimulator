#include "proargs.hpp"
#include <iostream>
#include "fld.hpp"

namespace sim {
  Proargs::Proargs(const std::span<const char*> args_view) : args_(args_view.begin(), args_view.end()) { }

  int Proargs::CheckCount() const {
    if (args_.size() != 4) {
      std::cout << "Error: Invalid number of arguments: " << args_.size() << "\n";
      return (-1);
    }
    return (0);
  }

  int Proargs::CheckNts(int &nts) {
    char* endPtr = nullptr;
    const long nts_long = std::strtol(args_.at(1), &endPtr, 10); // Se usa strtol para mejor prevencion de errores

    if (*endPtr != '\0') {
      std::cout << "Error: time step must be numeric\n";
      return (-1);
    }
    if (nts_long <= 0) {
      std::cout << "Error: Invalid number of time steps\n";
      return (-2);
    }
    nts = static_cast<int>(nts_long);
    return (0);
  }

  int Proargs::CheckFiles(sim::ifld& init_file, sim::ofld& final_file) {
    init_file.Open(GetInitPath());
    if(!init_file) {
      std::cout << "Error: Cannot open " << args_.at(2) << " for reading\n";
      return (-3);
    }

    final_file.Open(GetFinalPath());
    if(!final_file) {
      std::cout << "Error: Cannot open " << args_.at(3) << " for writing\n";
      return (-4);
    }
    return (0);
  }

}