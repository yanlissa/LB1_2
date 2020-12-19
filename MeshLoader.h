#pragma once

#include <string>

#include "Mesh.h"

class MeshLoader
{
public:
	virtual Mesh& loadMesh(const std::string& path) = 0;
	virtual ~MeshLoader() = default;
};
