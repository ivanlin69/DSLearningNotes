#include <stdio.h>
#include "ArrayC.h"

int main(int argc, const char * argv[]) {
    /**
    int A[] = {1, 2, 4, 8, 10};
    printf("Show the second element of the array: %d \n", A[1]);
    printf("Show the second element of the array: %d \n", 1[A]);
    printf("Show the second element of the array: %d \n", *(A+1));
    printf("Show the memory address of the array: %p \n", A);
    printf("Show the memory address of the 2nd element in an array: %p \n", &A[1]);
     */
    
    /**
     // using scanf and asks user to initialize the array
    struct Array arr;
    printf("Please enter the size of the array:\n");
    scanf("%d", &arr.size);  //scanf requires the address of the variable where it should store the input value
    
    arr.A = (int *) malloc(arr.size * sizeof(int));
    arr.length = 0;
       
    int n=0;
    printf("Please enter the total number of the elements you're going to put in the array:\n");
    scanf("%d", &n);
    
    printf("Please enter the elements one by one:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr.A[i]);
        arr.length++;
    }
    
    struct Array arr = {{2,3,5,7,11}, 10, 5};
        
    // size is dynamic and everything is initialized
    Append(&arr, 32);
    Insert(&arr, 2, 51);
    Delete(&arr, 1);
    Display(arr);
    printf("LinearSearch: %d\n", LinearSearch(&arr, 51));
    
    struct Array arr2 = {{2,3,5,7,11,51}, 10, 6};
    Display(arr2);
    printf("BinarySearch: %d\n", BinarySearch(arr2, 51));
    printf("BinarySearchRecursion: %d\n", BinarySearchRecursion(arr2, 51, 0, arr2.length-1));
    
    
    struct Array arr3 = {{2,3,5,7,11,51}, 10, 6};
    Display(arr3);
    printf("Get: %d\n", Get(arr3, 3));
    Set(&arr3, 4, 101);
    Display(arr3);
    printf("Max: %d\n", Max(arr3));
    printf("Min: %d\n", Min(arr3));
    printf("Sum: %d\n", Sum(arr3));
    printf("SumRecursive: %d\n", SumRecursive(arr3, arr3.length));
    printf("SumRecursiveStatic: %d\n", SumRecursiveStatic(arr3, arr3.length));
    printf("Avg: %.4f\n", Avg(arr3));
    
    struct Array arr4 = {{37, 3, 2,3,5,7,11,51}, 10, 8};
    Display(arr4);
    Reverse(&arr4);
    Display(arr4);
    ReverseForLoop(&arr4);
    Display(arr4);
    Rotate(&arr4);
    Display(arr4);
    Rotate(&arr4);
    Display(arr4);
    
    struct Array arr5 = {{2,3,5,7,11,37,51,12}, 10, 8};
    Display(arr5);
    InsertSorted(&arr5, 19);
    Display(arr5);
    printf("isSorted: %d\n", isSorted(arr5));
    
     
    struct Array arr6 = {{2,-3,-5,7,-11,37,-51,12}, 10, 8};
    Display(arr6);
    SeparateNegative(&arr6);
    Display(arr6);
    
    struct Array arr7 = {{2,3,5,7,11,37,51}, 10, 7};
    struct Array arr8 = {{1,23,53,77}, 10, 4};
    struct Array * merged = Merge(arr7, arr8);
    Display(arr7);
    Display(arr8);
    Display(*merged);
    */
    printf("\nTests for 2 unsorted arrays: \n");
    struct Array arr9 = {{3,2,1,53,51,7,37}, 10, 7};
    struct Array arr10 = {{77,1,53,23}, 10, 4};
    struct Array * unioned = UnionUnsorted(arr9, arr10);
    struct Array * intersected = IntersectUnsorted(arr9, arr10);
    struct Array * difference = DifferenceUnsorted(arr9, arr10);
    Display(arr9);
    Display(arr10);
    printf("Union: ");
    Display(*unioned);
    printf("Intersect: ");
    Display(*intersected);
    printf("Difference: ");
    Display(*difference);
     
    printf("\nTests for 2 sorted arrays: \n");
    struct Array arr11 = {{1,2,3,7,37,51,53}, 10, 7};
    struct Array arr12 = {{1,23,53,77}, 10, 4};
    struct Array * unionedSorted = UnionSorted(arr11, arr12);
    struct Array * intersectSorted = IntersectSorted(arr11, arr12);
    struct Array * differenceSorted = DifferenceSorted(arr11, arr12);
    Display(arr11);
    Display(arr12);
    printf("Union: ");
    Display(*unionedSorted);
    printf("Intersect: ");
    Display(*intersectSorted);
    printf("Difference: ");
    Display(*differenceSorted);
    
    return 0;
}
