#include "LinkedList.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template<class T>
void LinkedList<T>::AddEnd(T e){
    
    Node<T> * newNode = new Node<T>(e, NULL);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

template<class T>
void LinkedList<T>::AddFront(T e){
    
    Node<T> * newNode = new Node<T>(e, head);
    newNode->value = e;
    newNode->next = head;
    
    if(head == NULL){
        tail = newNode;
    }
    head = newNode;
    length++;
}

template<class T>
T LinkedList<T>::DeleteFront(){
    
    if(head == NULL){
        return NULL;
    } else if(head->next == NULL){
        delete head;
        head = NULL;
        tail = NULL;
        return NULL;
    } else{
        Node<T> * temp = head;
        T del = temp->value;
        head = head->next;
        delete temp;
        return del;
    }
    length--;
}

template<class T>
T LinkedList<T>::Delete(T e, size_t index){
    
    if(!head)
        return NULL;
    
    if(index == 0){
        return DeleteFront();
    }
    
    Node<T> * prev = head;
    for(size_t i=0; i<index-1; i++){
        if(prev->next == NULL){
            std::cout << "Index out of bound.\n";
            return NULL;
        }
        prev = prev->next;
    }
    Node<T> * temp = prev->next;
    T del = temp->value;
    prev->next = temp->next;
    delete temp;
    length--;
    return del;
}

template<class T>
void LinkedList<T>::Insert(size_t index, T e){
    
    if(index < 0 || index > length){
        return;
    } else if(index == 0){
        AddFront(e);
        return;
    } else if(index == length){
        AddEnd(e);
        return;
    } else {
        Node<T> * t = head;
        while(index > 1){
            t = t->next;
            index--;
        }
        
        Node<T> * newNode = new Node<T>(e, t->next);
        t->next = newNode;
    }
    length++;
}

template<class T>
void LinkedList<T>::DisplayLL(){
    Node<T> * temp = head;
    
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

template<class T>
void LinkedList<T>::Reverse(){
    
    if(head == NULL || head->next == NULL){
        return;
    }
    Node<T> * curr = head;
    Node<T> * next;
    tail = curr;
    
    while(curr->next){
        next = curr->next;
        curr->next = next->next;
        next->next = head;
        head = next;
    }
}

template<class T>
LinkedList<T>::~LinkedList(){
    while(head){
        Node<T> * temp = head;
        head = head->next;
        delete temp;
    }
}
