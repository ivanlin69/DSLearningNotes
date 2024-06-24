#include "Queue.hpp"
#include <iostream>

template<class T>
Queue<T>::Queue(int size) : rear(-1), size(size){
    A = new LinkedList<T>();
}

template<class T>
void Queue<T>::Enqueue(T e){
    if(rear != size-1){
        A->AddEnd(e);
        rear++;
    } else {
        std::cout << "Queue is full.\n";
    }
}

template<class T>
T Queue<T>::Dequeue(){
    if(rear == -1){
        std::cout << "Queue is empty.\n";
        return -1;
    }
    int removed = A->getHead()->value;
    A->DeleteFront();
    rear--;
    return removed;
}

template<class T>
int Queue<T>::isEmpty(){
    return rear == -1;
}

template<class T>
int Queue<T>::isFull(){
    return rear == size-1;
}

template<class T>
T Queue<T>::First(){
    if(!isEmpty()){
        return A->head->value;
    }
    std::cout << "Queue is empty.\n";
    return -1;
}

template<class T>
T Queue<T>::Last(){
    if(!isEmpty()){
        return A->tail->value;
    }
    std::cout << "Queue is empty.\n";
    return -1;
}

template<class T>
Queue<T>::~Queue(){
    delete A;
}
