#include "StringCalculator.h"
#include <sstream>
#include <stdexcept> // for std::invalid_argument

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;
    }

    std::stringstream ss(input);
    int sum = 0;
    char delimiter = ',';
    int number;

    // Read the first number
    ss >> number;
    sum += number;

    // Check if there is a second number
    if (ss.peek() == delimiter) {
        ss.ignore(); // Skip the comma
        ss >> number; // Read the second number
        sum += number;
    }

    // Check for any additional numbers
    while (ss >> number) {
        sum += number;
        ss.ignore(); // Skip the comma
    }

    return sum;
}
