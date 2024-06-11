#include "DiagonalMatrix.hpp"


DiagonalMartix::DiagonalMartix(size_t size) : size(size){
    A = new int[size];
}

int DiagonalMartix::Get(size_t x, size_t y){
    if(x < size && y < size){
        if(x==y){
            return A[x];
        }
    }
    return 0;
}

void DiagonalMartix::Set(size_t x, size_t y, int value){
    if(x==y && x < size){
        A[x] = value;
    }
}

void DiagonalMartix::Display(){
    for(size_t i=0; i<size; i++){
        for(size_t j=0; j<size; j++){
            if(i==j){
                printf("%d ", A[i]);
            } else{
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
    printf("\n");
}

DiagonalMartix::~DiagonalMartix(){
    delete [] A;
}
