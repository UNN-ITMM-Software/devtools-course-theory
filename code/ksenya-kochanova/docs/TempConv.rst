Ксения Кочанова: Конвертор температур
=====================================
Класс ``TemperatureConverter`` предназначен для конвертации одной единицы измерения температуры в другую.
Метод ConvertToCelsius конвертирует введенную величину в градусы по шкале Цельсия.
Метод ConvertFromCelsius конвертирует из градусов Цельсия в указанную единицу измерения.


.. code-block:: cpp

enum TemperatureUnit {Celsius, Kelvin, Fahrenheit, Newton};

struct Temperature {
    double value;
    TemperatureUnit unit;
};

static double a[4] = {1, 1, 5/9, 100/33};
static double b[4] = {0, -273.15, -32, 0};

class TemperatureConvertor {
    public
    :
        TemperatureConvertor(void);
        ~TemperatureConvertor(void);
        
        Temperature ConvertToCelsius(Temperature fromTemperature);
        Temperature ConvertFromCelsius(Temperature inCelsius,
TemperatureUnit toUnit);
    };


Примером использования класса в пользовательском C++ коде может служить нижеследующий код:


.. code-block:: cpp

    Temperature temperature;
    Temperature newTemperature;
    TemperatureConvertor convertor;
    temperature.value = 0;
    temperature.unit = Kelvin;
    TemperatureUnit newUnit = Newton;
    Temperature inCelsius = convertor.ConvertToCelsius(temperature);
    Temperature outTemperature = convertor.ConvertFromCelsius(inCelsius,
newUnit);