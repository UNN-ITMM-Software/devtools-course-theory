/* Copyright 2013 Ksenya Kochanova */
#ifndef CODE_KSENYA_KOCHANOVA_INCLUDE_TEMPERATURECONVERTER_H_
#define CODE_KSENYA_KOCHANOVA_INCLUDE_TEMPERATURECONVERTER_H_

enum TemperatureUnit {Celsius, Kelvin, Fahrenheit, Newton};

    struct Temperature {
    double value;
    TemperatureUnit unit;
};

class TemperatureConvertor {
    public
    :
        TemperatureConvertor(void);
        ~TemperatureConvertor(void);
        Temperature ConvertToCelsius(Temperature fromTemperature);
        Temperature ConvertFromCelsius(Temperature inCelsius,
TemperatureUnit toUnit);
    };

#endif  // CODE_KSENYA_KOCHANOVA_INCLUDE_TEMPERATURECONVERTER_H_
