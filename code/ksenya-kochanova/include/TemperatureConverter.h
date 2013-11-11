/* Copyright 2013 Ksenya Kochanova */
#ifndef CODE_KSENYA_KOCHANOVA_INCLUDE_TEMPERATURECONVERTER_H_
#define CODE_KSENYA_KOCHANOVA_INCLUDE_TEMPERATURECONVERTER_H_

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
        Temperature Convert(Temperature fromtemp, TemperatureUnit toUnit);
    private
    :
        Temperature ConvertToCelsius(Temperature fromTemperature);
        Temperature ConvertFromCelsius(Temperature inCelsius,
TemperatureUnit toUnit);
    };

#endif  // CODE_KSENYA_KOCHANOVA_INCLUDE_TEMPERATURECONVERTER_H_
