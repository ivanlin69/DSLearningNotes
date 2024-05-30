
#include <stdio.h>
#include <stdlib.h>

struct Array{
    
    //int *A;
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr){
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Append(struct Array *arr, int element){
    if(arr->length < arr->size)
        arr->A[arr->length++] = element;
}

void Insert(struct Array *arr, int index, int element){
    if(arr->length < arr->size && index >= 0 && index < arr->size){
        for(int i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = element;
        arr->length++;
    }
}

void Delete(struct Array *arr, int index){
    if(index >= 0 && index < arr->length){
        for(int i=index; i<arr->length-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->A[--(arr->length)] = 0; // can choose not to do since Display is control by length
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 Elements in the given array should be unique, otherwise only the first target index is returned
 No modification is made, so passing by value is just fine, but if 'Transposition' / 'Move to front/head' is applied, then pass by address is needed
 */
int LinearSearch(struct Array *arr, int target){
   
    for(int i=0; i<=arr->length; i++){
        if(arr->A[i] == target){
            
            /** ways to improve the efficiency
             1. Transposition   // Target's priority slowly increases based on the # of times being searched
              swap(&arr->A[i],&arr->A[i-1]);
              return i-1;
             2. Move to front/head  // Maximized the target's priority once it's searched
              swap(&arr->A[i],&arr->A[0]);
              return 0;
             */
            swap(&arr->A[i], &arr->A[i-1]);
            return i-1;
        }
    }
    return -1;
}

/**
 Elements in the given array should be unique, otherwise only the first target index is returned
 No modification is made, so passing by value is just fine
 This only works with sorted array
 */
int BinarySearch(struct Array arr, int target){
    int left = 0;
    int right = arr.length - 1;
    int mid = 0;
        
    while(left <= right){
        mid = left + (right-left) / 2; // prevent overflow
        if(arr.A[mid] == target){
            return mid;
        } else if(arr.A[mid] > target){
            right = mid-1;
        } else{
            left = mid+1;
        }
    }
    return -1;
}

// compare to iterative version, it requires more stack depth and overhead but more elegant
int BinarySearchRecursion(struct Array arr, int target, int left, int right){

    if(left > right){
        return -1;
    }
    int mid = left + (right-left) / 2; // prevent overflow
    
    if(arr.A[mid] == target){
        return mid;
    } else if(arr.A[mid] > target){
        return BinarySearchRecursion(arr, target, left, mid-1);
    } else{
        return BinarySearchRecursion(arr, target, mid+1, right);
    }
}

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
    */
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
    return 0;
}
