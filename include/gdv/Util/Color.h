#ifndef GDV_COLOR_H_
#define GDV_COLOR_H_

#include <algorithm>
#include <math.h>
#include "gdv/Common/Types.h"
#include "Tween.h"


namespace gdv {


struct HSV;


///	<summary>
///		RGB(A)�F���Ǘ������\����
///	</summary>
struct RGB {

	///	<summary>
	///		�f�t�H���g�R���X�g���N�^
	///	</summary>
	constexpr RGB() noexcept :
		a{1.0f}, r{0.0f}, g{0.0f}, b{0.0f}{}


	///	<summary>
	///		�R���X�g���N�^
	///	</summary>
	///	<param name='r'>
	///		��
	/// </param>
	///	<param name='g'>
	///		��
	/// </param>
	///	<param name='b'>
	///		��
	/// </param>
	constexpr RGB(float r, float g, float b) noexcept :
		a{1.0f}, r{r}, g{g}, b{b}{}


	///	<summary>
	///		�R���X�g���N�^
	///	</summary>
	///	<param name='a'>
	///		����
	/// </param>
	///	<param name='r'>
	///		��
	/// </param>
	///	<param name='g'>
	///		��
	/// </param>
	///	<param name='b'>
	///		��
	/// </param>
	constexpr RGB(float a, float r, float g, float b) noexcept :
		a{a}, r{r}, g{g}, b{b}{}


	///	<summary>
	///		�R���X�g���N�^
	///	</summary>
	///	<param name='c'>
	///		ARGB�J���[
	/// </param>
	constexpr RGB(uint32 c) noexcept :
		a{((c & 0xff000000) >> 24) / 255.0f},
		r{((c & 0x00ff0000) >> 16) / 255.0f},
		g{((c & 0x0000ff00) >>  8) / 255.0f},
		b{((c & 0x000000ff))       / 255.0f}{}


	///	<summary>
	///		�R���X�g���N�^
	///	</summary>
	///	<param name='c'>
	///		HSV�J���[
	/// </param>
	RGB(HSV c)noexcept;


	///	<summary>
	///		�R�s�[�R���X�g���N�^
	///	</summary>
	///	<param name='co'>
	///		RGB
	/// </param>
	constexpr RGB(const RGB &co) noexcept :
		a{co.a}, r{co.r}, g{co.g}, b{co.b}{}



	///	<summary>
	///		�������Z�q
	///	</summary>
	///	<param name='c'>
	///		RGB�\����
	/// </param>
	RGB& operator = (RGB c){
		a = c.a;
		r = c.r;
		g = c.g;
		b = c.b;
		return *this;
	}



	float a, r, g, b;
};




///	<summary>
///		HSV(A)�F���Ǘ������\����
///	</summary>
struct HSV {

	///	<summary>
	///		�f�t�H���g�R���X�g���N�^
	///	</summary>
	constexpr HSV() noexcept :
		a{1.0f}, h{0.0f}, s{0.0f}, v{0.0f}{}



	///	<summary>
	///		�R���X�g���N�^
	///	</summary>
	///	<param name='a'>
	///		����
	/// </param>
	///	<param name='h'>
	///		�F��
	/// </param>
	///	<param name='s'>
	///		�ʓx
	/// </param>
	///	<param name='v'>
	///		���x
	/// </param>
	constexpr HSV(float h, float s, float v) noexcept :
		a{1.0f}, h{h}, s{s}, v{v}{}



	///	<summary>
	///		�R���X�g���N�^
	///	</summary>
	///	<param name='h'>
	///		�F��
	/// </param>
	///	<param name='s'>
	///		�ʓx
	/// </param>
	///	<param name='v'>
	///		���x
	/// </param>
	constexpr HSV(float a, float h, float s, float v) noexcept :
		a{a}, h{h}, s{s}, v{v}{}



	///	<summary>
	///		�R�s�[�R���X�g���N�^
	///	</summary>
	///	<param name='co'>
	///		HSV
	/// </param>
	constexpr HSV(const HSV &c) noexcept :
		a{c.a}, h{c.h}, s{c.s}, v{c.v}{}



	///	<summary>
	///		�R�s�[�R���X�g���N�^
	///	</summary>
	///	<param name='co'>
	///		RGB
	/// </param>
	HSV(RGB c)noexcept;



	///	<summary>
	///		�������Z�q
	///	</summary>
	///	<param name='c'>
	///		HSV�\����
	/// </param>
	HSV& operator = (const HSV &c) {
		a = c.a;
		h = c.h;
		s = c.s;
		v = c.v;
		return *this;
	}


	float a, h, s, v;
};






RGB operator + (const RGB &co1, const RGB &co2)noexcept;
RGB operator - (const RGB &co1, const RGB &co2)noexcept;
RGB operator * (const RGB &co1, const RGB &co2)noexcept;
RGB& operator += (RGB &co1, const RGB &co2)noexcept;
RGB& operator -= (RGB &co1, const RGB &co2)noexcept;
RGB& operator *= (RGB &co1, const RGB &co2)noexcept;


HSV ToHSV(RGB c)noexcept;
RGB ToRGB(HSV c)noexcept;


using Color = RGB;

} // namespace gdv

#endif
