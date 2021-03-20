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

    AVLnode<T> *root;
public:

    AVLtree<T>(){

    }
    AVLnode<T> *insertHelper(T x, AVLnode<T> *t);

    AVLnode<T> *rightRotate(AVLnode<T> *&t);

    AVLnode<T> *leftRotate(AVLnode<T> *&t);

    AVLnode<T> *findMin(AVLnode<T> *t);

    AVLnode<T> *findMax(AVLnode<T> *t);

    int height();

    int heightHelper(AVLnode<T> *t);

    bool validate();

    bool validateHelper(AVLnode<T> *root);

    void insert(T x);

    bool containsHelper(AVLnode<T> *root, T val);

    bool contains(T val);


};
/*
private:
    AVLnode* node;

public:
    AVLtree();
    int height(AVLnode *N);
   // void insert(int);
    bool contains(int);
    bool validate();

    AVLnode* newNode(int key);
    AVLnode *rightRotate(AVLnode *y);
    AVLnode *leftRotate(AVLnode *x);
    int getBalance(AVLnode *N);
    AVLnode* insert(AVLnode* node, int key);
    void preOrder(AVLnode *root);

    void insertHelper(AVLnode*, int key);
};
*/
#endif //CPTS_223_AVLTREE_H

