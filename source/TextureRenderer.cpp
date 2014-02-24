#include "TextureRenderer.h"


namespace td {

TextureRenderer::TextureRenderer() {
}

TextureRenderer::~TextureRenderer() {
}

void TextureRenderer::OnDraw() {
	BaseRenderer::OnDraw();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	xform = camera.GetViewMatrix();

	program->Bind();
	GLint location = program->GetUniformLocation("xform");
	glUniformMatrix4fv(location, 1, GL_FALSE, &xform(0, 0));
	mesh->Bind();
	mesh->DrawIndexed(GL_TRIANGLES);
	mesh->Unbind();
	program->Unbind();
}

void TextureRenderer::OnInitialize() {
	BaseRenderer::OnInitialize();
	
	//Absolute path
	attributes = ObjUtilities::GetMesh(OBJECTS_DIR "/die_cube.obj");
	//attributes = ObjUtilities::GetMesh(OBJECTS_DIR "/maze.obj");
	
	program = td::ShaderProgram::FromFiles(SHADERS_DIR "/textured.vert.glsl",
										   SHADERS_DIR "/textured.frag.glsl");
	
	mesh = new td::VertexArray(*program, *attributes);
	
	camera.LookAt(Vector4(0.0f, 0.0f, 1.0f, 0.0f),
				  Vector4(0.0f, 0.0f, 0.0f, 0.0f),
				  Vector4(0.0f, 1.0f, 0.0f, 0.0f));

	xform = camera.GetViewMatrix();

	// load texture into RAM
	//Image texture(OBJECTS_DIR "/blop.ppm");
	Image texture(OBJECTS_DIR "/dice.ppm");
	
	// create a texture on the CPU
	glActiveTexture(GL_TEXTURE0);
	GLuint blop_tex_id;
	glGenTextures(1, &blop_tex_id);

	// bind that texture
	glBindTexture(GL_TEXTURE_2D, blop_tex_id);

	// set some parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// upload some parameters
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.GetWidth(), 
			   texture.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, 
			   texture.GetPixels());

	program->Bind();
	program->SetUniform("image", 0);
	program->Unbind();

	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

void TextureRenderer::OnKey(td::Keys::key_t key) {

	if(key == td::Keys::UP) {
		camera.Pitch(3.0f);
	} else if(key == td::Keys::DOWN) {
		camera.Pitch(-3.0f);
	} else if(key == td::Keys::LEFT) {
		camera.Yaw(3.0f);
	} else if(key == td::Keys::RIGHT) {
		camera.Yaw(-3.0f);
	} else if(key == 'w') {
		camera.AdvanceFreely(1.0f);
	} else if(key == 's') {
		camera.AdvanceFreely(-1.0f);
	} else if(key == 'a') {
		camera.StrafeFreely(-1.0f);
	} else if(key == 'd') {
		camera.StrafeFreely(1.0f);
	} else if(key == 'F') {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	} else if(key == 'f') {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
}

void TextureRenderer::OnSizeChanged(int width, int height) {
	BaseRenderer::OnSizeChanged(width, height);
	
	// Play with values for field of view
	Matrix4 projection = Matrix4::GetPerspective(45.0f, GetAspectRatio(), 0.01f, 1000.0f);
	
	program->Bind();
	GLint location = program->GetUniformLocation("projection");
	glUniformMatrix4fv(location, 1, GL_FALSE, &projection(0, 0));
	program->Unbind();

}

}
