all: lab1

%.o: %.cpp *.h Makefile
	g++ -c $< -o $@

lab1: lab1.o
	g++ -o lab1 $^

clean:
	rm *.o

test: all
	./lab1
