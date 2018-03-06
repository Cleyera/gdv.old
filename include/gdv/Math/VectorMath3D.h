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
///		�g���s�����v�Z���܂�
///	</summery>
///	<param name='x'>
///		x�����̊g�嗦
///	</param>
///	<param name='y'>
///		y�����̊g�嗦
///	</param>
///	<param name='z'>
///		z�����̊g�嗦
///	</param>
Mat4 Scaling(float x, float y, float z);



///	<summery>
///		�ړ��s�����v�Z���܂�
///	</summery>
///	<param name='x'>
///		x�����̈ړ���
///	</param>
///	<param name='y'>
///		y�����̈ړ���
///	</param>
///	<param name='z'>
///		z�����̈ړ���
///	</param>
Mat4 Translation(float x, float y, float z);




///	<summery>
///		x�������̉��]�s�����v�Z���܂�
///	</summery>
///	<param name='radians'>
///		���]�p�x(���W�A��)
///	</param>
Mat4 RotationX(float radians);



///	<summery>
///		y�������̉��]�s�����v�Z���܂�
///	</summery>
///	<param name='radians'>
///		���]�p�x(���W�A��)
///	</param>
Mat4 RotationY(float radians);



///	<summery>
///		z�������̉��]�s�����v�Z���܂�
///	</summery>
///	<param name='radians'>
///		���]�p�x(���W�A��)
///	</param>
Mat4 RotationZ(float radians);


///	<summery>
///		�C�ӎ����]���\���s�����v�Z���܂�
///	</summery>
///	<param name='axis'>
///		�C�ӎ�
///	</param>
///	<param name='angle'>
///		���]��
///	</param>
/// <remarks>
///		�����\���x�N�g���͐��K�������Ă����K�v�͂����܂���
///	</remarks>
Mat4 Rotation(Vec3 axis, float angle);


namespace LH {
}
namespace RH {
}
}



namespace RowMajor {
///	<summery>
///		�g���s�����v�Z���܂�
///	</summery>
///	<param name='x'>
///		x�����̊g�嗦
///	</param>
///	<param name='y'>
///		y�����̊g�嗦
///	</param>
///	<param name='z'>
///		z�����̊g�嗦
///	</param>
Mat4 Scaling(float x, float y, float z);



///	<summery>
///		�ړ��s�����v�Z���܂�
///	</summery>
///	<param name='x'>
///		x�����̈ړ���
///	</param>
///	<param name='y'>
///		y�����̈ړ���
///	</param>
///	<param name='z'>
///		z�����̈ړ���
///	</param>
Mat4 Translation(float x, float y, float z);




///	<summery>
///		x�������̉��]�s�����v�Z���܂�
///	</summery>
///	<param name='radians'>
///		���]�p�x(���W�A��)
///	</param>
Mat4 RotationX(float radians);



///	<summery>
///		y�������̉��]�s�����v�Z���܂�
///	</summery>
///	<param name='radians'>
///		���]�p�x(���W�A��)
///	</param>
Mat4 RotationY(float radians);



///	<summery>
///		z�������̉��]�s�����v�Z���܂�
///	</summery>
///	<param name='radians'>
///		���]�p�x(���W�A��)
///	</param>
Mat4 RotationZ(float radians);


///	<summery>
///		�C�ӎ����]���\���s�����v�Z���܂�
///	</summery>
///	<param name='axis'>
///		�C�ӎ�
///	</param>
///	<param name='angle'>
///		���]��
///	</param>
/// <remarks>
///		�����\���x�N�g���͐��K�������Ă����K�v�͂����܂���
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
