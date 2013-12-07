/* Copyright 2013 Pavel Korotaev */
#include "library/WeightConvertor.h"

#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <string>

WeightConvertor::WeightConvertor(void) {}
WeightConvertor::~WeightConvertor(void) {}

void CheckRange(double result);
void CheckRange(double result) {
    if (result > DBL_MAX)
        throw std::string("The result is larger than DBL_MAX");
    else if (result < -DBL_MAX)
        throw std::string("The result is less than -DBL_MAX");
}

Weight WeightConvertor::ConvertTo(Weight weight, WeightUnit UnitOutput) {
    double multiplierKilogram[7] = {0.0283495231, 0.45359237, 6.35029318,
                                    0.001, 1, 100, 1000};
    if (weight.value >= 0) {
        weight.value = multiplierKilogram[weight.unit]/
             multiplierKilogram[UnitOutput]*weight.value;
        CheckRange(weight.value);
    } else {
        weight.value = -1;
    }
    return static_cast<Weight>(weight);
}
