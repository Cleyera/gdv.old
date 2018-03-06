#ifndef GDV_VECTOR3_H_
#define GDV_VECTOR3_H_

#include <type_traits>
#include "gdv/Math/Vector2.h"

namespace gdv {

template<class Ty>
class alignas(alignof(Ty)) Vector3 {
	//	Vector3�N���X�̓X�J���^�݂̂̃T�|�[�g
	static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

	constexpr Vector3() noexcept :
		x{},y{},z{}{}

	constexpr Vector3(Ty x, Ty y, Ty z) noexcept :
		x{x},y{y},z{z}{}

	constexpr Vector3(const Vector3<Ty> &v) noexcept :
		x{v.x},y{v.y},z{v.z}{}

	constexpr Vector3(const Vector2<Ty> &v) noexcept :
		x{v.x},y{v.y},z{1.0}{}




	Vector3<Ty>& operator = (const Vector3<Ty> &v) noexcept {
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}


	operator Vector2<Ty>() const noexcept {return {x, y};}


public:
	Ty x;
	Ty y;
	Ty z;
};



template<class Ty>
bool operator == (Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}

template<class Ty>
bool operator != (Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	return v1.x != v2.x || v1.y != v2.y || v1.z != v2.z;
}

template<class Ty>
Vector3<Ty>& operator += (Vector3<Ty> &v1, Vector3<Ty> v2) noexcept {
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return v1;
}

template<class Ty>
Vector3<Ty>& operator += (Vector3<Ty> &pt, Ty val) noexcept {
	pt.x += val;
	pt.y += val;
	pt.z += val;
	return pt;
}

template<class Ty>
Vector3<Ty>& operator -= (Vector3<Ty> &v1, Vector3<Ty> v2) noexcept {
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return v1;
}

template<class Ty>
Vector3<Ty>& operator -= (Vector3<Ty> &pt, Ty val) noexcept {
	pt.x -= val;
	pt.y -= val;
	pt.z -= val;
	return pt;
}

template<class Ty>
Vector3<Ty>& operator *= (Vector3<Ty> &pt, Ty val) noexcept {
	pt.x *= val;
	pt.y *= val;
	pt.z *= val;
	return pt;
}

template<class Ty>
Vector3<Ty>& operator /= (Vector3<Ty> &pt, Ty val) noexcept {
	pt.x /= val;
	pt.y /= val;
	pt.z /= val;
	return pt;
}

template<class Ty>
Vector3<Ty> operator + (Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

template<class Ty>
Vector3<Ty> operator + (Vector3<Ty> pt, Ty val) noexcept {
	return {pt.x + val, pt.y + val, pt.z + val};
}

template<class Ty>
Vector3<Ty> operator - (Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

template<class Ty>
Vector3<Ty> operator - (Vector3<Ty> pt, Ty val) noexcept {
	return {pt.x - val, pt.y - val, pt.z - val};
}

template<class Ty>
Vector3<Ty> operator * (Vector3<Ty> pt, Ty val) noexcept {
	return {pt.x * val, pt.y * val, pt.z * val};
}
template<class Ty>
Vector3<Ty> operator / (Vector3<Ty> pt, Ty val) noexcept {
	return {pt.x / val, pt.y / val, pt.z / val};
}




template<class Ty>
Ty Dot(Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}


template<class Ty>
Vector3<Ty> Cross(Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
	return {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x};
}


template<class Ty>
Ty Angle(Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	return static_cast<Ty>(atan2(Dot(v1, v2), Cross(v1, v2)));
}


template<class Ty>
Ty Length(Vector3<Ty> v) noexcept {
	static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
	return static_cast<Ty>(hypot(hypot(v.x, v.y), v.z));
}


template<class Ty>
Vector3<Ty> Normalize(Vector3<Ty> v) noexcept {
	return (v / Length(v));
}




using Point3	= Vector3<int>;
using Vec3		= Vector3<float>;

} // namespace gdv

#endif
