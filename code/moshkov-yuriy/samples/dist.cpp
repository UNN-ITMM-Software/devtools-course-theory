#include "DistanceBetweenVectors.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	const int sizeVector = 2;
	float vector1[sizeVector] = {1, 0};
	float vector2[sizeVector] = {2, 1};
	float distance = DistanceBetweenVectors::CalculateDistance(vector1, vector2, L1, sizeVector);
	printf("%f distance between source vectors in L1 \n", distance);
	distance = DistanceBetweenVectors::CalculateDistance(vector1, vector2, L4, sizeVector);
	printf("%f distance between source vectors in L4 \n", distance);
	distance = DistanceBetweenVectors::CalculateDistance(vector1, vector2, LInfinity, sizeVector);
	printf("%f distance between source vectors in LInfinity \n", distance);
	return 0;
}