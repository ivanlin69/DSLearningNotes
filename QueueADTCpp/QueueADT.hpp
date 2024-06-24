#ifndef QueueADT_hpp
#define QueueADT_hpp

class Queue{
private:
    int * A;
    int first;
    int size;
    int rear;
    
public:
    Queue(int size);
    void Enqueue(int e);
    int Dequeue();
    int isEmpty();
    int isFull();
    int First();
    int Last();
    ~Queue();
};

#endif /* QueueADT_hpp */
