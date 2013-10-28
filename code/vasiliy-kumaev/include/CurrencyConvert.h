/* Copyright 2013 Vasiliy Kumaev */
#ifndef CODE_VASILIY_KUMAEV_INCLUDE_CURRENCYCONVERT_H_
#define CODE_VASILIY_KUMAEV_INCLUDE_CURRENCYCONVERT_H_

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

#endif  // CODE_VASILIY_KUMAEV_INCLUDE_CURRENCYCONVERT_H_
