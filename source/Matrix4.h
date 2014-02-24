#ifndef MATRIX4_H
#define MATRIX4_H

#include <iostream>
#include "Vector4.h"

class Matrix4 {
	public:
		Matrix4();
		
		static Matrix4 GetIdentity();
		static Matrix4 GetScale(float sx, float sy, float sz);
		static Matrix4 GetTranslate(float dx, float dy, float dz);
		static Matrix4 GetRotateAroundX(float degrees);
		static Matrix4 GetRotateAroundY(float degrees);
		static Matrix4 GetRotateAroundZ(float degrees);

		/**
		 @param axis Assume normalized!
		 */
		static Matrix4 GetRotate(float degrees, const Vector4& axis);
		static Matrix4 GetRotate(const Vector4& from, const Vector4& to);

		static Matrix4 GetOrtho(float l, float r, float b, float t, float n, float f);
		static Matrix4 GetPerspective(float fovy, float aspect_ration, float n, float f);
		
		float& operator()(int r, int c);
		const float& operator()(int r, int c) const;
		
		Vector4 operator*(const Vector4& v) const;
		Matrix4 operator*(const Matrix4& m) const;

	private:
		float data[16];
};

std::ostream& operator<<(std::ostream& out, const Matrix4& v);     
#endif
