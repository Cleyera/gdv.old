/**
* @file Camera.h
* @brief カメラと行列計算関数の宣言
**/
#ifndef GDV_CAMERA_H_
#define GDV_CAMERA_H_

#include "gdv/Math/Vector3.h"
#include "gdv/Math/Matrix4x4.h"

namespace gdv {

/**
* @class Camera
* @brief カメラの状態を表すクラスです
* @details ビューとプロジェクションの情報が保存されます
**/
class Camera {
public:

    /**
    * @enum Mode
    * @brief カメラの投影モード
    **/
    enum class Mode : int {

        //! 透視投影カメラ
        PERSPECTIVE = 0,

        //! 平行投影カメラ
        ORTHOGONAL = 1,
    };


public:

  /**
  * @brief デフォルトコンストラクタ
  * @return none
  * @exception none
  **/
  Camera() noexcept;


    /**
    * @brief コンストラクタ
    * @param[in] mode   投影モード
    * @param[in] pos    カメラの位置
    * @param[in] dst    カメラの注視点
    * @param[in] left   視錐台の左端
    * @param[in] right  視錐台の右端
    * @param[in] bottom 視錐台の下端
    * @param[in] top    視錐台の上端
    * @param[in] near   近くのクリップ面の奥行き
    * @param[in] far    遠くのクリップ面の奥行き
    * @return none
    * @exception none
    **/
    Camera(
        Mode mode,
        Vec3 pos,
        Vec3 dst,
        float left,
        float right,
        float bottom,
        float top,
        float near,
        float far) noexcept;


    /**
    * @brief コンストラクタ
    * @param[in] mode   投影モード
    * @param[in] pos    カメラの位置
    * @param[in] dst    カメラの注視点
    * @param[in] width  視錐台の幅
    * @param[in] height 視錐台の高さ
    * @param[in] near   近くのクリップ面の奥行き
    * @param[in] far    遠くのクリップ面の奥行き
    * @return none
    * @exception none
    **/
    Camera(
        Mode mode,
        Vec3 pos,
        Vec3 dst,
        float width,
        float height,
        float near,
        float far) noexcept;



    /**
    * @brief コンストラクタ
    * @param[in] mode   投影モード
    * @param[in] pos    カメラの位置
    * @param[in] dst    カメラの注視点
    * @param[in] up     カメラの上方ベクトル
    * @param[in] left   視錐台の左端
    * @param[in] right  視錐台の右端
    * @param[in] bottom 視錐台の下端
    * @param[in] top    視錐台の上端
    * @param[in] near   近くのクリップ面の奥行き
    * @param[in] far    遠くのクリップ面の奥行き
    * @return none
    * @exception none
    **/
    Camera(
        Mode mode,
        Vec3 pos,
        Vec3 dst,
        Vec3 up,
        float left,
        float right,
        float bottom,
        float top,
        float near,
        float far) noexcept;


    /**
    * @brief コンストラクタ
    * @param[in] mode   投影モード
    * @param[in] pos    カメラの位置
    * @param[in] dst    カメラの注視点
    * @param[in] up     カメラの上方ベクトル
    * @param[in] width  視錐台の幅
    * @param[in] height 視錐台の高さ
    * @param[in] near   近くのクリップ面の奥行き
    * @param[in] far    遠くのクリップ面の奥行き
    * @return none
    * @exception none
    **/
    Camera(
        Mode mode,
        Vec3 pos,
        Vec3 dst,
        Vec3 up,
        float width,
        float height,
        float near,
        float far) noexcept;



    /**
    * @brief コンストラクタ
    * @details このコンストラクタでは透視投影変換のカメラが作成されます
    * @param[in] pos    カメラの位置
    * @param[in] dst    カメラの注視点
    * @param[in] up     カメラの上方ベクトル
    * @param[in] fovy   視錐台の幅
    * @param[in] aspect アスペクト比
    * @param[in] near   近くのクリップ面の奥行き
    * @param[in] far    遠くのクリップ面の奥行き
    * @return none
    * @exception none
    **/
    Camera(
        Vec3 pos,
        Vec3 dst,
        Vec3 up,
        float fovy,
        float aspect,
        float near,
        float far) noexcept;



