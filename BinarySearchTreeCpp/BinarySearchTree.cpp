#include <stdio.h>
#include <iostream>
#include "BinarySearchTree.hpp"

template<class T>
BinarySearchTree<T>::BinarySearchTree(){
    root = NULL;
}

template<class T>
bool BinarySearchTree<T>::HelperSearchR(TreeNode<T> *t, T value){
    if(t == NULL){
        return false;
    }
    
    if(t->value == value){
        return true;
    } else if(t->value > value){
        return HelperSearchR(t->left, value);
    } else{
        return HelperSearchR(t->right, value);
    }
}

template<class T>
TreeNode<T> * BinarySearchTree<T>::HelperInsertR(TreeNode<T> *t, T value){
    if(t == NULL){
        TreeNode<T>  *newNode =  new TreeNode<T>();
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if(t->value == value){
        std::cout << "Found duplicates.\n";
        return t;
    } else if(t->value > value){
        t->left = HelperInsertR(t->left, value);
    } else{
        t->right = HelperInsertR(t->right, value);
    }
    return t;
}

template<class T>
TreeNode<T> * BinarySearchTree<T>::HelperDelete(TreeNode<T> *t, T value){
    if(t == NULL){
        return t;
    }
    
    if(t->value == value){
        
        if(t->left == NULL){
            TreeNode<T> * temp = t->right;
            delete t;
            return temp;
        } else if(t->right == NULL){
            TreeNode<T> * temp = t->left;
            delete t;
            return temp;
        } else{
            if(HelperHeight(t->left) > HelperHeight(t->right)){
                TreeNode<T> * pred = FindPredecessor(t);
                t->value = pred->value;
                t->left = HelperDelete(t->left, t->value);
            } else{
                TreeNode<T> * pred = FindSuccessor(t);
                t->value = pred->value;
                t->right = HelperDelete(t->right, t->value);
            }
        }
    } else if(t->value < value){
        t->right = HelperDelete(t->right, value);
    } else{
        t->left = HelperDelete(t->left, value);
    }
    return t;
}

template<class T>
bool BinarySearchTree<T>::Search(T value){
    TreeNode<T> * t = root;
    
    while(t){
        if(t->value == value){
            return true;
        } else if(t->value > value){
            t = t->left;
        } else{
            t = t->right;
        }
    }
    return false;
}

template<class T>
bool BinarySearchTree<T>::SearchR(T value){
    if(root == NULL){
        return false;
    }
    return HelperSearchR(root, value);
}

template<class T>
bool BinarySearchTree<T>::Insert(T value){
    
    if(root == NULL){
        TreeNode<T>  *newNode =  new TreeNode<T>();
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return true;
    }
    
    TreeNode<T> * t = root;
    TreeNode<T> * prev = root;
    while(t){
        if(t->value == value){
            std::cout << "Found duplicates.\n";
            return false;
        } else if(t->value > value){
            prev = t;
            t = t->left;
        } else{
            prev = t;
            t = t->right;
        }
    }
    
    TreeNode<T>  *newNode =  new TreeNode<T>();
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    t = newNode;
    
    if(prev->value > t->value){
        prev->left = t;
    } else{
        prev->right = t;
    }
    return true;
}

template<class T>
bool BinarySearchTree<T>::InsertR(T value){
    int prev = HelperCountNode(root);
    root = HelperInsertR(root, value);
    if(HelperCountNode(root) == prev + 1){
        return true;
    }
    return false;
}

template<class T>
bool BinarySearchTree<T>::DeleteR(T value){
    if(root == NULL){
        std::cout << "Tree is empty.\n";
        return false;
    }
    int prev = HelperCountNode(root);
    root = HelperDelete(root, value);
    if(HelperCountNode(root) == prev - 1){
        return true;
    }
   return false;
}

template<class T>
bool BinarySearchTree<T>::Delete(T value){
    if(root == NULL){
        std::cout << "Tree is empty.\n";
        return false;
    }
    // unlike recursive version, we need a tail pointer for connection
    TreeNode<T> * parent = root;
    TreeNode<T> * curr = root;
    
    while(curr != NULL){
        if(curr->value == value){
            break;
        } else if(curr->value > value){
            parent = curr;
            curr = curr->left;
        } else{
            parent = curr;
            curr = curr->right;
        }
    }
    
    if(curr == NULL){
        std::cout << "No such element.\n";
        return false;
    }
    
    // first deal with the case with nodes with 2 children
    // if not, then skip this part
    if(HelperHeight(curr->left) > HelperHeight(curr->right)){
        TreeNode<T> * pred = curr->left;
        TreeNode<T> * predParent = pred;
        while(pred->right){
            predParent = pred;
            pred = pred->right;
        }
        curr->value = pred->value;
        curr = pred;
        parent = predParent;
    } else{
        TreeNode<T> * pred = curr->right;
        TreeNode<T> * predParent = pred;
        while(pred->left){
            predParent = pred;
            pred = pred->left;
        }
        curr->value = pred->value;
        curr = pred;
        parent = predParent;
    }
    
    // cases for nodes with 0 or 1 child
    // with the help of previous if statement, we can sure that the node to
    //  be removed will have only 0 or 1 child
    TreeNode<T> * child = NULL;
    if(curr->left == NULL){
        child = curr->right;
    } else {
        child = curr->left;
    }
    
    if(parent == NULL){
        root = child;
    }
    else if(parent->right == curr){
        parent->right = child;
    } else {
        parent->left = child;
    }
    delete curr;
    return true;
}

template<class T>
TreeNode<T> * BinarySearchTree<T>::FindPredecessor(TreeNode<T> * t){
    TreeNode<T> * temp = t;
    if(t == NULL || t->left == NULL){
        std::cout << "Error: No predecessor.\n";
        return NULL;
    }
    temp = temp->left;
    while(temp->right){
        temp = temp->right;
    }
    return temp;
}
template<class T>
TreeNode<T> * BinarySearchTree<T>::FindSuccessor(TreeNode<T> * t){
    TreeNode<T> * temp = t;
    if(t == NULL || t->right == NULL){
        std::cout << "Error: No successor.\n";
        return NULL;
    }
    temp = temp->right;
    while(temp->left){
        temp = temp->left;
    }
    return temp;
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
