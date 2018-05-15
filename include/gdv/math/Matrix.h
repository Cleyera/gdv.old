#ifndef GDV_MATRIX_H_
#define GDV_MATRIX_H_

#if defined(USE_AVX)
#    if !__has_include(<immintrin.h>)
#        error AVX is not supported.
#    else // !__has_include(<immintrin.h>)
#        include <immintrin.h>
#    endif // !__has_include(<immintrin.h>)
#else // defined(USE_AVX)
#    if !__has_include(<pmmintrin.h>)
#        error SSE3 is not supported.
#    else // !__has_include(<immintrin.h>)
#        include <pmmintrin.h>
#    endif // !__has_include(<immintrin.h>)
#endif // defined(USE_AVX)

#include "gdv/math/matrix4x4.h"
#include "gdv/math/Vector.h"

namespace gdv {

namespace simd {

class matrix {
public:
    matrix() noexcept;
    matrix(const matrix &mat) noexcept;
    matrix( float m11, float m12, float m13, float m14,
            float m21, float m22, float m23, float m24,
            float m31, float m32, float m33, float m34,
            float m41, float m42, float m43, float m44) noexcept;
    matrix(matrix4x4<float> mat) noexcept;
    matrix(__m128 m1, __m128 m2, __m128 m3, __m128 m4) noexcept;


public:
    matrix& operator = (const matrix4x4<float> &mat) noexcept;
    matrix& operator = (const matrix &mat) noexcept;


public:
    operator matrix4x4<float>() noexcept;

public:
    __m128 m[4];
};


matrix operator + (matrix &m, float n);
matrix operator - (matrix &m, float n);
matrix operator * (matrix &m, float n);
matrix operator / (matrix &m, float n);
matrix& operator += (matrix &m, float n);
matrix& operator -= (matrix &m, float n);
matrix& operator *= (matrix &m, float n);
matrix& operator /= (matrix &m, float n);


matrix operator + (matrix &m1, matrix &m2);
matrix operator - (matrix &m1, matrix &m2);
matrix operator * (matrix &m1, matrix &m2);
matrix& operator += (matrix &m1, matrix &m2);
matrix& operator -= (matrix &m1, matrix &m2);
matrix& operator *= (matrix &m1, matrix &m2);

Vector operator * (matrix &m, Vector &v);
Vector operator * (Vector &v, matrix &m);
Vector& operator *= (Vector &v, matrix &m);

} // namespace simd;
} // namespace gdv

#endif
