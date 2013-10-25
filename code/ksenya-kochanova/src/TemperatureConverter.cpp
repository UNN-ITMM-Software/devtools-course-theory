/* Copyright 2013 Ksenya Kochanova */
#include <stdio.h>
#include <TemperatureConverter.h>

TemperatureConvertor::TemperatureConvertor(void) {}

TemperatureConvertor::~TemperatureConvertor(void) {}

Temperature TemperatureConvertor::ConvertToCelsius(Temperature
fromTemperature) {
    Temperature inCelsius;
    if (fromTemperature.value > -273.15)
        inCelsius.value = a[fromTemperature.unit] * fromTemperature.value
+ b[fromTemperature.unit];
    else
        inCelsius.value = 0.0001;
    return inCelsius;
}
Temperature TemperatureConvertor:: ConvertFromCelsius(Temperature inCelsius,
TemperatureUnit toUnit) {
    Temperature outTemperature;
    if (inCelsius.value == 0.0001) {
        outTemperature.value = 0.0001;
        printf("Erorr");
    }
    else
        outTemperature.value = 1 / a[toUnit] * (inCelsius.value - b[toUnit]);
    return outTemperature;
}
