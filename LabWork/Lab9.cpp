#include "Lab9.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

void Lab9::task1()
{
    std::vector<Dance> dances = {
        {"Хип-хоп", "США", 1970},       //
        {"Сальса", "Куба", 1920},       //
        {"Фламенко", "Испания", 1774},  //
        {"Бальет", "Франция", 1661},    //
        {"Танго", "Аргентина", 1880},   //
        {"Брейкданс", "США", 1970},     //
        {"Вальс", "Австрия", 1750},     //
        {"Ча-ча-ча", "Куба", 1948},     //
        {"Тап-танец", "США", 1907},     //
        {"Трайбл", "США", 1980}         //
    };                                  //

    std::cout << "Информация о танцах: ";
    printDances(dances);

    std::cout << "Информация о танцах, придуманных в США: ";
    printDances(dances, std::string("США"));

    std::cout << "Информация о танцах, отсортированный по году происхождения в порядке убывания: ";
    printDances(dances, false);
}

void Lab9::printDances(const std::vector<Dance>& V)
{
    std::cout << std::fixed
              << " \n"
                 "|   Танец     |    Страна    |    Год      |\n";
    for (auto& item : V)
    {
        std::cout << std::left << "|  " << std::setw(11)      //
                  << item.style_of_dance << "|    "           //
                  << std::setw(9) << item.county << " |    "  //
                  << std::setw(8) << item.year << " |\n"
                  << std::setw(0);
    }
    std::cout << "\n";
}

void Lab9::printDances(const std::vector<Dance>& V, std::string C)
{
    std::vector<Dance> Temp;

    for (auto& item : V)
    {
        if (item.county == C)
        {
            Temp.push_back(item);
        }
    }

    printDances(Temp);
}

void Lab9::printDances(const std::vector<Dance>& V, bool Up)
{
    std::vector<Dance> Temp = V;

    if (Up)
    {
        std::sort(Temp.begin(), Temp.end(), [](const Dance& A, const Dance& B) { return A.year < B.year; });
    }
    else
    {
        std::sort(Temp.begin(), Temp.end(), [](const Dance& A, const Dance& B) { return A.year > B.year; });
    }

    printDances(Temp);
}
