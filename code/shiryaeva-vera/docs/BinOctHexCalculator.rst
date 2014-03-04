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
	
	struct Number {
	std::string value;
	Notation notation;
	};

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
	Number num1, num2;
    num1.notation = Hex;
    num1.value = "10";
    num2.notation = Bin;
    num2.value = "1011";
    printf("Here is result of %s + %s: %s\n", num1.value.c_str(), num2.value.c_str(),
            calc.Add(num1, num2, Bin).c_str());
    printf("Here is result of %s - %s: %s\n", num1.value.c_str(), num2.value.c_str(),
            calc.Sub(num1, num2, Bin).c_str());
    printf("Here is result of %s * %s: %s\n", num1.value.c_str(), num2.value.c_str(),
            calc.Mult(num1, num2, Bin).c_str());
    printf("Here is result of %s / %s: %s\n", num1.value.c_str(), num2.value.c_str(),
            calc.Div(num1, num2, Bin).c_str());
