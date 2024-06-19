
#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node * prev;
    int value;
    struct Node * next;
};

struct DoublyLL{
    struct Node *head;
    size_t length;
};

void CreateDLL(struct DoublyLL *dl, int A[], size_t size){
    
    if(size <= 0){
        return;
    }
    
    dl->head = (struct Node *) malloc(sizeof(struct Node));
    dl->head->value = A[0];
    dl->head->prev = NULL;
    dl->head->next = NULL;
    dl->length = 1;
    
    struct Node * tail = dl->head;
    
    for(size_t i=1; i<size; i++){
        struct Node * newNode = malloc(sizeof(struct Node));
        newNode->value = A[i];
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = NULL;
        tail = tail->next;
        dl->length++;
    }
}

void Display(struct DoublyLL *dl){
    
    struct Node * temp = dl->head;
    if(temp == NULL){
        return;
    }
    
    while(temp){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void Insert(struct DoublyLL *dl, size_t index, int e){
    
    if(index < 0 || index > dl->length){
        return;
    }
    
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->value = e;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(dl->length == 0){
        dl->head = newNode;
        
    } else if(index == 0){
        dl->head->prev = newNode;
        newNode->next = dl->head;
        newNode->prev = NULL;
        dl->head = newNode;
        
    } else {
        struct Node * temp = dl->head;
        
        for(size_t i=0; i<index-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    dl->length++;
}

int Delete(struct DoublyLL *dl, size_t index){
    
    int value = -1;
    
    if(dl->head == NULL || index < 0 || index > dl->length-1){
        return value;
    }
    
    struct Node * temp = dl->head;
    
    if(index == 0){
        dl->head = dl->head->next;
        // it might be only 1 element
        if(temp->next != NULL){
            dl->head->prev = NULL;
        }

    } else{
        for(size_t i=0; i<index; i++){
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = temp->prev;
        }
    }
    value = temp->value;
    free(temp);
    dl->length--;
    
    return value;
}

void Reverse(struct DoublyLL *dl){
    
    
}


int main(int argc, const char * argv[]) {
    
    struct DoublyLL dl1 = {NULL, 0};
 
    int A[] = {1, 3, 8, 16, 23};
    CreateDLL(&dl1, A, 5);
    Display(&dl1);
    
    Insert(&dl1, 5, 88);
    Display(&dl1);
    
    printf("Delete an element: %d \n", Delete(&dl1, 5));
    Display(&dl1);
    
    return 0;
}
