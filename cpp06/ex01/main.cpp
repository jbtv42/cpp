#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data = {42, "Data phrase"};
    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original Address: " << &data << "\n";
    std::cout << "Deserialized Address: " << ptr << "\n";
    std::cout << "Value: " << ptr->value << ", Text: " << ptr->text << "\n";
    return 0;
}
