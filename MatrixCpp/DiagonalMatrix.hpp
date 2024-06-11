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

#endif /* DiagonalMatrix_hpp */
