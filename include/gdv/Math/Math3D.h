#ifndef GDV_MATH3D_H_
#define GDV_MATH3D_H_


#include "gdv/Math/Vector4.h"
#include "gdv/Math/Matrix4x4.h"
#include "gdv/Math/Matrix3x3.h"


namespace gdv {


/**
* @brief 単位行列を作成します
* @return Mat4
* @exception none
**/
Mat4 UnitMatrix() noexcept;



/**
* @brief 行列を転地します
* @param[in] m 転地する行列
* @return Mat3
* @exception none
**/
Mat3 Transpose(const Mat3 &m) noexcept;



/**
* @brief 行列を転地します
* @param[in] m 転地する行列
* @return Mat4
* @exception none
**/
Mat4 Transpose(const Mat4 &m) noexcept;




namespace ColumnMajor {



/**
* @brief スケーリング行列を作成します
* @param[in] x x軸方向の拡大率
* @param[in] y y軸方向の拡大率
* @param[in] z z軸方向の拡大率
* @return Mat4
* @exception none
**/
Mat4 Scaling(float x, float y, float z) noexcept;



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
* @param[in] top    視錐台の上端
* @param[in] bottom 視錐台の下端
* @param[in] near   近くのクリップ面の奥行き
* @param[in] far    遠くのクリップ面の奥行き
* @return Mat4
* @exception none
**/
Mat4 Orthogonal(float left, float right, float top, float bottom, float near, float far) noexcept;


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
* @param[in] top    視錐台の上端
* @param[in] bottom 視錐台の下端
* @param[in] near   近くのクリップ面の奥行き
* @param[in] far    遠くのクリップ面の奥行き
* @return Mat4
* @exception none
**/
Mat4 Perspective(float left, float right, float top, float bottom, float near, float far) noexcept;


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


Mat4 Orthogonal(float left, float right, float top, float bottom, float near, float far) noexcept;


Mat4 Orthogonal(float width, float height, float near, float far) noexcept;


Mat4 Perspective(float left, float right, float top, float bottom, float near, float far) noexcept;


Mat4 Perspective(float width, float height, float near, float far) noexcept;


Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept;

} // namespace LH
} // namespace ColumnMajor






namespace RowMajor {


Mat4 Scaling(float x, float y, float z) noexcept;


Mat4 Translation(float x, float y, float z) noexcept;


Mat4 RotationX(float radians) noexcept;


Mat4 RotationY(float radians) noexcept;


Mat4 RotationZ(float radians) noexcept;


Mat4 Rotation(Vec3 axis, float angle) noexcept;




namespace RH {


Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept;


Mat4 Orthogonal(float left, float right, float top, float bottom, float near, float far) noexcept;


Mat4 Orthogonal(float width, float height, float near, float far) noexcept;


Mat4 Perspective(float left, float right, float top, float bottom, float near, float far) noexcept;


Mat4 Perspective(float width, float height, float near, float far) noexcept;


Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept;

} // namespace RH




namespace LH {


Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept;


Mat4 Orthogonal(float left, float right, float top, float bottom, float near, float far) noexcept;


Mat4 Orthogonal(float width, float height, float near, float far) noexcept;


Mat4 Perspective(float left, float right, float top, float bottom, float near, float far) noexcept;


Mat4 Perspective(float width, float height, float near, float far) noexcept;


Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept;

} // namespace RowMajor
} // namespace LH
} // namespace gdv

#endif
