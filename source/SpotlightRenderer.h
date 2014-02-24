#ifndef SpotlightRenderer_H
#define SpotlightRenderer_H

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

class SpotlightRenderer : public BaseRenderer {

	public:
		SpotlightRenderer();
		~SpotlightRenderer();
		void OnInitialize();
		void OnDraw();

		void OnSizeChanged(int width, int height);
		void OnKey(td::Keys::key_t key);
	
	private:

		Vector4 spot_direction_world;
		Vector4 light_position_world;
	
        static const int NMODELS = 2;

		td::VertexAttributes *attributes[NMODELS];
		td::ShaderProgram *programs[NMODELS];
		td::VertexArray *meshes[NMODELS];
		Matrix4 xforms[NMODELS];
		Matrix4 ortho;
		Vector4 albedos[NMODELS];

		Camera camera;

};

}

#endif
