#ifndef VECTOR_MATH_3D_H_
#define VECTOR_MATH_3D_H_

//#define USE_AVX


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


#include "gdv/Math/Matrix.h"
#include "gdv/Math/Vector.h"

namespace gdv {

namespace simd {

Matrix UnitMatrix();

Matrix Transpose(Matrix m);


namespace ColumnMajor {

///	<summery>
///
///	</summery>
///	<param name='x'>
///
///	</param>
///	<param name='y'>
///
///	</param>
///	<param name='z'>
///
///	</param>
Mat4 Scaling(float x, float y, float z);



///	<summery>
///
///	</summery>
///	<param name='x'>
///
///	</param>
///	<param name='y'>
///
///	</param>
///	<param name='z'>
///
///	</param>
Mat4 Translation(float x, float y, float z);




///	<summery>
///
///	</summery>
///	<param name='radians'>
///
///	</param>
Mat4 RotationX(float radians);



///	<summery>
///
///	</summery>
///	<param name='radians'>
///
///	</param>
Mat4 RotationY(float radians);



///	<summery>
///
///	</summery>
///	<param name='radians'>
///
///	</param>
Mat4 RotationZ(float radians);


///	<summery>
///
///	</summery>
///	<param name='axis'>
///
///	</param>
///	<param name='angle'>
///
///	</param>
/// <remarks>
///
///	</remarks>
Mat4 Rotation(Vec3 axis, float angle);


namespace LH {
}
namespace RH {
}
}



namespace RowMajor {
///	<summery>
///
///	</summery>
///	<param name='x'>
///
///	</param>
///	<param name='y'>
///
///	</param>
///	<param name='z'>
///
///	</param>
Mat4 Scaling(float x, float y, float z);



///	<summery>
///
///	</summery>
///	<param name='x'>
///
///	</param>
///	<param name='y'>
///
///	</param>
///	<param name='z'>
///
///	</param>
Mat4 Translation(float x, float y, float z);




///	<summery>
///
///	</summery>
///	<param name='radians'>
///
///	</param>
Mat4 RotationX(float radians);



///	<summery>
///
///	</summery>
///	<param name='radians'>
///
///	</param>
Mat4 RotationY(float radians);



///	<summery>
///
///	</summery>
///	<param name='radians'>
///
///	</param>
Mat4 RotationZ(float radians);


///	<summery>
///
///	</summery>
///	<param name='axis'>
///
///	</param>
///	<param name='angle'>
///
///	</param>
/// <remarks>
///		
///	</remarks>
Mat4 Rotation(Vec3 axis, float angle);



namespace LH {
}
namespace RH {
}
}
}

} // namespace gdv

#endif
