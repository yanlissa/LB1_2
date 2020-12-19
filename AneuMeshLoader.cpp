#include <iostream>

#include "AneuMeshLoader.h"

Mesh&
AneuMeshLoader::LoadMesh(const std::string& filename)
{
	std::cout << filename << std::endl;
	return *(new Mesh());
}

