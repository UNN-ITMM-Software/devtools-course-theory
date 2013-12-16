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
			ComplexNumber(double real=0, double imaginary=0);
			~ComplexNumber();
			
			double GetReal() const;
			double GetImaginary() const;
			void SetReal(double real);
			void SetImaginary(double imaginary);
			void Input(char *str);
			void Output(char* str);
			ComplexNumber operator +(const ComplexNumber &second) const;
			ComplexNumber operator -(const ComplexNumber &second) const;
			ComplexNumber operator *(const ComplexNumber &second) const;
			ComplexNumber operator /(const ComplexNumber &second) const;
		};
		
Пример использования класса ``ComplexNumber`` в пользовательском C++ коде:

 .. code-block:: cpp
		
		ComplexNumber a(1, 1);
		ComplexNumber b(2, 2);
		ComplexNumber c(0, 0);
		char str[10] = "";
		c = a + b;
		c.Output(str);
		printf("A+B = %s\n", str);
