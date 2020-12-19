all: lab1

%.o: %.cpp *.h Makefile
	g++ -c $< -o $@

lab1: CompareCoordinates.o Structures.o Mesh.o AneuMeshLoader.o lab1.o
	g++ -o lab1 $^

clean:
	rm *.o

test: all
	./lab1 cube.aneu
