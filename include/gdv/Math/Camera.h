/**
* @file Camera.h
* @brief カメラと行列計算関数の宣言
**/
#ifndef GDV_CAMERA_H_
#define GDV_CAMERA_H_

#include "gdv/Math/Math3D.h"
#include "gdv/Math/Vector3.h"
#include "gdv/Math/Matrix4x4.h"

namespace gdv {

/**
* @class Camera
* @brief カメラの状態を表すクラスです
* @details ビューとプロジェクションの情報が保存されます
**/
template <class Ty>
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
  Camera() noexcept :
    mode_{},
    pos_{},
    dst_{},
    up_{},
    left_{},
    right_{},
    bottom_{},
    top_{},
    near_{},
    far_{}{}


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
        Vector3<Ty> pos,
        Vector3<Ty> dst,
        Ty left,
        Ty right,
        Ty bottom,
        Ty top,
        Ty near,
        Ty far) noexcept :
        mode_{mode},
        pos_{pos},
        dst_{dst},
        up_{static_cast<Ty>(0), static_cast<Ty>(1), static_cast<Ty>(0)},
        left_{left},
        right_{right},
        bottom_{bottom},
        top_{top},
        near_{near},
        far_{far}{}


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
        Vector3<Ty> pos,
        Vector3<Ty> dst,
        Ty width,
        Ty height,
        Ty near,
        Ty far) noexcept :
        mode_{mode},
        pos_{pos},
        dst_{dst},
        up_{0.0f, 1.0f, 0.0f},
        left_{-width / 2.0f},
        right_{width / 2.0f},
        bottom_{-height / 2.0f},
        top_{height / 2.0f},
        near_{near},
        far_{far}{}



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
        Vector3<Ty> pos,
        Vector3<Ty> dst,
        Vector3<Ty> up,
        Ty left,
        Ty right,
        Ty bottom,
        Ty top,
        Ty near,
        Ty far) noexcept :
        mode_{mode},
        pos_{pos},
        dst_{dst},
        up_{up},
        left_{left},
        right_{right},
        bottom_{bottom},
        top_{top},
        near_{near},
        far_{far}{}


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
        Vector3<Ty> pos,
        Vector3<Ty> dst,
        Vector3<Ty> up,
        Ty width,
        Ty height,
        Ty near,
        Ty far) noexcept :
        mode_{mode},
        pos_{pos},
        dst_{dst},
        up_{up},
        left_{-width / 2.0f},
        right_{width / 2.0f},
        bottom_{-height / 2.0f},
        top_{height / 2.0f},
        near_{near},
        far_{far}{}



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
        Vector3<Ty> pos,
        Vector3<Ty> dst,
        Vector3<Ty> up,
        Ty fovy,
        Ty aspect,
        Ty near,
        Ty far) noexcept :
        mode_{Mode::PERSPECTIVE},
        pos_{pos},
        dst_{dst},
        up_{up},
        left_{},
        right_{},
        bottom_{},
        top_{},
        near_{near},
        far_{far} {
            Ty width = (Ty)(near / tan(fovy / 2.0)) / 2.0f;
            Ty height = width / aspect;
            top_	= -height;
            bottom_ =  height;
            left_	= -width;
            right_	=  width;
        }



    /**
    * @brief コピーコンストラクタ
    * @param[in] c コピー元のカメラ
    * @return none
    * @exception none
    **/
    Camera(const Camera<Ty> &c) noexcept :
        mode_{c.mode_},
        pos_{c.pos_},
        dst_{c.dst_},
        up_{c.up_},
        left_{c.left_},
        right_{c.right_},
        bottom_{c.bottom_},
        top_{c.top_},
        near_{c.near_},
        far_{c.far_}{}



    /**
    * @brief 代入演算子
    * @param[in] c コピー元のカメラ
    * @return 自身の参照
    * @exception none
    **/
    Camera& operator = (const Camera<Ty> &c) noexcept {
        mode_   = c.mode_;
        pos_    = c.pos_;
        dst_    = c.dst_;
        up_     = c.up_;
        left_   = c.left_;
        right_  = c.right_;
        bottom_ = c.bottom_;
        top_    = c.top_;
        near_   = c.near_;
        far_    = c.far_;
        return *this;
    }



