#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>
#include <utility> // For std::pair

class StringCalculator {
public:
    int add(const std::string& input); // Ensure method names are consistent
    std::pair<std::string, std::string> ExtractDelimiter(const std::string& numbers);
    std::string ReplaceNewlineWithComma(const std::string& input);

private:
    int SumNumbers(const std::vector<int>& numbers);
    std::vector<int> Tokenize(const std::string& input, const std::string& delimiter);
    std::vector<int> FilterNumbers(const std::vector<int>& numbers); // Ensure this is declared
};

#endif // STRINGCALCULATOR_H
