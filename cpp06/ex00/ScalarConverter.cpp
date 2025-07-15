#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cctype>

static bool isChar(const std::string& str) {
    return str.length() == 1 && !std::isdigit(str[0]);
}

static bool isFloatPseudo(const std::string& str) {
    return str == "-inff" || str == "+inff" || str == "nanf";
}

static bool isDoublePseudo(const std::string& str) {
    return str == "-inf" || str == "+inf" || str == "nan";
}

void ScalarConverter::convert(std::string const& literal) {
    double value;

    if (isChar(literal)) {
        char c = literal[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << "\n";
        return;
    }

    if (isFloatPseudo(literal)) {
        std::string d = literal.substr(0, literal.length() - 1);
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "\n";
        std::cout << "double: " << d << "\n";
        return;
    }

    if (isDoublePseudo(literal)) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f\n";
        std::cout << "double: " << literal << "\n";
        return;
    }

    try {
        size_t idx = 0;
        value = std::stod(literal, &idx);
        if (idx != literal.length() && literal[literal.length() - 1] != 'f') throw std::invalid_argument("Invalid");
    } catch (...) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    if (value < 0 || value > 127 || std::isnan(value))
        std::cout << "char: impossible\n";
    else if (std::isprint(static_cast<char>(value)))
        std::cout << "char: '" << static_cast<char>(value) << "'\n";
    else
        std::cout << "char: Non displayable\n";

    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value))
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(value) << "\n";

    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << "\n";
}
