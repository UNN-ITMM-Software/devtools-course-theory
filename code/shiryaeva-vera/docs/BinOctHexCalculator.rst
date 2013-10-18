Ўир€ева ¬ера: HEX,BIN,OCT  алькул€тор
=====================================

 ласс ``BinOctHexCalculator`` предназначен дл€ осуществлени€ простых арифметических операций с числами, представленными в различных системах счислени€.
¬ нем представлены методы:
  * сложени€
  * вычитани€
  * умножени€
  * делени€
ƒл€ представлени€ чисел в различных системах счислени€ используетс€ структура ``Number``, состо€ща€ из собственно значени€, представленного строкой символов, и названи€ системы счислени€, представленного переменной перечисл€емого типа.

.. code-block:: cpp

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

ѕример использовани€ класса в пользовательском C++ коде:

.. code-block:: cpp

	BinOctHexCalculator calc;
	Number a, b;
	a.Notation = Bin;
	a.value = "1001";
	b.Notation = Hex;
	b.value = "A03B";
	Number output = calc.Add(a,b);
