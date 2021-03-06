#include <string.h>
#include <iostream>

#include "AneuMeshLoader.h"

int main (int argc, char *argv[]) {
	AneuMeshLoader loader;
	if (!argv[1] || strlen(argv[1]) == 0) {
		std::cout << "Usage:" << std::endl;
		std::cout << "  lab1 FILENAME" << std::endl;
		return 0;
	}
	Mesh mesh = loader.loadMesh(argv[1]);
	std::cout << "List of nodes" << std::endl;
	for (auto it: mesh.getNodes()) {
		std::cout << it.second << std::endl;
	}
	std::cout << "List of FE" << std::endl;
	for (auto it: mesh.getFininiteElements()) {
		std::cout << it.second << std::endl;
	}
	std::cout << "List of BFE" << std::endl;
	for (auto it: mesh.getBoundaryFiniteElements()) {
		std::cout << it.second << std::endl;
	}
	std::array<unsigned int, 3> nodeIds3 = {1, 2, 7};
	std::cout << "List of FE with {1, 2, 7}" << std::endl;
	for (auto it: mesh.findFEby3NodeIds(nodeIds3)) {
		std::cout << *it << std::endl;
	}
	std::array<unsigned int, 2> nodeIds2 = {2, 8};
	std::cout << "List of FE with {2, 8}" << std::endl;
	for (auto it: mesh.findFEby2NodeIds(nodeIds2)) {
		std::cout << *it << std::endl;
	}
	std::cout << "Nodes in boundary 1" << std::endl;
	for (auto it: mesh.findNodesByBoundaryId(1)) {
		std::cout << *it << std::endl;
	}
	std::cout << "List of FE by material 1" << std::endl;
	for (auto it: mesh.findFEsByMaterialId(1)) {
		std::cout << *it << std::endl;
	}
	std::cout << "List of nodes by edges from node 1" << std::endl;
	for (auto it: (mesh.findNodesByEdge().at(1))) {
		std::cout << *it << std::endl;
	}
	std::cout << "List of BFE by boundary 4" << std::endl;
	for (auto it: mesh.findBFEsByBoundaryId(4)) {
		std::cout << *it << std::endl;
	}
	return 0;
}
