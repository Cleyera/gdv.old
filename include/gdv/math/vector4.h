#ifndef GDV_VECTOR4_H_
#define GDV_VECTOR4_H_

#include <type_traits>
#include "gdv/math/vector3.h"

namespace gdv {

template <class Ty>
class alignas(alignof(Ty)) vector4 {
    static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

    constexpr vector4() noexcept :
        x{}, y{}, z{}, w{}{}

    constexpr vector4(Ty x, Ty y, Ty z) noexcept :
        x{x}, y{y}, z{z}, w{static_cast<Ty>(1)}{}

    constexpr vector4(Ty x, Ty y, Ty z, Ty w) noexcept :
        x{x}, y{y}, z{z}, w{w}{}

    constexpr vector4(const vector4<Ty> &v) noexcept :
        x{v.x}, y{v.y}, z{v.z}, w{v.w}{}

    constexpr vector4(const vector3<Ty> &v) noexcept :
        x{v.x}, y{v.y}, z{v.z}, w{static_cast<Ty>(1)}{}

    constexpr vector4(const vector3<Ty> &v, Ty w) noexcept :
        x{v.x}, y{v.y}, z{v.z}, w{w}{}






    vector4<Ty>& operator = (const vector4<Ty> &v) noexcept {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }


    vector4<Ty>& operator = (const vector3<Ty> &v) noexcept {
        x = v.x;
        y = v.y;
        z = v.z;
        w = static_cast<Ty>(1);
        return *this;
    }


    operator vector3<Ty>() const noexcept {return {x, y, z};}

public:
    Ty x;
    Ty y;
    Ty z;
    Ty w;
};




using vec4 = vector4<float>;

} // namespace gdv

#endif
