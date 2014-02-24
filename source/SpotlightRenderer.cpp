#include "SpotlightRenderer.h"
#include "Image.h"

namespace td {

/* ------------------------------------------------------------------------- */

SpotlightRenderer::SpotlightRenderer() {

}

/* ------------------------------------------------------------------------- */

SpotlightRenderer::~SpotlightRenderer() {
    
}

/* ------------------------------------------------------------------------- */

void SpotlightRenderer::OnDraw() {
	BaseRenderer::OnDraw();
	
	//Set spotlight transform
	Vector4 spot_spin_axis(0.0f, -1.0f, 0.0f, 0.0f);
	spot_spin_axis.Normalize();
	spot_direction_world = Matrix4::GetRotate(0.2f, spot_spin_axis) * spot_direction_world;
	//std::cout << "spot_direction_world: " << spot_direction_world << std::endl;
	//std::cout << "spot_direction_world.GetLength(): " << spot_direction_world.GetLength() << std::endl;
	
	Matrix4 aligner = Matrix4::GetRotate(Vector4(0.0f, -1.0f, 0.0f, 0.0f),
										  spot_direction_world);

	xforms[1] = Matrix4::GetTranslate(light_position_world[0], 
									  light_position_world[1], 
									  light_position_world[2]) * aligner;

	Vector4 light_position_eye = camera.GetViewMatrix() * light_position_world;	
	Vector4 spot_direction_eye = camera.GetViewMatrix() * spot_direction_world;	
	
	//Draw Terrain
	programs[0]->Bind();	
	GLint location = programs[0]->GetUniformLocation("xform");
	glUniformMatrix4fv(location, 1, GL_FALSE, &(camera.GetViewMatrix() * xforms[0])(0,0));
	programs[0]->SetUniform("light_position_eye", light_position_eye[0], light_position_eye[1], light_position_eye[2]);
	programs[0]->SetUniform("spot_direction_eye", spot_direction_eye[0], spot_direction_eye[1], spot_direction_eye[2]);
	meshes[0]->Bind();
	meshes[0]->DrawIndexed(GL_TRIANGLES);
	meshes[0]->Unbind();
	programs[0]->Unbind();
	
	//Draw Cone
	programs[1]->Bind();
	
	location = programs[1]->GetUniformLocation("xform");
	glUniformMatrix4fv(location, 1, GL_FALSE, &(camera.GetViewMatrix() * xforms[1])(0,0));
	
	programs[1]->SetUniform("albedo", albedos[1][0], albedos[1][1], albedos[1][2]);
	meshes[1]->Bind();
	meshes[1]->DrawIndexed(GL_TRIANGLES);
	meshes[1]->Unbind();
	programs[1]->Unbind();

}

/****************************************************************************************************************************/

void SpotlightRenderer::OnInitialize() {

	BaseRenderer::OnInitialize();

	//-----------Terrain------------//
	attributes[0] = ObjUtilities::GetMesh(OBJECTS_DIR "/terrain.obj");
	programs[0] = td::ShaderProgram::FromFiles(SHADERS_DIR "/1d.vert.glsl", SHADERS_DIR "/1d.frag.glsl");	
	meshes[0] = new td::VertexArray(*programs[0], *attributes[0]);
    xforms[0] = Matrix4::GetTranslate(0.0f, -15.0f, 0.0f);
	albedos[0] = Vector4(0.1f, 0.9f, 0.1f, 1.0f);
	
	//-----------Cone------------//
	attributes[1] = ObjUtilities::GetMesh(OBJECTS_DIR "/truncone2.obj");
    programs[1] =  td::ShaderProgram::FromFiles(SHADERS_DIR "/specular.vert.glsl", SHADERS_DIR "/specular.frag.glsl");
	meshes[1] = new td::VertexArray(*programs[1], *attributes[1]);
    albedos[1] = Vector4(1.0f, 0.1f, 0.1f, 1.0f);
 
	//Set spot light's direction
	spot_direction_world = Vector4(0.2f, -1.0f, -0.2f, 0.0f);
	spot_direction_world.Normalize();
	
	//Set spot light's position
	light_position_world = Vector4(77.0f, 5.0f, -77.0f, 1.0f);
 
 
    camera.LookAt(Vector4(64.0f, 3.0f, -64.0f, 0.0f),
				  Vector4(128.0f, 3.0f, -128.0f, 0.0f),
				  Vector4(0.0f, 1.0f, 0.0f, 0.0f));

		// load texture into RAM
	Image texture(OBJECTS_DIR "/romania1D.ppm");
	
	// create a texture on the CPU
	glActiveTexture(GL_TEXTURE0);
	GLuint blop_tex_id;
	glGenTextures(1, &blop_tex_id);

	// bind that texture
	glBindTexture(GL_TEXTURE_1D, blop_tex_id);

	// set some parameters
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	//glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	//glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	//glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	//glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// upload some parameters
	glTexImage1D(GL_TEXTURE_1D, 0, GL_RGB, texture.GetWidth(), 0, GL_RGB, GL_UNSIGNED_BYTE, 
			   texture.GetPixels());

	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	

}

void SpotlightRenderer::OnSizeChanged(int width, int height) {
	BaseRenderer::OnSizeChanged(width, height);

	Matrix4 projection = Matrix4::GetPerspective(45.0f, GetAspectRatio(), 0.01f, 1000.0f);

	for (int i = 0; i < NMODELS; ++i) {
		programs[i]->Bind();
		GLint location = programs[i]->GetUniformLocation("ortho");
		glUniformMatrix4fv(location, 1, GL_FALSE, &projection(0,0));
		programs[i]->Unbind();
	}

}

void SpotlightRenderer::OnKey(td::Keys::key_t key) {
	if(key == td::Keys::UP) {
		camera.Pitch(5.0f);
	} else if(key == td::Keys::DOWN) {
		camera.Pitch(-5.0f);
	} else if(key == td::Keys::LEFT) {
		camera.Yaw(5.0f);
	} else if(key == td::Keys::RIGHT) {
		camera.Yaw(-5.0f);
	} else if(key == 'w') {
		camera.AdvanceOnGround(5.0f);
	} else if(key == 's') {
		camera.AdvanceOnGround(-5.0f);
	} else if(key == 'a') {
		camera.StrafeOnGround(-5.0f);
	} else if(key == 'd') {
		camera.StrafeOnGround(5.0f);
	} else if(key == 'F') {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	} else if(key == 'f') {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

}


}
