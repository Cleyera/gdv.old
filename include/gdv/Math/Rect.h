//-----------------------------------------------------------------------------
//
//	���`�N���X
//
//-----------------------------------------------------------------------------
#ifndef GDV_RECT_H_
#define GDV_RECT_H_


#include <type_traits>

namespace gdv {

template<class Ty>
class Rect {
	//	Rect�N���X�̓X�J���^�݂̂̃T�|�[�g
	static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

	constexpr Rect() noexcept :
		top{},left{},bottom{},right{}{}


	constexpr Rect(Ty top, Ty left, Ty bottom, Ty right) noexcept :
		top{top},left{left},bottom{bottom},right{right}{}


	constexpr Rect(const Rect<Ty> &r) noexcept :
		top{r.top},left{r.left},bottom{r.bottom},right{r.right}{}




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
