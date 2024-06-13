#include <iostream>
#include "DiagonalMatrix.hpp"

int main(int argc, const char * argv[]) {
    /**
    DiagonalMartix m(10);
    m.Set(1, 1, 20);
    m.Display();
    
    LowerTriangularMatrix m2(4);
    m2.Set(1, 1, 20);
    m2.Set(2, 1, 20);
    m2.Set(3, 3, 20);
    m2.Set(0, 1, 20);
    m2.Display();
    
    TriDiagonalMatrix m3(4);
    m3.Set(1, 1, 20);
    m3.Set(2, 1, 20);
    m3.Set(3, 3, 20);
    m3.Set(0, 1, 20);
    m3.Set(2, 1, 20);
    
    m3.Set(3, 1, 20);
    
    m3.Display();
     */
    
    SparseMatrix m(5, 7, 6, 0);
    
    SparseElement e1(1, 2, 81);
    SparseElement e2(3, 4, 4);
    SparseElement e3(2, 2, 34);
    SparseElement e4(4, 2, 6);
    SparseElement e5(2, 5, 877);
    SparseElement e6(0, 1, 22);
    
    // add elements in ascending order
    m.AddElement(e6);
    m.AddElement(e1);
    m.AddElement(e3);
    m.AddElement(e5);
    m.AddElement(e2);
    m.AddElement(e4);
    
    m.Display();
    
    SparseMatrix other(5, 7, 8, 0);
    
    SparseElement e7(3, 3, 66);
    SparseElement e8(1, 0, 66);
    
    // add elements in ascending order
    
    other.AddElement(e6);
    other.AddElement(e8);
    other.AddElement(e1);
    other.AddElement(e3);
    other.AddElement(e5);
    other.AddElement(e7);
    other.AddElement(e2);
    other.AddElement(e4);
    
    printf("\n");

    other.Display();
    
    printf("\n");
    
    SparseMatrix *r = SparseMatrix::Adding(&m, &other);
    r->Display();
    
    return 0;
}
