#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int Add(std::string numbers);

private:
    std::string ExtractDelimiter(std::string& numbers);
    int SumNumbers(const std::string& numbers, const std::string& delimiter);
    std::vector<std::string> Tokenize(const std::string& input, const std::string& delimiter);
};

#endif // STRINGCALCULATOR_H
