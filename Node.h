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
public:
    Node() {
    }
    ~Node() {}

    /*
    * Returns the data that is stored in this node
    *
    * @return the data that is stored in this node.
    */
    int getData() const {
        return value;
    }

    /*
    * Returns the left child of this node or null if it doesn't have one.
    *
    * @return the left child of this node or null if it doesn't have one.
    */
    NodeInterface * getLeftChild() const {
        if (left == nullptr) {
            return nullptr;
        }
        return left;
    }

    /*
    * Returns the right child of this node or null if it doesn't have one.
    *
    * @return the right child of this node or null if it doesn't have one.
    */
    NodeInterface * getRightChild() const {
        if (right == nullptr) {
            return nullptr;
        }
        return right;
    }

};

#endif //BST_LAB_NODE_H
