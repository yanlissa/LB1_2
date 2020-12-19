#pragma once

#include <vector>

#include "Structures.h"

class Mesh
{
public:
	Mesh();
	~Mesh();
	std::vector<Node>& getNodes();
//	std::vector<FiniteElement>& getFininiteElements();
//	std::vector<BoundaryFiniteElement>& getBoundaryFiniteElements();
};

