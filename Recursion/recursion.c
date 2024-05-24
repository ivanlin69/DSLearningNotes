#include "recursion.h"

int sumNaturalNumbers(int n){
    int sum = 0;
    
    if(n == 0){
        return n;
    }
    
    sum = n + sumNaturalNumbers(n-1);
    return sum;
}
