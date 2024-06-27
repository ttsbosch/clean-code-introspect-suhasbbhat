#include "StringCalculator.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <vector>

int StringCalculator::Add(std::string numbers) { // Make a copy for modification
    if (numbers.empty()) {
        return 0;
    }

    std::string delimiter = ",";
    if (numbers.substr(0, 2) == "//") {
        size_t delimiterStart = numbers.find("//") + 2;
        size_t delimiterEnd = numbers.find("\n");
        delimiter = numbers.substr(delimiterStart, delimiterEnd - delimiterStart);
        numbers.erase(0, delimiterEnd + 1);
    }

    // Replace newlines with a comma, assuming delimiter processing can handle it
    std::replace(numbers.begin(), numbers.end(), '\n', ',');

    std::vector<std::string> tokens = Tokenize(numbers, delimiter);
    int sum = 0;
    for (const auto& token : tokens) {
        int num = std::stoi(token);
        if (num <= 1000) {
            sum += num;
        }
    }

    // Assuming negative number validation is desired at the end
    // ValidateNegatives(parsedNumbers); // This requires collecting parsedNumbers

    return sum;
}
