#include "fluid.hpp"
#include <vector>
#include <iostream>

using namespace sim;

Fluid::Fluid(int argc, char **argv) :
    args_parser_(argc, argv),
    init_file_(argv[2]),
    final_file_(argv[3])
{
}

int Fluid::ParseArgs(){
    int err = 0;
    //[[likely]] o [[unlikely]]?
    if ((err = args_parser_.CheckCount()) != 0)
        return (err);
    if ((err = args_parser_.CheckNts(nts_)) != 0)
        return (-1);
    if ((err = args_parser_.CheckFiles(init_file_, final_file_)) != 0)
        return err;
    return err;
}


int Fluid::InitSim() {
    int np = 0;
    int err = 0;
    double ppm = 0.0;
    if ((err = init_file_.ReadHeader(ppm, np)) != 0)
        return (err);
    if (( err = init_file_.ReadParticles()) != 0)
        return (err);

    std::cout << "ppm: " << ppm << std::endl;
    std::cout << "np: " << np << std::endl;
    return (0);
}

int Fluid::ProcessSim() {
    return 0;
}

int Fluid::StoreResults() {
    return 0;
}
