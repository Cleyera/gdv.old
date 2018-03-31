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

    /**
    * @brief 視錐台の左端を設定します
    * @param[in] left 視錐台の左端
    * @return none
    * @exception none
    **/
    void SetLeft(float left) noexcept;

    /**
    * @brief 視錐台の右端を設定します
    * @param[in] right 視錐台の右端
    * @return none
    * @exception none
    **/
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

    /**
    * @brief 近くのクリップ面の奥行きを設定します
    * @param[in] near クリップ面の奥行き
    * @return none
    * @exception none
    **/
    void SetNear(float near) noexcept;

    /**
    * @brief 遠くのクリップ面の奥行きを設定します
    * @param[in] far クリップ面の奥行き
    * @return none
    * @exception none
    **/
    void SetFar(float far) noexcept;

    /**
    * @brief 視錐台の幅を設定します
    * @param[in] Width 幅
    * @return none
    * @exception none
    **/
    void SetWidth(float width) noexcept;

    /**
    * @brief 視錐台の高さを設定します
    * @param[in] height 高さ
    * @return none
    * @exception none
    **/
    void SetHeight(float height) noexcept;

    /**
    * @brief クリップ面の奥行きを設定します
    * @param[in] near 近くのクリップ面の奥行き
    * @param[in] far 遠くのクリップ面の奥行き
    * @return none
    * @exception none
    **/
    void SetNearFar(float near, float far) noexcept;

    /**
    * @brief 視錐台の矩形を設定します
    * @param[in] left 視錐台の左端
    * @param[in] right 視錐台の右端
    * @param[in] bottom 視錐台の下端
    * @param[in] top 視錐台の上端
    * @return none
    * @exception none
    **/
    void SetRect(float left, float right, float bottom, float top) noexcept;



public:
    /**
    * @brief カメラの投影モードを取得します
    * @return 投影モード
    * @exception none
    **/
    Mode GetMode() const noexcept;

    /**
    * @brief カメラの位置を取得します
    * @return カメラの位置
    * @exception none
    **/
    Vec3 GetPos() const noexcept;

    /**
    * @brief カメラの注視点を取得します
    * @return 注視点
    * @exception none
    **/
    Vec3 GetDst() const noexcept;

    /**
    * @brief カメラの上方ベクトルを取得します
    * @return 上方ベクトル
    * @exception none
    **/
    Vec3 GetUp() const noexcept;

    /**
    * @brief カメラの視錐台の左端を取得します
    * @return 視錐台の左端
    * @exception none
    **/
    float GetLeft() const noexcept;

    /**
    * @brief カメラの視錐台の右端を取得します
    * @return 視錐台の右端
    * @exception none
    **/
    float GetRight() const noexcept;

    /**
    * @brief カメラの視錐台の下端を取得します
    * @return 視錐台の下端
    * @exception none
    **/
    float GetBottom() const noexcept;

    /**
    * @brief カメラの視錐台の上端を取得します
    * @return 視錐台の上端
    * @exception none
    **/
    float GetTop() const noexcept;

    /**
    * @brief 近くのクリップ面の奥行きを取得します
    * @return 近くのクリップ面の奥行き
    * @exception none
    **/
    float GetNear() const noexcept;

    /**
    * @brief 遠くのクリップ面の奥行きを取得します
    * @return 遠くのクリップ面の奥行き
    * @exception none
    **/
    float GetFar() const noexcept;
    
    /**
    * @brief 視錐台の幅を取得します
    * @return 視錐台の幅
    * @exception none
    **/
    float GetWidth() const noexcept;

    /**
    * @brief 視錐台の高さを取得します
    * @return 視錐台の高さ
    * @exception none
    **/
    float GetHeight() const noexcept;


private:
    Mode    mode_;      //! カメラの投影モード
    Vec3    pos_;       //! カメラの位置
    Vec3    dst_;       //! カメラの注視点
    Vec3    up_;        //! カメラの上方ベクトル
    float   left_;      //! 視錐台の左端
    float   right_;     //! 視錐台の右端
    float   bottom_;    //! 視錐台の下端
    float   top_;       //! 視錐台の上端
    float   near_;      //! 近くのクリップ面の奥行き
    float   far_;       //! 遠くのクリップ面の奥行き
};



namespace RowMajor {
namespace LH {

Mat4 Projection(Camera c) noexcept;
Mat4 View(Camera c) noexcept;
Mat4 Transform(Camera c) noexcept;

Mat4 operator * (Camera c, Mat4 m) noexcept;
Mat4 operator * (Mat4 m, Camera c) noexcept;
Vec3 operator * (Camera c, Vec3 v) noexcept;

} // namespace LH

namespace RH {

Mat4 Projection(Camera c) noexcept;
Mat4 View(Camera c) noexcept;
Mat4 Transform(Camera c) noexcept;

Mat4 operator * (Camera c, Mat4 m) noexcept;
Mat4 operator * (Mat4 m, Camera c) noexcept;
Vec3 operator * (Camera c, Vec3 v) noexcept;

} // namespace RH
} // namespace RowMajor



namespace ColumnMajor {
namespace LH {

Mat4 Projection(Camera c) noexcept;
Mat4 View(Camera c) noexcept;
Mat4 Transform(Camera c) noexcept;

Mat4 operator * (Camera c, Mat4 m) noexcept;
Mat4 operator * (Mat4 m, Camera c) noexcept;
Vec3 operator * (Vec3 v, Camera c) noexcept;

} // namespace LH

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
