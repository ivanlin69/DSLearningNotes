#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <stdlib.h>

class Stack{
private:
    int * A;
    int size;
    int top;
    
public:
    Stack(int size);
    void Push(int e);
    int Pop();
    int Peek(int index) const;
    int Top() const;
    int isEmpty() const;
    int isFull() const;
    ~Stack();
};

#endif /* Stack_hpp */
