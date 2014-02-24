#include <cmath>
#include <iostream>

#include "BaseRenderer.h"
#include "glut_utilities.h"
#include "Matrix4.h"
#include "Vector4.h"

class SpiralRenderer : public td::BaseRenderer {
	public:
		void OnInitialize();
		void OnDraw();

		void OnLeftMouseDragged(int x, int y);
	
	private:
		td::VertexAttributes *attributes;
		td::ShaderProgram *program;
		td::VertexArray *mesh;
		Matrix4 translater;
};

/**************************************************************************************/

void SpiralRenderer::OnDraw() {
	BaseRenderer::OnDraw();
	
	program->Bind();
	mesh->Bind();
	mesh->DrawSequence(GL_LINE_STRIP);
	mesh->Unbind();
	program->Unbind();
}

void SpiralRenderer::OnInitialize() {
	BaseRenderer::OnInitialize();
	
	const int NVERTICES = 1000;
	float positions[NVERTICES * 4];
	
	Vector4 vector(0.01f, 0.0f, 0.0f, 1.0f);
	Matrix4 rotater = Matrix4::GetRotateAroundZ(5.0f);
	Matrix4 scaler = Matrix4::GetScale(1.01f, 1.01f, 1.0f);
	
	float *position = positions;
	for(int i = 0; i < NVERTICES; ++i) {
		vector = scaler * (rotater * vector);
		position[0] = vector[0];
		position[1] = vector[1];
		position[2] = vector[2];
		position[3] = vector[3];
		position += 4;
	}
	
	attributes = new td::VertexAttributes();
	attributes->AddAttribute("position", NVERTICES, 4, positions);

	program = td::ShaderProgram::FromFiles("shaders/spiral.vert.glsl", "shaders/spiral.frag.glsl");
	
	mesh = new td::VertexArray(*program, *attributes);
	
	program->Bind();
	translater = Matrix4::GetIdentity();
	std::cout << translater << std::endl;
	GLint location = program->GetUniformLocation("translater");
	glUniformMatrix4fv(location, 1, GL_FALSE, &translater(0,0));
	program->Unbind();
}

void SpiralRenderer::OnLeftMouseDragged(int x, int y) {
	program->Bind();
	translater = Matrix4::GetTranslate(2.0f * (x / (float) GetWidth() - 0.5f),
									   2.0f * (y / (float) GetHeight() - 0.5f), 0.0f);
	GLint location = program->GetUniformLocation("translater");
	glUniformMatrix4fv(location, 1, GL_FALSE, &translater(0,0));
	program->Unbind();
}

/**********************************************************************************/

int main(int argc, char **argv) {
	SpiralRenderer *renderer = new SpiralRenderer();
	renderer->SetBackgroundColor(0.0f, 0.0f, 0.0f, 1.0f);
	glut_render(renderer);
	return 0;
}