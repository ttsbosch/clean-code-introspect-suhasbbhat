#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>

int StringCalculator::Add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    // Determine delimiters
    std::string delimiter = ",";
    size_t delimiterStart = numbers.find("//");
    if (delimiterStart != std::string::npos) {
        delimiterStart += 2;
        size_t delimiterEnd = numbers.find("\n", delimiterStart);
        delimiter = numbers.substr(delimiterStart, delimiterEnd - delimiterStart);
        numbers.erase(0, delimiterEnd + 1);
    }

    // Replace newlines with delimiter
    std::replace(numbers.begin(), numbers.end(), '\n', delimiter.front());

    // Tokenize input string based on delimiters
    std::istringstream ss(numbers);
    std::string token;
    int sum = 0;

    while (std::getline(ss, token, delimiter.front())) {
        int num = std::stoi(token);

        if (num < 0) {
            throw std::runtime_error("Negatives not allowed: " + token);
        }

        if (num <= 1000) {
            sum += num;
        }
    }

    return sum;
}
