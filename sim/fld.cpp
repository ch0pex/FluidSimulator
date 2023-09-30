#include "fld.hpp"

#include <array>
#include <cstring>
#include <iostream>

namespace sim {
  ifld::ifld(const std::string& path) : is_open_(false), length_(0) {
    Open(path);
  }

  ifld::ifld() : is_open_(false), length_(0) { }

  ifld::~ifld() {
    Close();
  }

  void ifld::Open(const std::string& path) {
    if (!is_open_) {
      input_file_.open(path, std::ios::binary);
      if (input_file_) {
        is_open_ = true;
      }
      input_file_.seekg(0, std::ifstream::end);
      length_ = input_file_.tellg();
      input_file_.seekg(0, std::ifstream::beg);
    }
  }

  void ifld::Close() {
    if(is_open_){
      input_file_.close();
    }
  }

  int ifld::ReadHeader(double& ppm, int& np) {
    std::array<char, 4> buffer{};
    float tmp = 0.0F;

    input_file_.seekg(0, std::ifstream::beg);
    input_file_.read(buffer.data(), 4);
    std::memcpy(&tmp, buffer.data(), sizeof(float));
    ppm = static_cast<double>(tmp);
    input_file_.read(buffer.data(), 4);
    std::memcpy(&np, buffer.data(), sizeof(int));

    if (np <= 0){
      std::cout << "Invalid number of particles\n";
      return (-5);
    }

    if (static_cast<size_t>(np) != ((length_ - 8) / 4) / 9) {
      std::cout << "Number of particles mismatch. Header: " << np << " Found: " << ((length_ - 8) / 4) / 9 << "\n";
      return (-5);
    }
    return (0);
  }

  int ifld::ReadParticles() {
    std::array<char,4> buffer{};
    float tmp = 0.0F;

    input_file_.seekg(8, std::ifstream::beg);
    particles.reserve((length_ - 8) / 4);
    for(size_t i = 0; i < length_ - 8;  i+=4){
      input_file_.read(buffer.data(), 4);
      std::memcpy(&tmp, buffer.data(), 4);
      particles.push_back(static_cast<double>(tmp));
    }
    return (0);
  }

  ifld::operator bool() const {
    return is_open_;
  }


  //TODO
  ofld::ofld(const std::string& path) {
    Open(path);
  }

  ofld::ofld() : is_open_(false){ }

  ofld::~ofld() {
    Close();
  }

  void ofld::Open(const std::string & path) {
    if (is_open_) {
      return;
    }
    output_file_.open(path);
    if (output_file_) {
      is_open_ = true;
    }
  }

  void ofld::Close() {
    if (is_open_){
      output_file_.close();
    }
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