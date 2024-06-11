#include <iostream>
#include "DiagonalMatrix.hpp"

int main(int argc, const char * argv[]) {
    
    DiagonalMartix m(10);
    m.Set(1, 1, 20);
    m.Display();
    
    return 0;
}
