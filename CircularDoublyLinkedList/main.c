#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node * prev;
    int value;
    struct Node * next;
};

struct CircularDLL{
    struct Node *head;
    size_t length;
};

void CreateCDLL(struct CircularDLL *dl, int A[], size_t size){
    
    if(size <= 0){
        return;
    }
    
    dl->head = (struct Node *) malloc(sizeof(struct Node));
    dl->head->value = A[0];
    dl->head->prev = dl->head;
    dl->head->next = dl->head;
    dl->length = 1;
    
    struct Node * tail = dl->head;
    
    for(size_t i=1; i<size; i++){
        struct Node * newNode = malloc(sizeof(struct Node));
        newNode->value = A[i];
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = dl->head;
        tail = tail->next;
        dl->head->prev = tail;
        dl->length++;
    }
}

void Display(struct CircularDLL *dl){
    
    struct Node * temp = dl->head;
    if(temp == NULL){
        return;
    }
    
    while(temp->next != dl->head){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("%d \n", temp->value);
}

void Insert(struct CircularDLL *dl, size_t index, int e){
    
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
        dl->head->prev->next = newNode;
        newNode->prev = dl->head->prev;
        newNode->next = dl->head;
        dl->head->prev = newNode;
        
    } else {
        struct Node * temp = dl->head;
        
        for(size_t i=0; i<index-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
    dl->length++;
}

int Delete(struct CircularDLL *dl, size_t index){
    
    int value = -1;
    
    if(dl->head == NULL || index < 0 || index > dl->length-1){
        return value;
    }
    
    struct Node * temp = dl->head;
    
    if(index == 0){
        dl->head = dl->head->next;
        // it might be only 1 element

    } else{
        for(size_t i=0; i<index; i++){
            temp = temp->next;
        }
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    
    value = temp->value;
    free(temp);
    dl->length--;
    
    return value;
}

void Reverse(struct CircularDLL *dl){
    
    if(dl->head == NULL || dl->length == 0 || dl->length == 1){
        return;
    }
    
    struct Node * temp = NULL;
    struct Node * curr = dl->head;
    
    while(temp != dl->head){
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;

        curr = temp;
    }
    dl->head = temp->prev;
}


int main(int argc, const char * argv[]) {
    
    struct CircularDLL c1 = {NULL, 0};
 
    int A[] = {1, 3, 8, 16, 23};
    CreateCDLL(&c1, A, 5);
    Display(&c1);

    Insert(&c1, 5, 88);
    Display(&c1);

    printf("Delete an element: %d \n", Delete(&c1, 0));
    Display(&c1);

    struct CircularDLL c2 = {NULL, 0};
 
    int B[] = {3, 8};
    CreateCDLL(&c2, B, 2);
    Display(&c2);
    
    Reverse(&c1);
    Display(&c1);
    
    return 0;
}
