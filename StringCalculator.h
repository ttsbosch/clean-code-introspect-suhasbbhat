#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>
#include <vector>

class StringCalculator {
public:
    int Add(const std::string& input);

private:
    std::vector<int> Tokenize(const std::string& input);
    void ProcessToken(std::string& token, std::vector<int>& tokens);
    void ReplaceNewlinesWithCommas(std::string& token);
    void ProcessNumber(const std::string& number, std::vector<int>& tokens);
    int SumNumbers(const std::vector<int>& numbers) const;
    void ValidateNumber(int number) const;
};

#endif // STRINGCALCULATOR_H
