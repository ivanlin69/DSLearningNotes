#include "Queue.hpp"
#include <iostream>

template<class T>
Queue<T>::Queue(int size) : first(0), rear(0), size(size+1){
    A = new T[size+1];
}

template<class T>
void Queue<T>::Enqueue(T e){
    if((rear+1)%size != first){
        // move forward circularly
        rear = (rear+1)%size;
        A[rear] = e;
    } else {
        std::cout << "Queue is full.\n";
    }
}

template<class T>
T Queue<T>::Dequeue(){
    if(rear == first){
        std::cout << "Queue is empty.\n";
        return -1;
    }
    // move forward circularly
    first = (first+1)%size;
    return A[first];
}

template<class T>
int Queue<T>::isEmpty(){
    return rear == first;
}

template<class T>
int Queue<T>::isFull(){
    return (rear+1)%size == first;
}

template<class T>
T Queue<T>::First(){
    if(!isEmpty()){
        return A[(first+1)%size];
    }
    std::cout << "Queue is empty.\n";
    return -1;
}

template<class T>
T Queue<T>::Last(){
    if(!isEmpty()){
        return A[rear];
    }
    std::cout << "Queue is empty.\n";
    return -1;
}

template<class T>
Queue<T>::~Queue(){
    delete [] A;
}
