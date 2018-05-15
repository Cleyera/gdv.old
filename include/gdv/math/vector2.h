#ifndef GDV_VECTOR2_H_
#define GDV_VECTOR2_H_

#include <type_traits>
#include <cmath>

namespace gdv {

template <class Ty>
class vector2 {
    static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

    constexpr vector2() noexcept :
        x{}, y{}{}


    constexpr vector2(Ty x, Ty y) noexcept :
        x{x}, y{y}{}


    constexpr vector2(const vector2<Ty> &v) noexcept :
        x{v.x}, y{v.y}{}




    vector2<Ty>& operator = (const vector2<Ty> &v) noexcept {
        x = v.x;
        y = v.y;
        return *this;
    }



public:
    Ty x;
    Ty y;
};



template<class Ty>
bool operator == (vector2<Ty> v1, vector2<Ty> v2) noexcept {
    return v1.x == v2.x && v1.y == v2.y;
}

template<class Ty>
bool operator != (vector2<Ty> v1, vector2<Ty> v2) noexcept {
    return v1.x != v2.x || v1.y != v2.y;
}

template<class Ty>
vector2<Ty>& operator += (vector2<Ty> &v1, vector2<Ty> v2) noexcept {
    v1.x += v2.x;
    v1.y += v2.y;
    return v1;
}

template<class Ty>
vector2<Ty>& operator += (vector2<Ty> &v, Ty val) noexcept {
    v.x += val;
    v.y += val;
    return v;
}

template<class Ty>
vector2<Ty>& operator -= (vector2<Ty> &v1, vector2<Ty> v2) noexcept {
    v1.x -= v2.x;
    v1.y -= v2.y;
    return v1;
}

template<class Ty>
vector2<Ty>& operator *= (vector2<Ty> &v, Ty val) noexcept {
    v.x *= val;
    v.y *= val;
    return v;
}

template<class Ty>
vector2<Ty>& operator /= (vector2<Ty> &v, Ty val) noexcept {
    v.x /= val;
    v.y /= val;
    return v;
}

template<class Ty>
vector2<Ty>& operator -= (vector2<Ty> &v, Ty val) noexcept {
    v.x -= val;
    v.y -= val;
    return v;
}

template<class Ty>
vector2<Ty> operator + (vector2<Ty> v1, vector2<Ty> v2) noexcept {
    return {v1.x + v2.x, v1.y + v2.y};
}

template<class Ty>
vector2<Ty> operator + (vector2<Ty> v, Ty val) noexcept {
    return {v.x + val, v.y + val};
}

template<class Ty>
vector2<Ty> operator - (vector2<Ty> v1, vector2<Ty> v2) noexcept {
    return {v1.x - v2.x, v1.y - v2.y};
}

template<class Ty>
vector2<Ty> operator - (vector2<Ty> v, Ty val) noexcept {
    return {v.x - val, v.y - val};
}

template<class Ty>
vector2<Ty> operator * (vector2<Ty> v, Ty val) noexcept {
    return {v.x * val, v.y * val};
}

template<class Ty>
vector2<Ty> operator / (vector2<Ty> v, Ty val) noexcept {
    return {v.x / val, v.y / val};
}





template<class Ty>
Ty dot(vector2<Ty> v1, vector2<Ty> v2) noexcept {
    static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
    return v1.x * v2.x + v1.y * v2.y;
}


template<class Ty>
Ty cross(vector2<Ty> v1, vector2<Ty> v2) noexcept {
    static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
    return v1.x * v2.y - v1.y * v2.x;
}


template<class Ty>
Ty angle(vector2<Ty> v1, vector2<Ty> v2) noexcept {
    return static_cast<Ty>(std::atan2(dot(v1, v2), cross(v1, v2)));
}


template<class Ty>
Ty length(vector2<Ty> v) noexcept {
    static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
    return static_cast<Ty>(std::hypot(v.x, v.y));
}


template<class Ty>
vector2<Ty> normalize(vector2<Ty> v) noexcept {
    return (v / length(v));
}


template<class Ty>
vector2<Ty> rotate(vector2<Ty> v, vector2<Ty> center, Ty angle) noexcept {
    static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
    const Ty s = std::sin(angle);
    const Ty c = std::cos(angle);
    const Ty x = v.x - center.x;
    const Ty y = v.y - center.y;
    return {
        x * c + y * s + center.x,
        y * c - x * s + center.y
    };
}




using point = vector2<int>;
using vec2  = vector2<float>;

} // namespace gdv

#endif
