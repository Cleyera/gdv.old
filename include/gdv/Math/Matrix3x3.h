#ifndef GDV_MATRIX3X3_H_
#define GDV_MATRIX3X3_H_

#include <type_traits>
#include "gdv/Math/Vector4.h"

namespace gdv {

template<class Ty>
class Matrix3x3 {

	static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

	constexpr Matrix3x3<Ty>() noexcept :
		m{}{}


	constexpr Matrix3x3<Ty>(Ty m11, Ty m12, Ty m13,
							Ty m21, Ty m22, Ty m23,
							Ty m31, Ty m32, Ty m33) noexcept :
							m {	m11, m12, m13,
								m21, m22, m23,
								m31, m32, m33}{}


	constexpr Matrix3x3<Ty>(const Matrix3x3<Ty> &m) noexcept = default;


	Matrix3x3<Ty>& operator = (const Matrix3x3<Ty> &v) noexcept = default;


	float* operator[](int i) noexcept {return &m[3 * i];}


public:
	Ty m[9];
};


template<class Ty>
Matrix3x3<Ty> operator+(const Matrix3x3<Ty> &m1, const Matrix3x3<Ty> &m2) noexcept {
	return {
		m1.m[0] + m2.m[0],
		m1.m[1] + m2.m[1],
		m1.m[2] + m2.m[2],
		m1.m[3] + m2.m[3],
		m1.m[4] + m2.m[4],
		m1.m[5] + m2.m[5],
		m1.m[6] + m2.m[6],
		m1.m[7] + m2.m[7],
		m1.m[8] + m2.m[8]
	};
}

template<class Ty>
Matrix3x3<Ty> operator-(const Matrix3x3<Ty> &m1, const Matrix3x3<Ty> &m2) noexcept {
	return {
		m1.m[0] - m2.m[0],
		m1.m[1] - m2.m[1],
		m1.m[2] - m2.m[2],
		m1.m[3] - m2.m[3],
		m1.m[4] - m2.m[4],
		m1.m[5] - m2.m[5],
		m1.m[6] - m2.m[6],
		m1.m[7] - m2.m[7],
		m1.m[8] - m2.m[8]
	};
}


template<class Ty>
Matrix3x3<Ty> operator*(const Matrix3x3<Ty> &m1, const Matrix3x3<Ty> &m2) noexcept {
	return{
		m1.m[0] * m2.m[0] + m1.m[1] * m2.m[3] + m1.m[2] * m2.m[6],
		m1.m[0] * m2.m[1] + m1.m[1] * m2.m[4] + m1.m[2] * m2.m[7],
		m1.m[0] * m2.m[2] + m1.m[1] * m2.m[5] + m1.m[2] * m2.m[8],

		m1.m[3] * m2.m[0] + m1.m[4] * m2.m[3] + m1.m[5] * m2.m[6],
		m1.m[3] * m2.m[1] + m1.m[4] * m2.m[4] + m1.m[5] * m2.m[7],
		m1.m[3] * m2.m[2] + m1.m[4] * m2.m[5] + m1.m[5] * m2.m[8],

		m1.m[6] * m2.m[0] + m1.m[7] * m2.m[3] + m1.m[8] * m2.m[6],
		m1.m[6] * m2.m[1] + m1.m[7] * m2.m[4] + m1.m[8] * m2.m[7],
		m1.m[6] * m2.m[2] + m1.m[7] * m2.m[5] + m1.m[8] * m2.m[8]
	};
}



template<class Ty>
Matrix3x3<Ty>& operator+=(Matrix3x3<Ty> &m1, const Matrix3x3<Ty> &m2) noexcept {
	m1.m[0] += m2.m[0];
	m1.m[1] += m2.m[1];
	m1.m[2] += m2.m[2];
	m1.m[3] += m2.m[3];
	m1.m[4] += m2.m[4];
	m1.m[5] += m2.m[5];
	m1.m[6] += m2.m[6];
	m1.m[7] += m2.m[7];
	m1.m[8] += m2.m[8];
	return m1;
}

template<class Ty>
Matrix3x3<Ty>& operator-=(Matrix3x3<Ty> &m1, const Matrix3x3<Ty> &m2) noexcept {
	m1.m[0] -= m2.m[0];
	m1.m[1] -= m2.m[1];
	m1.m[2] -= m2.m[2];
	m1.m[3] -= m2.m[3];
	m1.m[4] -= m2.m[4];
	m1.m[5] -= m2.m[5];
	m1.m[6] -= m2.m[6];
	m1.m[7] -= m2.m[7];
	m1.m[8] -= m2.m[8];
	return m1;
}


template<class Ty>
Matrix3x3<Ty>& operator*=(Matrix3x3<Ty> &m1, const Matrix3x3<Ty> &m2) noexcept {
	Matrix3x3<Ty> m{
		m1.m[0] * m2.m[0] + m1.m[1] * m2.m[3] + m1.m[2] * m2.m[6],
		m1.m[0] * m2.m[1] + m1.m[1] * m2.m[4] + m1.m[2] * m2.m[7],
		m1.m[0] * m2.m[2] + m1.m[1] * m2.m[5] + m1.m[2] * m2.m[8],

		m1.m[3] * m2.m[0] + m1.m[4] * m2.m[3] + m1.m[5] * m2.m[6],
		m1.m[3] * m2.m[1] + m1.m[4] * m2.m[4] + m1.m[5] * m2.m[7],
		m1.m[3] * m2.m[2] + m1.m[4] * m2.m[5] + m1.m[5] * m2.m[8],

		m1.m[6] * m2.m[0] + m1.m[7] * m2.m[3] + m1.m[8] * m2.m[6],
		m1.m[6] * m2.m[1] + m1.m[7] * m2.m[4] + m1.m[8] * m2.m[7],
		m1.m[6] * m2.m[2] + m1.m[7] * m2.m[5] + m1.m[8] * m2.m[8]
	};
	return m1 = m;
}



template<class Ty>
Vector4<Ty> operator*(const Vector4<Ty> &v, const Matrix3x3<Ty> &m) noexcept {
	return{
		m.m[0] * v.x + m.m[3] * v.y + m.m[6] * v.z,
		m.m[1] * v.x + m.m[4] * v.y + m.m[7] * v.z,
		m.m[2] * v.x + m.m[5] * v.y + m.m[8] * v.z
	};
}

template<class Ty>
Vector4<Ty> operator*(const Matrix3x3<Ty> &m, const Vector4<Ty> &v) noexcept {
	return{
		m.m[0] * v.x + m.m[1] * v.y + m.m[2] * v.z,
		m.m[3] * v.x + m.m[4] * v.y + m.m[5] * v.z,
		m.m[6] * v.x + m.m[7] * v.y + m.m[8] * v.z
	};
}


using Mat3 = Matrix3x3<float>;

} // namespace gdv

#endif
