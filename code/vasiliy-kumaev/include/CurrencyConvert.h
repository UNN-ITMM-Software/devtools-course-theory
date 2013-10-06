#pragma once
enum Unit {Dollar, Euro, Ruble, Pound};
struct Currency
{
	Unit UnitInput;
	Unit UnitOutput;
	double value;
}
class CurrencyConvert
{
public:
	CurrencyConvert(void);
	virtual ~CurrencyConvert(void);
	Currency ConvertCurrency(Currency currency);
};