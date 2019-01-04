#ifndef GDV_COLOR_H_
#define GDV_COLOR_H_

#include <algorithm>
#include <math.h>
#include <gdv/types.h>
#include <gdv/tools/tween.h>


namespace gdv {


template <class Ty>
struct hsv;
template <class Ty>
struct rgb;

template <class Ty>
hsv<Ty> to_hsv(rgb<Ty> c) noexcept;
template <class Ty>
rgb<Ty> to_rgb(hsv<Ty> c) noexcept;


template <class Ty>
struct rgb {

    constexpr rgb() noexcept :
        a{}, r{}, g{}, b{}{}


    constexpr rgb(Ty a, Ty r, Ty g, Ty b) noexcept :
        a{a}, r{r}, g{g}, b{b}{}



    rgb(hsv<Ty> c) noexcept :
        a{}, r{}, g{}, b{} {
        *this = to_rgb(c);
    }


    constexpr rgb(const rgb &co) noexcept :
        a{co.a}, r{co.r}, g{co.g}, b{co.b}{}



    rgb& operator = (rgb c) noexcept {
        a = c.a;
        r = c.r;
        g = c.g;
        b = c.b;
        return *this;
    }



    Ty a, r, g, b;
};





template <class Ty>
struct hsv {

    constexpr hsv() noexcept :
        a{}, h{}, s{}, v{}{}



    constexpr hsv(Ty a, Ty h, Ty s, Ty v) noexcept :
        a{a}, h{h}, s{s}, v{v}{}



    constexpr hsv(const hsv &c) noexcept :
        a{c.a}, h{c.h}, s{c.s}, v{c.v}{}




    hsv(rgb<Ty> c) noexcept :
        a{}, h{}, s{}, v{} {
        *this = to_hsv(c);
    }



    hsv& operator = (const hsv &c) noexcept {
        a = c.a;
        h = c.h;
        s = c.s;
        v = c.v;
        return *this;
    }


    Ty a, h, s, v;
};






template <class Ty>
rgb<Ty> operator + (const rgb<Ty> &c1, const rgb<Ty> &c2) noexcept {
    return {c1.a + c2.a, c1.r + c2.r, c1.g + c2.g, c1.b + c2.b};
}


template <class Ty>
rgb<Ty> operator - (const rgb<Ty> &c1, const rgb<Ty> &c2) noexcept {
    return {c1.a - c2.a, c1.r - c2.r, c1.g - c2.g, c1.b - c2.b};
}


template <class Ty>
rgb<Ty> operator * (const rgb<Ty> &c1, const rgb<Ty> &c2) noexcept {
    return {c1.a * c2.a, c1.r * c2.r, c1.g * c2.g, c1.b * c2.b};
}


template <class Ty>
rgb<Ty>& operator += (rgb<Ty> &c1, const rgb<Ty> &c2) noexcept {
    c1.a += c2.a;
    c1.r += c2.r;
    c1.g += c2.g;
    c1.b += c2.b;
    return c1;
}


template <class Ty>
rgb<Ty>& operator -= (rgb<Ty> &c1, const rgb<Ty> &c2) noexcept {
    c1.a -= c2.a;
    c1.r -= c2.r;
    c1.g -= c2.g;
    c1.b -= c2.b;
    return c1;
}


template <class Ty>
rgb<Ty>& operator *= (rgb<Ty> &c1, const rgb<Ty> &c2) noexcept {
    c1.a *= c2.a;
    c1.r *= c2.r;
    c1.g *= c2.g;
    c1.b *= c2.b;
    return c1;
}



template <class Ty>
hsv<Ty> to_hsv(rgb<Ty> c) noexcept {
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    constexpr Ty _3 = static_cast<Ty>(3);
    Ty max = std::max({c.r, c.g, c.b});
    Ty min = std::min({c.r, c.g, c.b});
    Ty diff = max - min;
    hsv<Ty> hsv;

    hsv.s = diff / max;
    hsv.v = max;
    hsv.a = c.a;

    if (c.r >= c.g && c.r >= c.b) {
        hsv.h = (c.g - c.b) / diff;
    } else if (c.g >= c.r && c.g >= c.b) {
        hsv.h = (c.b - c.r) / diff + (_1 / _3);
    } else {
        hsv.h = (c.r - c.g) / diff + (_2 / _3);
    }

    return hsv;
}



template <class Ty>
rgb<Ty> to_rgb(hsv<Ty> c) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    constexpr Ty _3 = static_cast<Ty>(3);
    Ty p[] {
        std::abs(std::fmod( _1        + c.h, _1) * (_2 * _3) - _3),
        std::abs(std::fmod((_2 / _3)  + c.h, _1) * (_2 * _3) - _3),
        std::abs(std::fmod((_1 / _3)  + c.h, _1) * (_2 * _3) - _3),
    };
    rgb rgb {
        c.a,
        c.v * tween::linear(_1, std::min(std::max(p[0], _0), _1), c.s),
        c.v * tween::linear(_1, std::min(std::max(p[1], _0), _1), c.s),
        c.v * tween::linear(_1, std::min(std::max(p[2], _0), _1), c.s)
    };
    return rgb;
}



template <class Ty>
using color = rgb<Ty>;

} // namespace gdv

#endif
