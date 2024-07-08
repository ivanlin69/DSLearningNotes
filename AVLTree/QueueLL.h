#ifndef QueueLL_h
#define QueueLL_h

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


struct Queue{
    int rear;
    struct LinkedList * A;
};

void CreateQueue(struct Queue *q){
    q->rear = -1;
    q->A = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    Initialize(q->A);
}

void EnQueue(struct Queue *q, struct TreeNode *e){
    if(AddEnd(q->A, e) == 0){
        q->rear++;
    } else {
        printf("EnQueue failed.\n");
    }
}

struct TreeNode * DeQueue(struct Queue *q){
    if(q->rear != -1){
        struct TreeNode * removed = q->A->head->value;
        DeleteFront(q->A);
        q->rear--;
        return removed;
    }
    printf("Queue is empty.\n");
    return NULL;
}

int IsEmpty(struct Queue *q){
    return q->rear == -1;
}

int IsFull(struct Queue *q){
    struct Node * temp = (struct Node *) malloc(sizeof(struct Node));
    return !temp;
}

void FreeQueue(struct Queue *q){
    freeLinkedlist(q->A);
    free(q->A);
    q->A = NULL;
    q->rear = -1;
}

#endif /* QueueLL_h */
