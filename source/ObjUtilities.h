#ifndef OBJUTILITIES_H
#define OBJUTILITIES_H

#include "VertexAttributes.h"
#include "Heightmap.h"

class ObjUtilities {
	public:
		static td::VertexAttributes *GetMesh(const std::string& path);
		static td::VertexAttributes* GetMeshFromHeightmap(const std::string& path, Heightmap* heightmap);

	private:
		static void Create2DArray(const int width, const int height, float*** array);	
		static void WriteOBJFile(float** heightmap, const int maxWidth, int width, const int maxHeight, int height, const int maxZ, int maxValue, const std::string& path);
		static bool FileExists(const std::string& path);
};

#endif