    /**
    * @brief コピーコンストラクタ
    * @param[in] c コピー元のカメラ
    * @return none
    * @exception none
    **/
    Camera(const Camera &c) noexcept;



    /**
    * @brief 代入演算子
    * @param[in] c コピー元のカメラ
    * @return 自身の参照
    * @exception none
    **/
    Camera& operator = (const Camera &c) noexcept;



public:
    /**
    * @brief カメラの投影モードを設定します
    * @param[in] mode 投影モード
    * @return none
    * @exception none
    **/
    void SetMode(Mode mode) noexcept;

    /**
    * @brief カメラの位置を設定します
    * @param[in] pos カメラの位置
    * @return none
    * @exception none
    **/
    void SetPos(Vec3 pos) noexcept;

    /**
    * @brief カメラの注視点を設定します
    * @param[in] pos カメラの注視点
    * @return none
    * @exception none
    **/
    void SetDst(Vec3 dst) noexcept;

    /**
    * @brief カメラの上方を設定します
    * @param[in] pos カメラの上方
    * @return none
    * @exception none
    **/
    void SetUp(Vec3 up) noexcept;

    void SetLeft(float left) noexcept;
    void SetRight(float right) noexcept;

    /**
    * @brief 視錐台の下端を設定します
    * @param[in] bottom 視錐台の下端
    * @return none
    * @exception none
    **/
    void SetBottom(float bottom) noexcept;

    /**
    * @brief 視錐台の上端を設定します
    * @param[in] top 視錐台の上端
    * @return none
    * @exception none
    **/
    void SetTop(float top) noexcept;
    void SetNear(float near) noexcept;
    void SetFar(float far) noexcept;
    void SetWidth(float width) noexcept;
    void SetHeight(float height) noexcept;
    void SetNearFar(float near, float far) noexcept;
    void SetRect(float top, float left, float bottom, float right) noexcept;

public:
    Mode GetMode() const noexcept;
    Vec3 GetPos() const noexcept;
    Vec3 GetDst() const noexcept;
    Vec3 GetUp() const noexcept;
    float GetLeft() const noexcept;
    float GetRight() const noexcept;
    float GetBottom() const noexcept;
    float GetTop() const noexcept;
    float GetNear() const noexcept;
    float GetFar() const noexcept;
    float GetWidth() const noexcept;
    float GetHeight() const noexcept;

private:
    Mode    mode_;
    Vec3    pos_;
    Vec3    dst_;
    Vec3    up_;
    float   left_;
    float   right_;
    float   bottom_;
    float   top_;
    float   near_;
    float   far_;
};



namespace RowMajor {
namespace LH {

Mat4 Projection(Camera c) noexcept;
Mat4 View(Camera c) noexcept;
Mat4 Transform(Camera c) noexcept;

Mat4 operator * (Camera c, Mat4 m) noexcept;
Mat4 operator * (Mat4 m, Camera c) noexcept;
Vec3 operator * (Camera c, Vec3 v) noexcept;

}//namespace LH

namespace RH {

Mat4 Projection(Camera c) noexcept;
Mat4 View(Camera c) noexcept;
Mat4 Transform(Camera c) noexcept;

Mat4 operator * (Camera c, Mat4 m) noexcept;
Mat4 operator * (Mat4 m, Camera c) noexcept;
Vec3 operator * (Camera c, Vec3 v) noexcept;

}// namespace RH
}//namespace RowMajor



namespace ColumnMajor {
namespace LH {

Mat4 Projection(Camera c) noexcept;
Mat4 View(Camera c) noexcept;
Mat4 Transform(Camera c) noexcept;

Mat4 operator * (Camera c, Mat4 m) noexcept;
Mat4 operator * (Mat4 m, Camera c) noexcept;
Vec3 operator * (Vec3 v, Camera c) noexcept;

}//namespace LH

namespace RH {

Mat4 Projection(Camera c) noexcept;
Mat4 View(Camera c) noexcept;
Mat4 Transform(Camera c) noexcept;

Mat4 operator * (Camera c, Mat4 m) noexcept;
Mat4 operator * (Mat4 m, Camera c) noexcept;
Vec3 operator * (Vec3 v, Camera c) noexcept;

} // namespace RH
} // namespace ColumnMajor
} // namespace gdv

#endif
