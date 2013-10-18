#include "DistanceBetweenVectors.hpp"
#include <stdio.h>

int main(int argc, char* argv[])
{
	const int sizeVector = 2;
	float vector1[sizeVector] = {1, 0};
	float vector2[sizeVector] = {2, 1};
	float distance = DistanceBetweenVectors::CalculateDistance(vector1, vector2, L3, sizeVector);
	printf("%f distance \n", distance);
	return 0;
}