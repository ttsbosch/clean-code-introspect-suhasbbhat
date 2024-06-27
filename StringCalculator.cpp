#include "StringCalculator.h"
#include <sstream>
#include <algorithm>

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;
    }

    // Refactored to avoid structured bindings
    auto delimiterAndNumbers = ExtractDelimiter(input);
    std::string delimiter = delimiterAndNumbers.first;
    std::string numbers = delimiterAndNumbers.second;

    std::string modifiedNumbers = ReplaceNewlineWithComma(numbers);
    std::vector<int> tokens = Tokenize(modifiedNumbers, delimiter);
    std::vector<int> filteredTokens = FilterNumbers(tokens); // Ensure this is correctly called
    return SumNumbers(filteredTokens);
}

// Ensure other methods are implemented as previously described

std::vector<int> StringCalculator::FilterNumbers(const std::vector<int>& numbers) {
    std::vector<int> filteredNumbers;
    for (int num : numbers) {
        if (num <= 1000) {
            filteredNumbers.push_back(num);
        }
    }
    return filteredNumbers;
}
