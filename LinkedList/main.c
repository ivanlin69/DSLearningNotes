#include <stdio.h>
#include <stdlib.h>


struct Node{
    int value;
    struct Node *next;
};

struct LinkedList{
    size_t length;
    struct Node *head;
    struct Node *tail;
};

void AddEnd(struct LinkedList * l, int e){
    
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->value = e;
    newNode->next = NULL;
    
    if(l->head == NULL){
        l->head = newNode;
        l->tail = newNode;
    } else {
        l->tail->next = newNode;
        l->tail = newNode;
    }
    l->length++;
}

void AddFront(struct LinkedList * l, int e){
    
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->value = e;
    newNode->next = l->head;
    
    if(l->head == NULL){
        l->tail = newNode;
    }
    l->head = newNode;
    l->length++;
}

void DeleteFront(struct LinkedList * l){
    
    if(l->head == NULL){
        return;
    } else if(l->head->next == NULL){
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
    } else{
        struct Node * temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
    l->length--;
}

// delete the target value(first found)
void Delete(struct LinkedList * l, int e){
    
    struct Node * temp = l->head;
    if(!l->head)
        return;
    
    if(temp->value == e){
        DeleteFront(l);
        return;
    } 
    
    struct Node * prev = NULL;
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
        l->tail = prev;
    }
    prev->next = temp->next;
    free(temp);
    l->length--;
}

void Insert(struct LinkedList * l, size_t index, int e){
    
    if(index < 0 || index > l->length){
        return;
    } else if(index == 0){
        AddFront(l, e);
        return;
    } else if(index == l->length){
        AddEnd(l, e);
        return;
    } else {
        struct Node * t = l->head;
        while(index > 1){
            t = t->next;
            index--;
        }
        
        struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->value = e;
        newNode->next = t->next;
        t->next = newNode;
    }
    l->length++;
}

// only applied fot an sorted linkedlist
void InsertSorted(struct LinkedList * l, int e){

    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->value = e;
    newNode->next = NULL;
    
    if(l->head == NULL){
        l->head = newNode;
        l->tail = newNode;
    } else{
        struct Node * temp = l->head;
        if(temp->value > e){
            newNode->next = l->head;
            l->head = newNode;
        } else{
            while(temp->next != NULL && temp->next->value < e){
                temp = temp->next;
            }
            newNode->next = temp->next;
            if(temp->next == NULL){
                l->tail = newNode;
            }
            temp->next = newNode;
        }
    }
    l->length++;
}


