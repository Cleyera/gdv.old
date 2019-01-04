#ifndef TWEEN_HEADER_
#define TWEEN_HEADER_

#include <cmath>
#include <gdv/math/constant.h>
#include <gdv/math/vector2.h>
#include <gdv/math/vector3.h>
#include <gdv/math/vector4.h>

namespace gdv {

namespace tween {

template <class Ty>
Ty linear(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ratio + begin;
}



template <class Ty>
Ty in_quad(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ratio * ratio + begin;
}

template <class Ty>
Ty out_quad(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * (ratio * (ratio - static_cast<Ty>(2)) - static_cast<Ty>(1)) + begin;
}

template <class Ty>
Ty in_out_quad(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return in_quad(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (out_quad(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty out_in_quad(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return out_quad(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (in_quad(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}




template <class Ty>
Ty in_cubic(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ratio * ratio * ratio + begin;
}

template <class Ty>
Ty out_cubic(Ty begin, Ty end, Ty ratio) noexcept {
    ratio -= static_cast<Ty>(1);
    return (end - begin) * (ratio * ratio * ratio + static_cast<Ty>(1)) + begin;
}

template <class Ty>
Ty in_out_cubic(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return in_cubic(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (out_cubic(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty out_in_cubic(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return out_cubic(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (in_cubic(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}





template <class Ty>
Ty in_quart(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ratio * ratio * ratio * ratio + begin;
}

template <class Ty>
Ty out_quart(Ty begin, Ty end, Ty ratio) noexcept {
    ratio -= static_cast<Ty>(1);
    return (end - begin) * (ratio * ratio * ratio * ratio - static_cast<Ty>(1)) + begin;
}

template <class Ty>
Ty in_out_quart(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return in_quart(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (out_quart(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty out_in_quart(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return out_quart(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (in_quart(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}






template <class Ty>
Ty in_quint(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ratio * ratio * ratio * ratio * ratio + begin;
}

template <class Ty>
Ty out_quint(Ty begin, Ty end, Ty ratio) noexcept {
    ratio -= static_cast<Ty>(1);
    return (end - begin) * (ratio * ratio * ratio * ratio * ratio + static_cast<Ty>(1)) + begin;
}

template <class Ty>
Ty in_out_quint(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return in_quint(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (out_quint(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty out_in_quint(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return out_quint(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (in_quint(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}






template <class Ty>
Ty in_sine(Ty begin, Ty end, Ty ratio) noexcept {
    return (begin - end) * cos(pi<Ty> * ratio) + end;
}

template <class Ty>
Ty out_sine(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * sin(pi<Ty> * ratio) + begin;
}

template <class Ty>
Ty in_out_sine(Ty begin, Ty end, Ty ratio) noexcept {
    return (begin - end) / static_cast<Ty>(2) * (cos(pi<Ty> * ratio) - static_cast<Ty>(1)) + begin;
}

template <class Ty>
Ty out_in_sine(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return out_sine(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (in_sine(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}






template <class Ty>
Ty in_exp(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * std::pow(static_cast<Ty>(2), static_cast<Ty>(10) * (ratio - 1)) + begin;
}

template <class Ty>
Ty out_exp(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * (static_cast<Ty>(1) - std::pow(static_cast<Ty>(2), static_cast<Ty>(-10) * ratio)) + begin;
}

template <class Ty>
Ty in_out_exp(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return in_exp(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (out_exp(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty out_in_exp(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return out_exp(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (in_exp(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}






template <class Ty>
Ty in_circ(Ty begin, Ty end, Ty ratio) noexcept {
    return begin - (end - begin) * (sqrt(static_cast<Ty>(1) - ratio * ratio) - static_cast<Ty>(1));
}

template <class Ty>
Ty out_circ(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * sqrt(static_cast<Ty>(1) - ratio * ratio) + begin;
}

template <class Ty>
Ty in_out_circ(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return in_circ(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (out_circ(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty out_in_circ(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return out_circ(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (in_circ(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}







template <class Ty>
Ty in_back(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
    return (end - begin) * (ratio * ratio * ((overshoot + static_cast<Ty>(1)) * ratio - overshoot) + static_cast<Ty>(1));
}

template <class Ty>
Ty out_back(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
    return (end - begin) * (ratio * ratio * ((overshoot + static_cast<Ty>(1)) * ratio * overshoot) + static_cast<Ty>(1)) + begin;
}

template <class Ty>
Ty in_out_back(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return in_back(begin, end, ratio * static_cast<Ty>(2), overshoot) * static_cast<Ty>(0.5);
    }
    return (out_back(begin, end, ratio * static_cast<Ty>(2), overshoot) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
Ty out_in_back(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return out_back(begin, end, ratio * static_cast<Ty>(2), overshoot) * static_cast<Ty>(0.5);
    }
    return (in_back(begin, end, ratio * static_cast<Ty>(2), overshoot) + (end - begin)) * static_cast<Ty>(0.5);
}





template <class Ty>
Ty in_elastic(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * sin(static_cast<Ty>(13) * pi<Ty> * ratio) * pow(static_cast<Ty>(2), static_cast<Ty>(10) * (ratio - static_cast<Ty>(1))) + begin;
}

template <class Ty>
float out_elastic(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * sin(static_cast<Ty>(13) * pi<Ty> * ratio) * pow(static_cast<Ty>(2), static_cast<Ty>(-10) * ratio) + begin;
}

template <class Ty>
float in_out_elastic(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return in_elastic(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (out_elastic(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
float out_in_elastic(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return out_elastic(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (in_elastic(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}





template <class Ty>
double out_bounce(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(1.0 / 2.75)) {
        return (end - begin) * (static_cast<Ty>(7.5625) * ratio * ratio) + begin;
    }
    else if (ratio < static_cast<Ty>(2.0 / 2.75)) {
        ratio -= static_cast<Ty>(1.5 / 2.75);
        return (end - begin) * (static_cast<Ty>(7.5625) * ratio * ratio + static_cast<Ty>(0.75)) + begin;
    }
    else if (ratio < static_cast<Ty>(2.5 / 2.75)) {
        ratio -= static_cast<Ty>(2.25 / 2.75);
        return (end - begin) * (static_cast<Ty>(7.5625) * ratio * ratio + static_cast<Ty>(0.9375)) + begin;
    }
    ratio -= static_cast<Ty>(2.625 / 2.75);
    return (end - begin) * (static_cast<Ty>(7.5625) * ratio * ratio + static_cast<Ty>(0.984375)) + begin;
}

template <class Ty>
double in_bounce(Ty begin, Ty end, Ty ratio) noexcept {
    return end - out_bounce(begin, end, ratio) + ratio;
}

template <class Ty>
double in_out_bounce(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return in_bounce(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (out_bounce(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
double out_in_bounce(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return out_bounce(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (in_bounce(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}



} // namespace Tween
} // namespace gdv

#endif

