#ifndef Queue_hpp
#define Queue_hpp
#include "LinkedList.hpp"

template<class T>
class Queue{
private:
    LinkedList<T> * A;
    int size;
    int rear;
    
public:
    Queue(int size);
    void Enqueue(T e);
    T Dequeue();
    int isEmpty();
    int isFull();
    T First();
    T Last();
    ~Queue();
};

#endif /* Queue_hpp */
