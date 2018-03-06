#ifndef GDV_EULER_H_
#define GDV_EULER_H_

#include <type_traits>


namespace gdv {

template<class Ty>
class Euler {
	static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:
	///	<summery>
	///		default constructor
	///	</summery>
	constexpr Euler() noexcept :
		x{},y{},z{}{}



	///	<summery>
	///		constructor
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
	///		constructor
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
	///		assignment operator
	///	</summery>
	Euler<Ty>& operator = (const Euler<Ty> &e) noexcept = default;

public:
	Ty x;
	Ty y;
	Ty z;
};

} // namespace gdv

#endif
