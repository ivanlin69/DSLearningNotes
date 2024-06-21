#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.hpp"

class Stack{
    
private:
    LinkedList *l;
    int size;
    int top;
    
public:
    Stack(int size);
    void Push(int e);
    int Pop();
    int Peek(int index);
    int Top();
    int isEmpty();
    int isFull();
    void FreeStack();
    ~Stack();
};

#endif /* Stack_hpp */
