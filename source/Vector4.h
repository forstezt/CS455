#ifndef VECTOR4_H
#define VECTOR4_H

#include <iostream>
#include <cmath>

class Vector4 {
	public:
		Vector4();
		Vector4(float x, float y, float z, float w);
		
		float& operator[](int i);
		const float& operator[](int i) const;
		
		float Dot(const Vector4& b) const;
		Vector4 Cross(const Vector4& other) const;
		
		float GetLength() const;
		void Normalize();

		float GetDistanceTo(const Vector4& to) const;
		float GetAngleBetween(const Vector4& to) const;
		
		Vector4 operator+(const Vector4& other) const;
		Vector4 operator-(const Vector4& other) const;
		Vector4 operator*(float scalar) const;

		bool Equals(const Vector4& other, float pickiness);
		
	private:
		float xyzw[4];
};

std::ostream& operator<<(std::ostream& out, const Vector4& v);

#endif
