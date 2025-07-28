#include <iostream>
#include <stdexcept>

int main() {
    unsigned int size = 5;

    int* a = new int();
    std::cout << *a << std::endl;
    
    int* b = new int[size];
    for (unsigned int i = 0; i < size; ++i)
        b[i] = i * 10;

    int* c = new int[size];
    for (unsigned int i = 0; i < size; ++i)
        c[i] = b[i];

    c[0] = 999;

    for (unsigned int i = 0; i < size; ++i)
        std::cout << "b[" << i << "] = " << b[i] << ", c[" << i << "] = " << c[i] << std::endl;

    try {
        if (10 >= size)
            throw std::out_of_range("Index out of range");
        std::cout << b[10] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    delete a;
    delete[] b;
    delete[] c;

    return 0;
}