public:
    /**
    * @brief カメラの投影モードを設定します
    * @param[in] mode 投影モード
    * @return none
    * @exception none
    **/
    void SetMode(Mode mode) noexcept {mode_ = mode;}

    /**
    * @brief カメラの位置を設定します
    * @param[in] pos カメラの位置
    * @return none
    * @exception none
    **/
    void SetPos(Vector3<Ty> pos) noexcept {pos_ = pos;}

    /**
    * @brief カメラの注視点を設定します
    * @param[in] pos カメラの注視点
    * @return none
    * @exception none
    **/
    void SetDst(Vector3<Ty> dst) noexcept {dst_ = dst;}

    /**
    * @brief カメラの上方を設定します
    * @param[in] pos カメラの上方
    * @return none
    * @exception none
    **/
    void SetUp(Vector3<Ty> up) noexcept {up_ = up;}

    /**
    * @brief 視錐台の左端を設定します
    * @param[in] left 視錐台の左端
    * @return none
    * @exception none
    **/
    void SetLeft(Ty left) noexcept {left_ = left;}

    /**
    * @brief 視錐台の右端を設定します
    * @param[in] right 視錐台の右端
    * @return none
    * @exception none
    **/
    void SetRight(Ty right) noexcept {right_ = right;}

    /**
    * @brief 視錐台の下端を設定します
    * @param[in] bottom 視錐台の下端
    * @return none
    * @exception none
    **/
    void SetBottom(Ty bottom) noexcept {bottom_ = bottom;}

    /**
    * @brief 視錐台の上端を設定します
    * @param[in] top 視錐台の上端
    * @return none
    * @exception none
    **/
    void SetTop(Ty top) noexcept {top_ = top;}

    /**
    * @brief 近くのクリップ面の奥行きを設定します
    * @param[in] near クリップ面の奥行き
    * @return none
    * @exception none
    **/
    void SetNear(Ty near) noexcept {near_ = near;}

    /**
    * @brief 遠くのクリップ面の奥行きを設定します
    * @param[in] far クリップ面の奥行き
    * @return none
    * @exception none
    **/
    void SetFar(Ty far) noexcept{far_ = far;}

    /**
    * @brief 視錐台の幅を設定します
    * @param[in] Width 幅
    * @return none
    * @exception none
    **/
    void SetWidth(Ty width) noexcept {
        left_   = -width / 2.0f;
        right_  =  width / 2.0f;
    }

    /**
    * @brief 視錐台の高さを設定します
    * @param[in] height 高さ
    * @return none
    * @exception none
    **/
    void SetHeight(Ty height) noexcept {
        top_    = height / 2.0f;
        bottom_ = height / 2.0f;
    }

    /**
    * @brief クリップ面の奥行きを設定します
    * @param[in] near 近くのクリップ面の奥行き
    * @param[in] far 遠くのクリップ面の奥行き
    * @return none
    * @exception none
    **/
    void SetNearFar(Ty near, Ty far) noexcept {
        near_   = near;
        far_    = far;
    }

    /**
    * @brief 視錐台の矩形を設定します
    * @param[in] left 視錐台の左端
    * @param[in] right 視錐台の右端
    * @param[in] bottom 視錐台の下端
    * @param[in] top 視錐台の上端
    * @return none
    * @exception none
    **/
    void SetRect(Ty left, Ty right, Ty bottom, Ty top) noexcept {
        left_   = left;
        right_  = right;
        bottom_ = bottom;
        top_    = top;
    }



