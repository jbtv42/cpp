#include <iostream>
#include "iter.hpp"

template<typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    ::iter(arr, 5, printElement);
    std::cout << std::endl;

    std::string s[] = {"hello", "world"};
    ::iter(s, 2, printElement);
    std::cout << std::endl;

    return 0;
}
