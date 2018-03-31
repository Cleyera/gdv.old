#include <float.h>
#include <math.h>
#include "gdv/Math/Camera.h"
#include "gdv/Math/Math3D.h"

namespace gdv {

Camera::Camera() noexcept :
    mode_{},
    pos_{},
    dst_{},
    up_{0.0f, 1.0f, 0.0f},
    left_{},
    right_{},
    bottom_{},
    top_{},
    near_{FLT_MIN},
    far_{}{}

Camera::Camera(Mode mode, Vec3 pos, Vec3 dst, float left, float right, float bottom, float top, float near, float far) noexcept :
    mode_{mode},
    pos_{pos},
    dst_{dst},
    up_{0.0f, 1.0f, 0.0f},
    left_{left},
    right_{right},
    bottom_{bottom},
    top_{top},
    near_{near},
    far_{far}{}


Camera::Camera(Mode mode, Vec3 pos, Vec3 dst, float width, float height, float near, float far) noexcept :
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


Camera::Camera(Mode mode, Vec3 pos, Vec3 dst, Vec3 up, float left, float right, float bottom, float top, float near, float far) noexcept :
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


Camera::Camera(Mode mode, Vec3 pos, Vec3 dst, Vec3 up, float width, float height, float near, float far) noexcept :
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



Camera::Camera(Vec3 pos, Vec3 dst, Vec3 up, float fovy, float aspect, float near, float far) noexcept :
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
    float width = (float)(near / tan(fovy / 2.0)) / 2.0f;
    float height = width / aspect;
    top_	= -height;
    bottom_ =  height;
    left_	= -width;
    right_	=  width;
}



Camera::Camera(const Camera &c) noexcept :
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



