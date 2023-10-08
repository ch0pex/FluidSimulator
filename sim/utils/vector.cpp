#include "vector.hpp"

namespace sim {
    vec3::vec3() : x(0.0), y(0.0), z(0.0) {}

    vec3 vec3::operator+(const vec3 &vector) const {
        return {x + vector.x, y + vector.y, z + vector.z};
    }

    vec3 vec3::operator+=(const vec3 &vector) {
        x += vector.x;
        y += vector.y;
        z += vector.z;
        return *this;
    }

    vec3 vec3::operator-(const vec3 &vector) const {
        return {x - vector.x, y - vector.y, z - vector.z};
    }

    vec3 vec3::operator-=(const vec3 &vector) {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const vec3 &v) {
        os << v.x << " x " << v.y << " x " << v.z;
        return os;
    };

}
