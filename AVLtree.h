//
// Created by jake on 3/20/21.
//
#ifndef CPTS_223_AVLTREE_H
#define CPTS_223_AVLTREE_H

#include "AVLnode.h"
#include <iostream>

using namespace std;

template <typename T>
class AVLtree {
protected:
    AVLnode<T> *root;
public:

    AVLtree<T>():root(nullptr){}

    ~AVLtree<T>(){
        delete root;
    }
    AVLnode<T> *insertHelper(T val, AVLnode<T> *node);

    AVLnode<T> *rightRotate(AVLnode<T> *&node);

    AVLnode<T> *leftRotate(AVLnode<T> *&node);

    AVLnode<T> *findMin(AVLnode<T> *node);

    AVLnode<T> *findMax(AVLnode<T> *node);

    int height();

    int heightHelper(AVLnode<T> *node);

    bool validate();

    bool validateHelper(AVLnode<T> *root);

    void insert(T val);

    bool containsHelper(AVLnode<T> *root, T val);

    bool contains(T val);


};
#endif //CPTS_223_AVLTREE_H

