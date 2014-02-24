#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include <stdlib.h>

class Heightmap {
	public:
		Heightmap();
		Heightmap(int width, int height, float** heights);
		~Heightmap();
		float QueryHeight(float x, float z);
		float QueryExactHeight(float x, float z);
		void PrintHeightmap();
		int GetMapHeight();
		int GetMapWidth();

	private:
		float** heights;
		int width;
		int height;
};

#endif