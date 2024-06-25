#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int * A;
    int size;
    int top;
};

void InitializeStack(struct Stack *s, int size){
    
    s->A = (int *) malloc(sizeof(int)*size);
    s->size = size;
    s->top = -1;
}

void Push(struct Stack *s, int e){
    if(s->top < s->size-1){
        s->A[++(s->top)] = e;
        
    } else {
        printf("Stack is full.\n");
    }
}

int Pop(struct Stack *s){
    if(s->top < 0){
        printf("Stack is empty.\n");
        return -1;
    }
    return s->A[(s->top)--];
}

int Peek(const struct Stack *s, int index){
    if(index <0 || index > s->top){
        printf("Index out of bound.\n");
        return -1;
    }
    return s->A[(s->top)-index];
}

int Top(const struct Stack *s){
    if(s->top >= 0){
        return s->A[s->top];
    }
    printf("Stack is empty.\n");
    return -1;
}

int isEmpty(const struct Stack *s){
    return s->top == -1;
}

int isFull(const struct Stack *s){
    return s->top == s->size-1;
}

void FreeStack(struct Stack *s){
    free(s->A);
    s->A = NULL;
    s->size = 0;
    s->top = -1;
}

#endif /* Stack_h */
