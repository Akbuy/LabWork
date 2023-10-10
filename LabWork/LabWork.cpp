// LabWork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <windows.h>
#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"
#include "Lab4.h"
#include "Lab5.h"
#include "Lab6.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    float a, b, x;

    // std::cout << "Первая лабораторная работа" << std::endl;
    //
    // std::cout << "Lab 1: Task 1: Input a value: " << std::endl;
    // std::cin >> a;
    //
    // std::cout << "Lab 1: Task 1: Result: " << Lab1::task1(a, 12.0f) << std::endl;
    //
    // std::cout << "Lab 1: Task 2: Tetrahedron: Result: " << Lab1::task2_tetrahedron(5.12f) << std::endl;
    // std::cout << "Lab 1: Task 2: Hexahedron: Result: " << Lab1::task2_hexahedron(5.12f) << std::endl;
    // std::cout << "Lab 1: Task 2: Octahedron: Result: " << Lab1::task2_octahedron(5.12f) << std::endl;
    //
    // std::cout << "Вторая лабораторная работа" << std::endl;
    //
    // std::cout << "Lab 2: Task 1: Input a value: " << std::endl;
    // std::cin >> a;
    // std::cout << "Lab 2: Task 1: Input b value: " << std::endl;
    // std::cin >> b;
    // std::cout << "Lab 2: Task 1: Input x value: " << std::endl;
    // std::cin >> x;
    // std::cout << "Lab 2: Task 1: Result: " << Lab2::task1(a, b, x) << std::endl;
    // std::cout << "Lab 2: Task 2: Input value: " << std::endl;
    // std::cin >> a;
    //
    // std::cout << "Lab 2: Task 2: Result: " << Lab2::task2(a) << std::endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    std::cout << "\nТретья лабораторная работа \n" << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    std::cout << "Lab 3: Task 1: Result: " << Lab3::task1() << std::endl;
    std::cout << "Lab 3: Task 2: Result: " << Lab3::task2(-5.0f, 5.0f, 0.25f) << std::endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << "\nЧетвертая лабораторная работа \n" << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    Lab4::task1();

    auto res41 = Lab4::task2();

    for (auto item : res41)
    {
        std::cout << "Lab 4: Task 2: Result: " << item << std::endl;
    }

    auto res43 = Lab4::task3();

    for (auto item : res43)
    {
        std::cout << "Lab 4: Task 3: Result: " << item << std::endl;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    std::cout << "\nПятая лабораторная работа" << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    Lab5::task2();

    Lab5::task3();

    Lab6::task1();

    Lab6::task2();
}
