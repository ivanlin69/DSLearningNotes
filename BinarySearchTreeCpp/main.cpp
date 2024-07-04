#include <iostream>
#include <stdio.h>
#include "BinarySearchTree.hpp"

int main(int argc, const char * argv[]) {
    
    BinarySearchTree<int> b;
    
    b.Insert(8);
    b.Insert(3);
    b.Insert(5);
    b.Insert(4);
    b.Insert(9);
    b.Insert(8);
    
    /**
     b.InsertR(8);
     b.InsertR(3);
     b.InsertR(5);
     b.InsertR(4);
     b.InsertR(9);
     b.InsertR(8);
     */
    
    printf("Search Tree - 1:%d \n", b.Search(1));
    printf("Search Tree - 5:%d \n", b.Search(5));
    printf("Search Tree Recursive - 1:%d \n", b.SearchR(1));
    printf("Search Tree Recursive - 5:%d \n", b.SearchR(5));
    
    printf("Tree traverse - PreOrder:\n");
    b.DisplayPreOrder();
    printf("\n");
    
    printf("Tree traverse - InOrder:\n");
    b.DisplayInOrder();
    printf("\n");
    
    printf("Tree traverse - PostOrder:\n");
    b.DisplayPostOrder();
    printf("\n");
    
    printf("Tree traverse - LevelOrder:\n");
    b.DisplayLevelOrder();
    printf("\n");
    
    printf("Delete '8':\n");
    b.Delete(8);

    printf("Tree traverse - PreOrder:\n");
    b.DisplayPreOrder();
    printf("\n");
    
    printf("Tree traverse - InOrder:\n");
    b.DisplayInOrder();
    printf("\n");
    
    printf("Tree traverse - PostOrder:\n");
    b.DisplayPostOrder();
    printf("\n");
    
    printf("Tree traverse - LevelOrder:\n");
    b.DisplayLevelOrder();
    printf("\n");
    
    return 0;
}
