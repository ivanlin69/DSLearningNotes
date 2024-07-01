#include <stdio.h>
#include "Stack.h"

int main(int argc, const char * argv[]) {
    
    struct Stack s1;
    InitializeStack(&s1, 6);
    
    printf("Is empty: %d \n", isEmpty(&s1));
    printf("Is full: %d \n", isFull(&s1));
    Push(&s1, 34);
    Push(&s1, 12);
    Push(&s1, 3);
    Push(&s1, 45);
    Push(&s1, 67);
    Push(&s1, 102);
    Push(&s1, 77);
    printf("Is full: %d \n", isFull(&s1));
    
    printf("Top is: %d \n", Top(&s1));
    printf("Pop: %d \n", Pop(&s1));
    printf("Top is: %d \n", Top(&s1));
    printf("Is empty: %d \n", isEmpty(&s1));
    
    printf("Pop again: %d \n", Pop(&s1));
    printf("Peek 0: %d \n", Peek(&s1, 0));
    printf("Peek 1: %d \n", Peek(&s1, 1));
    printf("Peek 2: %d \n", Peek(&s1, 2));
    printf("Peek 3: %d \n", Peek(&s1, 3));
    printf("Peek 4: %d \n", Peek(&s1, 4));
    
    FreeStack(&s1);
    
    return 0;
}
