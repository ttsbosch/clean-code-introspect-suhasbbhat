#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int Add(const std::string& input);

private:
    std::vector<int> Tokenize(const std::string& input);
    int SumNumbers(const std::vector<int>& numbers) const;
    void ValidateNumber(int number) const;
};

#endif // STRINGCALCULATOR_H
