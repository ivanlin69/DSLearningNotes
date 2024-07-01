#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int main(int argc, const char * argv[]) {
    
    struct BinaryTree * b = (struct BinaryTree *) malloc(sizeof(struct BinaryTree));
    CreateBinaryTree(b);
    
    printf("Tree traverse - PreOrder:\n");
    DisplayPreOrder(b->root);
    printf("\n");
    
    return 0;
}
