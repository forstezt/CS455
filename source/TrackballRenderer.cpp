#include "TrackballRenderer.h"

namespace td {

/* ------------------------------------------------------------------------- */

TrackballRenderer::TrackballRenderer() {

}

/* ------------------------------------------------------------------------- */

TrackballRenderer::~TrackballRenderer() {
}

/* ------------------------------------------------------------------------- */

void TrackballRenderer::OnDraw() {


	BaseRenderer::OnDraw();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	Vector4 direction;

	
	program->Bind();
	//GLint location = program->GetUniformLocation("rotater");
	GLint location = program->GetUniformLocation("xform");
	glUniformMatrix4fv(location, 1, GL_FALSE, &xform(0,0));
	program->SetUniform("light_position", light_position[0], light_position[1], light_position[2]);
	mesh->Bind();
	mesh->DrawIndexed(GL_TRIANGLES);
	mesh->Unbind();

	program->Unbind();


}

/****************************************************************************************************************************/

void TrackballRenderer::OnInitialize() {

	BaseRenderer::OnInitialize();

	light_position = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
	
	//Absolute path
	attributes = ObjUtilities::GetMesh(OBJECTS_DIR "/monkey.obj");
	//attributes = ObjUtilities::GetMesh(OBJECTS_DIR "/truncone2.obj");

	program = td::ShaderProgram::FromFiles(SHADERS_DIR "/toon_shading.vert.glsl", SHADERS_DIR "/toon_shading.frag.glsl");
	
	mesh = new td::VertexArray(*program, *attributes);
	
	xform = Matrix4::GetIdentity();

	program->Bind();
	//program->SetUniform("xform", xform);
	GLint location = program->GetUniformLocation("xform");
	glUniformMatrix4fv(location, 1, GL_FALSE, &xform(0,0));
	program->SetUniform("light_position", light_position[0], light_position[1], light_position[2]);
	program->Unbind();

	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

}

void TrackballRenderer::OnLeftMouseDown(int x, int y) {
	fore = MapPixelToUnitSphere(x, y);
}

void TrackballRenderer::OnRightMouseDragged(int x, int y) {
	light_position = MapPixelToUnitSphere(x, y);
	light_position[2] *= 5.0f;
}

Vector4 TrackballRenderer::MapPixelToUnitSphere(int x, int y) const {
	Vector4 mouse_in_pixels(x, y, 0.0f, 1.0f);
	Vector4 mouse_on_sphere = 
			Matrix4::GetTranslate(-1.0f, -1.0f, 0.0f) *
			Matrix4::GetScale(2.0f / GetWidth(), 2.0f / GetHeight(), 1.0f) * 
			mouse_in_pixels;
			
			
	float z_squared = 1.0f - (mouse_on_sphere[0] * mouse_on_sphere[0]) - (mouse_on_sphere[1] * mouse_on_sphere[1]);
	float z;
	if (z_squared > 0.0f) {
		z = sqrtf(z_squared);
	} else {
		z = 0.0f;
		
		//using hyperbole
		//z = (0.5f) / sqrtf((mouse_on_sphere[0] * mouse_on_sphere[0]) + (mouse_on_sphere[1] * mouse_on_sphere[1]));
	}
	
	mouse_on_sphere[2] = z;
	mouse_on_sphere[3] = 0.0f;
	mouse_on_sphere.Normalize();
	
	return mouse_on_sphere;
	
}


void TrackballRenderer::OnLeftMouseDragged(int x, int y) {
	
	Vector4 aft = MapPixelToUnitSphere(x, y);
	
	float theta = acos(fore.Dot(aft));
	
	if (fabs(theta) > 0.0001f) {
		Vector4 axis = fore.Cross(aft);
		axis.Normalize();
	
		Matrix4 rotation = Matrix4::GetRotate(theta * 180.0f / td::PI, axis);
	
		xform = rotation * xform;
	
		program->Bind();
		GLint location = program->GetUniformLocation("xform");
		glUniformMatrix4fv(location, 1, GL_FALSE, &xform(0, 0));
		program->Unbind();
	}
	
		fore = aft;
	
	
	
}

void TrackballRenderer::OnSizeChanged(int width, int height) {
	BaseRenderer::OnSizeChanged(width, height);

	float width_object = 2.0f;
	float height_object = 2.0f;

	Matrix4 projection;

	if(GetAspectRatio() >= 1.0f) {
		width_object = height_object * GetAspectRatio();
	} else {
		height_object = width_object / GetAspectRatio();
	}

	projection = Matrix4::GetOrtho(-width_object, width_object, -height_object, height_object, -2.0f, 2.0f);

	program->Bind();
	GLint location = program->GetUniformLocation("ortho");
	glUniformMatrix4fv(location, 1, GL_FALSE, &projection(0,0));
	program->Unbind();

}


}