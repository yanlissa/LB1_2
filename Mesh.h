#pragma once

#include <vector>

#include "Structures.h"

class Mesh
{
private:
	std::vector<Node> mNodes;
	std::vector<FiniteElement> mFEs;
public:
	Mesh();
	~Mesh();
	void addNode (double x, double y, double z, unsigned int k);
	const std::vector<Node>& getNodes() const { return mNodes; };
	void addFiniteElement(unsigned int finiteElementId, unsigned int materialId, unsigned int* nodeIds);
	const std::vector<FiniteElement>& getFininiteElements() const { return mFEs; };
//	std::vector<BoundaryFiniteElement>& getBoundaryFiniteElements();
};

