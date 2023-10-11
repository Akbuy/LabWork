#include "Lab6.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void Lab6::task1()
{
    std::string InputString;

    std::cout << "\nLab 6: Task 1: Input String: English Alphabet:" << std::endl;
    InputString = Lab6::StringValid(InputString);

    std::string Alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (auto InputItem : InputString)
    {
        for (auto AlphabetItem : Alphabet)
        {
            if (InputItem == AlphabetItem)
            {
                Alphabet.erase(Alphabet.find(InputItem), 1);
            }
        }
    }

    std::cout << "Lab 6: Task 1: Result: " << Alphabet << std::endl;
}

void Lab6::task2()
{
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "Lab 6: Task 2: Iteration: " << i + 1 << " Input Value:" << std::endl;

        std::string InputString;

        std::cin >> InputString;

        if (check_number(InputString))
        {
            std::cout << "Lab 6: Task 2: Result: Is Numeric" << std::endl;
        }
        else
        {
            std::cout << "Lab 6: Task 2: Result: Is Not Numeric" << std::endl;
        }
    }
}

std::string Lab6::StringValid(std::string Input)
{
    std::getline(std::cin, Input);
    while (std::cin.fail() || std::cin.eof() || Input.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos)
    {

        std::cout << "Not valid value, enter string: " << std::endl;

        if (Input.find_first_not_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos)
        {
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }

        std::getline(std::cin, Input);
    }

    return Input;
}

float Lab6::stringToFloat(std::string Input)
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

    return std::stof(Input);
}

bool Lab6::check_number(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ',' || str[i] == '.')
        {
            continue;
        }
        if (isdigit(str[i]) == false)
        {
            return false;
        }
    }

    return true;
}
