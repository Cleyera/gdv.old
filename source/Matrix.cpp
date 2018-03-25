#include "gdv/Math/Matrix.h"
#include "gdv/Math/VectorMath3D.h"

namespace gdv {

namespace simd {


Matrix::Matrix() :
    m{}{}



Matrix::Matrix(const Matrix &mat) :
    m{mat.m[0], mat.m[1], mat.m[2], mat.m[3]}{}



Matrix::Matrix( float m11, float m12, float m13, float m14,
                float m21, float m22, float m23, float m24,
                float m31, float m32, float m33, float m34,
                float m41, float m42, float m43, float m44) :
    m{}{
    alignas(alignof(__m128)) float v1[4]{m11, m12, m13, m14};
    alignas(alignof(__m128)) float v2[4]{m21, m22, m23, m24};
    alignas(alignof(__m128)) float v3[4]{m31, m32, m33, m34};
    alignas(alignof(__m128)) float v4[4]{m41, m42, m43, m44};
    m[0] = _mm_load_ps(v1);
    m[1] = _mm_load_ps(v2);
    m[2] = _mm_load_ps(v3);
    m[3] = _mm_load_ps(v4);
}



Matrix::Matrix(Matrix4x4<float> mat) :
    m{}{
    alignas(alignof(__m128)) float v1[4]{mat.m[ 0], mat.m[ 1], mat.m[ 2], mat.m[ 3]};
    alignas(alignof(__m128)) float v2[4]{mat.m[ 4], mat.m[ 5], mat.m[ 6], mat.m[ 7]};
    alignas(alignof(__m128)) float v3[4]{mat.m[ 8], mat.m[ 9], mat.m[10], mat.m[11]};
    alignas(alignof(__m128)) float v4[4]{mat.m[12], mat.m[13], mat.m[14], mat.m[15]};
    this->m[0] = _mm_load_ps(v1);
    this->m[1] = _mm_load_ps(v2);
    this->m[2] = _mm_load_ps(v3);
    this->m[3] = _mm_load_ps(v4);
}



Matrix::Matrix(__m128 m1, __m128 m2, __m128 m3, __m128 m4) :
    m{m1, m2, m3, m4}{}


Matrix& Matrix::operator = (const Matrix4x4<float> &mat) {
    alignas(alignof(__m128)) float v1[4]{mat.m[ 0], mat.m[ 1], mat.m[ 2], mat.m[ 3]};
    alignas(alignof(__m128)) float v2[4]{mat.m[ 4], mat.m[ 5], mat.m[ 6], mat.m[ 7]};
    alignas(alignof(__m128)) float v3[4]{mat.m[ 8], mat.m[ 9], mat.m[10], mat.m[11]};
    alignas(alignof(__m128)) float v4[4]{mat.m[12], mat.m[13], mat.m[14], mat.m[15]};
    this->m[0] = _mm_load_ps(v1);
    this->m[1] = _mm_load_ps(v2);
    this->m[2] = _mm_load_ps(v3);
    this->m[3] = _mm_load_ps(v4);
    return *this;
}



Matrix& Matrix::operator = (const Matrix &mat) {
    this->m[0] = mat.m[0];
    this->m[1] = mat.m[1];
    this->m[2] = mat.m[2];
    this->m[3] = mat.m[3];
    return *this;
}



Matrix::operator Matrix4x4<float>() {
    alignas(alignof(__m128)) float v1[4]{};
    alignas(alignof(__m128)) float v2[4]{};
    alignas(alignof(__m128)) float v3[4]{};
    alignas(alignof(__m128)) float v4[4]{};
    _mm_store_ps(v1, m[0]);
    _mm_store_ps(v2, m[1]);
    _mm_store_ps(v3, m[2]);
    _mm_store_ps(v4, m[3]);
    return {
        v1[0], v1[1], v1[2], v1[3],
        v2[0], v2[1], v2[2], v2[3],
        v3[0], v3[1], v3[2], v3[3],
        v4[0], v4[1], v4[2], v4[3]
    };
}



Matrix operator + (Matrix &m, float n) {
    return {
        _mm_add_ps(m.m[0], _mm_set_ps1(n)),
        _mm_add_ps(m.m[1], _mm_set_ps1(n)),
        _mm_add_ps(m.m[2], _mm_set_ps1(n)),
        _mm_add_ps(m.m[3], _mm_set_ps1(n))
    };
}



Matrix operator - (Matrix &m, float n) {
    return {
        _mm_sub_ps(m.m[0], _mm_set_ps1(n)),
        _mm_sub_ps(m.m[1], _mm_set_ps1(n)),
        _mm_sub_ps(m.m[2], _mm_set_ps1(n)),
        _mm_sub_ps(m.m[3], _mm_set_ps1(n))
    };
}



Matrix operator * (Matrix &m, float n) {
    return {
        _mm_mul_ps(m.m[0], _mm_set_ps1(n)),
        _mm_mul_ps(m.m[1], _mm_set_ps1(n)),
        _mm_mul_ps(m.m[2], _mm_set_ps1(n)),
        _mm_mul_ps(m.m[3], _mm_set_ps1(n))
    };
}



Matrix operator / (Matrix &m, float n) {
    return {
        _mm_div_ps(m.m[0], _mm_set_ps1(n)),
        _mm_div_ps(m.m[1], _mm_set_ps1(n)),
        _mm_div_ps(m.m[2], _mm_set_ps1(n)),
        _mm_div_ps(m.m[3], _mm_set_ps1(n))
    };
}



Matrix& operator += (Matrix &m, float n) {
    m.m[0] = _mm_add_ps(m.m[0], _mm_set_ps1(n));
    m.m[1] = _mm_add_ps(m.m[1], _mm_set_ps1(n));
    m.m[2] = _mm_add_ps(m.m[2], _mm_set_ps1(n));
    m.m[3] = _mm_add_ps(m.m[3], _mm_set_ps1(n));
    return m;
}



Matrix& operator -= (Matrix &m, float n) {
    m.m[0] = _mm_sub_ps(m.m[0], _mm_set_ps1(n));
    m.m[1] = _mm_sub_ps(m.m[1], _mm_set_ps1(n));
    m.m[2] = _mm_sub_ps(m.m[2], _mm_set_ps1(n));
    m.m[3] = _mm_sub_ps(m.m[3], _mm_set_ps1(n));
    return m;
}



Matrix& operator *= (Matrix &m, float n) {
    m.m[0] = _mm_mul_ps(m.m[0], _mm_set_ps1(n));
    m.m[1] = _mm_mul_ps(m.m[1], _mm_set_ps1(n));
    m.m[2] = _mm_mul_ps(m.m[2], _mm_set_ps1(n));
    m.m[3] = _mm_mul_ps(m.m[3], _mm_set_ps1(n));
    return m;
}



Matrix& operator /= (Matrix &m, float n) {
    m.m[0] = _mm_div_ps(m.m[0], _mm_set_ps1(n));
    m.m[1] = _mm_div_ps(m.m[1], _mm_set_ps1(n));
    m.m[2] = _mm_div_ps(m.m[2], _mm_set_ps1(n));
    m.m[3] = _mm_div_ps(m.m[3], _mm_set_ps1(n));
    return m;
}



Matrix operator + (Matrix &m1, Matrix &m2) {
    return {
        _mm_add_ps(m1.m[0], m2.m[0]),
        _mm_add_ps(m1.m[1], m2.m[1]),
        _mm_add_ps(m1.m[2], m2.m[2]),
        _mm_add_ps(m1.m[3], m2.m[3])
    };
}



Matrix operator - (Matrix &m1, Matrix &m2) {
    return {
        _mm_sub_ps(m1.m[0], m2.m[0]),
        _mm_sub_ps(m1.m[1], m2.m[1]),
        _mm_sub_ps(m1.m[2], m2.m[2]),
        _mm_sub_ps(m1.m[3], m2.m[3])
    };
}



Matrix operator * (Matrix &m1, Matrix &m2) {
    Matrix m = Transpose(m2);
    Matrix _m1 = Transpose({
        _mm_mul_ps(m1.m[0], m.m[0]),
        _mm_mul_ps(m1.m[0], m.m[1]),
        _mm_mul_ps(m1.m[0], m.m[2]),
        _mm_mul_ps(m1.m[0], m.m[3])});
    Matrix _m2 = Transpose({
        _mm_mul_ps(m1.m[1], m.m[0]),
        _mm_mul_ps(m1.m[1], m.m[1]),
        _mm_mul_ps(m1.m[1], m.m[2]),
        _mm_mul_ps(m1.m[1], m.m[3])});
    Matrix _m3 = Transpose({
        _mm_mul_ps(m1.m[2], m.m[0]),
        _mm_mul_ps(m1.m[2], m.m[1]),
        _mm_mul_ps(m1.m[2], m.m[2]),
        _mm_mul_ps(m1.m[2], m.m[3])});
    Matrix _m4 = Transpose({
        _mm_mul_ps(m1.m[3], m.m[0]),
        _mm_mul_ps(m1.m[3], m.m[1]),
        _mm_mul_ps(m1.m[3], m.m[2]),
        _mm_mul_ps(m1.m[3], m.m[3])});
    return {
        _mm_add_ps(_mm_add_ps(_mm_add_ps(_m1.m[0], _m1.m[1]), _m1.m[2]), _m1.m[3]),
        _mm_add_ps(_mm_add_ps(_mm_add_ps(_m2.m[0], _m2.m[1]), _m2.m[2]), _m2.m[3]),
        _mm_add_ps(_mm_add_ps(_mm_add_ps(_m3.m[0], _m3.m[1]), _m3.m[2]), _m3.m[3]),
        _mm_add_ps(_mm_add_ps(_mm_add_ps(_m4.m[0], _m4.m[1]), _m4.m[2]), _m4.m[3]),
    };
}



Matrix& operator += (Matrix &m1, Matrix &m2) {
    m1.m[0] = _mm_add_ps(m1.m[0], m2.m[0]);
    m1.m[1] = _mm_add_ps(m1.m[1], m2.m[1]);
    m1.m[2] = _mm_add_ps(m1.m[2], m2.m[2]);
    m1.m[3] = _mm_add_ps(m1.m[3], m2.m[3]);
    return m1;
}



Matrix& operator -= (Matrix &m1, Matrix &m2) {
    m1.m[0] = _mm_sub_ps(m1.m[0], m2.m[0]);
    m1.m[1] = _mm_sub_ps(m1.m[1], m2.m[1]);
    m1.m[2] = _mm_sub_ps(m1.m[2], m2.m[2]);
    m1.m[3] = _mm_sub_ps(m1.m[3], m2.m[3]);
    return m1;
}



Matrix& operator *= (Matrix &m1, Matrix &m2) {
    Matrix m = Transpose(m2);
    Matrix _m1 = Transpose({
        _mm_mul_ps(m1.m[0], m.m[0]),
        _mm_mul_ps(m1.m[0], m.m[1]),
        _mm_mul_ps(m1.m[0], m.m[2]),
        _mm_mul_ps(m1.m[0], m.m[3])});
    Matrix _m2 = Transpose({
        _mm_mul_ps(m1.m[1], m.m[0]),
        _mm_mul_ps(m1.m[1], m.m[1]),
        _mm_mul_ps(m1.m[1], m.m[2]),
        _mm_mul_ps(m1.m[1], m.m[3])});
    Matrix _m3 = Transpose({
        _mm_mul_ps(m1.m[2], m.m[0]),
        _mm_mul_ps(m1.m[2], m.m[1]),
        _mm_mul_ps(m1.m[2], m.m[2]),
        _mm_mul_ps(m1.m[2], m.m[3])});
    Matrix _m4 = Transpose({
        _mm_mul_ps(m1.m[3], m.m[0]),
        _mm_mul_ps(m1.m[3], m.m[1]),
        _mm_mul_ps(m1.m[3], m.m[2]),
        _mm_mul_ps(m1.m[3], m.m[3])});
    m1.m[0] = _mm_add_ps(_mm_add_ps(_mm_add_ps(_m1.m[0], _m1.m[1]), _m1.m[2]), _m1.m[3]);
    m1.m[1] = _mm_add_ps(_mm_add_ps(_mm_add_ps(_m2.m[0], _m2.m[1]), _m2.m[2]), _m2.m[3]);
    m1.m[2] = _mm_add_ps(_mm_add_ps(_mm_add_ps(_m3.m[0], _m3.m[1]), _m3.m[2]), _m3.m[3]);
    m1.m[3] = _mm_add_ps(_mm_add_ps(_mm_add_ps(_m4.m[0], _m4.m[1]), _m4.m[2]), _m4.m[3]);
    return m1;
}



Vector operator * (Matrix &m, Vector &v) {
    Matrix _m = Transpose(m);
    __m128 v1 = _mm_mul_ps(_m.m[0], v.v);
    __m128 v2 = _mm_mul_ps(_m.m[1], v.v);
    __m128 v3 = _mm_mul_ps(_m.m[2], v.v);
    __m128 v4 = _mm_mul_ps(_m.m[3], v.v);
    return {_mm_add_ps(_mm_add_ps(_mm_add_ps(v1, v2), v3), v4)};
}



Vector operator * (Vector &v, Matrix &m) {
    __m128 v1 = _mm_mul_ps(m.m[0], v.v);
    __m128 v2 = _mm_mul_ps(m.m[1], v.v);
    __m128 v3 = _mm_mul_ps(m.m[2], v.v);
    __m128 v4 = _mm_mul_ps(m.m[3], v.v);
    return {_mm_add_ps(_mm_add_ps(_mm_add_ps(v1, v2), v3), v4)};
}



Vector& operator *= (Vector &v, Matrix &m) {
    __m128 v1 = _mm_mul_ps(m.m[0], v.v);
    __m128 v2 = _mm_mul_ps(m.m[1], v.v);
    __m128 v3 = _mm_mul_ps(m.m[2], v.v);
    __m128 v4 = _mm_mul_ps(m.m[3], v.v);
    v = _mm_add_ps(_mm_add_ps(_mm_add_ps(v1, v2), v3), v4);
    return v;
}



} // namespace simd;
} // namespace gdv
