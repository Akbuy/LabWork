#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "Lab5.h"
#include "stdlib.h"

constexpr static int ArrayLen = 8;
constexpr static int ArrayLen2 = 7;

int Lab5::task1()
{
    int Array[ArrayLen][ArrayLen];
    int Temp = INT_MIN;

    for (size_t i = 0; i < ArrayLen; i++)
    {
        for (size_t j = 0; j < ArrayLen; j++)
        {
            Array[i][j] = rand() % 100;
        }
    }

    for (size_t i = 0; i < ArrayLen; i++)
    {
        for (size_t j = 0; j < ArrayLen; j++)
        {
            if (i == j)
            {
                if (Temp < Array[i][j])
                {
                    Temp = Array[i][j];
                }
            }
        }
    }

    return Temp;
}

void Lab5::task2()
{
    int Array[ArrayLen2][ArrayLen];

    int Temp = 0;

    for (size_t i = 0; i < ArrayLen2; i++)
    {
        for (size_t j = 0; j < ArrayLen2; j++)
        {
            Array[i][j] = (rand() % 200) - 100;
        }
    }

    std::cout << "\nLab 5: Task 2: Generated Matrix: " << std::endl;

    for (size_t i = 0; i < ArrayLen2; i++)
    {
        for (size_t j = 0; j < ArrayLen2; j++)
        {
            std::cout << Array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (size_t i = 0; i < ArrayLen2; i++)
    {
        for (size_t j = 0; j < ArrayLen; j++)
        {
            if (j == ArrayLen - 1)
            {
                Array[i][j] = Temp;
                continue;
            }
            if (Array[i][j] < 0.0f)
            {
                Temp = Array[i][j];
            }
        }
    }
    std::cout << "\nLab 5: Task 2: Result Matrix: " << std::endl;

    for (size_t i = 0; i < ArrayLen2; i++)
    {
        for (size_t j = 0; j < ArrayLen; j++)
        {
            std::cout << Array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nLab 5: Task 2: Result : " << std::endl;

    for (size_t i = 0; i < ArrayLen2; i++)
    {
        std::cout << Array[i][ArrayLen - 1] << '\t';
    }
}

void Lab5::task3()
{
    std::string theInputN, theInputM;
    int inputAsIntN, inputAsIntM;

    std::cout << "\nEnter the number of rows in the range from 1 to 100: \n";

    inputAsIntN = Lab5::stringToInt(theInputN);

    std::cout << "Enter the number of columns in the range from 1 to 50: \n";

    inputAsIntM = Lab5::stringToInt(theInputM);

    std::vector<std::vector<int>> Array(inputAsIntN, std::vector<int>(inputAsIntM));

    for (size_t i = 0; i < inputAsIntN; i++)
    {
        for (size_t j = 0; j < inputAsIntM; j++)
        {
            Array[i][j] = rand() % 100;
        }
    }

    std::cout << "\nLab 5: Task 3: Array: " << std::endl;

    for (auto ArrayElem : Array)
    {
        for (auto item : ArrayElem)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nLab 5: Task 3: Sorted Array: " << std::endl;

    std::sort(Array.begin(), Array.end());

    for (size_t i = 0; i < inputAsIntN; i++)
    {
        std::sort(Array[i].begin(), Array[i].end());
    }

    for (auto ArrayElem : Array)
    {
        for (auto item : ArrayElem)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}

int Lab5::stringToInt(std::string Input)
{
    std::getline(std::cin, Input);
    while (std::cin.fail() || std::cin.eof() || Input.find_first_not_of("0123456789") != std::string::npos)
    {

        std::cout << "Not valid value, enter the number of rows in the range from 1 to 100: " << std::endl;

        if (Input.find_first_not_of("0123456789") == std::string::npos)
        {
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }

        std::getline(std::cin, Input);
    }

    return std::stoi(Input);
}
