Кумаев Василий: Конвертор валют
===============================

Класс ``CurrencyConvertor`` и  его метод ``ConvertCurrency`` предназначены для конвертации одной валюты в другую.

.. code-block:: cpp

struct Currency
{
	enum  {Dollar, Euro, Ruble, Pound};
	double value;
}
class CurrencyConvert
{
	enum Unit {Dollar, Euro, Ruble, Pound};
public:
	CurrencyConvert(void);
	Currency ConvertCurrency(Currency fromCurrency, Unit toUnit);
	virtual ~CurrencyConvert(void);
};


Примером использования класса в пользовательском C++ коде может служить нижеследующий код:

    CurrencyConvert(void);
    CurrencyСonvert* convertor;
    Currency fromС;
    fromС.UnitInput = Ruble;
    fromC.value = 50;
    UnitO = Dollar
    convertor->ConvertCurrency(fromC,UnitO);
