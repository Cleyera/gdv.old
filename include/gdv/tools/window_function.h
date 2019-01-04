#ifndef GDV_WINDOW_SUNCTION_H_
#define GDV_WINDOW_SUNCTION_H_

#include <cmath>
#include <gdv/constant.h>

namespace gdv {


template <class Ty>
Ty hann(Ty x) {
    static constexpr Ty half = static_cast<Ty>(0.5);
    return half - half * std::cos(static_cast<Ty>(2) * pi<Ty> * x);
}


template <class Ty>
Ty hamming(Ty x) {
    return static_cast<Ty>(0.54) - static_cast<Ty>(0.46) * std::cos(static_cast<Ty>(2) * pi<Ty> * x);
}



template <class Ty>
Ty blackman(Ty x) {
    return static_cast<Ty>(0.42) 
        - static_cast<Ty>(0.5) * std::cos(static_cast<Ty>(2) * pi<Ty> * x) 
        + static_cast<Ty>(0.08) * std::cos(static_cast<Ty>(4) * pi<Ty> * x);
}


template <class Ty>
Ty bartlett(Ty x) {
    return static_cast<Ty>(1) - static_cast<Ty>(2) * std::abs(x - static_cast<Ty>(0.5));
}


template <class Ty>
Ty gauss(Ty x, Ty deviation) {
    return std::exp(-(x * x) / (deviation * deviation));
}


template <class Ty>
Ty bartlett_hann(Ty x) {
    return static_cast<Ty>(0.64)
        - static_cast<Ty>(0.48) * std::abs(x - static_cast<Ty>(0.5))
        - static_cast<Ty>(0.38) * std::cos(static_cast<Ty>(2) * pi<Ty> * x);
}


template <class Ty>
Ty nuttall(Ty x) {
    return static_cast<Ty>(0.355768) 
        + static_cast<Ty>(0.487396) * std::cos(static_cast<Ty>(4) * pi<Ty> * x)
        - static_cast<Ty>(0.012604) * std::cos(static_cast<Ty>(6) * pi<Ty> * x);
}



template <class Ty>
Ty blackman_harris(Ty x) {
    return static_cast<Ty>(0.35875) 
        - static_cast<Ty>(0.48829) * std::cos(static_cast<Ty>(2) * pi<Ty> * x)
        + static_cast<Ty>(0.14128) * std::cos(static_cast<Ty>(4) * pi<Ty> * x)
        - static_cast<Ty>(0.01168) * std::cos(static_cast<Ty>(6) * pi<Ty> * x);
}



template <class Ty>
Ty blackman_nuttall(Ty x) {
    return static_cast<Ty>(0.3635819) 
        - static_cast<Ty>(0.4891775) * std::cos(static_cast<Ty>(2) * pi<Ty> * x)
        + static_cast<Ty>(0.1365995) * std::cos(static_cast<Ty>(4) * pi<Ty> * x)
        - static_cast<Ty>(0.0106411) * std::cos(static_cast<Ty>(6) * pi<Ty> * x);
}



template <class Ty>
Ty flat_top(Ty x) {
    return static_cast<Ty>(1) 
        - static_cast<Ty>(1.93)  * std::cos(static_cast<Ty>(2) * pi<Ty> * x)
        + static_cast<Ty>(1.29)  * std::cos(static_cast<Ty>(4) * pi<Ty> * x)
        - static_cast<Ty>(0.388) * std::cos(static_cast<Ty>(6) * pi<Ty> * x)
        + static_cast<Ty>(0.032) * std::cos(static_cast<Ty>(8) * pi<Ty> * x);
}


template <class Ty>
Ty parzen(Ty x) {
    x = std::abs(x * static_cast<Ty>(2));
    const Ty t = std::ceil(x - static_cast<Ty>(1));
    return (static_cast<Ty>(1) - static_cast<Ty>(1.5) * std::pow(x, 2) + static_cast<Ty>(0.75) * std::pow(std::abs(x), 3)) * (static_cast<Ty>(1) - t) 
        + (static_cast<Ty>(0.25) * (static_cast<Ty>(2) - std::pow(std::abs(x), 3))) * t;
}


template <class Ty>
Ty akaike(Ty x) {
    return static_cast<Ty>(0.625) 
        + static_cast<Ty>(0.5) * std::cos(static_cast<Ty>(2) * pi<Ty> * x)
        - static_cast<Ty>(0.125) * std::cos(static_cast<Ty>(4) * pi<Ty> * x);
}


template <class Ty>
Ty sine(Ty x) {
    return std::sin(pi<Ty> * x);
}


template <class Ty>
Ty vorbis(Ty x) {
    return std::sin(pi<Ty> / static_cast<Ty>(2) * std::pow(std::sin(pi<Ty> * x), 2));
}



template <class Ty>
Ty lanczos(Ty x, Ty n) {
    return (std::sin(pi<Ty> * x) / (pi<Ty> * x)) * (std::sin(pi<Ty> * (x / n)) / (pi<Ty> * (x / n)));
}


} // namespace gdv;


#endif

