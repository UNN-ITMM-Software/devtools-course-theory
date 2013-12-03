/* Copyright 2013 Dmitry Vodopyanov */
#include "library/LengthConvertor.h"

#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <string>

LengthConvertor::LengthConvertor(void) {}
LengthConvertor::~LengthConvertor(void) {}

void CheckRange(double result);
void CheckRange(double result) {
    if (result > DBL_MAX)
        throw std::string("The result is larger than DBL_MAX");
    else if (result < -DBL_MAX)
        throw std::string("The result is less than -DBL_MAX");
}

Length LengthConvertor::Convert(Length length, LengthUnit UnitOutput) {
    double multiplierMeter[7] = {0.0253999998, 0.3048, 0.914399999,
                                 1609.34401, 1, 1000, 0.01};
    CheckRange(length.value);
    if (length.value >= 0) {
        length.value = multiplierMeter[length.UnitInput]/
                       multiplierMeter[UnitOutput]*length.value;
        length.UnitInput = UnitOutput;
    } else {
        length.value = -1;
    }
    return static_cast<Length>(length);
}
