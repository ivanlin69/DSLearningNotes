#include "Array.hpp"
#include <iostream>

template<class T>
Array<T>::Array(size_t size) : size(size), length(0){
    A = new T [size];
}

template<class T>
Array<T>::Array(const std::initializer_list<T> &lst) : size(lst.size()*2), length(lst.size()){
    A = new T [size];
    typename std::initializer_list<T>::iterator it = lst.begin();
    size_t i = 0;
    while(it != lst.end()){
        A[i++] = *it++;
    }
}

template<class T>
void Array<T>::Append(const T &element){
    if(length < size){
        A[length] = element;
        length++;
    }
}

template<class T>
void Array<T>::Insert(int index, const T &element){
    if(length < size && index >=0 && index < length){
        size_t i=length;
        while(i > index){
            A[i] = A[i-1];
            i--;
        }
        A[index] = element;
        length++;
    }
}

template<class T>
T Array<T>::Get(int index) const{
    return A[index];
    
}

template<class T>
void Array<T>::Set(int index, const T &element){
    if(index >=0 && index < length){
        A[index] = element;
    }
}

template<class T>
T Array<T>::Delete(size_t index){
    if(index >= length){
        throw std::out_of_range("Index out of range");
    }
    T del = A[index];
    size_t i=index;
    while(i < length-1){
        A[i] = A[i+1];
        i++;
    }
    length--;
    return del;
}

template<class T>
T Array<T>::Delete(const T &element){
    for(size_t i=0; i<length; i++){
        if(A[i] == element){
            return Delete(i);
        }
    }
    throw std::invalid_argument("No such element.");
}

template<class T>
size_t Array<T>::GetLength() const{
    return length;
}

template<class T>
void Array<T>::Display() const{
    int i=0;
    while(i<length){
        std::cout << A[i++] << " ";
    }
    std::cout << std::endl;
}

template<class T>
Array<T> & Array<T>::operator=(const Array<T> & other){
    if(this == &other){
        return *this;
    }
    
    delete [] A;
    length = other.length;
    size = other.size;
    
    A = new T [size];
    for(size_t i=0; i<length; i++){
        A[i] = other[i];
    }
    return *this;
}

template<class T>
// read-only
const T & Array<T>::operator[](size_t index) const {
    if(index >= length){
        throw std::out_of_range("index out of range.");
    }
    return A[index];
}
