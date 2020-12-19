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
		std::cout << it << std::endl;
	}
	std::cout << "List of FE" <<std::endl;
	for (auto it: mesh.getFininiteElements()) {
		std::cout << it << std::endl;
	}
	return 0;
}
