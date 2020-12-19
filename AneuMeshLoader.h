#pragma once

#include "MeshLoader.h"

class AneuMeshLoader : MeshLoader
{
public:
	AneuMeshLoader () {};
	~AneuMeshLoader () {};
	virtual Mesh& LoadMesh(const std::string& filename) override;
};
