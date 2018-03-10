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
Mat4 ToMatrix(Viewport<Ty> v) {
    return {
        v.w / 2, 0, 0, v.x + v.w / 2,
        0, v.h / 2, 0, v.y + v.h / 2,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
}

} // nemspace ColumnMajor


namespace RowMajor {

template <class Ty>
Mat4 ToMatrix(Viewport<Ty> v) {
    return {
        v.w / 2, 0, 0, 0,
        0, v.h / 2, 0, 0,
        0, 0, 1, 0,
        v.x + v.w / 2, v.y + v.h / 2, 0, 1
    };
}

} // namespace RowMajor

} // namespace gdv

#endif
