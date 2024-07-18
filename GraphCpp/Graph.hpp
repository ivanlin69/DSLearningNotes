#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>

#include "LinkedList.hpp"
#include "LinkedList.cpp"

class Graph{
private:
    LinkedList<int> * AdjacencyList;
    int vertices;
    void DFSrHelper();
public:
    Graph(int n);
    bool AddEdge(int src, int des);
    void BFS();
    void DFS();
    void DFSr();
    ~Graph();
};

#endif /* Graph_hpp */
