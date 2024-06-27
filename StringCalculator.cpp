#include "StringCalculator.h"
#include <sstream>

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;
    }

    std::stringstream ss(input);
    int number;
    int sum = 0;

    while (ss >> number) {
        sum += number;
        if (ss.peek() == ',') {
            ss.ignore();
        }
    }

    return sum;
}
