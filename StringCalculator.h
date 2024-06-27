#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int Add(const std::string& numbers);

private:
    std::vector<std::string> Tokenize(const std::string& input, const std::string& delimiters);
    void ValidateNegatives(const std::vector<int>& numbers);
};

#endif // STRINGCALCULATOR_H
