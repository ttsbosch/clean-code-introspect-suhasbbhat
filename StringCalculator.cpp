#include "StringCalculator.h"

int StringCalculator::add(const std::string& input) {
    // If input is empty, return 0
    if (input.empty()) {
        return 0;
    }

    // Convert input string to stringstream for easier extraction
    std::stringstream ss(input);
    int number;
    int sum = 0;

    // Iterate through comma-separated values in the input string
    while (ss >> number) {
        sum += number;
        // Check for comma and skip it
        if (ss.peek() == ',') {
            ss.ignore();
        }
    }
