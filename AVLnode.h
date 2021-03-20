//
// Created by jake on 3/20/21.
//

#ifndef CPTS_223_AVLNODE_H
#define CPTS_223_AVLNODE_H

class AVLnode
{
public:
    int data;
    AVLnode *left;
    AVLnode *right;
    int height;

    AVLnode(){
        data = 0;
        left = nullptr;
        right = nullptr;
        height = 0;
    }
};

#endif //CPTS_223_AVLNODE_H
