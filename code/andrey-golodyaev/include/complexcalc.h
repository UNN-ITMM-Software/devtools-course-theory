class ComplexCalculator
{
private:
	double real;
	double fake;
public:
	ComplexCalculator(double _real=0, double _fake=0);
	virtual ~ComplexCalculator();

	double GetReal();
	double GetFake();
	void SetReal(double _real);
	void SetFake(double _fake);
	ComplexCalculator operator +(ComplexCalculator second);
	ComplexCalculator operator -(ComplexCalculator second);
	ComplexCalculator operator *(ComplexCalculator second);
	ComplexCalculator operator /(ComplexCalculator second);
};