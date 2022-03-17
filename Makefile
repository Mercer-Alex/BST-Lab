build:
	g++ -g -std=c++11 -o test BST.h Node.h
test: build
	valgrind --leak-check=full ./test