#pragma once

#include <vector>
#include <iostream>

struct Node
{
	unsigned int id;
	std::array<double, 3> coordinates;
	bool isVertex;

	Node() = default;
	Node(unsigned int, std::array<double, 3>, bool);

	friend std::ostream& operator<<(std::ostream&, const Node&);
};

struct FiniteElement
{
	unsigned int finiteElementId;
	unsigned int materialId;
	unsigned int nodeIds[4];

	friend std::ostream& operator<<(std::ostream&, const FiniteElement&);
};

struct BoundaryFiniteElement
{
	unsigned int boundaryFiniteElementId;
	unsigned int boundaryId;
	unsigned int nodeIds[3];

	friend std::ostream& operator<<(std::ostream&, const BoundaryFiniteElement&);
};
