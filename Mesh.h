#pragma once

#include <map>
#include <vector>

#include "CompareCoordinates.h"
#include "Structures.h"

class Mesh
{
private:
	std::map<unsigned int, Node> mNodes;
	std::map<std::array<double, 3>, Node, CompareCoordinates> mNodesByCoordinates;
	std::vector<FiniteElement> mFEs;
	std::vector<BoundaryFiniteElement> mBFEs;
public:
	Mesh();
	~Mesh();
	void addNode (std::array<double, 3> coordinates, unsigned int k);
	const std::map<unsigned int, Node>& getNodes() const { return mNodes; };
	void addFiniteElement (unsigned int finiteElementId, unsigned int materialId, unsigned int* nodeIds);
	const std::vector<FiniteElement>& getFininiteElements() const { return mFEs; };
	void addBoundaryFiniteElement (unsigned int boundaryFiniteElementId, unsigned int boundaryId, unsigned int* nodeIds);
	const std::vector<BoundaryFiniteElement>& getBoundaryFiniteElements() const { return mBFEs; };
};

