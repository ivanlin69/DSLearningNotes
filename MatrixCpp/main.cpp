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
     */
    
    TriDiagonalMatrix m3(4);
    m3.Set(1, 1, 20);
    m3.Set(2, 1, 20);
    m3.Set(3, 3, 20);
    m3.Set(0, 1, 20);
    m3.Set(2, 1, 20);
    
    m3.Set(3, 1, 20);
    
    m3.Display();
    
    return 0;
}