/* Copyright 2013 Vasiliy Kumaev */
#include "library/CurrencyConvert.h"

#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <string>

CurrencyConvert::CurrencyConvert(void) {}

CurrencyConvert::~CurrencyConvert(void) {}

void CheckRange(double result);
void CheckRange(double result) {
    if (result > DBL_MAX)
        throw std::string("The result is larger than DBL_MAX");
    else if (result < -DBL_MAX)
        throw std::string("The result is less than -DBL_MAX");
}

Currency CurrencyConvert::Convert(Currency currency, Unit UnitOutput) {
    double multiplierToDollar[4] = {1, 0.74, 0.03, 1.59};
    if (currency.value >= 0) {
        currency.value = multiplierToDollar[currency.unit]*
                         currency.value/multiplierToDollar[UnitOutput];
        currency.unit = UnitOutput;
        CheckRange(currency.value);
    } else {
        currency.value = -1;
    }
    return static_cast<Currency>(currency);
}
