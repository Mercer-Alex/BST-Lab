build:
	g++ -g -o bst main.cpp

test: build
	valgrind --leak-check=full ./bst
