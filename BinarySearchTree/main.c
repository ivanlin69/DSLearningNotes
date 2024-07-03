#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main(int argc, const char * argv[]) {
    
    struct BinarySearchTree * b = (struct BinarySearchTree *) malloc(sizeof(struct BinarySearchTree));

    InsertNode(b, 8);
    InsertNode(b, 3);
    InsertNode(b, 5);
    InsertNode(b, 4);
    InsertNode(b, 9);
    InsertNode(b, 8);
    
    printf("Search Tree - 1:%d \n", SearchTree(b, 1));
    printf("Search Tree - 5:%d \n", SearchTree(b, 5));
    printf("Search Tree Recursive - 1:%d \n", SearchTreeR(b->root, 1));
    printf("Search Tree Recursive - 5:%d \n", SearchTreeR(b->root, 5));
    
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
    
    FreeTree(b->root);
    return 0;
}
