#include "DiagonalMatrix.hpp"
#include <cmath>
#include <stdexcept>

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
    A = new int[3*size - 2];
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


SparseElement::SparseElement(size_t r, size_t c, int v) : row(r), col(c), value(v){}

SparseMatrix::SparseMatrix(size_t r, size_t c, size_t s, size_t l) : rowLength(r), colLength(c), size(s), length(l){
    A = new SparseElement[size];
}

void SparseMatrix::AddElement(SparseElement e){
    if(length < size){
        A[length++] = e;
    }
}

SparseMatrix SparseMatrix::operator+(SparseMatrix &m){
    
    if(rowLength != m.rowLength || colLength != m.colLength){
        return *this;
    }
    
    size_t i=0;
    size_t j=0;
    size_t index = 0;
    
    struct SparseMatrix *sm = new SparseMatrix(rowLength, colLength,(size + m.size), 0);
    
    while(i<length && j<m.length){
        if(A[i].row < m.A[j].row){
            sm->A[index++] = A[i++];
        } else if(A[i].row > m.A[j].row){
            sm->A[index++] = A[j++];
        } else{
            if(A[i].col < m.A[j].col){
                sm->A[index++] = A[i++];
            } else if(A[i].col > m.A[j].col){
                sm->A[index++] = m.A[j++];
            } else{
                sm->A[index] = A[i++];
                sm->A[index++].value += m.A[j++].value;
            }
        }
        sm->length++;
    }
    
    for(; i<length; i++){
        sm->A[i] = A[i];
        sm->length++;
    }
    
    for(; j<m.rowLength; j++){
        sm->A[j] = m.A[j];
        sm->length++;
    }
    
    return *sm;
    
}

// only applys when 2 matrixs are the same size
SparseMatrix SparseMatrix::Adding(SparseMatrix &m1, SparseMatrix &m2){
    
    if(m1.rowLength != m2.rowLength || m1.colLength != m2.colLength){
        throw std::runtime_error("out of boundary.");
    }
    
    size_t i=0;
    size_t j=0;
    size_t index = 0;
    
    struct SparseMatrix *sm = new SparseMatrix(m1.rowLength, m1.colLength,(m1.size + m2.size), 0);
    
    while(i<m1.length && j<m2.length){
        if(m1.A[i].row < m2.A[j].row){
            sm->A[index++] = m2.A[i++];
        } else if(m1.A[i].row > m2.A[j].row){
            sm->A[index++] = m1.A[j++];
        } else{
            if(m1.A[i].col < m2.A[j].col){
                sm->A[index++] = m1.A[i++];
            } else if(m1.A[i].col > m2.A[j].col){
                sm->A[index++] = m2.A[j++];
            } else{
                sm->A[index] = m1.A[i++];
                sm->A[index++].value += m2.A[j++].value;
            }
        }
        sm->length++;
    }
    
    for(; i<m1.length; i++){
        sm->A[i] = m1.A[i];
        sm->length++;
    }
    
    for(; j<m2.rowLength; j++){
        sm->A[j] = m2.A[j];
        sm->length++;
    }
    
    return *sm;
}


void SparseMatrix::Display(){
    size_t index = 0;
    for(size_t i=0; i<rowLength; i++){
        for(size_t j=0; j<colLength; j++){
            if(A[index].row == i && A[index].col == j){
                printf("%d ", A[index].value);
                index++;
            } else{
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
}
SparseMatrix::~SparseMatrix(){
    delete [] A;
};
