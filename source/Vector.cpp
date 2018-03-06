#include "gdv/Math/Vector.h"

namespace gdv {
namespace simd {

Vector::Vector() :
	v{} {}



Vector::Vector(const Vector &v) :
	v{v.v} {
}



Vector::Vector(float x, float y, float z, float w) :
	v{} {
	alignas(alignof(__m128)) float vec[] = {x, y, z, w};
	v = _mm_load_ps(vec);
}



Vector::Vector(Vector3<float> vec) :
	v{} {
	alignas(alignof(__m128)) float f4[] = {vec.x, vec.y, vec.z, 1.0f};
	this->v = _mm_load_ps(f4);
}



Vector::Vector(Vector3<float> vec, float w) :
	v{} {
	alignas(alignof(__m128)) float f4[] = {vec.x, vec.y, vec.z, w};
	this->v = _mm_load_ps(f4);
}



Vector::Vector(Vector4<float> vec) :
	v{} {
	alignas(alignof(__m128)) float f4[] = {vec.x, vec.y, vec.z, vec.w};
	v = _mm_load_ps(f4);

}



Vector::Vector(__m128 vec) :
	v{vec} {
}



Vector& Vector::operator = (Vector3<float> vec) {
	alignas(alignof(__m128)) float f4[] = {vec.x, vec.y, vec.z, 1.0f};
	v = _mm_load_ps(f4);
	return *this;
}



Vector& Vector::operator = (Vector4<float> vec) {
	alignas(alignof(__m128)) float f4[] = {vec.x, vec.y, vec.z, vec.w};
	v = _mm_load_ps(f4);
	return *this;
}



Vector& Vector::operator = (const Vector &vec) {
	v = vec.v;
	return *this;
}


Vector::operator Vector3<float>() {
	alignas(alignof(__m128)) float vec[4]{};
	_mm_store_ps(vec, v);
	return {vec[0], vec[1], vec[2]};
}



Vector::operator Vector4<float>() {
	alignas(alignof(__m128)) float vec[4]{};
	_mm_store_ps(vec, v);
	return {vec[0], vec[1], vec[2], vec[3]};
}



Vector operator + (Vector &v, float n) {
	return {_mm_add_ps(v.v, _mm_set_ps1(n))};
}



Vector operator - (Vector &v, float n) {
	return {_mm_sub_ps(v.v, _mm_set_ps1(n))};
}



Vector operator * (Vector &v, float n) {
	return {_mm_mul_ps(v.v, _mm_set_ps1(n))};
}



Vector operator / (Vector &v, float n) {
	return {_mm_div_ps(v.v, _mm_set_ps1(n))};
}



Vector& operator += (Vector &v, float n) {
	v.v = _mm_add_ps(v.v, _mm_set_ps1(n));
	return v;
}



Vector& operator -= (Vector &v, float n) {
	v.v = _mm_sub_ps(v.v, _mm_set_ps1(n));
	return v;
}



Vector& operator *= (Vector &v, float n) {
	v.v = _mm_mul_ps(v.v, _mm_set_ps1(n));
	return v;
}



Vector& operator /= (Vector &v, float n) {
	v.v = _mm_div_ps(v.v, _mm_set_ps1(n));
	return v;
}


Vector operator + (Vector &v1, Vector &v2) {
	return {_mm_add_ps(v1.v, v2.v)};
}



Vector operator - (Vector &v1, Vector &v2) {
	return {_mm_sub_ps(v1.v, v2.v)};
}



Vector operator * (Vector &v1, Vector &v2) {
	return {_mm_mul_ps(v1.v, v2.v)};
}



Vector operator / (Vector &v1, Vector &v2) {
	return {_mm_div_ps(v1.v, v2.v)};
}



Vector& operator += (Vector &v1, Vector &v2) {
	v1 = _mm_add_ps(v1.v, v2.v);
	return v1;
}



Vector& operator -= (Vector &v1, Vector &v2) {
	v1 = _mm_sub_ps(v1.v, v2.v);
	return v1;
}



Vector& operator *= (Vector &v1, Vector &v2) {
	v1 = _mm_mul_ps(v1.v, v2.v);
	return v1;
}



Vector& operator /= (Vector &v1, Vector &v2) {
	v1 = _mm_div_ps(v1.v, v2.v);
	return v1;
}


} // namespace simd;
} // namespace gdv
