#include "CurrencyConvert.h"
#include "stdio.h"

int main()
{
	CurrencyConvert convertor;
	Currency currency;
	currency.value = 16; currency.unit = Dollar;
	printf("16 dollars = %lf rubles\n", convertor.ConvertCurrency(currency, Ruble).value);
	currency.value = 35.4; currency.unit = Ruble;
	printf("35.4 rubles = %lf pounds\n", convertor.ConvertCurrency(currency, Pound).value);
	currency.value = -13; currency.unit = Dollar;
	printf("-13 dollars = %lf euro\n", convertor.ConvertCurrency(currency, Euro).value); //Incorrect input, returns -1.0
	return 0;
}