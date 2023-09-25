#include "fluid.hpp"

using namespace sim;

Fluid::Fluid(int argc, char **argv) : args_parser_(argc, argv) { }

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
    return 0;
}

int Fluid::ProcessSim() {
    return 0;
}

int Fluid::StoreResults() {
    return 0;
}
