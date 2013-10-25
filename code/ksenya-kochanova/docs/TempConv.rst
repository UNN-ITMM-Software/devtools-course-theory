Ксения Кочанова: Конвертор температур
=====================================
Класс ``TemperatureConverter`` предназначен для конвертации одной единицы измерения температуры в другую.
Каждый метод конвертирует введенную величину температуры в указанную.


.. code-block:: cpp
/* Copyright 2013 Ksenya Kochanova */
#ifndef CODE_KSENYA_KOCHANOVA_INCLUDE_TEMPERATURECONVERTER_H_
#define CODE_KSENYA_KOCHANOVA_INCLUDE_TEMPERATURECONVERTER_H_

enum TemperatureUnit {Celsius, Kelvin, Fahrenheit, Newton};

struct Temperature
{
    double value;
    TemperatureUnit unit;
};

static double a[4] = {1, 1, 5/9, 100/33};
static double b[4] = {0, -273.15, -32, 0};

class TemperatureConvertor
    {
    public
    :
        TemperatureConvertor(void);
        ~TemperatureConvertor(void);
        
        Temperature ConvertToCelsius(Temperature fromTemperature);
        Temperature ConvertFromCelsius(Temperature inCelsius,
        TemperatureUnit toUnit);
    };

#endif // CODE_KSENYA_KOCHANOVA_INCLUDE_TEMPERATURECONVERTER_H_

Примером использования класса в пользовательском C++ коде может служить нижеследующий код:


.. code-block:: cpp

    Temperature temperature;
	Temperature newTemperature;
	TemperatureConvertor convertor;
	temperature.value = 0;
	temperature.unit = Kelvin;
	TemperatureUnit newUnit = Newton;
	Temperature inCelsius = convertor.ConvertToCelsius(temperature);
	Temperature outTemperature = convertor.ConvertFromCelsius(inCelsius, newUnit);