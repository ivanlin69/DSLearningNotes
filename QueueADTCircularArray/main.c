#include <stdio.h>
#include "QueueCircularArray.h"

int main(int argc, const char * argv[]) {
    struct Queue q1;
    CreateQueue(&q1, 5);
    printf("Empty?: %d\n", IsEmpty(&q1));
    printf("Full?: %d\n", IsFull(&q1));
    EnQueue(&q1, 12);
    EnQueue(&q1, 14);
    EnQueue(&q1, 15);
    EnQueue(&q1, 23);
    EnQueue(&q1, 27);
    EnQueue(&q1, 72);
    
    printf("Dequeue: %d\n", DeQueue(&q1));
    printf("Dequeue: %d\n", DeQueue(&q1));
    printf("Dequeue: %d\n", DeQueue(&q1));
    printf("Empty?: %d\n", IsEmpty(&q1));
    printf("Full?: %d\n", IsFull(&q1));
    
    printf("Dequeue: %d\n", DeQueue(&q1));
    printf("Dequeue: %d\n", DeQueue(&q1));
    printf("Dequeue: %d\n", DeQueue(&q1));
    printf("Dequeue: %d\n", DeQueue(&q1));
    
    printf("Empty?: %d\n", IsEmpty(&q1));
    printf("Full?: %d\n", IsFull(&q1));
    
    EnQueue(&q1, 15);
    EnQueue(&q1, 23);
    EnQueue(&q1, 15);
    EnQueue(&q1, 23);
    
    printf("Dequeue: %d\n", DeQueue(&q1));
    printf("Dequeue: %d\n", DeQueue(&q1));
    
    FreeQueue(&q1);
    
    
    return 0;
}
