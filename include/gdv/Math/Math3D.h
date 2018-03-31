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
* @tparam Ty スカラ型のみ受付ます
* @param[in] x x軸方向の移動量
* @param[in] y y軸方向の移動量
* @param[in] z z軸方向の移動量
* @return Matrix4x4<Ty>
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> Translation(Ty x, Ty y, Ty z) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    return {
        _1, _0, _0,  x,
        _0, _1, _0,  y,
        _0, _0, _1,  z,
        _0, _0, _0, _1
    };
}



/**
* @brief 移動行列を作成します
* @tparam Ty スカラ型のみ受付ます
* @param[in] v 移動量
* @return Matrix4x4<Ty>
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> Translation(Vector3<Ty> v) noexcept {
    return Translation(v.x, v.y, v.z);
}



/**
* @brief x軸に関する回転行列を作成します
* @tparam Ty スカラ型のみ受付ます
* @param[in] radians 回転角(ラジアン)
* @return Mat4
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> RotationX(Ty radians) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Ty s = std::sin(radians);
    Ty c = std::cos(radians);
    return {
        _1, _0, _0, _0,
        _0,  c, -s, _0,
        _0,  s,  c, _0,
        _0, _0, _0, _1
    };
}



/**
* @brief y軸に関する回転行列を作成します
* @tparam Ty スカラ型のみ受付ます
* @param[in] radians 回転角(ラジアン)
* @return Mat4
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> RotationY(Ty radians) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Ty s = std::sin(radians);
    Ty c = std::cos(radians);
    return {
         c, _0,  s, _0,
        _0, _1, _0, _0,
        -s, _0,  c, _0,
        _0, _0, _0, _1
    };
}



/**
* @brief z軸に関する回転行列を作成します
* @tparam Ty スカラ型のみ受付ます
* @param[in] radians 回転角(ラジアン)
* @return Mat4
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> RotationZ(Ty radians) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Ty s = std::sin(radians);
    Ty c = std::cos(radians);
    return {
         c, -s, _0, _0,
         s,  c, _0, _0,
        _0, _0, _1, _0,
        _0, _0, _0, _1
    };
}




/**
* @brief 任意軸に関する回転行列を作成します
* @tparam Ty スカラ型のみ受付ます
* @param[in] axis       回転軸
* @param[in] radians    回転角(ラジアン)
* @return Mat4
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> Rotation(Vector3<Ty> axis, Ty angle) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);

    axis = Normalize(axis);
    const Ty c = std::cos(angle);
    const Ty s = std::sin(angle);
    const Ty x = axis.x;
    const Ty y = axis.y;
    const Ty z = axis.z;
    const Ty ic = _1 - c;

    return {
        x * x * ic + c,     x * y * ic + z * s, x * z * ic - y * s, _0,
        x * y * ic - z * s, y * y * ic + c,     y * z * ic + x * s, _0,
        x * z * ic + y * s, y * z * ic - x * s, z * z * ic + c,     _0,
                        _0,                 _0,                 _0, _1
    };

}





namespace RH {


/**
* @brief ビュー行列を作成します
* @tparam Ty スカラ型のみ受付ます
* @param[in] pos    カメラの位置
* @param[in] dst    注視点
* @param[in] up     カメラの上方ベクトル
* @return Mat4
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> LookAt(Vector3<Ty> pos, Vector3<Ty> dst, Vector3<Ty> up) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Vector3<Ty> z = Normalize(pos - dst);
    Vector3<Ty> x = Normalize(Cross(up, z));
    Vector3<Ty> y = Cross(z, x);
    return{
        x.x, y.x, z.x, -Dot(pos, x),
        x.y, y.y, z.y, -Dot(pos, y),
        x.z, y.z, z.z, -Dot(pos, z),
        _0, _0, _0, _1
    };

}



/**
* @brief 平行投影行列を作成します
* @tparam Ty スカラ型のみ受付ます
* @param[in] left   視錐台の左端
* @param[in] right  視錐台の右端
* @param[in] bottom 視錐台の下端
* @param[in] top    視錐台の上端
* @param[in] near   近くのクリップ面の奥行き
* @param[in] far    遠くのクリップ面の奥行き
* @return Mat4
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> Orthogonal(Ty left, Ty right, Ty bottom, Ty top, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 / (right - left), _0, _0, (right + left) / (left - right),
        _0, _2 / (top - bottom), _0, (top + bottom) / (bottom - top),
        _0, _0, _1 / (near - far), _1 / (near - far),
        _0, _0, _0, _1,
    };
}




/**
* @brief 平行投影行列を作成します
* @tparam Ty スカラ型のみ受付ます
* @param[in] width  視錐台の幅
* @param[in] height 視錐台の高さ
* @param[in] near   近くのクリップ面の奥行き
* @param[in] far    遠くのクリップ面の奥行き
* @return Mat4
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> Orthogonal(Ty width, Ty height, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 / width, _0, _0, _0,
        _0, _2 / height, _0, _0,
        _0, _0, _1 / (near - far), _1 / (near - far),
        _0, _0, _0, _1,
    };
}




/**
* @brief 透視投影行列を作成します
* @tparam Ty スカラ型のみ受付ます
* @param[in] left   視錐台の左端
* @param[in] right  視錐台の右端
* @param[in] bottom 視錐台の下端
* @param[in] top    視錐台の上端
* @param[in] near   近くのクリップ面の奥行き
* @param[in] far    遠くのクリップ面の奥行き
* @return Mat4
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> Perspective(Ty left, Ty right, Ty bottom, Ty top, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 * near / (right - left), _0, (right + left) / (right - left), _0,
        _0, _2 * near / (bottom - top), (bottom + top) / (bottom - top), _0,
        _0, _0, far / (near - far), far * near / (near - far),
        _0, _0, -_1, _0,
    };
}




/**
* @brief 透視投影行列を作成します
* @param[in] width  視錐台の幅
* @param[in] height 視錐台の高さ
* @param[in] near   近くのクリップ面の奥行き
* @param[in] far    遠くのクリップ面の奥行き
* @return Mat4
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> Perspective(Ty width, Ty height, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 * near / width, _0, _0, _0,
        _0, _2 * near / height, _0, _0,
        _0, _0, far / (near - far), far * near / (near - far),
        _0, _0, -_1, _0,
    };
}


/**
* @brief 平行投影行列を作成します
* @param[in] fovy   視錐台の幅
* @param[in] aspect アスペクト比
* @param[in] near   近くのクリップ面の奥行き
* @param[in] far    遠くのクリップ面の奥行き
* @return Mat4
* @exception none
**/
template <class Ty>
Matrix4x4<Ty> PerspectiveFov(Ty angle, Ty aspect, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Ty f = static_cast<Ty>(_1 / std::tan(angle / static_cast<Ty>(2)));
    return {
        f / aspect, _0, _0, _0,
        _0, f, _0, _0,
        _0, _0, far / (near - far), far * near / (near - far),
        _0, _0, -_1, _0,
    };
}

} // namespace RH





