#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void Initialize(struct LinkedList *l){
    l->length = 0;
    l->head = NULL;
    l->tail = NULL;
}

int AddEnd(struct LinkedList * l, int e){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("malloc failed.\n");
        return -1;
    }
    newNode->value = e;
    newNode->next = NULL;
    
    if(l->head == NULL){
        l->head = newNode;
        l->tail = newNode;
    } else {
        l->tail->next = newNode;
        l->tail = newNode;
    }
    l->length++;
    return 0;
}

int AddFront(struct LinkedList * l, int e){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("malloc failed.\n");
        return -1;
    }
    newNode->value = e;
    newNode->next = l->head;
    
    if(l->head == NULL){
        l->tail = newNode;
    }
    l->head = newNode;
    l->length++;
    return 0;
}

int DeleteFront(struct LinkedList * l){
    int del = -1;
    if(l->head == NULL){
        return del;
    } else if(l->head->next == NULL){
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
    } else{
        struct Node * temp = l->head;
        l->head = l->head->next;
        del = temp->value;
        free(temp);
    }
    l->length--;
    return del;
}

int Delete(struct LinkedList * l, size_t index){
    
    int del = -1;
    if(l == NULL || l->head == NULL){
        return del;
    }
    
    if(index == 0){
        return DeleteFront(l);
    }
    
    struct Node * prev = l->head;
    for(size_t i=0; i<index-1; i++){
        if(prev->next == NULL){
            printf("Index out of bound.\n");
            return del;
        }
        prev = prev->next;
    }
    
    struct Node * temp = prev->next;
    if(temp->next == NULL){
        prev->next = NULL;
    } else{
        prev->next = temp->next;
    }
    del = temp->value;
    free(temp);
    l->length--;
    return del;
}

int Insert(struct LinkedList * l, size_t index, int e){
    
    if(index < 0 || index > l->length){
        printf("Index out of bound.\n");
        return -1;
    } else if(index == 0){
        return AddFront(l, e);
    } else if(index == l->length){
        return AddEnd(l, e);
    } else {
        struct Node * t = l->head;
        while(index > 1){
            t = t->next;
            index--;
        }
        
        struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
        if(newNode == NULL){
            printf("malloc failed.\n");
            return -1;
        }
        newNode->value = e;
        newNode->next = t->next;
        t->next = newNode;
    }
    l->length++;
    return 0;
}

// only applied fot an sorted linkedlist
int InsertSorted(struct LinkedList * l, int e){

    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("malloc failed.\n");
        return -1;
    }
    newNode->value = e;
    newNode->next = NULL;
    
    if(l->head == NULL){
        l->head = newNode;
        l->tail = newNode;
    } else{
        struct Node * temp = l->head;
        if(temp->value > e){
            newNode->next = l->head;
            l->head = newNode;
        } else{
            while(temp->next != NULL && temp->next->value < e){
                temp = temp->next;
            }
            newNode->next = temp->next;
            if(temp->next == NULL){
                l->tail = newNode;
            }
            temp->next = newNode;
        }
    }
    l->length++;
    return 0;
}

void DisplayLL(struct LinkedList * l){
    struct Node * temp = l->head;
    
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int Sum(struct LinkedList * l){
    struct Node * temp = l->head;
    int sum=0;
    
    while(temp){
        sum += temp->value;
        temp = temp->next;
    }
    return sum;
}

int Max(struct LinkedList * l){
    struct Node * temp = l->head;
    int max=temp->value;
    
    while(temp){
        if(max < temp->value){
            max = temp->value;
        }
        temp = temp->next;
    }
    return max;
}


struct Node * Search(struct LinkedList *l, int value){
    struct Node * temp = l->head;
    while(temp) {
        if(temp->value == value){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


int IsSorted(struct LinkedList * l){
    if(l->head == NULL || l->head->next == NULL){
        return 1;
    }
    struct Node * curr = l->head;
    
    while(curr->next){
        if(curr->value > curr->next->value){
            return 0;
        }
        curr = curr->next;
    }
    return 1;
}

void Reverse(struct LinkedList * l){
    
    if(l->head == NULL || l->head->next == NULL){
        return;
    }
    struct Node * curr = l->head;
    struct Node * next;
    l->tail = curr;
    
    while(curr->next){
        next = curr->next;
        curr->next = next->next;
        next->next = l->head;
        l->head = next;
    }
}


int HaveLoop(struct LinkedList * l){
    
    struct Node * p = l->head;
    struct Node * q = l->head;
    
    if(p == NULL || p->next == NULL){
        return 0;
    }
    
    while(p && q){
        p = p->next;
        q = q->next;
        
        if(q) {
            // q moves faster
            q = q->next;
        }
        
        if(p == q){
            return 1;
        }
    }
    return 0;
}

void freeLinkedlist(struct LinkedList *l){
    while(l->head){
        struct Node * temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
}
