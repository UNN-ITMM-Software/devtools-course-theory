/* Copyright 2013 Dmitry Vodopyanov */
#include <LengthConvertor.h>

LengthConvertor::LengthConvertor(void) {}

LengthConvertor::~LengthConvertor(void) {}

Length LengthConvertor::Convert(Length length, LengthUnit UnitOutput) {
    double multiplierMeter[7] = {0.0253999998, 0.3048, 0.914399999,
                                 1609.34401, 1, 1000, 0.01};
    if (length.value >= 0) {
        length.value = multiplierMeter[length.UnitInput]/
                       multiplierMeter[UnitOutput]*length.value;
        length.UnitInput = UnitOutput;
    } else {
        length.value = -1;
    }
    return length;
}
