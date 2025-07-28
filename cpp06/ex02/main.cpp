#include "Base.hpp"
#include <iostream>

int main() {
    Base* obj = generate();
    std::cout << "Identified from pointer: ";
    identify(obj);
    std::cout << "Identified from reference: ";
    identify(*obj);
    delete obj;
    return 0;
}
