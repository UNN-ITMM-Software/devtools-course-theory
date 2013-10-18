enum Notation {Bin, Oct, Hex};

struct Number
{
	char* value;
	Notation notation; 
};

class BinOctHexCalculator
{
private:
	double NumberToDouble(Number a);
	Number DoubleToNumber(double a, Notation notation);
public:
	BinOctHexCalculator(void);
	virtual ~BinOctHexCalculator(void);
	Number Add(Number a, Number b, Notation outputNotation);
	Number Sub(Number a, Number b, Notation outputNotation);
	Number Mult(Number a, Number b, Notation outputNotation);
	Number Div(Number a, Number b, Notation outputNotation);
};