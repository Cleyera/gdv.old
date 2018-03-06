//-----------------------------------------------------------------------------
//
//	���W�Ǘ��N���X
//
//-----------------------------------------------------------------------------
#ifndef GDV_VECTOR4_H_
#define GDV_VECTOR4_H_

#include <type_traits>
#include "gdv/Math/Vector3.h"

namespace gdv {

///	<summery>
///		x, y, z, w ��3D�x�N�g���������Ƃ��Ɏg�p�����N���X
///	</summery>
///	<param name='Ty'>
///		�X�J���^
///	</param>
/// <remarks>
///		�e���v���[�g�����̓X�J���^�݂̂��T�|�[�g���Ă��܂�
///	</remarks>
template<class Ty>
class alignas(alignof(Ty)) Vector4 {
	static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

	///	<summery>
	///		�f�t�H���g�R���X�g���N�^
	///	</summery>
	constexpr Vector4() noexcept :
		x{}, y{}, z{}, w{}{}


	///	<summery>
	///		�R���X�g���N�^
	///	</summery>
	///	<param name='x'>
	///		x�x�N�g��
	///	</param>
	///	<param name='y'>
	///		y�x�N�g��
	///	</param>
	constexpr Vector4(Ty x, Ty y, Ty z) noexcept :
		x{x}, y{y}, z{z}, w{static_cast<Ty>(1)}{}


	///	<summery>
	///		�R���X�g���N�^
	///	</summery>
	///	<param name='x'>
	///		x�x�N�g��
	///	</param>
	///	<param name='y'>
	///		y�x�N�g��
	///	</param>
	constexpr Vector4(Ty x, Ty y, Ty z, Ty w) noexcept :
		x{x}, y{y}, z{z}, w{w}{}


	///	<summery>
	///		�R�s�[�R���X�g���N�^
	///	</summery>
	///	<param name='v'>
	///		Vector4
	///	</param>
	constexpr Vector4(const Vector4<Ty> &v) noexcept :
		x{v.x}, y{v.y}, z{v.z}, w{v.w}{}


	///	<summery>
	///		�R�s�[�R���X�g���N�^
	///	</summery>
	///	<param name='v'>
	///		Vector3D
	///	</param>
	constexpr Vector4(const Vector3<Ty> &v) noexcept :
		x{v.x}, y{v.y}, z{v.z}, w{static_cast<Ty>(1)}{}


	///	<summery>
	///		�R�s�[�R���X�g���N�^
	///	</summery>
	///	<param name='v'>
	///		Vector3D
	///	</param>
	/// <param name="w">
	///		w
	/// </param>
	constexpr Vector4(const Vector3<Ty> &v, Ty w) noexcept :
		x{v.x}, y{v.y}, z{v.z}, w{w}{}





	///	<summery>
	///		�������Z�q
	///	</summery>
	Vector4<Ty>& operator = (const Vector4<Ty> &v) noexcept {
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
		return *this;
	}


	///	<summery>
	///		�������Z�q
	///	</summery>
	Vector4<Ty>& operator = (const Vector3<Ty> &v) noexcept {
		x = v.x;
		y = v.y;
		z = v.z;
		w = static_cast<Ty>(1);
		return *this;
	}


	operator Vector3<Ty>() const noexcept {return {x, y, z};}

public:
	Ty x;
	Ty y;
	Ty z;
	Ty w;
};


//�G�C���A�X�̒��`
using Vec4 = Vector4<float>;

} // namespace gdv

#endif
