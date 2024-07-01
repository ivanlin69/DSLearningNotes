#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

struct LinkedList{
    size_t length;
    struct Node *head;
    struct Node *tail;
};

void Initialize(struct LinkedList *l);
int AddEnd(struct LinkedList * l, int e);
int AddFront(struct LinkedList * l, int e);
void DeleteFront(struct LinkedList * l);
void Delete(struct LinkedList * l, size_t index);
int Insert(struct LinkedList * l, size_t index, int e);

// only applied fot an sorted linkedlist
int InsertSorted(struct LinkedList * l, int e);

void DisplayLL(struct LinkedList * l);
int Sum(struct LinkedList * l);
int Max(struct LinkedList * l);
struct Node * Search(struct LinkedList *l, int value);
int IsSorted(struct LinkedList * l);
void Reverse(struct LinkedList * l);
int HaveLoop(struct LinkedList * l);
void freeLinkedlist(struct LinkedList *l);

#endif /* LinkedList_h */
