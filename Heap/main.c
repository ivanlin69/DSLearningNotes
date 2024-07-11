#include <stdio.h>
#include "Heap.h"

int main(int argc, const char * argv[]) {
    struct Heap p;
    CreatePQ(&p, 30);
    
    insertPQ(&p, 8);
    insertPQ(&p, 6);
    insertPQ(&p, 4);
    
    
    DisplayPQ(&p);
    
    insertPQ(&p, 9);
    DisplayPQ(&p);
    insertPQ(&p, 8);
    insertPQ(&p, 13);
    
    DisplayPQ(&p);
    
    int length = p.length;
    int * sorted = HeapSort(&p);
    
    printf("Heap sort result: ");
    for(size_t i=0; i<=length; i++){
        printf("%d ", sorted[i]);
    }
    printf("\n");
    
    printf("After delete %d:\n", deletePQ(&p));
    DisplayPQ(&p);

    FreePQ(&p);
    
    return 0;
}
