#include <algorithm>
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
	mNodesByCoordinates[coordinates] = &mNodes[k];
}

void
Mesh::addFiniteElement(unsigned int k, unsigned int materialId, std::array<unsigned int, 4> nodeIds)
{
	if (mFEs.find(k) != mFEs.end()) {
		throw std::runtime_error("Duplicate finite element id!");
	}
	std::sort(nodeIds.begin(), nodeIds.end());
	if (mFEsByNodeIds.find(nodeIds) != mFEsByNodeIds.end()) {
		throw std::runtime_error("Duplicate finite element by node ids!");
	}
	FiniteElement fe1;
	fe1.finiteElementId = k;
	fe1.materialId = materialId;
	fe1.nodeIds = nodeIds;
	mFEs[k] = fe1;
	mFEsByNodeIds[nodeIds] = &mFEs[k];
	for (int i = 3; i >= 0; i--) {
		std::array<unsigned int, 3> nodeIds3;
		int l = 0;
		for (int j = 0; j < 4; j++) {
			if (i != j) {
				nodeIds3[l] = nodeIds[j];
				l++;
			}
		}
		if (mFEsBy3Nodes.find(nodeIds3) == mFEsBy3Nodes.end()) {
			mFEsBy3Nodes[nodeIds3] = *(new std::set<FiniteElement *>);
		}
		mFEsBy3Nodes[nodeIds3].insert(&mFEs[k]);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			std::array<unsigned int, 2> nodeIds2;
			nodeIds2[0] = nodeIds[i];
			nodeIds2[1] = nodeIds[j];
			if (mFEsBy2Nodes.find(nodeIds2) == mFEsBy2Nodes.end()) {
				mFEsBy2Nodes[nodeIds2] = *(new std::set<FiniteElement *>);
			}
			mFEsBy2Nodes[nodeIds2].insert(&mFEs[k]);
		}
	}
}

void
Mesh::addBoundaryFiniteElement(unsigned int boundaryFiniteElementId, unsigned int boundaryId, std::array<unsigned int, 3> nodeIds)
{
	if (mBFEs.find(boundaryFiniteElementId) != mBFEs.end()) {
		throw std::runtime_error("Duplicate boundary finite element id!");
	}
	if (mBFEsByNodeIds.find(nodeIds) != mBFEsByNodeIds.end()) {
		throw std::runtime_error("Duplicate boundary finite element by node ids!");
	}
	BoundaryFiniteElement bfe1;
	bfe1.boundaryFiniteElementId = boundaryFiniteElementId;
	bfe1.boundaryId = boundaryId;
	bfe1.nodeIds = nodeIds;
	mBFEs[boundaryFiniteElementId] = bfe1;
	mBFEsByNodeIds[nodeIds] = &mBFEs[boundaryFiniteElementId];
}

std::set<FiniteElement *>&
Mesh::findFEby3NodeIds(std::array<unsigned int, 3> nodeIds)
{
	if (mFEsBy3Nodes.find(nodeIds) == mFEsBy3Nodes.end()) {
		return *(new std::set<FiniteElement *>);
	}
	return mFEsBy3Nodes[nodeIds];
}

std::set<FiniteElement *>&
Mesh::findFEby2NodeIds(std::array<unsigned int, 2> nodeIds)
{
	if (mFEsBy2Nodes.find(nodeIds) == mFEsBy2Nodes.end()) {
		return *(new std::set<FiniteElement *>);
	}
	return mFEsBy2Nodes[nodeIds];
}
