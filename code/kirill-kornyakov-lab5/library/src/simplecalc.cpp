// Copyright 2013 Kirill Kornyakov

#include "library/simplecalc.h"

#include <stdint.h>
#include <limits.h>
#include <string>

SimpleCalculator::SimpleCalculator() {}
SimpleCalculator::~SimpleCalculator() {}

void CheckRange(int64_t result);
void CheckRange(int64_t result) {
    if (result > INT_MAX)
        throw std::string("The result is larger than INT_MAX");
    else if (result < -INT_MAX)
        throw std::string("The result is less than -INT_MAX");
}

int SimpleCalculator::Add(int a, int b) {
    int64_t sum = static_cast<int64_t>(a) + static_cast<int64_t>(b);

    CheckRange(sum);

    return static_cast<int>(sum);
}

int SimpleCalculator::Sub(int a, int b) {
    int64_t diff = static_cast<int64_t>(a) - static_cast<int64_t>(b);

    CheckRange(diff);

    return static_cast<int>(diff);
}
