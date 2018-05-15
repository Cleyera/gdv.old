#include "gdv/math/VectorMath3D.h"

namespace gdv {
namespace simd {

matrix UnitMatrix() {
    return {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
}



matrix Transpose(matrix m) {
    __m128 lo1 = _mm_unpacklo_ps(m.m[0], m.m[1]);
    __m128 hi1 = _mm_unpackhi_ps(m.m[0], m.m[1]);
    __m128 lo2 = _mm_unpacklo_ps(m.m[2], m.m[3]);
    __m128 hi2 = _mm_unpackhi_ps(m.m[2], m.m[3]);
    return {
        _mm_movelh_ps(lo1, lo2),
        _mm_movehl_ps(lo2, lo1),
        _mm_movelh_ps(hi1, hi2),
        _mm_movehl_ps(hi2, hi1)
    };
}




namespace ColumnMajor {


mat4 Scaling(float x, float y, float z) {
    return {
           x, 0.0f, 0.0f, 0.0f,
        0.0f,    y, 0.0f, 0.0f,
        0.0f, 0.0f,    z, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}




mat4 Translation(float x, float y, float z);





mat4 RotationX(float radians);




mat4 RotationY(float radians);




mat4 RotationZ(float radians);



mat4 Rotation(vec3 axis, float angle);


namespace LH {
}
namespace RH {
}
}



namespace RowMajor {

mat4 Scaling(float x, float y, float z) {
    return {
        x, 0.0f, 0.0f, 0.0f,
        0.0f,    y, 0.0f, 0.0f,
        0.0f, 0.0f,    z, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}




mat4 Translation(float x, float y, float z);





mat4 RotationX(float radians);




mat4 RotationY(float radians);




mat4 RotationZ(float radians);



mat4 Rotation(vec3 axis, float angle);



namespace LH {
}
namespace RH {
}
}
}

} // namespace gdv
