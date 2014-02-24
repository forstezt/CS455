#include <iostream>

#include "CircleRenderer.h"
#include <cmath>

namespace td {

/* ------------------------------------------------------------------------- */

CircleRenderer::CircleRenderer() {

}

/* ------------------------------------------------------------------------- */

CircleRenderer::~CircleRenderer() {
}

/* ------------------------------------------------------------------------- */

void CircleRenderer::OnDraw() {

	//-------------------------NO-PHYSICS----------------------------//

	BaseRenderer::OnDraw();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	program->Bind(); 

	if (abs(currOffsetX) >= 1.0f) {
		translationFactorX *= -1.0f;
	}
	
	if (abs(currOffsetY) >= 1.0f) {
		translationFactorY *= -1.0f;
	}

	if (isRotatingRight) {
		rotationFactor += 0.001f;
	} else if (isRotatingLeft) {
		rotationFactor -= 0.001f;
	}

	program->SetUniform("beta", rotationFactor);

	currOffsetX += translationFactorX;
	currOffsetY += translationFactorY;

	program->SetUniform("velocityX", currOffsetX);
	program->SetUniform("velocityY", currOffsetY);

	triangle->Bind();
	triangle->DrawSequence(GL_TRIANGLE_STRIP);
	triangle->Unbind();

	program->Unbind();
	
	//-------------------------NO-PHYSICS----------------------------//






	//-------------------------PHYSICS----------------------------//
	/*BaseRenderer::OnDraw();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	program->Bind(); 

	if (abs(currX) >= 1.0f) {
		originalX = currX;
		originalY = currY;
		time = 0.0f;
		initVelocityX *= -0.8f;
	}
	
	if (abs(currY) >= 1.0f) {
		totalOffsetX += currX;
		totalOffsetY += currY;
		originalX = 0.0f;
		originalY = 0.0f;
		time = 0.0f;
		initVelocityY *= -0.9f;
	}



	if (isRotatingRight) {
		rotationFactor += 0.001f;
	} else if (isRotatingLeft) {
		rotationFactor -= 0.001f;
	}



	program->SetUniform("beta", rotationFactor);

	currX = originalX + (initVelocityX * time);
	currY = originalY + (initVelocityY * time) - (0.5f * gravity * time * time); 

	program->SetUniform("velocityX", deltaX);
	program->SetUniform("velocityY", deltaY);

	triangle->Bind();
	triangle->DrawSequence(GL_TRIANGLE_STRIP);
	triangle->Unbind();

	program->Unbind();
	*/
	//-------------------------PHYSICS----------------------------//

}

/****************************************************************************************************************************/

void CircleRenderer::OnInitialize() {

	currOffsetX = 0.0f;
	currOffsetY = 0.0f;

	translationFactorX = 0.0005f;
	translationFactorY = 0.0003f;

	rotationFactor = 0.0f;

	isRotatingRight = false;
	isRotatingLeft = false;

	//-------------------------PHYSICS----------------------------//
	gravity = 0.00002f;
	time = 0.0f;

	initMouseX = 0.0f;
	initMouseY = 0.0f;

	initVelocityX = 0.0f;
	initVelocityY = 0.0f;

	currX = 0.0f;
	currY = 0.0f;

	totalOffsetX = 0.0f;
	totalOffsetY = 0.0f;
	//-------------------------PHYSICS----------------------------//

	attributes = new td::VertexAttributes();






	//Creates arrays for vertex attributes
	float positions[104 * 2];
	float colors[104 * 3];






	//Assigns colors to each vertex
	float* colorPosition = colors;
	for (int i = 0; i < 104; i++) {

		if (i % 2 == 0) {
			colorPosition[0] = 0.0f;
			colorPosition[1] = 0.0f;
			colorPosition[3] = 1.0f;
		} else {
			colorPosition[0] = 1.0f;
			colorPosition[1] = 0.0f;
			colorPosition[3] = 0.5f;
		}
		colorPosition += 3;
	}






	//Circumference vertices
	float* position = positions;
	float theta = 0.0f;
	for (int i = 0; i < 52; i++) {
		position[0] = cos(theta);
		position[1] = sin(theta);
		position[2] = 0.3f * cos(theta);
		position[3] = 0.3f * sin(theta);
		theta += (2.0 * td::PI) / 52.0f;
		position += 4;
	}






	//Sending vertices to vertex shader
	attributes->AddAttribute("position", 100, 2, positions);

	//Sending vertices to vertex shader
	attributes->AddAttribute("color", 100, 3, colors);

	program = td::ShaderProgram::FromFiles(SHADERS_DIR "/colored.vert.glsl", SHADERS_DIR "/colored.frag.glsl");

	triangle = new td::VertexArray(*program, *attributes);
	
}

/****************************************************************************************************************************/

void CircleRenderer::OnLeftMouseDown(int x, int y) {
	isRotatingLeft = true;

}

/****************************************************************************************************************************/

void CircleRenderer::OnLeftMouseUp(int x, int y) {
	isRotatingLeft = false;

}

/****************************************************************************************************************************/

void CircleRenderer::OnRightMouseDown(int x, int y) {
	isRotatingRight = true;

}

/****************************************************************************************************************************/

void CircleRenderer::OnRightMouseUp(int x, int y) {
	isRotatingRight = false;

}

/****************************************************************************************************************************/

void CircleRenderer::OnMiddleMouseDown(int x, int y) {
	initMouseX = x;
	initMouseY = y;

}

/****************************************************************************************************************************/

void CircleRenderer::OnMiddleMouseUp(int x, int y) {
	
	//translationFactorX = (x - initialX) / 100000.0f;
	//translationFactorY = (y - initialY) / 100000.0f;
	
	time = 0.0f;


	initVelocityX = -1.0 * (x - initMouseX) / 100000.0f;
	initVelocityY = -1.0 * (y - initMouseY) / 100000.0f;
}


}