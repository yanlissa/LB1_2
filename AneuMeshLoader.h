#pragma once

#include "MeshLoader.h"

class AneuMeshLoader : MeshLoader
{
public:
	AneuMeshLoader () {};
	~AneuMeshLoader () {};
	virtual Mesh& loadMesh(const std::string& filename) override;
	void loadNodes(std::ifstream &fileIn, Mesh* mesh);
	void loadFiniteElements(std::ifstream &fileIn, Mesh* mesh);
	void loadBoundaryFiniteElements(std::ifstream &fileIn, Mesh* mesh);
};
