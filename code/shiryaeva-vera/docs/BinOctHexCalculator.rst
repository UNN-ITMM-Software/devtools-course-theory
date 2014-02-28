Ширяева Вера: HEX,BIN,OCT Калькулятор
=====================================

Класс ``BinOctHexCalculator`` предназначен для осуществления простых арифметических операций с числами, представленными в различных системах счисления.
В нем представлены методы:
  * сложения
  * вычитания
  * умножения
  * деления

.. code-block:: cpp

	enum Notation {Bin, Oct, Hex};

	class BinOctHexCalculator {
		public:
			BinOctHexCalculator(void);
			~BinOctHexCalculator(void);

			std::string Add(std::string value1, Notation notation1, std::string value2, Notation notation2, Notation outputNotation);
			std::string Sub(std::string value1, Notation notation1, std::string value2, Notation notation2, Notation outputNotation);
			std::string Mult(std::string value1, Notation notation1, std::string value2, Notation notation2, Notation outputNotation);
			std::string Div(std::string value1, Notation notation1, std::string value2, Notation notation2, Notation outputNotation);
	};

Пример использования класса в пользовательском C++ коде:

.. code-block:: cpp

	BinOctHexCalculator calc;
	Notation notation1 = Hex;
	std::string value1 = "10";
	Notation notation2 = Bin;
	std::string value2 = "1011";
	printf("Here is result of %s + %s: %s\n",value1.c_str(), value2.c_str(), calc.Add(value1, notation1, value2, notation2, Bin).c_str());
	printf("Here is result of %s - %s: %s\n",value1.c_str(), value2.c_str(), calc.Sub(value1, notation1, value2, notation2, Bin).c_str());
	printf("Here is result of %s * %s: %s\n",value1.c_str(), value2.c_str(), calc.Mult(value1, notation1, value2, notation2, Bin).c_str());
	printf("Here is result of %s / %s: %s\n",value1.c_str(), value2.c_str(), calc.Div(value1, notation1, value2, notation2, Bin).c_str());
