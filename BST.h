#ifndef BST_LAB_BST_H
#define BST_LAB_BST_H
#include <iostream>
#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST: public BSTInterface {
public:
    BST() {
        root = nullptr;
    }
    ~BST() {
        _clear(root);
    }

    NodeInterface* getRootNode() const {
        return root;
    }

    bool add(int data) {
        return _add(this->root, data);
    }
    bool _add(Node<int>*& node, int item) {
        if (node == nullptr) {
            node = new Node<int>(item);
            return true;
        }
        if (node->value == item) {
            return false;
        }
        else if (item < node->value) {
            return _add(node->left, item);
        }
        else {
            return _add(node->right, item);
        }
    }

    bool remove(int data) {
        return _remove(this->root, data);
    }
    bool _remove(Node<int>*& node, int item) {
        if (node == nullptr) {
            return false;
        }
        if (node->getData() == item) {
             if (node->left == nullptr) {
                Node<int>* tmp = node;
                node = node->right;
                delete tmp;
                return true;
             }
             else if (node->right == nullptr) {
                Node<int>* tmp = node;
                node = node->left;
                delete tmp;
                return true;
             }
             else {
                int const& iop_value = _get_iop_value(node);
                node->value = iop_value;
                 _remove(node->left, iop_value);
                 return true;
             }
        }
        else if (item < node->value) {
            return _remove(node->left, item);
        }
        else {
            return _remove(node->right, item);
        }
    }
    int _get_iop_value(Node<int>* const& node) {
        auto tmp = node->left;
        while (tmp->right != nullptr) {
            tmp = tmp->right;
        }
        return tmp->value;
    }

    void clear() {
        _clear(this->root);
        root = nullptr;
    }
    void _clear(Node<int>*& node) {
         if (node == nullptr) {
            return;
         }
         _clear(node->left);
         _clear(node->right);
         delete node;
    }

protected:
    Node<int>* root;
};

#endif //BST_LAB_BST_H
