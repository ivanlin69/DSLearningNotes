#ifndef DiagonalMatrix_hpp
#define DiagonalMatrix_hpp

#include <stdio.h>

class DiagonalMartix{
private:
    int *A;
    size_t size;
public:
    DiagonalMartix(size_t size);
    int Get(size_t x, size_t y);
    void Set(size_t x, size_t y, int value);
    void Display();
    ~DiagonalMartix();
};

class LowerTriangularMatrix{
private:
    int *A;
    size_t size;
public:
    LowerTriangularMatrix(size_t size);
    int Get(size_t x, size_t y);
    void Set(size_t x, size_t y, int value);
    void Display();
    ~LowerTriangularMatrix();
};

class TriDiagonalMatrix{
private:
    int *A;
    size_t size;
public:
    TriDiagonalMatrix(size_t size);
    size_t GetIndex(size_t x, size_t y);
    int Get(size_t x, size_t y);
    void Set(size_t x, size_t y, int value);
    void Display();
    ~TriDiagonalMatrix();
};

class SparseElement{
public:
    size_t row;
    size_t col;
    int value;
    SparseElement(){}
    SparseElement(size_t r, size_t c, int v);
    ~SparseElement(){}
};

class SparseMatrix{
private:
    size_t rowLength;
    size_t colLength;
    size_t size;
    size_t length;
    SparseElement *A;

public:
    SparseMatrix(size_t r, size_t c, size_t s, size_t l);
    void AddElement(SparseElement e);
    static SparseMatrix * Adding(SparseMatrix *m1, SparseMatrix *m2);
    void Display();
    ~SparseMatrix();
};


#endif /* DiagonalMatrix_hpp */
