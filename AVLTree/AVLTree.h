#ifndef AVLTree_h
#define AVLTree_h

#include <stdio.h>
#include <stdlib.h>
#include "QueueLL.h"
#include "Stack.h"


struct AVLTree{
    struct TreeNode * root;
};

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

struct TreeNode * LLRotation(struct TreeNode * t){
    struct TreeNode * lchild = t->left;
    
    t->left = lchild->right;
    lchild->right = t;
    //note that the order is important, update the new root last
    t->height = Height(t);
    lchild->height = Height(lchild);
    
    return lchild;
}

struct TreeNode * RRRotation(struct TreeNode * t){
    struct TreeNode * rchild = t->right;
    
    t->right = rchild->left;
    rchild->left = t;
    //note that the order is important, update the new root last
    t->height = Height(t);
    rchild->height = Height(rchild);
    
    return rchild;
}

struct TreeNode * LRRotation(struct TreeNode * t){
    t->left = RRRotation(t->left);
    return LLRotation(t);
}

struct TreeNode * RLRotation(struct TreeNode * t){
    t->right = LLRotation(t->right);
    return RRRotation(t);
}

int BalanceFactor(struct TreeNode * t){
    if(t == NULL){
        return 0;
    }
    return Height(t->left) - Height(t->right);
}

struct TreeNode * BalanceNode(struct TreeNode *t){
    if(BalanceFactor(t) > 1){
        if(BalanceFactor(t->left) >= 0){
            t = LLRotation(t);
        } else{
            t = LRRotation(t);
        }
    } else if(BalanceFactor(t) < -1){
        if(BalanceFactor(t->right) <= 0){
            t = RRRotation(t);
        } else{
            t = RLRotation(t);
        }
    }
    return t;
}

int InsertNode(struct AVLTree *b, int value){
    if(b == NULL){
        printf("Error: Invalid Tree.\n");
        return -1;
    }
    
    struct TreeNode * newNode = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    
    if(b->root == NULL){
        b->root = newNode;
        return 0;
    }
    
    struct TreeNode * temp = b->root;
    struct TreeNode * prev = temp;
    struct Stack s;
    InitializeStack(&s, 100);
    
    while(temp){
        Push(&s, temp);
        if(value == temp->value){
            printf("Error: Found duplicates.\n");
            free(newNode);
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
    
    while(!isEmpty(&s)){
        temp = Pop(&s);
        temp = BalanceNode(temp);
        if(!isEmpty(&s)){
            if(Top(&s)->left == temp){
                Top(&s)->left = temp;
            } else{
                Top(&s)->right = temp;
            }
        } else{
            b->root = temp;
        }
    }
    return 0;
}


struct TreeNode * HelperInsertNodeR(struct TreeNode *t, int value){
    if(t == NULL){
        struct TreeNode * newNode = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }
    
    if(t->value == value){
        printf("Found duplicates.\n");
        return t;
    } else if(t->value > value){
        t->left = HelperInsertNodeR(t->left, value);
    } else{
        t->right = HelperInsertNodeR(t->right, value);
    }
    // don't forget to update the height
    t->height = Height(t);
    return BalanceNode(t);
}

int InsertNodeR(struct AVLTree *a, int value){
    if(a == NULL){
        printf("Invalid tree.\n");
        return -1;
    }
    a->root = HelperInsertNodeR(a->root, value);
    return 0;
}

struct TreeNode * FindPredecessor(struct TreeNode * t){
    struct TreeNode * temp = t->left;
    while(temp->right){
        temp = temp->right;
    }
    return temp;
}

struct TreeNode * FindSuccessor(struct TreeNode * t){
    struct TreeNode * temp = t->right;
    while(temp->left){
        temp = temp->left;
    }
    return temp;
}

int DeleteIter(struct AVLTree *a, int value){
    
    if(a == NULL){
        printf("Invalid tree.\n");
        return -1;
    }
    
    struct TreeNode * curr = a->root;
    // for iter, we need a tail pointer for connection
    struct TreeNode * prev = NULL;
    
    struct Stack s;
    InitializeStack(&s, 100);
            
    while(curr != NULL){
        if(curr->value == value){
            break;
        }
        
        prev = curr;
        Push(&s, curr);
        if(curr->value > value){
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    
    if(curr == NULL){
        printf("No such element in the tree.\n");
        return -1;
    }
    
    if(curr->left && curr->right){
        
        struct TreeNode * pred = NULL;
        // for iter, we need a tail pointer for connection
        struct TreeNode * predParent = NULL;
        Push(&s, curr);
        
        if(Height(curr->left) > Height(curr->right)){
            pred = curr->left;
            while(pred->right){
                Push(&s, pred);
                predParent = pred;
                pred = pred->right;
            }
        } else{
            pred = curr->right;
            while(pred->left){
                Push(&s, pred);
                predParent = pred;
                pred = pred->left;
            }
        }
        curr->value = pred->value;
        prev = predParent;
        curr = pred;
    }
    
    // now deal with the case of 0/1 child together
    struct TreeNode * child = NULL;
    if(curr->left != NULL){
        child = curr->left;
    } else{
        child = curr->right;
    }
    
    // if prev = curr = root, then after removed only child lives
    if(prev == NULL){
        a->root = child;
    } else if(prev->right == curr){
        prev->right = child;
    } else {
        prev->left = child;
    } 
    free(curr);
    
    while(!isEmpty(&s)){
        struct TreeNode * c = Pop(&s);
        
        // backtracking for updating the height of the node and balancing the node
        c->height = Height(c);
        c = BalanceNode(c);
        // make sure after rotation the connection is updated
        if(!isEmpty(&s)){
            struct TreeNode * p = Top(&s);
            if(p->right == c){
                p->right = c;
            } else{
                p->left = c;
            }
        } else{
            // if the stack is empty, then specify the root
            a->root = c;
        }
    }
    return 0;
}

struct TreeNode * HelperDeleteNode(struct TreeNode *t, int value){
    if(t == NULL){
        printf("Target not found.\n");
        return t;
    }
    
    if(t->value > value){
        t->left = HelperDeleteNode(t->left, value);
    } else if(t->value < value){
        t->right = HelperDeleteNode(t->right, value);
    } else{
        struct TreeNode * temp = NULL;
        if(t->left == NULL){
            temp = t->right;
            free(t);
            return temp;
        } else if(t->right == NULL){
            temp = t->left;
            free(t);
            return temp;
        } else {
            struct TreeNode * pred = NULL;
            if(Height(t->left) > Height(t->right)){
                pred = FindPredecessor(t);
                t->value = pred->value;
                t->left = HelperDeleteNode(t->left, pred->value);
            } else{
                pred = FindSuccessor(t);
                t->value = pred->value;
                t->right = HelperDeleteNode(t->right, pred->value);
            }
        }
    }
    t->height = Height(t);
    return BalanceNode(t);
}

int DeleteR(struct AVLTree *b, int value){
    
    if(b == NULL || b->root == NULL){
        printf("Error: Tree is empty.\n");
        return -1;
    }
    b->root = HelperDeleteNode(b->root, value);
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

void FreeTree(struct TreeNode *t){
    if(t != NULL){
        FreeTree(t->left);
        FreeTree(t->right);
        free(t);
    }
}

#endif /* AVLTree_h */