public:
    /**
    * @brief カメラの投影モードを取得します
    * @return 投影モード
    * @exception none
    **/
    Mode GetMode() const noexcept {return mode_;}

    /**
    * @brief カメラの位置を取得します
    * @return カメラの位置
    * @exception none
    **/
    Vector3<Ty> GetPos() const noexcept {return pos_;}

    /**
    * @brief カメラの注視点を取得します
    * @return 注視点
    * @exception none
    **/
    Vector3<Ty> GetDst() const noexcept {return dst_;}

    /**
    * @brief カメラの上方ベクトルを取得します
    * @return 上方ベクトル
    * @exception none
    **/
    Vector3<Ty> GetUp() const noexcept {return up_;}

    /**
    * @brief カメラの視錐台の左端を取得します
    * @return 視錐台の左端
    * @exception none
    **/
    Ty GetLeft() const noexcept{return left_;}

    /**
    * @brief カメラの視錐台の右端を取得します
    * @return 視錐台の右端
    * @exception none
    **/
    Ty GetRight() const noexcept {return right_;}

    /**
    * @brief カメラの視錐台の下端を取得します
    * @return 視錐台の下端
    * @exception none
    **/
    Ty GetBottom() const noexcept {return bottom_;}

    /**
    * @brief カメラの視錐台の上端を取得します
    * @return 視錐台の上端
    * @exception none
    **/
    Ty GetTop() const noexcept {return top_;}

    /**
    * @brief 近くのクリップ面の奥行きを取得します
    * @return 近くのクリップ面の奥行き
    * @exception none
    **/
    Ty GetNear() const noexcept {return near_;}

    /**
    * @brief 遠くのクリップ面の奥行きを取得します
    * @return 遠くのクリップ面の奥行き
    * @exception none
    **/
    Ty GetFar() const noexcept {return far_;}
    
    /**
    * @brief 視錐台の幅を取得します
    * @return 視錐台の幅
    * @exception none
    **/
    Ty GetWidth() const noexcept {return right_ - left_;}

    /**
    * @brief 視錐台の高さを取得します
    * @return 視錐台の高さ
    * @exception none
    **/
    Ty GetHeight() const noexcept {return top_ - bottom_;}


private:
    Mode        mode_;      //! カメラの投影モード
    Vector3<Ty> pos_;       //! カメラの位置
    Vector3<Ty> dst_;       //! カメラの注視点
    Vector3<Ty> up_;        //! カメラの上方ベクトル
    Ty          left_;      //! 視錐台の左端
    Ty          right_;     //! 視錐台の右端
    Ty          bottom_;    //! 視錐台の下端
    Ty          top_;       //! 視錐台の上端
    Ty          near_;      //! 近くのクリップ面の奥行き
    Ty          far_;       //! 遠くのクリップ面の奥行き
};



namespace RowMajor {
namespace RH {
namespace {
template <class Ty>
constexpr Matrix4x4<Ty>(*ProjectionFunc[])(Ty, Ty, Ty, Ty) noexcept {Perspective, Orthogonal};
}

template <class Ty>
Matrix4x4<Ty> Projection(Camera<Ty> c) noexcept {
    return ProjectionFunc<Ty>[(int)c.GetMode()](c.GetWidth(), c.GetHeight(), c.GetNear(), c.GetFar());
}

template <class Ty>
Matrix4x4<Ty> View(Camera<Ty> c) noexcept {
    return LookAt(c.GetPos(), c.GetDst(), c.GetUp());
}

template <class Ty>
Matrix4x4<Ty> Transform(Camera<Ty> c) noexcept {
    return View(c) * Projection(c);
}


template <class Ty>
Matrix4x4<Ty> operator * (Camera<Ty> c, Matrix4x4<Ty> m) noexcept {
    return Transform(c) * m;
}


template <class Ty>
Matrix4x4<Ty> operator * (Matrix4x4<Ty> m, Camera<Ty> c) noexcept {
    return m * Transform(c);
}


template <class Ty>
Vector3<Ty> operator * (Vector3<Ty> v, Camera<Ty> c) noexcept {
	return Transform(c) * v;
}

}// namespace RH



namespace LH {
namespace {
template <class Ty>
constexpr Matrix4x4<Ty>(*ProjectionFunc[])(Ty, Ty, Ty, Ty) noexcept {Perspective, Orthogonal};
}

template <class Ty>
Matrix4x4<Ty> Projection(Camera<Ty> c) noexcept {
    return ProjectionFunc<Ty>[(int)c.GetMode()](c.GetWidth(), c.GetHeight(), c.GetNear(), c.GetFar());
}

template <class Ty>
Matrix4x4<Ty> View(Camera<Ty> c) noexcept {
    return LookAt(c.GetPos(), c.GetDst(), c.GetUp());
}

template <class Ty>
Matrix4x4<Ty> Transform(Camera<Ty> c) noexcept {
	return View(c) * Projection(c);
}


template <class Ty>
Matrix4x4<Ty> operator * (Camera<Ty> c, Matrix4x4<Ty> m) noexcept {
    return Transform(c) * m;
}


template <class Ty>
Matrix4x4<Ty> operator * (Matrix4x4<Ty> m, Camera<Ty> c) noexcept {
    return m * Transform(c);
}


template <class Ty>
Vector3<Ty> operator * (Vector3<Ty> v, Camera<Ty> c) noexcept {
    return Transform(c) * v;
}

} // namespace LH
} // namespace RowMajor