namespace LH {


template <class Ty>
Matrix4x4<Ty> LookAt(Vector3<Ty> pos, Vector3<Ty> dst, Vector3<Ty> up) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Vector3<Ty> z = Normalize(dst - pos);
    Vector3<Ty> x = Normalize(Cross(up, z));
    Vector3<Ty> y = Cross(z, x);
    return{
        x.x, y.x, z.x, -Dot(pos, x),
        x.y, y.y, z.y, -Dot(pos, y),
        x.z, y.z, z.z, -Dot(pos, z),
        _0, _0, _0, _1
    };
}


template <class Ty>
Matrix4x4<Ty> Orthogonal(Ty left, Ty right, Ty bottom, Ty top, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 / (right - left), _0, _0, (right + left) / (left - right),
        _0, _2 / (top - bottom), _0, (top + bottom) / (bottom - top),
        _0, _0, _1 / (far - near), _1 / (near - far),
        _0, _0, _0, _1,
    };
}


template <class Ty>
Matrix4x4<Ty> Orthogonal(Ty width, Ty height, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 / width, _0, _0, _0,
        _0, _2 / height, _0, _0,
        _0, _0, _1 / (far - near), _1 / (near - far),
        _0, _0, _0, _1,
    };
}


template <class Ty>
Matrix4x4<Ty> Perspective(Ty left, Ty right, Ty bottom, Ty top, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 * near / (right - left), _0, (right + left) / (left - right), _0,
        _0, _2 * near / (bottom - top), (bottom + top) / (top - bottom), _0,
        _0, _0, far / (far - near), far * near / (near - far),
        _0, _0, _1, _0,
    };
}


