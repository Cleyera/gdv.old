#include "gdv/Math/VectorMath3D.h"

namespace gdv {
namespace simd {

Matrix UnitMatrix() {
	return {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
	};
}



Matrix Transpose(Matrix m) {
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


Mat4 Scaling(float x, float y, float z) {
	return {
		   x, 0.0f, 0.0f, 0.0f,
		0.0f,    y, 0.0f, 0.0f,
		0.0f, 0.0f,    z, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
}




Mat4 Translation(float x, float y, float z);





Mat4 RotationX(float radians);




Mat4 RotationY(float radians);




Mat4 RotationZ(float radians);



Mat4 Rotation(Vec3 axis, float angle);


namespace LH {
}
namespace RH {
}
}



namespace RowMajor {

Mat4 Scaling(float x, float y, float z) {
	return {
		x, 0.0f, 0.0f, 0.0f,
		0.0f,    y, 0.0f, 0.0f,
		0.0f, 0.0f,    z, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
}




Mat4 Translation(float x, float y, float z);





Mat4 RotationX(float radians);




Mat4 RotationY(float radians);




Mat4 RotationZ(float radians);



Mat4 Rotation(Vec3 axis, float angle);



namespace LH {
}
namespace RH {
}
}
}

} // namespace gdv
