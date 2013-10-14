Кирилл Николаев: Конвертор чисел
================================
Класс ``NumConverter`` предназначен для представления чисел, записанных в различных позиционных системах счисления (двоичной, восьмеричной, десятичной, шестнадцатеричной). Класс позволяет переводить числа в другие системы счисления из заявленных выше.

.. code-block:: cpp

	enum NumSystem
	{
		hex,octal,decimal,binary
	};
	std::string dec_to_bin(int dec_number);
	class NumConverter
	{
	private:
		NumSystem NumSys;
		std::string Value;
	public:
		NumConverter(NumSystem myNumSys, std::string myValue);
		~NumConverter();
		std::string GetValue();
		int ToHex();
		int ToOctal();
		int ToDecimal();
		int ToBinary();
	};

Пример использования:
---------------------
.. code-block:: cpp

	NumConverter a(decimal,"100");
	a.ToBinary();
	std::cout<<a.GetValue()<<std::endl;