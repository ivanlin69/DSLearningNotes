#include <stdio.h>
#include "recursion.h"


int main(int argc, const char * argv[]) {
    
    printf("Sum of first 'N' natural numbers: %d \n", sumNaturalNumbers(3));
    printf("Factorial of 'N': %lu \n", factorial(7));
    printf("power of 'N': %d \n", power(3, 2));
    printf("Taylor series of 'N': %f \n", taylorSeries(3, 20));
    printf("Taylor series(Iterative) of 'N': %f \n", taylorSeriesIter(3, 20));
    printf("Taylor series(Horner) of 'N': %f \n", taylorSeriesHorner(2, 10));
    printf("Taylor series(Horner_Iterative) of 'N': %f \n", taylorSeriesHornerIter(2, 10));
    printf("Fibonacci of 'N': %d \n", fibonacci(6));
    
    return 0;
}
