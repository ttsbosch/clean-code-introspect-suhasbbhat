#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <vector>

// Extracts the delimiter from the input string and modifies the string to remove the delimiter declaration
std::string StringCalculator::ExtractDelimiter(std::string& numbers) {
    std::string delimiter = ",";
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterStart = numbers.find("//") + 2;
        size_t delimiterEnd = numbers.find("\n");
        delimiter = numbers.substr(delimiterStart, delimiterEnd - delimiterStart);
        numbers.erase(0, delimiterEnd + 1);
    }
    return delimiter;
}

// Sums the numbers in the string, using the provided delimiter
int StringCalculator::SumNumbers(const std::string& numbers, const std::string& delimiter) {
    std::vector<std::string> tokens = Tokenize(numbers, delimiter);
    int sum = 0;
    for (const auto& token : tokens) {
        int num = std::stoi(token);
        if (num <= 1000) {
            sum += num;
        }
    }
    return sum;
}

int StringCalculator::Add(std::string numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiter = ExtractDelimiter(numbers);
    std::replace(numbers.begin(), numbers.end(), '\n', ',');
    return SumNumbers(numbers, delimiter);
}