template <class Ty>
Matrix4x4<Ty> Perspective(Ty width, Ty height, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 * near / width, _0, _0, _0,
        _0, _2 * near / height, _0, _0,
        _0, _0, far / (far - near), far * near / (near - far),
        _0, _0, _1, _0,
    };
}


template <class Ty>
Matrix4x4<Ty> PerspectiveFov(Ty angle, Ty aspect, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Ty f = static_cast<Ty>(_1 / std::tan(angle / static_cast<Ty>(2)));
    return {
        f / aspect, _0, _0, _0,
        _0, f, _0, _0,
        _0, _0, far / (far - near), far * near / (near - far),
        _0, _0, _1, _0,
    };
}

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



template <class Ty>
Matrix4x4<Ty> Translation(Ty x, Ty y, Ty z) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    return {
        _1, _0, _0, _0,
        _0, _1, _0, _0,
        _0, _0, _1, _0,
         x,  y,  z, _1
    };
}



template <class Ty>
Matrix4x4<Ty> Translation(Vector3<Ty> v) noexcept {
    return Translation(v.x, v.y, v.z);
}



template <class Ty>
Matrix4x4<Ty> RotationX(Ty radians) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Ty s = std::sin(radians);
    Ty c = std::cos(radians);
    return {
        _1, _0, _0, _0,
        _0,  c,  s, _0,
        _0, -s,  c, _0,
        _0, _0, _0, _1
    };
}



template <class Ty>
Matrix4x4<Ty> RotationY(Ty radians) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Ty s = std::sin(radians);
    Ty c = std::cos(radians);
    return {
         c, _0, -s, _0,
        _0, _1, _0, _0,
         s, _0,  c, _0,
        _0, _0, _0, _1
    };
}


template <class Ty>
Matrix4x4<Ty> RotationZ(Ty radians) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Ty s = std::sin(radians);
    Ty c = std::cos(radians);
    return {
         c,  s, _0, _0,
        -s,  c, _0, _0,
        _0, _0, _1, _0,
        _0, _0, _0, _1
    };
}


template <class Ty>
Matrix4x4<Ty> Rotation(Vector3<Ty> axis, Ty angle) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);

    axis = Normalize(axis);
    const Ty c = std::cos(angle);
    const Ty s = std::sin(angle);
    const Ty x = axis.x;
    const Ty y = axis.y;
    const Ty z = axis.z;
    const Ty ic = _1 - c;

    return {
        x * x * ic + c,     x * y * ic - z * s, x * z * ic + y * s, _0,
        x * y * ic + z * s, y * y * ic + c,     y * z * ic - x * s, _0,
        x * z * ic - y * s, y * z * ic + x * s, z * z * ic + c,     _0,
                        _0,                 _0,                 _0, _1
    };
}





namespace RH {


template <class Ty>
Matrix4x4<Ty> LookAt(Vector3<Ty> pos, Vector3<Ty> dst, Vector3<Ty> up) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Vector3<Ty> z = Normalize(pos - dst);
    Vector3<Ty> x = Normalize(Cross(up, z));
    Vector3<Ty> y = Cross(z, x);
    return{
        x.x, x.y, x.z, _0,
        y.x, y.y, y.z, _0,
        z.x, z.y, z.z, _0,
        -Dot(pos, x), -Dot(pos, y), -Dot(pos, z), _1
    };
}


template <class Ty>
Matrix4x4<Ty> Orthogonal(Ty left, Ty right, Ty bottom, Ty top, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 / (right - left), _0, _0, _0,
        _0, _2 / (top - bottom), _0, _0,
        _0, _0, _1 / (near - far), _0,
        (right + left) / (left - right), (top + bottom) / (bottom - top), _1 / (near - far), _1,
    };
}


