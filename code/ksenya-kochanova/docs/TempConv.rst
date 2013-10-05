Кочанова Ксения: Конвертор температур
=====================================

Класс ``TemperatureConverter`` предназначен для конвертации одной единицы измерения температуры в другую.
Каждый метод конвертирует введенную величину температуры в указанную.

.. code-block:: cpp

enum Unit {Celsius, Kelvin, Fahrenheit, Newton};

	struct Temperature
	{
	public:
		double myValue;
		Unit myUnit;
	};
	class TemperatureConverter
	{

	public:
		Temperature t;
		TemperatureConverter(void);
		virtual ~TemperatureConverter(void);	
		Temperature ConvertTemperature(Temperature fromTemperature,Unit toUnit);
	};


Примером использования класса в пользовательском C++ коде может служить нижеследующий код:


	TemperatureConverter();
	TemperatureConverter myConv;
	myConv.t.myUnit = Celsius;
	myConv.t.myValue = 10;
	Unit toUnit = Kelvin;
	Temperature OutputTemperature = myConv.ConvertTemperature(myConv.t,toUnit);