namespace ColumnMajor {
namespace RH {
namespace {
template <class Ty>
constexpr Matrix4x4<Ty>(*ProjectionFunc[])(Ty, Ty, Ty, Ty) noexcept {Perspective, Orthogonal};
}

template <class Ty>
Matrix4x4<Ty> Projection(Camera<Ty> c) noexcept {
	/*return
		c.GetMode() == Camera<Ty>::Mode::PERSPECTIVE ?
		Perspective(c.GetWidth(), c.GetHeight(), c.GetNear(), c.GetFar()):
		Orthogonal(c.GetWidth(), c.GetHeight(), c.GetNear(), c.GetFar());*/
    return ProjectionFunc<Ty>[(int)c.GetMode()](c.GetWidth(), c.GetHeight(), c.GetNear(), c.GetFar());
}

template <class Ty>
Matrix4x4<Ty> View(Camera<Ty> c) noexcept {
    return LookAt(c.GetPos(), c.GetDst(), c.GetUp());
}

template <class Ty>
Matrix4x4<Ty> Transform(Camera<Ty> c) noexcept {
    return Projection(c) * View(c);
}

template <class Ty>
Matrix4x4<Ty> operator * (Camera<Ty> c, Matrix4x4<Ty> m) noexcept {
    return Transform(c) * m;
}


template <class Ty>
Matrix4x4<Ty> operator * (Matrix4x4<Ty> m, Camera<Ty> c) noexcept {
    return m * Transform(c);
}


template <class Ty>
Vector3<Ty> operator * (Camera<Ty> c, Vector3<Ty> v) noexcept {
    return Transform(c) * v;
}

} // namespace RH



namespace LH {
namespace {
template <class Ty>
constexpr Matrix4x4<Ty>(*ProjectionFunc[])(Ty, Ty, Ty, Ty) noexcept {Perspective, Orthogonal};
}

template <class Ty>
Matrix4x4<Ty> Projection(Camera<Ty> c) noexcept {
    return ProjectionFunc<Ty>[(int)c.GetMode()](c.GetWidth(), c.GetHeight(), c.GetNear(), c.GetFar());
}

template <class Ty>
Matrix4x4<Ty> View(Camera<Ty> c) noexcept {
    return LookAt(c.GetPos(), c.GetDst(), c.GetUp());
}

template <class Ty>
Matrix4x4<Ty> Transform(Camera<Ty> c) noexcept {
    return Projection(c) * View(c);
}


template <class Ty>
Matrix4x4<Ty> operator * (Camera<Ty> c, Matrix4x4<Ty> m) noexcept {
    return Transform(c) * m;
}


template <class Ty>
Matrix4x4<Ty> operator * (Matrix4x4<Ty> m, Camera<Ty> c) noexcept {
    return m * Transform(c);
}


template <class Ty>
Vector3<Ty> operator * (Camera<Ty> c, Vector3<Ty> v) noexcept {
    return Transform(c) * v;
}

} // namespace LH
} // namespavce ColumnMajor
} // namespace gdv

#endif

