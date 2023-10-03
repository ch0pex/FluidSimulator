#include "fld.hpp"

#include <array>
#include <cstring>
#include <iostream>


namespace sim {
    /**
     * Constructor explicito de la clase cuando se proporciona una path, se abre el archivo directamente
     * con permisos de lectura
     * @param path: Ruta del archivo que se desea leer
     */
    ifld::ifld(const std::string &path) : length_(0) {
        Open(path);
    }

    /**
     * Constructor por defecto de la clase, si no se proporciona ningun path, se colocan valores por
     * defecto en length y is_open
     */
    ifld::ifld() : length_(0) {}

    /**
     * Destructor de la clase, se asegura de que si el objeto ifld sale de scope el archivo se cierre
     */
    ifld::~ifld() {
        Close();
    }

    /**
     * Abre el fichero .fld como archivo binario con permisos de lectura, cambia el valor length
     * @param path: archivo .fld que se desea abrir
     */
    void ifld::Open(const std::string &path) { // TODO: Comprobar que el fichero es .fld?
        if (!input_file_.is_open()) {
            input_file_.open(path, std::ios::binary);
            input_file_.seekg(0, std::ifstream::end);
            length_ = input_file_.tellg();
            input_file_.seekg(0, std::ifstream::beg);
        }
    }

    /**
     * Cierra el archivo .fld si esta abierto
     */
    void ifld::Close() {
        if (input_file_.is_open()) {
            input_file_.close();
        }
    }

    /**
     * Lee el header del archivo y guarda sus valores si son correctos en los parametros
     * @param ppm  Referencia donde se guarda las particulas por metro especificadas en el header
     * @param np Referencia donde se guarda el numero de particulas especificado en el header
     * @return Si el numero de particulas es menor que 0 o no coincide con las particulas encontradas en el archivo
     * se devuelve PARTICLE_NUM_ERR (-5), en caso de exito se devuelve SUCCESS (0)
     */
    sim::error_code ifld::ReadHeader(double &ppm, int &np) {
        std::array<char, 4> buffer{};
        float tmp = 0.0F;

        input_file_.seekg(0, std::ifstream::beg);
        input_file_.read(buffer.data(), 4);
        std::memcpy(&tmp, buffer.data(), sizeof(float));
        ppm = static_cast<double>(tmp);
        input_file_.read(buffer.data(), 4);
        std::memcpy(&np, buffer.data(), sizeof(int));

        if (np <= 0) {
            std::cout << "Invalid number of particles\n";
            return (PARTICLE_NUM_ERR);
        }

        if (static_cast<size_t>(np) != ((length_ - 8) / 4) / 9) {
            std::cout << "Number of particles mismatch. Header: " << np << " Found: " << ((length_ - 8) / 4) / 9
                      << "\n";
            return (PARTICLE_NUM_ERR);
        }
        return (SUCCESS);
    }

    /**
     * Lee todas las particulas almacenadas en el fichero inicial
     * @return Devuelve SUCCESS (0)
     */
    sim::error_code ifld::ReadParticles() {
        std::array<char, 4> buffer{};
        float tmp = 0.0F;

        input_file_.seekg(8, std::ifstream::beg);
        particles.reserve((length_ - 8) / 4);
        for (size_t i = 0; i < length_ - 8; i += 4) {
            input_file_.read(buffer.data(), 4); // if (!input_file_) return SOME_ERROR?
            std::memcpy(&tmp, buffer.data(), 4);
            particles.push_back(static_cast<double>(tmp));
        }
        return (SUCCESS);
    }

    /**
     * Operador booleano de la clase
     * @return Devuelve true si hay un fichero fld abierto y false en caso contrario
     */
    ifld::operator bool() const {
        return input_file_.is_open();
    }


    /**
     * Constructor explicito de la clase cuando se proporciona una path, se abre el archivo
     * directamente con permisos escritura
     * @param path
     */
    ofld::ofld(const std::string &path) {
        Open(path);
    }

    /**
     * Constructor por defecto de ofld
     */
    ofld::ofld() = default;

    /**
     * Destructor de la clase, se asegura de que si el objeto ofld sale de scope el archivo se cierre
     */
    ofld::~ofld() {
        Close();
    }

    /**
     * Abre el fichero .fld como archivo binario con permisos de escritura
     * @param path: archivo .fld en el que se desea escribir
     */
    void ofld::Open(const std::string &path) {
        if (!output_file_.is_open()) {
            output_file_.open(path, std::ios::binary);
        }
    }

    /**
     * Cierra el archivo .fld si esta abierto
     */
    void ofld::Close() {
        if (output_file_.is_open()) {
            output_file_.close();
        }
    }

    /**
     *
     * @return
     */
    sim::error_code ofld::WriteHeader() {
        return (SUCCESS);
    }

    /**
     *
     * @return
     */
    sim::error_code ofld::WriteParticles() {
        return (SUCCESS);
    }

    /**
     *
     * @return
     */
    ofld::operator bool() const {
        return output_file_.is_open();
    }


}