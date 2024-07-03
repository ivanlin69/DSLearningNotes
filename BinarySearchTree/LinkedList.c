#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void Initialize(struct LinkedList *l){
    l->length = 0;
    l->head = NULL;
    l->tail = NULL;
}

int AddEnd(struct LinkedList * l, struct TreeNode * e){
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

int AddFront(struct LinkedList * l, struct TreeNode * e){
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

void DeleteFront(struct LinkedList * l){
    if(l->head == NULL){
        return;
    } else if(l->head->next == NULL){
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
    } else{
        struct Node * temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
    l->length--;
}

void Delete(struct LinkedList * l, size_t index){
    
    if(l == NULL || l->head == NULL){
        return;
    }
    
    if(index == 0){
        DeleteFront(l);
        return;
    }
    
    struct Node * prev = l->head;
    for(size_t i=0; i<index-1; i++){
        if(prev->next == NULL){
            printf("Index out of bound.\n");
            return;
        }
        prev = prev->next;
    }
    
    struct Node * temp = prev->next;
    if(temp->next == NULL){
        prev->next = NULL;
    } else{
        prev->next = temp->next;
    }
    free(temp);
    l->length--;
}

int Insert(struct LinkedList * l, size_t index, struct TreeNode * e){
    
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

void freeLinkedlist(struct LinkedList *l){
    while(l->head){
        struct Node * temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
}
