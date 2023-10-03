#ifndef ARQUICOMP_P1_BLOCK_HPP
#define ARQUICOMP_P1_BLOCK_HPP

#include <vector>

namespace sim {
    class Block {
    public:
        Block();

        inline bool IsComputed();

    private:
        bool comptuted_;
        //Particles
        std::vector<double> positions_;
        std::vector<double> hvs_;
        std::vector<double> velocities_;
        std::vector<double> densisties_;
    };
}
#endif //ARQUICOMP_P1_BLOCK_HPP
