#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include "LinkedList.hpp"
#include "LinkedList.cpp"

class Graph{
private:
    LinkedList<int> * AdjacencyList;
    int vertices;
    void DFSrHelper(int root, bool* visited);
public:
    Graph(int n);
    bool AddEdge(int src, int des);
    void BFS(int root);
    void DFS(int root);
    void DFSr(int root);
    ~Graph();
};

#endif /* Graph_hpp */
