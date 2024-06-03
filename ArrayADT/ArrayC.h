#ifndef ArrayC_h
#define ArrayC_h

struct Array{
    //int *A;
    int A[20];  //For testing purposes, using a fixed-sized stack array
    int size;
    int length;
};

void Display(struct Array arr);
void Append(struct Array *arr, int element);
void Insert(struct Array *arr, int index, int element);
void Delete(struct Array *arr, int index);
void Swap(int *x, int *y);
int LinearSearch(struct Array *arr, int target);
int BinarySearch(struct Array arr, int target);
int BinarySearchRecursion(struct Array arr, int target, int left, int right);
int Get(struct Array arr, int index);
void Set(struct Array *arr, int index, int value);
int Max(struct Array arr);
int Min(struct Array arr);
int Sum(struct Array arr);
int SumRecursive(struct Array arr, int length);
int SumRecursiveStatic(struct Array arr, int length);
float Avg(struct Array arr);
void Reverse(struct Array *arr);
void ReverseForLoop(struct Array *arr);
void Rotate(struct Array *arr);
void InsertSorted(struct Array *arr, int element);
int isSorted(struct Array arr);
void SeparateNegative(struct Array *arr);
struct Array * Merge(struct Array arr1, struct Array arr2);
struct Array * UnionUnsorted(struct Array arr1, struct Array arr2);
struct Array * UnionSorted(struct Array arr1, struct Array arr2);
struct Array * IntersectUnsorted(struct Array arr1, struct Array arr2);
struct Array * IntersectSorted(struct Array arr1, struct Array arr2);
struct Array * DifferenceUnsorted(struct Array arr1, struct Array arr2);
struct Array * DifferenceSorted(struct Array arr1, struct Array arr2);

#endif /* ArrayC_h */
