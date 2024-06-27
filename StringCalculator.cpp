#include "StringCalculator.h"
#include <sstream>
#include <string>

int StringCalculator::add(const std::string& input) {
    std::istringstream ss(input);
    std::string token;
    int sum = 0;
    char delimiter = ',';

    while (std::getline(ss, token, delimiter)) {
        sum += std::stoi(token);
    }

    return sum;
}
