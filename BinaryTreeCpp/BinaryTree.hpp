#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include "Queue.hpp"
#include "Queue.cpp"
#include "Stack.hpp"
#include "Stack.cpp"

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
    
    int HelperHeight(TreeNode<T> *t);
    int HelperCountNode(TreeNode<T> *t);
    int HelperCountNodeDeg2(TreeNode<T> *t);
    int HelperCountLeaf(TreeNode<T> *t);
    
public:
    
    
    BinaryTree(int size);
    
    void DisplayPreOrder();
    void DisplayInOrder();
    void DisplayPostOrder();
    
    void DisplayPreOrderIter();
    void DisplayInOrderIter();
    void DisplayPostOrderIter();
    
    void DisplayLevelOrder();
    
    int Height();
    int CountNode();
    int CountNodeDeg2();
    int CountLeaf();
    
    ~BinaryTree();
    
};



#endif /* BinaryTree_hpp */
