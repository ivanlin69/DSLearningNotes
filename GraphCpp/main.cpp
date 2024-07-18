#include <iostream>
#include "Graph.hpp"

int main(int argc, const char * argv[]) {
    
    class Graph g(7);
    g.AddEdge(1, 2);
    g.AddEdge(1, 3);
    g.AddEdge(1, 4);
    g.AddEdge(2, 3);
    g.AddEdge(3, 4);
    g.AddEdge(3, 5);
    g.AddEdge(4, 5);
    //AddEdge(5, 6); // make the graph disconnected
    g.AddEdge(5, 7);
    g.BFS(1);
    g.BFS(4);

    g.DFS(1);
    g.DFSr(1);
    //g.DFSr2(1);
    return 0;
}
