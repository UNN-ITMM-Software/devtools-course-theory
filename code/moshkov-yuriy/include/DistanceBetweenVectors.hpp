#include <math.h>


enum TypeMetric{L1 = 1, L2, L3, L4, LInfinity};

class DistanceBetweenVectors
{
public:
	static float CalculateDistance(float *vector1, float *vector2, TypeMetric typeMetric, int sizeVector);
};