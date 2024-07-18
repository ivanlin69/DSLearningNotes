#include "Graph.hpp"
#include "LinkedList.hpp"
#include "LinkedList.cpp"
#include "Queue.hpp"
#include "Queue.cpp"
#include "Stack.hpp"
#include "Stack.cpp"


void Graph::DFSrHelper(){
}

Graph::Graph(int n){
    vertices = n;
    AdjacencyList = new LinkedList<int>[n+1];
}

bool Graph::AddEdge(int src, int des){
    if(src > vertices || des > vertices){
        std::cout << "Invalid vertices.\n";
        return false;
    }
    AdjacencyList[src].InsertSorted(des);
    // for undirected graph
    AdjacencyList[des].InsertSorted(src);
}

void Graph::BFS(){
}

void Graph::DFS(){
}

void Graph::DFSr(){
}
 
Graph::~Graph(){
}

