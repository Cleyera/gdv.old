//-----------------------------------------------------------------------------
//
//	���W�Ǘ��N���X
//
//-----------------------------------------------------------------------------
#ifndef GDV_MATRIX4X4_H_
#define GDV_MATRIX4X4_H_

#include <type_traits>
#include "gdv/Math/Vector4.h"

namespace gdv {

template<class Ty>
class Matrix4x4 {
	static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

	constexpr Matrix4x4<Ty>() noexcept :
		m{}{}


	constexpr Matrix4x4<Ty>(Ty m11, Ty m12, Ty m13, Ty m14,
							Ty m21, Ty m22, Ty m23, Ty m24,
							Ty m31, Ty m32, Ty m33, Ty m34,
							Ty m41, Ty m42, Ty m43, Ty m44) noexcept :
							m {	m11, m12, m13, m14,
								m21, m22, m23, m24,
								m31, m32, m33, m34,
								m41, m42, m43, m44}{}


	constexpr Matrix4x4<Ty>(const Matrix4x4<Ty> &m) noexcept = default;



	Matrix4x4<Ty>& operator = (const Matrix4x4<Ty> &v) noexcept = default;


	float* operator[](int i) noexcept {return &m[4 * i];}


public:
	Ty m[16];
};


template<class Ty>
Matrix4x4<Ty> operator+(const Matrix4x4<Ty> &m1, const Matrix4x4<Ty> &m2) noexcept {
	return {
		m1.m[ 0] + m2.m[ 0],
		m1.m[ 1] + m2.m[ 1],
		m1.m[ 2] + m2.m[ 2],
		m1.m[ 3] + m2.m[ 3],
		m1.m[ 4] + m2.m[ 4],
		m1.m[ 5] + m2.m[ 5],
		m1.m[ 6] + m2.m[ 6],
		m1.m[ 7] + m2.m[ 7],
		m1.m[ 8] + m2.m[ 8],
		m1.m[ 9] + m2.m[ 9],
		m1.m[10] + m2.m[10],
		m1.m[11] + m2.m[11],
		m1.m[12] + m2.m[12],
		m1.m[13] + m2.m[13],
		m1.m[14] + m2.m[14],
		m1.m[15] + m2.m[15],
	};
}

template<class Ty>
Matrix4x4<Ty> operator-(const Matrix4x4<Ty> &m1, const Matrix4x4<Ty> &m2) noexcept {
	return {
		m1.m[ 0] - m2.m[ 0],
		m1.m[ 1] - m2.m[ 1],
		m1.m[ 2] - m2.m[ 2],
		m1.m[ 3] - m2.m[ 3],
		m1.m[ 4] - m2.m[ 4],
		m1.m[ 5] - m2.m[ 5],
		m1.m[ 6] - m2.m[ 6],
		m1.m[ 7] - m2.m[ 7],
		m1.m[ 8] - m2.m[ 8],
		m1.m[ 9] - m2.m[ 9],
		m1.m[10] - m2.m[10],
		m1.m[11] - m2.m[11],
		m1.m[12] - m2.m[12],
		m1.m[13] - m2.m[13],
		m1.m[14] - m2.m[14],
		m1.m[15] - m2.m[15],
	};
}


template<class Ty>
Matrix4x4<Ty> operator*(const Matrix4x4<Ty> &m1, const Matrix4x4<Ty> &m2) noexcept {
	return{
		m1.m[ 0] * m2.m[ 0] + m1.m[ 1] * m2.m[ 4] + m1.m[ 2] * m2.m[ 8] + m1.m[ 3] * m2.m[12],
		m1.m[ 0] * m2.m[ 1] + m1.m[ 1] * m2.m[ 5] + m1.m[ 2] * m2.m[ 9] + m1.m[ 3] * m2.m[13],
		m1.m[ 0] * m2.m[ 2] + m1.m[ 1] * m2.m[ 6] + m1.m[ 2] * m2.m[10] + m1.m[ 3] * m2.m[14],
		m1.m[ 0] * m2.m[ 3] + m1.m[ 1] * m2.m[ 7] + m1.m[ 2] * m2.m[11] + m1.m[ 3] * m2.m[15],

		m1.m[ 4] * m2.m[ 0] + m1.m[ 5] * m2.m[ 4] + m1.m[ 6] * m2.m[ 8] + m1.m[ 7] * m2.m[12],
		m1.m[ 4] * m2.m[ 1] + m1.m[ 5] * m2.m[ 5] + m1.m[ 6] * m2.m[ 9] + m1.m[ 7] * m2.m[13],
		m1.m[ 4] * m2.m[ 2] + m1.m[ 5] * m2.m[ 6] + m1.m[ 6] * m2.m[10] + m1.m[ 7] * m2.m[14],
		m1.m[ 4] * m2.m[ 3] + m1.m[ 5] * m2.m[ 7] + m1.m[ 6] * m2.m[11] + m1.m[ 7] * m2.m[15],

		m1.m[ 8] * m2.m[ 0] + m1.m[ 9] * m2.m[ 4] + m1.m[10] * m2.m[ 8] + m1.m[11] * m2.m[12],
		m1.m[ 8] * m2.m[ 1] + m1.m[ 9] * m2.m[ 5] + m1.m[10] * m2.m[ 9] + m1.m[11] * m2.m[13],
		m1.m[ 8] * m2.m[ 2] + m1.m[ 9] * m2.m[ 6] + m1.m[10] * m2.m[10] + m1.m[11] * m2.m[14],
		m1.m[ 8] * m2.m[ 3] + m1.m[ 9] * m2.m[ 7] + m1.m[10] * m2.m[11] + m1.m[11] * m2.m[15],

		m1.m[12] * m2.m[ 0] + m1.m[13] * m2.m[ 4] + m1.m[14] * m2.m[ 8] + m1.m[15] * m2.m[12],
		m1.m[12] * m2.m[ 1] + m1.m[13] * m2.m[ 5] + m1.m[14] * m2.m[ 9] + m1.m[15] * m2.m[13],
		m1.m[12] * m2.m[ 2] + m1.m[13] * m2.m[ 6] + m1.m[14] * m2.m[10] + m1.m[15] * m2.m[14],
		m1.m[12] * m2.m[ 3] + m1.m[13] * m2.m[ 7] + m1.m[14] * m2.m[11] + m1.m[15] * m2.m[15],
	};
}



template<class Ty>
Matrix4x4<Ty>& operator+=(Matrix4x4<Ty> &m1, const Matrix4x4<Ty> &m2) noexcept {
	m1.m[ 0] += m2.m[ 0];
	m1.m[ 1] += m2.m[ 1];
	m1.m[ 2] += m2.m[ 2];
	m1.m[ 3] += m2.m[ 3];
	m1.m[ 4] += m2.m[ 4];
	m1.m[ 5] += m2.m[ 5];
	m1.m[ 6] += m2.m[ 6];
	m1.m[ 7] += m2.m[ 7];
	m1.m[ 8] += m2.m[ 8];
	m1.m[ 9] += m2.m[ 9];
	m1.m[10] += m2.m[10];
	m1.m[11] += m2.m[11];
	m1.m[12] += m2.m[12];
	m1.m[13] += m2.m[13];
	m1.m[14] += m2.m[14];
	m1.m[15] += m2.m[15];
	return m1;
}

template<class Ty>
Matrix4x4<Ty>& operator-=(Matrix4x4<Ty> &m1, const Matrix4x4<Ty> &m2) noexcept {
	m1.m[ 0] -= m2.m[ 0];
	m1.m[ 1] -= m2.m[ 1];
	m1.m[ 2] -= m2.m[ 2];
	m1.m[ 3] -= m2.m[ 3];
	m1.m[ 4] -= m2.m[ 4];
	m1.m[ 5] -= m2.m[ 5];
	m1.m[ 6] -= m2.m[ 6];
	m1.m[ 7] -= m2.m[ 7];
	m1.m[ 8] -= m2.m[ 8];
	m1.m[ 9] -= m2.m[ 9];
	m1.m[10] -= m2.m[10];
	m1.m[11] -= m2.m[11];
	m1.m[12] -= m2.m[12];
	m1.m[13] -= m2.m[13];
	m1.m[14] -= m2.m[14];
	m1.m[15] -= m2.m[15];
	return m1;
}


template<class Ty>
Matrix4x4<Ty>& operator*=(Matrix4x4<Ty> &m1, const Matrix4x4<Ty> &m2) noexcept {
	Matrix4x4<Ty> m{
		m1.m[ 0] * m2.m[ 0] + m1.m[ 1] * m2.m[ 4] + m1.m[ 2] * m2.m[ 8] + m1.m[ 3] * m2.m[12],
		m1.m[ 0] * m2.m[ 1] + m1.m[ 1] * m2.m[ 5] + m1.m[ 2] * m2.m[ 9] + m1.m[ 3] * m2.m[13],
		m1.m[ 0] * m2.m[ 2] + m1.m[ 1] * m2.m[ 6] + m1.m[ 2] * m2.m[10] + m1.m[ 3] * m2.m[14],
		m1.m[ 0] * m2.m[ 3] + m1.m[ 1] * m2.m[ 7] + m1.m[ 2] * m2.m[11] + m1.m[ 3] * m2.m[15],

		m1.m[ 4] * m2.m[ 0] + m1.m[ 5] * m2.m[ 4] + m1.m[ 6] * m2.m[ 8] + m1.m[ 7] * m2.m[12],
		m1.m[ 4] * m2.m[ 1] + m1.m[ 5] * m2.m[ 5] + m1.m[ 6] * m2.m[ 9] + m1.m[ 7] * m2.m[13],
		m1.m[ 4] * m2.m[ 2] + m1.m[ 5] * m2.m[ 6] + m1.m[ 6] * m2.m[10] + m1.m[ 7] * m2.m[14],
		m1.m[ 4] * m2.m[ 3] + m1.m[ 5] * m2.m[ 7] + m1.m[ 6] * m2.m[11] + m1.m[ 7] * m2.m[15],

		m1.m[ 8] * m2.m[ 0] + m1.m[ 9] * m2.m[ 4] + m1.m[10] * m2.m[ 8] + m1.m[11] * m2.m[12],
		m1.m[ 8] * m2.m[ 1] + m1.m[ 9] * m2.m[ 5] + m1.m[10] * m2.m[ 9] + m1.m[11] * m2.m[13],
		m1.m[ 8] * m2.m[ 2] + m1.m[ 9] * m2.m[ 6] + m1.m[10] * m2.m[10] + m1.m[11] * m2.m[14],
		m1.m[ 8] * m2.m[ 3] + m1.m[ 9] * m2.m[ 7] + m1.m[10] * m2.m[11] + m1.m[11] * m2.m[15],

		m1.m[12] * m2.m[ 0] + m1.m[13] * m2.m[ 4] + m1.m[14] * m2.m[ 8] + m1.m[15] * m2.m[12],
		m1.m[12] * m2.m[ 1] + m1.m[13] * m2.m[ 5] + m1.m[14] * m2.m[ 9] + m1.m[15] * m2.m[13],
		m1.m[12] * m2.m[ 2] + m1.m[13] * m2.m[ 6] + m1.m[14] * m2.m[10] + m1.m[15] * m2.m[14],
		m1.m[12] * m2.m[ 3] + m1.m[13] * m2.m[ 7] + m1.m[14] * m2.m[11] + m1.m[15] * m2.m[15],
	};
	return m1 = m;
}



template<class Ty>
Vector4<Ty> operator*(const Vector4<Ty> &v, const Matrix4x4<Ty> &m) noexcept {
	return{
		m.m[ 0] * v.x + m.m[ 4] * v.y + m.m[ 8] * v.z + m.m[12] * v.w,
		m.m[ 1] * v.x + m.m[ 5] * v.y + m.m[ 9] * v.z + m.m[13] * v.w,
		m.m[ 2] * v.x + m.m[ 6] * v.y + m.m[10] * v.z + m.m[14] * v.w,
		m.m[ 3] * v.x + m.m[ 7] * v.y + m.m[11] * v.z + m.m[15] * v.w,
	};
}

template<class Ty>
Vector4<Ty> operator*(const Matrix4x4<Ty> &m, const Vector4<Ty> &v) noexcept {
	return{
		m.m[ 0] * v.x + m.m[ 1] * v.y + m.m[ 2] * v.z + m.m[ 3] * v.w,
		m.m[ 4] * v.x + m.m[ 5] * v.y + m.m[ 6] * v.z + m.m[ 7] * v.w,
		m.m[ 8] * v.x + m.m[ 9] * v.y + m.m[10] * v.z + m.m[11] * v.w,
		m.m[12] * v.x + m.m[13] * v.y + m.m[14] * v.z + m.m[15] * v.w,
	};
}


template<class Ty>
Vector4<Ty> operator*(const Vector3<Ty> &v, const Matrix4x4<Ty> &m) noexcept {
	return{
		m.m[ 0] * v.x + m.m[ 4] * v.y + m.m[ 8] * v.z + m.m[12],
		m.m[ 1] * v.x + m.m[ 5] * v.y + m.m[ 9] * v.z + m.m[13],
		m.m[ 2] * v.x + m.m[ 6] * v.y + m.m[10] * v.z + m.m[14],
		m.m[ 3] * v.x + m.m[ 7] * v.y + m.m[11] * v.z + m.m[15]
	};
}

template<class Ty>
Vector4<Ty> operator*(const Matrix4x4<Ty> &m, const Vector3<Ty> &v) noexcept {
	return{
		m.m[ 0] * v.x + m.m[ 1] * v.y + m.m[ 2] * v.z + m.m[ 3],
		m.m[ 4] * v.x + m.m[ 5] * v.y + m.m[ 6] * v.z + m.m[ 7],
		m.m[ 8] * v.x + m.m[ 9] * v.y + m.m[10] * v.z + m.m[11],
		m.m[12] * v.x + m.m[12] * v.y + m.m[14] * v.z + m.m[15]
	};
}

using Mat4 = Matrix4x4<float>;

} // namespace gdv

#endif
