#include <iostream>

#include "Mesh.h"

Mesh::Mesh ()
{
}

Mesh::~Mesh ()
{
}

void
Mesh::addNode(double x, double y, double z)
{
	std::cout << "x=" << x << "   y=" << y << "   z=" << z << std::endl;
}
