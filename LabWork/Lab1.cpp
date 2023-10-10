#include "Lab1.h"
#include "math.h"

float Lab1::task1(float a, float b)
{
	return powf(a + b, 2.0f) + (a * sqrtf(b)) / (1.0f - powf(sinf(powf(b, 3.0f)), 3.0f));
}

float Lab1::task2_tetrahedron(float x)
{
	return powf(x, 2.0f) * sqrtf(3.0f);
}

float Lab1::task2_hexahedron(float x)
{
	return 6.0f * powf(x, 2.0f);
}

float Lab1::task2_octahedron(float x)
{
	return 2.0f * powf(x, 2.0f) * sqrtf(3.0f);
}
