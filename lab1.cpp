#include <string.h>
#include <iostream>
#include "CompareCoordinates.h"

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
		std::cout << it << std::endl;
	}
	std::cout << "List of BFE" << std::endl;
	for (auto it: mesh.getBoundaryFiniteElements()) {
		std::cout << it << std::endl;
	}
	return 0;
}
