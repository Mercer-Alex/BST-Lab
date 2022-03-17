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

//    void setData(T data) {
//        this->value = data;
//    }

    NodeInterface* getLeftChild() const {
        if (left == nullptr) {
            return nullptr;
        }
        return left;
    }

//    void setLeftChild(T data) {
//        left = new Node<T>(data);
//    }
//    void setLeftChild(Node<T>* node) {
//        left = node;
//    }

    NodeInterface* getRightChild() const {
        if (right == nullptr) {
            return nullptr;
        }
        return right;
    }

//    void setRightChild(T data) {
//        right = new Node<T>(data);
//    }
//    void setRightChild(Node<T>* node) {
//        right = node;
//    }

};

#endif //BST_LAB_NODE_H
