/* Copyright 2013 Moshkov Yuriy */
#include "library/DistanceBetweenVectors.h"

#include <float.h>
#include <string>

void CheckRange(float result) {
    if (result != 0.0) {
        if (result > FLT_MAX)
            throw std::string("The result is larger than FLT_MAX");
        else if (result < -FLT_MAX)
            throw std::string("The result is less than -FLT_MAX");
        else if (result < FLT_MIN && result > 0.0)
            throw std::string("The result is less than FLT_MIN and larger 0");
        else if (result > -FLT_MIN && result < 0.0)
            throw std::string("The result is larger than -FLT_MIN and less 0");
    }
}

float DistanceBetweenVectors::CalculateDistance(float *vector1, float *vector2,
                                       TypeMetric typeMetric, int sizeVector) {
    float distance;
    if (typeMetric == LInfinity) {
        float max = 0;
        for (int i = 0; i < sizeVector; i++)
            if (max < fabs(vector1[i] - vector2[i]))
                max = fabs(vector1[i] - vector2[i]);
        distance = max;
    } else {
        float sumComp = 0;
        for (int i = 0; i < sizeVector; i++)
            sumComp += powf(fabs(vector1[i] - vector2[i]), 1.0f * typeMetric);
        distance = powf(sumComp, 1.0f / typeMetric);
    }
    CheckRange(distance);
    return static_cast<float>(distance);
}
