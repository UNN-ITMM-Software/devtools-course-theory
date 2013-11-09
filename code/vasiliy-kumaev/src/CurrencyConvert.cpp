/* Copyright 2013 Vasiliy Kumaev */
#include <CurrencyConvert.h>

CurrencyConvert::CurrencyConvert(void) {}

CurrencyConvert::~CurrencyConvert(void) {}

Currency CurrencyConvert::Convert(Currency currency) {
    double multiplierToDollar[4] = {1, 0.74, 0.03, 1.59};
    if (currency.value >= 0)
        currency.value = multiplierToDollar[currency.oldunit]*
                         currency.value/multiplierToDollar[currency.newunit];
    else
        currency.value = -1;
    return currency;
}
