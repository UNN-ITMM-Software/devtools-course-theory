#include "CurrencyConvert.h"

CurrencyConvert::CurrencyConvert(void) {}

CurrencyConvert::~CurrencyConvert(void) {}

Currency CurrencyConvert::ConvertCurrency(Currency currency, Unit UnitOutput)
{
	double multiplierToDollar[4] = {1, 0.74, 0.03, 1.59};
	if (currency.value >= 0)
		currency.value = multiplierToDollar[currency.unit]*currency.value/multiplierToDollar[UnitOutput];
	else
		currency.value = -1;
	return currency;        
}	