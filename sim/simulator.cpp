#include "simulator.hpp"

#include <iostream>
#include <vector>

namespace sim {
  Simulator::Simulator(const std::span<const char*> args_view) :
      args_parser_(args_view),
      nts_(0)
  {
  }

  sim::error_code Simulator::ParseArgs() {
    error_code err = SUCCESS;

    err = args_parser_.CheckCount();
    if (err != SUCCESS) { //[[likely]] o [[unlikely]]?
      return (err);
    }

    err = args_parser_.CheckNts(nts_);
    if (err != 0) {
      return (err);
    }

    err = args_parser_.CheckFiles(init_file_, final_file_);
    if (err != SUCCESS) {
      return (err);
    }

    return (err);
  }

  sim::error_code Simulator::InitSim() {
    sim::error_code err = SUCCESS;
    int num_particles = 0;
    double ppm = 0.0;

    err = init_file_.ReadHeader(ppm, num_particles);
    if (err != SUCCESS) {
      return (err);
    }

    err = init_file_.ReadParticles();
    if (err != SUCCESS) {
      return (err);
    }

    grid_.emplace(num_particles, ppm);
    return (err);
  }

  sim::error_code Simulator::ProcessSim() {
    for(int i = 0; i < nts_; i++) {

    }
    return (SUCCESS);
  }

  sim::error_code Simulator::StoreResults() {
    return (SUCCESS);
  }

}
