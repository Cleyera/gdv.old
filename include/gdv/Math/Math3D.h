#ifndef GDV_MATH3D_H_
#define GDV_MATH3D_H_


#include "gdv/Math/Vector4.h"
#include "gdv/Math/Matrix4x4.h"
#include "gdv/Math/Matrix3x3.h"


namespace gdv {


///	<summery>
///		単位行列を作成
///	</summery>
Mat4 UnitMatrix() noexcept;



/// <summary>
///		3x3の行列を転地します
/// </summary>
/// <param name="m">
///		Matrix3x3
/// </param>
Mat3 Transpose(const Mat3 &m) noexcept;



/// <summary>
///		4x4の行列を転地します
/// </summary>
/// <param name="m">
///		Matrix4x4
/// </param>
Mat4 Transpose(const Mat4 &m) noexcept;









//-----------------------------------------------------------------------------
// function decralation
//-----------------------------------------------------------------------------


///	<summery>
///		列優先の格納形式
///	</summery>
namespace ColumnMajor {



///	<summery>
///		スケーリング行列を作成
///	</summery>
///	<param name='x'>
///		scale x
///	</param>
///	<param name='y'>
///		scale y
///	</param>
///	<param name='z'>
///		scale z
///	</param>
Mat4 Scaling(float x, float y, float z) noexcept;



///	<summery>
///		移動行列を作成
///	</summery>
///	<param name='x'>
///		Amount of movement in x
///	</param>
///	<param name='y'>
///		Amount of movement in y
///	</param>
///	<param name='z'>
///		Amount of movement in z
///	</param>
Mat4 Translation(float x, float y, float z) noexcept;




///	<summery>
///		x軸に関する回転行列を作成
///	</summery>
///	<param name='radians'>
///		amount of rotation
///	</param>
Mat4 RotationX(float radians) noexcept;



///	<summery>
///		y軸に関する回転行列を作成
///	</summery>
///	<param name='radians'>
///		amount of rotation
///	</param>
Mat4 RotationY(float radians) noexcept;



///	<summery>
///		z軸に関する回転行列を作成
///	</summery>
///	<param name='radians'>
///		amount of rotation
///	</param>
Mat4 RotationZ(float radians) noexcept;


///	<summery>
///		任意軸による回転行列を作成
///	</summery>
///	<param name='axis'>
///		回転軸
///	</param>
///	<param name='angle'>
///		回転角
///	</param>
Mat4 Rotation(Vec3 axis, float angle) noexcept;




///	<summery>
///		right hand coordinate system
///	</summery>
namespace RH {


/// <summary>
///		�r���[�s�����v�Z���܂�
/// </summary>
/// <param name="pos">
///		�J�����̈ʒu
/// </param>
/// <param name="dst">
///		�J�����̒����_
/// </param>
/// <param name="up">
///		�J�����̏����x�N�g��
/// </param>
Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept;



/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="left">
///		�N���b�v�������̍��[
/// </param>
/// <param name="right">
///		�N���b�v�������̉E�[
/// </param>
/// <param name="top">
///		�N���b�v�������̏��[
/// </param>
/// <param name="bottom">
///		�N���b�v�������̉��[
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Orthogonal(float left, float right, float top, float bottom, float near, float far) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="width">
///		�N���b�v�������̕�
/// </param>
/// <param name="height">
///		�N���b�v�������̍���
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Orthogonal(float width, float height, float near, float far) noexcept;




/// <summary>
///		�������e�s�����v�Z���܂�
/// </summary>
/// <param name="left">
///		�N���b�v�������̍��[
/// </param>
/// <param name="right">
///		�N���b�v�������̉E�[
///	</param>
/// <param name="top">
///		�N���b�v�������̏��[
/// </param>
/// <param name="bottom">
///		�N���b�v�������̉��[
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Perspective(float left, float right, float top, float bottom, float near, float far) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="width">
///		�N���b�v�������̕�
/// </param>
/// <param name="height">
///		�N���b�v�������̍���
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Perspective(float width, float height, float near, float far) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="angle">
///		�����p(���W�A���P��)
/// </param>
/// <param name="aspect">
///		�A�X�y�N�g��(width / height)
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
/// <returns></returns>
Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept;

} // namespace RH


///	<summery>
///		left hand coordinate system
///	</summery>
namespace LH {

/// <summary>
///		�r���[�s�����v�Z���܂�
/// </summary>
/// <param name="pos">
///		�J�����̈ʒu
/// </param>
/// <param name="dst">
///		�J�����̒����_
/// </param>
/// <param name="up">
///		�J�����̏����x�N�g��
/// </param>
Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="left">
///		�N���b�v�������̍��[
/// </param>
/// <param name="right">
///		�N���b�v�������̉E�[
/// </param>
/// <param name="top">
///		�N���b�v�������̏��[
/// </param>
/// <param name="bottom">
///		�N���b�v�������̉��[
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Orthogonal(float left, float right, float top, float bottom, float near, float far) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="width">
///		�N���b�v�������̕�
/// </param>
/// <param name="height">
///		�N���b�v�������̍���
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Orthogonal(float width, float height, float near, float far) noexcept;




/// <summary>
///		�������e�s�����v�Z���܂�
/// </summary>
/// <param name="left">
///		�N���b�v�������̍��[
/// </param>
/// <param name="right">
///		�N���b�v�������̉E�[
///	</param>
/// <param name="top">
///		�N���b�v�������̏��[
/// </param>
/// <param name="bottom">
///		�N���b�v�������̉��[
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Perspective(float left, float right, float top, float bottom, float near, float far) noexcept;



/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="width">
///		�N���b�v�������̕�
/// </param>
/// <param name="height">
///		�N���b�v�������̍���
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Perspective(float width, float height, float near, float far) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="angle">
///		�����p(���W�A���P��)
/// </param>
/// <param name="aspect">
///		�A�X�y�N�g��(width / height)
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept;

} // namespace LH

} // namespace ColumnMajor








//-----------------------------------------------------------------------------
// ���D���̊i�[�`��
//-----------------------------------------------------------------------------

///	<summery>
///		���D���̍s���p�֐������`���܂�
///	</summery>
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
Mat4 Scaling(float x, float y, float z) noexcept;




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
Mat4 Translation(float x, float y, float z) noexcept;



///	<summery>
///		x�������̉��]�s�����v�Z���܂�
///	</summery>
///	<param name='radians'>
///		���]�p�x(���W�A��)
///	</param>
Mat4 RotationX(float radians) noexcept;



///	<summery>
///		y�������̉��]�s�����v�Z���܂�
///	</summery>
///	<param name='radians'>
///		���]�p�x(���W�A��)
///	</param>
Mat4 RotationY(float radians) noexcept;



///	<summery>
///		z�������̉��]�s�����v�Z���܂�
///	</summery>
///	<param name='radians'>
///		���]�p�x(���W�A��)
///	</param>
Mat4 RotationZ(float radians) noexcept;


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
Mat4 Rotation(Vec3 axis, float angle) noexcept;


///	<summery>
///		right hand coordinate system
///	</summery>
namespace RH {


/// <summary>
///		�r���[�s�����v�Z���܂�
/// </summary>
/// <param name="pos">
///		�J�����̈ʒu
/// </param>
/// <param name="dst">
///		�J�����̒����_
/// </param>
/// <param name="up">
///		�J�����̏����x�N�g��
/// </param>
Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="left">
///		�N���b�v�������̍��[
/// </param>
/// <param name="right">
///		�N���b�v�������̉E�[
/// </param>
/// <param name="top">
///		�N���b�v�������̏��[
/// </param>
/// <param name="bottom">
///		�N���b�v�������̉��[
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Orthogonal(float left, float right, float top, float bottom, float near, float far) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="width">
///		�N���b�v�������̕�
/// </param>
/// <param name="height">
///		�N���b�v�������̍���
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Orthogonal(float width, float height, float near, float far) noexcept;




/// <summary>
///		�������e�s�����v�Z���܂�
/// </summary>
/// <param name="left">
///		�N���b�v�������̍��[
/// </param>
/// <param name="right">
///		�N���b�v�������̉E�[
///	</param>
/// <param name="top">
///		�N���b�v�������̏��[
/// </param>
/// <param name="bottom">
///		�N���b�v�������̉��[
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Perspective(float left, float right, float top, float bottom, float near, float far) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="width">
///		�N���b�v�������̕�
/// </param>
/// <param name="height">
///		�N���b�v�������̍���
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Perspective(float width, float height, float near, float far) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="angle">
///		�����p(���W�A���P��)
/// </param>
/// <param name="aspect">
///		�A�X�y�N�g��(width / height)
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
/// <returns></returns>
Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept;

} // namespace RH


///	<summery>
///		left hand coordinate system
///	</summery>
namespace LH {


/// <summary>
///		�r���[�s�����v�Z���܂�
/// </summary>
/// <param name="pos">
///		�J�����̈ʒu
/// </param>
/// <param name="dst">
///		�J�����̒����_
/// </param>
/// <param name="up">
///		�J�����̏����x�N�g��
/// </param>
Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="left">
///		�N���b�v�������̍��[
/// </param>
/// <param name="right">
///		�N���b�v�������̉E�[
/// </param>
/// <param name="top">
///		�N���b�v�������̏��[
/// </param>
/// <param name="bottom">
///		�N���b�v�������̉��[
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Orthogonal(float left, float right, float top, float bottom, float near, float far) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="width">
///		�N���b�v�������̕�
/// </param>
/// <param name="height">
///		�N���b�v�������̍���
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Orthogonal(float width, float height, float near, float far) noexcept;




/// <summary>
///		�������e�s�����v�Z���܂�
/// </summary>
/// <param name="left">
///		�N���b�v�������̍��[
/// </param>
/// <param name="right">
///		�N���b�v�������̉E�[
///	</param>
/// <param name="top">
///		�N���b�v�������̏��[
/// </param>
/// <param name="bottom">
///		�N���b�v�������̉��[
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Perspective(float left, float right, float top, float bottom, float near, float far) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="width">
///		�N���b�v�������̕�
/// </param>
/// <param name="height">
///		�N���b�v�������̍���
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 Perspective(float width, float height, float near, float far) noexcept;


/// <summary>
///		���s���e�s�����v�Z���܂�
/// </summary>
/// <param name="angle">
///		�����p(���W�A���P��)
/// </param>
/// <param name="aspect">
///		�A�X�y�N�g��(width / height)
/// </param>
/// <param name="near">
///		�߂��̃N���b�v�ʂƂ̋���
/// </param>
/// <param name="far">
///		�����̃N���b�v�ʂƂ̋���
/// </param>
Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept;

} // namespace RowMajor
} // namespace LH
} // namespace gdv

#endif
