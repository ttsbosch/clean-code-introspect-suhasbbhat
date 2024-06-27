#include "StringCalculator.h"
#include <sstream>

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;
    }

    std::stringstream ss(input);
    int sum = 0;
    char delimiter = ',';
    int number;

    // Read numbers separated by commas
    while (ss >> number) {
        sum += number;

        // Check for comma and skip it
        if (ss.peek() == delimiter) {
            ss.ignore();
        }
    }

    return sum;
}
