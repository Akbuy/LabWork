#include "Lab11.h"

void Lab11::filterSentences(const std::string& inputFileName, const std::string& outputFileName, const std::string& targetWord)
{
    {
        std::ifstream inputFile(inputFileName);
        std::ofstream outputFile(outputFileName);

        if (!inputFile.is_open())
        {
            std::cout << "Ошибка открытия файла: " << inputFileName << "\n";
            return;
        }

        if (!outputFile.is_open())
        {
            std::cout << "Ошибка открытия файла: " << outputFileName << "\n";
            return;
        }

        std::string line;
        while (getline(inputFile, line))
        {
            std::istringstream sentenceStream(line);
            std::string sentence;
            while (getline(sentenceStream, sentence, '.'))
            {
                if (containsWord(sentence, targetWord))
                {
                    outputFile << sentence << '.' << "\n";
                }
            }
        }

        std::cout << "Файл успешно создан. Предложения с заданным словом записаны в: " << outputFileName << "\n";

        inputFile.close();
        outputFile.close();
    }
}

bool Lab11::containsWord(const std::string& sentence, const std::string& targetWord)
{
    std::istringstream iss(sentence);
    std::string word;
    while (iss >> word)
    {
        if (word == targetWord)
        {
            return true;
        }
    }
    return false;
}
