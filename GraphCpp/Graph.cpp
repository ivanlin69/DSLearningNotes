#include "Graph.hpp"
#include "Queue.hpp"
#include "Queue.cpp"
#include "Stack.hpp"
#include "Stack.cpp"


void Graph::DFSrHelper(int curr, bool* visited){
    std::cout << curr << " ";
    visited[curr] = true;
    
    Node<int> *temp = AdjacencyList[curr].getHead();
    while(temp){
        if(!visited[temp->value]){
            DFSrHelper(temp->value, visited);
        }
        temp = temp->next;
    }
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
    return true;
}

void Graph::BFS(int root){
    
    if(root > vertices){
        std::cout << "Invalid vertex.\n";
        return;
    }
    
    bool *visited = new bool[vertices+1];
    for(size_t i=0; i<=vertices; i++){
        visited[i] = false;
    }
    
    Queue<int> q(30);
    std::cout << root << " ";
    visited[root] = true;
    q.Enqueue(root);
    
    while(!q.isEmpty()){
        int curr = q.Dequeue();
        Node<int> * temp = AdjacencyList[curr].getHead();
        while(temp){
            if(!visited[temp->value]){
                std::cout << temp->value << " ";
                q.Enqueue(temp->value);
                visited[temp->value] = true;
            }
            temp = temp->next;
        }
    }
    std::cout << std::endl;
    delete [] visited;
}

void Graph::DFS(int root){
    
    if(root > vertices){
        std::cout << "Invalid vertex.\n";
        return;
    }
    
    bool *visited = new bool[vertices+1];
    for(size_t i=0; i<=vertices; i++){
        visited[i] = false;
    }
    
    Stack<int> s(30);
    s.Push(root);
    
    while(!s.isEmpty()){
        int curr = s.Pop();
        if(!visited[curr]){
            std::cout << curr << " ";
            visited[curr] = true;
            s.Push(curr);
        }
        
        Node<int> * temp = AdjacencyList[curr].getHead();
        while(temp){
            curr = temp->value;
            if(!visited[curr]){
                s.Push(curr);
            }
            temp = temp->next;
        }
    }
    std::cout << std::endl;
    delete [] visited;
}

void Graph::DFSr(int root){
    if(root > vertices){
        std::cout << "Invalid vertex.\n";
        return;
    }
    
    bool *visited = new bool[vertices+1];
    for(size_t i=0; i<=vertices; i++){
        visited[i] = false;
    }
    
    for(int i=1; i<=vertices; i++){
        if(visited[i] == false){
            DFSrHelper(i, visited);
        }
    }
    std::cout << std::endl;
    delete [] visited;
}
 
Graph::~Graph(){
}

