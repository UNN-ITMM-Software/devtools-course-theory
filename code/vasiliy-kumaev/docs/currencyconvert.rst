Кумаев Василий: Конвертор валют
===============================

Класс ``CurrencyConvert`` предназначен для осуществления конвертации валют. Он представляет метод ``Convert`` для конвертирования одной валюты в другую.

.. code-block:: cpp

/* Copyright 2013 Vasiliy Kumaev */
#ifndef CODE_VASILIY_KUMAEV_INCLUDE_CURRENCYCONVERTOR_H_
#define CODE_VASILIY_KUMAEV_INCLUDE_CURRENCYCONVERTOR_H_

enum Unit {Dollar, Euro, Ruble, Pound};

struct Currency {
    Unit unit;
    double value;
};

class CurrencyConvert {
public:
        CurrencyConvert(void);
        virtual ~CurrencyConvert(void);

        Currency Convert(Currency currency, Unit UnitOutput);
};

#endif  // CODE_VASILIY_KUMAEV_INCLUDE_CURRENCYCONVERTOR_H_

Примером использования класса в пользовательском C++ коде может служить нижеследующий код:

.. code-block:: cpp

CurrencyConvertor convertor;
Currency CurrencyUnit;
CurrencyUnit.value = 50;
CurrencyUnit.unit = Ruble;
Unit UnitOutput = Euro;
Currency CurrencyOutput = convertor.Convert(CurrencyUnit, UnitOutput);