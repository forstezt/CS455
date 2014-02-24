#include <iostream>

#include "CircleRenderer.h"
#include "glut_utilities.h"

int main(int argc,
         char **argv) {

	td::CircleRenderer* renderer = new td::CircleRenderer();
	glut_render(renderer);

	return 0;

}
