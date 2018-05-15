#ifndef TWEEN_HEADER_
#define TWEEN_HEADER_

#include <math.h>
#include "gdv/math/math_constant.h"
#include "gdv/math/vector2.h"
#include "gdv/math/vector3.h"
#include "gdv/math/vector4.h"

namespace gdv {

namespace tween {

template <class Ty>
Ty linear(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ratio + begin;
}

template <class Ty>
Ty linear(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return (end - begin) * ratio + begin;
}

template <class Ty>
Ty linear(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return (end - begin) * ratio + begin;
}

template <class Ty>
Ty linear(vector4<Ty> begin, vector4<Ty> end, Ty ratio) noexcept {
    return (end - begin) * ratio + begin;
}




template <class Ty>
Ty in_quad(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * ratio * ratio + begin;
}

template <class Ty>
Ty out_quad(Ty begin, Ty end, Ty ratio) noexcept {
    return (end - begin) * (ratio * (ratio - 2) - 1) + begin;
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
vector2<Ty> in_quad(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_quad(begin.x, end.x, ratio),
        in_quad(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_quad(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_quad(begin.x, end.x, ratio),
        out_quad(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> in_out_quad(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_out_quad(begin.x, end.x, ratio),
        in_out_quad(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_in_quad(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_in_quad(begin.x, end.x, ratio),
        out_in_quad(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector3<Ty> in_quad(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_quad(begin.x, end.x, ratio),
        in_quad(begin.y, end.y, ratio),
        in_quad(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_quad(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_quad(begin.x, end.x, ratio),
        out_quad(begin.y, end.y, ratio),
        out_quad(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> in_out_quad(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_out_quad(begin.x, end.x, ratio),
        in_out_quad(begin.y, end.y, ratio),
        in_out_quad(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_in_quad(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_in_quad(begin.x, end.x, ratio),
        out_in_quad(begin.y, end.y, ratio),
        out_in_quad(begin.z, end.z, ratio)
    };
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
vector2<Ty> in_cubic(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_cubic(begin.x, end.x, ratio),
        in_cubic(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_cubic(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_cubic(begin.x, end.x, ratio),
        out_cubic(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> in_out_cubic(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_out_cubic(begin.x, end.x, ratio),
        in_out_cubic(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_in_cubic(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_in_cubic(begin.x, end.x, ratio),
        out_in_cubic(begin.y, end.y, ratio)
    };
}
template <class Ty>
vector3<Ty> in_cubic(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_cubic(begin.x, end.x, ratio),
        in_cubic(begin.y, end.y, ratio),
        in_cubic(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_cubic(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_cubic(begin.x, end.x, ratio),
        out_cubic(begin.y, end.y, ratio),
        out_cubic(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> in_out_cubic(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_out_cubic(begin.x, end.x, ratio),
        in_out_cubic(begin.y, end.y, ratio),
        in_out_cubic(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_in_cubic(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_in_cubic(begin.x, end.x, ratio),
        out_in_cubic(begin.y, end.y, ratio),
        out_in_cubic(begin.z, end.z, ratio)
    };
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
vector2<Ty> in_quart(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_quart(begin.x, end.x, ratio),
        in_quart(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_quart(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_quart(begin.x, end.x, ratio),
        out_quart(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> in_out_quart(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_out_quart(begin.x, end.x, ratio),
        in_out_quart(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_in_quart(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_in_quart(begin.x, end.x, ratio),
        out_in_quart(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector3<Ty> in_quart(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_quart(begin.x, end.x, ratio),
        in_quart(begin.y, end.y, ratio),
        in_quart(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_quart(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_quart(begin.x, end.x, ratio),
        out_quart(begin.y, end.y, ratio),
        out_quart(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> in_out_quart(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_out_quart(begin.x, end.x, ratio),
        in_out_quart(begin.y, end.y, ratio),
        in_out_quart(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_in_quart(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_in_quart(begin.x, end.x, ratio),
        out_in_quart(begin.y, end.y, ratio),
        out_in_quart(begin.z, end.z, ratio)
    };
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
vector2<Ty> in_quint(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_quint(begin.x, end.x, ratio),
        in_quint(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_quint(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_quint(begin.x, end.x, ratio),
        out_quint(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> in_out_quint(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_out_quint(begin.x, end.x, ratio),
        in_out_quint(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_in_quint(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_in_quint(begin.x, end.x, ratio),
        out_in_quint(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector3<Ty> in_quint(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_quint(begin.x, end.x, ratio),
        in_quint(begin.y, end.y, ratio),
        in_quint(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_quint(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_quint(begin.x, end.x, ratio),
        out_quint(begin.y, end.y, ratio),
        out_quint(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> in_out_quint(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_out_quint(begin.x, end.x, ratio),
        in_out_quint(begin.y, end.y, ratio),
        in_out_quint(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_in_quint(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_in_quint(begin.x, end.x, ratio),
        out_in_quint(begin.y, end.y, ratio),
        out_in_quint(begin.z, end.z, ratio)
    };
}









template <class Ty>
Ty in_sine(Ty begin, Ty end, Ty ratio) noexcept {
    end -= begin;
    return -end * cos(PI<Ty> * ratio) + begin + end;
}

template <class Ty>
Ty out_sine(Ty begin, Ty end, Ty ratio) noexcept {
    end -= begin;
    return end * sin(PI<Ty> * ratio) + begin;
}

template <class Ty>
Ty in_out_sine(Ty begin, Ty end, Ty ratio) noexcept {
    end -= begin;
    return -end / static_cast<Ty>(2) * (cos(PI<Ty> * ratio) - static_cast<Ty>(1)) + begin;
}

template <class Ty>
Ty out_in_sine(Ty begin, Ty end, Ty ratio) noexcept {
    if (ratio < static_cast<Ty>(0.5)) {
        return out_sine(begin, end, ratio * static_cast<Ty>(2)) * static_cast<Ty>(0.5);
    }
    return (in_sine(begin, end, ratio * static_cast<Ty>(2)) + (end - begin)) * static_cast<Ty>(0.5);
}

template <class Ty>
vector2<Ty> in_sine(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_sine(begin.x, end.x, ratio),
        in_sine(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_sine(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_sine(begin.x, end.x, ratio),
        out_sine(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> in_out_sine(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_out_sine(begin.x, end.x, ratio),
        in_out_sine(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_in_sine(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_in_sine(begin.x, end.x, ratio),
        out_in_sine(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector3<Ty> in_sine(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_sine(begin.x, end.x, ratio),
        in_sine(begin.y, end.y, ratio),
        in_sine(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_sine(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_sine(begin.x, end.x, ratio),
        out_sine(begin.y, end.y, ratio),
        out_sine(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> in_out_sine(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_out_sine(begin.x, end.x, ratio),
        in_out_sine(begin.y, end.y, ratio),
        in_out_sine(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_in_sine(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_in_sine(begin.x, end.x, ratio),
        out_in_sine(begin.y, end.y, ratio),
        out_in_sine(begin.z, end.z, ratio)
    };
}









template <class Ty>
Ty in_exp(Ty begin, Ty end, Ty ratio) noexcept {
    end -= begin;
    return end * pow(static_cast<Ty>(2), static_cast<Ty>(10) * (ratio - 1)) + begin;
}

template <class Ty>
Ty out_exp(Ty begin, Ty end, Ty ratio) noexcept {
    end -= begin;
    return end * (static_cast<Ty>(1) - pow(static_cast<Ty>(2), static_cast<Ty>(-10) * ratio)) + begin;
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
vector2<Ty> in_exp(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_exp(begin.x, end.x, ratio),
        in_exp(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_exp(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_exp(begin.x, end.x, ratio),
        out_exp(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> in_out_exp(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_out_exp(begin.x, end.x, ratio),
        in_out_exp(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_in_exp(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_in_exp(begin.x, end.x, ratio),
        out_in_exp(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector3<Ty> in_exp(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_exp(begin.x, end.x, ratio),
        in_exp(begin.y, end.y, ratio),
        in_exp(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_exp(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_exp(begin.x, end.x, ratio),
        out_exp(begin.y, end.y, ratio),
        out_exp(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> in_out_exp(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_out_exp(begin.x, end.x, ratio),
        in_out_exp(begin.y, end.y, ratio),
        in_out_exp(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_in_exp(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_in_exp(begin.x, end.x, ratio),
        out_in_exp(begin.y, end.y, ratio),
        out_in_exp(begin.z, end.z, ratio)
    };
}







template <class Ty>
Ty in_circ(Ty begin, Ty end, Ty ratio) noexcept {
    end -= begin;
    return begin - end * (sqrt(static_cast<Ty>(1) - ratio * ratio) - static_cast<Ty>(1));
}

template <class Ty>
Ty out_circ(Ty begin, Ty end, Ty ratio) noexcept {
    end -= begin;
    return end * sqrt(static_cast<Ty>(1) - ratio * ratio) + begin;
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
vector2<Ty> in_circ(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_circ(begin.x, end.x, ratio),
        in_circ(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_circ(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_circ(begin.x, end.x, ratio),
        out_circ(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> in_out_circ(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_out_circ(begin.x, end.x, ratio),
        in_out_circ(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_in_circ(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_in_circ(begin.x, end.x, ratio),
        out_in_circ(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector3<Ty> in_circ(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_circ(begin.x, end.x, ratio),
        in_circ(begin.y, end.y, ratio),
        in_circ(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_circ(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_circ(begin.x, end.x, ratio),
        out_circ(begin.y, end.y, ratio),
        out_circ(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> in_out_circ(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_out_circ(begin.x, end.x, ratio),
        in_out_circ(begin.y, end.y, ratio),
        in_out_circ(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_in_circ(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_in_circ(begin.x, end.x, ratio),
        out_in_circ(begin.y, end.y, ratio),
        out_in_circ(begin.z, end.z, ratio)
    };
}








template <class Ty>
Ty in_back(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
    end -= begin;
    return end * ratio * ratio * ((overshoot + static_cast<Ty>(1)) * ratio - overshoot) + end;
}

template <class Ty>
Ty out_back(Ty begin, Ty end, Ty ratio, Ty overshoot) noexcept {
    end -= begin;
    return end * (ratio * ratio * ((overshoot + static_cast<Ty>(1)) * ratio * overshoot) + 1) + begin;
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
vector2<Ty> in_back(vector2<Ty> begin, vector2<Ty> end, Ty ratio, Ty overshoot) noexcept {
    return {
        in_back(begin.x, end.x, ratio, overshoot),
        in_back(begin.y, end.y, ratio, overshoot)
    };
}

template <class Ty>
vector2<Ty> out_back(vector2<Ty> begin, vector2<Ty> end, Ty ratio, Ty overshoot) noexcept {
    return {
        out_back(begin.x, end.x, ratio, overshoot),
        out_back(begin.y, end.y, ratio, overshoot)
    };
}

template <class Ty>
vector2<Ty> in_out_back(vector2<Ty> begin, vector2<Ty> end, Ty ratio, Ty overshoot) noexcept {
    return {
        in_out_back(begin.x, end.x, ratio, overshoot),
        in_out_back(begin.y, end.y, ratio, overshoot)
    };
}

template <class Ty>
vector2<Ty> out_in_back(vector2<Ty> begin, vector2<Ty> end, Ty ratio, Ty overshoot) noexcept {
    return {
        out_in_back(begin.x, end.x, ratio, overshoot),
        out_in_back(begin.y, end.y, ratio, overshoot)
    };
}

template <class Ty>
vector3<Ty> in_back(vector3<Ty> begin, vector3<Ty> end, Ty ratio, Ty overshoot) noexcept {
    return {
        in_back(begin.x, end.x, ratio, overshoot),
        in_back(begin.y, end.y, ratio, overshoot),
        in_back(begin.z, end.z, ratio, overshoot)
    };
}

template <class Ty>
vector3<Ty> out_back(vector3<Ty> begin, vector3<Ty> end, Ty ratio, Ty overshoot) noexcept {
    return {
        out_back(begin.x, end.x, ratio, overshoot),
        out_back(begin.y, end.y, ratio, overshoot),
        out_back(begin.z, end.z, ratio, overshoot)
    };
}

template <class Ty>
vector3<Ty> in_out_back(vector3<Ty> begin, vector3<Ty> end, Ty ratio, Ty overshoot) noexcept {
    return {
        in_out_back(begin.x, end.x, ratio, overshoot),
        in_out_back(begin.y, end.y, ratio, overshoot),
        in_out_back(begin.z, end.z, ratio, overshoot)
    };
}

template <class Ty>
vector3<Ty> out_in_back(vector3<Ty> begin, vector3<Ty> end, Ty ratio, Ty overshoot) noexcept {
    return {
        out_in_back(begin.x, end.x, ratio, overshoot),
        out_in_back(begin.y, end.y, ratio, overshoot),
        out_in_back(begin.z, end.z, ratio, overshoot)
    };
}





template <class Ty>
Ty in_elastic(Ty begin, Ty end, Ty ratio) noexcept {
    end -= begin;
    return end * sin(static_cast<Ty>(13) * PI<Ty> * ratio) * pow(static_cast<Ty>(2), static_cast<Ty>(10) * (ratio - static_cast<Ty>(1))) + begin;
}

template <class Ty>
float out_elastic(Ty begin, Ty end, Ty ratio) noexcept {
    end -= begin;
    return end * sin(static_cast<Ty>(13) * PI<Ty> * ratio) * pow(static_cast<Ty>(2), static_cast<Ty>(-10) * ratio) + begin;
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
vector2<Ty> in_elastic(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_elastic(begin.x, end.x, ratio),
        in_elastic(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_elastic(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_elastic(begin.x, end.x, ratio),
        out_elastic(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> in_out_elastic(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_out_elastic(begin.x, end.x, ratio),
        in_out_elastic(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_in_elastic(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_in_elastic(begin.x, end.x, ratio),
        out_in_elastic(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector3<Ty> in_elastic(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_elastic(begin.x, end.x, ratio),
        in_elastic(begin.y, end.y, ratio),
        in_elastic(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_elastic(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_elastic(begin.x, end.x, ratio),
        out_elastic(begin.y, end.y, ratio),
        out_elastic(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> in_out_elastic(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_out_elastic(begin.x, end.x, ratio),
        in_out_elastic(begin.y, end.y, ratio),
        in_out_elastic(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_in_elastic(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_in_elastic(begin.x, end.x, ratio),
        out_in_elastic(begin.y, end.y, ratio),
        out_in_elastic(begin.z, end.z, ratio)
    };
}







template <class Ty>
double out_bounce(Ty begin, Ty end, Ty ratio) noexcept {
    end -= begin;

    if (ratio < static_cast<Ty>(1.0 / 2.75)) {
        return end * (static_cast<Ty>(7.5625) * ratio * ratio) + begin;
    }
    else if (ratio < static_cast<Ty>(2.0 / 2.75)) {
        ratio -= static_cast<Ty>(1.5 / 2.75);
        return end * (static_cast<Ty>(7.5625) * ratio * ratio + static_cast<Ty>(0.75)) + begin;
    }
    else if (ratio < static_cast<Ty>(2.5 / 2.75)) {
        ratio -= static_cast<Ty>(2.25 / 2.75);
        return end * (static_cast<Ty>(7.5625) * ratio * ratio + static_cast<Ty>(0.9375)) + begin;
    }
    ratio -= static_cast<Ty>(2.625 / 2.75);
    return end * (static_cast<Ty>(7.5625) * ratio * ratio + static_cast<Ty>(0.984375)) + begin;
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

template <class Ty>
vector2<Ty> in_bounce(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_bounce(begin.x, end.x, ratio),
        in_bounce(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_bounce(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_bounce(begin.x, end.x, ratio),
        out_bounce(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> in_out_bounce(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        in_out_bounce(begin.x, end.x, ratio),
        in_out_bounce(begin.y, end.y, ratio)
    };
}

template <class Ty>
vector2<Ty> out_in_bounce(vector2<Ty> begin, vector2<Ty> end, Ty ratio) noexcept {
    return {
        out_in_bounce(begin.x, end.x, ratio),
        out_in_bounce(begin.y, end.y, ratio)
    };
}



template <class Ty>
vector3<Ty> in_bounce(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_bounce(begin.x, end.x, ratio),
        in_bounce(begin.y, end.y, ratio),
        in_bounce(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_bounce(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_bounce(begin.x, end.x, ratio),
        out_bounce(begin.y, end.y, ratio),
        out_bounce(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> in_out_bounce(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        in_out_bounce(begin.x, end.x, ratio),
        in_out_bounce(begin.y, end.y, ratio),
        in_out_bounce(begin.z, end.z, ratio)
    };
}

template <class Ty>
vector3<Ty> out_in_bounce(vector3<Ty> begin, vector3<Ty> end, Ty ratio) noexcept {
    return {
        out_in_bounce(begin.x, end.x, ratio),
        out_in_bounce(begin.y, end.y, ratio),
        out_in_bounce(begin.z, end.z, ratio)
    };
}


} // namespace Tween
} // namespace gdv

#endif
