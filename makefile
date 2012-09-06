all: quickSort

clean:
	rm quickSort.o quickSort

quickSort: quickSort.o
	g++ -g -o quickSort quickSort.o

quickSort.o: quickSort.cpp
	g++ -c -g quickSort.cpp