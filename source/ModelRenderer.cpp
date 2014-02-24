#include "ModelRenderer.h"

namespace td {

void ModelRenderer::OnDraw() {
	BaseRenderer::OnDraw();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	xform = camera.GetViewMatrix();

	program->Bind();
	GLint location = program->GetUniformLocation("xform");
	// Matrix4 pushedXform = push * xform;
	glUniformMatrix4fv(location, 1, GL_FALSE, &xform(0, 0));
	mesh->Bind();
	mesh->DrawIndexed(GL_TRIANGLES);
	mesh->Unbind();
	program->Unbind();
}

void ModelRenderer::OnInitialize() {
	BaseRenderer::OnInitialize();
	
	//Absolute path
	attributes = ObjUtilities::GetMesh("H:/CS455/Objects/die_cube.obj");

	program = td::ShaderProgram::FromFiles(SHADERS_DIR "/cel.vert.glsl",
										   SHADERS_DIR "/cel.frag.glsl");
	
	mesh = new td::VertexArray(*program, *attributes);
	
	camera.LookAt(Vector4(0.0f, 0.0f, 1.0f, 0.0f),
				  Vector4(0.0f, 0.0f, 0.0f, 0.0f),
				  Vector4(0.0f, 1.0f, 0.0f, 0.0f));

	xform = camera.GetViewMatrix();

	// Push object down the z axis 3 units to get away from the camera
	// (because the object is centered around the origin, which is the position of the eye)
	//push = Matrix4::GetTranslate(0.0f, 0.0f, -3.0f);
	//xform = Matrix4::GetIdentity();

	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

void ModelRenderer::OnLeftMouseDragged(int x, int y) {
	Vector4 aft = MapPixelToUnitSphere(x, y);
	
	float theta = acos(fore.Dot(aft));
	
	if(fabs(theta) > 0.0001f) {
		Vector4 axis = fore.Cross(aft);
		axis.Normalize();
		
		Matrix4 rotation = Matrix4::GetRotate(theta * 180.0f / td::PI, axis);
		xform = rotation * xform;
	}

	fore = aft;
}

Vector4 ModelRenderer::MapPixelToUnitSphere(int x, int y) const {
	Vector4 mouse_in_pixels(x, y, 0.0f, 1.0f);
	Vector4 mouse_on_sphere = Matrix4::GetTranslate(-1, -1, 0.0f)
							  * Matrix4::GetScale(2.0f / GetWidth(),
												  2.0f / GetHeight(), 1.0f)
							  * mouse_in_pixels;
	float z_squared = 1.0f - mouse_on_sphere[0] * mouse_on_sphere[0] - mouse_on_sphere[1] * mouse_on_sphere[1];
	float z;
	if (z_squared > 0.0f) {
		z = sqrtf(z_squared);
	} else {
		z = 0.0f;
	}
	
	mouse_on_sphere[2] = z;
	mouse_on_sphere[3] = 0.0f;
	mouse_on_sphere.Normalize();
	
	return mouse_on_sphere;
}

void ModelRenderer::OnLeftMouseDown(int x, int y) {
	fore = MapPixelToUnitSphere(x, y);
}

void ModelRenderer::OnKey(td::Keys::key_t key) {
	/*
	if(key == td::Keys::UP) {
		xform = Matrix4::GetRotateAroundX(-5.0f) * xform;
	} else if(key == td::Keys::DOWN) {
		xform = Matrix4::GetRotateAroundX(5.0f) * xform;
	} else if(key == td::Keys::LEFT) {
		xform = Matrix4::GetRotateAroundY(-5.0f) * xform;
	} else if(key == td::Keys::RIGHT) {
		xform = Matrix4::GetRotateAroundY(5.0f) * xform;
	}
	*/

	if(key == td::Keys::UP) {
		camera.AdvanceFreely(1.0f);
	} else if(key == td::Keys::DOWN) {
		camera.AdvanceFreely(-1.0f);
	} else if(key == td::Keys::LEFT) {
		camera.StrafeFreely(-1.0f);
	} else if(key == td::Keys::RIGHT) {
		camera.StrafeFreely(1.0f);
	} else if(key == 'a') {
		camera.Yaw(3.0f);
	} else if(key == 'd') {
		camera.Yaw(-3.0f);
	}

	//Matrix4 offset = Matrix4::GetTranslate(3.0f, 0.0f, 0.0f) *
	//				 xform *
	//				 Matrix4::GetTranslate(-3.0f, 0.0f, 0.0f);
}

void ModelRenderer::OnSizeChanged(int width, int height) {
	BaseRenderer::OnSizeChanged(width, height);
	
	// Play with values for field of view
	Matrix4 projection = Matrix4::GetPerspective(45.0f, GetAspectRatio(), 0.01f, 1000.0f);
	
	/*
	width_object = 5.0f;
	float height_object = 5.0f;

	if(GetAspectRatio() >= 1.0f) {
		width_object = height_object * GetAspectRatio();
	} else {
		height_object = width_object / GetAspectRatio();
	}

	projection = Matrix4::GetOrtho(-width_object, width_object, -height_object, height_object, -5.0f, 5.0f);
	*/
	
	program->Bind();
	GLint location = program->GetUniformLocation("projection");
	glUniformMatrix4fv(location, 1, GL_FALSE, &projection(0, 0));
	program->Unbind();

}

void ModelRenderer::OnRightMouseDown(int x, int y) {

}

void ModelRenderer::OnRightMouseDragged(int x, int y) {
	Vector4 light_pos = MapPixelToUnitSphere(x, y);
	program->Bind();
	GLint location = program->GetUniformLocation("light_position");
	glUniform4fv(location, 1, &light_pos[0]);
	program->Unbind();
}


}
