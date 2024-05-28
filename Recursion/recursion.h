#ifndef recursion_h
#define recursion_h

#include <stdio.h>

int sumNaturalNumbers(int n);
unsigned long factorial(int n);
int power(int base, int p);
double taylorSeries(int x, int n);
double taylorSeriesIter(int x, int n);
double taylorSeriesHorner(int x, int n);
double taylorSeriesHornerIter(int x, int n);
int fibonacci(int n);
int fibonacciIter(int n);
int fibonacciMemoization(int n);
int combination(int n, int r);
void towerOfHanoi(int n, char A, char B, char C);

#endif
