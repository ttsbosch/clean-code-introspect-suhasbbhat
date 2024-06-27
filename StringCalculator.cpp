#include "StringCalculator.h"
#include <sstream>

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;
    }

    std::stringstream ss(input);
    int sum = 0;
    char delimiter = ',';

    while (ss >> sum) {
        ss.ignore(); // Ignore the delimiter
    }

    return sum;
}
