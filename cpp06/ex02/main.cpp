#include "Base.hpp"
#include <iostream>

void identify(Base* p);
void identify(Base& p);
Base* generate();

int main() {
    Base* obj = generate();
    std::cout << "Identified from pointer: ";
    identify(obj);
    std::cout << "Identified from reference: ";
    identify(*obj);
    delete obj;
    return 0;
}
