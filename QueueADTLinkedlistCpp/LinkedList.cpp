#include "LinkedList.hpp"
#include <stdio.h>
#include <stdlib.h>

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
void LinkedList<T>::DeleteFront(){
    
    if(head == NULL){
        return;
    } else if(head->next == NULL){
        delete head;
        head = NULL;
        tail = NULL;
    } else{
        Node<T> * temp = head;
        head = head->next;
        delete temp;
    }
    length--;
}

template<class T>
// delete the target value(first found)
void LinkedList<T>::Delete(T e){
    
    Node<T> * temp = head;
    if(!head)
        return;
    
    if(temp->value == e){
        DeleteFront();
        return;
    }
    
    Node<T> * prev = NULL;
    while(temp){
        if(temp->value == e){
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    if(temp->next == NULL){
        tail = prev;
    }
    prev->next = temp->next;
    delete temp;
    length--;
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
