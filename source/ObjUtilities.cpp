#include "ObjUtilities.h"
#include <fstream>
#include <iostream>
#include "Vector4.h"
#include <sstream>
#include <cstring>

td::VertexAttributes* ObjUtilities::GetMesh(const std::string& path) {
	

	/*************************Connection to count vertices and faces***************************/	

	int nvertices = 0;
	int nfaces = 0;
	int ntexcoords = 0;

	std::ifstream countingConnection(path);

	std::string line = " ";
	while(std::getline(countingConnection, line)) {

		if (line[0] == 'v') {
			if (line[1] == 't') { //it's a texture coordinate
				ntexcoords++;
			} else { //it's a vertex
				nvertices++;
			}
		} else if (line[0] == 'f') { //it's a face
			nfaces++;
		} 
	}
	std::cout << "nvertices - " << nvertices << std::endl;
	std::cout << "ntexcoords - " << ntexcoords << std::endl;
	std::cout << "nfaces - " << nfaces << std::endl;

	countingConnection.close();

	/******************Connection to actually read in vertices and faces*******************/	

	std::ifstream in(path);



	Vector4* vertex_normals = new Vector4[nvertices];

	float* positions = new float[nvertices * 3];
	int* faces = new int[nfaces * 3];
	float* texcoords = new float[ntexcoords * 2];

	float* position = positions;
	int* face = faces;
	float* texcoord = texcoords;

	std::string dummy;
	int vertexCount = 0;

	while((in >> dummy)) {
		if(dummy.size() == 1 && dummy[0] == 'v') {
			in >> position[0] >> position[1] >> position[2];
			//std::cout << dummy << " " << position[0] << " " << position[1] << " " << position[2] << std::endl;
			position += 3;
			vertex_normals[vertexCount] = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
			vertexCount++;
		} else if(dummy.size() == 2 && dummy[1] == 't') {
			in >> texcoord[0] >> texcoord[1];
			//std::cout << dummy << " " << texcoord[0] << " " << texcoord[1] << std::endl;
			texcoord += 2;
		} else if(dummy[0] == 'f') {
			in >> face[0] >> face[1] >> face[2];
			//std::cout << dummy << " " << face[0] << " " << face[1] << " " << face[2] << std::endl;

			//Because the faces in the .obj file are 1-based, not 0-based, 
			//as we need them to be
			--face[0];
			--face[1];
			--face[2];
		
			//Sets the a pointer to each of the 3 vertices that make up the current face
			float* a = positions + face[0] * 3;
			float* b = positions + face[1] * 3;
			float* c = positions + face[2] * 3;
		
			//Calculates the vectors between a & b, and between a & c
			Vector4 a2b = Vector4(b[0] - a[0], b[1] - a[1], b[2] - a[2], 0.0f); 
			Vector4 a2c = Vector4(c[0] - a[0], c[1] - a[1], c[2] - a[2], 0.0f);

			//Calculates the normal vector to the face
			Vector4 face_normal = a2b.Cross(a2c);
		
			//Normalizes the face_normal
			face_normal.Normalize();
		
			//adds the calculated face_normal to the normal vector of every vertex that
			//it touches
			vertex_normals[face[0]] = vertex_normals[face[0]] + face_normal;
			vertex_normals[face[1]] = vertex_normals[face[1]] + face_normal;
			vertex_normals[face[2]] = vertex_normals[face[2]] + face_normal;
		
			face += 3;
		}

		std::getline(in, line);

	}
	
	float* normals = new float[nvertices * 3];
	float* normal = normals;
	for (int i = 0; i < nvertices; ++i) {
		vertex_normals[i].Normalize();
		normal[0] = vertex_normals[i][0];
		normal[1] = vertex_normals[i][1];
		normal[2] = vertex_normals[i][2];
		
		normal += 3;
	}

	td::VertexAttributes *attributes = new td::VertexAttributes();
	attributes->AddAttribute("position", nvertices, 3, positions);
	attributes->AddAttribute("normal", nvertices, 3, normals);
	
	if(ntexcoords > 0) {
		attributes->AddAttribute("texcoord", nvertices, 2, texcoords);
	}
	
	attributes->AddIndices(nfaces * 3, faces);
	
	in.close();


	return attributes;
}

