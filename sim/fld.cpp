#include "fld.hpp"

#include <iostream>
#include <chrono>

namespace sim {
ifld::ifld(const char *path) : is_open_(false) {
    input_file_.open(path, std::ios::binary);
    if (input_file_)
        is_open_ = true;
    input_file_.seekg(0, input_file_.end);
    length_ = input_file_.tellg();
    input_file_.seekg(0, input_file_.beg);
}

ifld::~ifld() {
    input_file_.close();
}

int ifld::ReadHeader(double& ppm, int& np) {
    char buffer[4];

    input_file_.seekg(0, input_file_.beg);
    input_file_.read(buffer, 4);
    ppm = static_cast<double>(*reinterpret_cast<float*>(buffer));
    input_file_.read(buffer, 4);
    np = *reinterpret_cast<int*>(buffer);

    if (np <= 0){
        std::cout << "Invalid number of particles" << std::endl;
        return (-5);
    }

    if (static_cast<size_t>(np) != ((length_ - 8) / 4) / 9) {
        std::cout << "Number of particles mismatch. Header: " << np << " Found: " << ((length_ - 8) / 4) / 9 << std::endl;
        return (-5);
    }
    return (0);
}

int ifld::ReadParticles() {
    char buffer[4];

    input_file_.seekg(8, input_file_.beg);
    particles.reserve((length_ - 8) / 4);
    for(size_t i = 0; i < length_ - 8;  i+=4){
        input_file_.read(buffer, 4);
        particles.push_back(static_cast<double>(*reinterpret_cast<float*>(buffer)));
    }
    return (0);
}

ifld::operator bool() {
    return is_open_;
}



//TODO
ofld::ofld(const char *path) {
    output_file_.open(path);
    if (output_file_)
        is_open_ = true;
}

ofld::~ofld() {
    output_file_.close();
}

int ofld::WriteHeader() {
    return 0;
}

int ofld::WriteParticles() {
    return 0;
}

ofld::operator bool() {
    return is_open_;
}
}