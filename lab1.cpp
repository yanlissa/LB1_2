#include <iostream>

#include "AneuMeshLoader.h"

int main () {
	AneuMeshLoader loader;
	Mesh mesh = loader.LoadMesh("1.aneu");
	return 0;
}
