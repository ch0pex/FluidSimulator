#ifndef ARQUICOMP_P1_PROARGS_HPP
#define ARQUICOMP_P1_PROARGS_HPP

#include <cstdint>
#include <string_view>

#include "sim/fld.hpp"

namespace sim {
class Proargs{
public:
    explicit Proargs(int argc, char* argv[]);
    [[nodiscard]] int CheckCount() const;
    int CheckNts(int& nts);
    int CheckFiles(sim::ifld& init_file, sim::ofld& final_file);

private:
    int argc_;
    char** argv_;
};
}

#endif //ARQUICOMP_P1_PROARGS_HPP