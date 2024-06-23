#include <stdio.h>
#include <stdlib.h>


struct Queue{
    int * A;
    int first;
    int size;
    int rear;
};

void CreateQueue(struct Queue *q, int size){
    q->A = (int *) malloc(sizeof(int)*size);
    q->first = -1;
    q->rear = -1;
    q->size = size;
}

void Enqueue(struct Queue *q, int e){
    if(q->rear != q->size-1){
        q->A[++(q->rear)] = e;
    } else {
        printf("Queue is full.\n");
    }
}

int Dequeue(struct Queue *q){
    if(q->rear == q->first){
        printf("Queue is empty.\n");
        return -1;
    }
    return q->A[(q->first++)+1];
}

int isEmpty(struct Queue *q){
    return q->rear == -1 || q->rear == q->first;
}

int isFull(struct Queue *q){
    return q->rear == q->size-1;
}

int First(struct Queue *q){
    if(!isEmpty(q)){
        return q->A[(q->first)+1];
    }
    printf("Queue is empty.\n");
    return -1;
}

int Last(struct Queue *q){
    if(!isEmpty(q)){
        return q->A[q->rear];
    }
    printf("Queue is empty.\n");
    return -1;
}

void FreeQueue(struct Queue *q){
    free(q->A);
    q->A = NULL;
    q->first = -1;
    q->rear = -1;
    q->size = 0;
}

int main(int argc, const char * argv[]) {
    
    struct Queue q1;
    CreateQueue(&q1, 5);
    printf("Empty?: %d\n", isEmpty(&q1));
    printf("Full?: %d\n", isFull(&q1));
    Enqueue(&q1, 12);
    Enqueue(&q1, 14);
    Enqueue(&q1, 15);
    Enqueue(&q1, 23);
    Enqueue(&q1, 27);
    Enqueue(&q1, 72);
    
    printf("Dequeue: %d\n", Dequeue(&q1));
    printf("Dequeue: %d\n", Dequeue(&q1));
    printf("Dequeue: %d\n", Dequeue(&q1));
    printf("Empty?: %d\n", isEmpty(&q1));
    printf("Full?: %d\n", isFull(&q1));
    
    printf("Dequeue: %d\n", Dequeue(&q1));
    printf("Dequeue: %d\n", Dequeue(&q1));
    printf("Dequeue: %d\n", Dequeue(&q1));
    printf("Dequeue: %d\n", Dequeue(&q1));
    
    // The cons that using array to implement a queue, is that the
    //  first element will also move forward, causing the available space to shrink
    printf("Empty?: %d\n", isEmpty(&q1));
    printf("Full?: %d\n", isFull(&q1));
    
    FreeQueue(&q1);
    
    return 0;
}
