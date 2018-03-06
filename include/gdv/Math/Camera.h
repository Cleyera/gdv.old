#ifndef GDV_CAMERA_H_
#define GDV_CAMERA_H_

#include "gdv/Math/Vector3.h"
#include "gdv/Math/Matrix4x4.h"

namespace gdv {

///	<summery>
///		�J�����̏������i�[�����N���X
///	</summery>
class Camera {
public:

	///	<summery>
	///		�J�����̓��e���[�h�̒��`
	///	</summery>
	enum class Mode : int {

		///	<summery>
		///		�������e�J����
		///	</summery>
		PERSPECTIVE,

		///	<summery>
		///		���s���e�J����
		///	</summery>
		ORTHOGONAL,
	};


public:
	///	<summery>
	///		�f�t�H���g�R���X�g���N�^
	///	</summery>
	Camera()noexcept;



	///	<summery>
	///		�R���X�g���N�^
	///	</summery>
	///	<param name='mode'>
	///		�J�����̃��[�h
	///	</param>
	///	<param name='pos'>
	///		�J�����̈ʒu
	///	</param>
	///	<param name='dst'>
	///		�J�����̒����_
	///	</param>
	///	<param name='top'>
	///		�߂��̃N���b�v�ʂ̎������̏��[
	///	</param>
	///	<param name='left'>
	///		�߂��̃N���b�v�ʂ̎������̍��[
	///	</param>
	///	<param name='bottom'>
	///		�߂��̃N���b�v�ʂ̎������̉��[
	///	</param>
	///	<param name='right'>
	///		�߂��̃N���b�v�ʂ̎������̉E�[
	///	</param>
	///	<param name='near'>
	///		�߂��̃N���b�v�ʂ̉��s��
	///	</param>
	///	<param name='far'>
	///		�����̃N���b�v�ʂ̉��s��
	///	</param>
	Camera(
		Mode mode,
		Vec3 pos,
		Vec3 dst,
		float top,
		float left,
		float bottom,
		float right,
		float near,
		float far)noexcept;




	///	<summery>
	///		�R���X�g���N�^
	///	</summery>
	///	<param name='mode'>
	///		�J�����̃��[�h
	///	</param>
	///	<param name='pos'>
	///		�J�����̈ʒu
	///	</param>
	///	<param name='dst'>
	///		�J�����̒����_
	///	</param>
	///	<param name='width'>
	///		�߂��̃N���b�v�ʂ̎������̕�
	///	</param>
	///	<param name='height'>
	///		�߂��̃N���b�v�ʂ̎������̍���
	///	</param>
	///	<param name='near'>
	///		�߂��̃N���b�v�ʂ̉��s��
	///	</param>
	///	<param name='far'>
	///		�����̃N���b�v�ʂ̉��s��
	///	</param>
	Camera(
		Mode mode,
		Vec3 pos,
		Vec3 dst,
		float width,
		float height,
		float near,
		float far)noexcept;






	///	<summery>
	///		�R���X�g���N�^
	///	</summery>
	///	<param name='mode'>
	///		�J�����̃��[�h
	///	</param>
	///	<param name='pos'>
	///		�J�����̈ʒu
	///	</param>
	///	<param name='dst'>
	///		�J�����̒����_
	///	</param>
	///	<param name='up'>
	///		�J�����̏����x�N�g��
	///	</param>
	///	<param name='top'>
	///		�߂��̃N���b�v�ʂ̎������̏��[
	///	</param>
	///	<param name='left'>
	///		�߂��̃N���b�v�ʂ̎������̍��[
	///	</param>
	///	<param name='bottom'>
	///		�߂��̃N���b�v�ʂ̎������̉��[
	///	</param>
	///	<param name='right'>
	///		�߂��̃N���b�v�ʂ̎������̉E�[
	///	</param>
	///	<param name='near'>
	///		�߂��̃N���b�v�ʂ̉��s��
	///	</param>
	///	<param name='far'>
	///		�����̃N���b�v�ʂ̉��s��
	///	</param>
	Camera(
		Mode mode,
		Vec3 pos,
		Vec3 dst,
		Vec3 up,
		float top,
		float left,
		float bottom,
		float right,
		float near,
		float far)noexcept;




