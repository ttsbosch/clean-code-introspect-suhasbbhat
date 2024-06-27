#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <vector>

// Simplified to directly return the delimiter without modifying the input string
std::pair<std::string, std::string> StringCalculator::ExtractDelimiter(const std::string& numbers) {
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterEnd = numbers.find("\n");
        std::string delimiter = numbers.substr(2, delimiterEnd - 2);
        std::string modifiedNumbers = numbers.substr(delimiterEnd + 1);
        return {delimiter, modifiedNumbers};
    }
    return {",", numbers};
}

// Simplified by moving the check for numbers <= 1000 directly into the Tokenize function
int StringCalculator::SumNumbers(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum;
}

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;
    }

    auto [delimiter, numbers] = ExtractDelimiter(input);
    std::string modifiedNumbers = ReplaceNewlineWithComma(numbers);
    std::vector<int> tokens = Tokenize(modifiedNumbers, delimiter);
    return SumNumbers(tokens);
}

std::string StringCalculator::ReplaceNewlineWithComma(const std::string& input) {
    std::string result = input;
    std::replace(result.begin(), result.end(), '\n', ',');
    return result;
}

// Tokenizes the input string and filters out numbers > 1000
std::vector<int> StringCalculator::Tokenize(const std::string& input, const std::string& delimiter) {
    std::vector<int> numbers;
    size_t start = 0, end = 0;
    while ((end = input.find(delimiter, start)) != std::string::npos) {
        int num = std::stoi(input.substr(start, end - start));
        if (num <= 1000) numbers.push_back(num);
        start = end + delimiter.length();
    }
    int lastNum = std::stoi(input.substr(start));
    if (lastNum <= 1000) numbers.push_back(lastNum);
    return numbers;
}
