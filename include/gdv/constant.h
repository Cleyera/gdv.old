/**
* @file constant.h
* @brief define constants
**/
#ifndef GDV_CONSTANT_H_
#define GDV_CONSTANT_H_

namespace gdv {

/**
* @tparam Ty type of pi
**/
template <class Ty>
constexpr Ty pi  = static_cast<Ty>(3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211);

/**
* @tparam Ty type of root 2
**/
template <class Ty>
constexpr Ty r2  = static_cast<Ty>(1.41421356237309504880168872420969807856967187537694807317667973799073247846210703885038753432764);

/**
* @tparam Ty type of root 3
**/
template <class Ty>
constexpr Ty r3  = static_cast<Ty>(1.73205080756887729352744634150587236694280525381038062805580697945193301690880003708114618675724);

/**
* @tparam Ty type of napier
**/
template <class Ty>
constexpr Ty e   = static_cast<Ty>(2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138217852516);

/**
* @tparam Ty type of phy
**/
template <class Ty>
constexpr Ty phy = static_cast<Ty>(1.61803398874989484820458683436563811772030917980576286213544862270526046281890244970720720418939);

} // namespace gdv

#endif

