Голодяев Андрей: Калькулятор комплексных чисел
==============================================

Класс ``ComplexCalculator`` предназначен для осуществления простых операций с комплексными числами.
В нем представлены методы для сложения, вычитания, умножения и деления комплексных чисел.

 .. code-block:: cpp
 
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
		
Пример использования класса ``ComplexCalculator`` в пользовательском C++ коде:

 .. code-block:: cpp
		
		ComplexCalculator a(5,1);
		ComplexCalculator b(1,2);
		ComplexCalculator c;
		c.Add(a,b);
		cout<<"A+B="<<c<<endl;
		c.Sub(a,b);
		cout<<"A-B="<<c<<endl;
		c.Multi(a,b);
		cout<<"A*B="<<c<<endl;
		c.Div(a,b);
		cout<<"A/B="<<c<<endl;
