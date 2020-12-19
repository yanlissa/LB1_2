#include <iostream>

#include "Mesh.h"

Mesh::Mesh ()
{
}

Mesh::~Mesh ()
{
}

void
Mesh::addNode(double x, double y, double z, unsigned int k)
{
	Node node1(k,x,y,z,false);
	m_nodes.push_back(node1);
}
