class ComplexCalculator
{
private:
	double real;
	double imaginary;
public:
	ComplexCalculator(double _real=0, double _imaginary=0);
	virtual ~ComplexCalculator();

	double GetReal();
	double GetImaginary();
	void SetReal(double _real);
	void SetImaginary(double _imaginary);
	friend istream& operator >>(istream& cin, compl &second);
	friend ostream& operator <<(ostream& cout, compl &second);
	ComplexCalculator Add(ComplexCalculator first, ComplexCalculator second);
	ComplexCalculator Sub(ComplexCalculator first, ComplexCalculator second);
	ComplexCalculator Multi(ComplexCalculator first, ComplexCalculator second);
	ComplexCalculator Div(ComplexCalculator first, ComplexCalculator second);
};