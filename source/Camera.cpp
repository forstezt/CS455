#include "Camera.h"

Camera::Camera() {

}

Camera::Camera(const Heightmap& heightmap, int* is_being_tossed) {
	this->heightmap = heightmap;
	this->is_being_tossed = is_being_tossed;
}

Camera::~Camera() {
}

Vector4 Camera::GetFrom() {
	return from;
}

Vector4 Camera::GetTo() {
	return to;
}

const Matrix4& Camera::GetViewMatrix() const {
	return view_matrix;
}

void Camera::Toss() {
	float center_height = heightmap.QueryHeight(heightmap.GetMapWidth() / 2, heightmap.GetMapHeight() / 2);

	Vector4 center_point = Vector4(0.0f, center_height, 0.0f, 0.0f);

	Vector4 cumulated_to = to;
	Vector4 cumulated_up = up;
	Vector4 saved_from = from;

	if(!from.Equals(center_point, 10.0f)) {

		float frames_to_animate = 50.0f;
		float total_vertical_rotation = 180.0f;
		float total_horizontal_rotation = 270.0f;

		float distance_to_center = from.GetDistanceTo(center_point);

		LookAt((from) * 0.99f, center_point, Vector4(0.0f, 1.0f, 0.0f, 0.0f));
		AdvanceOnGround(distance_to_center / frames_to_animate);
		
		cumulated_to[0] += (from[0] - saved_from[0]);
		cumulated_to[1] += (from[1] - saved_from[1]);
		cumulated_to[2] += (from[2] - saved_from[2]);
		LookAt(from, cumulated_to, cumulated_up);
		
		Pitch(total_vertical_rotation / frames_to_animate);
		Yaw(total_horizontal_rotation / frames_to_animate);

		AdvanceOnGround(distance_to_center / frames_to_animate);

	} else {
		LookAt(from, cumulated_to, cumulated_up);
		*is_being_tossed = 1;
	}

}

void Camera::StrafeOnGround(float delta) {
    right = Vector4(right[0], 0.0f, right[2], right[3]);
    right.Normalize();
    
	int map_height = heightmap.GetMapHeight();
	int map_width = heightmap.GetMapWidth();

	float height = heightmap.QueryHeight(from[0] + map_width / 2, from[2] + map_height / 2);
	if (height < 10000.0f) {
		from = from + (right * delta);
		to = to + (right * delta);

		float to_from_height_difference = to[1] - from[1];

		from = Vector4(from[0], height, from[2], from[3]);
		to = Vector4(to[0], height + to_from_height_difference, to[2], to[3]);
	
		LookAt(from, to, up);
	} else {
		*is_being_tossed = 0;
		
	}
}

void Camera::AdvanceOnGround(float delta) {
    forward = Vector4(forward[0], 0.0f, forward[2], right[3]);
    forward.Normalize();

	int map_height = heightmap.GetMapHeight();
	int map_width = heightmap.GetMapWidth();
	
	float height = heightmap.QueryHeight(from[0] + map_width / 2, from[2] + map_height / 2);
	if (height < 10000.0f) {
		from = from + (forward * delta);
		to = to + (forward * delta);
	
		float to_from_height_difference = to[1] - from[1];

		from = Vector4(from[0], height, from[2], from[3]);
		to = Vector4(to[0], height + to_from_height_difference, to[2], to[3]);
	
		LookAt(from, to, up);
	} else {
		*is_being_tossed = 0;
	}
}

void Camera::StrafeFreely(float delta) {
	from = from + (right * delta);
	to = to + (right * delta);
	LookAt(from, to, up);
}

void Camera::AdvanceFreely(float delta) {
	from = from + (forward * delta);
	to = to + (forward * delta);
	LookAt(from, to, up);
}

void Camera::Yaw(float degrees) {
	to = from + Matrix4::GetRotate(degrees, Vector4(0.0f, 1.0f, 0.0f, 0.0f)) * (to - from);
	up = Matrix4::GetRotate(degrees, Vector4(0.0f, 1.0f, 0.0f, 0.0f)) * up;
	LookAt(from, to, up);
}

void Camera::Pitch(float degrees) {
	to = from + Matrix4::GetRotate(degrees, right) * (to - from);
	up = Matrix4::GetRotate(degrees, right) * up;
	LookAt(from, to, up);
}

void Camera::LookAt(const Vector4& from,
					const Vector4& to,
					const Vector4& up) {
	
	this->from = from;
	this->to = to;
	view_matrix = Matrix4::GetIdentity();
	
	//rotation
	forward = to - from;
	forward.Normalize();
	view_matrix(2, 0) = -forward[0];
	view_matrix(2, 1) = -forward[1];
	view_matrix(2, 2) = -forward[2];
	
	right = forward.Cross(up);
	right.Normalize();
	
	//New x axis
	view_matrix(0, 0) = right[0];
	view_matrix(0, 1) = right[1];
	view_matrix(0, 2) = right[2];
	
	this->up = right.Cross(forward);
	this->up.Normalize();
	
	//New y axis
	view_matrix(1, 0) = this->up[0];
	view_matrix(1, 1) = this->up[1];
	view_matrix(1, 2) = this->up[2];
	
	//translation
	view_matrix = view_matrix * Matrix4::GetTranslate(-from[0], -from[1], -from[2]);
}
