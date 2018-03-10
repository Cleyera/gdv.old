#include "gdv/Util/Color.h"

namespace gdv {

ColorRGB::ColorRGB(ColorHSV c) noexcept :
    a{}, r{}, g{}, b{} {
    *this = ToRGB(c);
}



ColorHSV::ColorHSV(ColorRGB c) noexcept :
    a{}, h{}, s{}, v{} {
    *this = ToHSV(c);
}



ColorRGB operator + (const ColorRGB &co1, const ColorRGB &co2) noexcept {
    return {co1.a + co2.a, co1.r + co2.r, co1.g + co2.g, co1.b + co2.b};
}

ColorRGB operator - (const ColorRGB &co1, const ColorRGB &co2) noexcept {
    return {co1.a - co2.a, co1.r - co2.r, co1.g - co2.g, co1.b - co2.b};
}

ColorRGB operator * (const ColorRGB &co1, const ColorRGB &co2) noexcept {
    return {co1.a * co2.a, co1.r * co2.r, co1.g * co2.g, co1.b * co2.b};
}

ColorRGB& operator += (ColorRGB &co1, const ColorRGB &co2) noexcept {
    co1.a += co2.a;
    co1.r += co2.r;
    co1.g += co2.g;
    co1.b += co2.b;
    return co1;
}

ColorRGB& operator -= (ColorRGB &co1, const ColorRGB &co2) noexcept {
    co1.a -= co2.a;
    co1.r -= co2.r;
    co1.g -= co2.g;
    co1.b -= co2.b;
    return co1;
}

ColorRGB& operator *= (ColorRGB &co1, const ColorRGB &co2) noexcept {
    co1.a *= co2.a;
    co1.r *= co2.r;
    co1.g *= co2.g;
    co1.b *= co2.b;
    return co1;
}


ColorHSV ToHSV(ColorRGB c) noexcept {
    float max = std::max({c.r, c.g, c.b});
    float min = std::min({c.r, c.g, c.b});
    float diff = max - min;
    ColorHSV hsv;

    hsv.s = diff / max;
    hsv.v = max;
    hsv.a = c.a;

    if (c.r >= c.g && c.r >= c.b) {
        hsv.h = (c.g - c.b) / diff;
    } else if (c.g >= c.r && c.g >= c.b) {
        hsv.h = (c.b - c.r) / diff + (1.0f / 3.0f);
    } else {
        hsv.h = (c.r - c.g) / diff + (2.0f / 3.0f);
    }

    return hsv;
}



ColorRGB ToRGB(ColorHSV c) noexcept {
    float p[] {
        abs(fmod( 1.0f          + c.h, 1.0f) * 6.0f - 3.0f),
        abs(fmod((2.0f / 3.0f)  + c.h, 1.0f) * 6.0f - 3.0f),
        abs(fmod((1.0f / 3.0f)  + c.h, 1.0f) * 6.0f - 3.0f),
    };
    ColorRGB rgb {
        c.a,
        c.v * Tween::Linear(1.0f, std::min(std::max(p[0], 0.0f), 1.0f), c.s),
        c.v * Tween::Linear(1.0f, std::min(std::max(p[1], 0.0f), 1.0f), c.s),
        c.v * Tween::Linear(1.0f, std::min(std::max(p[2], 0.0f), 1.0f), c.s)
    };
    return rgb;
}

} // namespace gdv
