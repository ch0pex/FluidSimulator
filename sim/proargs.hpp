#ifndef ARQUICOMP_P1_PROARGS_HPP
#define ARQUICOMP_P1_PROARGS_HPP

#include <cstdint>
#include <string_view>
#include <fstream>

namespace sim {
class Proargs{
public:
    explicit Proargs(int argc, char* argv[]);
    int CheckCount();
    int CheckNts(int& nts);
    int CheckFiles(std::ifstream& init_file, std::ofstream& final_file);

private:
    int argc_;
    char** argv_;
};
}

#endif //ARQUICOMP_P1_PROARGS_HPP