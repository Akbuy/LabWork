#include "Lab8.h"

#include <iostream>
#include <cmath>

constexpr float PI = 3.14;
constexpr int ArrayLenght1 = 15;
constexpr int ArrayLenght2 = 22;

float Lab8::task1()
{
    float First = Lab8::ArithmeticMeanValue(-2.0f, 2.0f, 0.7f, false) - Lab8::ArithmeticMeanValue(-2.0f, 2.0f, 0.7f, true);
    float Second = Lab8::ArithmeticMeanValue(5.0f, 10.0f, 0.3f, false) - Lab8::ArithmeticMeanValue(5.0f, 10.0f, 0.3f, true);
    float Third = Lab8::ArithmeticMeanValue(-PI, 2.0f * PI, 0.4f, false) - Lab8::ArithmeticMeanValue(-PI, 2.0f * PI, 0.4f, true);
    float Fourth = Lab8::ArithmeticMeanValue(-1.0f, 5.0f, 0.3f, false) - Lab8::ArithmeticMeanValue(-1.0f, 5.0f, 0.3f, true);

    float MinOne = Lab8::MinValue(First, Second);
    float MinTwo = Lab8::MinValue(Third, Fourth);

    return Lab8::MinValue(MinOne, MinTwo);
}

void Lab8::task2()
{
    int U1[ArrayLenght1];
    for (size_t i = 0; i < ArrayLenght1; i++)
    {
        U1[i] = rand() % 100;
    }

    int U2[ArrayLenght2];
    for (size_t i = 0; i < ArrayLenght2; i++)
    {
        U2[i] = rand() % 100;
    }

    std::cout << "\nLab 8: Task 2: Result Min Element: " << GetMin(U1, ArrayLenght1) << std::endl;
    std::cout << "Lab 8: Task 2: Result Max Element: " << GetMax(U2, ArrayLenght2) << std::endl;
}

float Lab8::ArithmeticMeanValue(float min, float max, float step, bool isNegative)
{
    float Temp = 0;
    int count = 0;

    for (float i = min; i < max; i += step)
    {
        float f = 3 * sinf(5 * i) - 2.5 * cosf(2 * i);
        if (isNegative ? f < 0.0f : f > 0.0f)
        {
            count++;
            Temp += f;
        }
    }
    return Temp;
}

float Lab8::MinValue(float A, float B)
{
    if (A > B) return B;
    return A;
}

int Lab8::GetMin(int* Array, int Lenght)
{
    int Temp = INT_MAX;
    for (size_t i = 0; i < Lenght; i++)
    {
        if (Array[i] < Temp) Temp = Array[i];
    }
    return Temp;
}

int Lab8::GetMax(int* Array, int Lenght)
{
    int Temp = INT_MIN;
    for (size_t i = 0; i < Lenght; i++)
    {
        if (Array[i] > Temp) Temp = Array[i];
    }
    return Temp;
}
