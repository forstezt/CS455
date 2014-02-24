#include <iostream>

#include "SpotlightRenderer.h"
#include "glut_utilities.h"

int main(int argc,
         char **argv) {

	td::SpotlightRenderer* renderer = new td::SpotlightRenderer();
	renderer->SetBackgroundColor(0.1f, 0.1f, 0.1f, 1.0f);
	glut_render(renderer);

	return 0;

}
