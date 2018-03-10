/**
* @file Euler.h
* @brief オイラー角を表現するクラスを定義したファイルです
**/
#ifndef GDV_EULER_H_
#define GDV_EULER_H_

#include <type_traits>


namespace gdv {

/**
* @class Euler
* @brief オイラー角を表現するクラスです
* このクラスはQuaternionと相互に変換する事ができます
* @tparam Ty スカラ型のみ受付ます
**/
template <class Ty>
class Euler {
    static_assert(std::is_integral<Ty>::value || std::is_floating_point<Ty>::value, "invalid template parameter.");

public:

    /**
    * @brief デフォルトコンストラクタ
    * @return none
  * @exception none
    **/
    constexpr Euler() noexcept :
        x{}, y{}, z{} {}



    /**
    * @brief コンストラクタ
    * @param[in] x x軸に関する回転角
    * @param[in] y y軸に関する回転角
    * @param[in] z z軸に関する回転角
    * @return none
    * @exception none
    **/
    constexpr Euler(Ty x, Ty y, Ty z) noexcept :
        x{x}, y{y}, z{z} {}


    /**
    * @brief コピーコンストラクタ
    * @param[in] e オイラー角
    * @return none
    * @exception none
    **/
    constexpr Euler(const Euler<Ty> &e) noexcept :
        x{e.x}, y{e.y}, z{e.z} {}


    /**
    * @brief コピー代入演算子
    * @param[in] e オイラー角
    * @return 自身の参照
    * @exception none
    **/
    Euler<Ty>& operator = (const Euler<Ty> &e) noexcept = default;

public:
    Ty x; //! pitch
    Ty y; //! yaw
    Ty z; //! roll
};

} // namespace gdv

#endif
