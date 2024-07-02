#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    struct TreeNode * left;
    struct TreeNode * right;
    int value;
};

struct Node{
    struct TreeNode *value;
    struct Node *next;
};

struct LinkedList{
    size_t length;
    struct Node *head;
    struct Node *tail;
};

void Initialize(struct LinkedList *l);
int AddEnd(struct LinkedList * l, struct TreeNode * e);
int AddFront(struct LinkedList * l, struct TreeNode * e);
void DeleteFront(struct LinkedList * l);
void Delete(struct LinkedList * l, size_t index);
int Insert(struct LinkedList * l, size_t index, struct TreeNode * e);

void freeLinkedlist(struct LinkedList *l);

#endif /* LinkedList_h */
