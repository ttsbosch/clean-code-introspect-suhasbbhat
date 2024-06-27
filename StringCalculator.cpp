#include "StringCalculator.h"
#include <sstream>
#include <string>
#include <stdexcept> // For std::runtime_error

int StringCalculator::add(const std::string& input) {
    std::istringstream ss(input);
    std::string token;
    int sum = 0;
    char delimiter = ',';

    while (std::getline(ss, token, delimiter)) {
        int number = std::stoi(token);
        if (number < 0) {
            throw std::runtime_error("Negatives not allowed");
        }
        sum += number;
    }

    return sum;
}
