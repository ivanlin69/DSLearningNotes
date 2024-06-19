
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

void Insert(struct CircularLL *cl, size_t index, int value){
    if(index < 0 || index > cl->length){
        return;
        
    } else if(index == 0 || index == cl->length){
        
        struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->value = value;
        if(cl->head == NULL){
            cl->head = newNode;
        }
        newNode->next = cl->head;
        
        struct Node * last = cl->head;
        while(last->next != cl->head){
            last = last->next;
        }
        last->next = newNode;
        
    }else{
        struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->value = value;
        
        struct Node * prev = cl->head;
        for(size_t i=0; i<index-1; i++){
            prev = prev->next;
        }
        
        newNode->next = prev->next;
        prev->next = newNode;
    }
}



int main(int argc, const char * argv[]) {
    
    struct CircularLL cl1;
    int A[] = {1, 3, 4, 16, 21};
    createCLL(&cl1, A, 5);
    Display(&cl1);
    
    struct CircularLL cl2 ={0, NULL};
    
    Insert(&cl1, 5, 88);
    Display(&cl1);
    Insert(&cl2, 0, 88);
    Display(&cl2);
    
    
    
    return 0;
}
