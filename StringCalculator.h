#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>
#include <utility>

class StringCalculator {
public:
    int add(const std::string& input);
    std::pair<std::string, std::string> ExtractDelimiter(const std::string& numbers);
    std::string ReplaceNewlineWithComma(const std::string& input);
    std::vector<int> Tokenize(const std::string& input, const std::string& delimiter);
    int SumNumbers(const std::vector<int>& numbers);

private:
    std::vector<int> FilterNumbers(const std::vector<int>& numbers);
};

#endif // STRINGCALCULATOR_H
