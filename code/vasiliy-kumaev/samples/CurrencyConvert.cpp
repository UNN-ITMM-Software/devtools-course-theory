/* Copyright 2013 Vasiliy Kumaev */
#include <CurrencyConvert.h>
#include <stdio.h>

int main() {
    CurrencyConvert convertor;
    Currency currency;
    currency.value = 16; currency.unit = Dollar;
    printf("16 dollars = %lf rubles\n",
           convertor.Convert(currency, Ruble).value);
    currency.value = 35.4; currency.unit = Ruble;
    printf("35.4 rubles = %lf pounds\n",
           convertor.Convert(currency, Pound).value);
    currency.value = -13; currency.unit = Dollar;
    printf("-13 dollars = %lf euro\n",
           convertor.Convert(currency, Euro).value);
    return 0;
}
