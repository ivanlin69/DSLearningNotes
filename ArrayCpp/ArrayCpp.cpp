#include "ArrayCpp.hpp"
#include <stdio.h>

void ArrayCpp::Display(){
    for(size_t i=0; i<length; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void ArrayCpp::Append(int element){
    if(length < size)
        A[length++] = element;
}

void ArrayCpp::Insert(int index, int element){
    if(length < size && index >= 0 && index < size){
        for(size_t i=length; i>index; i--){
            A[i] = A[i-1];
        }
        A[index] = element;
        length++;
    }
}

void ArrayCpp::Delete(int index){
    if(index >= 0 && index < length){
        for(int i=index; i<length-1; i++){
            A[i] = A[i+1];
        }
        A[--length] = 0; // can choose not to do since Display is control by length
    }
}

void ArrayCpp::Swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 Elements in the given array should be unique, otherwise only the first target index is returned
 No modification is made, so passing by value is just fine, but if 'Transposition' / 'Move to front/head' is applied, then pass by address is needed
 */
int ArrayCpp::LinearSearch(int target){
    
    for(int i=0; i<=length; i++){
        if(A[i] == target){
            
            /** ways to improve the efficiency
             1. Transposition   // Target's priority slowly increases based on the # of times being searched
             swap(&A[i],&A[i-1]);
             return i-1;
             2. Move to front/head  // Maximized the target's priority once it's searched
             swap(&A[i],&A[0]);
             return 0;
             */
            return i;
        }
    }
    return -1;
}

/**
 Elements in the given array should be unique, otherwise only the first target index is returned
 No modification is made, so passing by value is just fine
 This only works with sorted array
 */
int ArrayCpp::BinarySearch(int target){
    int left = 0;
    int right = (int) length - 1;
    int mid = 0;
    
    while(left <= right){
        mid = left + (right-left) / 2; // prevent overflow
        if(A[mid] == target){
            return mid;
        } else if(A[mid] > target){
            right = mid-1;
        } else{
            left = mid+1;
        }
    }
    return -1;
}

// compare to iterative version, it requires more stack depth and overhead but more elegant
int ArrayCpp::BinarySearchRecursion(int target, int left, int right){
    
    if(left > right){
        return -1;
    }
    int mid = left + (right-left) / 2; // prevent overflow
    
    if(A[mid] == target){
        return mid;
    } else if(A[mid] > target){
        return BinarySearchRecursion(target, left, mid-1);
    } else{
        return BinarySearchRecursion(target, mid+1, right);
    }
}

int ArrayCpp::Get(int index){
    if(index >= 0 && index < length){
        return A[index];
    }
    return -1; // for testing purposes, return -1 indicating invalid operation
}

int ArrayCpp::GetSize(){
    return (int) size;
}

int ArrayCpp::GetLength(){
    return (int) length;
}

int * ArrayCpp::GetArray(){
    return A;
}


void ArrayCpp::Set(int index, int value){
    if(index >= 0 && index < length)
        A[index] = value;
}

void ArrayCpp::SetLength(int value){
    length = value;
}

int ArrayCpp::Max(){
    int max = A[0];
    for(int i=1; i<length; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int ArrayCpp::Min(){
    int min = A[0];;
    for(int i=1; i<length; i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int ArrayCpp::Sum(){
    int result = 0;
    for(int i=0; i<length; i++){
        result += A[i];
    }
    return result;
}


int ArrayCpp::SumRecursive(int length){
    int result = 0;
    if(length == 0){
        return 0;
    }
    result += SumRecursive(length-1) + A[length-1];
    return result;
}

// using static variable, only works for 1 call unless reset function is used
int ArrayCpp::SumRecursiveStatic(int length){
    static int result = 0;
    if(length == 0){
        return result;
    }
    result += A[length-1];
    
    return SumRecursiveStatic(length-1);
}

float ArrayCpp::Avg(){
    return (float) Sum() / length;
}

void ArrayCpp::Reverse(){
    
    if(length <= 1){
        return;
    }
    
    int i = 0;
    while(i != (length)/2){
        int temp = A[i];
        A[i] = A[length-1-i];
        A[length-1-i] = temp;
        i++;
    }
}

void ArrayCpp::ReverseForLoop(){
    
    if(length <= 1){
        return;
    }
    int i, j;
    for(i=0, j=(int) length-1; i<=j; i++, j--){
        Swap(&A[i], &A[j]);
    }
}

void ArrayCpp::Rotate(){
    
    int temp = A[0];
    
    for(int i=0; i<length; i++){
        A[i] = A[i+1];
    }
    A[length-1] = temp;
}


// this function is only used for a sorted array
// after insertion the order is kept sored
void ArrayCpp::InsertSorted(int element){
    
    if(length >= size){
        return;
    }
    
    int i = (int) length-1;
    
    while(A[i] >= element && i>=0){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = element;
    length++;
}

int ArrayCpp::isSorted(){
    
    for(int i=0; i<length-2; i++){
        if(A[i] > A[i+1]){
            return 0;
        }
    }
    return 1;
}

void ArrayCpp::SeparateNegative(){
    
    int i=0, j=(int) length-1;
    
    while(i<(int) length-1 && j>=0 && i<j){
        if(A[i] > 0 && A[j] < 0){
            Swap(&A[i], &A[j]);
            i++;
            j--;
        } else if(A[i] < 0){
            i++;
        } else if(A[j] > 0){
            j--;
        }
    }
}

/**
 Binary Operation for 2 arrays
 */

// keep sorted
ArrayCpp * ArrayCpp::Merge(ArrayCpp &arr1, ArrayCpp &arr2){
    
    ArrayCpp *a = new ArrayCpp(arr1.GetSize()+arr2.GetSize());
    
    int i=0, j=0, k=0;
    
    while(i < arr1.GetLength() && j < arr2.GetLength()){
        if(arr1.GetArray()[i] < arr2.GetArray()[j]){
            a->GetArray()[k++] = arr1.GetArray()[i++];
        } else{
            a->GetArray()[k++] = arr2.GetArray()[j++];
        }
    }
    
    for(;i < arr1.GetLength(); i++){
        a->GetArray()[k++] = arr1.GetArray()[i];
    }
    for(;j < arr2.GetLength(); j++){
        a->GetArray()[k++] = arr2.GetArray()[j];
    }
    a->SetLength(arr1.GetLength()+arr2.GetLength());;
    return a;
}

// only applied for sets
ArrayCpp * ArrayCpp::UnionUnsorted(ArrayCpp &arr1, ArrayCpp &arr2){
    
    ArrayCpp *a = new ArrayCpp(arr1.GetSize()+arr2.GetSize());
    int i=0, j=0, k=0;
    
    for(i=0; i<arr1.GetLength(); i++){
        a->GetArray()[i] = arr1.GetArray()[i];
    }
    a->SetLength(arr1.GetLength());
    
    for(j=0; j<arr2.GetLength(); j++){
        int flag = 0;
        for(k=0; k<arr1.GetLength(); k++){
            if(arr2.GetArray()[j] == arr1.GetArray()[k]){
                flag = 1;
                break;
            }
        }
        if(flag!=1){
            a->GetArray()[i++] = arr2.GetArray()[j];
            a->SetLength(a->GetLength()+1);
        }
    }
    return a;
}

// only applied for sets
ArrayCpp * ArrayCpp::UnionSorted(ArrayCpp &arr1, ArrayCpp &arr2){
    
    ArrayCpp *a = new ArrayCpp(arr1.GetSize()+arr2.GetSize());
    int i=0, j=0, k=0;
    
    while(i<arr1.GetLength() && j<arr2.GetLength()){
        if(arr1.GetArray()[i] < arr2.GetArray()[j]){
            a->GetArray()[k++] = arr1.GetArray()[i++];
        } else if(arr1.GetArray()[i] > arr2.GetArray()[j]){
            a->GetArray()[k++] = arr2.GetArray()[j++];
        } else{
            a->GetArray()[k++] = arr1.GetArray()[i++];
            j++;
        }
        a->SetLength(a->GetLength()+1);
    }
    
    for(; i<arr1.GetLength(); i++){
        a->GetArray()[k++] = arr1.GetArray()[i];
        a->SetLength(a->GetLength()+1);
    }
    for(; j<arr2.GetLength(); j++){
        a->GetArray()[k++] = arr2.GetArray()[j];
        a->SetLength(a->GetLength()+1);
    }
    
    return a;
}

// only applied for sets
ArrayCpp * ArrayCpp::IntersectUnsorted(ArrayCpp &arr1, ArrayCpp &arr2){
    
    ArrayCpp *a = new ArrayCpp(arr1.GetSize()+arr2.GetSize());
    int i=0, j=0, k=0;
    
    for(; i<arr1.GetLength(); i++){
        for(j=0; j<arr2.GetLength(); j++){
            if(arr1.GetArray()[i] == arr2.GetArray()[j]){
                a->GetArray()[k++] = arr1.GetArray()[i];
                a->SetLength(a->GetLength()+1);
            }
        }
    }
    return a;
}

ArrayCpp * ArrayCpp::IntersectSorted(ArrayCpp &arr1, ArrayCpp &arr2){
    
    ArrayCpp *a = new ArrayCpp(arr1.GetSize()+arr2.GetSize());
    int i=0, j=0, k=0;
    
    while(i<arr1.GetLength() && j<arr2.GetLength()){
        if(arr1.GetArray()[i] == arr2.GetArray()[j]){
            a->GetArray()[k++] = arr1.GetArray()[i++];
            j++;
            a->SetLength(a->GetLength()+1);
        } else if(arr1.GetArray()[i] < arr2.GetArray()[j]){
            i++;
        } else{
            j++;
        }
    }
    return a;
}

// A-B
ArrayCpp * ArrayCpp::DifferenceUnsorted(ArrayCpp &arr1, ArrayCpp &arr2){
    
    ArrayCpp *a = new ArrayCpp(arr1.GetSize()+arr2.GetSize());
    int i=0, j=0, k=0;
    
    for(; i<arr1.GetLength(); i++){
        int flag = 0;
        for(j=0; j<arr2.GetLength(); j++){
            if(arr1.GetArray()[i] == arr2.GetArray()[j]){
                flag = 1;
                break;
            }
        }
        if(flag!=1){
            a->GetArray()[k++] = arr1.GetArray()[i];
            a->SetLength(a->GetLength()+1);
        }
    }
    return a;
}

ArrayCpp * ArrayCpp::DifferenceSorted(ArrayCpp &arr1, ArrayCpp &arr2){
    
    ArrayCpp *a = new ArrayCpp(arr1.GetSize()+arr2.GetSize());
    int i=0, j=0, k=0;
    
    while(i<arr1.GetLength() && j<arr2.GetLength()){
        if(arr1.GetArray()[i] < arr2.GetArray()[j]){
            a->GetArray()[k++] = arr1.GetArray()[i++];
            a->SetLength(a->GetLength()+1);
        } else if(arr1.GetArray()[i] > arr2.GetArray()[j]){
            j++;
        } else{
            i++;
            j++;
        }
    }
    return a;
}
