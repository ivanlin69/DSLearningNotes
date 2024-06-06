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

template<class T>
void Array<T>::MissingElements(){
    size_t diff = A[0];
    for(size_t i=0; i<length; i++){
        size_t newDiff = A[i] - i;
        if(newDiff != diff){
            size_t count = newDiff - diff;
            for(size_t j=1; j<=count; j++){
                std::cout << A[i-1] + j << " ";
            }
            diff = newDiff;
        }
    }
}

// concept of hashing (trade off: space and time)
template<class T>
void Array<T>::MissingElementsUnsorted(){
    size_t max = A[0];
    for(size_t i=1; i<length; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    
    int hashing[max+1];
    for(size_t i=0; i<max+1; i++){
        hashing[i] = 0;
    }
    
    for(size_t i=0; i<length; i++){
        hashing[A[i]] = 1;
    }
    
    for(size_t i=1; i<max; i++){
        if(hashing[i] == 0){
            std::cout << i << " ";
        }
    }
}

template<class T>
void Array<T>::FindDuplicateSorted(){
    for(size_t i=0; i<length-1; i++){
        if(A[i] == A[i+1]){
            size_t j=i+1;
            while(A[j] == A[i]){
                j++;
            }
            std::cout << A[i] << ": There is(are) " << j-i-1 << " duplicate(s)\n";
            i = j-1; // Note that we need to return i to the normal end state
            // edge case: consecutive duplicates
        }
    }
}


template<class T>
void Array<T>::FindDuplicateUnsorted(){
    
    for(size_t i=0; i<length-1; i++){
        if(A[i] != -1){
            size_t count = 0;
            for(size_t j = i+1; j<length; j++){
                if(A[i] == A[j]){
                    count++;
                    A[j] = -1;
                }
            }
            if(count > 0){
                std::cout << A[i] << ": There is(are) " << count << " duplicate(s)\n";
            }
        }
    }
    
    
}

template<class T>
void Array<T>::FindDuplicateUnsortedHashing(){
    int max = A[0];
    for(size_t i=1; i<length; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    
    T hashing[max+1];
    for(size_t i=0; i<max+1; i++){
        hashing[i] = 0;
    }
    
    for(size_t i=0; i<length; i++){
        hashing[A[i]]++;
    }
    
    for(size_t i=0; i<max; i++){
        if(hashing[i] > 1){
            std::cout << i << ": There is(are) " << hashing[i]-1 << " duplicate(s)\n";
        }
    }
}

template<class T>
void Array<T>::TwoSumUnsorted(size_t sum){
    int found = 0;
    for(size_t i=0; i<length-1; i++){
        for(size_t j=i+1; j<length; j++){
            if(A[i] + A[j] == sum){
                found = 1;
                std::cout << A[i] << " and " << A[j] << std::endl;
            }
        }
    }
    if(found != 1){
        std::cout << "No such pair." << std::endl;
    }
}

template<class T>
void Array<T>::TwoSumUnsortedHashing(size_t sum){
    int max = A[0];
    for(size_t i=1; i<length; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    
    T hashing[max+1];
    for(size_t i=0; i<max+1; i++){
        hashing[i] = 0;
    }
    int found = 0;
    for(size_t i=0; i<length; i++){
        hashing[A[i]]++;
        if((sum-A[i]) >= 0 && hashing[(sum-A[i])] > 0){
            std::cout << A[i] << " and " << (sum-A[i]) << std::endl;
            found = 1;
        }
    }
    if(found != 1){
        std::cout << "No such pair." << std::endl;
    }
}

template<class T>
void Array<T>::TwoSumSorted(size_t sum){
    
    size_t i=0, j=length-1, found=0;
    
    while(j>i){
        if(A[i] + A[j] == sum){
            found = 1;
            std::cout << A[i++] << " and " << A[j--] << std::endl;
        } else if(A[i] + A[j] > sum){
            j--;
        } else{
            i++;
        }
    }
    if(found != 1){
        std::cout << "No such pair." << std::endl;
    }
    
}

template<class T>
void Array<T>::FindMaxMin(){
    int max=A[0], min=A[0];
    for(size_t i=1; i<length; i++){
        if(A[i] > max){
            max = A[i];
        } else if(A[i] < min){
            min = A[i];
        }
    }
    std::cout << "Max: " << max << " min: " << min << std::endl;
}

