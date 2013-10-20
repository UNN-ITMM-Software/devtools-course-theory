Ширяева Вера: HEX,BIN,OCT Калькулятор
=====================================

Класс ``BinOctHexCalculator`` предназначен для осуществления простых арифметических операций с числами, представленными в различных системах счисления.
В нем представлены методы:
  * сложения
  * вычитания
  * умножения
  * деления
Для представления чисел в различных системах счисления используется структура ``Number``, состоящая из собственно значения, представленного строкой символов, и названия системы счисления, представленного переменной перечисляемого типа.

.. code-block:: cpp

	enum Notation {Bin, Oct, Hex};

	struct Number
	{
		char* value;
		Notation notation; 
	};

	class BinOctHexCalculator
	{
	public:
		BinOctHexCalculator(void);
		virtual ~BinOctHexCalculator(void);
		Number Add(Number a, Number b, Notation outputNotation);
		Number Sub(Number a, Number b, Notation outputNotation);
		Number Mult(Number a, Number b, Notation outputNotation);
		Number Div(Number a, Number b, Notation outputNotation);
	private:
		double NumberToDouble(Number a);
		Number DoubleToNumber(double a, Notation notation);
	};

Пример использования класса в пользовательском C++ коде:

.. code-block:: cpp

	BinOctHexCalculator calc;
	Number a, b;
	a.Notation = Bin;
	a.value = "1001";
	b.Notation = Hex;
	b.value = "A03B";
	Number output = calc.Add(a,b);
