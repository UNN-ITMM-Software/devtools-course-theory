/* Copyright 2013 Pavel Korotaev */
#include "library/WeightConvertor.h"

#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <string>

WeightConvertor::WeightConvertor(void) {}
WeightConvertor::~WeightConvertor(void) {}

Weight WeightConvertor::ConvertTo(Weight weight, WeightUnit UnitOutput) {
    double multiplierKilogram[7] = {0.0283495231, 0.45359237, 6.35029318,
                                    0.001, 1, 100, 1000};
    if (weight.value >= 0) {
        weight.value = multiplierKilogram[weight.unit]/
             multiplierKilogram[UnitOutput]*weight.value;
    } else {
        weight.value = -1;
    }
    return static_cast<Weight>(weight);
}
