//
// Created by jake on 3/20/21.
//

#ifndef CPTS_223_AVLNODE_H
#define CPTS_223_AVLNODE_H

template <typename T>
class AVLnode
{
public:
    T data;
    AVLnode *left;
    AVLnode *right;
    int height;

    AVLnode<T>(){
        data = 0;
        left = nullptr;
        right = nullptr;
        height = 0;
    }

    ~AVLnode(){
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 0;
    }
};

#endif //CPTS_223_AVLNODE_H
