#pragma once

#include <string>

#include "Mesh.h"

class MeshLoader
{
public:
	virtual Mesh& LoadMesh(const std::string& path) = 0;
	virtual ~MeshLoader() = default;
};
