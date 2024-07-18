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
    //AddEdge(&g, 5, 6); // make the graph disconnected
    AddEdge(&g, 5, 7);
    BFS(&g, 1);
    BFS(&g, 4);
    
    DFS(&g, 1);
    DFSv2(&g, 1);
    DFSr(&g, 1);
    DFSr2(&g, 1);
    
    FreeGraph(&g);
    return 0;
}
