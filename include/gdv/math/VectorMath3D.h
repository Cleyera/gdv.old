#ifndef VECTOR_MATH_3D_H_
#define VECTOR_MATH_3D_H_

//#define USE_AVX


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


#include "gdv/math/Matrix.h"
#include "gdv/math/Vector.h"

namespace gdv {

namespace simd {

matrix UnitMatrix();

matrix Transpose(matrix m);


namespace column_major {

mat4 Scaling(float x, float y, float z);


mat4 Translation(float x, float y, float z);


mat4 RotationX(float radians);


mat4 RotationY(float radians);


mat4 RotationZ(float radians);


mat4 Rotation(vec3 axis, float angle);


namespace left_hand {
}
namespace right_hand {
}
}



namespace row_major {

mat4 Scaling(float x, float y, float z);


mat4 Translation(float x, float y, float z);


mat4 RotationX(float radians);


mat4 RotationY(float radians);


mat4 RotationZ(float radians);


mat4 Rotation(vec3 axis, float angle);



namespace left_hand {
}
namespace right_hand {
}
}
}

} // namespace gdv

#endif
