#include "Lab13.h"
#include <iostream>
#include <cmath>

bool Triangle::IsValid() const
{
    if (GetLength().a + GetLength().b > GetLength().c)
    {
        if (GetLength().b + GetLength().c > GetLength().a)
        {
            if (GetLength().a + GetLength().c > GetLength().b)
            {
                return true;
            }
        }
    }

    return false;
}

Vector Triangle::GetAngle() const
{
    return Vector(                                                     //
        CalculateAngle(GetLength().a, GetLength().c, GetLength().b),   //
        CalculateAngle(GetLength().a, GetLength().b, GetLength().c),   //
        CalculateAngle(GetLength().b, GetLength().c, GetLength().a));  //
}

float Triangle::GetPerimeter() const
{
    return GetLength().a + GetLength().b + GetLength().c;
}

float Triangle::GetSquare() const
{
    return sqrtf(GetPerimeter()                        //
                 * (GetPerimeter() - GetLength().a)    //
                 * (GetPerimeter() - GetLength().b)    //
                 * (GetPerimeter() - GetLength().c));  //
}

void Triangle::PrintTriangle() const
{
    if (IsValid())
    {
        std::cout << "Треугольник существует\n";

        std::cout << "Длина сторон треугольника: \n"  //
                  << "A: " << GetLength().a << "\n"   //
                  << "B: " << GetLength().b << "\n"   //
                  << "C: " << GetLength().c << "\n";  //

        std::cout << "Углы треугольника: \n"         //
                  << "a: " << GetAngle().a << "\n"   //
                  << "b: " << GetAngle().b << "\n"   //
                  << "c: " << GetAngle().c << "\n";  //

        std::cout << "Периметр треугольника: " << GetPerimeter() << "\n";
        std::cout << "Площадь треугольника: " << GetSquare() << "\n";
    }
    else
    {
        std::cout << "Треугольник не существует\n";
    }
}

float Triangle::CalculateAngle(float a, float b, float c)
{
    return (powf(a, 2) + powf(b, 2) - powf(c, 2)) / (2 * a * b);
}

bool EquipotentialTriangle::IsValid() const
{
    if (GetLength().a + GetLength().b > GetLength().c)
    {
        if (GetLength().b + GetLength().c > GetLength().a)
        {
            if (GetLength().a + GetLength().c > GetLength().b)
            {
                if (GetLength().a == GetLength().b      //
                    && GetLength().a == GetLength().c   //
                    && GetLength().b == GetLength().c)  //
                {
                    return true;
                }
            }
        }
    }

    return false;
}
