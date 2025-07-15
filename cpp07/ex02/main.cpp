#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = i * 10;

    Array<int> b = a;
    b[0] = 999;

    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << "a[" << i << "] = " << a[i] << ", b[" << i << "] = " << b[i] << std::endl;

    try {
        std::cout << a[10] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
