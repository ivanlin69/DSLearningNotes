#ifndef ArrayCpp_hpp
#define ArrayCpp_hpp

#include <stdio.h>
#include <initializer_list>

// for testing purposes, the type of the array is declared as int instead of using templates
class ArrayCpp{
private:
    int *A;
    size_t size;
    size_t length;

public:
    ArrayCpp(size_t size) : size(size), length(0){
        A = new int[size];
    }
    
    ArrayCpp(std::initializer_list<int> lst) : size(lst.size()*2), length(lst.size()){
        A = new int[size];
        int i=0;
        std::initializer_list<int>::iterator it = lst.begin();
        while(it!=lst.end()){
            A[i++] = *it++;
        }
    }
    
    void Display();
    void Append(int element);
    void Insert(int index, int element);
    void Delete(int index);
    
    static void Swap(int *x, int *y);
    
    int LinearSearch(int target);
    int BinarySearch(int target);
    int BinarySearchRecursion(int target, int left, int right);
    int Get(int index);
    int GetSize();
    int GetLength();
    int * GetArray();
    void Set(int index, int value);
    void SetLength(int value);
    int Max();
    int Min();
    int Sum();
    int SumRecursive(int length);
    int SumRecursiveStatic(int length);
    float Avg();
    
    void Reverse();
    void ReverseForLoop();
    void Rotate();
    void InsertSorted(int element);
    int isSorted();
    void SeparateNegative();
    
    static ArrayCpp * Merge(ArrayCpp &arr1, ArrayCpp &arr2);
    static ArrayCpp * UnionUnsorted(ArrayCpp &arr1, ArrayCpp &arr2);
    static ArrayCpp * UnionSorted(ArrayCpp &arr1, ArrayCpp &arr2);
    static ArrayCpp * IntersectUnsorted(ArrayCpp &arr1, ArrayCpp &arr2);
    static ArrayCpp * IntersectSorted(ArrayCpp &arr1, ArrayCpp &arr2);
    static ArrayCpp * DifferenceUnsorted(ArrayCpp &arr1, ArrayCpp &arr2);
    static ArrayCpp * DifferenceSorted(ArrayCpp &arr1, ArrayCpp &arr2);
    
    ~ArrayCpp(){
        delete [] A;
    }
};

#endif /* ArrayCpp_hpp */
