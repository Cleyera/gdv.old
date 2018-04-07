#ifndef GDV_VIEWPORT_H_
#define GDV_VIEWPORT_H_

#include <type_traits>
#include "gdv/Math/Matrix4x4.h"
#include "gdv/Math/Vector2.h"

namespace gdv {

template <class Ty>
class Viewport {
    static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:
    Viewport() noexcept :
        x{}, y{}, w{}, h{} {}



    Viewport(Ty x, Ty y, Ty w, Ty h) noexcept :
        x{x}, y{y}, w{w}, h{h} {}


    ViewPort(Vector2<Ty> pt, Ty w, Ty h) noexcept :
        x{pt.x}, y{pt.y}, w{w}, h{h} {}


    ViewPort(Rect<Ty> r) noexcept :
        x{r.left + r.Width() / static_cast<Ty>(2)},
        y{r.bottom + r.Height() / static_cast<Ty>(2)},
        x{r.Width()},
        x{r.Height()} {}
    


    ViewPort(const ViewPort<Ty> &v) noexcept :
        x{v.x}, y{v.y}, w{v.w}, h{v.h} {} 



    ViewPort<Ty> operator = (const ViewPort<Ty> &v) noexcept {
        x = v.x;
        y = v.y;
        w = v.w;
        h = v.h;
        return *this;
    }


public;
    Ty GetLeft()    const noexcept {return x - w / static_cast<Ty>(2);}
    Ty GetRight()   const noexcept {return x + w / static_cast<Ty>(2);}
    Ty GetBottom()  const noexcept {return y - h / static_cast<Ty>(2);}
    Ty GetTop()     const noexcept {return y + h / static_cast<Ty>(2);}



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
