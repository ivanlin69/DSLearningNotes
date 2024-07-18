#ifndef Graph_h
#define Graph_h

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "QueueLL.h"

struct AdjacencyList{
    // an array of (pointers to) linkedlists
    struct LinkedList **A;
};

struct Graph{
    struct AdjacencyList * list;
    size_t vertices;
};

void CreateGraph(struct Graph* g, size_t vertices){
    g->vertices = vertices;
    g->list = (struct AdjacencyList *) malloc(sizeof(struct AdjacencyList));
    // Added extra 1 space for index 0
    g->list->A = (struct LinkedList **) malloc(sizeof(struct LinkedList *)*(vertices+1));
    for(size_t i=0; i<g->vertices+1; i++){
        g->list->A[i] = (struct LinkedList *) malloc(sizeof(struct LinkedList));
        Initialize(g->list->A[i]);
    }
}

int AddEdge(struct Graph *g, int src, int des){
    if(src > g->vertices || des > g->vertices){
        printf("Vertex out of range.\n");
        return -1;
    }
    InsertSorted(g->list->A[src], des);
    //for undirected graph
    InsertSorted(g->list->A[des], src);
    return 0;
}

void BFS(struct Graph *g, int root){
    if(g == NULL || root > g->vertices){
        printf("Invalid graph or given vertex.\n");
        return;
    }
    // arary for storing the visited vertices
    int explored[g->vertices+1];
    for(size_t i=0; i<=g->vertices; i++){
        explored[i] = 0;
    }
    // queue for traversing the vertices in FIFO fashion
    struct Queue q;
    CreateQueue(&q);
    EnQueue(&q, root);
    printf("%d ", root);
    explored[root] = 1;
    
    while(!IsEmpty(&q)){
        int curr = DeQueue(&q);
        struct Node * temp = g->list->A[curr]->head;
        while(temp != NULL){
            // if the node isn't visited
            if(explored[temp->value] == 0){
                printf("%d ", temp->value);
                EnQueue(&q, temp->value);
                // mark it as visited
                explored[temp->value] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    FreeQueue(&q);
}

void DFS(struct Graph *g, int root){
    if(g == NULL || root > g->vertices){
        printf("Invalid graph or given vertex.\n");
        return;
    }

    int explored[g->vertices+1];
    for(size_t i=0; i<=g->vertices; i++){
        explored[i] = 0;
    }
    
    struct Stack s;
    InitializeStack(&s, 30);
    Push(&s, root);
    printf("%d ", root);
    explored[root] = 1;
    struct Node * temp = NULL;
    
    while(!isEmpty(&s)){
        int curr = Pop(&s);
        temp = g->list->A[curr]->head;
        
        while(temp){
            while(temp && explored[temp->value] != 0){
                temp = temp->next;
            }
            if(temp){
                printf("%d ", temp->value);
                Push(&s, temp->value);
                explored[temp->value] = 1;
                
                temp = g->list->A[temp->value]->head;
            }
        }
    }
    printf("\n");
    FreeStack(&s);
}

void DFSv2(struct Graph *g, int root){
    if(g == NULL || root > g->vertices){
        printf("Invalid graph or given vertex.\n");
        return;
    }

    int explored[g->vertices+1];
    for(size_t i=0; i<=g->vertices; i++){
        explored[i] = 0;
    }
    
    struct Stack s;
    InitializeStack(&s, 30);
    Push(&s, root);
    struct Node * temp = NULL;
    
    while(!isEmpty(&s)){
        int curr = Pop(&s);
        if(explored[curr] == 0){
            printf("%d ", curr);
            explored[curr] = 1;
        }
        
        temp = g->list->A[curr]->head;
        
        while(temp){
            if(explored[temp->value] == 0){
                Push(&s, temp->value);
            }
            temp = temp->next;
        }
    }
    printf("\n");
    FreeStack(&s);
}


void HelperDFSr(struct Graph *g, int curr, int *explored){

    printf("%d ", curr);
    explored[curr] = 1;
    
    struct Node * temp = g->list->A[curr]->head;
    while(temp){
        if(explored[temp->value] == 0){
            HelperDFSr(g, temp->value, explored);
        }
        temp = temp->next;
    }
}

void DFSr(struct Graph *g, int root){
    int explored[g->vertices+1];
    for(size_t i=0; i<=g->vertices; i++){
        explored[i] = 0;
    }
    HelperDFSr(g, root, explored);
    
    printf("\n");
}

// Visits all the nodes even the graph is disconnected
void DFSr2(struct Graph *g, int root){
    int explored[g->vertices+1];
    for(size_t i=0; i<=g->vertices; i++){
        explored[i] = 0;
    }
    for(int i=1; i<=g->vertices; i++){
        if(explored[i] == 0){
            HelperDFSr(g, i, explored);
        }
    }
    printf("\n");
}


void FreeGraph(struct Graph *g){
    for(size_t i=0; i<=g->vertices; i++){
        freeLinkedlist(g->list->A[i]);
        free(g->list->A[i]);
    }
    free(g->list->A);
    free(g->list);
    g->vertices = 0;
}

#endif /* Graph_h */
