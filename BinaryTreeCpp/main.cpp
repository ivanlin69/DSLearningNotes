#include <iostream>
#include "BinaryTree.hpp"
#include "BinaryTree.cpp"

int main(int argc, const char * argv[]) {
    
    BinaryTree<int> b(20);
    
    printf("Tree traverse - PreOrder:\n");
    b.DisplayPreOrder();
    printf("\n");
    
    printf("Tree traverse - InOrder:\n");
    b.DisplayInOrder();
    printf("\n");
    
    printf("Tree traverse - PostOrder:\n");
    b.DisplayPostOrder();
    printf("\n");
    
    printf("Tree traverse - IterPreOrder:\n");
    b.DisplayPreOrderIter();
    printf("\n");
    
    printf("Tree traverse - IterInOrder:\n");
    b.DisplayInOrderIter();
    printf("\n");
    
    printf("Tree traverse - IterPostOrder:\n");
    b.DisplayPostOrderIter();
    printf("\n");
    
    printf("Tree traverse - LevelOrder:\n");
    b.DisplayLevelOrder();
    printf("\n");


    return 0;
}
