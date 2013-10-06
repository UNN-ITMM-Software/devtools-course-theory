Кумаев Василий: Конвертор валют
===============================

Класс ``CurrencyConvert`` и  его метод ``ConvertCurrency`` предназначены для конвертации одной валюты в другую.

.. code-block:: cpp

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

Примером использования класса в пользовательском C++ коде может служить нижеследующий код:

    CurrencyConvertor convertor;
    Currency currencyconv;
    currencyconv.value = 50;
    currencyconv.UnitInput = Ruble;
    currencyconv.UnitOutput = Euro;
    convertor.ConvertCurrency(currencyconv);