	///	<summery>
	///		�R���X�g���N�^
	///	</summery>
	///	<param name='mode'>
	///		�J�����̃��[�h
	///	</param>
	///	<param name='pos'>
	///		�J�����̈ʒu
	///	</param>
	///	<param name='dst'>
	///		�J�����̒����_
	///	</param>
	///	<param name='up'>
	///		�J�����̏����x�N�g��
	///	</param>
	///	<param name='width'>
	///		�߂��̃N���b�v�ʂ̎������̕�
	///	</param>
	///	<param name='height'>
	///		�߂��̃N���b�v�ʂ̎������̍���
	///	</param>
	///	<param name='near'>
	///		�߂��̃N���b�v�ʂ̉��s��
	///	</param>
	///	<param name='far'>
	///		�����̃N���b�v�ʂ̉��s��
	///	</param>
	Camera(
		Mode mode,
		Vec3 pos,
		Vec3 dst,
		Vec3 up,
		float width,
		float height,
		float near,
		float far)noexcept;




	///	<summery>
	///		�R���X�g���N�^
	///	</summery>
	///	<param name='pos'>
	///		�J�����̈ʒu
	///	</param>
	///	<param name='dst'>
	///		�J�����̒����_
	///	</param>
	///	<param name='up'>
	///		�J�����̏����x�N�g��
	///	</param>
	///	<param name='fovy'>
	///		�����p
	///	</param>
	///	<param name='aspect'>
	///		�A�X�y�N�g��
	///	</param>
	///	<param name='near'>
	///		�߂��̃N���b�v�ʂ̉��s��
	///	</param>
	///	<param name='far'>
	///		�����̃N���b�v�ʂ̉��s��
	///	</param>
	Camera(
		Vec3 pos,
		Vec3 dst,
		Vec3 up,
		float fovy,
		float aspect,
		float near,
		float far)noexcept;





	///	<summery>
	///		�R���X�g���N�^
	///	</summery>
	///	<param name='c'>
	///		�J����
	///	</param>
	Camera(const Camera &c)noexcept;


public:
	void SetMode(Mode mode)noexcept;
	void SetPos(Vec3 pos)noexcept;
	void SetDst(Vec3 dst)noexcept;
	void SetUp(Vec3 up)noexcept;
	void SetTop(float top)noexcept;
	void SetBottom(float bottom)noexcept;
	void SetLeft(float left)noexcept;
	void SetRight(float right)noexcept;
	void SetNear(float near)noexcept;
	void SetFar(float far)noexcept;
	void SetWidth(float width)noexcept;
	void SetHeight(float height)noexcept;
	void SetNearFar(float near, float far)noexcept;
	void SetRect(float top, float left, float bottom, float right)noexcept;

public:
	Mode  GetMode()const noexcept;
	Vec3 GetPos()const noexcept;
	Vec3 GetDst()const noexcept;
	Vec3 GetUp()const noexcept;
	float GetTop()const noexcept;
	float GetBottom()const noexcept;
	float GetLeft()const noexcept;
	float GetRight()const noexcept;
	float GetNear()const noexcept;
	float GetFar()const noexcept;
	float GetWidth()const noexcept;
	float GetHeight()const noexcept;

private:
	Mode	mode_;
	Vec3	pos_;
	Vec3	dst_;
	Vec3	up_;
	float	top_;
	float	left_;
	float	bottom_;
	float	right_;
	float	near_;
	float	far_;
};



namespace RowMajor {
namespace LH {

Mat4 Projection(Camera c)noexcept;
Mat4 View(Camera c)noexcept;
Mat4 Transform(Camera c)noexcept;

Mat4 operator * (Camera c, Mat4 m)noexcept;
Mat4 operator * (Mat4 m, Camera c)noexcept;
Vec3 operator * (Camera c, Vec3 v)noexcept;

}//namespace LH

namespace RH {

Mat4 Projection(Camera c)noexcept;
Mat4 View(Camera c)noexcept;
Mat4 Transform(Camera c)noexcept;

Mat4 operator * (Camera c, Mat4 m)noexcept;
Mat4 operator * (Mat4 m, Camera c)noexcept;
Vec3 operator * (Camera c, Vec3 v)noexcept;

}// namespace RH
}//namespace RowMajor



namespace ColumnMajor {
namespace LH {

Mat4 Projection(Camera c)noexcept;
Mat4 View(Camera c)noexcept;
Mat4 Transform(Camera c)noexcept;

Mat4 operator * (Camera c, Mat4 m)noexcept;
Mat4 operator * (Mat4 m, Camera c)noexcept;
Vec3 operator * (Vec3 v, Camera c)noexcept;

}//namespace LH

namespace RH {

Mat4 Projection(Camera c)noexcept;
Mat4 View(Camera c)noexcept;
Mat4 Transform(Camera c)noexcept;

Mat4 operator * (Camera c, Mat4 m)noexcept;
Mat4 operator * (Mat4 m, Camera c)noexcept;
Vec3 operator * (Vec3 v, Camera c)noexcept;

} // namespace RH
} // namespace ColumnMajor
} // namespace gdv

#endif
