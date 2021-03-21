#include<iostream>
#include "AVLtree.h"

using namespace std;

template <typename T>
void AVLtree<T>::insert(T val) {
    root = insertHelper(val, root);
}

template <typename T>
AVLnode<T> *AVLtree<T>::insertHelper(T val, AVLnode<T> *node) {
    if (node == nullptr) {
        node = new AVLnode<T>;
        node->data = val;
    } else if (val < node->data) {
        node->left = insertHelper(val, node->left);
        if (heightHelper(node->left) - heightHelper(node->right) == 2) {
            if (val < node->left->data)
                node = rightRotate(node);
            else {
                node->left = leftRotate(node->left);
                node = rightRotate(node);
            }
        }
    } else if (val > node->data) {
        node->right = insertHelper(val, node->right);
        if (heightHelper(node->right) - heightHelper(node->left) == 2) {
            if (val > node->right->data)
                node = leftRotate(node);
            else {
                node->right = rightRotate(node->right);
                node = leftRotate(node);
            }
        }
    }
    node->height = max(heightHelper(node->left), heightHelper(node->right)) + 1;
    return node;
}

template <typename T>
AVLnode<T> *AVLtree<T>::rightRotate(AVLnode<T> *&node) {
    AVLnode<T> *e = node->left;
    node->left = e->right;
    e->right = node;
    node->height = max(heightHelper(node->left), heightHelper(node->right)) + 1;
    e->height = max(heightHelper(e->left), node->height) + 1;
    return e;
}

template <typename T>
AVLnode<T> *AVLtree<T>::leftRotate(AVLnode<T> *&t) {
    AVLnode<T> *u = t->right;
    t->right = u->left;
    u->left = t;
    t->height = max(heightHelper(t->left), heightHelper(t->right)) + 1;
    u->height = max(heightHelper(t->right), t->height) + 1;
    return u;
}

template <typename T>
AVLnode<T> *AVLtree<T>::findMin(AVLnode<T> *node) {
    if (node == nullptr)
        return nullptr;
    else if (node->left == nullptr)
        return node;
    else
        return findMin(node->left);
}

template <typename T>
AVLnode<T> *AVLtree<T>::findMax(AVLnode<T> *node) {
    if (node == nullptr)
        return nullptr;
    else if (node->right == nullptr)
        return node;
    else
        return findMax(node->right);
}

template <typename T>
int AVLtree<T>::height() {
    return heightHelper(root);
}

template <typename T>
int AVLtree<T>::heightHelper(AVLnode<T> *node) {
    return (node == nullptr ? 0 : node->height);
}

template <typename T>
bool AVLtree<T>::validate() {
    return validateHelper(root);
}

template <typename T>
bool AVLtree<T>::validateHelper(AVLnode<T> *root) {
    if (root == nullptr)
        return 1;

    int lNode = heightHelper(root->left);
    int rNode = heightHelper(root->right);
    if (abs(lNode - rNode) <= 1 && validateHelper(root->left) && validateHelper(root->right))
        return 1;
    return 0;
}

template <typename T>
bool AVLtree<T>::containsHelper(AVLnode<T> *root, T val){
    if (root == nullptr)
        return false;
    if (val == root->data)
        return true;
    if (val < root->data)
        return containsHelper(root->left, val);
    return containsHelper(root->right, val);
}

template <typename T>
bool AVLtree<T>::contains(T val) {
    return containsHelper(root, val);
}


template class AVLnode<int>;
template class AVLtree<int>;