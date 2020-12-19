#pragma once

#include "MeshLoader.h"

class AneuMeshLoader : MeshLoader
{
public:
	AneuMeshLoader () {};
	~AneuMeshLoader () {};
	virtual Mesh& loadMesh(const std::string& filename) override;
};
