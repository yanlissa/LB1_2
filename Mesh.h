#pragma once

#include <functional>
#include <map>
#include <set>
#include <vector>

#include "Structures.h"

class Mesh
{
private:
	std::map<unsigned int, Node> mNodes;
	std::map<std::array<double, 3>, Node *> mNodesByCoordinates;
	std::map<unsigned int, FiniteElement> mFEs;
	std::map<std::array<unsigned int, 4>, FiniteElement *> mFEsByNodeIds;
	std::map<unsigned int, BoundaryFiniteElement> mBFEs;
	std::map<std::array<unsigned int, 3>, BoundaryFiniteElement *> mBFEsByNodeIds;
	std::map<std::array<unsigned int, 3>, std::set<FiniteElement *>> mFEsBy3Nodes;
	std::map<std::array<unsigned int, 2>, std::set<FiniteElement *>> mFEsBy2Nodes;
	std::map<unsigned int, std::set<Node *>> mNodesByBoundaryId;
public:
	Mesh();
	~Mesh();
	void addNode (std::array<double, 3> coordinates, unsigned int k);
	const std::map<unsigned int, Node>& getNodes() const { return mNodes; };
	void addFiniteElement (unsigned int finiteElementId, unsigned int materialId, std::array<unsigned int, 4> nodeIds);
	const std::map<unsigned int, FiniteElement>& getFininiteElements() const { return mFEs; };
	void addBoundaryFiniteElement (unsigned int boundaryFiniteElementId, unsigned int boundaryId, std::array<unsigned int, 3> nodeIds);
	const std::map<unsigned int, BoundaryFiniteElement>& getBoundaryFiniteElements() const { return mBFEs; };
	std::set<FiniteElement *>& findFEby3NodeIds(std::array<unsigned int, 3> nodeIds);
	std::set<FiniteElement *>& findFEby2NodeIds(std::array<unsigned int, 2> nodeIds);
	std::set<Node *>& findNodesByBoundaryId(unsigned int boundaryId);
};

