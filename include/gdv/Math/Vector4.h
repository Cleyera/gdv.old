#ifndef GDV_VECTOR4_H_
#define GDV_VECTOR4_H_

#include <type_traits>
#include "gdv/Math/Vector3.h"

namespace gdv {

template<class Ty>
class alignas(alignof(Ty)) Vector4 {
	static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

	constexpr Vector4() noexcept :
		x{}, y{}, z{}, w{}{}

	constexpr Vector4(Ty x, Ty y, Ty z) noexcept :
		x{x}, y{y}, z{z}, w{static_cast<Ty>(1)}{}

	constexpr Vector4(Ty x, Ty y, Ty z, Ty w) noexcept :
		x{x}, y{y}, z{z}, w{w}{}

	constexpr Vector4(const Vector4<Ty> &v) noexcept :
		x{v.x}, y{v.y}, z{v.z}, w{v.w}{}

	constexpr Vector4(const Vector3<Ty> &v) noexcept :
		x{v.x}, y{v.y}, z{v.z}, w{static_cast<Ty>(1)}{}

	constexpr Vector4(const Vector3<Ty> &v, Ty w) noexcept :
		x{v.x}, y{v.y}, z{v.z}, w{w}{}






	Vector4<Ty>& operator = (const Vector4<Ty> &v) noexcept {
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
		return *this;
	}


	Vector4<Ty>& operator = (const Vector3<Ty> &v) noexcept {
		x = v.x;
		y = v.y;
		z = v.z;
		w = static_cast<Ty>(1);
		return *this;
	}


	operator Vector3<Ty>() const noexcept {return {x, y, z};}

public:
	Ty x;
	Ty y;
	Ty z;
	Ty w;
};




using Vec4 = Vector4<float>;

} // namespace gdv

#endif
