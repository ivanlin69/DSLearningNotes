#include "LinkedList.hpp"
#include <stdio.h>
#include <stdlib.h>


void LinkedList::AddEnd(int e){
    
    Node * newNode = new Node(e, NULL);
    
    if(head == NULL){
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::AddFront(int e){
    
    Node * newNode = new Node(e, head);
    newNode->value = e;
    newNode->next = head;
    
    if(head == NULL){
        tail = newNode;
    }
    head = newNode;
    length++;
}

void LinkedList::DeleteFront(){
    
    if(head == NULL){
        return;
    } else if(head->next == NULL){
        delete head;
        head = NULL;
        tail = NULL;
    } else{
        Node * temp = head;
        head = head->next;
        delete temp;
    }
    length--;
}

// delete the target value(first found)
void LinkedList::Delete(int e){
    
    Node * temp = head;
    if(!head)
        return;
    
    if(temp->value == e){
        DeleteFront();
        return;
    }
    
    Node * prev = NULL;
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

void LinkedList::Insert(size_t index, int e){
    
    if(index < 0 || index > length){
        return;
    } else if(index == 0){
        AddFront(e);
        return;
    } else if(index == length){
        AddEnd(e);
        return;
    } else {
        Node * t = head;
        while(index > 1){
            t = t->next;
            index--;
        }
        
        Node * newNode = new Node(e, t->next);
        t->next = newNode;
    }
    length++;
}

// only applied fot an sorted linkedlist
void LinkedList::InsertSorted(int e){

    Node * newNode = new Node(e, NULL);
    
    if(head == NULL){
        head = newNode;
        tail = newNode;
    } else{
        Node * temp = head;
        if(temp->value > e){
            newNode->next = head;
            head = newNode;
        } else{
            while(temp->next != NULL && temp->next->value < e){
                temp = temp->next;
            }
            newNode->next = temp->next;
            if(temp->next == NULL){
                tail = newNode;
            }
            temp->next = newNode;
        }
    }
    length++;
}


void LinkedList::DisplayLL(){
    Node * temp = head;
    
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void LinkedList::DisplayLLRecursive(Node * head){
    if(head != NULL){
        printf("%d ", head->value);
        DisplayLLRecursive(head->next);
        // printf("%d ", head->value);  prints backward
    }
}

int LinkedList::Sum(){
    Node * temp = head;
    int sum=0;
    
    while(temp){
        sum += temp->value;
        temp = temp->next;
    }
    return sum;
}

int LinkedList::SumRecursion(Node * head){
    
    if(!head){
        return 0;
    }
    return SumRecursion(head->next) + head->value;
}

int LinkedList::Max(){
    Node * temp = head;
    int max=temp->value;
    
    while(temp){
        if(max < temp->value){
            max = temp->value;
        }
        temp = temp->next;
    }
    return max;
}

int LinkedList::MaxRecursion(Node * head){
    Node * temp = head;
    int max=0;
    
    if(!temp){
        return INT32_MIN;
    }
    max = MaxRecursion(temp->next);
    if(max < temp->value){
        return temp->value;
    }
    return max;
    // return max < temp->value ? temp->value : max;
}


Node * LinkedList::Search(int value){
    Node * temp = head;
    while(temp) {
        if(temp->value == value){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// improved with moving to head(order will be changed)
Node * LinkedList::SearchMH(int value){
    Node * curr = head;
    Node * prev = NULL;
    
    while(curr) {
        if(curr->value == value){
            if(prev == NULL){
                return curr;
            }
            if(curr == tail){
                tail = prev;
            }
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL;
}

int LinkedList::IsSorted(){
    if(head == NULL || head->next == NULL){
        return 1;
    }
    Node * curr = head;
    
    while(curr->next){
        if(curr->value > curr->next->value){
            return 0;
        }
        curr = curr->next;
    }
    return 1;
}

void LinkedList::DeleteDuplicates(){
    
    if(head == NULL || head->next == NULL){
        return;
    }
    
    Node * curr = head;
    while(curr->next != NULL){
        if(curr->next->value == curr->value){
            Node * temp = curr->next;
            if(curr->next->next == NULL){
                tail = curr;
            }
            curr->next = curr->next->next;
            delete temp;
            length--;
        } else{
            // move forward if no duplictes
            curr = curr->next;
        }
    }
}

void LinkedList::Reverse(){
    
    if(head == NULL || head->next == NULL){
        return;
    }
    Node * curr = head;
    Node * next;
    tail = curr;
    
    while(curr->next){
        next = curr->next;
        curr->next = next->next;
        next->next = head;
        head = next;
    }
}

void LinkedList::ReverseV2(){
    
    Node * r = NULL;
    Node * q = NULL;
    Node * p = head;
    tail = head;
    
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void LinkedList::ReverseR(Node * n){
    
    if(n == NULL || n->next == NULL){
        return;
    }
    
    if(n->next->next != NULL){
        ReverseR(n->next);
    } else {
        head = n->next;
    }
    
    n->next->next = n;
    n->next = NULL;
    tail = n;
}

// doesn't keep the duplicates
// merging without copying elements, note thay any modification on the elements affects all lists
LinkedList * LinkedList::Merge2SortedLL(LinkedList * l1, LinkedList * l2){
    
    Node * h1 = l1->head;
    Node * h2 = l2->head;
    
    if(l1->head == NULL){
        return l2;
    } else if(l2->head == NULL){
        return l1;
    }
    
    LinkedList * merged = new LinkedList();
    Node * temp;
    
    if(h1->value > h2->value){
        merged->head = h2;
        h2 = h2->next;
    } else if(h1->value < h2->value){
        merged->head = h1;
        h1 = h1->next;
    } else{
        merged->head = h1;
        h1 = h1->next;
        h2 = h2->next;
    }
    merged->length++;
    temp = merged->head;
    
    while(h1 && h2){
        if(h1->value > h2->value){
            temp->next = h2;
            h2 = h2->next;
        } else if(h1->value < h2->value){
            temp->next = h1;
            h1 = h1->next;
        } else{
            temp->next = h1;
            h1 = h1->next;
            h2 = h2->next;
        }
        merged->length++;
        temp = temp->next;
    }
    
    while(h1){
        temp->next = h1;
        h1 = h1->next;
        temp = temp->next;
        merged->length++;
    }
    while(h2){
        temp->next = h2;
        h2 = h2->next;
        temp = temp->next;
        merged->length++;
    }
    
    merged->tail = temp;
    temp->next = NULL;

    return merged;
}

int LinkedList::HaveLoop(){
    
    Node * p = head;
    Node * q = head;
    
    if(p == NULL || p->next == NULL){
        return 0;
    }
    
    while(p && q){
        p = p->next;
        q = q->next;
        
        if(q) {
            // q moves faster
            q = q->next;
        }
        
        if(p == q){
            return 1;
        }
    }
    return 0;
}

LinkedList::~LinkedList(){
    while(head){
        Node * temp = head;
        head = head->next;
        delete temp;
    }
}
