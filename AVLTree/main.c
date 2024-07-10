#include <stdio.h>
#include "AVLTree.h"

int main(int argc, const char * argv[]) {
    
    struct AVLTree a = {NULL};

    InsertNode(&a, 8);
    InsertNode(&a, 7);
    InsertNode(&a, 6);
    InsertNode(&a, 10);
    InsertNode(&a, 16);
    /**
    InsertNodeR(&a, 8);
    InsertNodeR(&a, 7);
    InsertNodeR(&a, 6);
    InsertNodeR(&a, 10);
    InsertNodeR(&a, 16);
     */
    
    
    printf("Tree traverse - PreOrder:\n");
    DisplayPreOrder(a.root);
    printf("\n");
    
    printf("Tree traverse - InOrder:\n");
    DisplayInOrder(a.root);
    printf("\n");
    
    DeleteIter(&a, 8);
    DeleteR(&a, 7);
    
    printf("Tree traverse - PreOrder:\n");
    DisplayPreOrder(a.root);
    printf("\n");
    
    printf("Tree traverse - InOrder:\n");
    DisplayInOrder(a.root);
    printf("\n");
    
    FreeTree(a.root);
    
    return 0;
}
