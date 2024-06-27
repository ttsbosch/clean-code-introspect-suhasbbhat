#include "StringCalculator.h"
#include <sstream>
#include <algorithm>
#include <numeric>
#include <stdexcept>

int StringCalculator::Add(const std::string& input) {
    if (input.empty()) return 0;

    std::vector<int> numbers = Tokenize(input);
    return SumNumbers(numbers);
}

std::vector<int> StringCalculator::Tokenize(const std::string& input) {
    std::string processedInput = input;
    char delimiter = DetectAndProcessCustomDelimiter(processedInput);

    return SplitAndConvertToNumbers(processedInput, delimiter);
}

char StringCalculator::DetectAndProcessCustomDelimiter(std::string& input) {
    char delimiter = ',';
    if (input.rfind("//", 0) == 0) {
        size_t newlinePos = input.find('\n');
        if (newlinePos != std::string::npos) {
            delimiter = input[2];
            input = input.substr(newlinePos + 1);
        }
    }
    return delimiter;
}

std::vector<int> StringCalculator::SplitAndConvertToNumbers(const std::string& input, char delimiter) {
    std::vector<int> tokens;
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, delimiter)) {
        ReplaceNewlinesWithCommas(token);
        std::istringstream tokenStream(token);
        std::string number;
        while (std::getline(tokenStream, number, ',')) {
            int num = std::stoi(number);
            ValidateAndAddNumber(num, tokens);
        }
    }

    return tokens;
}

void StringCalculator::ReplaceNewlinesWithCommas(std::string& token) {
    std::replace(token.begin(), token.end(), '\n', ',');
}

void StringCalculator::ValidateAndAddNumber(int number, std::vector<int>& tokens) {
    if (number < 0) {
        throw std::runtime_error("Negatives not allowed");
    }
    if (number <= 1000) {
        tokens.push_back(number);
    }
}

int StringCalculator::SumNumbers(const std::vector<int>& numbers) const {
    return std::accumulate(numbers.begin(), numbers.end(), 0);
}
