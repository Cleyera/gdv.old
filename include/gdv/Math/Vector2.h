//-----------------------------------------------------------------------------
//
//	���W�Ǘ��N���X
//
//-----------------------------------------------------------------------------
#ifndef GDV_VECTOR2_H_
#define GDV_VECTOR2_H_

#include <type_traits>

namespace gdv {

///	<summery>
///		�񎟌��̃x�N�g���������N���X�ł�
///	</summery>
///	<param name='Ty'>
///		�X�J���^
///	</param>
/// <remarks>
///		�e���v���[�g�����̓X�J���^�݂̂��T�|�[�g���Ă��܂�
///	</remarks>
template<class Ty>
class Vector2 {
	//	Vector2�N���X�̓X�J���^�݂̂̃T�|�[�g
	static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

	///	<summery>
	///		�f�t�H���g�R���X�g���N�^
	///	</summery>
	constexpr Vector2() noexcept :
		x{},y{}{}


	///	<summery>
	///		�R���X�g���N�^
	///	</summery>
	///	<param name='x'>
	///		x�x�N�g��
	///	</param>
	///	<param name='y'>
	///		y�x�N�g��
	///	</param>
	constexpr Vector2(Ty x, Ty y) noexcept :
		x{x},y{y}{}


	///	<summery>
	///		�R�s�[�R���X�g���N�^
	///	</summery>
	///	<param name='v'>
	///		Vector2
	///	</param>
	constexpr Vector2(const Vector2<Ty> &v) noexcept :
		x{v.x},y{v.y}{}



	///	<summery>
	///		�������Z�q
	///	</summery>
	Vector2<Ty>& operator = (const Vector2<Ty> &v) noexcept {
		x = v.x;
		y = v.y;
		return *this;
	}



public:
	Ty x;
	Ty y;
};



template<class Ty>
bool operator == (Vector2<Ty> v1, Vector2<Ty> v2) noexcept {
	return v1.x == v2.x && v1.y == v2.y;
}

template<class Ty>
bool operator != (Vector2<Ty> v1, Vector2<Ty> v2) noexcept {
	return v1.x != v2.x || v1.y != v2.y;
}

template<class Ty>
Vector2<Ty>& operator += (Vector2<Ty> &v1, Vector2<Ty> v2) noexcept {
	v1.x += v2.x;
	v1.y += v2.y;
	return v1;
}

template<class Ty>
Vector2<Ty>& operator += (Vector2<Ty> &v, Ty val) noexcept {
	v.x += val;
	v.y += val;
	return v;
}

template<class Ty>
Vector2<Ty>& operator -= (Vector2<Ty> &v1, Vector2<Ty> v2) noexcept {
	v1.x -= v2.x;
	v1.y -= v2.y;
	return v1;
}

template<class Ty>
Vector2<Ty>& operator *= (Vector2<Ty> &v, Ty val) noexcept {
	v.x *= val;
	v.y *= val;
	return v;
}

template<class Ty>
Vector2<Ty>& operator /= (Vector2<Ty> &v, Ty val) noexcept {
	v.x /= val;
	v.y /= val;
	return v;
}

template<class Ty>
Vector2<Ty>& operator -= (Vector2<Ty> &v, Ty val) noexcept {
	v.x -= val;
	v.y -= val;
	return v;
}

template<class Ty>
Vector2<Ty> operator + (Vector2<Ty> v1, Vector2<Ty> v2) noexcept {
	return {v1.x + v2.x, v1.y + v2.y};
}

template<class Ty>
Vector2<Ty> operator + (Vector2<Ty> v, Ty val) noexcept {
	return {v.x + val, v.y + val};
}

template<class Ty>
Vector2<Ty> operator - (Vector2<Ty> v1, Vector2<Ty> v2) noexcept {
	return {v1.x - v2.x, v1.y - v2.y};
}

template<class Ty>
Vector2<Ty> operator - (Vector2<Ty> v, Ty val) noexcept {
	return {v.x - val, v.y - val};
}

template<class Ty>
Vector2<Ty> operator * (Vector2<Ty> v, Ty val) noexcept {
	return {v.x * val, v.y * val};
}

template<class Ty>
Vector2<Ty> operator / (Vector2<Ty> v, Ty val) noexcept {
	return {v.x / val, v.y / val};
}




///	<summery>
///		�񎟌��x�N�g���̓��ς��v�Z���܂�
///	</summery>
///	<param name='v1'>
///		�x�N�g��1
///	</param>
///	<param name='v2'>
///		�x�N�g��2
///	</param>
///	</summary>
///	<returns>
///		���ς̒l
/// </returns>
template<class Ty>
Ty Dot(Vector2<Ty> v1, Vector2<Ty> v2) noexcept {
	static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
	return v1.x * v2.x + v1.y * v2.y;
}


///	<summery>
///		�񎟌��x�N�g���̊O�ς̑傫�����v�Z���܂�
///	</summery>
///	<param name='v1'>
///		�x�N�g��1
///	</param>
///	<param name='v2'>
///		�x�N�g��2
///	</param>
///	</summary>
///	<returns>
///		�O�ς̑傫��
/// </returns>
template<class Ty>
Ty Cross(Vector2<Ty> v1, Vector2<Ty> v2) noexcept {
	static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
	return v1.x * v2.y - v1.y * v2.x;
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
Ty Angle(Vector2<Ty> v1, Vector2<Ty> v2) noexcept {
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
Ty Length(Vector2<Ty> v) noexcept {
	static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
	return static_cast<Ty>(hypot(v.x, v.y));
}



///	<summery>
///		�x�N�g���̐��K�����s���܂�
///	</summery>
///	<param name='v'>
///		�x�N�g��
///	</param>
/// <remarks>
///		���������_�^�̃x�N�g���̂݃T�|�[�g���Ă��܂�
///	</remarks>
///	</summary>
///	<returns>
///		���K�����ꂽ�x�N�g��
/// </returns>
template<class Ty>
Vector2<Ty> Normalize(Vector2<Ty> v) noexcept {
	return (v / Length(v));
}




///	<summery>
///		�x�N�g�������]���܂�
///	</summery>
///	<param name='v'>
///		�x�N�g��
///	</param>
///	<param name='center'>
///		���]�̒��S
///	</param>
///	<param name='angle'>
///		���]�����p�x
///	</param>
/// <remarks>
///		���������_�^�̃x�N�g���̂݃T�|�[�g���Ă��܂�
///	</remarks>
///	</summary>
///	<returns>
///		���]���̃x�N�g��
/// </returns>
template<class Ty>
Vector2<Ty> Rotation(Vector2<Ty> v, Vector2<Ty> center, Ty angle) noexcept {
	static_assert(std::is_floating_point<Ty>::value, "Template parameters require floating point type.");
	const float s = sin(angle);
	const float c = cos(angle);
	const float x = v.x - center.x;
	const float y = v.y - center.y;
	return {
		x * c + y * s + center.x,
		y * c - x * s + center.y
	};
}




//�G�C���A�X�̒��`
using Point = Vector2<int>;
using Vec2	= Vector2<float>;

} // namespace gdv

#endif
