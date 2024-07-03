#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

struct Stack{
    struct LinkedList *l;
    int size;
    int top;
};

void InitializeStack(struct Stack *s, int size){
    s->l = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    Initialize(s->l);
    s->size = size;
    s->top = -1;
}

void Push(struct Stack *s, struct TreeNode *e){
    if(s->top < s->size-1){
        AddFront(s->l, e);
        s->top++;
        
    } else {
        printf("Stack is full.\n");
    }
}

struct TreeNode * Pop(struct Stack *s){
    if(s->top < 0){
        printf("Stack is empty.\n");
        return NULL;
    }
    struct TreeNode * value = s->l->head->value;
    DeleteFront(s->l);
    s->top--;
    return value;
}

struct TreeNode * Peek(const struct Stack *s, int index){
    if(index <0 || index > s->top){
        printf("Index out of bound.\n");
        return NULL;
    }
    struct Node * temp = s->l->head;
    for(size_t i=0; i<index; i++){
        temp = temp->next;
    }
    return temp->value;
}

struct TreeNode * Top(const struct Stack *s){
    if(s->top >= 0){
        return s->l->head->value;
    }
    printf("Stack is empty.\n");
    return NULL;
}

int isEmpty(const struct Stack *s){
    return s->top == -1;
}

int isFull(const struct Stack *s){
    return s->top == s->size-1;
}

void FreeStack(struct Stack *s){
    freeLinkedlist(s->l);
    free(s->l);
    s->l = NULL;
    s->size = 0;
    s->top = -1;
}

#endif /* Stack_h */
