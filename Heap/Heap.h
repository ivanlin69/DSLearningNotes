#ifndef Heap_h
#define Heap_h

#include <stdio.h>
#include <stdlib.h>

struct Heap{
    int size;
    int * A;
    int length;
};

int CreatePQ(struct Heap *p, int size){
    p->A = (int *) malloc(sizeof(int)*size);
    if(p->A == NULL){
        printf("Memory allocation failed.\n");
        return -1;
    }
    p->length = -1;
    p->size = size;
    return 0;
}

int insertPQ(struct Heap *p, int value){
    if(p == NULL){
        printf("Invalid PriorityQueue.\n");
        return -1;
    }
    
    if(p->length == p->size-1){
        printf("PQueue is full.\n");
        return -1;
    }
    p->A[++(p->length)] = value;
    
    size_t parent = (p->length-1)/2;
    size_t child = p->length;
    
    // Max heap
    while(child != 0 && p->A[child] > p->A[parent]){
        
        int temp = p->A[child];
        p->A[child] = p->A[parent];
        p->A[parent] = temp;
        
        child = parent;
        parent = (child-1)/2;
   
    }
    return 0;
}

int deletePQ(struct Heap *p){
    if(p == NULL){
        printf("Invalid Heap.\n");
        return -1;
    }
    
    if(p->length == -1){
        printf("Heap is empty.\n");
        return -1;
    }
    
    int removed = p->A[0];
    p->A[0] = p->A[(p->length)--];
    
    int parent = 0;
    int lchild = 1;
    int rchild = 2;
    
    while(lchild <= p->length){
        int temp = p->A[parent];
        int maxIndex = parent;
        
        if(p->A[parent] < p->A[lchild]){
            maxIndex = lchild;
        }
        
        if(p->A[lchild] < p->A[rchild] && p->A[parent] < p->A[rchild]){
            maxIndex = rchild;
        }
        
        if(parent != maxIndex){
            p->A[parent] = p->A[maxIndex];
            p->A[maxIndex] = temp;
            
            parent = maxIndex;
            lchild = 2*parent + 1;
            rchild = lchild + 1;
        } else {
            break;
        }
       
    }
    return removed;
}

int * HeapSort(struct Heap *p){
    int * result = (int *) malloc(sizeof(int)*(p->length));
    int flag = 0;
    size_t i=0;
    while(flag != -1){
        flag = deletePQ(p);
        if(flag != -1){
            result[i++] = flag;
        }
    }
    return result;
}

void DisplayPQ(struct Heap *p){
    if(p->length == -1){
        printf("Heap is empty.\n");
        return;
    }
    for(size_t i=0; i<=p->length; i++){
        printf("%d ", p->A[i]);
    }
    printf("\n");
}

void FreePQ(struct Heap *p){
    free(p->A);
    p->A = NULL;
    p->length = -1;
    p->size = 0;
}

#endif /* PriorityQueue_h */
