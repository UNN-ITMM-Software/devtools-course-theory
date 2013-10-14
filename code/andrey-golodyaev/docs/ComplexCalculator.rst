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
			friend istream& operator >>(istream& cin, ComplexCalculator &second);
			friend ostream& operator <<(ostream& cout, ComplexCalculator &second);
			static ComplexCalculator Add(ComplexCalculator first, ComplexCalculator second);
			static ComplexCalculator Sub(ComplexCalculator first, ComplexCalculator second);
			static ComplexCalculator Multi(ComplexCalculator first, ComplexCalculator second);
			static ComplexCalculator Div(ComplexCalculator first, ComplexCalculator second);
		};
		
Пример использования класса ``ComplexCalculator`` в пользовательском C++ коде:

 .. code-block:: cpp
		
		ComplexCalculator a(5,1);
		ComplexCalculator b(1,2);
		ComplexCalculator c;
		c=ComplexCalculator::Add(a,b);
		cout<<"A+B="<<c<<endl;
		c=ComplexCalculator::Sub(a,b);
		cout<<"A-B="<<c<<endl;
		c=ComplexCalculator::Multi(a,b);
		cout<<"A*B="<<c<<endl;
		c=ComplexCalculator::Div(a,b);
		cout<<"A/B="<<c<<endl;
