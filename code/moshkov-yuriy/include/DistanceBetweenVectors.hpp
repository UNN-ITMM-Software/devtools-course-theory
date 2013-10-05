enum VectorSize{L1, L2, L3, L4, LInfinity};

class DistanseBetweenVectors
{
public:
	static float CalculateDistance(float *vector1, float *vector2, VectorSize vectorSize, int sizeVector = 0);
};