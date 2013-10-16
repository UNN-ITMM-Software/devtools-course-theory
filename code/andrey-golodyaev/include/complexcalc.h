class ComplexCalculator
{
private:
	double real;
	double imaginary;
public:
	ComplexCalculator(double _real, double _imaginary);
	virtual ~ComplexCalculator();

	double GetReal();
	double GetImaginary();
	void SetReal(double _real);
	void SetImaginary(double _imaginary);
	void Input(char *str);
	void Output(char* str);
	static ComplexCalculator Add(ComplexCalculator first, ComplexCalculator second);
	static ComplexCalculator Sub(ComplexCalculator first, ComplexCalculator second);
	static ComplexCalculator Multi(ComplexCalculator first, ComplexCalculator second);
	static ComplexCalculator Div(ComplexCalculator first, ComplexCalculator second);
};