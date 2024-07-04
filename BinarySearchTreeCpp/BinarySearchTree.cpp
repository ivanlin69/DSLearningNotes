#include <stdio.h>
#include "BinarySearchTree.hpp"

template<class T>
BinarySearchTree<T>::BinarySearchTree(){
    root = NULL;
}

template<class T>
bool BinarySearchTree<T>::HelperSearchR(TreeNode<T> *t, T value){
    
}

template<class T>
bool BinarySearchTree<T>::HelperInsertR(TreeNode<T> *t, T value){
    
}

template<class T>
TreeNode<T> * BinarySearchTree<T>::HelperDelete(TreeNode<T> *t, T value){
    
}

template<class T>
bool BinarySearchTree<T>::Search(T value){
    
}

template<class T>
bool BinarySearchTree<T>::SearchR(T value){
    
}

template<class T>
bool BinarySearchTree<T>::Insert(T value){
    
}

template<class T>
bool BinarySearchTree<T>::InsertR(T value){
    
}

template<class T>
bool BinarySearchTree<T>::Delete(T value){
    
}




template<class T>
void BinarySearchTree<T>::DisplayPreOrder(){
    HelperDisplayPreOrder(root);
}

template<class T>
void BinarySearchTree<T>::HelperDisplayPreOrder(struct TreeNode<T> *t){
    if(t == NULL){
        return;
    }
    printf("%d ", t->value);
    HelperDisplayPreOrder(t->left);
    HelperDisplayPreOrder(t->right);
}

template<class T>
void BinarySearchTree<T>::DisplayInOrder(){
    HelperDisplayInOrder(root);
}

template<class T>
void BinarySearchTree<T>::HelperDisplayInOrder(struct TreeNode<T> *t){
    if(t == NULL){
        return;
    }
    HelperDisplayInOrder(t->left);
    printf("%d ", t->value);
    HelperDisplayInOrder(t->right);
}

template<class T>
void BinarySearchTree<T>::DisplayPostOrder(){
    HelperDisplayPostOrder(root);
}

template<class T>
void BinarySearchTree<T>::HelperDisplayPostOrder(TreeNode<T> *t){
    if(t == NULL){
        return;
    }
    HelperDisplayPostOrder(t->left);
    HelperDisplayPostOrder(t->right);
    printf("%d ", t->value);
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree(){
    FreeTree(root);
}

template<class T>
void BinarySearchTree<T>::DisplayPreOrderIter(){
    
    if(root == NULL){
        return;
    }
    
    Stack<TreeNode<T> *> s(20);
    TreeNode<T> * curr = root;
    
    while(curr != NULL || !s.isEmpty()){
        if(curr != NULL){
            printf("%d ", curr->value);
            s.Push(curr);
            curr = curr->left;
        } else {
            curr = s.Pop();
            curr = curr->right;
        }
    }
}

template<class T>
void BinarySearchTree<T>::DisplayInOrderIter(){
    
    if(root == NULL){
        return;
    }
    Stack<TreeNode<T> *> s(20);
    TreeNode<T> * curr = root;
    while(curr != NULL || !s.isEmpty()){
        if(curr != NULL){
            s.Push(curr);
            curr = curr->left;
        } else {
            curr = s.Pop();
            printf("%d ", curr->value);
            curr = curr->right;
        }
    }
}

template<class T>
void BinarySearchTree<T>::DisplayPostOrderIter(){
    
    if(root == NULL){
        return;
    }
    Stack<TreeNode<T> *> s1(20);
    Stack<TreeNode<T> *> s2(20);
    
    TreeNode<T> * curr = root;
    s1.Push(curr);
    
    while(!s1.isEmpty()){
        curr = s1.Pop();
        s2.Push(curr);
        if(curr->left){
            s1.Push(curr->left);
        }
        if(curr->right){
            s1.Push(curr->right);
        }
    }
    while(!s2.isEmpty()){
        printf("%d ", s2.Pop()->value);
    }
}

template<class T>
void BinarySearchTree<T>::DisplayLevelOrder(){
    
    if(root == NULL){
        return;
    }
    
    Queue<TreeNode<T> *> q(20);
    q.Enqueue(root);
    
    while(!q.isEmpty()){
        TreeNode<T> * curr = q.Dequeue();
        printf("%d ", curr->value);
        if(curr->left){
            q.Enqueue(curr->left);
        }
        if(curr->right){
            q.Enqueue(curr->right);
        }
    }
}

template<class T>
void BinarySearchTree<T>::FreeTree(TreeNode<T> *t){
    if(t == NULL){
        return;
    }
    FreeTree(t->left);
    FreeTree(t->right);
    delete t;
}

template<class T>
int BinarySearchTree<T>::Height(){
    return HelperHeight(root);
}

template<class T>
int BinarySearchTree<T>::CountNode(){
    return HelperCountNode(root);
}

template<class T>
int BinarySearchTree<T>::CountNodeDeg2(){
    return HelperCountNodeDeg2(root);
}

template<class T>
int BinarySearchTree<T>::CountLeaf(){
    return HelperCountLeaf(root);
}

template<class T>
int BinarySearchTree<T>::HelperHeight(TreeNode<T> *t){
    if(t == NULL){
        return 0;
    }
    int l = HelperHeight(t->left);
    int r = HelperHeight(t->right);
    if(l > r){
        return l + 1;
    }
    return r + 1;
}

template<class T>
int BinarySearchTree<T>::HelperCountNode(TreeNode<T> *t){
    if(t == NULL){
        return 0;
    }
    int l = HelperCountNode(t->left);
    int r = HelperCountNode(t->right);
    return l + r + 1;
}

template<class T>
int BinarySearchTree<T>::HelperCountNodeDeg2(TreeNode<T> *t){
    if(t == NULL){
        return 0;
    }
    int l = HelperCountNodeDeg2(t->left);
    int r = HelperCountNodeDeg2(t->right);
    if(t->left && t->right){
        return l + r + 1;
    }
    return l + r;
}

template<class T>
int BinarySearchTree<T>::HelperCountLeaf(TreeNode<T> *t){
    if(t == NULL){
        return 0;
    }
    int l = HelperCountLeaf(t->left);
    int r = HelperCountLeaf(t->right);
    if(!t->left && !t->right){
        return l + r + 1;
    }
    return l + r;
}
