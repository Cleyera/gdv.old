/**
* @file camera.h
* @brief カメラと行列計算関数の宣言
**/
#ifndef GDV_CAMERA_H_
#define GDV_CAMERA_H_

#include <gdv/math/math_function.h>
#include <gdv/math/vector3.h>
#include <gdv/math/matrix4x4.h>

namespace gdv {

/**
* @class camera
* @brief カメラの状態を表すクラスです
* @details ビューとプロジェクションの情報が保存されます
**/
template <class Ty>
class camera {
public:

    /**
    * @enum mode
    * @brief カメラの投影モード
    **/
    enum class mode : int {

        //! 透視投影カメラ
        perspective = 0,

        //! 平行投影カメラ
        orthogonal = 1,
    };


public:

  /**
  * @brief デフォルトコンストラクタ
  * @return none
  * @exception none
  **/
  camera() noexcept :
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
    camera(
        mode mode,
        vector3<Ty> pos,
        vector3<Ty> dst,
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
    camera(
        mode mode,
        vector3<Ty> pos,
        vector3<Ty> dst,
        Ty width,
        Ty height,
        Ty near,
        Ty far) noexcept :
        mode_{mode},
        pos_{pos},
        dst_{dst},
        up_{static_cast<Ty>(0), static_cast<Ty>(1), static_cast<Ty>(0)},
        left_{-width / static_cast<Ty>(2)},
        right_{width / static_cast<Ty>(2)},
        bottom_{-height / static_cast<Ty>(2)},
        top_{height / static_cast<Ty>(2)},
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
    camera(
        mode mode,
        vector3<Ty> pos,
        vector3<Ty> dst,
        vector3<Ty> up,
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
    camera(
        mode mode,
        vector3<Ty> pos,
        vector3<Ty> dst,
        vector3<Ty> up,
        Ty width,
        Ty height,
        Ty near,
        Ty far) noexcept :
        mode_{mode},
        pos_{pos},
        dst_{dst},
        up_{up},
        left_{-width / static_cast<Ty>(2)},
        right_{width / static_cast<Ty>(2)},
        bottom_{-height / static_cast<Ty>(2)},
        top_{height / static_cast<Ty>(2)},
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
    camera(
        vector3<Ty> pos,
        vector3<Ty> dst,
        vector3<Ty> up,
        Ty fovy,
        Ty aspect,
        Ty near,
        Ty far) noexcept :
        mode_{mode::perspective},
        pos_{pos},
        dst_{dst},
        up_{up},
        left_{},
        right_{},
        bottom_{},
        top_{},
        near_{near},
        far_{far} {
            Ty width = (near / std::tan(fovy / static_cast<Ty>(2))) / static_cast<Ty>(2);
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
    camera(const camera<Ty> &c) noexcept :
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
    camera& operator = (const camera<Ty> &c) noexcept {
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
    void set_mode(mode mode) noexcept {mode_ = mode;}

    /**
    * @brief カメラの位置を設定します
    * @param[in] pos カメラの位置
    * @return none
    * @exception none
    **/
    void set_pos(vector3<Ty> pos) noexcept {pos_ = pos;}

    /**
    * @brief カメラの注視点を設定します
    * @param[in] pos カメラの注視点
    * @return none
    * @exception none
    **/
    void set_dst(vector3<Ty> dst) noexcept {dst_ = dst;}

    /**
    * @brief カメラの上方を設定します
    * @param[in] pos カメラの上方
    * @return none
    * @exception none
    **/
    void set_up(vector3<Ty> up) noexcept {up_ = up;}

    /**
    * @brief 視錐台の左端を設定します
    * @param[in] left 視錐台の左端
    * @return none
    * @exception none
    **/
    void set_left(Ty left) noexcept {left_ = left;}

    /**
    * @brief 視錐台の右端を設定します
    * @param[in] right 視錐台の右端
    * @return none
    * @exception none
    **/
    void set_right(Ty right) noexcept {right_ = right;}

    /**
    * @brief 視錐台の下端を設定します
    * @param[in] bottom 視錐台の下端
    * @return none
    * @exception none
    **/
    void set_bottom(Ty bottom) noexcept {bottom_ = bottom;}

    /**
    * @brief 視錐台の上端を設定します
    * @param[in] top 視錐台の上端
    * @return none
    * @exception none
    **/
    void set_top(Ty top) noexcept {top_ = top;}

    /**
    * @brief 近くのクリップ面の奥行きを設定します
    * @param[in] near クリップ面の奥行き
    * @return none
    * @exception none
    **/
    void set_near(Ty near) noexcept {near_ = near;}

    /**
    * @brief 遠くのクリップ面の奥行きを設定します
    * @param[in] far クリップ面の奥行き
    * @return none
    * @exception none
    **/
    void set_far(Ty far) noexcept{far_ = far;}

    /**
    * @brief 視錐台の幅を設定します
    * @param[in] width 幅
    * @return none
    * @exception none
    **/
    void set_width(Ty width) noexcept {
        left_   = -width / static_cast<Ty>(2);
        right_  =  width / static_cast<Ty>(2);
    }

    /**
    * @brief 視錐台の高さを設定します
    * @param[in] height 高さ
    * @return none
    * @exception none
    **/
    void set_height(Ty height) noexcept {
        top_    = height / static_cast<Ty>(2);
        bottom_ = height / static_cast<Ty>(2);
    }

    /**
    * @brief クリップ面の奥行きを設定します
    * @param[in] near 近くのクリップ面の奥行き
    * @param[in] far 遠くのクリップ面の奥行き
    * @return none
    * @exception none
    **/
    void set_near_far(Ty near, Ty far) noexcept {
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
    void set_rect(Ty left, Ty right, Ty bottom, Ty top) noexcept {
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
    mode get_mode() const noexcept {return mode_;}

    /**
    * @brief カメラの位置を取得します
    * @return カメラの位置
    * @exception none
    **/
    vector3<Ty> get_pos() const noexcept {return pos_;}

    /**
    * @brief カメラの注視点を取得します
    * @return 注視点
    * @exception none
    **/
    vector3<Ty> get_dst() const noexcept {return dst_;}

    /**
    * @brief カメラの上方ベクトルを取得します
    * @return 上方ベクトル
    * @exception none
    **/
    vector3<Ty> get_up() const noexcept {return up_;}

    /**
    * @brief カメラの視錐台の左端を取得します
    * @return 視錐台の左端
    * @exception none
    **/
    Ty get_left() const noexcept{return left_;}

    /**
    * @brief カメラの視錐台の右端を取得します
    * @return 視錐台の右端
    * @exception none
    **/
    Ty get_right() const noexcept {return right_;}

    /**
    * @brief カメラの視錐台の下端を取得します
    * @return 視錐台の下端
    * @exception none
    **/
    Ty get_bottom() const noexcept {return bottom_;}

    /**
    * @brief カメラの視錐台の上端を取得します
    * @return 視錐台の上端
    * @exception none
    **/
    Ty get_top() const noexcept {return top_;}

    /**
    * @brief 近くのクリップ面の奥行きを取得します
    * @return 近くのクリップ面の奥行き
    * @exception none
    **/
    Ty get_near() const noexcept {return near_;}

    /**
    * @brief 遠くのクリップ面の奥行きを取得します
    * @return 遠くのクリップ面の奥行き
    * @exception none
    **/
    Ty get_far() const noexcept {return far_;}
    
    /**
    * @brief 視錐台の幅を取得します
    * @return 視錐台の幅
    * @exception none
    **/
    Ty get_width() const noexcept {return right_ - left_;}

    /**
    * @brief 視錐台の高さを取得します
    * @return 視錐台の高さ
    * @exception none
    **/
    Ty get_height() const noexcept {return top_ - bottom_;}


private:
    mode        mode_;      //! カメラの投影モード
    vector3<Ty> pos_;       //! カメラの位置
    vector3<Ty> dst_;       //! カメラの注視点
    vector3<Ty> up_;        //! カメラの上方ベクトル
    Ty          left_;      //! 視錐台の左端
    Ty          right_;     //! 視錐台の右端
    Ty          bottom_;    //! 視錐台の下端
    Ty          top_;       //! 視錐台の上端
    Ty          near_;      //! 近くのクリップ面の奥行き
    Ty          far_;       //! 遠くのクリップ面の奥行き
};



namespace row_major {
namespace right_hand {
namespace {
template <class Ty>
constexpr matrix4x4<Ty>(*projection_func[])(Ty, Ty, Ty, Ty) noexcept {perspective, orthogonal};
}

template <class Ty>
matrix4x4<Ty> projection(camera<Ty> c) noexcept {
    return projection_func<Ty>[(int)c.mode()](c.width(), c.height(), c.near(), c.far());
}

template <class Ty>
matrix4x4<Ty> view(camera<Ty> c) noexcept {
    return look_at(c.pos(), c.dst(), c.up());
}

template <class Ty>
matrix4x4<Ty> to_matrix(camera<Ty> c) noexcept {
    return view(c) * projection(c);
}


template <class Ty>
matrix4x4<Ty> operator * (camera<Ty> c, matrix4x4<Ty> m) noexcept {
    return to_matrix(c) * m;
}


template <class Ty>
matrix4x4<Ty> operator * (matrix4x4<Ty> m, camera<Ty> c) noexcept {
    return m * to_matrix(c);
}


template <class Ty>
vector3<Ty> operator * (vector3<Ty> v, camera<Ty> c) noexcept {
	return to_matrix(c) * v;
}

}// namespace right_hand



namespace left_hand {
namespace {
template <class Ty>
constexpr matrix4x4<Ty>(*projection_func[])(Ty, Ty, Ty, Ty) noexcept {perspective, orthogonal};
}

template <class Ty>
matrix4x4<Ty> projection(camera<Ty> c) noexcept {
    return projection_func<Ty>[(int)c.get_mode()](c.get_width(), c.get_height(), c.get_near(), c.get_far());
}

template <class Ty>
matrix4x4<Ty> view(camera<Ty> c) noexcept {
    return look_at(c.get_pos(), c.get_dst(), c.get_up());
}

template <class Ty>
matrix4x4<Ty> to_matrix(camera<Ty> c) noexcept {
	return view(c) * projection(c);
}


template <class Ty>
matrix4x4<Ty> operator * (camera<Ty> c, matrix4x4<Ty> m) noexcept {
    return to_matrix(c) * m;
}


template <class Ty>
matrix4x4<Ty> operator * (matrix4x4<Ty> m, camera<Ty> c) noexcept {
    return m * to_matrix(c);
}


template <class Ty>
vector3<Ty> operator * (vector3<Ty> v, camera<Ty> c) noexcept {
    return to_matrix(c) * v;
}

} // namespace left_hand
} // namespace row_major






namespace column_major {
namespace right_hand {
namespace {
template <class Ty>
constexpr matrix4x4<Ty>(*projection_func[])(Ty, Ty, Ty, Ty) noexcept {perspective, orthogonal};
}

template <class Ty>
matrix4x4<Ty> projection(camera<Ty> c) noexcept {
	/*return
		c.mode() == camera<Ty>::mode::PERSPECTIVE ?
		perspective(c.width(), c.height(), c.near(), c.far()):
		orthogonal(c.width(), c.height(), c.near(), c.far());*/
    return projection_func<Ty>[(int)c.get_mode()](c.get_width(), c.get_height(), c.get_near(), c.get_far());
}

template <class Ty>
matrix4x4<Ty> view(camera<Ty> c) noexcept {
    return look_at(c.get_pos(), c.get_dst(), c.get_up());
}

template <class Ty>
matrix4x4<Ty> to_matrix(camera<Ty> c) noexcept {
    return projection(c) * view(c);
}

template <class Ty>
matrix4x4<Ty> operator * (camera<Ty> c, matrix4x4<Ty> m) noexcept {
    return to_matrix(c) * m;
}


template <class Ty>
matrix4x4<Ty> operator * (matrix4x4<Ty> m, camera<Ty> c) noexcept {
    return m * to_matrix(c);
}


template <class Ty>
vector3<Ty> operator * (camera<Ty> c, vector3<Ty> v) noexcept {
    return to_matrix(c) * v;
}

} // namespace right_hand



namespace left_hand {
namespace {
template <class Ty>
constexpr matrix4x4<Ty>(*projection_func[])(Ty, Ty, Ty, Ty) noexcept {perspective, orthogonal};
}

template <class Ty>
matrix4x4<Ty> projection(camera<Ty> c) noexcept {
    return projection_func<Ty>[(int)c.get_mode()](c.get_width(), c.get_height(), c.get_near(), c.get_far());
}

template <class Ty>
matrix4x4<Ty> view(camera<Ty> c) noexcept {
    return look_at(c.get_pos(), c.get_dst(), c.get_up());
}

template <class Ty>
matrix4x4<Ty> to_matrix(camera<Ty> c) noexcept {
    return projection(c) * view(c);
}


template <class Ty>
matrix4x4<Ty> operator * (camera<Ty> c, matrix4x4<Ty> m) noexcept {
    return to_matrix(c) * m;
}


template <class Ty>
matrix4x4<Ty> operator * (matrix4x4<Ty> m, camera<Ty> c) noexcept {
    return m * to_matrix(c);
}


template <class Ty>
vector3<Ty> operator * (camera<Ty> c, vector3<Ty> v) noexcept {
    return to_matrix(c) * v;
}

} // namespace left_hand
} // namespavce column_major
} // namespace gdv

#endif

