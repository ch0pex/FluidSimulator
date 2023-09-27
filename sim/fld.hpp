#ifndef FLUID_FLD_HPP
#define FLUID_FLD_HPP

#include <fstream>
#include <vector>

namespace sim {
class ifld {
public:
    explicit ifld(const char* path);
    ~ifld();
    int ReadHeader(double& ppm, int& np);
    int ReadParticles();
    operator bool();
private:
    std::ifstream input_file_;
    std::vector<double> particles;
    bool is_open_;
    size_t length_;
};


class ofld {
public:
    ofld(const char* path);
    ~ofld();
    int WriteHeader();
    int WriteParticles();
    operator bool();
private:
    std::ofstream output_file_;
    size_t length_;
    bool is_open_;
};
}


#endif //FLUID_FLD_HPP
