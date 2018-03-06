#ifndef GDV_VIEWPORT_H_
#define GDV_VIEWPORT_H_

#include <type_traits>

namespace gdv {

///	<summery>
///		�r���[�|�[�g�������N���X�ł�
///	</summery>
///	<param name='Ty'>
///		�X�J���^
///	</param>
/// <remarks>
///		�e���v���[�g�����̓X�J���^�݂̂��T�|�[�g���Ă��܂�
///	</remarks>
template<class Ty>
class Viewport {
	//	Viewport�N���X�̓X�J���^�݂̂̃T�|�[�g
	static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:
	Viewport() noexcept :
		x{}, y{}, w{}, h{} {}

	Viewport(Ty x, Ty y, Ty w, Ty h) noexcept :
		x{x}, y{y}, w{w}, h{h} {}

public:
	Ty x;
	Ty y;
	Ty w;
	Ty h;
};

} // namespace gdv

#endif
