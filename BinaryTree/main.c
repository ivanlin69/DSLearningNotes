#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int main(int argc, const char * argv[]) {
    
    struct BinaryTree * b = (struct BinaryTree *) malloc(sizeof(struct BinaryTree));
    CreateBinaryTree(b);
    
    printf("Tree traverse - PreOrder:\n");
    DisplayPreOrder(b->root);
    printf("\n");
    
    printf("Tree traverse - InOrder:\n");
    DisplayInOrder(b->root);
    printf("\n");
    
    printf("Tree traverse - PostOrder:\n");
    DisplayPostOrder(b->root);
    printf("\n");
    
    printf("Tree traverse - IterPreOrder:\n");
    DisplayPreOrderIter(b->root);
    printf("\n");
    
    printf("Tree traverse - IterInOrder:\n");
    DisplayInOrderIter(b->root);
    printf("\n");
    
    printf("Tree traverse - IterPostOrder:\n");
    DisplayPostOrderIter(b->root);
    printf("\n");
    
    printf("Tree traverse - LevelOrder:\n");
    DisplayLevelOrder(b->root);
    printf("\n");
    
    printf("Total number of nodes: %d \n", CountOfNodes(b->root));
    printf("Total number of nodes with deg 2: %d \n", CountOfNodesDeg2(b->root));
    printf("Height of the Tree: %d \n", Height(b->root));
    
    return 0;
}
