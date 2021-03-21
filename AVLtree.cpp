#include<iostream>
#include "AVLtree.h"

using namespace std;

template <typename T>
void AVLtree<T>::insert(T val) {
    root = insertHelper(val, root);
}

template <typename T>
AVLnode<T> *AVLtree<T>::insertHelper(T val, AVLnode<T> *node) {
    if (node == nullptr) { // if root node is null make a new node
        node = new AVLnode<T>;
        node->data = val;
    } else if (val < node->data) { // check on left branch
        node->left = insertHelper(val, node->left);
        if (heightHelper(node->left) - heightHelper(node->right) == 2) { // if height difference is more than 2
            if (val < node->left->data)
                node = rightRotate(node);
            else {
                node->left = leftRotate(node->left);
                node = rightRotate(node);
            }
        }
    } else if (val > node->data) { // check on right branch
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
    AVLnode<T> *e = node->left; //temp node to be returned
    node->left = e->right;
    e->right = node;
    node->height = max(heightHelper(node->left), heightHelper(node->right)) + 1; // check height
    e->height = max(heightHelper(e->left), node->height) + 1;
    return e;
}

template <typename T>
AVLnode<T> *AVLtree<T>::leftRotate(AVLnode<T> *&node) { // same process as right rotate, different branch
    AVLnode<T> *e = node->right;
    node->right = e->left;
    e->left = node;
    node->height = max(heightHelper(node->left), heightHelper(node->right)) + 1;
    e->height = max(heightHelper(node->right), node->height) + 1;
    return e;
}

template <typename T>
int AVLtree<T>::height() {
    return heightHelper(root);
}

template <typename T> // find the height of the tree
int AVLtree<T>::heightHelper(AVLnode<T> *node) {
    return (node == nullptr ? 0 : node->height);
}

template <typename T> // validate the tree to be an AVL tree
bool AVLtree<T>::validate() {
    return validateHelper(root);
}

template <typename T>
bool AVLtree<T>::validateHelper(AVLnode<T> *root) {
    if (root == nullptr)
        return 1;

    int lNode = heightHelper(root->left); // find left height
    int rNode = heightHelper(root->right); // find right height
    if (abs(lNode - rNode) <= 1 && validateHelper(root->left) && validateHelper(root->right))
        return 1; // compare and return true if difference is less than or equal to 1
    return 0;
}

template <typename T>
bool AVLtree<T>::containsHelper(AVLnode<T> *root, T val){
    if (root == nullptr)
        return false;
    if (val == root->data) //check node data
        return true;
    if (val < root->data)
        return containsHelper(root->left, val); // recursively check AVL tree
    return containsHelper(root->right, val);
}

template <typename T>
bool AVLtree<T>::contains(T val) {
    return containsHelper(root, val);
}
// used for referencing to main
template class AVLnode<int>;
template class AVLtree<int>;