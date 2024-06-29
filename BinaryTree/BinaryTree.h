#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdlib.h>
#include <QueueLL.h>

struct Node{
    struct Node * left;
    struct Node * right;
    int value;
};

struct Tree{
    struct Node * root;
}

#endif /* BinaryTree_h */
