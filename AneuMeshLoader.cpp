#include <iostream>
#include <fstream>
#include <stdexcept>

#include "AneuMeshLoader.h"

Mesh&
AneuMeshLoader::LoadMesh(const std::string& filename)
{
	std::ifstream filein;
	filein.open(filename);

	if (!filein.is_open()) {
		throw std::runtime_error("File not open!");
	}

	unsigned int amount1;
	unsigned int size1;
	double x, y, z;

	filein >> amount1;
	std::cout << "amount1=" << amount1 << std::endl;
	filein >> size1;
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
		filein >> x >> y >> z;
		mesh->addNode(x, y, z, i);
	}

	unsigned int amount2;
	unsigned int size2;
	unsigned int material_id;
	unsigned int node_ids[4];

	filein >> amount2;
	std::cout << "amount2=" << amount2 << std::endl;
	filein >> size2;
	std::cout << "size2=" << size2 << std::endl;

	if (size2 != 4) {
		throw std::runtime_error("Wrong size of FE!");
	}

	for (int i=1; i<=amount2; i++) {
		filein >> material_id >> node_ids[0] >> node_ids[1] >> node_ids[2] >> node_ids[3];
		std::cout << material_id << "  " << node_ids[0] << "  " << node_ids[1] << "  " << node_ids[2] << "  " 
			<< node_ids[3] << std::endl;
	}

	filein.close();
	return *mesh;
}

