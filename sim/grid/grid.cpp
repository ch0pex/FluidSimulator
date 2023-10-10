#include "grid.hpp"
#include "sim/utils/constants.hpp"

#include <iostream>
#include <cmath>


namespace sim {

   /**
   * Constructor de la clase Grid
   *
   * @param np número total de partículas
   * @param ppm partículas por metro, la densidad de partículas en el grid
   * @param data vector que contiene las posiciones y características de las partículas.
   */
    Grid::Grid(int np, double ppm, std::vector<vec3> &data)
            : np_(np), ppm_(ppm),
              h_(MUL_RAD / ppm_),
              m_(DENSITY / pow(ppm_, 3)),
              grid_size_({
                                 std::floor((TOP_LIMIT.x - BOTTOM_LIMIT.x) / h_),
                                 std::floor((TOP_LIMIT.y - BOTTOM_LIMIT.y) / h_),
                                 std::floor((TOP_LIMIT.z - BOTTOM_LIMIT.z) / h_)
                         }),
              block_size_({
                                  (TOP_LIMIT.x - BOTTOM_LIMIT.x) / grid_size_.x,
                                  (TOP_LIMIT.y - BOTTOM_LIMIT.y) / grid_size_.y,
                                  (TOP_LIMIT.z - BOTTOM_LIMIT.z) / grid_size_.z,
                          }),
              blocks_(static_cast<size_t>(grid_size_.x * grid_size_.y * grid_size_.z)) {
        InitMessage();

        // Itera a través de los datos de las partículas y asigna cada partícula a un bloque en la cuadrícula.
        for(size_t i = 0; i < data.size(); i+=3) {
           const size_t block_index = GetBlockIndex(data[i]); //Coger la posicion de la particula comprobar en que bloque le toca
           blocks_[block_index].AddParticle(i/3, data[i], data[i + 1], data[i + 2]); //Anadir la particula a dicho bloque
        }
    }

    void Grid::InitMessage() const {
        std::cout << "Number of particles: " << np_ << "\n";
        std::cout << "Particles per meter: " << ppm_ << "\n";
        std::cout << "Smoothing length: " << h_ << "\n";
        std::cout << "Particles Mass: " << m_ << "\n";
        std::cout << "Grid size: " << grid_size_ << "\n";
        std::cout << "Number of blocks: " << blocks_.size() << "\n";
        std::cout << "Block size: " << block_size_ << "\n";
    }

     /**
     * Obtiene el índice del bloque al que pertenece una partícula
     *
     * @param particle_pos posición de la partícula en coordenadas x,y,z
     * @return índice del bloque al que pertenece la partícula en la cuadrícula.
     */
    size_t Grid::GetBlockIndex(vec3 &particle_pos) {
        // i,j,k posicion del bloque en la malla --> pasarlo al indice del bloque
        double pos_i = (particle_pos.x - BOTTOM_LIMIT.x) / block_size_.x;
        double pos_j = (particle_pos.y - BOTTOM_LIMIT.y) / block_size_.y;
        double pos_k = (particle_pos.z - BOTTOM_LIMIT.z) / block_size_.z;

        // Asegura que las coordenadas estén dentro de los límites de la cuadrícula
        pos_i = pos_i >= 0 ? pos_i : 0;
        pos_i = pos_i < grid_size_.x ? pos_i : grid_size_.x;
        pos_j = pos_j >= 0 ? pos_j : 0;
        pos_j = pos_j < grid_size_.y ? pos_j : grid_size_.y;
        pos_k = pos_k >= 0 ? pos_k : 0;
        pos_k = pos_k < grid_size_.z ? pos_k : grid_size_.z;

        // Calcula el índice del bloque utilizando las coordenadas en la cuadrícula.
        return (static_cast<size_t>(pos_i) + static_cast<size_t>(pos_j) * static_cast<size_t>(grid_size_.y) + static_cast<size_t>(pos_k) * static_cast<size_t>(grid_size_.z));
    }
}