void DisplayLL(struct LinkedList * l){
    struct Node * temp = l->head;
    
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void DisplayLLRecursive(struct Node * head){
    if(head != NULL){
        printf("%d ", head->value);
        DisplayLLRecursive(head->next);
        // printf("%d ", head->value);  prints backward
    }
}

int Sum(struct LinkedList * l){
    struct Node * temp = l->head;
    int sum=0;
    
    while(temp){
        sum += temp->value;
        temp = temp->next;
    }
    return sum;
}

int SumRecursion(struct Node * head){
    
    if(!head){
        return 0;
    }
    return SumRecursion(head->next) + head->value;
}

int Max(struct LinkedList * l){
    struct Node * temp = l->head;
    int max=temp->value;
    
    while(temp){
        if(max < temp->value){
            max = temp->value;
        }
        temp = temp->next;
    }
    return max;
}

int MaxRecursion(struct Node * head){
    struct Node * temp = head;
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


struct Node * Search(struct LinkedList *l, int value){
    struct Node * temp = l->head;
    while(temp) {
        if(temp->value == value){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// improved with moving to head(order will be changed)
struct Node * SearchMH(struct LinkedList *l, int value){
    struct Node * curr = l->head;
    struct Node * prev = NULL;
    
    while(curr) {
        if(curr->value == value){
            if(prev == NULL){
                return curr;
            }
            if(curr == l->tail){
                l->tail = prev;
            }
            prev->next = curr->next;
            curr->next = l->head;
            l->head = curr;
            return l->head;
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL;
}

int IsSorted(struct LinkedList * l){
    if(l->head == NULL || l->head->next == NULL){
        return 1;
    }
    struct Node * curr = l->head;
    
    while(curr->next){
        if(curr->value > curr->next->value){
            return 0;
        }
        curr = curr->next;
    }
    return 1;
}

void DeleteDuplicates(struct LinkedList * l){
    
    if(l->head == NULL || l->head->next == NULL){
        return;
    }
    
    struct Node * curr = l->head;
    while(curr->next != NULL){
        if(curr->next->value == curr->value){
            struct Node * temp = curr->next;
            if(curr->next->next == NULL){
                l->tail = curr;
            }
            curr->next = curr->next->next;
            free(temp);
            l->length--;
        } else{
            // move forward if no duplictes
            curr = curr->next;
        }
    }
}

void Reverse(struct LinkedList * l){
    
    if(l->head == NULL || l->head->next == NULL){
        return;
    }
    struct Node * curr = l->head;
    struct Node * next;
    l->tail = curr;
    
    while(curr->next){
        next = curr->next;
        curr->next = next->next;
        next->next = l->head;
        l->head = next;
    }
}

void ReverseV2(struct LinkedList * l){
    
    struct Node * r = NULL;
    struct Node * q = NULL;
    struct Node * p = l->head;
    l->tail = l->head;
    
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    l->head = q;
}

void ReverseR(struct LinkedList * l, struct Node * n){
    
    if(n == NULL || n->next == NULL){
        return;
    }
    
    if(n->next->next != NULL){
        ReverseR(l, n->next);
    } else {
        l->head = n->next;
    }
    
    n->next->next = n;
    n->next = NULL;
    l->tail = n;
}

// doesn't keep the duplicates
// merging without copying elements, note thay any modification on the elements affects all lists
struct LinkedList * Merge2SortedLL(struct LinkedList * l1, struct LinkedList * l2){
    
    struct Node * h1 = l1->head;
    struct Node * h2 = l2->head;
    
    if(l1->head == NULL){
        return l2;
    } else if(l2->head == NULL){
        return l1;
    }
    
    struct LinkedList * merged = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    struct Node * temp;
    
    merged->length = 0;
    
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

int HaveLoop(struct LinkedList * l){
    
    struct Node * p = l->head;
    struct Node * q = l->head;
    
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

void freeLinkedlist(struct LinkedList *l){
    while(l->head){
        struct Node * temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
}


int main(int argc, const char * argv[]) {
    /**
    struct LinkedList l = {0, NULL, NULL};
    
    DisplayLL(&l);
    
    AddEnd(&l, 34);
    AddEnd(&l, -3);
    AddEnd(&l, 386);
    AddEnd(&l, 67);
    
    AddFront(&l, 543);
    
    DisplayLL(&l);
    DisplayLLRecursive(l.head);
    printf("\n");
    
    printf("Sum is: %d\n", Sum(&l));
    printf("Sum(Recursion) is: %d\n", SumRecursion(l.head));
    printf("Max is: %d\n", Max(&l));
    printf("Max(Recursion) is: %d\n", MaxRecursion(l.head));
    
    struct Node * t =  Search(&l, 87);
    if(t){
        printf("Search: %d found.\n", t->value);
    } else{
        printf("Not found.\n");
    }
    
    t = SearchMH(&l, 67);
    if(t){
        printf("SearchMH: %d found.\n", t->value);
    } else{
        printf("Not found.\n");
    }
    
    DisplayLL(&l);
    SearchMH(&l, 67);
    
    Insert(&l, 4, 666);
    DisplayLL(&l);

    
    struct LinkedList l2 = {0, NULL, NULL};
    
    DisplayLL(&l2);
    
    InsertSorted(&l2, 34);
    InsertSorted(&l2, 43);
    InsertSorted(&l2, -9);
    InsertSorted(&l2, 105);
    InsertSorted(&l2, 36);
    
    DisplayLL(&l2);
    
    DeleteFront(&l2);
    DisplayLL(&l2);
    
    Delete(&l2, 105);
    DisplayLL(&l2);
    AddFront(&l2, 90);
    DisplayLL(&l2);
    
    printf("Is sorted? : %d\n", IsSorted(&l2));

    
    struct LinkedList l3 = {0, NULL, NULL};
    
    InsertSorted(&l3, 3);
    InsertSorted(&l3, 3);
    InsertSorted(&l3, 4);
    InsertSorted(&l3, 9);
    InsertSorted(&l3, 9);
    InsertSorted(&l3, 9);
    
    DisplayLL(&l3);
    
    DeleteDuplicates(&l3);
    InsertSorted(&l3, 16);
    DisplayLL(&l3);
    
    Reverse(&l3);
    DisplayLL(&l3);
    
    ReverseV2(&l3);
    DisplayLL(&l3);
    
    ReverseR(&l3, l3.head);
    DisplayLL(&l3);
    */
    
    struct LinkedList l4 = {0, NULL, NULL};
    
    InsertSorted(&l4, 2);
    InsertSorted(&l4, 3);
    InsertSorted(&l4, 4);
    InsertSorted(&l4, 9);
    InsertSorted(&l4, 12);
    InsertSorted(&l4, 14);
    
    DisplayLL(&l4);
    
    struct LinkedList l5 = {0, NULL, NULL};
    
    InsertSorted(&l5, 11);
    InsertSorted(&l5, 14);
    InsertSorted(&l5, 110);
    InsertSorted(&l5, 119);
    InsertSorted(&l5, 121);
    
    DisplayLL(&l5);
    /**
    struct LinkedList *merged = Merge2SortedLL(&l4, &l5);
    DisplayLL(merged);
    
    // create a loop
    merged->tail->next = merged->head->next;
    printf("Is a loop? : %d \n", HaveLoop(merged));
     */
    freeLinkedlist(&l4);
    freeLinkedlist(&l5);
    
    return 0;
}
