#include <stdio.h>
#include "Graph.h"

int main(int argc, const char * argv[]) {
    
    struct Graph g;
    CreateGraph(&g, 7);
    AddEdge(&g, 1, 2);
    AddEdge(&g, 1, 3);
    AddEdge(&g, 1, 4);
    AddEdge(&g, 2, 3);
    AddEdge(&g, 3, 4);
    AddEdge(&g, 3, 5);
    AddEdge(&g, 4, 5);
    AddEdge(&g, 5, 6);
    AddEdge(&g, 5, 7);
    BFS(&g, 1);
    
    FreeGraph(&g);
    return 0;
}
