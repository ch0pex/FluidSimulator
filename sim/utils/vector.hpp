#ifndef FLUID_VECTOR_HPP
#define FLUID_VECTOR_HPP

#include <array>
#include <ostream>

/// Vector de tres dimiensiones
namespace sim {
    template<typename DataType>
    struct vec3 {
        DataType x, y, z;

        template<typename T>
        vec3<DataType>(T _x, T _y, T _z)
                : x(static_cast<DataType>(_x)),
                  y(static_cast<DataType>(_y)),
                  z(static_cast<DataType>(_z)) {
        }

        vec3();

        constexpr vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

        vec3 operator+(const vec3 &vector) const;

        vec3 operator+=(const vec3 &vector);

        vec3 operator-(const vec3 &vector) const;

        vec3 operator-=(const vec3 &vector);

        template<typename T>
        inline vec3 operator*(T scalar) const {
            return {x * scalar, y * scalar, z * scalar};
        }

        template<typename T>
        inline vec3 operator/(T scalar) const {
            return {x / scalar, y / scalar, z / scalar};
        }

        friend std::ostream &operator<<(std::ostream &os, const vec3 &v);
    };
    using vec3d = vec3<double>;
}
#endif //FLUID_VECTOR_HPP
