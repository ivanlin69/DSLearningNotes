#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct Queue{
    int size;
    int rear;
    struct Stack * s1;
    struct Stack * s2;
};

void CreateQueue(struct Queue *q, int size){
    q->size = size;
    q->rear = -1;
    q->s1 = (struct Stack *) malloc(sizeof(struct Stack));
    q->s2 = (struct Stack *) malloc(sizeof(struct Stack));
    InitializeStack(q->s1, size);
    InitializeStack(q->s2, size);
}

void EnQueue(struct Queue *q, int e){
    if(q->rear < q->size-1){
        Push(q->s1, e);
        q->rear++;
    } else{
        printf("Queue is full.\n");
    }
}

int DeQueue(struct Queue *q){
    if(q->rear == -1){
        printf("Queue is empty.\n");
        return -1;
    }
    while(!isEmpty(q->s1)){
        Push(q->s2, Pop(q->s1));
    }
    q->rear--;
    return Pop(q->s2);
}

int IsQueueEmpty(struct Queue *q){
    return q->rear == -1;
}

int IsQueueFull(struct Queue *q){
    return q->rear == q->size-1;
}

int First(struct Queue *q){
    if(!IsQueueEmpty(q)){
        if(isEmpty(q->s2)){
            while(!isEmpty(q->s1)){
                Push(q->s2, Pop(q->s1));
            }
        }
        return Top(q->s2);
    }
    printf("Queue is empty.\n");
    return -1;
}

int Last(struct Queue *q){
    if(!IsQueueEmpty(q)){
        if(isEmpty(q->s1)){
            return Peek(q->s2, q->rear);
        } else {
            return Top(q->s1);
        }
    }
    printf("Queue is empty.\n");
    return -1;
}

void FreeQueue(struct Queue *q){
    FreeStack(q->s1);
    FreeStack(q->s2);
    free(q->s1);
    free(q->s2);
    q->s1 = NULL;
    q->s2 = NULL;
    q->rear = -1;
    q->size = 0;
}

int main(int argc, const char * argv[]) {
    struct Queue q1;
    CreateQueue(&q1, 5);
    printf("Empty?: %d\n", IsQueueEmpty(&q1));
    printf("Full?: %d\n", IsQueueFull(&q1));
    EnQueue(&q1, 12);
    EnQueue(&q1, 14);
    EnQueue(&q1, 15);
    EnQueue(&q1, 23);
    EnQueue(&q1, 27);
    EnQueue(&q1, 72);
    
    printf("First: %d\n", First(&q1));
    printf("Last: %d\n", Last(&q1));
    
    printf("Dequeue: %d\n", DeQueue(&q1));
    printf("Dequeue: %d\n", DeQueue(&q1));
    printf("Dequeue: %d\n", DeQueue(&q1));
    
    printf("First: %d\n", First(&q1));
    printf("Last: %d\n", Last(&q1));
    
    printf("Empty?: %d\n", IsQueueEmpty(&q1));
    printf("Full?: %d\n", IsQueueFull(&q1));
    
    printf("Dequeue: %d\n", DeQueue(&q1));
    printf("Dequeue: %d\n", DeQueue(&q1));
    printf("Dequeue: %d\n", DeQueue(&q1));
    printf("Dequeue: %d\n", DeQueue(&q1));
    
    printf("First: %d\n", First(&q1));
    printf("Last: %d\n", Last(&q1));
    
    printf("Empty?: %d\n", IsQueueEmpty(&q1));
    printf("Full?: %d\n", IsQueueFull(&q1));
    
    EnQueue(&q1, 15);
    EnQueue(&q1, 23);
    EnQueue(&q1, 15);
    EnQueue(&q1, 23);
    
    printf("Dequeue: %d\n", DeQueue(&q1));
    printf("Dequeue: %d\n", DeQueue(&q1));
    
    FreeQueue(&q1);
    return 0;
}
