#include "Lab3.h"
#include "math.h"

float Lab3::task1()
{
	float TempA = 0,
		TempB = 0;

	for (size_t i = 5; i <= 10; i++)
	{
		TempA += powf(i, 2.0f);
	}
	for (size_t i = 3; i <= 10; i++)
	{
		TempB *= powf(i, 2.0f) + 2.0f;
	}
	return TempA - TempB;
}

float Lab3::task2(float min, float max, float step)
{
	float Temp = 0,
		x = min;
	size_t count = 0;

	for (float i = min; i <= max; i += step)
	{
		Temp += 2 * cosf(x - 1);
		x += step;
		count++;
	}

	return Temp / count;
}
