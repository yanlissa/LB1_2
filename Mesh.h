#pragma once

#include <vector>

#include "Structures.h"

class Mesh
{
private:
	std::vector<Node> m_nodes;
public:
	Mesh();
	~Mesh();
	void addNode (double x, double y, double z, unsigned int k);
	const std::vector<Node>& getNodes() const { return m_nodes; };
//	std::vector<FiniteElement>& getFininiteElements();
//	std::vector<BoundaryFiniteElement>& getBoundaryFiniteElements();
};

