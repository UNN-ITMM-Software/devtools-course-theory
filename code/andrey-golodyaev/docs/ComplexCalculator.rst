Голодяев Андрей: Калькулятор комплексных чисел
==============================================

Класс ``ComplexCalculator`` предназначен для осуществления простых операций с комплексными числами.
В нем представлены методы для сложения, вычитания, умножения и деления комплексных чисел.

 .. code-block:: cpp
 
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
		
Пример использования класса ``ComplexCalculator`` в пользовательском C++ коде:

 .. code-block:: cpp
		
		ComplexCalculator a(5,1);
		ComplexCalculator b(1,2);
		ComplexCalculator c;
		c=a+b;
		printf("A+B=%d+%d*i",c.GetReal,c.GetFake);
		c=a-b;
		printf("A-B=%d+%d*i",c.GetReal,c.GetFake);
		c=a*b;
		printf("A*B=%d+%d*i",c.GetReal,c.GetFake);
		c=a/b;
		printf("A/B=%d+%d*i",c.GetReal,c.GetFake);
