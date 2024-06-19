#include <iostream>
#include "LinkedList.hpp"

int main(int argc, const char * argv[]) {

    LinkedList l;
    l.DisplayLL();
    
    l.AddEnd(34);
    l.AddEnd(-3);
    l.AddEnd(386);
    l.AddEnd(67);
    l.AddFront(543);
    
    l.DisplayLL();
    l.DisplayLLRecursive(l.getHead());
    printf("\n");
    
    printf("Sum is: %d\n", l.Sum());
    printf("Sum(Recursion) is: %d\n", l.SumRecursion(l.getHead()));
    printf("Max is: %d\n", l.Max());
    printf("Max(Recursion) is: %d\n", l.MaxRecursion(l.getHead()));
    
    Node * t =  l.Search(87);
    if(t){
        printf("Search: %d found.\n", t->value);
    } else{
        printf("Not found.\n");
    }
    
    t = l.SearchMH(67);
    if(t){
        printf("SearchMH: %d found.\n", t->value);
    } else{
        printf("Not found.\n");
    }
    
    l.DisplayLL();
    l.SearchMH(67);
    
    l.Insert(4, 666);
    l.DisplayLL();

    
    LinkedList l2;
    
    l2.DisplayLL();
    
    l2.InsertSorted(34);
    l2.InsertSorted(43);
    l2.InsertSorted(-9);
    l2.InsertSorted(105);
    l2.InsertSorted(36);
    
    l2.DisplayLL();
    
    l2.DeleteFront();
    l2.DisplayLL();
    
    l2.Delete(105);
    l2.DisplayLL();
    l2.AddFront(90);
    l2.DisplayLL();
    
    printf("Is sorted? : %d\n", l2.IsSorted());

    
    LinkedList l3;
    
    l3.InsertSorted(3);
    l3.InsertSorted(3);
    l3.InsertSorted(4);
    l3.InsertSorted(9);
    l3.InsertSorted(9);
    l3.InsertSorted(9);
    
    l3.DisplayLL();
    
    l3.DeleteDuplicates();
    l3.InsertSorted(16);
    l3.DisplayLL();
    
    l3.Reverse();
    l3.DisplayLL();
    
    l3.ReverseV2();
    l3.DisplayLL();
    
    l3.ReverseR(l3.getHead());
    l3.DisplayLL();
    
    return 0;
}
