#include "Lab2.h"
#include "math.h"

float Lab2::task1(float a, float b, float x)
{
	if (a < b && x > 0.0f)
	{
		return a * cosf(x);
	}
	else if (a > x && x <= 0.0f)
	{
		return 1.0f / (a + b);
	}
	return 0;
}

std::string Lab2::task2(int value)
{
	switch (value)
	{
	case 1:
		return "Бультерьер";
	case 2:
		return "Далматин";
	case 3:
		return "Доберман";
	case 4:
		return "Мастив";
	case 5:
		return "Овчарка";
	case 6:
		return "Корги";
	case 7:
		return "Чау-Чау";
	case 8:
		return "Колли";
	case 9:
		return "Мопс";
	case 10:
		return "Шпиц";
	default:
		return "Not Found!";
	}
}
