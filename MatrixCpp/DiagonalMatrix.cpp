#include "DiagonalMatrix.hpp"
#include <cmath>

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



TriDiagonalMatrix::TriDiagonalMatrix(size_t size) : size(size){
    A = new int[size*(size+1)/2];
}

size_t TriDiagonalMatrix::GetIndex(size_t x, size_t y){
    int value = (int)x - (int)y;
    switch (value){
        case 1:
            return y;
        case 0:
            return size-1 + y;
        default:
            return 2*size -1 + y-1;
   }
}

int TriDiagonalMatrix::Get(size_t x, size_t y){
    if(std::abs( (int)x - (int)y) <= 1){
        return A[GetIndex(x, y)];
    }
    return 0;
}

void TriDiagonalMatrix::Set(size_t x, size_t y, int value){
    if(std::abs( (int)x - (int)y) <= 1){
        A[GetIndex(x, y)] = value;
    }
}

void TriDiagonalMatrix::Display(){
    for(size_t i=0; i<size; i++){
        for(size_t j=0; j<size; j++){
            if(std::abs( (int)i - (int)j) <= 1){
                printf("%d ", A[GetIndex(i, j)]);
            } else{
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
    printf("\n");
}

TriDiagonalMatrix::~TriDiagonalMatrix(){
    delete [] A;
}
