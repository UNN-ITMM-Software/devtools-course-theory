#include "DistanceBetweenVectors.hpp"
#include <stdio.h>

int main(int argc, char* argv[])
{
	float vector1[2] = {1, 0};
	float vector2[2] = {2, 1};
	float distance = DistanceBetweenVectors::CalculateDistance(vector1, vector2, L2, 2);
	printf("%f distance \n", distance);
	return 0;
}