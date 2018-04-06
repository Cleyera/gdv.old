#ifndef GDV_VIEWPORT_H_
#define GDV_VIEWPORT_H_

#include <type_traits>
#include "gdv/Math/Matrix4x4.h"

namespace gdv {

template<class Ty>
class Viewport {
    static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:
    Viewport() noexcept :
        x{}, y{}, w{}, h{} {}

    Viewport(Ty x, Ty y, Ty w, Ty h) noexcept :
        x{x}, y{y}, w{w}, h{h} {}

public:
    Ty x;
    Ty y;
    Ty w;
    Ty h;
};


namespace ColumnMajor {

template <class Ty>
Matrix4x4<Ty> ToMatrix(Viewport<Ty> v) {
    static constexpr Ty _0 = static_cast<Ty>(0);
    static constexpr Ty _1 = static_cast<Ty>(1);
    static constexpr Ty _2 = static_cast<Ty>(2);
    return {
        v.w / _2, _0, _0, v.x + v.w / _2,
        _0, v.h / _2, _0, v.y + v.h / _2,
        _0, _0, _1, _0,
        _0, _0, _0, _1
    };
}

} // nemspace ColumnMajor


namespace RowMajor {

template <class Ty>
Matrix4x4<Ty> ToMatrix(Viewport<Ty> v) {
    static constexpr Ty _0 = static_cast<Ty>(0);
    static constexpr Ty _1 = static_cast<Ty>(1);
    static constexpr Ty _2 = static_cast<Ty>(2);
    return {
        v.w / _2, _0, _0, _0,
        _0, v.h / _2, _0, _0,
        _0, _0, _1, _0,
        v.x + v.w / _2, v.y + v.h / _2, _0, _1
    };
}

} // namespace RowMajor

} // namespace gdv

#endif
