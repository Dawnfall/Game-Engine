#include "ResourceLoader.h"

#include <glm/glm.hpp>

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "Mesh.h"

static glm::vec3 ParseOBJVec3(const char* line, unsigned lineLength);

void ResourceLoader::loadMesh(std::string fileName)
{
	for (int i = fileName.length(); i >= 0; i--)
	{
		if (fileName[i] == '.')
		{
			if (fileName.substr(i) == ".obj")
			{

			}
			else
				std::cerr << "Error: File format " + fileName.substr(i) + " not suported" << std::endl;
			return;
		}
	}
	std::cerr << "Error: Wrong file name" << std::endl;
}



static glm::vec3 ParseOBJVec3(const char* line, unsigned lineLength)
{

}
