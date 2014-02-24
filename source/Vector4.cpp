#include <cassert>

#include "Vector4.h"
#include "Utilities.h"

Vector4::Vector4() {

}

Vector4::Vector4(float x, float y, float z, float w) {
	xyzw[0] = x;
	xyzw[1] = y;
	xyzw[2] = z;
	xyzw[3] = w;
}


float Vector4::GetAngleBetween(const Vector4& to) const{
	return acos((*this).Dot(to)) * 180.0f / td::PI;
}

bool Vector4::Equals(const Vector4& other, float pickiness) {
	if(abs(xyzw[0] - other[0]) < pickiness && abs(xyzw[1] - other[1]) < pickiness && abs(xyzw[2] - other[2]) < pickiness && abs(xyzw[3] - other[3]) < pickiness) {
		return true;
	} else {
		return false;
	}
}

float& Vector4::operator[](int i) {
	assert(0 <= i && i <= 3);
	return xyzw[i];
}

const float& Vector4::operator[](int i) const {
	assert(0 <= i && i <= 3);
	return xyzw[i];
}

Vector4 Vector4::operator*(float scalar) const {
	return Vector4(xyzw[0] * scalar,
				   xyzw[1] * scalar,
				   xyzw[2] * scalar,
				   xyzw[3] * scalar);
}

float Vector4::Dot(const Vector4& b) const{
	return (*this)[0] * b[0] +
		   (*this)[1] * b[1] +
		   (*this)[2] * b[2] +
		   (*this)[3] * b[3];
}
 
Vector4 Vector4::operator+(const Vector4& other) const {
	return Vector4(xyzw[0] + other[0],
				   xyzw[1] + other[1],
				   xyzw[2] + other[2],
				   xyzw[3] + other[3]);
}

Vector4 Vector4::operator-(const Vector4& other) const {
	return Vector4(xyzw[0] - other[0],
				   xyzw[1] - other[1],
				   xyzw[2] - other[2],
				   xyzw[3] - other[3]);
}

float Vector4::GetLength() const {
	return sqrtf((*this)[0] * (*this)[0] + 
			     (*this)[1] * (*this)[1] +
				 (*this)[2] * (*this)[2] + 
				 (*this)[3] * (*this)[3]);
}

void Vector4::Normalize() {
	float length = GetLength();
	(*this)[0] /= length;
	(*this)[1] /= length;
	(*this)[2] /= length;
	(*this)[3] /= length;	
}

float Vector4::GetDistanceTo(const Vector4& to) const {
	return sqrtf((xyzw[0] - to[0]) * (xyzw[0] - to[0]) + 
				 (xyzw[1] - to[1]) * (xyzw[1] - to[1]) + 
				 (xyzw[2] - to[2]) * (xyzw[2] - to[2]) + 
				 (xyzw[3] - to[3]) * (xyzw[3] - to[3])); 
}

Vector4 Vector4::Cross(const Vector4& other) const {
	Vector4 cross;
	
	cross[0] = (*this)[1] * other[2] - (*this)[2] * other[1];
	cross[1] = (*this)[2] * other[0] - (*this)[0] * other[2];
	cross[2] = (*this)[0] * other[1] - (*this)[1] * other[0];
	cross[3] = 0.0f;
	
	return cross;
	
}

std::ostream& operator<<(std::ostream& out, const Vector4& v) {
	out << v[0] << " " << v[1] << " " << v[2] << " " << v[3];
	return out;
}
