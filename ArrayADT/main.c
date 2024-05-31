
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void Swap(int *x, int *y){
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
            Swap(&arr->A[i], &arr->A[i-1]);
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

int Get(struct Array arr, int index){
    if(index >= 0 && index < arr.length){
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int value){
    if(index >= 0 && index < arr->length)
        arr->A[index] = value;
}

int Max(struct Array arr){
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];;
    for(int i=1; i<arr.length; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr){
    int result = 0;
    for(int i=0; i<arr.length; i++){
        result += arr.A[i];
    }
    return result;
}


int SumRecursive(struct Array arr, int length){
    int result = 0;
    if(length == 0){
        return 0;
    }
    result += SumRecursive(arr, length-1) + arr.A[length-1];
    return result;
}

// using static variable, only works for 1 call unless reset function is used
int SumRecursiveStatic(struct Array arr, int length){
    static int result = 0;
    if(length == 0){
        return result;
    }
    result += arr.A[length-1];
    
    return SumRecursiveStatic(arr, length-1);
}

float Avg(struct Array arr){
    return (float) Sum(arr) / arr.length;
}

void Reverse(struct Array *arr){
    
    if(arr->length <= 1 || arr == NULL){
        return;
    }
    
    int i = 0;
    while(i != (arr->length)/2){
        int temp = arr->A[i];
        arr->A[i] = arr->A[arr->length-1-i];
        arr->A[arr->length-1-i] = temp;
        i++;
    }
}

void ReverseForLoop(struct Array *arr){
    
    if(arr->length <= 1 || arr == NULL){
        return;
    }
    int i, j;
    for(i=0, j=arr->length-1; i<=j; i++, j--){
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void Rotate(struct Array *arr){
        
    int temp = arr->A[0];
    
    for(int i=0; i<arr->length; i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = temp;
}


/**
 Binary Operation for 2 arrays
 */

// this function is only used for a sorted array
// after insertion the order is kept sored
void InsertSorted(struct Array *arr, int element){
    
    if(arr->length >= arr->size){
        return;
    }
    
    int i=arr->length-1;
    
    while(arr->A[i] >= element && i>=0){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = element;
    arr->length++;
}

int isSorted(struct Array arr){
        
    for(int i=0; i<arr.length-2; i++){
        if(arr.A[i] > arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}

void SeparateNegative(struct Array *arr){
    
    int i=0, j=arr->length-1;
    
    while(i<arr->length-1 && j>=0 && i<j){
        if(arr->A[i] > 0 && arr->A[j] < 0){
            Swap(&arr->A[i], &arr->A[j]);
            i++;
            j--;
        } else if(arr->A[i] < 0){
            i++;
        } else if(arr->A[j] > 0){
            j--;
        }
    }
}

// keep sorted
struct Array * Merge(struct Array arr1, struct Array arr2){
    
    struct Array * c = (struct Array *) malloc(sizeof(struct Array));
    c->length = 0;
    c->size = arr1.size + arr2.size;
    int i=0, j=0, k=0;
    
    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            c->A[k++] = arr1.A[i++];
        } else{
            c->A[k++] = arr2.A[j++];
        }
    }
    
    for(;i < arr1.length; i++){
        c->A[k++] = arr1.A[i];
    }
    for(;j < arr2.length; j++){
        c->A[k++] = arr2.A[j];
    }
    c->length = arr1.length + arr2.length;
    return c;
}

// only applied for sets
struct Array * UnionUnsorted(struct Array arr1, struct Array arr2){
    
    struct Array * result = (struct Array *) malloc(sizeof(struct Array));
    int i, j, k;
    if(arr1.length > arr2.length){
        for(i=0; i<arr1.length; i++){
            result->A[i] = arr1.A[i];
        }
        result->length = arr1.length;
    } else{
        for(i=0; i<arr2.length; i++){
            result->A[i] = arr2.A[i];
        }
        result->length = arr2.length;
    }
    
    for(j=0; j<arr2.length; j++){
        int flag = 0;
        for(k=0; k<arr1.length; k++){
            if(arr2.A[j] == arr1.A[k]){
                flag = 1;
                break;
            }
        }
        if(flag!=1){
            result->A[i++] = arr2.A[j];
            result->length++;
        }
    }
    result->size = arr1.size + arr2.size;
    return result;
}

// only applied for sets
struct Array * UnionSorted(struct Array arr1, struct Array arr2){
    
    struct Array * c = (struct Array *)malloc(sizeof(struct Array));
    c->length = 0;
    int i=0, j=0, k=0;
    
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            c->A[k++] = arr1.A[i++];
        } else if(arr1.A[i] > arr2.A[j]){
            c->A[k++] = arr2.A[j++];
        } else{
            c->A[k++] = arr1.A[i++];
            j++;
        }
        c->length++;
    }
    
    for(; i<arr1.length; i++){
        c->A[k++] = arr1.A[i];
        c->length++;
    }
    for(; j<arr2.length; j++){
        c->A[k++] = arr2.A[j];
        c->length++;
    }
    c->size = arr1.size + arr2.size;
    return c;
}
    
// only applied for sets
struct Array * IntersectUnsorted(struct Array arr1, struct Array arr2){
    
    struct Array * result = (struct Array *) malloc(sizeof(struct Array));
    result->length = 0;
    int i=0, j=0, k=0;
       
    for(; i<arr1.length; i++){
        for(j=0; j<arr2.length; j++){
            if(arr1.A[i] == arr2.A[j]){
                result->A[k++] = arr1.A[i];
                result->length++;
            }
        }
    }
    result->size = arr1.size + arr2.size;
    return result;
}

struct Array * IntersectSorted(struct Array arr1, struct Array arr2){
    
    struct Array * result = (struct Array *) malloc(sizeof(struct Array));
    result->length = 0;
    int i=0, j=0, k=0;
    
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i] == arr2.A[j]){
            result->A[k++] = arr1.A[i++];
            j++;
            result->length++;
        } else if(arr1.A[i] < arr2.A[j]){
            i++;
        } else{
            j++;
        }
    }
    result->size = arr1.size + arr2.size;
    return result;
}

// A-B
struct Array * DifferenceUnsorted(struct Array arr1, struct Array arr2){
    
    struct Array * result = (struct Array *) malloc(sizeof(struct Array));
    result->length = 0;
    int i=0, j=0, k=0;
       
    for(; i<arr1.length; i++){
        int flag = 0;
        for(j=0; j<arr2.length; j++){
            if(arr1.A[i] == arr2.A[j]){
                flag = 1;
                break;
            }
        }
        if(flag!=1){
            result->A[k++] = arr1.A[i];
            result->length++;
        }
    }
    result->size = arr1.size + arr2.size;
    return result;
}

struct Array * DifferenceSorted(struct Array arr1, struct Array arr2){
    
    struct Array * result = (struct Array *) malloc(sizeof(struct Array));
    result->length = 0;
    int i=0, j=0, k=0;
    
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            result->A[k++] = arr1.A[i++];
            result->length++;
        } else if(arr1.A[i] > arr2.A[j]){
            j++;
        } else{
            i++;
            j++;
        }
    }
    
    result->size = arr1.size + arr2.size;
    return result;
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
