#pragma once

#include <vector>

#include "Structures.h"

class Mesh
{
public:
	Mesh();
	~Mesh();
	void addNode (double x, double y, double z);
//	std::vector<Node>& getNodes();
//	std::vector<FiniteElement>& getFininiteElements();
//	std::vector<BoundaryFiniteElement>& getBoundaryFiniteElements();
};

