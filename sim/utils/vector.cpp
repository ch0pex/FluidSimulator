#include "vector.hpp"

namespace sim {
    //inicializamos las coordenadas a 0.0 en la clase vec3
    vec3::vec3() : x(0.0), y(0.0), z(0.0) {}

    /**
     * Suma dos objetos vec3.
     *
     * @param vector segundo objeto vec3 que se sumará a este objeto
     * @return nuevo objeto vec3 resultado de la suma
     */
    vec3 vec3::operator+(const vec3 &vector) const {
        return {x + vector.x, y + vector.y, z + vector.z};
    }

    /**
     * asignación para sumar otro objeto vec3 al objeto actual y actualizarlo
     *
     * @param vector segundo objeto vec3 que se sumará a este objeto
     * @return referencia al objeto vec3 actual después de la suma
     */
    vec3 vec3::operator+=(const vec3 &vector) {
        x += vector.x;
        y += vector.y;
        z += vector.z;
        return *this; // Devuelve una referencia al objeto actual después de la operación
    }

    /**
     *  restar dos objetos vec3.
     *
     * @param vector Sgundo objeto vec3 que se restará de este objeto
     * @return nuevo objeto vec3 que es el resultado de la resta
     */
    vec3 vec3::operator-(const vec3 &vector) const {
        return {x - vector.x, y - vector.y, z - vector.z};
    }

    /**
     * signación para restar otro objeto vec3 al objeto actual y actualizarlo.
     *
     * @param vector Segundo objeto vec3 que se restará de este objeto.
     * @return referencia al objeto vec3 actual después de la resta.
     */

    vec3 vec3::operator-=(const vec3 &vector) {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;
        return *this;
    }

    /**
     * imprimir un objeto vec3 en un flujo de salida (como std::cout)
     *
     * @param os flujo de salida donde se imprimirá el objeto vec3
     * @param v objeto vec3 que se imprimirá
     * @return flujo de salida después de la operación de impresión
     */
    std::ostream &operator<<(std::ostream &os, const vec3 &v) {
        os << v.x << " x " << v.y << " x " << v.z;
        return os;
    }

}
