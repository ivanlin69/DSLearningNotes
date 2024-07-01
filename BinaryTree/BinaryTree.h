#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdlib.h>
#include "QueueLL.h"


struct BinaryTree{
    struct TreeNode * root;
};

void CreateBinaryTree(struct BinaryTree *b){
    
    b->root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    struct Queue q;
    CreateQueue(&q);
    int x;
    printf("Enter root value:\n");
    scanf("%d", &x);
    
    b->root->value = x;
    b->root->right = NULL;
    b->root->left = NULL;
    EnQueue(&q, b->root);
    
    while(!IsEmpty(&q)){
        struct TreeNode * curr = DeQueue(&q);
        
        printf("Enter %d's left child's value(-1 if NULL):\n", curr->value);
        scanf("%d", &x);
        if(x != -1){
            curr->left = (struct TreeNode *) malloc(sizeof(struct TreeNode));
            curr->left->value = x;
            curr->left->left = NULL;
            curr->left->right = NULL;
            EnQueue(&q, curr->left);
        }
        
        printf("Enter %d's the right child's value(-1 if NULL):\n", curr->value);
        scanf("%d", &x);
        if(x != -1){
            curr->right = (struct TreeNode *) malloc(sizeof(struct TreeNode));
            curr->right->value = x;
            curr->right->left = NULL;
            curr->right->right = NULL;
            EnQueue(&q, curr->right);
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
