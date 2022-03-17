build:
	g++ -g -o bst BST.h Node.h main.cpp

test: build
	valgrind --leak-check=full ./bst
