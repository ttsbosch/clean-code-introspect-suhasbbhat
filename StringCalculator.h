#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int Add(const std::string& input);

private:
    std::vector<int> Tokenize(const std::string& input);
    char DetectAndProcessCustomDelimiter(std::string& input);
    std::vector<int> SplitAndConvertToNumbers(const std::string& input, char delimiter);
    void ReplaceNewlinesWithCommas(std::string& token);
    void ValidateAndAddNumber(int number, std::vector<int>& tokens);
    int SumNumbers(const std::vector<int>& numbers) const;
};

#endif // STRINGCALCULATOR_H
