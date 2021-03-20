#include<iostream>
#include "AVLtree.h"

using namespace std;

template <typename T>
void AVLtree<T>::insert(T x) {
    root = insertHelper(x, root);
}

template <typename T>
AVLnode<T> *AVLtree<T>::insertHelper(T x, AVLnode<T> *t) {
    if (t == nullptr) {
        t = new AVLnode<T>;
        t->data = x;
        t->height = 0;
        t->left = t->right = nullptr;
    } else if (x < t->data) {
        t->left = insertHelper(x, t->left);
        if (heightHelper(t->left) - heightHelper(t->right) == 2) {
            if (x < t->left->data)
                t = rightRotate(t);
            else
                t->left = leftRotate(t->left);
        }
    } else if (x > t->data) {
        t->right = insertHelper(x, t->right);
        if (heightHelper(t->right) - heightHelper(t->left) == 2) {
            if (x > t->right->data)
                t = leftRotate(t);
            else
                t->right = rightRotate(t->right);
        }
    }
    t->height = max(heightHelper(t->left), heightHelper(t->right)) + 1;
    return t;
}

template <typename T>
AVLnode<T> *AVLtree<T>::rightRotate(AVLnode<T> *&t) {
    AVLnode<T> *u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = max(heightHelper(t->left), heightHelper(t->right)) + 1;
    u->height = max(heightHelper(u->left), t->height) + 1;
    return u;
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
AVLnode<T> *AVLtree<T>::findMin(AVLnode<T> *t) {
    if (t == nullptr)
        return nullptr;
    else if (t->left == nullptr)
        return t;
    else
        return findMin(t->left);
}

template <typename T>
AVLnode<T> *AVLtree<T>::findMax(AVLnode<T> *t) {
    if (t == nullptr)
        return nullptr;
    else if (t->right == nullptr)
        return t;
    else
        return findMax(t->right);
}

template <typename T>
int AVLtree<T>::height() {
    return heightHelper(root);
}

template <typename T>
int AVLtree<T>::heightHelper(AVLnode<T> *t) {
    return (t == nullptr ? -1 : t->height);
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