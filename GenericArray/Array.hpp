#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>
#include <initializer_list>

template<class T>
class Array {
private:
    T * A;
    size_t size;
    size_t length;

public:
    Array(size_t size);
    Array(const std::initializer_list<T> &lst);
    
    void Append(const T &element);
    void Insert(int index, const T &element);

    T Get(int index) const;
    void Set(int index, const T &element);

    T Delete(size_t index);
    T Delete(const T &element);
    size_t GetLength() const;

    void Display() const ;
    
    Array<T> & operator=(const Array<T> &other);
    T & operator[](size_t index);
    
    ~Array(){
        delete [] A;
    }
};

#endif /* Array_hpp */
