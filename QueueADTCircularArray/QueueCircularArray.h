#ifndef QueueCircularArray_h
#define QueueCircularArray_h

#include <stdio.h>
#include <stdlib.h>


struct Queue{
    int size;
    int front;
    int rear;
    int * A;
};

void CreateQueue(struct Queue *q, int size){
    q->size = size+1;
    q->front = 0;
    q->rear = 0;
    // need 1 extra space for allocating front
    q->A = (int *) malloc(sizeof(int)*(size+1));
}

void EnQueue(struct Queue *q, int e){
    if((q->rear+1)%(q->size) == q->front){
        printf("Queue is full.\n");
        return;
    }
    q->rear = (q->rear+1)%(q->size); // move forward circularly
    q->A[q->rear] = e;
}

int DeQueue(struct Queue *q){
    if(q->rear == q->front){
        printf("Queue is empty.\n");
        return -1;
    }
    q->front = (q->front+1)%(q->size); // move forward circularly
    return q->A[q->front];
}

int IsEmpty(struct Queue *q){
    return q->rear == q->front;
}

int IsFull(struct Queue *q){
    return (q->rear+1)%(q->size) == q->front;
}

int First(struct Queue *q){
    if(!IsEmpty(q)){
        return q->A[(q->front+1)%(q->size)];
    }
    printf("Queue is empty.\n");
    return -1;
}

int Last(struct Queue *q){
    if(!IsEmpty(q)){
        return q->A[q->rear];
    }
    printf("Queue is empty.\n");
    return -1;
}

void FreeQueue(struct Queue *q){
    free(q->A);
    q->A = NULL;
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

#endif /* QueueCircularArray_h */
