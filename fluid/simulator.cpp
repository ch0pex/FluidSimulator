#include "simulator.hpp"

#include <iostream>
#include <vector>


Simulator::Simulator(const std::span<const char*> args_view) :
    args_parser_(args_view),
    nts_(0)
{
}

int Simulator::ParseArgs() {
  int err = 0;
  //[[likely]] o [[unlikely]]?
  err = args_parser_.CheckCount();
  if (err != 0) {
    return (err);
  }

  err = args_parser_.CheckNts(nts_);
  if (err != 0) {
    return (-1);
  }

  err = args_parser_.CheckFiles(init_file_, final_file_);
  if (err != 0) {
    return err;
  }
  return err;
}

int Simulator::InitSim() {
  int np = 0;
  int err = 0;
  double ppm = 0.0;
  err = init_file_.ReadHeader(ppm, np);
  if (err != 0) {
    return (err);
  }
  err = init_file_.ReadParticles();
  if (err != 0) {
    return (err);
  }

  std::cout << "ppm: " << ppm << std::endl;
  std::cout << "np: " << np << std::endl;
  return (0);
}

int Simulator::ProcessSim() {
  return 0;
}

int Simulator::StoreResults() {
  return 0;
}

