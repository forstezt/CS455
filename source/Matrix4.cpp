#include <cassert>
#include <cmath>
#include <stdio.h>

#include "Matrix4.h"
#include "Utilities.h"

Matrix4::Matrix4() {
}

Matrix4 Matrix4::GetIdentity() {
	Matrix4 m;
	m(0, 0) = m(1, 1) = m(2, 2) = m(3, 3) = 1.0f;
	m(0, 1) = m(0, 2) = m(0, 3) =
	m(1, 0) = m(1, 2) = m(1, 3) =
	m(2, 0) = m(2, 1) = m(2, 3) =
	m(3, 0) = m(3, 1) = m(3, 2) = 0.0f;
	return m;
}

Matrix4 Matrix4::GetScale(float sx, float sy, float sz) {
	Matrix4 m = GetIdentity();
	m(0, 0) = sx;
	m(1, 1) = sy;
	m(2, 2) = sz;
	return m;
}

Matrix4 Matrix4::GetTranslate(float dx, float dy, float dz) {
	Matrix4 m = GetIdentity();
	m(0, 3) = dx;
	m(1, 3) = dy;
	m(2, 3) = dz;
	return m;
}

Matrix4 Matrix4::GetRotateAroundX(float degrees) {
	float radians = degrees * td::PI / 180.0f;
	Matrix4 m = GetIdentity();
	m(1, 1) = cos(radians);
	m(1, 2) = sin(radians);
	m(2, 1) = -sin(radians);
	m(2, 2) = cos(radians);
	return m;
}

Matrix4 Matrix4::GetRotateAroundY(float degrees) {
	float radians = degrees * td::PI / 180.0f;
	Matrix4 m = GetIdentity();
	m(0, 0) = cos(radians);
	m(0, 2) = -sin(radians);
	m(2, 0) = sin(radians);
	m(2, 2) = cos(radians);
	return m;
}

Matrix4 Matrix4::GetRotateAroundZ(float degrees) {
	float radians = degrees * td::PI / 180.0f;
	Matrix4 m = GetIdentity();
	m(0, 0) = cos(radians);
	m(0, 1) = -sin(radians);
	m(1, 0) = sin(radians);
	m(1, 1) = cos(radians);
	return m;
}

Matrix4 Matrix4::GetRotate(float degrees, const Vector4& axis /* normalized */) {
	float radians = (float) (degrees * td::PI / 180.0f);
	float sine = (float) sin(radians);
	float cosine = (float) cos(radians);
	float cos_compliment = 1.0f - cosine;

	Matrix4 m = GetIdentity();
	
	m(0, 0) = cos_compliment * axis[0] * axis[0] + cosine;
	m(0, 1) = cos_compliment * axis[0] * axis[1] - sine * axis[2];
	m(0, 2) = cos_compliment * axis[0] * axis[2] + sine * axis[1];
	
	m(1, 0) = cos_compliment * axis[1] * axis[0] + sine * axis[2];
	m(1, 1) = cos_compliment * axis[1] * axis[1] + cosine;
	m(1, 2) = cos_compliment * axis[1] * axis[2] - sine * axis[0];
	
	m(2, 0) = cos_compliment * axis[2] * axis[0] - sine * axis[1];
	m(2, 1) = cos_compliment * axis[2] * axis[1] + sine * axis[0];
	m(2, 2) = cos_compliment * axis[2] * axis[2] + cosine;
	
	return m;
}

Matrix4 Matrix4::GetRotate(const Vector4& from, const Vector4& to) {
	Vector4 axis = from.Cross(to);
	axis.Normalize();
	float degrees = from.GetAngleBetween(to);
	return GetRotate(degrees, axis);
}

Matrix4 Matrix4::GetOrtho(float l, float r, float b, float t, float n, float f) {
	Matrix4 m = GetIdentity();
	m(0, 0) = 2.0f / (r - l);
	m(1, 1) = 2.0f / (t - b);
	m(2, 2) = 2.0f / (n - f);
	m(0, 3) = -(r + l) / (r - l);
	m(1, 3) = -(t + b) / (t - b);
	m(2, 3) = -(n + f) / (n - f);
	return m;
}

Matrix4 Matrix4::GetPerspective(float fovy, float aspect_ration, float n, float f) {
	float t = n * tan(fovy / 2.0f * td::PI / 180.0f);
	float r = aspect_ration * t;

	Matrix4 m = GetIdentity();
	m(0, 0) = n / r;
	m(1, 1) = n / t;
	m(2, 2) = -(f + n) / (f - n);
	m(2, 3) = -2.0f * f * n / (f - n);
	m(3, 2) = -1.0f;
	m(3, 3) = 0.0f;

	return m;
}

float& Matrix4::operator()(int r, int c) {
	assert(0 <= r && r <= 3);
	assert(0 <= c && c <= 3);
	return data[c*4 + r];
}

const float& Matrix4::operator()(int r, int c) const {
	assert(0 <= r && r <= 3);
	assert(0 <= c && c <= 3);
	return data[c*4 + r];
}

Vector4 Matrix4::operator*(const Vector4& v) const {
	Vector4 product;
	for(int r = 0; r <= 3; r++) {
		product[r] = (*this)(r, 0) * v[0] +
					 (*this)(r, 1) * v[1] +
					 (*this)(r, 2) * v[2] +
					 (*this)(r, 3) * v[3];
	}
	return product;
}

Matrix4 Matrix4::operator*(const Matrix4& m) const {
	Matrix4 product;
	for(int r = 0; r <= 3; r++) {
		for(int c = 0; c <= 3; c++) {
			// dot row r of this with column c of m
			product(r, c) = (*this)(r, 0) * m(0, c) +
							(*this)(r, 1) * m(1, c) +
							(*this)(r, 2) * m(2, c) +
							(*this)(r, 3) * m(3, c);
		}
	}
	return product;
}

std::ostream& operator<<(std::ostream& out, const Matrix4& m) {
	for(int r = 0; r <=3; ++r) {
		for(int c = 0; c <=3; ++c) {
			out << m(r, c) << " ";
		}
		out << std::endl;
	}
	return out;
}