Camera& Camera::operator = (const Camera &c) noexcept {
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


void Camera::SetMode(Mode mode)     noexcept {mode_ = mode;}
void Camera::SetPos(Vec3 pos)       noexcept {pos_ = pos;}
void Camera::SetDst(Vec3 dst)       noexcept {dst_ = dst;}
void Camera::SetUp(Vec3 up)         noexcept {up_ = up;}
void Camera::SetLeft(float left)    noexcept {left_ = left;}
void Camera::SetRight(float right)  noexcept {right_ = right;}
void Camera::SetBottom(float bottom)noexcept {bottom_ = bottom;}
void Camera::SetTop(float top)      noexcept {top_ = top;}
void Camera::SetNear(float near)    noexcept {near_ = near;}
void Camera::SetFar(float far)      noexcept {far_ = far;}

void Camera::SetWidth(float width) noexcept {
    left_   = -width / 2.0f;
    right_  =  width / 2.0f;
}

void Camera::SetHeight(float height) noexcept {
	top_       =  height / 2.0f;
	bottom_    = -height / 2.0f;
}

void Camera::SetNearFar(float near, float far) noexcept {
	near_  = near;
	far_   = far;
}

void Camera::SetRect(float left, float right, float bottom, float top) noexcept {
    left_      = left;
    right_     = right;
    bottom_    = bottom;
	top_       = top;
}

Camera::Mode Camera::GetMode()  const noexcept {return mode_;}
Vec3 Camera::GetPos()           const noexcept {return pos_;}
Vec3 Camera::GetDst()           const noexcept {return dst_;}
Vec3 Camera::GetUp()            const noexcept {return up_;}
float Camera::GetLeft()         const noexcept {return left_;}
float Camera::GetRight()        const noexcept {return right_;}
float Camera::GetBottom()       const noexcept {return bottom_;}
float Camera::GetTop()          const noexcept {return top_;}
float Camera::GetNear()         const noexcept {return near_;}
float Camera::GetFar()          const noexcept {return far_;}
float Camera::GetWidth()        const noexcept {return right_ - left_;}
float Camera::GetHeight()       const noexcept {return top_ - bottom_;}




namespace ColumnMajor {
namespace RH {
namespace {
constexpr Mat4(*ProjectionFunc[])(float, float, float, float) noexcept {Perspective, Orthogonal};
}

Mat4 Projection(Camera c) noexcept {
	/*return
		c.GetMode() == Camera::Mode::PERSPECTIVE ?
		Perspective(c.GetWidth(), c.GetHeight(), c.GetNear(), c.GetFar()):
		Orthogonal(c.GetWidth(), c.GetHeight(), c.GetNear(), c.GetFar());*/
    return ProjectionFunc[(int)c.GetMode()](c.GetWidth(), c.GetHeight(), c.GetNear(), c.GetFar());
}

Mat4 View(Camera c) noexcept {
    return LookAt(c.GetPos(), c.GetDst(), c.GetUp());
}

Mat4 Transform(Camera c) noexcept {
    return Projection(c) * View(c);
}

Mat4 operator * (Camera c, Mat4 m) noexcept {
    return Transform(c) * m;
}


Mat4 operator * (Mat4 m, Camera c) noexcept {
    return m * Transform(c);
}


Vec3 operator * (Camera c, Vec3 v) noexcept {
    return Transform(c) * v;
}

}// namespace RH



namespace LH {
namespace {
constexpr Mat4(*ProjectionFunc[])(float, float, float, float) noexcept {Perspective, Orthogonal};
}

Mat4 Projection(Camera c) noexcept {
    return ProjectionFunc[(int)c.GetMode()](c.GetWidth(), c.GetHeight(), c.GetNear(), c.GetFar());
}

Mat4 View(Camera c) noexcept {
    return LookAt(c.GetPos(), c.GetDst(), c.GetUp());
}

Mat4 Transform(Camera c) noexcept {
    return Projection(c) * View(c);
}


Mat4 operator * (Camera c, Mat4 m) noexcept {
    return Transform(c) * m;
}


Mat4 operator * (Mat4 m, Camera c) noexcept {
    return m * Transform(c);
}


Vec3 operator * (Camera c, Vec3 v) noexcept {
    return Transform(c) * v;
}

}//namespace LH
}//namespavce ColumnMajor




namespace RowMajor {
namespace RH {
namespace {
constexpr Mat4(*ProjectionFunc[])(float, float, float, float) noexcept {Perspective, Orthogonal};
}

Mat4 Projection(Camera c) noexcept {
    return ProjectionFunc[(int)c.GetMode()](c.GetWidth(), c.GetHeight(), c.GetNear(), c.GetFar());
}

Mat4 View(Camera c) noexcept {
    return LookAt(c.GetPos(), c.GetDst(), c.GetUp());
}

Mat4 Transform(Camera c) noexcept {
    return View(c) * Projection(c);
}


Mat4 operator * (Camera c, Mat4 m) noexcept {
    return Transform(c) * m;
}


Mat4 operator * (Mat4 m, Camera c) noexcept {
    return m * Transform(c);
}


Vec3 operator * (Vec3 v, Camera c) noexcept {
	return Transform(c) * v;
}

}// namespace RH



namespace LH {
namespace {
constexpr Mat4(*ProjectionFunc[])(float, float, float, float) noexcept {Perspective, Orthogonal};
}

Mat4 Projection(Camera c) noexcept {
    return ProjectionFunc[(int)c.GetMode()](c.GetWidth(), c.GetHeight(), c.GetNear(), c.GetFar());
}

Mat4 View(Camera c) noexcept {
    return LookAt(c.GetPos(), c.GetDst(), c.GetUp());
}

Mat4 Transform(Camera c) noexcept {
	return View(c) * Projection(c);
}


Mat4 operator * (Camera c, Mat4 m) noexcept {
    return Transform(c) * m;
}


Mat4 operator * (Mat4 m, Camera c) noexcept {
    return m * Transform(c);
}


Vec3 operator * (Vec3 v, Camera c) noexcept {
    return Transform(c) * v;
}

} // namespace LH
} // namespace RowMajor
} // namespace gdv