/****************************************************************************************************/

td::VertexAttributes* ObjUtilities::GetMeshFromHeightmap(const std::string& path, Heightmap* heights) {
	//Initiate variables
	std::string line;
	const float maxHeight = 20.0f;
	const float maxWidth = 20.0f;
	const float maxZ = 50.0f;
	int maxValue;

	int width = 0;
	int height = 0;

	std::ifstream in(path);
		
	//Read in the first 2 lines of the file
	std::getline(in, line);
	std::getline(in, line);

	in >> width >> height >> maxValue;
	std::cout << "Width of image in pixels: " << width << std::endl;
	std::cout << "Height of image: " << height << std::endl;
	std::cout << "Maximum Pixel Value: " << maxValue << std::endl << std::endl;

	//Create 2D array datastructure on heap for heightmap
	float** heightmap;
	Create2DArray(width, height, &heightmap);

	//Populate heightmap
	for(int i = 0; i < width; i++) {
		for(int j = 0; j < height; j++) {
			in >> heightmap[j][i];
		}
	}


	in.close();

	for(int i = 0; i < width; i++) {
		for(int j = 0; j < height; j++) {
			heightmap[j][i] = (((float)heightmap[j][i] / (float)maxValue) * -maxZ);
		}
	}

    (*heights) = Heightmap(width, height, heightmap);
	
	std::string objFile = OBJECTS_DIR "/test_desert.obj";
	//std::string objFile = "H:\CS455/test_desert.obj";
	WriteOBJFile(heightmap, maxWidth, width, maxHeight, height, maxZ, maxValue, objFile);

	td::VertexAttributes* attributes = new td::VertexAttributes();
	attributes = GetMesh(objFile);

	return attributes;
}


void ObjUtilities::Create2DArray(const int width, const int height, float*** array) {
   float** tmpArray = new float* [width];
   for (int j = 0; j < width; j ++) {
      tmpArray[j] = new float[height];
   }

   *array = tmpArray;

   std::cout << "2D array initialized" << std::endl << std::endl;

}

bool ObjUtilities::FileExists(const std::string& path) {
  std::ifstream ifile(path);
  return ifile;
}

void ObjUtilities::WriteOBJFile(float** heightmap, const int maxWidth, int width, const int maxHeight, int height, const int maxZ, int maxValue, const std::string& path) {
	
	if (!FileExists(path)) {
		std::ofstream out;
		out.open(path);

		std::string writestring;
		std::stringstream sstm;

		for(int i = 0; i < width; i++) {
			for(int j = 0; j < height; j++) {
				sstm << "v " << (i - (width / 2))  << " " << heightmap[i][j] << " " << (j - (height / 2)) << std::endl;
			}
		}

		for(int i = 0; i < width - 1; i++) {
			for(int j = 0; j < height - 1; j++) {
				int bottomLeft = j * width + i + 1;
				int bottomRight = bottomLeft + 1;
				int topRight = bottomRight + width;
				int topLeft = bottomLeft + width;
				sstm << "f " << bottomLeft << " " << bottomRight << " " << topRight << std::endl;
				sstm << "f " << bottomLeft << " " << topRight << " " << topLeft << std::endl;
			}
		}

		writestring = sstm.str();

		out << writestring;

		out.close();

		std::cout << "Faces and vertices successfully written to " << path << std::endl;
	} else {
		char response;
		std::cout << "The file " << path << " has already been written." << std::endl << "Would you like to overwrite it? (Y/N)" << std::endl;
		std::cin >> response;
		std::cout << std::endl;

		if(response == 'Y') {

			char* fileToRemove = new char [path.length()+1];
			//strcpy(fileToRemove, path.c_str());
            path.copy(fileToRemove, path.size(), 0);

			remove(fileToRemove);
			WriteOBJFile(heightmap, maxWidth, width, maxHeight, height, maxZ, maxValue, path);

		} else {
			std::cout << "No new .obj file was created" << std::endl;
		}
	}
}
