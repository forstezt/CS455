#ifndef MODEL_H
#define MODEL_H


#include <cmath>
#include <iostream>
#include "BaseRenderer.h"
#include "glut_utilities.h"
#include "ObjUtilities.h"
#include "Matrix4.h"
#include "Vector4.h"
#include "Camera.h"
#include <cmath>


namespace td {

/* ------------------------------------------------------------------------- */

class ModelRenderer : public BaseRenderer {

	public:
		void OnInitialize();
		void OnDraw();

		void OnLeftMouseDown(int x, int y);
		void OnLeftMouseDragged(int x, int y);
		void OnKey(td::Keys::key_t key);
		void OnSizeChanged(int width, int height);
		void OnRightMouseDown(int x, int y);
		void OnRightMouseDragged(int x, int y);
	
	private:
		Vector4 MapPixelToUnitSphere(int x, int y) const;
		td::VertexAttributes *attributes;
		td::ShaderProgram *program;
		td::VertexArray *mesh;
		
		Matrix4 xform;
		Matrix4 push;
		Vector4 fore;

		Camera camera;

};

}

#endif
