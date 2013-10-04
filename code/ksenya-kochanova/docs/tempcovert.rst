Кочанова Ксения: Конвертор температур
=====================================

Класс ``TemperatureConvertor`` предназначен для конвертации одной единицы измерения температуры в другую.
Каждый метод конвертирует введенную величину температуры в указанную.

.. code-block:: cpp

struct Temperature
	{
		enum UnitInput {Celsiy, Kelvin, Farengate, Newton};
		double value;
	}
class TemperatureConvert
	{
		enum UnitOutput {Celsiy, Kelvin, Farengate, Newton};
		Temperature fromTemperature;
public:
		TemperatureConvert(void);
		Temperature ConvertTemperature(Temperature fromTemperature, UnitOutput toUnit);
		virtual ~TemperatureConvert(void);
	};


Примером использования класса в пользовательском C++ коде может служить нижеследующий код:

    TemperatureConvert(void);
    TemperatureСonvert* convertor;
    Temperature fromT;
    fromT.UnitInput = 'Celsiy';
    fromT.value = 10;
    UnitO = 'Kelvin'
    convertor->ToFootCelsiyToKelvin(fromT,UnitO);
