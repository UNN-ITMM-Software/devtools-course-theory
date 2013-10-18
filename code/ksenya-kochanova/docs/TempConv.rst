Ксения Кочанова: Конвертор температур
=====================================
Класс ``TemperatureConverter`` предназначен для конвертации одной единицы измерения температуры в другую.
Каждый метод конвертирует введенную величину температуры в указанную.


.. code-block:: cpp

#include <iostream>
#include <string>
#pragma once

enum TemperatureUnit {Celsius, Kelvin, Fahrenheit, Newton};
struct Temperature
{
	double value;
	TemperatureUnit unit;
};

class TemperatureConvertor
{
	friend std::istream& operator>>(std::istream& input, TemperatureUnit& newtemp);
public:
	TemperatureConvertor(void);
	virtual ~TemperatureConvertor(void);
	Temperature ConvertTo(Temperature fromTemperature,TemperatureUnit toUnit);
};

Примером использования класса в пользовательском C++ коде может служить нижеследующий код:


.. code-block:: cpp

    Temperature temperature;
    temperature.Temperature = Celsius;
    temperature.value = 10;

    TemperatureConverter convertor;
    Temperature outTemperature = convertor.ConvertTo(temperature, TemperatureUnit::Kelvin);