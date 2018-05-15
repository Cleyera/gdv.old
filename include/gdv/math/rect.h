#ifndef GDV_RECT_H_
#define GDV_RECT_H_


#include <type_traits>

namespace gdv {

template <class Ty>
class rect {
    static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

    constexpr rect() noexcept :
        top{},left{},bottom{},right{}{}


    constexpr rect(Ty top, Ty left, Ty bottom, Ty right) noexcept :
        top{top},left{left},bottom{bottom},right{right}{}


    constexpr rect(const rect<Ty> &r) noexcept :
        top{r.top},left{r.left},bottom{r.bottom},right{r.right}{}




    rect<Ty>& operator = (const rect<Ty> &r) noexcept {
        top     = r.top;
        left    = r.left;
        bottom  = r.bottom;
        right   = r.right;
        return *this;
    }


public:
    Ty width() const noexcept {return right - left;}
    Ty height() const noexcept {return bottom - top;}


public:
    Ty top;
    Ty left;
    Ty bottom;
    Ty right;
};

} // namespace gdv

#endif
