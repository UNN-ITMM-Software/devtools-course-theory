/* Copyright 2013 Ksenya Kochanova */
#ifndef CODE_KSENYA_KOCHANOVA_LIBRARY_TEMPERATURECONVERTER_H_
#define CODE_KSENYA_KOCHANOVA_LIBRARY_TEMPERATURECONVERTER_H_

enum TemperatureUnit {Celsius, Kelvin, Fahrenheit, Newton};
#pragma pack(push, 1)
typedef struct {
    double value;
    TemperatureUnit unit;
} Temperature;
#pragma pack(pop)

class TemperatureConvertor {
    public
    :
        TemperatureConvertor(void);
        ~TemperatureConvertor(void);
       double Convert(double value, TemperatureUnit fromUnit,
       TemperatureUnit toUnit);
    private
    :
        Temperature ConvertToCelsius(Temperature fromTemperature);
        double ConvertFromCelsius(Temperature inCelsius,
TemperatureUnit toUnit);
    };

#endif  // CODE_KSENYA_KOCHANOVA_LIBRARY_TEMPERATURECONVERTER_H_
