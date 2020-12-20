#include <iostream>

#include "Mesh.h"

Mesh::Mesh ()
{
}

Mesh::~Mesh ()
{
}

void
Mesh::addNode(std::array<double, 3> coordinates, unsigned int k)
{
	Node node1(k, coordinates, false);
	if (mNodes.find(k) != mNodes.end()) {
		throw std::runtime_error("Duplicate node id!");
	}
	if (mNodesByCoordinates.find(coordinates) != mNodesByCoordinates.end()) {
		throw std::runtime_error("Duplicate node coordinates!");
	}
	mNodes[k] = node1;
	mNodesByCoordinates[coordinates] = node1;
}

void
Mesh::addFiniteElement(unsigned int k, unsigned int materialId, std::array<unsigned int, 4> nodeIds)
{
	if (mFEs.find(k) != mFEs.end()) {
		throw std::runtime_error("Duplicate finite element id!");
	}
	if (mFEsByNodeIds.find(nodeIds) != mFEsByNodeIds.end()) {
		throw std::runtime_error("Duplicate finite element by node ids!");
	}
	FiniteElement fe1;
	fe1.finiteElementId = k;
	fe1.materialId = materialId;
	fe1.nodeIds = nodeIds;
	mFEs[k] = fe1;
}

void
Mesh::addBoundaryFiniteElement(unsigned int boundaryFiniteElementId, unsigned int boundaryId, unsigned int* nodeIds)
{
	if (mBFEs.find(boundaryFiniteElementId) != mBFEs.end()) {
		throw std::runtime_error("Duplicate boundary finite element id!");
	}
	BoundaryFiniteElement bfe1;
	bfe1.boundaryFiniteElementId = boundaryFiniteElementId;
	bfe1.boundaryId = boundaryId;
	bfe1.nodeIds[0] = nodeIds[0];
	bfe1.nodeIds[1] = nodeIds[1];
	bfe1.nodeIds[2] = nodeIds[2];
	mBFEs[boundaryFiniteElementId] = bfe1;
}
