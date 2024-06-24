#ifndef QueueADT_hpp
#define QueueADT_hpp

template<class T>
class Queue{
private:
    T * A;
    int first;
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

#endif /* QueueADT_hpp */
