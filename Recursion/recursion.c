#include "recursion.h"
#include "math.h"


int sumNaturalNumbers(int n){
    int sum = 0;
    
    if(n == 0){
        return n;
    }
    
    sum = n + sumNaturalNumbers(n-1);
    return sum;
    
    // find the recursion relationship first:
    // T(n)=0, if n=0;
    // else, T(n) = T(n-1) + n;
}

unsigned long factorial(int n){
    unsigned long fac = 1;
    if(n == 1){
        return 1;
    }
    fac = n * factorial(n-1);
    return fac;
}

int power(int base, int p){
    int result = base;
    if(p == 0){
        return 1;
    }
    result = base * power(base, p-1);
    return result;
}

// use static variables, the function can only be called once
// reset function needed (bad use of recursion)
double taylorSeries(int x, int n){
    double prev = 0;
    static double pow = 1;
    static unsigned long fac = 1;
    
    if(n == 0){
        return 1;
    }
    
    prev = taylorSeries(x, n-1);
    
    pow = pow * x;
    fac = fac * n;
    return prev + pow/fac;
}

double taylorSeriesIter(int x, int n){
    double result = 1;
    
    if(n == 0){
        return result;
    }
    
    double pow = 1;
    double fac = 1;
    
    for(int i=1; i<=n; i++){
        pow *= x;
        fac *= i;
        result += pow / fac;
    }
    return result;
}


double taylorSeriesHorner(int x, int n){
    static double result = 1;
        
    if(n == 0){
        return result;
    }
    
    result = 1 + result * (double) x/n;
    
    return taylorSeriesHorner(x, n-1);
}

double taylorSeriesHornerIter(int x, int n){
    double result = 1;
    
    if(n == 0){
        return result;
    }   
    
    for(int i=n; i>0; i--){
        result = 1 + result * (double) x / i;
    }
    return result;
}

int fibonacci(int n){
    
    if(n == 0 || n == 1){
        return n;
    }
    
    return fibonacci(n-2) + fibonacci(n-1);
}

int fibonacciIter(int n){
    
    if(n == 0 || n == 1){
        return n;
    }
    int prev = 0;
    int result = 1;
    for(int i=1; i<n; i++){
        int temp = result;
        result += prev;
        prev = temp;
    }
    
    /**
        Better:
     int t0 = 0;
     int t1 = 1;
     int result = 0;
     for(int i=2; i<=n; i++){
         result = t0 + t1;
         t0 = t1;
         t1 = result;
     }
     */
    
    return result;
}

// For memoization, using global variable
// Can only be applied based on the array size
int F[10] = {0,1,1,-1,-1,-1,-1,-1,-1,-1};
int fibonacciMemoization(int n){
    
    if(n == 0 || n == 1){
        return F[n];
    }
    
    if(F[n-2] == -1){
        F[n-2] = fibonacciMemoization(n-2);
    }
    
    if(F[n-1] == -1){
        F[n-1] = fibonacciMemoization(n-1);
    }
    
    F[n] = F[n-2] + F[n-1];
    return F[n];
}

// Pascal triangle
int combination(int n, int r){
    
    if(r == 0 || r == n){
        return 1;
    }
    return combination(n-1, r-1) + combination(n-1, r);
}

void towerOfHanoi(int n, char A, char B, char C){
    
    if(n==1){
        printf("Move from %c to %c \n", A, C);
    } else{
        towerOfHanoi(n-1, A, C, B);
        towerOfHanoi(1, A, B, C);
        towerOfHanoi(n-1, B, A, C);
    }
}
