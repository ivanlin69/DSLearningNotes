#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdlib.h>
#include "QueueLL.h"


struct BinaryTree{
    struct TreeNode * root;
    struct Queue * q;
};

void CreateBinaryTree(struct BinaryTree *b){
    
    b->root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    b->q = (struct Queue *) malloc(sizeof(struct Queue));
    CreateQueue(b->q);
    int x;
    printf("Enter root value:\n");
    scanf("%d", &x);
    
    b->root->value = x;
    b->root->right = NULL;
    b->root->left = NULL;
    EnQueue(b->q, b->root);
    
    while(!IsEmpty(b->q)){
        struct TreeNode * curr = DeQueue(b->q);
        
        printf("Enter %d's left child's value(-1 if NULL):\n", curr->value);
        scanf("%d", &x);
        if(x != -1){
            curr->left = (struct TreeNode *) malloc(sizeof(struct TreeNode));
            curr->left->value = x;
            curr->left->left = NULL;
            curr->left->right = NULL;
            EnQueue(b->q, curr->left);
        }
        
        printf("Enter %d's the right child's value(-1 if NULL):\n", curr->value);
        scanf("%d", &x);
        if(x != -1){
            curr->right = (struct TreeNode *) malloc(sizeof(struct TreeNode));
            curr->right->value = x;
            curr->right->left = NULL;
            curr->right->right = NULL;
            EnQueue(b->q, curr->right);
        }
    }
}

void DisplayPreOrder(struct TreeNode *t){
    if(t == NULL){
        return;
    }
    printf("%d ", t->value);
    DisplayPreOrder(t->left);
    DisplayPreOrder(t->right);
}

void DisplayInOrder(struct TreeNode *t){
    if(t == NULL){
        return;
    }
    DisplayInOrder(t->left);
    printf("%d ", t->value);
    DisplayInOrder(t->right);
}

void DisplayPostOrder(struct TreeNode *t){
    if(t == NULL){
        return;
    }
    DisplayPostOrder(t->left);
    DisplayPostOrder(t->right);
    printf("%d ", t->value);
}



#endif /* BinaryTree_h */
