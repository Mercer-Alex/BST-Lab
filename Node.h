#ifndef BST_LAB_NODE_H
#define BST_LAB_NODE_H
#include <iostream>
#include "NodeInterface.h"

template<class T>
class Node: public NodeInterface {
private:
    T value;
    Node<T>* left;
    Node<T>* right;
    friend class BST;

public:
    Node(T item) {
        value = item;
        left = nullptr;
        right = nullptr;
    }
    ~Node() {}

    int getData() const {
        return value;
    }

    NodeInterface* getLeftChild() const {
        if (left == nullptr) {
            return nullptr;
        }
        return left;
    }

    NodeInterface* getRightChild() const {
        if (right == nullptr) {
            return nullptr;
        }
        return right;
    }
};

#endif //BST_LAB_NODE_H
