#ifndef FLUID_FLD_HPP
#define FLUID_FLD_HPP

#include <fstream>
#include <vector>

#include "error.hpp"

namespace sim {
    /// Clase encargada de la lectura de fichero .fld
    class ifld {
    public:
        explicit ifld(const std::string &path);

        ifld();

        ~ifld();

        void Open(const std::string &path);

        void Close();

        sim::error_code ReadHeader(double &ppm, int &np);

        sim::error_code ReadParticles();

        operator bool() const;

    private:
        std::ifstream input_file_;
        std::vector<double> particles;
        size_t length_;
    };

    /// Clase encargada de la escritura de fichero .fld
    class ofld { //TODO: Implementar escritura
    public:
        explicit ofld(const std::string &path);

        ofld();

        ~ofld();

        void Open(const std::string &path);

        void Close();

        sim::error_code WriteHeader();

        sim::error_code WriteParticles();

        operator bool() const;

    private:
        std::ofstream output_file_;
    };
}


#endif //FLUID_FLD_HPP
