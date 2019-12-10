all: main.o
	g++ *.o -o test.exe

main.o: main.cpp
	g++ main.cpp -c -o main.o

test: all
	test.exe
