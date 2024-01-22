#include "Lab9.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

void Lab9::task1()
{
    std::vector<Dance> dances = {
        {"���-���", "���", 1970},       //
        {"������", "����", 1920},       //
        {"��������", "�������", 1774},  //
        {"������", "�������", 1661},    //
        {"�����", "���������", 1880},   //
        {"���������", "���", 1970},     //
        {"�����", "�������", 1750},     //
        {"��-��-��", "����", 1948},     //
        {"���-�����", "���", 1907},     //
        {"������", "���", 1980}         //
    };                                  //

    std::cout << "���������� � ������: ";
    printDances(dances);

    std::cout << "���������� � ������, ����������� � ���: ";
    printDances(dances, std::string("���"));

    std::cout << "���������� � ������, ��������������� �� ���� ������������� � ������� ��������: ";
    printDances(dances, false);
}

void Lab9::printDances(const std::vector<Dance>& V)
{
    std::cout << std::fixed
              << " \n"
                 "|   �����     |    ������    |    ���      |\n";
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
