#include "vector.hpp"

#include <cmath>

namespace sim {
  // inicializamos las coordenadas a 0.0 en la clase vec3
  template <typename DataType>
  vec3<DataType>::vec3() : x(0.0), y(0.0), z(0.0) { }

  /**
   * Suma dos objetos vec3.
   *
   * @param vector segundo objeto vec3 que se sumará a este objeto
   * @return nuevo objeto vec3 resultado de la suma
   */
  template <typename DataType>
  vec3<DataType> vec3<DataType>::operator+(vec3 const & vector) const {
    return {x + vector.x, y + vector.y, z + vector.z};
  }

  /**
   * asignación para sumar otro objeto vec3 al objeto actual y actualizarlo
   *
   * @param vector segundo objeto vec3 que se sumará a este objeto
   * @return referencia al objeto vec3 actual después de la suma
   */
  template <typename DataType>
  vec3<DataType> vec3<DataType>::operator+=(vec3 const & vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;
    return *this;  // Devuelve una referencia al objeto actual después de la operación
  }

  /**
   *  restar dos objetos vec3.
   *
   * @param vector Sgundo objeto vec3 que se restará de este objeto
   * @return nuevo objeto vec3 que es el resultado de la resta
   */
  template <typename DataType>
  vec3<DataType> vec3<DataType>::operator-(vec3 const & vector) const {
    return {x - vector.x, y - vector.y, z - vector.z};
  }

  /**
   * signación para restar otro objeto vec3 al objeto actual y actualizarlo.
   *
   * @param vector Segundo objeto vec3 que se restará de este objeto.
   * @return referencia al objeto vec3 actual después de la resta.
   */
  template <typename DataType>
  vec3<DataType> vec3<DataType>::operator-=(vec3 const & vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
    return *this;
  }

  /**
   *
   * @tparam DataType
   * @param scalar
   * @return
   */
  template <typename DataType>
  vec3<DataType> vec3<DataType>::operator*(DataType scalar) const {
    return {x * scalar, y * scalar, z * scalar};
  }

  /**
   *
   * @tparam DataType
   * @param scalar
   * @return
   */
  template <typename DataType>
  vec3<DataType> vec3<DataType>::operator/(DataType scalar) const {
    return {x / scalar, y / scalar, z / scalar};
  }

  template <typename DataType>
  double vec3<DataType>::SquaredDistance(const vec3<DataType> & v_1, const vec3<DataType> & v_2) {
    return pow(v_2.x - v_1.x, 2) + pow(v_2.y - v_1.y, 2) + pow(v_2.z - v_1.z, 2) ;
  }
  template struct vec3<double>;
  template struct vec3<size_t>;
}  // namespace sim
