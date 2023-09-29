// main.cpp

#include "calculator.hpp"

#include <iostream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    Calculator calculator;
    int value = calculator.evaluateInfix(input);
    
    std::cout << value << '\n';
    
    return EXIT_SUCCESS;
}

