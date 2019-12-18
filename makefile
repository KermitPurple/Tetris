all: main.o
	g++ *.o -o test.exe -lwinmm

main.o: main.cpp
	g++ main.cpp -c -o main.o -lwinmm

test: all
	test.exe
