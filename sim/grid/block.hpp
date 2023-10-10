#include <vector>

#include "sim/utils/vector.hpp"


namespace sim {
    class Block {
    public:
        Block();
        void AddParticle(size_t id, vec3& position, vec3& hv, vec3& velocity);
    private:
        bool is_computed;
        // Vectores que almacenan información de las partículas del bloque
        std::vector<size_t> ids_; //id de las partículas
        std::vector<vec3> positions_; //posiciones 3d de las partículas
        std::vector<vec3> hvs_; //vectores hv
        std::vector<vec3> velocities_; //vectores velocidad
    };
}