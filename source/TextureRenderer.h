#ifndef TEXTURERENDERER_H
#define TEXTURERENDERER_H


#include <cmath>
#include <iostream>
#include "BaseRenderer.h"
#include "glut_utilities.h"
#include "ObjUtilities.h"
#include "Matrix4.h"
#include "Vector4.h"
#include "Camera.h"
#include <cmath>
#include "Image.h"


namespace td {

/* ------------------------------------------------------------------------- */

class TextureRenderer : public BaseRenderer {

	public:
		TextureRenderer();
		~TextureRenderer();
		void OnInitialize();
		void OnDraw();

		void OnKey(td::Keys::key_t key);
		void OnSizeChanged(int width, int height);

	
	private:
		Vector4 MapPixelToUnitSphere(int x, int y) const;
		td::VertexAttributes *attributes;
		td::ShaderProgram *program;
		td::VertexArray *mesh;
		
		Matrix4 xform;
		Vector4 fore;

		Camera camera;

};

}

#endif
