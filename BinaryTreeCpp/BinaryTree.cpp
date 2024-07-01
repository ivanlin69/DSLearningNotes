#include <stdio.h>
#include "BinaryTree.hpp"

template<class T>
BinaryTree<T>::BinaryTree(int size){

    root = new TreeNode<T>();
    Queue<TreeNode<T> *> q(size);
    
    int x;
    std::cout << "Enter root value:\n";
    std::cin >> x;
    
    root->value = x;
    root->right = NULL;
    root->left = NULL;
    q.Enqueue(root);
    
    while(!q.isEmpty()){
        TreeNode<T> * curr = q.Dequeue();
        
        printf("Enter %d's left child's value(-1 if NULL):\n", curr->value);
        std::cin >> x;
        if(x != -1){
            curr->left = new TreeNode<T>();
            curr->left->value = x;
            curr->left->left = NULL;
            curr->left->right = NULL;
            q.Enqueue(curr->left);
        }
        
        printf("Enter %d's the right child's value(-1 if NULL):\n", curr->value);
        std::cin >> x;
        if(x != -1){
            curr->right = new TreeNode<T>();
            curr->right->value = x;
            curr->right->left = NULL;
            curr->right->right = NULL;
            q.Enqueue(curr->right);
        }
    }
}

template<class T>
void BinaryTree<T>::DisplayPreOrder(){
    HelperDisplayPreOrder(root);
}

template<class T>
void BinaryTree<T>::HelperDisplayPreOrder(struct TreeNode<T> *t){
    if(t == NULL){
        return;
    }
    printf("%d ", t->value);
    HelperDisplayPreOrder(t->left);
    HelperDisplayPreOrder(t->right);
}

template<class T>
void BinaryTree<T>::DisplayInOrder(){
    HelperDisplayInOrder(root);
}

template<class T>
void BinaryTree<T>::HelperDisplayInOrder(struct TreeNode<T> *t){
    if(t == NULL){
        return;
    }
    HelperDisplayInOrder(t->left);
    printf("%d ", t->value);
    HelperDisplayInOrder(t->right);
}

template<class T>
void BinaryTree<T>::DisplayPostOrder(){
    HelperDisplayPostOrder(root);
}

template<class T>
void BinaryTree<T>::HelperDisplayPostOrder(TreeNode<T> *t){
    if(t == NULL){
        return;
    }
    HelperDisplayPostOrder(t->left);
    HelperDisplayPostOrder(t->right);
    printf("%d ", t->value);
}

template<class T>
BinaryTree<T>::~BinaryTree(){
    FreeTree(root);
}

template<class T>
void BinaryTree<T>::FreeTree(TreeNode<T> *t){
    if(t == NULL){
        return;
    }
    FreeTree(t->left);
    FreeTree(t->right);
    delete t;
}
