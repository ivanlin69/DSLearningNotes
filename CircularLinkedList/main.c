
#include <stdio.h>
#include <stdlib.h>


struct Node{
    int value;
    struct Node *next;
};

struct CircularLL{
    size_t length;
    struct Node *head;
};

void createCLL(struct CircularLL * cl, int A[], size_t size){
    
    cl->length=0;
    cl->head = (struct Node *) malloc(sizeof(struct Node));
    
    cl->head->value = A[0];
    cl->head->next = cl->head;
    cl->length++;
    
    struct Node * tail = cl->head;
    
    for(size_t i=1; i<size; i++){
        struct Node * temp = (struct Node *) malloc(sizeof(struct Node));
        temp->value = A[i];
        temp->next = cl->head;

        tail->next  = temp;
        tail = tail->next;
        cl->length++;
    }
}

void Display(struct CircularLL * cl){
    struct Node * temp = cl->head;
    
    do{
        printf("%d ", temp->value);
        temp = temp->next;
    } while(temp != cl->head);
    
    printf("\n");
}



int main(int argc, const char * argv[]) {
    
    struct CircularLL cl1;
    int A[] = {1, 3, 4, 16, 21};
    createCLL(&cl1, A, 5);
    
    Display(&cl1);
    
    
    return 0;
}
