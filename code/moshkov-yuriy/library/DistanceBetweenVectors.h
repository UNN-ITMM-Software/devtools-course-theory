/* Copyright 2013 Moshkov Yuriy */
#ifndef CODE_MOSHKOV_YURIY_LIBRARY_DISTANCEBETWEENVECTORS_H_
#define CODE_MOSHKOV_YURIY_LIBRARY_DISTANCEBETWEENVECTORS_H_
#include <math.h>

enum TypeMetric {L1 = 1, L2, L3, L4, LInfinity};

class DistanceBetweenVectors {
public:
    static float CalculateDistance(float *vector1, float *vector2,
                                   TypeMetric typeMetric, int sizeVector);
};

#endif  // CODE_MOSHKOV_YURIY_LIBRARY_DISTANCEBETWEENVECTORS_H_
