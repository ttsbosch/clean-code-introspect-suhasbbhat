#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;
    }

    auto [delimiter, numbers] = ExtractDelimiter(input);
    std::string modifiedNumbers = ReplaceNewlineWithComma(numbers);
    std::vector<int> tokens = Tokenize(modifiedNumbers, delimiter);
    std::vector<int> filteredTokens = FilterNumbers(tokens);
    return SumNumbers(filteredTokens);
}

std::pair<std::string, std::string> StringCalculator::ExtractDelimiter(const std::string& numbers) {
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterEnd = numbers.find("\n");
        std::string delimiter = numbers.substr(2, delimiterEnd - 2);
        std::string modifiedNumbers = numbers.substr(delimiterEnd + 1);
        return {delimiter, modifiedNumbers};
    }
    return {",", numbers};
}

std::string StringCalculator::ReplaceNewlineWithComma(const std::string& input) {
    std::string result = input;
    std::replace(result.begin(), result.end(), '\n', ',');
    return result;
}

std::vector<int> StringCalculator::Tokenize(const std::string& input, const std::string& delimiter) {
    std::vector<int> numbers;
    size_t start = 0, end = 0;
    while ((end = input.find(delimiter, start)) != std::string::npos) {
        int num = std::stoi(input.substr(start, end - start));
        numbers.push_back(num);
        start = end + delimiter.length();
    }
    numbers.push_back(std::stoi(input.substr(start)));
    return numbers;
}

std::vector<int> StringCalculator::FilterNumbers(const std::vector<int>& numbers) {
    std::vector<int> filteredNumbers;
    for (int num : numbers) {
        if (num <= 1000) {
            filteredNumbers.push_back(num);
        }
    }
    return filteredNumbers;
}

int StringCalculator::SumNumbers(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum;
}
