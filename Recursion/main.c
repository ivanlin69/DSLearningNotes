#include <stdio.h>
#include "recursion.h"


int main(int argc, const char * argv[]) {
    printf("\n");
    /**
    printf("Sum of first 'N' natural numbers: %d \n", sumNaturalNumbers(3));
    printf("Factorial of 'N': %lu \n", factorial(7));
    printf("power of 'N': %d \n", power(3, 2));
    printf("Taylor series of 'N': %f \n", taylorSeries(3, 20));
    printf("Taylor series(Iterative) of 'N': %f \n", taylorSeriesIter(3, 20));
    printf("Taylor series(Horner) of 'N': %f \n", taylorSeriesHorner(2, 10));
    printf("Taylor series(Horner_Iterative) of 'N': %f \n", taylorSeriesHornerIter(2, 10));
    
    printf("Fibonacci of 'N': %d \n", fibonacci(11));
    printf("Fibonacci(Iter) of 'N': %d \n", fibonacciIter(11));
    printf("Fibonacci(Memoization) of 'N': %d \n", fibonacciMemoization(11));
     */
    
    printf("Combination of 'N' take 'r': %d \n", combination(5, 2));
    printf("Tower of Hanoi of high 'N':\n");
    towerOfHanoi(4, 'A', 'B', 'C');
            
    printf("\n");
    return 0;
}
