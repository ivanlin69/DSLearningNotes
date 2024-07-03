#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdlib.h>
#include "QueueLL.h"
#include "Stack.h"


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
    FreeQueue(&q);
}

void DisplayPreOrder(struct TreeNode *t){
    if(t == NULL){
        return;
    }
    printf("%d ", t->value);
    DisplayPreOrder(t->left);
    DisplayPreOrder(t->right);
}

void DisplayPreOrderIter(struct TreeNode *t){
    
    if(t == NULL){
        return;
    }
    
    struct Stack s;
    InitializeStack(&s, 30);
    
    struct TreeNode * curr = t;
    
    while(curr != NULL || !isEmpty(&s)){
        
        if(curr != NULL){
            Push(&s, curr);
            printf("%d ", curr->value);
            curr = curr->left;
        } else{
            curr = Pop(&s);
            curr = curr->right;
        }
    }
    FreeStack(&s);
}

void DisplayInOrder(struct TreeNode *t){
    if(t == NULL){
        return;
    }
    DisplayInOrder(t->left);
    printf("%d ", t->value);
    DisplayInOrder(t->right);
}

void DisplayInOrderIter(struct TreeNode *t){
    
    if(t == NULL){
        return;
    }
    
    struct Stack s;
    InitializeStack(&s, 30);
    
    struct TreeNode * curr = t;
    
    while(curr != NULL || !isEmpty(&s)){
        
        if(curr != NULL){
            Push(&s, curr);
            curr = curr->left;
        } else{
            curr = Pop(&s);
            printf("%d ", curr->value);
            curr = curr->right;
        }
    }
    FreeStack(&s);
}

void DisplayPostOrder(struct TreeNode *t){
    if(t == NULL){
        return;
    }
    DisplayPostOrder(t->left);
    DisplayPostOrder(t->right);
    printf("%d ", t->value);
}

void DisplayPostOrderIter(struct TreeNode *t){
    
    if(t == NULL){
        return;
    }
    
    struct Stack s1;
    struct Stack s2;
    InitializeStack(&s1, 30);
    InitializeStack(&s2, 30);
    
    struct TreeNode * curr = t;
    Push(&s1, curr);
    
    while(!isEmpty(&s1)){
        curr = Pop(&s1);
        Push(&s2, curr);
        if(curr->left){
            Push(&s1, curr->left);
        }
        if(curr->right){
            Push(&s1, curr->right);
        }
    }
    
    while(!isEmpty(&s2)){
        curr = Pop(&s2);
        printf("%d ", curr->value);
    }
    FreeStack(&s1);
    FreeStack(&s2);
}

void DisplayLevelOrder(struct TreeNode *t){
    
    if(t == NULL){
        return;
    }
    
    struct Queue q;
    CreateQueue(&q);
    struct TreeNode * curr = t;
    EnQueue(&q, curr);
    
    while(!IsEmpty(&q)){
        curr = DeQueue(&q);
        printf("%d ", curr->value);
        if(curr->left){
            EnQueue(&q, curr->left);
        }
        if(curr->right){
            EnQueue(&q, curr->right);
        }
    }
    FreeQueue(&q);
}

int CountOfNodes(struct TreeNode *t){
    int l, r;
    if(t != NULL){
        l = CountOfNodes(t->left);
        r = CountOfNodes(t->right);
        return l+r+1;
    }
    return 0;
}

int CountOfNodesDeg2(struct TreeNode *t){
    if(t != NULL){
        int l = CountOfNodesDeg2(t->left);
        int r = CountOfNodesDeg2(t->right);
        if(t->left && t->right){
            return l+r+1;
        }
        return l+r;
    }
    return 0;
}

int CountLeafNodes(struct TreeNode *t){
    if(t != NULL){
        int l = CountOfNodesDeg2(t->left);
        int r = CountOfNodesDeg2(t->right);
        if(!t->left && !t->right){
            return l+r+1;
        }
        return l+r;
    }
    return 0;
}

//Note: The height of an empty tree is 0 and the height of a tree with single node is 1.
int Height(struct TreeNode *t){
    if(t != NULL){
        int l = Height(t->left);
        int r = Height(t->right);
        if(l > r){
            return l + 1;
        }
        return r + 1;
    }
    return 0;
}
#endif /* BinaryTree_h */
