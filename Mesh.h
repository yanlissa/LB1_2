#pragma once

#include <functional>
#include <map>
#include <vector>

#include "Structures.h"

class Mesh
{
private:
	std::map<unsigned int, Node> mNodes;
	std::map<std::array<double, 3>, Node> mNodesByCoordinates;
	std::map<unsigned int, FiniteElement> mFEs;
	std::map<unsigned int, BoundaryFiniteElement> mBFEs;
public:
	Mesh();
	~Mesh();
	void addNode (std::array<double, 3> coordinates, unsigned int k);
	const std::map<unsigned int, Node>& getNodes() const { return mNodes; };
	void addFiniteElement (unsigned int finiteElementId, unsigned int materialId, unsigned int* nodeIds);
	const std::map<unsigned int, FiniteElement>& getFininiteElements() const { return mFEs; };
	void addBoundaryFiniteElement (unsigned int boundaryFiniteElementId, unsigned int boundaryId, unsigned int* nodeIds);
	const std::map<unsigned int, BoundaryFiniteElement>& getBoundaryFiniteElements() const { return mBFEs; };
};

