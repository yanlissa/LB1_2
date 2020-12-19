#pragma once

#include <vector>

#include "Structures.h"

class Mesh
{
private:
	std::vector<Node> mNodes;
	std::vector<FiniteElement> mFEs;
	std::vector<BoundaryFiniteElement> mBFEs;
public:
	Mesh();
	~Mesh();
	void addNode (double x, double y, double z, unsigned int k);
	const std::vector<Node>& getNodes() const { return mNodes; };
	void addFiniteElement (unsigned int finiteElementId, unsigned int materialId, unsigned int* nodeIds);
	const std::vector<FiniteElement>& getFininiteElements() const { return mFEs; };
	void addBoundaryFiniteElement (unsigned int boundaryFiniteElementId, unsigned int boundaryId, unsigned int* nodeIds);
	const std::vector<BoundaryFiniteElement>& getBoundaryFiniteElements() const { return mBFEs; };
};

