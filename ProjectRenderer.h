#ifndef PROJECTRENDERER_H
#define PROJECTRENDERER_H

#include <cmath>
#include <iostream>
#include "BaseRenderer.h"
#include "glut_utilities.h"
#include "ObjUtilities.h"
#include "Matrix4.h"
#include "Vector4.h"
#include "Camera.h"
#include <cmath>
#include <vector>
#include "Heightmap.h"

namespace td {

/* ------------------------------------------------------------------------- */

class ProjectRenderer : public BaseRenderer {

	public:
		ProjectRenderer();
		~ProjectRenderer();
		void OnInitialize();
		//void OnDraw();
		void OnDraw(float delta_time);

		void OnSizeChanged(int width, int height);
		void OnKey(td::Keys::key_t key);
		void OnKeys(bool* key_states);
	
	private:

        static const int NMODELS = 27;

		td::VertexAttributes* attributes[NMODELS];
		td::ShaderProgram* programs[NMODELS];
		td::VertexArray* meshes[NMODELS];
		td::VertexArray* to_shadow_meshes[NMODELS];
		Matrix4 ortho;
		Vector4 albedos[NMODELS];

		td::ShaderProgram* to_shadow_program;

        std::vector<std::vector<Matrix4>> xforms2;

		Camera camera;

		int is_being_tossed;
		Vector4 light_position_world;
		Vector4 spot_direction_world;
		bool* key_states;

		float t;

		GLuint framebuffer_id;
		GLuint screenshot_id;
		GLuint depth_tid;

};

}

#endif
