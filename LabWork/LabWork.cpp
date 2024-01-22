// LabWork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Variant 22

#include <iostream>
#include <vector>
#include <windows.h>
#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"
#include "Lab4.h"
#include "Lab5.h"
#include "Lab6.h"
#include "Lab7.h"
#include "Lab8.h"
#include "Lab9.h"
#include "Lab10.h"
#include "Lab11.h"
#include "Lab13.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Лабораторная работа #9" << std::endl;

    Lab9::task1();

    std::cout << "Лабораторная работа #10" << std::endl;

    BookLibrary library = BookLibrary();

    library.root = BookLibrary::insertBook(library.root, new TreeNode(Book(1, "Толстой Л.Н.", "Война и мир", 1868, 16)));
    library.root = BookLibrary::insertBook(library.root, new TreeNode(Book(2, "Климов Г.П.", "Князь мира сего", 1970, 32)));
    library.root = BookLibrary::insertBook(library.root, new TreeNode(Book(3, "Лукьяненко С.В.", "Ночной Дозор", 1998, 48)));

    std::cout << "Информация о книгах в библиотеке: "
              << "\n";
    BookLibrary::printBooks(library.root);

    library.root = BookLibrary::insertBook(library.root, new TreeNode(Book(4, "Диккер Ж.", "Дело Аляски Сандерс", 2023, 64)));
    library.root = BookLibrary::insertBook(library.root, new TreeNode(Book(5, "Карризи Д.", "Дом огней", 2022, 86)));

    std::cout << "\nИнформация о книгах после добавления новых данных:"
              << "\n";
    BookLibrary::printBooks(library.root);

    auto bookToBeDeleted = new TreeNode(Book(3, "Лукьяненко С.В.", "Ночной Дозор", 1998, 48));

    library.root = BookLibrary::deleteBooks(library.root, bookToBeDeleted);

    std::cout << "\nИнформация о книгах после удаления книги: " << bookToBeDeleted->val.title << ", " << bookToBeDeleted->val.author << ": "
              << "\n";
    BookLibrary::printBooks(library.root);

    std::cout << "Лабораторная работа #11" << std::endl;

    std::string targetWord;

    std::cout << "Введите слово для поиска в предложениях: \n";
    std::cin >> targetWord;

    Lab11::filterSentences("input.txt", "output.txt", targetWord);

    std::cout << "Лабораторная работа #12" << std::endl;

    const int K = 5;
    const int L = 7;

    Triangle KArray[K];
    EquipotentialTriangle LArray[L];

    for (size_t i = 0; i < K; i++)
    {
        KArray[i] = Triangle();
        KArray[i].SetLength(Vector(rand() % 10, rand() % 10, rand() % 10));
        std::cout << "Треугольник K #" << i << "\n";
        KArray[i].PrintTriangle();
    }

    float TotalSquare = 0;
    for (size_t i = 0; i < K; i++)
    {
        if (KArray[i].IsValid())
        {
            TotalSquare += KArray[i].GetSquare();
        }
    }
    TotalSquare = TotalSquare / 5;

    std::cout << "Средняя площадь для K треугольников: " << TotalSquare;

    for (size_t i = 0; i < L; i++)
    {
        LArray[i] = EquipotentialTriangle();
        float temp = rand() % 10;
        LArray[i].SetLength(Vector(temp, temp, temp));
        std::cout << "Треугольник L #" << i;
        LArray[i].PrintTriangle();
    }
    EquipotentialTriangle Temp = LArray[0];

    for (size_t i = 1; i < L; i++)
    {
        if (LArray[i].IsValid())
        {
            if (LArray[i].GetSquare() > Temp.GetSquare())
            {
                Temp = LArray[i];
            }
        }
    }
    std::cout << "Наибольший равносторонний треугольник L: \n";

    Temp.PrintTriangle();
}
/*
void FirstTerm()
{
    float a, b, x;

    std::cout << "Первая лабораторная работа" << std::endl;

    std::cout << "Lab 1: Task 1: Input a value: " << std::endl;
    std::cin >> a;

    std::cout << "Lab 1: Task 1: Result: " << Lab1::task1(a, 12.0f) << std::endl;

    std::cout << "Lab 1: Task 2: Tetrahedron: Result: " << Lab1::task2_tetrahedron(5.12f) << std::endl;
    std::cout << "Lab 1: Task 2: Hexahedron: Result: " << Lab1::task2_hexahedron(5.12f) << std::endl;
    std::cout << "Lab 1: Task 2: Octahedron: Result: " << Lab1::task2_octahedron(5.12f) << std::endl;

    std::cout << "Вторая лабораторная работа" << std::endl;

    std::cout << "Lab 2: Task 1: Input a value: " << std::endl;
    std::cin >> a;
    std::cout << "Lab 2: Task 1: Input b value: " << std::endl;
    std::cin >> b;
    std::cout << "Lab 2: Task 1: Input x value: " << std::endl;
    std::cin >> x;
    std::cout << "Lab 2: Task 1: Result: " << Lab2::task1(a, b, x) << std::endl;
    std::cout << "Lab 2: Task 2: Input value: " << std::endl;
    std::cin >> a;

    std::cout << "Lab 2: Task 2: Result: " << Lab2::task2(a) << std::endl;

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

    std::cout << Lab5::task1();

    Lab5::task2();

    Lab5::task3();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    std::cout << "\nШестая лабораторная работа" << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    Lab6::task1();

    Lab6::task2();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "\nСедьмая лабораторная работа" << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    Lab7::task1();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    std::cout << "\nВосьмая лабораторная работа" << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    std::cout << "Lab 8: Task 1: Result: " << Lab8::task1();

    Lab8::task2();
}
*/