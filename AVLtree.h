//
// Created by jake on 3/20/21.
//
#ifndef CPTS_223_AVLTREE_H
#define CPTS_223_AVLTREE_H

#include "AVLnode.h"
#include <iostream>
using namespace std;


class AVLtree
{
    AVLnode* root;
public:

    AVLtree(): root(nullptr){}
    void makeEmpty(AVLnode* t);
    AVLnode* insert(int x, AVLnode* t);
    AVLnode* singleRightRotate(AVLnode* &t);
    AVLnode* singleLeftRotate(AVLnode* &t);
    AVLnode* doubleLeftRotate(AVLnode* &t);
    AVLnode* doubleRightRotate(AVLnode* &t);
    AVLnode* findMin(AVLnode* t);
    AVLnode* findMax(AVLnode* t);
    int height(AVLnode* t);
    void inorder(AVLnode* t);

    void insert(int x)
    {
        root = insert(x, root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }

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

