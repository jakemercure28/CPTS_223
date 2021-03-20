#include<iostream>
#include "AVLtree.h"

using namespace std;

    void AVLtree::insert(int x)
    {
        root = insertHelper(x, root);
    }

    AVLnode* AVLtree::insertHelper(int x, AVLnode* t)
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
            t->left = insertHelper(x, t->left);
            if(heightHelper(t->left) - heightHelper(t->right) == 2)
            {
                if(x < t->left->data)
                    t = rightRotate(t);
                else
                    t->left = leftRotate(t->left);

            }
        }
        else if(x > t->data)
        {
            t->right = insertHelper(x, t->right);
            if(heightHelper(t->right) - heightHelper(t->left) == 2)
            {
                if(x > t->right->data)
                    t = leftRotate(t);
                else
                    t->right = rightRotate(t->right);
            }
        }

        t->height = max(heightHelper(t->left), heightHelper(t->right))+1;
        return t;
    }

    AVLnode* AVLtree::rightRotate(AVLnode* &t)
    {
        AVLnode* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(heightHelper(t->left), heightHelper(t->right))+1;
        u->height = max(heightHelper(u->left), t->height)+1;
        return u;
    }

    AVLnode* AVLtree::leftRotate(AVLnode* &t)
    {
        AVLnode* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(heightHelper(t->left), heightHelper(t->right))+1;
        u->height = max(heightHelper(t->right), t->height)+1 ;
        return u;
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
int AVLtree::height()
{
    return heightHelper(root);
}
int AVLtree::heightHelper(AVLnode* t){
        return (t == NULL ? -1 : t->height);
    }


bool AVLtree::validate(){
    return validateHelper(root);
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
