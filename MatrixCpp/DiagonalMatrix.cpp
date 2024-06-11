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



LowerTriangularMatrix::LowerTriangularMatrix(size_t size) : size(size){
    A = new int[size*(size+1)/2];
}

int LowerTriangularMatrix::Get(size_t x, size_t y){
    if(x < size && y < size){
        if(x>=y){
            return A[x*(x+1)/2 + y];
        }
    }
    return 0;
}

void LowerTriangularMatrix::Set(size_t x, size_t y, int value){
    if(x < size && y < size && x >= y){
        A[x*(x+1)/2 + y] = value;
    }
}

void LowerTriangularMatrix::Display(){
    for(size_t i=0; i<size; i++){
        for(size_t j=0; j<size; j++){
            if(i>=j){
                printf("%d ", A[i*(i+1)/2 + j]);
            } else{
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
    printf("\n");
}

LowerTriangularMatrix::~LowerTriangularMatrix(){
    delete [] A;
}
