#ifndef GDV_VECTOR3_H_
#define GDV_VECTOR3_H_

#include <type_traits>
#include "gdv/math/vector2.h"

namespace gdv {

template <class Ty>
class alignas(alignof(Ty)) vector3 {
    static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

    constexpr vector3() noexcept :
        x{}, y{}, z{}{}

    constexpr vector3(Ty v) noexcept :
        x{v}, y{v}, z{v}{}

    constexpr vector3(Ty x, Ty y, Ty z) noexcept :
        x{x}, y{y}, z{z}{}

    constexpr vector3(const vector3<Ty> &v) noexcept :
        x{v.x}, y{v.y}, z{v.z}{}

    constexpr vector3(const vector2<Ty> &v) noexcept :
        x{v.x}, y{v.y}, z{static_cast<Ty>(1)}{}

    constexpr vector3(const vector2<Ty> &v, Ty z) noexcept :
        x{v.x}, y{v.y}, z{z}{}



    vector3<Ty>& operator = (const vector3<Ty> &v) noexcept {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }


    operator vector2<Ty>() const noexcept {return {x, y};}


public:
    Ty x;
    Ty y;
    Ty z;
};



template<class Ty>
bool operator == (vector3<Ty> v1, vector3<Ty> v2) noexcept {
    return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}

template<class Ty>
bool operator != (vector3<Ty> v1, vector3<Ty> v2) noexcept {
    return v1.x != v2.x || v1.y != v2.y || v1.z != v2.z;
}

template<class Ty>
vector3<Ty>& operator += (vector3<Ty> &v1, vector3<Ty> v2) noexcept {
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
    return v1;
}

template<class Ty>
vector3<Ty>& operator += (vector3<Ty> &pt, Ty val) noexcept {
    pt.x += val;
    pt.y += val;
    pt.z += val;
    return pt;
}

template<class Ty>
vector3<Ty>& operator -= (vector3<Ty> &v1, vector3<Ty> v2) noexcept {
    v1.x -= v2.x;
    v1.y -= v2.y;
    v1.z -= v2.z;
    return v1;
}

template<class Ty>
vector3<Ty>& operator -= (vector3<Ty> &pt, Ty val) noexcept {
    pt.x -= val;
    pt.y -= val;
    pt.z -= val;
    return pt;
}

template<class Ty>
vector3<Ty>& operator *= (vector3<Ty> &pt, Ty val) noexcept {
    pt.x *= val;
    pt.y *= val;
    pt.z *= val;
    return pt;
}

template<class Ty>
vector3<Ty>& operator /= (vector3<Ty> &pt, Ty val) noexcept {
    pt.x /= val;
    pt.y /= val;
    pt.z /= val;
    return pt;
}

template<class Ty>
vector3<Ty> operator + (vector3<Ty> v1, vector3<Ty> v2) noexcept {
    return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

template<class Ty>
vector3<Ty> operator + (vector3<Ty> pt, Ty val) noexcept {
    return {pt.x + val, pt.y + val, pt.z + val};
}

template<class Ty>
vector3<Ty> operator - (vector3<Ty> v1, vector3<Ty> v2) noexcept {
    return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

template<class Ty>
vector3<Ty> operator - (vector3<Ty> pt, Ty val) noexcept {
    return {pt.x - val, pt.y - val, pt.z - val};
}

template<class Ty>
vector3<Ty> operator * (vector3<Ty> pt, Ty val) noexcept {
    return {pt.x * val, pt.y * val, pt.z * val};
}
template<class Ty>
vector3<Ty> operator / (vector3<Ty> pt, Ty val) noexcept {
    return {pt.x / val, pt.y / val, pt.z / val};
}




template<class Ty>
Ty dot(vector3<Ty> v1, vector3<Ty> v2) noexcept {
    static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}


template<class Ty>
vector3<Ty> cross(vector3<Ty> v1, vector3<Ty> v2) noexcept {
    static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
    return {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x};
}


template<class Ty>
Ty angle(vector3<Ty> v1, vector3<Ty> v2) noexcept {
    return static_cast<Ty>(std::atan2(dot(v1, v2), length(cross(v1, v2))));
}


template<class Ty>
Ty length(vector3<Ty> v) noexcept {
    static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
    return static_cast<Ty>(std::hypot(std::hypot(v.x, v.y), v.z));
}


template<class Ty>
vector3<Ty> normalize(vector3<Ty> v) noexcept {
    return (v / length(v));
}




using point3    = vector3<int>;
using vec3      = vector3<float>;

} // namespace gdv

#endif
