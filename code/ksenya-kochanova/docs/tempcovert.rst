Кочанова Ксения: Конвертор температур
==================================

Класс ``TemperatureConvertor`` предназначен для конвертации одной единицы измерения температуры в другую.
Каждый метод конвертирует любую величину температуры в указанную.

.. code-block:: cpp

	class TemperatureСonverter
	{
	public:
		TemperatureСonverter();
		virtual ~TemperatureСonverter();

		double CelsiyToKelvin(double temp);
		double CelsiyToFarengate(double temp);
		double CelsiyToNewton(double temp);
		double KelvinToCelsiy(double temp);
		double FarengateToCelsiy(double temp);
		double NewtonToCelsiy(double temp);
	};


Примером использования класса в пользовательском C++ коде может служить нижеследующий код:


.. code-block:: cpp

    TemperatureСonverter* convertor;
    double temp = 10;
    convertor->ToFootCelsiyToKelvin(temp);