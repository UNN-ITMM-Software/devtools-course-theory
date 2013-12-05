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
			~ComplexCalculator();
			
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
		
Пример использования класса ``ComplexCalculator`` в пользовательском C++ коде:

 .. code-block:: cpp
		
		ComplexCalculator a(1,1);
		ComplexCalculator b(2,2);
		ComplexCalculator c(0,0);
		char str[10]="";
		c=ComplexCalculator::Add(a,b);
		c.Output(str);
		printf("A+B=%s\n",str);
