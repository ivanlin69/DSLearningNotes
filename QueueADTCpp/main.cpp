#include <iostream>
#include "QueueADT.hpp"
#include "QueueADT.cpp"

int main(int argc, const char * argv[]) {
    
    Queue<int> q(5);
    
    printf("Empty?: %d\n", q.isEmpty());
    printf("Full?: %d\n", q.isFull());
    q.Enqueue(12);
    q.Enqueue(14);
    q.Enqueue(15);
    q.Enqueue(23);
    q.Enqueue(27);
    q.Enqueue(72);
    
    printf("Dequeue: %d\n", q.Dequeue());
    printf("Dequeue: %d\n", q.Dequeue());
    printf("Dequeue: %d\n", q.Dequeue());
    printf("Empty?: %d\n", q.isEmpty());
    printf("Full?: %d\n", q.isFull());
    
    printf("Dequeue: %d\n", q.Dequeue());
    printf("Dequeue: %d\n", q.Dequeue());
    printf("Dequeue: %d\n", q.Dequeue());
    
    // The cons that using array to implement a queue, is that the
    //  first element will also move forward, causing the available space to shrink
    printf("Empty?: %d\n", q.isEmpty());
    printf("Full?: %d\n", q.isFull());
    
    return 0;
}
