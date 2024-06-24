#include "QueueADT.hpp"
#include <iostream>

Queue::Queue(int size) : first(-1), rear(-1), size(size){
    A = new int[size];
}

void Queue::Enqueue(int e){
    if(rear != size-1){
        A[++(rear)] = e;
    } else {
        std::cout << "Queue is full.\n";
    }
}

int Queue::Dequeue(){
    if(rear == first){
        std::cout << "Queue is empty.\n";
        return -1;
    }
    return A[(first++)+1];
}

int Queue::isEmpty(){
    return rear == first;
}

int Queue::isFull(){
    return rear == size-1;
}

int Queue::First(){
    if(!isEmpty()){
        return A[first+1];
    }
    std::cout << "Queue is empty.\n";
    return -1;
}

int Queue::Last(){
    if(!isEmpty()){
        return A[rear];
    }
    std::cout << "Queue is empty.\n";
    return -1;
}

Queue::~Queue(){
    delete [] A;
}
