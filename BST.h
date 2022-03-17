#ifndef BST_LAB_BST_H
#define BST_LAB_BST_H
#include <iostream>
#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST: public BSTInterface {
public:
    BST() {}
    ~BST() {
        clear();
    }
    //Please note that the class that implements this interface must be made
    //of objects which implement the NodeInterface

    /*
    * Returns the root node for this tree
    *
    * @return the root node for this tree.
    */
    Node<int>* getRootNode() const {
        return root;
    }

    bool add(int data) {
        return _add(this->root, data);
    }
    bool _add(Node<int>* node, int item) {
        if (node == nullptr) {
            node = new Node<int>(item);
            return true;
        }
        if (node->getData() == item) {
            return false;
        }
        else if (item < node->getData()) {
            return _add(node->getLeftChild(), item);
        }
        else {
            return _add(node->getRightChild(), item);
        }
    }

    bool remove(int data) {
        return _remove(this->root, data);
    }
    bool _remove(Node<int>* node, int item) {
        if (node == nullptr) {
            return false;
        }
        if (node->getData() == item) {
             if (node->getLeftChild() == nullptr) {
                 auto tmp = node;
                 node = node->getRightChild();
                 delete tmp;
                 return true;
             }
             else if (node->getRightChild() == nullptr) {
                 auto tmp = node;
                 node = node->getLeftChild();
                 delete tmp;
                 return true;
             }
             else {
                 //two children, swap iop
                int iop_value = _get_iop_value(node);
                node->setData(iop_value);
                 _remove(node->getLeftChild(), iop_value);
                 return true;
             }
        }
        else if (item < node->getData() ) {
            return _remove(node->getLeftChild(), item);
        }
        else {
            return _remove(node->getRightChild(), item);
        }
    }
    int _get_iop_value(Node<int>* node) {
        auto tmp = node->getLeftChild();
        while (tmp->getRightChild() != nullptr) {
            tmp = tmp->getRightChild();
        }
        return tmp->getData();
    }


    void clear() {
        _clear(this->root);
    }

    void _clear(Node<int>* node) {
         if (node == nullptr) {
             return;
         }
         _clear(node->getLeftChild());
         _clear(node->getRightChild());
         delete node;
    }

protected:
    Node<int>* root;
};


#endif //BST_LAB_BST_H
