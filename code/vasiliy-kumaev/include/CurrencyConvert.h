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

