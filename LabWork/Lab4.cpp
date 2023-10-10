#include "Lab4.h"
#include <vector>
#include <algorithm>

// 1 task //
constexpr static int ArrayLen1 = 25;

constexpr static float LO = -100.0f;
constexpr static float HI = 100.0f;

// 2 task //
constexpr static int ArrayLen2 = 35;

void Lab4::task1()
{
	float temp[ArrayLen1];
	int count = 0;

	for (size_t i = 0; i < ArrayLen1; i++)
	{
		temp[i] = ((float(rand()) / float(RAND_MAX)) * (HI - LO)) + LO;

	}

	for (size_t i = 0; i < ArrayLen1; i++)
	{
		if (temp[i] < 0.0f)
		{
			count++;
		}
	}

	for (size_t i = 0; i < ArrayLen1; i++)
	{
		if (i % 2 == 1)
		{
			temp[i] = count;
		}
	}

	for (size_t i = 0; i < 25; i++)
	{
		std::cout << "Lab 4: Task 1: Result: " << temp[i] << std::endl;
	}
}

std::vector<int> Lab4::task2()
{
	int temp[ArrayLen2];
	std::vector<int> result;

	int count = 0;

	for (size_t i = 0; i < ArrayLen2; i++)
	{
		temp[i] = std::rand() % 100;
	}

	for (size_t i = 0; i < ArrayLen2; i++)
	{
		if (temp[5] < temp[i])
		{
			result.push_back(temp[i]);
		}
	}

	return result;
}

std::vector<int> Lab4::task3()
{
	std::vector<int> Temp;

	for (size_t i = 0; i < ArrayLen1; i++)
	{
		Temp.push_back(std::rand() % 100);
	}

	for (auto item : Temp)
	{
		std::cout << "Lab 4: Task 2: Unsorted:" << item << std::endl;
	}

	std::sort(begin(Temp), end(Temp));

	return Temp;
}
