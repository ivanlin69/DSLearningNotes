#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main(int argc, const char * argv[]) {
    
    struct BinarySearchTree * b = (struct BinarySearchTree *) malloc(sizeof(struct BinarySearchTree));
    
    InsertNodeR(&b->root, 8);
    InsertNodeR(&b->root, 3);
    InsertNodeR(&b->root, 5);
    InsertNodeR(&b->root, 4);
    InsertNodeR(&b->root, 9);
    InsertNodeR(&b->root, 8);
    
    /**
    struct TreeNode * rootNode = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    rootNode->value = 8;
    rootNode->left = NULL;
    rootNode->right = NULL;
    b->root = rootNode;

    InsertNodeR2(b->root, 3);
    InsertNodeR2(b->root, 5);
    InsertNodeR2(b->root, 4);
    InsertNodeR2(b->root, 9);
    InsertNodeR2(b->root, 8);
     */
    
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
    
    printf("Delete '8':\n");
    DeleteNode(b, 8);

    
    printf("Tree traverse - PreOrder:\n");
    DisplayPreOrder(b->root);
    printf("\n");
    
    printf("Tree traverse - InOrder:\n");
    DisplayInOrder(b->root);
    printf("\n");
    
    printf("Tree traverse - PostOrder:\n");
    DisplayPostOrder(b->root);
    printf("\n");
    
    FreeTree(b->root);
    return 0;
}
