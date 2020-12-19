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
	Mesh mesh = loader.LoadMesh(argv[1]);
	return 0;
}
