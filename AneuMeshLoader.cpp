#include <iostream>
#include <fstream>
#include <stdexcept>

#include "AneuMeshLoader.h"

Mesh&
AneuMeshLoader::LoadMesh(const std::string& filename)
{
	std::ifstream fileIn;
	fileIn.open(filename);

	if (!fileIn.is_open()) {
		throw std::runtime_error("File not open!");
	}

	unsigned int amount1;
	unsigned int size1;
	double x, y, z;

	fileIn >> amount1;
	std::cout << "amount1=" << amount1 << std::endl;
	fileIn >> size1;
	std::cout << "size1=" << size1 << std::endl;
//	Nodes.reserve(amount);

//	for (int i=0; i<amount; i++)
//	{
//		filein >> x >> y >> z;
//		Nodes.push_back(Node(i, x, y, z, false));
//	}

	if (size1 != 3) {
		throw std::runtime_error("Wrong size of Node!");
	}

	Mesh *mesh = new Mesh();
	for (int i=1; i<=amount1; i++) {
		fileIn >> x >> y >> z;
		mesh->addNode(x, y, z, i);
	}

	unsigned int amount2;
	unsigned int size2;
	unsigned int materialId;
	unsigned int nodeIds[4];

	fileIn >> amount2;
	std::cout << "amount2=" << amount2 << std::endl;
	fileIn >> size2;
	std::cout << "size2=" << size2 << std::endl;

	if (size2 != 4) {
		throw std::runtime_error("Wrong size of FE!");
	}

	for (int i=1; i<=amount2; i++) {
		fileIn >> materialId >> nodeIds[0] >> nodeIds[1] >> nodeIds[2] >> nodeIds[3];
		mesh->addFiniteElement(i, materialId, nodeIds);
	}

	fileIn.close();
	return *mesh;
}

