Ксения Кочанова: Конвертор температур
=====================================
Класс ``TemperatureConverter`` предназначен для конвертации одной единицы измерения температуры в другую.
Каждый метод конвертирует введенную величину температуры в указанную.

.. code-block:: cpp

    enum TemperatureUnit {Celsius, Kelvin, Fahrenheit, Newton};
    struct Temperature
    {
        double value;
        TemperatureUnit unit;
    };

    class TemperatureConvertor
    {
    public:
        TemperatureConvertor(void);
        virtual ~TemperatureConvertor(void);
        ConvertTo(Temperature fromTemperature,TemperatureUnit toUnit);
    };


Примером использования класса в пользовательском C++ коде может служить нижеследующий код:


.. code-block:: cpp

    Temperature temperature;
    temperature.Temperature = Celsius;
    temperature.value = 10;

    TemperatureConverter convertor;
    Temperature outTemperature = convertor.ConvertTo(temperature, TemperatureUnit::Kelvin);