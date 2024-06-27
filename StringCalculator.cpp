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
    std::vector<int> tokens;
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, ',')) {
        ProcessToken(token, tokens);
    }

    return tokens;
}

void StringCalculator::ProcessToken(std::string& token, std::vector<int>& tokens) {
    ReplaceNewlinesWithCommas(token);
    std::istringstream tokenStream(token);
    std::string number;
    while (std::getline(tokenStream, number, ',')) {
        ProcessNumber(number, tokens);
    }
}

void StringCalculator::ReplaceNewlinesWithCommas(std::string& token) {
    std::replace(token.begin(), token.end(), '\n', ',');
}

void StringCalculator::ProcessNumber(const std::string& number, std::vector<int>& tokens) {
    int num = std::stoi(number);
    ValidateNumber(num);
    if (num <= 1000) tokens.push_back(num);
}

int StringCalculator::SumNumbers(const std::vector<int>& numbers) const {
    return std::accumulate(numbers.begin(), numbers.end(), 0);
}

void StringCalculator::ValidateNumber(int number) const {
    if (number < 0) {
        throw std::runtime_error("Negatives not allowed");
    }
}
