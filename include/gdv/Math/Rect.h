//-----------------------------------------------------------------------------
//
//	���`�N���X
//
//-----------------------------------------------------------------------------
#ifndef GDV_RECT_H_
#define GDV_RECT_H_


#include <type_traits>

namespace gdv {

///	<summery>
///		���`�������N���X�ł�
///	</summery>
///	<param name='Ty'>
///		�X�J���^
///	</param>
/// <remarks>
///		�e���v���[�g�����̓X�J���^�݂̂��T�|�[�g���Ă��܂�
///	</remarks>
template<class Ty>
class Rect {
	//	Rect�N���X�̓X�J���^�݂̂̃T�|�[�g
	static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

	///	<summery>
	///		�f�t�H���g�R���X�g���N�^
	///	</summery>
	constexpr Rect() noexcept :
		top{},left{},bottom{},right{}{}


	///	<summery>
	///		�R���X�g���N�^
	///	</summery>
	///	<param name='x'>
	///		x�x�N�g��
	///	</param>
	///	<param name='y'>
	///		y�x�N�g��
	///	</param>
	constexpr Rect(Ty top, Ty left, Ty bottom, Ty right) noexcept :
		top{top},left{left},bottom{bottom},right{right}{}


	///	<summery>
	///		�R�s�[�R���X�g���N�^
	///	</summery>
	///	<param name='v'>
	///		Vector2D
	///	</param>
	constexpr Rect(const Rect<Ty> &r) noexcept :
		top{r.top},left{r.left},bottom{r.bottom},right{r.right}{}



	///	<summery>
	///		�������Z�q
	///	</summery>
	Rect<Ty>& operator = (const Rect<Ty> &r) noexcept {
		top		= r.top;
		left	= r.left;
		bottom	= r.bottom;
		right	= r.right;
		return *this;
	}


public:
	Ty Width() const noexcept {return right - left;}
	Ty Height() const noexcept {return bottom - top;}


public:
	Ty top;
	Ty left;
	Ty bottom;
	Ty right;
};

} // namespace gdv

#endif
