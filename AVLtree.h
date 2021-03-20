//
// Created by jake on 3/20/21.
//
#ifndef CPTS_223_AVLTREE_H
#define CPTS_223_AVLTREE_H

#include "AVLnode.h"
#include <iostream>

using namespace std;


class AVLtree {
    AVLnode *root;
public:

    AVLtree() : root(nullptr) {}

    AVLnode *insertHelper(int x, AVLnode *t);

    AVLnode *rightRotate(AVLnode *&t);

    AVLnode *leftRotate(AVLnode *&t);

    AVLnode *findMin(AVLnode *t);

    AVLnode *findMax(AVLnode *t);

    int height();

    int heightHelper(AVLnode *t);

    bool validate();

    bool validateHelper(AVLnode *root);

    void insert(int x);

    bool containsHelper(AVLnode *root, int val);

    bool contains(int val);


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

