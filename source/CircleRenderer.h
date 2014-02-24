#ifndef CIRCLERENDERER_H
#define CIRCLERENDERER_H

#include "Keys.h"
#include "UtilitiesOpenGL.h"
#include "VertexArray.h"
#include "BaseRenderer.h"

namespace td {

/* ------------------------------------------------------------------------- */

class CircleRenderer : public BaseRenderer {
  public:
    CircleRenderer();
    ~CircleRenderer();

    float GetAspectRatio() const;

    void OnInitialize();
    void OnDraw();
	void OnLeftMouseDown(int x, int y);
	void OnLeftMouseUp(int x, int y);
	void OnRightMouseDown(int x, int y);
	void OnRightMouseUp(int x, int y);
	void OnMiddleMouseDown(int x, int y);
    void OnMiddleMouseUp(int x, int y);

  private:
    float background_color[4];
	bool isRotatingRight;
	bool isRotatingLeft;
	float rotationFactor;
	float currOffsetX;
	float currOffsetY;
	float translationFactorX;
	float translationFactorY;

	//Physics variables
	float gravity;
	float friction;
	float time;

	float initMouseX;
	float initMouseY;

	float initVelocityX;
	float initVelocityY;

	float currX;
	float currY;

	float originalX;
	float originalY;

	float totalOffsetX;
	float totalOffsetY;

	td::VertexAttributes* attributes;
	td::ShaderProgram* program;
	td::VertexArray* triangle;

};

/* ------------------------------------------------------------------------- */

}

#endif
