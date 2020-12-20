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
	std::array<unsigned int, 4> nodeIds;

	friend std::ostream& operator<<(std::ostream&, const FiniteElement&);
};

struct BoundaryFiniteElement
{
	unsigned int boundaryFiniteElementId;
	unsigned int boundaryId;
	std::array<unsigned int, 3> nodeIds;

	friend std::ostream& operator<<(std::ostream&, const BoundaryFiniteElement&);
};
