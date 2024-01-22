#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

struct Dance
{
    std::string style_of_dance;
    std::string county;
    int year;
};

class Lab9
{
public:
    static void task1();

private:
    static void printDances(const std::vector<Dance>& V);
    static void printDances(const std::vector<Dance>& V, std::string C);
    static void printDances(const std::vector<Dance>& V, bool Up);
};
