#ifndef GDV_EULER_H_
#define GDV_EULER_H_


#include <type_traits>


namespace gdv {


///	<summery>
///		�I�C���[�p�������N���X�ł�
///	</summery>
///	<param name='Ty'>
///		�X�J���^
///	</param>
/// <remarks>
///		�e���v���[�g�����̓X�J���^�݂̂��T�|�[�g���Ă��܂�
///	</remarks>
template<class Ty>
class Euler{
	//	Euler�N���X�̓X�J���^�݂̂̃T�|�[�g
	static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:
	///	<summery>
	///		�f�t�H���g�R���X�g���N�^
	///	</summery>
	constexpr Euler() noexcept :
		x{},y{},z{}{}



	///	<summery>
	///		�R���X�g���N�^
	///	</summery>
	///	<param name='x'>
	///		roll
	///	</param>
	///	<param name='y'>
	///		pitch
	///	</param>
	///	<param name='z'>
	///		yaw
	///	</param>
	constexpr Euler(Ty x, Ty y, Ty z) noexcept :
		x{x},y{y},z{z}{}


	///	<summery>
	///		�R���X�g���N�^
	///	</summery>
	///	<param name='x'>
	///		roll
	///	</param>
	///	<param name='y'>
	///		pitch
	///	</param>
	///	<param name='z'>
	///		yaw
	///	</param>
	constexpr Euler(const Euler<Ty> &e) noexcept :
		x{e.x},y{e.y},z{e.z}{}


	///	<summery>
	///		�������Z�q
	///	</summery>
	Euler<Ty>& operator = (const Euler<Ty> &e) noexcept = default;

public:
	Ty x;
	Ty y;
	Ty z;
};

} // namespace gdv

#endif
