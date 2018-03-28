#ifndef GDV_MATH3D_H_
#define GDV_MATH3D_H_


#include "gdv/Math/Vector4.h"
#include "gdv/Math/Matrix4x4.h"
#include "gdv/Math/Matrix3x3.h"


namespace gdv {


/**
* @brief 単位行列を作成します
* @tparam Ty スカラ型のみ受付ます
* @return Mat4
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> UnitMatrix() noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    return {
        _1, _0, _0, _0,
        _0, _1, _0, _0,
        _0, _0, _1, _0,
        _0, _0, _0, _1,
    };
}



/**
* @brief 行列を転地します
* @tparam Ty スカラ型のみ受付ます
* @param[in] m 転地する行列
* @return Mat3
* @exception none
**/
template <class Ty>
Matrix3x3<Ty> Transpose(Matrix3x3<Ty> m) noexcept {
    return {
        m.m[0], m.m[3], m.m[6],
        m.m[1], m.m[4], m.m[7],
        m.m[2], m.m[5], m.m[8]
    };
}



/**
* @brief 行列を転地します
* @tparam Ty スカラ型のみ受付ます
* @param[in] m 転地する行列
* @return Mat4
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> Transpose(Matrix4x4<Ty> m) noexcept {
    return {
        m.m[0], m.m[4], m.m[ 8], m.m[12],
        m.m[1], m.m[5], m.m[ 9], m.m[13],
        m.m[2], m.m[6], m.m[10], m.m[14],
        m.m[3], m.m[7], m.m[11], m.m[15]
    };
}




namespace ColumnMajor {



/**
* @brief スケーリング行列を作成します
* @tparam Ty スカラ型のみ受付ます
* @param[in] x x軸方向の拡大率
* @param[in] y y軸方向の拡大率
* @param[in] z z軸方向の拡大率
* @return Matrix4x4<Ty>
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> Scaling(Ty x, Ty y, Ty z) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    return {
         x, _0, _0, _0,
        _0,  y, _0, _0,
        _0, _0,  z, _0,
        _0, _0, _0, _1
    };
}


/**
* @brief スケーリング行列を作成します
* @tparam Ty スカラ型のみ受付ます
* @param[in] v 拡大率
* @return Matrix4x4<Ty>
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> Scaling(Vector3<Ty> v) noexcept {
    return Scaling(v.x, v.y, v.z);
}



/**
* @brief 移動行列を作成します
* @param[in] x x軸方向の移動量
* @param[in] y y軸方向の移動量
* @param[in] z z軸方向の移動量
* @return Mat4
* @exception none
**/
Mat4 Translation(float x, float y, float z) noexcept;




/**
* @brief x軸に関する回転行列を作成します
* @param[in] radians 回転角(ラジアン)
* @return Mat4
* @exception none
**/
Mat4 RotationX(float radians) noexcept;



/**
* @brief y軸に関する回転行列を作成します
* @param[in] radians 回転角(ラジアン)
* @return Mat4
* @exception none
**/
Mat4 RotationY(float radians) noexcept;



/**
* @brief z軸に関する回転行列を作成します
* @param[in] radians 回転角(ラジアン)
* @return Mat4
* @exception none
**/
Mat4 RotationZ(float radians) noexcept;


/**
* @brief 任意軸に関する回転行列を作成します
* @param[in] axis       回転軸
* @param[in] radians    回転角(ラジアン)
* @return Mat4
* @exception none
**/
Mat4 Rotation(Vec3 axis, float angle) noexcept;





namespace RH {


/**
* @brief ビュー行列を作成します
* @param[in] pos    カメラの位置
* @param[in] dst    注視点
* @param[in] up     カメラの上方ベクトル
* @return Mat4
* @exception none
**/
Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept;



/**
* @brief 平行投影行列を作成します
* @param[in] left   視錐台の左端
* @param[in] right  視錐台の右端
* @param[in] bottom 視錐台の下端
* @param[in] top    視錐台の上端
* @param[in] near   近くのクリップ面の奥行き
* @param[in] far    遠くのクリップ面の奥行き
* @return Mat4
* @exception none
**/
Mat4 Orthogonal(float left, float right, float bottom, float top, float near, float far) noexcept;


/**
* @brief 平行投影行列を作成します
* @param[in] width  視錐台の幅
* @param[in] height 視錐台の高さ
* @param[in] near   近くのクリップ面の奥行き
* @param[in] far    遠くのクリップ面の奥行き
* @return Mat4
* @exception none
**/
Mat4 Orthogonal(float width, float height, float near, float far) noexcept;




/**
* @brief 透視投影行列を作成します
* @param[in] left   視錐台の左端
* @param[in] right  視錐台の右端
* @param[in] bottom 視錐台の下端
* @param[in] top    視錐台の上端
* @param[in] near   近くのクリップ面の奥行き
* @param[in] far    遠くのクリップ面の奥行き
* @return Mat4
* @exception none
**/
Mat4 Perspective(float left, float right, float bottom, float top, float near, float far) noexcept;


/**
* @brief 透視投影行列を作成します
* @param[in] width  視錐台の幅
* @param[in] height 視錐台の高さ
* @param[in] near   近くのクリップ面の奥行き
* @param[in] far    遠くのクリップ面の奥行き
* @return Mat4
* @exception none
**/
Mat4 Perspective(float width, float height, float near, float far) noexcept;


/**
* @brief 平行投影行列を作成します
* @param[in] fovy   視錐台の幅
* @param[in] aspect アスペクト比
* @param[in] near   近くのクリップ面の奥行き
* @param[in] far    遠くのクリップ面の奥行き
* @return Mat4
* @exception none
**/
Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept;

} // namespace RH





namespace LH {


Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept;


Mat4 Orthogonal(float left, float right, float bottom, float top, float near, float far) noexcept;


Mat4 Orthogonal(float width, float height, float near, float far) noexcept;


Mat4 Perspective(float left, float right, float bottom, float top, float near, float far) noexcept;


Mat4 Perspective(float width, float height, float near, float far) noexcept;


Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept;

} // namespace LH
} // namespace ColumnMajor






namespace RowMajor {


template <class Ty>
Matrix4x4<Ty> Scaling(Ty x, Ty y, Ty z) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    return {
         x, _0, _0, _0,
        _0,  y, _0, _0,
        _0, _0,  z, _0,
        _0, _0, _0, _1
    };
}


template <class Ty>
Matrix4x4<Ty> Scaling(Vector3<Ty> v) noexcept {
    return Scaling(v.x, v.y, v.z);
}


Mat4 Translation(float x, float y, float z) noexcept;


Mat4 RotationX(float radians) noexcept;


Mat4 RotationY(float radians) noexcept;


Mat4 RotationZ(float radians) noexcept;


Mat4 Rotation(Vec3 axis, float angle) noexcept;




namespace RH {


Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept;


Mat4 Orthogonal(float left, float right, float bottom, float top, float near, float far) noexcept;


Mat4 Orthogonal(float width, float height, float near, float far) noexcept;


Mat4 Perspective(float left, float right, float bottom, float top, float near, float far) noexcept;


Mat4 Perspective(float width, float height, float near, float far) noexcept;


Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept;

} // namespace RH




namespace LH {


Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept;


Mat4 Orthogonal(float left, float right, float bottom, float top, float near, float far) noexcept;


Mat4 Orthogonal(float width, float height, float near, float far) noexcept;


Mat4 Perspective(float left, float right, float bottom, float top, float near, float far) noexcept;


Mat4 Perspective(float width, float height, float near, float far) noexcept;


Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept;

} // namespace RowMajor
} // namespace LH
} // namespace gdv

#endif
