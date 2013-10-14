
#pragma once

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
       Temperature ConvertTo(Temperature fromTemperature,TemperatureUnit toUnit);
    };

