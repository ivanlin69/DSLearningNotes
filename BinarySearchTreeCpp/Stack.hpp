#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.hpp"

template<class T>
class Stack{
    
private:
    LinkedList<T> *l;
    int size;
    int top;
    
public:
    Stack(int size);
    void Push(T e);
    T Pop();
    T Peek(int index);
    T Top();
    int isEmpty();
    int isFull();
    void FreeStack();
    ~Stack();
};

#endif /* Stack_hpp */
