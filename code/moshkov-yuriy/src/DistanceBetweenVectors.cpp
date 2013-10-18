#include "DistanceBetweenVectors.hpp"


float DistanceBetweenVectors::CalculateDistance(float *vector1, float *vector2, TypeMetric typeMetric, int sizeVector = 0)
{
	float distance;
	if (typeMetric == LInfinity)
	{

	}
	else
	{
		float sumComp = 0;
		for (int i = 0; i < sizeVector; i++)
		{
			sumComp += powf(vector1[i] - vector2[i], 1.0f * typeMetric);
		}
		distance = powf(sumComp, 1.0f / typeMetric);
	}
	return distance;
}