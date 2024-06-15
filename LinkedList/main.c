#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

void AddNode(struct Node * head, int e){
    
    struct Node * temp = head;
    
    while(head->next != NULL){
        head = head->next;
    }
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    head->next = newNode;
    newNode->value = e;
    newNode->next = NULL;
    head = temp;
}

void DisplayLL(struct Node * head){
    struct Node * temp = head;
    
    while(head != NULL){
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
    head = temp;
}

int main(int argc, const char * argv[]) {
    
    struct Node * LL = (struct Node *) malloc(sizeof(struct Node));
    LL->value = 1;
    LL->next = NULL;
    
    DisplayLL(LL);
    
    AddNode(LL, 34);
    AddNode(LL, -3);
    AddNode(LL, 386);
    AddNode(LL, 67);
    
    DisplayLL(LL);
    
    return 0;
}
