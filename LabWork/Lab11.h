#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Lab11
{
public:
    static void filterSentences(const std::string& inputFileName, const std::string& outputFileName, const std::string& targetWord);

private:
    static bool containsWord(const std::string& sentence, const std::string& targetWord);
};
