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
     */
    
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
    
    return 0;
}
