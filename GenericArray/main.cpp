#include <iostream>
#include "Array.hpp"
#include "Array.cpp"

int main(int argc, const char * argv[]) {

    Array<float> * a = new Array<float>({1.1f, 2.3f, 3.5f});
    a->Display();
    
    a->Insert(1, 5.12f);
    a->Display();
    float test = a->Delete(5.12f);
    a->Display();
    std::cout << test << std::endl;
    a->Set(1, 1.92);
    a->Display();
    
    Array<float> * b = new Array<float>({21.1f, 234.3f, 443.5f, 1567.1});
    b->Display();
    *b = *a;
    b->Display();
    std::cout << (*b)[0] << " " << (*b)[1] << std::endl;
    
    delete a;
    //delete b;
    
    return 0;
}
