#include "Stack.hpp"
#include "LinkedList.hpp"
#include <stdio.h>
#include <iostream>


Stack::Stack(int size) : size(size), top(-1){
    l = new LinkedList();
}

void Stack::Push(int e){
    if(top < size-1){
        l->AddFront(e);
        top++;
        
    } else {
        std::cout << "Stack is full.\n";
    }
}

int Stack::Pop(){
    if(top < 0){
        std::cout << "Stack is empty.\n";
        return -1;
    }
    int value = l->getHead()->value;
    l->DeleteFront();
    top--;
    return value;
}

int Stack::Peek(int index){
    if(index <0 || index > top){
        std::cout << "Index out of bound.\n";
        return -1;
    }
    Node * temp = l->getHead();
    for(size_t i=0; i<index; i++){
        temp = temp->next;
    }
    return temp->value;
}

int Stack::Top(){
    if(top >= 0){
        return l->getHead()->value;
    }
    std::cout << "Stack is empty.\n";
    return -1;
}

int Stack::isEmpty(){
    return top == -1;
}

int Stack::isFull(){
    return top == size-1;
}

Stack::~Stack(){
    delete (l);
}

