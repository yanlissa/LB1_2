#pragma once

#include <vector>
#include <iostream>

struct Node
{
	unsigned int id;
	double x, y, z;
	bool versh;

	Node() = default;
	Node(unsigned int, double, double, double, bool);

	friend std::ostream& operator<<(std::ostream&, const Node&);
};

struct FiniteElement
{
	unsigned int id_FinElement;
	unsigned int id_material;
	unsigned int id_nodes[4];

	friend std::ostream& operator<<(std::ostream&, const FiniteElement&);
};

struct BoundaryFiniteElement
{
	unsigned int id_BoundFinElement;
	unsigned int id_granica;

	friend std::ostream& operator<<(std::ostream&, const BoundaryFiniteElement&);
};
