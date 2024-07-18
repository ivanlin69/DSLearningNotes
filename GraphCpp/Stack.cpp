#include "Stack.hpp"
#include "LinkedList.hpp"
#include <stdio.h>
#include <iostream>

template<class T>
Stack<T>::Stack(int size) : size(size), top(-1){
    l = new LinkedList<T>();
}

template<class T>
void Stack<T>::Push(T e){
    if(top < size-1){
        l->AddFront(e);
        top++;
        
    } else {
        std::cout << "Stack is full.\n";
    }
}

template<class T>
T Stack<T>::Pop(){
    if(top < 0){
        std::cout << "Stack is empty.\n";
        return NULL;
    }
    T value = l->getHead()->value;
    l->DeleteFront();
    top--;
    return value;
}

template<class T>
T Stack<T>::Peek(int index){
    if(index <0 || index > top){
        std::cout << "Index out of bound.\n";
        return -1;
    }
    Node<T> * temp = l->getHead();
    for(size_t i=0; i<index; i++){
        temp = temp->next;
    }
    return temp->value;
}

template<class T>
T Stack<T>::Top(){
    if(top >= 0){
        return l->getHead()->value;
    }
    std::cout << "Stack is empty.\n";
    return NULL;
}

template<class T>
int Stack<T>::isEmpty(){
    return top == -1;
}

template<class T>
int Stack<T>::isFull(){
    return top == size-1;
}

template<class T>
Stack<T>::~Stack(){
    delete (l);
}

