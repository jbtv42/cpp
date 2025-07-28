#include "iter.hpp"
#include <iostream>
#include <cstddef>

template<typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    iter(a, 5, printElement);
    std::cout << std::endl;

    const int b[] = { 6, 7, 8, 9, 10};
    iter(b, 5, printElement);
    std::cout << std::endl;

    return 0;
}
