#include "Lab7.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

constexpr static int RowLenght = 8;
constexpr static int ColumnLenght = 8;

void Lab7::task1()
{
    std::vector<std::vector<int>> Array(ColumnLenght, std::vector<int>(RowLenght));

    for (size_t i = 0; i < ColumnLenght; i++)
    {
        for (size_t j = 0; j < RowLenght; j++)
        {
            Array[i][j] = rand() % 101;
        }
    }

    std::cout << "\nLab 7: Task 1: Array: " << std::endl;

    for (auto ArrayElem : Array)
    {
        for (auto item : ArrayElem)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    int n;
    std::cout << "\Input column for delete: " << std::endl;
    std::cin >> n;

    Array.erase(Array.begin() + n - 1);

    std::cout << "\nLab 7: Task 1: Result Array: " << std::endl;
    for (auto ArrayElem : Array)
    {
        for (auto item : ArrayElem)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}
