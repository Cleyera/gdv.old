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

#include "gdv/Math/Vector3.h"
#include "gdv/Math/Vector4.h"

namespace gdv {

namespace simd {


class Vector {
public:
	Vector();
	Vector(const Vector &vec);
	Vector(float x, float y, float z, float w);
	Vector(Vector3<float> vec);
	Vector(Vector3<float> vec, float w);
	Vector(Vector4<float> vec);
	Vector(__m128 vec);


public:
	Vector& operator = (Vector3<float> vec);
	Vector& operator = (Vector4<float> vec);
	Vector& operator = (const Vector &vec);


public:
	operator Vector3<float>();
	operator Vector4<float>();


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
