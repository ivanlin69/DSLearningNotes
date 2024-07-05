#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

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
class BinarySearchTree{
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
    
    bool HelperSearchR(TreeNode<T> *t, T value);
    TreeNode<T> *  HelperInsertR(TreeNode<T> *t, T value);
    TreeNode<T> * HelperDelete(TreeNode<T> *t, T value);
    
    
public:
    
    BinarySearchTree();
    
    bool Search(T value);
    bool SearchR(T value);
    bool Insert(T value);
    bool InsertR(T value);
    bool Delete(T value);
    bool DeleteR(T value);
    
    TreeNode<T> * FindPredecessor(TreeNode<T> * t);
    TreeNode<T> * FindSuccessor(TreeNode<T> * t);
    
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
    
    ~BinarySearchTree();
    
};



#endif /* BinarySearchTree_hpp */
