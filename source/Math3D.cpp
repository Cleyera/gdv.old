#include <math.h>
#include "gdv/Math/Math3D.h"

namespace gdv {


Mat4 UnitMatrix() noexcept {
    return {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };
}


Mat4 Transpose(const Mat4 &m) noexcept {
    return {
        m.m[0], m.m[4], m.m[ 8], m.m[12],
        m.m[1], m.m[5], m.m[ 9], m.m[13],
        m.m[2], m.m[6], m.m[10], m.m[14],
        m.m[3], m.m[7], m.m[11], m.m[15],
    };
}


Mat3 Transpose(const Mat3 &m) noexcept {
    return {
        m.m[0], m.m[3], m.m[6],
        m.m[1], m.m[4], m.m[7],
        m.m[2], m.m[5], m.m[8],
    };
}


//OpenGL
namespace ColumnMajor {


Mat4 Scaling(float x, float y, float z) noexcept {
    return {
           x, 0.0f, 0.0f, 0.0f,
        0.0f,    y, 0.0f, 0.0f,
        0.0f, 0.0f,    z, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}


Mat4 Translation(float x, float y, float z) noexcept {
    return {
        1.0f, 0.0f, 0.0f,    x,
        0.0f, 1.0f, 0.0f,    y,
        0.0f, 0.0f, 1.0f,    z,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}


Mat4 RotationX(float radians) noexcept {
    float s = sinf(radians);
    float c = cosf(radians);
    return {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f,    c,   -s, 0.0f,
        0.0f,    s,    c, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}



Mat4 RotationY(float radians) noexcept {
    float s = sinf(radians);
    float c = cosf(radians);
    return {
           c, 0.0f,    s, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
          -s, 0.0f,    c, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}


Mat4 RotationZ(float radians) noexcept {
    float s = sinf(radians);
    float c = cosf(radians);
    return {
           c,   -s, 0.0f, 0.0f,
           s,    c, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}


Mat4 Rotation(Vec3 axis, float angle) noexcept {
    axis = Normalize(axis);
    float c = cosf(angle);
    float s = sinf(angle);
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    return {
        x * x * (1 - c) + c,     x * y * (1 - c) + z * s, x * z * (1 - c) - y * s, 0.0f,
        x * y * (1 - c) - z * s, y * y * (1 - c) + c,     y * z * (1 - c) + x * s, 0.0f,
        x * z * (1 - c) + y * s, y * z * (1 - c) - x * s, z * z * (1 - c) + c,     0.0f,
                           0.0f,                    0.0f,                0.0f,     1.0f
    };
}


namespace RH {

Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept {
    Vec3 z = Normalize(pos - dst);
    Vec3 x = Normalize(Cross(up, z));
    Vec3 y = Cross(z, x);
    return{
        x.x, y.x, z.x, -Dot(pos, x),
        x.y, y.y, z.y, -Dot(pos, y),
        x.z, y.z, z.z, -Dot(pos, z),
        0.0f, 0.0f, 0.0f, 1.0f
    };
}


Mat4 Orthogonal(float left, float right, float top, float bottom, float near, float far) noexcept {
    return {
        2.0f / (right - left), 0.0f, 0.0f, (right + left) / (left - right),
        0.0f, 2.0f / (top - bottom), 0.0f, (top + bottom) / (bottom - top),
        0.0f, 0.0f, 1.0f / (near - far), 1.0f / (near - far),
        0.0f, 0.0f, 0.0f, 1.0f,
    };
}

Mat4 Orthogonal(float width, float height, float near, float far) noexcept {
    return {
        2.0f / width, 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f / height, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f / (near - far), 1.0f / (near - far),
        0.0f, 0.0f, 0.0f, 1.0f,
    };
}


Mat4 Perspective(float left, float right, float top, float bottom, float near, float far) noexcept {
    return {
        2.0f * near / (right - left), 0.0f, (right + left) / (right - left), 0.0f,
        0.0f, 2.0f * near / (bottom - top), (bottom + top) / (bottom - top), 0.0f,
        0.0f, 0.0f, far / (near - far), far * near / (near - far),
        0.0f, 0.0f, -1.0f, 0.0f,
    };
}


Mat4 Perspective(float width, float height, float near, float far) noexcept {
    return {
        2.0f * near / width, 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f * near / height, 0.0f, 0.0f,
        0.0f, 0.0f, far / (near - far), far * near / (near - far),
        0.0f, 0.0f, -1.0f, 0.0f,
    };
}

Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept {
    float f = (float)(1.0 / tan(angle / 2.0));
    return {
        f / aspect, 0.0f, 0.0f, 0.0f,
        0.0f, f, 0.0f, 0.0f,
        0.0f, 0.0f, far / (near - far), far * near / (near - far),
        0.0f, 0.0f, -1.0f, 0.0f,
    };
}
}



namespace LH {

Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept {
    Vec3 z = Normalize(dst - pos);
    Vec3 x = Normalize(Cross(up, z));
    Vec3 y = Cross(z, x);
    return{
        x.x, y.x, z.x, -Dot(pos, x),
        x.y, y.y, z.y, -Dot(pos, y),
        x.z, y.z, z.z, -Dot(pos, z),
        0.0f, 0.0f, 0.0f, 1.0f
    };
}


Mat4 Orthogonal(float left, float right, float top, float bottom, float near, float far) noexcept {
    return {
        2.0f / (right - left), 0.0f, 0.0f, (right + left) / (left - right),
        0.0f, 2.0f / (top - bottom), 0.0f, (top + bottom) / (bottom - top),
        0.0f, 0.0f, 1.0f / (far - near), 1.0f / (near - far),
        0.0f, 0.0f, 0.0f, 1.0f,
    };
}

Mat4 Orthogonal(float width, float height, float near, float far) noexcept {
    return {
        2.0f / width, 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f / height, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f / (far - near), 1.0f / (near - far),
        0.0f, 0.0f, 0.0f, 1.0f,
    };
}



Mat4 Perspective(float left, float right, float top, float bottom, float near, float far) noexcept {
    return {
        2.0f * near / (right - left), 0.0f, (right + left) / (left - right), 0.0f,
        0.0f, 2.0f * near / (bottom - top), (bottom + top) / (top - bottom), 0.0f,
        0.0f, 0.0f, far / (far - near), far * near / (near - far),
        0.0f, 0.0f, 1.0f, 0.0f,
    };
}


Mat4 Perspective(float width, float height, float near, float far) noexcept {
    return {
        2.0f * near / width, 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f * near / height, 0.0f, 0.0f,
        0.0f, 0.0f, far / (far - near), far * near / (near - far),
        0.0f, 0.0f, 1.0f, 0.0f,
    };
}

Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept {
    float f = (float)(1.0 / tan(angle / 2.0));
    return {
        f / aspect, 0.0f, 0.0f, 0.0f,
        0.0f, f, 0.0f, 0.0f,
        0.0f, 0.0f, far / (far - near), far * near / (near - far),
        0.0f, 0.0f, 1.0f, 0.0f,
    };
}

}
}




//DirectX
namespace RowMajor {



Mat4 Scaling(float x, float y, float z) noexcept {
    return {
           x, 0.0f, 0.0f, 0.0f,
        0.0f,    y, 0.0f, 0.0f,
        0.0f, 0.0f,    z, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}



Mat4 Translation(float x, float y, float z) noexcept {
    return{
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
           x,    y,    z, 1.0f
    };
}



Mat4 RotationX(float radians) noexcept {
    float s = sinf(radians);
    float c = cosf(radians);
    return {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f,    c,    s, 0.0f,
        0.0f,   -s,    c, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}



Mat4 RotationY(float radians) noexcept {
    float s = sinf(radians);
    float c = cosf(radians);
    return {
           c, 0.0f,   -s, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
           s, 0.0f,    c, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}


Mat4 RotationZ(float radians) noexcept {
    float s = sinf(radians);
    float c = cosf(radians);
    return {
           c,    s, 0.0f, 0.0f,
          -s,    c, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
}


Mat4 Rotation(Vec3 axis, float angle) noexcept {
    axis = Normalize(axis);
    float c = cosf(angle);
    float s = sinf(angle);
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    return {
        x * x * (1 - c) + c,     x * y * (1 - c) - z * s, x * z * (1 - c) + y * s, 0.0f,
        x * y * (1 - c) + z * s, y * y * (1 - c) + c,     y * z * (1 - c) - x * s, 0.0f,
        x * z * (1 - c) - y * s, y * z * (1 - c) + x * s, z * z * (1 - c) + c,     0.0f,
        0.0f,                    0.0f,                    0.0f,                    1.0f
    };
}



namespace RH {

Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept {
    Vec3 z = Normalize(pos - dst);
    Vec3 x = Normalize(Cross(up, z));
    Vec3 y = Cross(z, x);
    return{
        x.x, x.y, x.z, 0.0f,
        y.x, y.y, y.z, 0.0f,
        z.x, z.y, z.z, 0.0f,
        -Dot(pos, x), -Dot(pos, y), -Dot(pos, z), 1.0f
    };
}

Mat4 Orthogonal(float left, float right, float top, float bottom, float near, float far) noexcept {
    return {
        2.0f / (right - left), 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f / (top - bottom), 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f / (near - far), 0.0f,
        (right + left) / (left - right), (top + bottom) / (bottom - top), 1.0f / (near - far), 1.0f,
    };
}

Mat4 Orthogonal(float width, float height, float near, float far) noexcept {
    return {
        2.0f / width, 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f / height, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f / (near - far), 0.0f,
        0.0f, 0.0f, 1.0f / (near - far), 1.0f,
    };
}


Mat4 Perspective(float left, float right, float top, float bottom, float near, float far) noexcept {
    return {
        2.0f * near / (right - left), 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f * near / (top - bottom), 0.0f, 0.0f,
        (right + left) / (right - left),(bottom + top) / (top - bottom),far / (near - far), -1.0f,
        0.0f, 0.0f, far * near / (near - far), 0.0f,
    };
}

Mat4 Perspective(float width, float height, float near, float far) noexcept {
    return {
        2.0f * near / width, 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f * near / height, 0.0f, 0.0f,
        0.0f, 0.0f, far / (near - far), -1.0f,
        0.0f, 0.0f, far * near / (near - far), 0.0f,
    };
}

Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept {
    float f = (float)(1.0 / tan(angle / 2.0));
    return {
        f / aspect, 0.0f, 0.0f, 0.0f,
        0.0f, f, 0.0f, 0.0f,
        0.0f, 0.0f, far / (near - far), -1.0f,
        0.0f, 0.0f, far * near / (near - far), 0.0f,
    };
}
}



namespace LH {

Mat4 LookAt(Vec3 pos, Vec3 dst, Vec3 up) noexcept {
    Vec3 z = Normalize(dst - pos);
    Vec3 x = Normalize(Cross(up, z));
    Vec3 y = Cross(z, x);
    return{
        x.x, x.y, x.z, 0.0f,
        y.x, y.y, y.z, 0.0f,
        z.x, z.y, z.z, 0.0f,
        -Dot(pos, x), -Dot(pos, y), -Dot(pos, z), 1.0f
    };
}

Mat4 Orthogonal(float left, float right, float top, float bottom, float near, float far) noexcept {
    return {
        2.0f / (right - left), 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f / (top - bottom), 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f / (far - near), 0.0f,
        (right + left) / (left - right), (top + bottom) / (bottom - top), 1.0f / (near - far), 1.0f,
    };
}

Mat4 Orthogonal(float width, float height, float near, float far) noexcept {
    return {
        2.0f / width, 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f / height, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f / (far - near), 0.0f,
        0.0f, 0.0f, 1.0f / (near - far), 1.0f,
    };
}


Mat4 Perspective(float left, float right, float top, float bottom, float near, float far) noexcept {
    return {
        2.0f * near / (right - left), 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f * near / (bottom - top), 0.0f, 0.0f,
        (right + left) / (left - right),(bottom + top) / (top - bottom),far / (far - near), 1.0f,
        0.0f, 0.0f, far * near / (near - far), 0.0f,
    };
}

Mat4 Perspective(float width, float height, float near, float far) noexcept {
    return {
        2.0f * near / width, 0.0f, 0.0f, 0.0f,
        0.0f, 2.0f * near / height, 0.0f, 0.0f,
        0.0f, 0.0f, far / (far - near), 1.0f,
        0.0f, 0.0f, far * near / (near - far), 0.0f,
    };
}

Mat4 PerspectiveFov(float angle, float aspect, float near, float far) noexcept {
    float f = (float)(1.0 / tan(angle / 2.0));
    return {
        f / aspect, 0.0f, 0.0f, 0.0f,
        0.0f, f, 0.0f, 0.0f,
        0.0f, 0.0f, far / (far - near), 1.0f,
        0.0f, 0.0f, far * near / (near - far), 0.0f,
    };
}

}
} // namespace LH
} // namespace gdv
