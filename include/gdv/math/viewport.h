/**
* @file Camera.h
* @brief カメラと行列計算関数の宣言
**/
#ifndef GDV_VIEWPORT_H_
#define GDV_VIEWPORT_H_

#include <type_traits>
#include <gdv/math/matrix4x4.h>
#include <gdv/math/vector2.h>

namespace gdv {

/**
* @class viewport
* @brief ビューポートを表すクラスです
* @details ビューポートの位置とサイズを格納されます
**/
template <class Ty>
class viewport {
    static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

    /**
    * @brief デフォルトコンストラクタ
    * @return none
    * @exception none
    **/
    viewport() noexcept :
        x{}, y{}, w{}, h{} {}



    /**
    * @brief コンストラクタ
    * @param[in] x   x座標
    * @param[in] y   y座標
    * @param[in] w   ビューポートの幅
    * @param[in] h   視錐台の左端
    * @return none
    * @exception none
    **/
    viewport(Ty x, Ty y, Ty w, Ty h) noexcept :
        x{x}, y{y}, w{w}, h{h} {}


    /**
    * @brief コンストラクタ
    * @param[in] pt  中心座標
    * @param[in] w   ビューポートの幅
    * @param[in] h   視錐台の左端
    * @return none
    * @exception none
    **/
    viewport(vector2<Ty> pt, Ty w, Ty h) noexcept :
        x{pt.x}, y{pt.y}, w{w}, h{h} {}


    /**
    * @brief コンストラクタ
    * @param[in] r  rect 
    * @return none
    * @exception none
    **/
    viewport(rect<Ty> r) noexcept :
        x{r.left + r.Width() / static_cast<Ty>(2)},
        y{r.bottom + r.Height() / static_cast<Ty>(2)},
        x{r.Width()},
        x{r.Height()} {}
    


    /**
    * @brief コンストラクタ
    * @param[in] v  ビューポート
    * @return none
    * @exception none
    **/
    viewport(const viewport<Ty> &v) noexcept :
        x{v.x}, y{v.y}, w{v.w}, h{v.h} {} 



    /**
    * @brief コピー代入演算子
    * @param[in] v ビューポート
    * @return 自身の参照
    * @exception none
    **/
    viewport<Ty> operator = (const viewport<Ty> &v) noexcept {
        x = v.x;
        y = v.y;
        w = v.w;
        h = v.h;
        return *this;
    }


public:

    /**
    * @brief ビューポートの左端を取得します
    * @return ビューポートの左端
    * @exception none
    **/
    Ty left()    const noexcept {return x - w / static_cast<Ty>(2);}

    /**
    * @brief ビューポートの右端を取得します
    * @return ビューポートの端
    * @exception none
    **/
    Ty right()   const noexcept {return x + w / static_cast<Ty>(2);}

    /**
    * @brief ビューポートの下端を取得します
    * @return ビューポートの下端
    * @exception none
    **/
    Ty bottom()  const noexcept {return y - h / static_cast<Ty>(2);}

    /**
    * @brief ビューポートの上端を取得します
    * @return ビューポートの上端
    * @exception none
    **/
    Ty top()     const noexcept {return y + h / static_cast<Ty>(2);}



public:
    Ty x;
    Ty y;
    Ty w;
    Ty h;
};


namespace column_major {

template <class Ty>
matrix4x4<Ty> to_matrix(viewport<Ty> v) {
    static constexpr Ty _0 = static_cast<Ty>(0);
    static constexpr Ty _1 = static_cast<Ty>(1);
    static constexpr Ty _2 = static_cast<Ty>(2);
    return {
        v.w / _2, _0, _0, v.x + v.w / _2,
        _0, v.h / _2, _0, v.y + v.h / _2,
        _0, _0, _1, _0,
        _0, _0, _0, _1
    };
}

} // nemspace column_major


namespace row_major {

template <class Ty>
matrix4x4<Ty> to_matrix(viewport<Ty> v) {
    static constexpr Ty _0 = static_cast<Ty>(0);
    static constexpr Ty _1 = static_cast<Ty>(1);
    static constexpr Ty _2 = static_cast<Ty>(2);
    return {
        v.w / _2, _0, _0, _0,
        _0, v.h / _2, _0, _0,
        _0, _0, _1, _0,
        v.x + v.w / _2, v.y + v.h / _2, _0, _1
    };
}

} // namespace row_major

} // namespace gdv

#endif
