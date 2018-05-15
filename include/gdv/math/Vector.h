#ifndef GDV_VECTOR_H_
#define GDV_VECTOR_H_

//#define USE_AVX


#if defined(USE_AVX)
#if !__has_include(<immintrin.h>)
#error AVX is not supported.
#else // !__has_include(<immintrin.h>)
#include <immintrin.h>
#endif // !__has_include(<immintrin.h>)
#else // defined(USE_AVX)
#if !__has_include(<pmmintrin.h>)
#error SSE3 is not supported.
#else // !__has_include(<immintrin.h>)
#include <pmmintrin.h>
#endif // !__has_include(<immintrin.h>)
#endif // defined(USE_AVX)

#if 0
#include <immintrin.h> //avx
#include <nmmintrin.h> //sse4.2
#include <smmintrin.h> //sse4.1
#include <tmmintrin.h> //ssse3
#include <pmmintrin.h> //sse3
#include <emmintrin.h> //sse2
#include <xmmintrin.h> //sse
#include <arm_neon.h> //arm neon
#endif

#include "gdv/math/vector3.h"
#include "gdv/math/vector4.h"

namespace gdv {

namespace simd {


class Vector {
public:
    Vector() noexcept;
    Vector(const Vector &vec) noexcept;
    Vector(float x, float y, float z, float w) noexcept;
    Vector(vector3<float> vec) noexcept;
    Vector(vector3<float> vec, float w) noexcept;
    Vector(vector4<float> vec) noexcept;
    Vector(__m128 vec) noexcept;


public:
    Vector& operator = (vector3<float> vec) noexcept;
    Vector& operator = (vector4<float> vec) noexcept;
    Vector& operator = (const Vector &vec) noexcept;


public:
    operator vector3<float>() noexcept;
    operator vector4<float>() noexcept;


public:
    __m128 v;
};


Vector operator + (Vector &v, float n);
Vector operator - (Vector &v, float n);
Vector operator * (Vector &v, float n);
Vector operator / (Vector &v, float n);
Vector& operator += (Vector &v, float n);
Vector& operator -= (Vector &v, float n);
Vector& operator *= (Vector &v, float n);
Vector& operator /= (Vector &v, float n);


Vector operator + (Vector &v1, Vector &v2);
Vector operator - (Vector &v1, Vector &v2);
Vector operator * (Vector &v1, Vector &v2);
Vector operator / (Vector &v1, Vector &v2);
Vector& operator += (Vector &v1, Vector &v2);
Vector& operator -= (Vector &v1, Vector &v2);
Vector& operator *= (Vector &v1, Vector &v2);
Vector& operator /= (Vector &v1, Vector &v2);


} // namespace simd;
} // namespace gdv

#endif
