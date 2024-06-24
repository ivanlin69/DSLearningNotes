#include "QueueADT.hpp"
#include <iostream>

template<class T>
Queue<T>::Queue(int size) : first(-1), rear(-1), size(size){
    A = new T[size];
}

template<class T>
void Queue<T>::Enqueue(T e){
    if(rear != size-1){
        A[++(rear)] = e;
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
    return A[(first++)+1];
}

template<class T>
int Queue<T>::isEmpty(){
    return rear == first;
}

template<class T>
int Queue<T>::isFull(){
    return rear == size-1;
}

template<class T>
T Queue<T>::First(){
    if(!isEmpty()){
        return A[first+1];
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
