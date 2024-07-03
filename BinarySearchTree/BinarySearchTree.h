#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdio.h>
#include <stdlib.h>
#include "QueueLL.h"
#include "Stack.h"


struct BinarySearchTree{
    struct TreeNode * root;
};

int SearchTree(struct BinarySearchTree *b, int value){
    if(b == NULL || b->root == NULL){
        printf("Not found.\n");
        return 0;
    }
    
    struct TreeNode * temp = b->root;
    while(temp){
        if(value == temp->value){
            printf("Target found.\n");
            return 1;
        } else if(value > temp->value){
            temp = temp->right;
        } else{
            temp = temp->left;
        }
    }
    printf("Not found.\n");
    return 0;
}

int SearchTreeR(struct TreeNode *t, int value){
    if(t == NULL){
        printf("Not found.\n");
        return 0;
    }
    
    if(value == t->value){
        printf("Target found.\n");
        return 1;
    } else if(value > t->value){
        return SearchTreeR(t->right, value);
    } else{
        return SearchTreeR(t->left, value);
    }

    printf("Not found.\n");
    return 0;
}

int InsertNode(struct BinarySearchTree *b, int value){
    if(b == NULL){
        printf("Error: Invalid Tree.\n");
        return -1;
    }
    
    struct TreeNode * newNode = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    
    if(b->root == NULL){
        b->root = newNode;
        return 0;
    }
    
    struct TreeNode * temp = b->root;
    struct TreeNode * prev = temp;
    
    while(temp){
        if(value == temp->value){
            printf("Error: Found duplicates.\n");
            return -1;
        } else if(value > temp->value){
            prev = temp;
            temp = temp->right;
        } else{
            prev = temp;
            temp = temp->left;
        }
    }
    
    if(value > prev->value){
        prev->right = newNode;
    } else{
        prev->left = newNode;
    }
    return 0;
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

void FreeTree(struct TreeNode *t){
    if(t != NULL){
        FreeTree(t->left);
        FreeTree(t->right);
        free(t);
    }
}

#endif /* BinaryTree_h */
