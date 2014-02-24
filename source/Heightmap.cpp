#include "Heightmap.h"
#include <iostream>

Heightmap::Heightmap() {
}

Heightmap::Heightmap(int width, int height, float** heights) {
	this->heights = heights;
	this->width = width;
	this->height = height;
}

Heightmap::~Heightmap() {

}

int Heightmap::GetMapHeight() {
	return height;
}

int Heightmap::GetMapWidth() { 
	return width;
}

float Heightmap::QueryHeight(float x, float z) {
	int lower_x_bound = (int)x - 6;
	int upper_x_bound = (int)x + 7;
	int upper_z_bound = (int)z + 7;
	int lower_z_bound = (int)z - 6;

	//std::cout << "lower_x_bound: " << lower_x_bound << " lower_z_bound: " << lower_z_bound << " upper_x_bound: " << upper_x_bound << " upper_z_bound: " << upper_z_bound << std::endl;
	//std::cout << "lower_x_bound: " << 0 << " lower_z_bound: " << 0 << " upper_x_bound: " << GetMapWidth() << " upper_z_bound: " << GetMapHeight() << std::endl;

	if ((lower_x_bound < 2) || (lower_z_bound < 2) || (upper_x_bound > GetMapWidth() - 2) || (upper_z_bound > GetMapWidth() - 2)) {
		return 10010.0f;
	}

	float tl_weight = ((upper_x_bound - x) * (z - lower_z_bound)) / ((upper_x_bound - lower_x_bound) * (upper_z_bound - lower_z_bound));
	float tr_weight = ((upper_x_bound - x) * (upper_z_bound - z)) / ((upper_x_bound - lower_x_bound) * (upper_z_bound - lower_z_bound));
	float bl_weight = ((x - lower_x_bound) * (z - lower_z_bound)) / ((upper_x_bound - lower_x_bound) * (upper_z_bound - lower_z_bound));
	float br_weight = ((x - lower_x_bound) * (upper_z_bound - z)) / ((upper_x_bound - lower_x_bound) * (upper_z_bound - lower_z_bound));

    return heights[lower_x_bound][lower_z_bound] * bl_weight + 
		   heights[lower_x_bound][upper_z_bound] * br_weight +
		   heights[upper_x_bound][lower_z_bound] * tl_weight +
		   heights[upper_x_bound][upper_z_bound] * tr_weight + 8;
}

float Heightmap::QueryExactHeight(float x, float z) {

	if ((x < 2) || (z < 2) || (x > GetMapWidth() - 2) || (z > GetMapWidth() - 2)) {
		return 10010.0f;
	}

    return heights[(int)x][(int)z] + 0.5;
}

void Heightmap::PrintHeightmap() {

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			std::cout << (this->heights)[j][i] << " ";
		}

		std::cout << std::endl;
	}
}
