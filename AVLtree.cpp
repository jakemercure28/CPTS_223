#include<iostream>
#include "AVLtree.h"

using namespace std;

    AVLnode* AVLtree::insert(int x, AVLnode* t)
    {
        if(t == NULL)
        {
            t = new AVLnode;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
        {
            t->left = insert(x, t->left);
            if(heightHelper(t->left) - heightHelper(t->right) == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            t->right = insert(x, t->right);
            if(heightHelper(t->right) - heightHelper(t->left) == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(heightHelper(t->left), heightHelper(t->right))+1;
        return t;
    }

    AVLnode* AVLtree::singleRightRotate(AVLnode* &t)
    {
        AVLnode* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(heightHelper(t->left), heightHelper(t->right))+1;
        u->height = max(heightHelper(u->left), t->height)+1;
        return u;
    }

    AVLnode* AVLtree::singleLeftRotate(AVLnode* &t)
    {
        AVLnode* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(heightHelper(t->left), heightHelper(t->right))+1;
        u->height = max(heightHelper(t->right), t->height)+1 ;
        return u;
    }

    AVLnode* AVLtree::doubleLeftRotate(AVLnode* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    AVLnode* AVLtree::doubleRightRotate(AVLnode* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    AVLnode* AVLtree::findMin(AVLnode* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    AVLnode* AVLtree::findMax(AVLnode* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }
    int AVLtree::heightHelper(AVLnode* t){
        return (t == NULL ? -1 : t->height);
    }
    int AVLtree::height()
    {
        return heightHelper(root);
    }

    bool AVLtree::validateHelper(AVLnode* root){
        if(root == NULL)
            return 1;

        int lNode = heightHelper(root->left);
        int rNode = heightHelper(root->right);
        if(abs(lNode-rNode) <= 1 && validateHelper(root->left) && validateHelper(root->right))
            return 1;
        return 0;
    }
    bool AVLtree::validate(){
        return validateHelper(root);
    }