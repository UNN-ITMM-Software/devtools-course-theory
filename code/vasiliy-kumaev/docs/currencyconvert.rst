Кумаев Василий: Конвертор валют
===============================

Класс ``CurrencyConvert`` предназначен для осуществления конвертации валют. Он представляет метод ``ConvertCurrency`` для конвертирования одной валюты в другую.

.. code-block:: cpp

    #pragma once
    enum Unit {Dollar, Euro, Ruble, Pound};
    struct Currency
    {
        Unit unit;
        double value;
    };
    class CurrencyConvert
    {
    public:
        CurrencyConvert(void);
        virtual ~CurrencyConvert(void);
        Currency ConvertCurrency(Currency currency, Unit UnitOutput);
    };

Примером использования класса в пользовательском C++ коде может служить нижеследующий код:

.. code-block:: cpp

    CurrencyConvertor convertor;
    Currency CurrencyUnit;
    CurrencyUnit.value = 50;
    CurrencyUnit.unit = Ruble;
    Unit UnitOutput = Euro;
    Currency CurrencyOutput = convertor.ConvertCurrency(CurrencyUnit, UnitOutput);