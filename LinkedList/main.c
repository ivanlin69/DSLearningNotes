#include <stdio.h>
#include <stdlib.h>


struct Node{
    int value;
    struct Node *next;
};

struct LinkedList{
    size_t length;
    struct Node *head;
    struct Node *last;
};

void AddEnd(struct LinkedList * l, int e){
    
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->value = e;
    newNode->next = NULL;
    
    if(l->head == NULL){
        l->head = newNode;
        l->last = newNode;
    } else {
        l->last->next = newNode;
        l->last = newNode;
    }
    l->length++;
}

void AddFront(struct LinkedList * l, int e){
    
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->value = e;
    newNode->next = l->head;
    
    if(l->head == NULL){
        l->last = newNode;
    }
    l->head = newNode;
    l->length++;
}

void DisplayLL(struct LinkedList * l){
    struct Node * temp = l->head;
    
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void DisplayLLRecursive(struct Node * head){
    if(head != NULL){
        printf("%d ", head->value);
        DisplayLLRecursive(head->next);
        // printf("%d ", head->value);  prints backward
    }
}

int main(int argc, const char * argv[]) {
    
    struct LinkedList l = {0, NULL, NULL};
    
    DisplayLL(&l);
    
    AddEnd(&l, 34);
    AddEnd(&l, -3);
    AddEnd(&l, 386);
    AddEnd(&l, 67);
    
    AddFront(&l, 543);
    
    DisplayLL(&l);
    DisplayLLRecursive(l.head);
    printf("\n");
    
    return 0;
}
