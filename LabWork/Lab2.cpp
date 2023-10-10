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
		return "����������";
	case 2:
		return "��������";
	case 3:
		return "��������";
	case 4:
		return "������";
	case 5:
		return "�������";
	case 6:
		return "�����";
	case 7:
		return "���-���";
	case 8:
		return "�����";
	case 9:
		return "����";
	case 10:
		return "����";
	default:
		return "Not Found!";
	}
}
