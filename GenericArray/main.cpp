#include <iostream>
#include "Array.hpp"
#include "Array.cpp"

int main(int argc, const char * argv[]) {
    /**
    Array<float> * a = new Array<float>({1.1f, 2.3f, 3.5f});
    a->Display();
    
    a->Insert(1, 5.12f);
    a->Display();
    float test = a->Delete(5.12f);
    a->Display();
    std::cout << test << std::endl;
    a->Set(1, 1.92);
    a->Display();
    
    Array<float> * b = new Array<float>({21.1f, 234.3f, 443.5f, 1567.1});
    b->Display();
    *b = *a;
    b->Display();
    std::cout << (*b)[0] << " " << (*b)[1] << std::endl;
    
    delete a;
    //delete b;
    
    Array<int> unsorted = {3, 2, 6, 4, 7, 11, 10};
    unsorted.MissingElementsUnsorted();
    
    std::cout << "Finding duplicate items: \n";
    Array<int> sorted = {2, 3, 3, 4, 6, 6, 6, 10, 10, 10};
    sorted.FindDuplicateSorted();
    
    std::cout << "Finding duplicate items in unsorted array: \n";
    Array<int> unsorted2 = {3, 2, 3, 4, 7, 11, 3, 10, 6, 10, 7};
    unsorted2.FindDuplicateUnsorted();
    // unsorted2.FindDuplicateUnsortedHashing();
     */
    
    Array<int> unsorted = {3, 2, 4, 7, 11, 32, 103, 6, 10, 78};
    unsorted.TwoSumUnsortedHashing(16);
    
    Array<int> sorted = {2, 3, 4, 7, 11, 33, 101, 116};
    sorted.TwoSumSorted(134);
    sorted.FindMaxMin();
    
    return 0;
}
