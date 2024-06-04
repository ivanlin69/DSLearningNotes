#include <iostream>
#include "ArrayCpp.hpp"

int main(int argc, const char * argv[]) {
    
    /**
    ArrayCpp * a1 = new ArrayCpp({1,2,3,6,7,9});
    std::cout << "Array1 is: ";
    a1->Display();
    
    std::cout << "Testing BinarySearch(): ";
    std::cout << a1->BinarySearchRecursion(7, 0, a1->GetLength()) << "\n";
    std::cout << "Testing Set(): ";
    a1->Set(1, 56);
    a1->Display();
    
    std::cout << "Testing Max(): " << a1->Max() << std::endl;
    std::cout << "Testing Sum(): " << a1->Sum() << std::endl;
    std::cout << "Testing SumRecursive(): " << a1->SumRecursive(a1->GetLength()) << std::endl;
    
    a1->Reverse();
    a1->Display();
    */
    
    // Binary Operations
    std::cout << "Testing Binary Operations: \n";

    ArrayCpp * a1 = new ArrayCpp({1,2,5,6,17,29});
    ArrayCpp * a2 = new ArrayCpp({3,17,22,67,79,91});
    
    ArrayCpp * a3 = new ArrayCpp({2,1,6,29,17,5});
    ArrayCpp * a4 = new ArrayCpp({67,23,17,91,79,3});
    
    std::cout << "2 Sorted arrays: \nArray1: ";
    a1->Display();
    std::cout << "Array2: ";
    a2->Display();
    std::cout << "2 Unsorted arrays: \nArray3: ";
    a3->Display();
    std::cout << "Array4: ";
    a4->Display();
    
    /**
    ArrayCpp * a5 = ArrayCpp::Merge(*a1, *a2);
    std::cout << "Merged: ";
    a5->Display();
    
    ArrayCpp * a5 = ArrayCpp::UnionSorted(*a1, *a2);
    std::cout << "UnionSorted: ";
    a5->Display();
 
    ArrayCpp * a6 = ArrayCpp::UnionSorted(*a3, *a4);
    std::cout << "UnionUnsorted: ";
    a5->Display();

    ArrayCpp * a5 = ArrayCpp::IntersectSorted(*a1, *a2);
    std::cout << "IntersectSorted: ";
    a5->Display();
    
    ArrayCpp * a6 = ArrayCpp::IntersectUnsorted(*a3, *a4);
    std::cout << "IntersectUnsorted: ";
    a5->Display();
     */
    
    ArrayCpp * a5 = ArrayCpp::DifferenceSorted(*a1, *a2);
    std::cout << "DifferenceSorted: ";
    a5->Display();
    
    ArrayCpp * a6 = ArrayCpp::DifferenceUnsorted(*a3, *a4);
    std::cout << "DifferenceUnsorted: ";
    a5->Display();
    
    delete a1;
    delete a2;
    delete a3;
    delete a4;
    delete a5;
    delete a6;
    
    return 0;
}
