#ifndef FLUID_VECTOR_HPP
#define FLUID_VECTOR_HPP

#include <immintrin.h>
#include <ostream>
/// Vector de tres dimiensiones
#define FASTCALL __attribute__((fastcall))

namespace sim {
  template <typename DataType>
  struct vec3;
  using vec3d   = vec3<double>;
  using AVXvec3 = __m256d;
  typedef AVXvec3 const FAVXvec3;
  typedef AVXvec3 const & GAVXvec3;
  typedef AVXvec3 const & HAVXvec3;
  typedef AVXvec3 const & CAVXvec3;

  inline FASTCALL AVXvec3 AVXsetvec3(double const d);
  inline FASTCALL AVXvec3 AVXLoadvec3(vec3d const & vec);
  inline FASTCALL vec3d AVXStorevec3(AVXvec3 & va);

  template <typename DataType>
  struct vec3 {
      DataType x, y, z;

      template <typename T>
      vec3(T _x, T _y, T _z)
        : x(static_cast<DataType>(_x)), y(static_cast<DataType>(_y)), z(static_cast<DataType>(_z)) {
      }

      vec3();

      constexpr vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) { }

      constexpr vec3(int _x, int _y, int _z) : x(_x), y(_y), z(_z) { }

      vec3<DataType> operator+(vec3<DataType> const & vector) const;

      vec3<DataType> operator+=(vec3<DataType> const & vector);

      vec3<DataType> operator-(vec3 const & vector) const;

      vec3<DataType> operator-=(vec3 const & vector);

      vec3<DataType> operator*(DataType scalar) const;

      vec3<DataType> operator/(DataType scalar) const;

      inline static double SquaredDistance(vec3<DataType> const & v_i, vec3<DataType> const & v_j) {
        double const x = v_i.x - v_j.x;
        double const y = v_i.y - v_j.y;
        double const z = v_i.z - v_j.z;
        return x * x + y * y + z * z;
      }

      /**
       * imprimir un objeto vec3 en un flujo de salida (como std::cout)
       *
       * @param os flujo de salida donde se imprimirá el objeto vec3
       * @param v objeto vec3 que se imprimirá
       * @return flujo de salida después de la operación de impresión
       */
      friend std::ostream & operator<<(std::ostream & os, vec3<DataType> const & v) {
        os << v.x << " x " << v.y << " x " << v.z;
        return os;
      }
  };

  inline FASTCALL AVXvec3 AVXsetvec3(double const d) {
    return _mm256_set_pd(d, d, d, d);
  };

  inline FASTCALL vec3d AVXStorevec3(AVXvec3 & va) {
    double d[4];
    _mm256_store_pd(d, va);
    return vec3d(d[3], d[2], d[1]);
  };

  inline FASTCALL AVXvec3 AVXLoadvec3(vec3d const & vec) {
    double const d[] = {0.0, vec.z, vec.y, vec.x};
    return _mm256_load_pd(d);
  };
}  // namespace sim
#endif  // FLUID_VECTOR_HPP
