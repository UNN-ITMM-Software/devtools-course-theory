/* Copyright 2013 Vasiliy Kumaev */
#ifndef CODE_VASILIY_KUMAEV_LIBRARY_CURRENCYCONVERT_H_
#define CODE_VASILIY_KUMAEV_LIBRARY_CURRENCYCONVERT_H_

enum Unit {Dollar, Euro, Ruble, Pound};

#pragma pack(push, 1)
typedef struct {
    double value;
    Unit unit;
} Currency;
#pragma pack(pop)

class CurrencyConvert {
 public:
    CurrencyConvert(void);
    virtual ~CurrencyConvert(void);

    Currency Convert(Currency currency, Unit UnitOutput);
};

#endif  // CODE_VASILIY_KUMAEV_LIBRARY_CURRENCYCONVERT_H_
