#ifndef CAMERA_H
#define CAMERA_H

#include "Vector4.h"
#include "Matrix4.h"
#include "Heightmap.h"

class Camera {
	public:
		Camera();
		Camera(const Heightmap& heightmap, int* is_being_tossed);
		~Camera();
		
        void LookAt(const Vector4& from,
					const Vector4& to,
					const Vector4& up);

		const Matrix4& GetViewMatrix() const;
		void AdvanceOnGround(float delta);
		void StrafeOnGround(float delta);
    	void AdvanceFreely(float delta);
		void StrafeFreely(float delta);
		void Yaw(float degrees);
		void Pitch(float degrees);
		void Toss();
		Vector4 GetFrom();
		Vector4 GetTo();

	private:
		Vector4 right;
		Vector4 forward;
		Vector4 from;
		Vector4 to;
		Vector4 up;
        		
		Matrix4 view_matrix;

        Heightmap heightmap;

		int* is_being_tossed;
};

#endif
