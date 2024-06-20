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

int Peek(struct Stack *s, int index){
    if(index <0 || index > s->top){
        printf("Index out of bound.\n");
        return -1;
    }
    return s->A[(s->top)-index];
}

int Top(struct Stack *s){
    if(s->top >= 0){
        return s->A[s->top];
    }
    printf("Stack is empty.\n");
    return -1;
}

int isEmpty(struct Stack *s){
    return s->top == -1;
}

int isFull(struct Stack *s){
    return s->top == s->size-1;
}

void FreeStack(struct Stack *s){
    free(s->A);
    s->A = NULL;
    s->size = 0;
    s->top = -1;
}


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
