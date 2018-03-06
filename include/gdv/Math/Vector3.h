//-----------------------------------------------------------------------------
//
//	���W�Ǘ��N���X
//
//-----------------------------------------------------------------------------
#ifndef GDV_VECTOR3_H_
#define GDV_VECTOR3_H_

#include <type_traits>
#include "gdv/Math/Vector2.h"

namespace gdv {

///	<summery>
///		�O�����̃x�N�g���������N���X�ł�
///	</summery>
///	<param name='Ty'>
///		�X�J���^
///	</param>
/// <remarks>
///		�e���v���[�g�����̓X�J���^�݂̂��T�|�[�g���Ă��܂�
///	</remarks>
template<class Ty>
class alignas(alignof(Ty)) Vector3 {
	//	Vector3�N���X�̓X�J���^�݂̂̃T�|�[�g
	static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

	///	<summery>
	///		�f�t�H���g�R���X�g���N�^
	///	</summery>
	constexpr Vector3() noexcept :
		x{},y{},z{}{}


	///	<summery>
	///		�R���X�g���N�^
	///	</summery>
	///	<param name='x'>
	///		x�x�N�g��
	///	</param>
	///	<param name='y'>
	///		y�x�N�g��
	///	</param>
	///	<param name='z'>
	///		z�x�N�g��
	///	</param>
	constexpr Vector3(Ty x, Ty y, Ty z) noexcept :
		x{x},y{y},z{z}{}


	///	<summery>
	///		�R�s�[�R���X�g���N�^
	///	</summery>
	///	<param name='v'>
	///		Vector3
	///	</param>
	constexpr Vector3(const Vector3<Ty> &v) noexcept :
		x{v.x},y{v.y},z{v.z}{}


	///	<summery>
	///		�R�s�[�R���X�g���N�^
	///	</summery>
	///	<param name='v'>
	///		Vector2D
	///	</param>
	constexpr Vector3(const Vector2<Ty> &v) noexcept :
		x{v.x},y{v.y},z{1.0}{}



	///	<summery>
	///		�������Z�q
	///	</summery>
	Vector3<Ty>& operator = (const Vector3<Ty> &v) noexcept {
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}


	///	<summery>
	///		�L���X�g���Z�q
	///	</summery>
	operator Vector2<Ty>() const noexcept {return {x, y};}


public:
	Ty x;
	Ty y;
	Ty z;
};



template<class Ty>
bool operator == (Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}

template<class Ty>
bool operator != (Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	return v1.x != v2.x || v1.y != v2.y || v1.z != v2.z;
}

template<class Ty>
Vector3<Ty>& operator += (Vector3<Ty> &v1, Vector3<Ty> v2) noexcept {
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return v1;
}

template<class Ty>
Vector3<Ty>& operator += (Vector3<Ty> &pt, Ty val) noexcept {
	pt.x += val;
	pt.y += val;
	pt.z += val;
	return pt;
}

template<class Ty>
Vector3<Ty>& operator -= (Vector3<Ty> &v1, Vector3<Ty> v2) noexcept {
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return v1;
}

template<class Ty>
Vector3<Ty>& operator -= (Vector3<Ty> &pt, Ty val) noexcept {
	pt.x -= val;
	pt.y -= val;
	pt.z -= val;
	return pt;
}

template<class Ty>
Vector3<Ty>& operator *= (Vector3<Ty> &pt, Ty val) noexcept {
	pt.x *= val;
	pt.y *= val;
	pt.z *= val;
	return pt;
}

template<class Ty>
Vector3<Ty>& operator /= (Vector3<Ty> &pt, Ty val) noexcept {
	pt.x /= val;
	pt.y /= val;
	pt.z /= val;
	return pt;
}

template<class Ty>
Vector3<Ty> operator + (Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

template<class Ty>
Vector3<Ty> operator + (Vector3<Ty> pt, Ty val) noexcept {
	return {pt.x + val, pt.y + val, pt.z + val};
}

template<class Ty>
Vector3<Ty> operator - (Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

template<class Ty>
Vector3<Ty> operator - (Vector3<Ty> pt, Ty val) noexcept {
	return {pt.x - val, pt.y - val, pt.z - val};
}

template<class Ty>
Vector3<Ty> operator * (Vector3<Ty> pt, Ty val) noexcept {
	return {pt.x * val, pt.y * val, pt.z * val};
}
template<class Ty>
Vector3<Ty> operator / (Vector3<Ty> pt, Ty val) noexcept {
	return {pt.x / val, pt.y / val, pt.z / val};
}



///	<summery>
///		�O�����x�N�g���̓��ς��v�Z���܂�
///	</summery>
///	<param name='v1'>
///		�x�N�g��1
///	</param>
///	<param name='v2'>
///		�x�N�g��2
///	</param>
///	<returns>
///		���ς̒l
/// </returns>
template<class Ty>
Ty Dot(Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}


///	<summery>
///		�O�����x�N�g���̊O�ς��v�Z���܂�
///	</summery>
///	<param name='v1'>
///		�x�N�g��1
///	</param>
///	<param name='v2'>
///		�x�N�g��2
///	</param>
///	<returns>
///		�O�ς̃x�N�g��
/// </returns>
template<class Ty>
Vector3<Ty> Cross(Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
	return {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x};
}



///	<summery>
///		�Q�̃x�N�g���̂Ȃ��p���v�Z���܂�
///	</summery>
/// <remarks>
///		���������_�^�̃x�N�g���݂̂��T�|�[�g���Ă��܂�
///	</remarks>
///	<param name='v1'>
///		�x�N�g��1
///	</param>
///	<param name='v2'>
///		�x�N�g��2
///	</param>
///	<returns>
///		�Q�̃x�N�g���̂Ȃ��p
/// </returns>
template<class Ty>
Ty Angle(Vector3<Ty> v1, Vector3<Ty> v2) noexcept {
	return static_cast<Ty>(atan2(Dot(v1, v2), Cross(v1, v2)));
}



///	<summery>
///		�x�N�g���̑傫�����Ԃ��܂�
///	</summery>
///	<param name='v'>
///		�x�N�g��
///	</param>
///	<returns>
///		�x�N�g���̑傫��
/// </returns>
template<class Ty>
Ty Length(Vector3<Ty> v) noexcept {
	static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
	return static_cast<Ty>(hypot(hypot(v.x, v.y), v.z));
}



///	<summery>
///		�x�N�g���̐��K�����s���܂�
///	</summery>
/// <remarks>
///		���������_�^�̃x�N�g���̂݃T�|�[�g���Ă��܂�
///	</remarks>
///	<param name='v'>
///		�x�N�g��
///	</param>
///	<returns>
///		���K�����ꂽ�x�N�g��
/// </returns>
template<class Ty>
Vector3<Ty> Normalize(Vector3<Ty> v) noexcept {
	return (v / Length(v));
}



//�G�C���A�X�̒��`
using Point3	= Vector3<int>;
using Vec3		= Vector3<float>;

} // namespace gdv

#endif
