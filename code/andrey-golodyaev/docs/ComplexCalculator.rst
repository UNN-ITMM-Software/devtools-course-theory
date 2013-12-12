Голодяев Андрей: Калькулятор комплексных чисел
==============================================

Класс ``ComplexNumber`` предназначен для хранения комплексных чисел и осуществления с ними простых операций.
В нем представлены методы для сложения, вычитания, умножения и деления комплексных чисел.

 .. code-block:: cpp
 
		class ComplexNumber
		{
		private:
			double real;
			double imaginary;
		public:
			ComplexNumber(double _real=0, double _imaginary=0);
			~ComplexNumber();
			
			double GetReal();
			double GetImaginary();
			void SetReal(double _real);
			void SetImaginary(double _imaginary);
			void Input(char *str);
			void Output(char* str);
			static ComplexNumber Add(ComplexNumber first, ComplexNumber second);
			static ComplexNumber Sub(ComplexNumber first, ComplexNumber second);
			static ComplexNumber Mul(ComplexNumber first, ComplexNumber second);
			static ComplexNumber Div(ComplexNumber first, ComplexNumber second);
		};
		
Пример использования класса ``ComplexNumber`` в пользовательском C++ коде:

 .. code-block:: cpp
		
		ComplexNumber a(1,1);
		ComplexNumber b(2,2);
		ComplexNumber c(0,0);
		char str[10]="";
		c=ComplexNumber::Add(a,b);
		c.Output(str);
		printf("A+B=%s\n",str);
