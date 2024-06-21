#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

struct Node{
    int value;
    struct Node *next;
    
    Node(){}
    Node(int value, struct Node * next) : value(value), next(next){}
    ~Node(){}
};

class LinkedList{
private:
    size_t length;
    Node *head;
    Node *tail;
    
public:
    Node * getHead(){ return head; }
    Node * getTail(){ return tail; }
    size_t getLength(){ return length; }
    
    LinkedList() : length(0), head(NULL), tail(NULL){}
    void AddEnd(int e);
    void AddFront(int e);
    void DeleteFront();
    void Delete(int e);
    void Insert(size_t index, int e);
    
    // only applied fot an sorted linkedlist
    void InsertSorted(int e);
    void DisplayLL();
    void DisplayLLRecursive(Node * head);
    int Sum();
    int SumRecursion(Node * head);
    int Max();
    int MaxRecursion(Node * head);
    Node * Search(int value);
    
    // improved with moving to head(order will be changed)
    Node * SearchMH(int value);
    int IsSorted();
    void DeleteDuplicates();
    void Reverse();
    void ReverseV2();
    void ReverseR(Node * n);
    
    // doesn't keep the duplicates
    // merging without copying elements, note thay any modification on the elements affects all lists
    static class LinkedList * Merge2SortedLL(class LinkedList * l1, class LinkedList * l2);
    int HaveLoop();
    ~LinkedList();
};


#endif /* LinkedList_hpp */
