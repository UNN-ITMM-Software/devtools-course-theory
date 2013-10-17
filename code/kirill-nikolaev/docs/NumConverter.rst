Кирилл Николаев: Конвертер чисел
================================
Класс ``NumConverter`` предназначен для представления чисел, записанных в различных позиционных системах счисления (двоичной, восьмеричной, десятичной, шестнадцатеричной). Класс позволяет переводить числа в другие системы счисления из заявленных выше.

.. code-block:: cpp

	enum NumSystem
	{
		hex,oct,dec,bin
	};
	std::string dec_to_bin(int dec_number);
	class NumConverter
	{
	public:
		NumConverter(NumSystem numsys, std::string value);
		~NumConverter();
		std::string GetValue();
		void ToHex();
		void ToOctal();
		void ToDecimal();
		void ToBinary();
	};

Пример использования:
---------------------
.. code-block:: cpp

	NumConverter a(dec,"100");
	a.ToBinary();
	std::cout<<a.GetValue()<<std::endl;
	