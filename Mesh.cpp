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
	mNodes.push_back(node1);
}

void
Mesh::addFiniteElement(unsigned int k, unsigned int materialId, unsigned int* nodeIds)
{
	FiniteElement fe1;
	fe1.finiteElementId = k;
	fe1.materialId = materialId;
	fe1.nodeIds[0] = nodeIds[0];
	fe1.nodeIds[1] = nodeIds[1];
	fe1.nodeIds[2] = nodeIds[2];
	fe1.nodeIds[3] = nodeIds[3];
	mFEs.push_back(fe1);
	//std::cout << mFEs.length << std::endl;
}
