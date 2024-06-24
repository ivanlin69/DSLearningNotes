#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <stdlib.h>

template<class T>
class Node{
public:
    T value;
    Node *next;
    
    Node(){}
    Node(T value, Node * next) : value(value), next(next){}
    ~Node(){}
};

template<class T>
class LinkedList{
private:
    size_t length;
    Node<T> *head;
    Node<T> *tail;
    
public:
    Node<T> * getHead(){ return head; }
    Node<T> * getTail(){ return tail; }
    size_t getLength(){ return length; }
    
    LinkedList() : length(0), head(NULL), tail(NULL){}
    void AddEnd(T e);
    void AddFront(T e);
    void DeleteFront();
    void Delete(T e);
    void Insert(size_t index, T e);

    void DisplayLL();
    void Reverse();
    int HaveLoop();
    ~LinkedList();
};


#endif /* LinkedList_hpp */
