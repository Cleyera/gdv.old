#ifndef GDV_COLOR_H_
#define GDV_COLOR_H_

#include <algorithm>
#include <math.h>
#include "gdv/Common/Types.h"
#include "gdv/Util/Tween.h"


namespace gdv {


struct ColorHSV;


struct ColorRGB {


    constexpr ColorRGB() noexcept :
        a{1.0f}, r{0.0f}, g{0.0f}, b{0.0f}{}


    constexpr ColorRGB(float r, float g, float b) noexcept :
        a{1.0f}, r{r}, g{g}, b{b}{}



    constexpr ColorRGB(float a, float r, float g, float b) noexcept :
        a{a}, r{r}, g{g}, b{b}{}



    constexpr ColorRGB(uint32 c) noexcept :
        a{((c & 0xff000000) >> 24) / 255.0f},
        r{((c & 0x00ff0000) >> 16) / 255.0f},
        g{((c & 0x0000ff00) >>  8) / 255.0f},
        b{((c & 0x000000ff))       / 255.0f}{}


    ColorRGB(ColorHSV c) noexcept;


    constexpr ColorRGB(const ColorRGB &co) noexcept :
        a{co.a}, r{co.r}, g{co.g}, b{co.b}{}



    ColorRGB& operator = (ColorRGB c){
        a = c.a;
        r = c.r;
        g = c.g;
        b = c.b;
        return *this;
    }



    float a, r, g, b;
};





struct ColorHSV {

    constexpr ColorHSV() noexcept :
        a{1.0f}, h{0.0f}, s{0.0f}, v{0.0f}{}



    constexpr ColorHSV(float h, float s, float v) noexcept :
        a{1.0f}, h{h}, s{s}, v{v}{}


    constexpr ColorHSV(float a, float h, float s, float v) noexcept :
        a{a}, h{h}, s{s}, v{v}{}



    constexpr ColorHSV(const ColorHSV &c) noexcept :
        a{c.a}, h{c.h}, s{c.s}, v{c.v}{}




    ColorHSV(ColorRGB c) noexcept;




    ColorHSV& operator = (const ColorHSV &c) {
        a = c.a;
        h = c.h;
        s = c.s;
        v = c.v;
        return *this;
    }


    float a, h, s, v;
};






ColorRGB operator + (const ColorRGB &co1, const ColorRGB &co2) noexcept;
ColorRGB operator - (const ColorRGB &co1, const ColorRGB &co2) noexcept;
ColorRGB operator * (const ColorRGB &co1, const ColorRGB &co2) noexcept;
ColorRGB& operator += (ColorRGB &co1, const ColorRGB &co2) noexcept;
ColorRGB& operator -= (ColorRGB &co1, const ColorRGB &co2) noexcept;
ColorRGB& operator *= (ColorRGB &co1, const ColorRGB &co2) noexcept;


ColorHSV ToHSV(ColorRGB c) noexcept;
ColorRGB ToRGB(ColorHSV c) noexcept;


using Color = ColorRGB;

} // namespace gdv

#endif
