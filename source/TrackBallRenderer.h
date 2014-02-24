#ifndef TRACKBALLRENDERER_H
#define TRACKBALLRENDERER_H


#include <cmath>
#include <iostream>
#include "BaseRenderer.h"
#include "glut_utilities.h"
#include "ObjUtilities.h"
#include "Matrix4.h"
#include "Vector4.h"
#include <cmath>


namespace td {

/* ------------------------------------------------------------------------- */

class TrackballRenderer : public BaseRenderer {

	public:
		TrackballRenderer();
		~TrackballRenderer();
		void OnInitialize();
		void OnDraw();

		void OnLeftMouseDragged(int x, int y);
		void OnLeftMouseDown(int x, int y);
		void OnRightMouseDragged(int x, int y);
		void OnSizeChanged(int width, int height);
	
	private:
		Vector4 MapPixelToUnitSphere(int x, int y) const;
		td::VertexAttributes *attributes;
		td::ShaderProgram *program;
		td::VertexArray *mesh;
		Matrix4 ortho;

		Matrix4 xform;
		Vector4 fore;

		Vector4 light_position;

};

}

#endif