template <class Ty>
Matrix4x4<Ty> Orthogonal(Ty width, Ty height, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 / width, _0, _0, _0,
        _0, _2 / height, _0, _0,
        _0, _0, _1 / (near - far), _0,
        _0, _0, _1 / (near - far), _1,
    };
}


template <class Ty>
Matrix4x4<Ty> Perspective(Ty left, Ty right, Ty bottom, Ty top, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 * near / (right - left), _0, _0, _0,
        _0, _2 * near / (top - bottom), _0, _0,
        (right + left) / (right - left),(bottom + top) / (top - bottom),far / (near - far), -_1,
        _0, _0, far * near / (near - far), _0,
    };
}


template <class Ty>
Matrix4x4<Ty> Perspective(Ty width, Ty height, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 * near / width, _0, _0, _0,
        _0, _2 * near / height, _0, _0,
        _0, _0, far / (near - far), -_1,
        _0, _0, far * near / (near - far), _0,
    };
}


template <class Ty>
Matrix4x4<Ty> PerspectiveFov(Ty angle, Ty aspect, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Ty f = static_cast<Ty>(_1 / std::tan(angle / static_cast<Ty>(2)));
    return {
        f / aspect, _0, _0, _0,
        _0, f, _0, _0,
        _0, _0, far / (near - far), -_1,
        _0, _0, far * near / (near - far), _0,
    };
}

} // namespace RH




namespace LH {


template <class Ty>
Matrix4x4<Ty> LookAt(Vector3<Ty> pos, Vector3<Ty> dst, Vector3<Ty> up) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Vector3<Ty> z = Normalize(dst - pos);
    Vector3<Ty> x = Normalize(Cross(up, z));
    Vector3<Ty> y = Cross(z, x);
    return{
        x.x, x.y, x.z, _0,
        y.x, y.y, y.z, _0,
        z.x, z.y, z.z, _0,
        -Dot(pos, x), -Dot(pos, y), -Dot(pos, z), _1
    };
}


template <class Ty>
Matrix4x4<Ty> Orthogonal(Ty left, Ty right, Ty bottom, Ty top, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 / (right - left), _0, _0, _0,
        _0, _2 / (top - bottom), _0, _0,
        _0, _0, _1 / (far - near), _0,
        (right + left) / (left - right), (top + bottom) / (bottom - top), _1 / (near - far), _1,
    };
}


template <class Ty>
Matrix4x4<Ty> Orthogonal(Ty width, Ty height, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 / width, _0, _0, _0,
        _0, _2 / height, _0, _0,
        _0, _0, _1 / (far - near), _0,
        _0, _0, _1 / (near - far), _1,
    };
}


template <class Ty>
Matrix4x4<Ty> Perspective(Ty left, Ty right, Ty bottom, Ty top, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 * near / (right - left), _0, _0, _0,
        _0, _2 * near / (bottom - top), _0, _0,
        (right + left) / (left - right),(bottom + top) / (top - bottom),far / (far - near), _1,
        _0, _0, far * near / (near - far), _0,
    };
}


template <class Ty>
Matrix4x4<Ty> Perspective(Ty width, Ty height, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    constexpr Ty _2 = static_cast<Ty>(2);
    return {
        _2 * near / width, _0, _0, _0,
        _0, _2 * near / height, _0, _0,
        _0, _0, far / (far - near), _1,
        _0, _0, far * near / (near - far), _0,
    };
}


template <class Ty>
Matrix4x4<Ty> PerspectiveFov(Ty angle, Ty aspect, Ty near, Ty far) noexcept {
    constexpr Ty _0 = static_cast<Ty>(0);
    constexpr Ty _1 = static_cast<Ty>(1);
    Ty f = static_cast<Ty>(_1 / std::tan(angle / static_cast<Ty>(2)));
    return {
        f / aspect, _0, _0, _0,
        _0, f, _0, _0,
        _0, _0, far / (far - near), _1,
        _0, _0, far * near / (near - far), _0,
    };
}

} // namespace RowMajor
} // namespace LH
} // namespace gdv

#endif
