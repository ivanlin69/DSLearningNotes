#include <iostream>
#include "Stack.hpp"

int main(int argc, const char * argv[]) {
    
    struct Stack s1(6);
    
    printf("Is empty: %d \n", s1.isEmpty());
    printf("Is full: %d \n", s1.isFull());
    s1.Push(34);
    s1.Push(12);
    s1.Push(3);
    s1.Push(45);
    s1.Push(67);
    s1.Push(102);
    s1.Push(77);
    printf("Is full: %d \n", s1.isFull());
    
    printf("Top is: %d \n", s1.Top());
    printf("Pop: %d \n", s1.Pop());
    printf("Top is: %d \n", s1.Top());
    printf("Is empty: %d \n", s1.isEmpty());
    
    printf("Pop again: %d \n", s1.Pop());
    printf("Peek 0: %d \n", s1.Peek(0));
    printf("Peek 1: %d \n", s1.Peek(1));
    printf("Peek 2: %d \n", s1.Peek(2));
    printf("Peek 3: %d \n", s1.Peek(3));
    printf("Peek 4: %d \n", s1.Peek(4));

    return 0;
}
