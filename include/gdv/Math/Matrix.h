#ifndef GDV_MATRIX_H_
#define GDV_MATRIX_H_

#if defined(USE_AVX)
#	if !__has_include(<immintrin.h>)
#		error AVX is not supported.
#	else // !__has_include(<immintrin.h>)
#		include <immintrin.h>
#	endif // !__has_include(<immintrin.h>)
#else // defined(USE_AVX)
#	if !__has_include(<pmmintrin.h>)
#		error SSE3 is not supported.
#	else // !__has_include(<immintrin.h>)
#		include <pmmintrin.h>
#	endif // !__has_include(<immintrin.h>)
#endif // defined(USE_AVX)

#include "gdv/Math/Matrix4x4.h"
#include "gdv/Math/Vector.h"

namespace gdv {

namespace simd {

class Matrix {
public:
	Matrix();
	Matrix(const Matrix &m);
	Matrix( float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);
	Matrix(Matrix4x4<float> m);
	Matrix(__m128 m1, __m128 m2, __m128 m3, __m128 m4);


public:
	Matrix& operator = (const Matrix4x4<float> &m);
	Matrix& operator = (const Matrix &m);


public:
	operator Matrix4x4<float>();

public:
	__m128 m[4];
};


Matrix operator + (Matrix &m, float n);
Matrix operator - (Matrix &m, float n);
Matrix operator * (Matrix &m, float n);
Matrix operator / (Matrix &m, float n);
Matrix& operator += (Matrix &m, float n);
Matrix& operator -= (Matrix &m, float n);
Matrix& operator *= (Matrix &m, float n);
Matrix& operator /= (Matrix &m, float n);


Matrix operator + (Matrix &m1, Matrix &m2);
Matrix operator - (Matrix &m1, Matrix &m2);
Matrix operator * (Matrix &m1, Matrix &m2);
Matrix& operator += (Matrix &m1, Matrix &m2);
Matrix& operator -= (Matrix &m1, Matrix &m2);
Matrix& operator *= (Matrix &m1, Matrix &m2);

Vector operator * (Matrix &m, Vector &v);
Vector operator * (Vector &v, Matrix &m);
Vector& operator *= (Vector &v, Matrix &m);

} // namespace simd;
} // namespace gdv

#endif
