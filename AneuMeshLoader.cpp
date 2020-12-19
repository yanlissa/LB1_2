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

	unsigned int amount;
	unsigned int size;
	double x, y, z;

	filein >> amount;
	std::cout << "amount=" << amount << std::endl;
	filein >> size;
	std::cout << "size=" << size << std::endl;
//	Nodes.reserve(amount);

//	for (int i=0; i<amount; i++)
//	{
//		filein >> x >> y >> z;
//		Nodes.push_back(Node(i, x, y, z, false));
//	}

	for (int i=0; i<amount; i++)
	{
		filein >> x >> y >> z;
		std::cout << "x=" << x << "   y=" << y << "   z=" << z << std::endl;
	}
	filein.close();
	return *(new Mesh());
}

