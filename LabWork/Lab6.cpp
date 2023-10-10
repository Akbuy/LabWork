#include "Lab6.h"

#include <string>
#include <iostream>

void Lab6::task1()
{
    std::string InputString;

    std::cout << "\nLab 6: Task 1: Input String: English Alphabet:" << std::endl;
    std::cin >> InputString;

    if (std::cin.fail())
    {
        std::cout << "You entered a number. Try again.\n";
        Lab6::task1();
    }

    std::string Alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (auto InputItem : InputString)
    {
        for (auto AlphabetItem : Alphabet)
        {
            if (InputItem == AlphabetItem)
            {
                Alphabet.erase(Alphabet.find(InputItem), Alphabet.find(InputItem));
            }
        }
    }

    std::cout << "Lab 6: Task 1: Result: " << Alphabet << std::endl;
}

void Lab6::task2()
{
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "Lab 6: Task 2: Input Value: " << std::endl;

        std::string InputString;

        std::cin >> InputString;

        if (std::cin.fail())
        {
            std::cout << "You entered a not number. Try again.\n";
            Lab6::task2();
        }

        float Result = std::stof(InputString);

        std::cout << "Lab 6: Task 2: Result: " << Result << std::endl;
    }
}

void Lab6::task3() 
{
    
}

