#include <iostream>
#include <fstream>
#include <stdexcept>

#include "AneuMeshLoader.h"

Mesh&
AneuMeshLoader::loadMesh(const std::string& filename)
{
	std::ifstream fileIn;
	fileIn.open(filename);

	if (!fileIn.is_open()) {
		throw std::runtime_error("File not open!");
	}

	Mesh *mesh = new Mesh();
	loadNodes(fileIn, mesh);
	loadFiniteElements(fileIn, mesh);
	loadBoundaryFiniteElements(fileIn, mesh);
	fileIn.close();
	return *mesh;
}

void
AneuMeshLoader::loadNodes(std::ifstream &fileIn, Mesh* mesh)
{
	unsigned int amount;
	unsigned int size;
	double x, y, z;

	fileIn >> amount;
	std::cout << "amount1=" << amount << std::endl;
	fileIn >> size;
	std::cout << "size1=" << size << std::endl;

	if (size != 3) {
		throw std::runtime_error("Wrong size of Node!");
	}

	for (int i=1; i<=amount; i++) {
		fileIn >> x >> y >> z;
		mesh->addNode(x, y, z, i);
	}

}

void
AneuMeshLoader::loadFiniteElements(std::ifstream &fileIn, Mesh* mesh)
{
	unsigned int amount;
	unsigned int size;
	unsigned int materialId;
	unsigned int nodeIds[4];

	fileIn >> amount;
	std::cout << "amount2=" << amount << std::endl;
	fileIn >> size;
	std::cout << "size2=" << size << std::endl;

	if (size != 4) {
		throw std::runtime_error("Wrong size of FE!");
	}

	for (int i=1; i<=amount; i++) {
		fileIn >> materialId >> nodeIds[0] >> nodeIds[1] >> nodeIds[2] >> nodeIds[3];
		mesh->addFiniteElement(i, materialId, nodeIds);
	}
}

void
AneuMeshLoader::loadBoundaryFiniteElements(std::ifstream &fileIn, Mesh* mesh)
{
	unsigned int amount;
	unsigned int size;
	unsigned int boundaryId;
	unsigned int nodeIds[3];

	fileIn >> amount;
	std::cout << "amount3=" << amount << std::endl;
	fileIn >> size;
	std::cout << "size3=" << size << std::endl;

	if (size != 3) {
		throw std::runtime_error("Wrong size of Node!");
	}

	for (int i=1; i<=amount; i++) {
		fileIn >> boundaryId >> nodeIds[0] >> nodeIds[1] >> nodeIds[2];
		std::cout << boundaryId << nodeIds[0] << nodeIds[1] << nodeIds[2] << std::endl;
	}
}
