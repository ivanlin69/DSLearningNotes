#ifndef Queue_hpp
#define Queue_hpp

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

#endif /* Queue_hpp */
