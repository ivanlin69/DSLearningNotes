#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include "Queue.hpp"
#include "Queue.cpp"

template<class T>
struct TreeNode{
    TreeNode<T> * left;
    TreeNode<T> * right;
    T value;
};

template<class T>
class BinaryTree{
private:
    TreeNode<T> * root;
    void HelperDisplayPreOrder(TreeNode<T> *t);
    void HelperDisplayInOrder(TreeNode<T> *t);
    void HelperDisplayPostOrder(TreeNode<T> *t);
    void FreeTree(TreeNode<T> *t);
    
public:
    
    
    BinaryTree(int size);
    
    void DisplayPreOrder();
    void DisplayInOrder();
    void DisplayPostOrder();
    
    ~BinaryTree();
    
};



#endif /* BinaryTree_hpp */
