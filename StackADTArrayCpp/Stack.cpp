#include "Stack.hpp"
#include <stdio.h>
#include <stdlib.h>

Stack::Stack(int size) : size(size), top(-1){
    A = new int[size];
}

void Stack::Push(int e){
    if(top < size-1){
        A[++top] = e;
        
    } else {
        printf("Stack is full.\n");
    }
}

int Stack::Pop(){
    if(top < 0){
        printf("Stack is empty.\n");
        return -1;
    }
    return A[top--];
}

int Stack::Peek(int index) const{
    if(index <0 || index > top){
        printf("Index out of bound.\n");
        return -1;
    }
    return A[top-index];
}

int Stack::Top() const{
    if(top >= 0){
        return A[top];
    }
    printf("Stack is empty.\n");
    return -1;
}

int Stack::isEmpty() const{
    return top == -1;
}

int Stack::isFull() const{
    return top == size-1;
}

Stack::~Stack(){
    delete [] A;
}
