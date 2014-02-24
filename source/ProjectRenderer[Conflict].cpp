#include "ProjectRenderer.h"
#include "KeyIndices.h"
#include "Image.h"

namespace td {

/* ------------------------------------------------------------------------- */

ProjectRenderer::ProjectRenderer() {

}

/* ------------------------------------------------------------------------- */

ProjectRenderer::~ProjectRenderer() {
    
}

/* ------------------------------------------------------------------------- */

void ProjectRenderer::OnDraw() {

	BaseRenderer::OnDraw();
	if(is_being_tossed == 0) {
		camera.Toss();
	} else {
		if(key_states[td::KeyStates::key_w]) { //Move forward
			camera.AdvanceOnGround(1.8f);
		} 

		if(key_states[td::KeyStates::key_s]) { //Move backward
			camera.AdvanceOnGround(-1.8f);
		} 

		if(key_states[td::KeyStates::key_a]) { //Strafe left
			camera.StrafeOnGround(-1.8f);
		} 

		if(key_states[td::KeyStates::key_d]) { //Strafe right
			camera.StrafeOnGround(1.8f);
		} 

		if(key_states[td::KeyStates::key_up]) { //Pitch up
			camera.Pitch(1.8f);
		} 

		if(key_states[td::KeyStates::key_down]) { //Pitch down
			camera.Pitch(-1.8f);
		} 

		if(key_states[td::KeyStates::key_left]) { //Yaw left
			camera.Yaw(1.8f);
		} 

		if(key_states[td::KeyStates::key_right]) { //Yaw right
			camera.Yaw(-1.8f);
		} 

		if(key_states[td::KeyStates::key_f]) { //Regular mode
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		} 

		if(key_states[td::KeyStates::key_F]) { //Wire frame mode
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		} 
	}

	sunlight_position_world = Matrix4::GetRotateAroundY(0.5f) * sunlight_position_world;
	Vector4 sunlight_position_eye = camera.GetViewMatrix() * sunlight_position_world;
	//xforms2.at(24).at(0) = Matrix4::GetRotateAroundZ(0.5f) * xforms2.at(24).at(1);

    for (int i = 0; i < NMODELS; ++i) {
		programs[i]->Bind();
		
        for (int j = 0; j < xforms2.at(i).size(); ++j) {
            
	    	GLint location = programs[i]->GetUniformLocation("xform");
	    	glUniformMatrix4fv(location, 1, GL_FALSE, &(camera.GetViewMatrix() * xforms2.at(i).at(j))(0,0));

			programs[i]->SetUniform("light_position", sunlight_position_eye[0], sunlight_position_eye[1], sunlight_position_eye[2]);
            
            meshes[i]->Bind();
		    meshes[i]->DrawIndexed(GL_TRIANGLES);
		    meshes[i]->Unbind();
        }
	
        programs[i]->Unbind();
    }

}

/****************************************************************************************************************************/

void ProjectRenderer::OnInitialize() {

	BaseRenderer::OnInitialize();
    Heightmap heightmap;
	is_being_tossed = 1;

	//-----------Terrain------------//
	attributes[0] = ObjUtilities::GetMeshFromHeightmap(OBJECTS_DIR "/desert.pgm", &heightmap);
	programs[0] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");	
	meshes[0] = new td::VertexArray(*programs[0], *attributes[0]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(0).push_back(Matrix4::GetIdentity());
	albedos[0] = Vector4(238.0f / 255.0f, 230.0f / 255.0f, 133.0f / 255.0f, 1.0f);
	
	//-----------Cactus------------//
	attributes[1] = ObjUtilities::GetMesh(OBJECTS_DIR "/cactus.obj");
    programs[1] =  td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");
	meshes[1] = new td::VertexArray(*programs[1], *attributes[1]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(1).push_back(Matrix4::GetTranslate(200.0f, -31.0f, -200.0f) * Matrix4::GetScale(3.0f, 3.0f, 3.0f));
    xforms2.at(1).push_back(Matrix4::GetTranslate(155.0f, -31.0f, -70.0f) * Matrix4::GetScale(5.0f, 5.0f, 5.0f));
    xforms2.at(1).push_back(Matrix4::GetTranslate(143.0f, -27.0f, -85.0f) * Matrix4::GetRotateAroundY(45.0f) * Matrix4::GetScale(4.0f, 4.0f, 4.0f));
    xforms2.at(1).push_back(Matrix4::GetTranslate(43.0f, -8.0f, 50.0f) * Matrix4::GetScale(4.0f, 4.0f, 4.0f));
    albedos[1] = Vector4(0.0f, 0.7f, 0.0f, 1.0f);

	//-----------Camel------------//
	attributes[2] = ObjUtilities::GetMesh(OBJECTS_DIR "/camel.obj");
	programs[2] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl"); 	
	meshes[2] = new td::VertexArray(*programs[2], *attributes[2]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(2).push_back(Matrix4::GetTranslate(-30.0f, -19.5f, 149.0f) * Matrix4::GetRotateAroundY(70.0f) * Matrix4::GetScale(8.0f, 8.0f, 8.0f));
    albedos[2] = Vector4(218.0f / 255.0f, 210.0f / 255.0f, 113.0f / 255.0f, 1.0f);

	//-----------Bone------------//
	attributes[3] = ObjUtilities::GetMesh(OBJECTS_DIR "/bone.obj");
	programs[3] = td::ShaderProgram::FromFiles(SHADERS_DIR "/specular.vert.glsl", SHADERS_DIR "/specular.frag.glsl");	
	meshes[3] = new td::VertexArray(*programs[3], *attributes[3]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(3).push_back(Matrix4::GetTranslate(141.0f, -33.0f, -50.0) * Matrix4::GetRotateAroundX(32.0f) * Matrix4::GetScale(6.0f, 6.0f, 6.0f));
    xforms2.at(3).push_back(Matrix4::GetTranslate(141.0f, -30.3f, -8.0f) * Matrix4::GetRotateAroundX(-10.0f) * Matrix4::GetRotateAroundZ(-10.0f) * Matrix4::GetScale(6.0f, 6.0f, 6.0f));
    xforms2.at(3).push_back(Matrix4::GetTranslate(142.0f, -29.0f, 2.0f) * Matrix4::GetRotateAroundY(45.0f) * Matrix4::GetScale(6.0f, 6.0f, 6.0f));
    xforms2.at(3).push_back(Matrix4::GetTranslate(146.0f, -30.6f, -5.0f) * Matrix4::GetRotateAroundY(15.0f) * Matrix4::GetRotateAroundZ(-10.0f) * Matrix4::GetScale(6.0f, 6.0f, 6.0f));
    xforms2.at(3).push_back(Matrix4::GetTranslate(140.0f, -30.0f, -5.0f) * Matrix4::GetRotateAroundZ(45.0f) * Matrix4::GetScale(6.0f, 6.0f, 6.0f));
    albedos[3] = Vector4(0.8f, 0.8f, 0.8f, 1.0f);
	
	//-----------Skull------------//
	attributes[4] = ObjUtilities::GetMesh(OBJECTS_DIR "/skull.obj");
	programs[4] = td::ShaderProgram::FromFiles(SHADERS_DIR "/specular.vert.glsl", SHADERS_DIR "/specular.frag.glsl");	
	meshes[4] = new td::VertexArray(*programs[4], *attributes[4]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(4).push_back(Matrix4::GetTranslate(150.0f, -34.5f, -50.0f) * Matrix4::GetRotateAroundZ(50.0f) * Matrix4::GetScale(2.0f, 2.0f, 2.0f));
    xforms2.at(4).push_back(Matrix4::GetTranslate(150.0f, -32.0f, -5.0f) * Matrix4::GetRotateAroundX(50.0f) * Matrix4::GetScale(2.0f, 2.0f, 2.0f));
    albedos[4] = Vector4(0.8f, 0.8f, 0.8f, 1.0f); 

	//-----------Stone1------------//
	attributes[5] = ObjUtilities::GetMesh(OBJECTS_DIR "/stone1.obj");
	programs[5] = td::ShaderProgram::FromFiles(SHADERS_DIR "/specular.vert.glsl", SHADERS_DIR "/specular.frag.glsl");	
	meshes[5] = new td::VertexArray(*programs[5], *attributes[5]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(5).push_back(Matrix4::GetTranslate(-40.0f, -31.0f, 45.0f) * Matrix4::GetRotateAroundZ(30.0f) * Matrix4::GetScale(25.0f, 25.0f, 25.0f));
    albedos[5] = Vector4(139.0f / 255.0f, 137.0f / 255.0f, 137.0f / 255.0f, 1.0f);

	//-----------Stone2------------//
	attributes[6] = ObjUtilities::GetMesh(OBJECTS_DIR "/stone2.obj");
	programs[6] = td::ShaderProgram::FromFiles(SHADERS_DIR "/specular.vert.glsl", SHADERS_DIR "/specular.frag.glsl");
	meshes[6] = new td::VertexArray(*programs[6], *attributes[6]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(6).push_back(Matrix4::GetTranslate(-40.0f, -29.0f, 165.0f) * Matrix4::GetScale(27.0f, 27.0f, 27.0f));
    albedos[6] = Vector4(139.0f / 255.0f, 137.0f / 255.0f, 137.0f / 255.0f, 1.0f);

	//-----------Stone3------------//
	attributes[7] = ObjUtilities::GetMesh(OBJECTS_DIR "/stone3.obj");
	programs[7] = td::ShaderProgram::FromFiles(SHADERS_DIR "/specular.vert.glsl", SHADERS_DIR "/specular.frag.glsl");	
	meshes[7] = new td::VertexArray(*programs[7], *attributes[7]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(7).push_back(Matrix4::GetTranslate(-170.0f, -33.0f, 25.0f) * Matrix4::GetRotateAroundX(-30.0f) * Matrix4::GetScale(15.0f, 15.0f, 15.0f));
    xforms2.at(7).push_back(Matrix4::GetTranslate(5.0f, -21.5f, 138.0f) * Matrix4::GetScale(20.0f, 20.0f, 20.0f));
    albedos[7] = Vector4(139.0f / 255.0f, 137.0f / 255.0f, 137.0f / 255.0f, 1.0f);

	//-----------Plane------------//
	attributes[8] = ObjUtilities::GetMesh(OBJECTS_DIR "/plane.obj");
	programs[8] = td::ShaderProgram::FromFiles(SHADERS_DIR "/specular.vert.glsl", SHADERS_DIR "/specular.frag.glsl");	
	meshes[8] = new td::VertexArray(*programs[8], *attributes[8]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(8).push_back(Matrix4::GetTranslate(190.0f, -31.0f, -20.0f) * Matrix4::GetRotateAroundZ(-10.0f) * Matrix4::GetRotateAroundY(30.0f) * Matrix4::GetScale(8.0f, 8.0f, 8.0f));
    albedos[8] = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

	//-----------Tree------------//
	attributes[9] = ObjUtilities::GetMesh(OBJECTS_DIR "/tree.obj");
	programs[9] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");	
	meshes[9] = new td::VertexArray(*programs[9], *attributes[9]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(9).push_back(Matrix4::GetTranslate(-160.0f, -33.0f, 5.0f) * Matrix4::GetScale(5.0f, 5.0f, 5.0f));
    xforms2.at(9).push_back(Matrix4::GetTranslate(-150.0f, -28.0f, 85.0f) * Matrix4::GetScale(7.0f, 7.0f, 7.0f));
    xforms2.at(9).push_back(Matrix4::GetTranslate(-90.0f, -31.0f, -70.0f) * Matrix4::GetScale(9.0f, 9.0f, 9.0f));
    albedos[9] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

	//-----------Bush1------------//
	attributes[10] = ObjUtilities::GetMesh(OBJECTS_DIR "/bush1.obj");
	programs[10] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");	
	meshes[10] = new td::VertexArray(*programs[10], *attributes[10]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(10).push_back(Matrix4::GetTranslate(-160.0f, -30.0f, 50.0f) * Matrix4::GetScale(5.0f, 5.0f, 5.0f));
    xforms2.at(10).push_back(Matrix4::GetTranslate(-60.0f, -34.0f, -52.0f) * Matrix4::GetScale(7.0f, 7.0f, 7.0f));
    albedos[10] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

	//-----------Bush2------------//
	attributes[11] = ObjUtilities::GetMesh(OBJECTS_DIR "/bush2.obj");
	programs[11] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");	
	meshes[11] = new td::VertexArray(*programs[11], *attributes[11]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(11).push_back(Matrix4::GetTranslate(-35.0f, -30.5f, -15.0f) * Matrix4::GetRotateAroundZ(20.0f) * Matrix4::GetScale(5.0f, 5.0f, 5.0f));
    albedos[11] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

	//-----------Bush3------------//
	attributes[12] = ObjUtilities::GetMesh(OBJECTS_DIR "/bush3.obj");
	programs[12] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");	
	meshes[12] = new td::VertexArray(*programs[12], *attributes[12]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(12).push_back(Matrix4::GetTranslate(-30.0f, -27.0f, 19.0f) * Matrix4::GetRotateAroundZ(25.0f) * Matrix4::GetScale(5.0f, 5.0f, 5.0f));
    albedos[12] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

	//-----------Bush4------------//
	attributes[13] = ObjUtilities::GetMesh(OBJECTS_DIR "/bush4.obj");
	programs[13] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");	
	meshes[13] = new td::VertexArray(*programs[13], *attributes[13]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(13).push_back(Matrix4::GetTranslate(-30.0f, -27.0f, 85.0f) * Matrix4::GetRotateAroundZ(25.0f) * Matrix4::GetScale(5.0f, 5.0f, 5.0f));
    albedos[13] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	
	//-----------Bush5------------//
	attributes[14] = ObjUtilities::GetMesh(OBJECTS_DIR "/bush5.obj");
	programs[14] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");	
	meshes[14] = new td::VertexArray(*programs[14], *attributes[14]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(14).push_back(Matrix4::GetTranslate(-5.0f, -29.0f, 145.0f) * Matrix4::GetScale(7.0f, 7.0f, 7.0f));
    albedos[14] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

	//-----------Bush6------------//
	attributes[15] = ObjUtilities::GetMesh(OBJECTS_DIR "/bush6.obj");
	programs[15] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");	
	meshes[15] = new td::VertexArray(*programs[15], *attributes[15]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(15).push_back(Matrix4::GetTranslate(-125.0f, -31.0f, 105.0f) * Matrix4::GetScale(7.0f, 7.0f, 7.0f));
    albedos[15] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

	//-----------Bush7------------//
	attributes[16] = ObjUtilities::GetMesh(OBJECTS_DIR "/bush7.obj");
	programs[16] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");	
	meshes[16] = new td::VertexArray(*programs[16], *attributes[16]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(16).push_back(Matrix4::GetTranslate(-55.0f, -29.0f, 180.0f) * Matrix4::GetScale(7.0f, 7.0f, 7.0f));
    albedos[16] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
    
    //-----------Flower1------------//
	attributes[17] = ObjUtilities::GetMesh(OBJECTS_DIR "/flower1.obj");	
	programs[17] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");
	meshes[17] = new td::VertexArray(*programs[17], *attributes[17]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(17).push_back(Matrix4::GetTranslate(-25.0f, -7.0f, 100.0f) * Matrix4::GetScale(60.0f, 60.0f, 60.0f));
    albedos[17] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
    
    //-----------Flower2------------//
	attributes[18] = ObjUtilities::GetMesh(OBJECTS_DIR "/flower2.obj");	
	programs[18] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");
	meshes[18] = new td::VertexArray(*programs[18], *attributes[18]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(18).push_back(Matrix4::GetTranslate(-35.0f, -5.0f, 100.0f) * Matrix4::GetScale(60.0f, 60.0f, 60.0f));
    albedos[18] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
    
    //-----------Flower3------------//
	attributes[19] = ObjUtilities::GetMesh(OBJECTS_DIR "/flower3.obj");	
	programs[19] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");
	meshes[19] = new td::VertexArray(*programs[19], *attributes[19]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(19).push_back(Matrix4::GetTranslate(-5.0f, -5.0f, 110.0f) * Matrix4::GetScale(20.0f, 20.0f, 20.0f));
    albedos[19] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
   
    //-----------Flower4------------//
	attributes[20] = ObjUtilities::GetMesh(OBJECTS_DIR "/flower4.obj");
	programs[20] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");
	meshes[20] = new td::VertexArray(*programs[20], *attributes[20]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(20).push_back(Matrix4::GetTranslate(-78.0f, -27.0f, 145.0f) * Matrix4::GetScale(20.0f, 20.0f, 20.0f));
    xforms2.at(20).push_back(Matrix4::GetTranslate(-135.0f, -23.5f, 100.0f) * Matrix4::GetScale(20.0f, 20.0f, 20.0f));
    xforms2.at(20).push_back(Matrix4::GetTranslate(-125.0f, -30.0f, 85.0f) * Matrix4::GetScale(18.0f, 18.0f, 18.0f));
    xforms2.at(20).push_back(Matrix4::GetTranslate(-135.0f, -31.0f, 70.0f) * Matrix4::GetScale(17.0f, 17.0f, 17.0f));
    albedos[20] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

    //-----------Flower5------------//
	attributes[21] = ObjUtilities::GetMesh(OBJECTS_DIR "/flower5.obj");
	programs[21] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");
	meshes[21] = new td::VertexArray(*programs[21], *attributes[21]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(21).push_back(Matrix4::GetTranslate(-25.0f, -22.0f, 80.0f) * Matrix4::GetScale(20.0f, 20.0f, 20.0f));
    albedos[21] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

    //-----------Scorpion------------//
    attributes[22] = ObjUtilities::GetMesh(OBJECTS_DIR "/scorpion.obj");
    programs[22] = td::ShaderProgram::FromFiles(SHADERS_DIR "/specular.vert.glsl", SHADERS_DIR "/specular.frag.glsl");	
	meshes[22] = new td::VertexArray(*programs[22], *attributes[22]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(22).push_back(Matrix4::GetTranslate(150.0f, -33.7f, -13.0f) * Matrix4::GetRotateAroundX(10.0f) * Matrix4::GetScale(2.0f, 2.0f, 2.0f));
    albedos[22] = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
	
    //-----------Condor------------//
    attributes[23] = ObjUtilities::GetMesh(OBJECTS_DIR "/condor.obj");
    programs[23] = td::ShaderProgram::FromFiles(SHADERS_DIR "/project.vert.glsl", SHADERS_DIR "/project.frag.glsl");	
	meshes[23] = new td::VertexArray(*programs[23], *attributes[23]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(23).push_back(Matrix4::GetTranslate(0.0f, 90.0f, 0.0f) * Matrix4::GetScale(13.0f, 13.0f, 13.0f));
    albedos[23] = Vector4(0.0f, 0.0f, 0.0f, 1.0f);

	//-----------Skybox------------//
    attributes[24] = ObjUtilities::GetMesh(OBJECTS_DIR "/skyboxtextured.obj");
    programs[24] = td::ShaderProgram::FromFiles(SHADERS_DIR "/textured.vert.glsl", SHADERS_DIR "/textured.frag.glsl");	
	meshes[24] = new td::VertexArray(*programs[24], *attributes[24]);
    xforms2.push_back(std::vector<Matrix4>(0));
    xforms2.at(24).push_back(Matrix4::GetScale(90.0f, 90.0f, 90.0f));
    albedos[24] = Vector4(0.0f, 0.0f, 0.0f, 1.0f);

	sunlight_position_world = Vector4(240.0f, 60.0f, 0.0f, 1.0f);

	camera = Camera(heightmap, &is_being_tossed);

    camera.LookAt(Vector4(64.0f, 15.0f, -64.0f, 0.0f),
				  Vector4(-128.0f, 15.0f, 100.0f, 0.0f),
				  Vector4(0.0f, 1.0f, 0.0f, 0.0f));


	GLuint tex_ids[1];
	glGenTextures(1, tex_ids);

	// load texture into RAM
	Image skybox_texture(OBJECTS_DIR "/skybox.ppm");
	//Image flower1_texture(OBJECTS_DIR "/flower1.ppm");
	//Image flower2_texture(OBJECTS_DIR "/flower2.ppm");
	//Image flower3_texture(OBJECTS_DIR "/flower3.ppm");
	//Image flower4_texture(OBJECTS_DIR "/flower4.ppm");
	//Image flower5_texture(OBJECTS_DIR "/flower5.ppm");

	//-----------Skybox Texture------------//
	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, tex_ids[0]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, skybox_texture.GetWidth(), 
			   skybox_texture.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, 
			   skybox_texture.GetPixels());

/*	

	//-----------Flower 1 Texture------------//
	glActiveTexture(GL_TEXTURE1);

	glBindTexture(GL_TEXTURE_2D, tex_ids[1]);

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

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, flower1_texture.GetWidth(), 
			   flower1_texture.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, 
			   flower1_texture.GetPixels());

	//-----------Flower 2 Texture------------//
	glActiveTexture(GL_TEXTURE2);

	glBindTexture(GL_TEXTURE_2D, tex_ids[2]);

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

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, flower2_texture.GetWidth(), 
			   flower2_texture.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, 
			   flower2_texture.GetPixels());

	//-----------Flower 3 Texture------------//
	glActiveTexture(GL_TEXTURE3);

	glBindTexture(GL_TEXTURE_2D, tex_ids[3]);

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

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, flower3_texture.GetWidth(), 
			   flower3_texture.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, 
			   flower3_texture.GetPixels());

	//-----------Flower 4 Texture------------//
	glActiveTexture(GL_TEXTURE4);

	glBindTexture(GL_TEXTURE_2D, tex_ids[4]);

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

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, flower4_texture.GetWidth(), 
			   flower4_texture.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, 
			   flower4_texture.GetPixels());

	//-----------Flower 5 Texture------------//
	glActiveTexture(GL_TEXTURE5);

	glBindTexture(GL_TEXTURE_2D, tex_ids[5]);

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

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, flower5_texture.GetWidth(), 
			   flower5_texture.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, 
			   flower5_texture.GetPixels());
*/

	programs[24]->Bind();
	programs[24]->SetUniform("image", 0);
	programs[24]->Unbind();
/*
	programs[17]->Bind();
	programs[17]->SetUniform("image", 1);
	programs[17]->Unbind();

	programs[18]->Bind();
	programs[18]->SetUniform("image", 2);
	programs[18]->Unbind();

	programs[19]->Bind();
	programs[19]->SetUniform("image", 3);
	programs[19]->Unbind();

	programs[20]->Bind();
	programs[20]->SetUniform("image", 4);
	programs[20]->Unbind();

	programs[21]->Bind();
	programs[21]->SetUniform("image", 5);
	programs[21]->Unbind();
*/
	for (int i = 0; i < NMODELS; ++i) {
		programs[i]->Bind();
		programs[i]->SetUniform("albedo", albedos[i][0], albedos[i][1], albedos[i][2]);
		programs[i]->Unbind();
	}

	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	

}

void ProjectRenderer::OnSizeChanged(int width, int height) {
	BaseRenderer::OnSizeChanged(width, height);

	Matrix4 projection = Matrix4::GetPerspective(45.0f, GetAspectRatio(), 0.01f, 1300.0f);

	for (int i = 0; i < NMODELS; ++i) {
		programs[i]->Bind();
		GLint location = programs[i]->GetUniformLocation("projection");
		glUniformMatrix4fv(location, 1, GL_FALSE, &projection(0,0));
		programs[i]->Unbind();
	}

}

void ProjectRenderer::OnKey(td::Keys::key_t key) {
	
	if(is_being_tossed == 1) {
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
		} else if(key == 'p') {
			is_being_tossed = 0;
		}
	}
}

void ProjectRenderer::OnKeys(bool* key_states) {
	this->key_states = key_states;
}


}
