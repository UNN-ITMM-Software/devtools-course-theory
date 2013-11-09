/* Copyright 2013 Ksenya Kochanova */
#include <stdio.h>
#include <TemperatureConverter.h>

TemperatureConvertor::TemperatureConvertor(void) {}

TemperatureConvertor::~TemperatureConvertor(void) {}

Temperature TemperatureConvertor::ConvertToCelsius(Temperature
fromTemperature) {
    double a[4] = {1, 1, 5/9, 100/33};
    double b[4] = {0, -273.15, -32, 0};
    Temperature inCelsius;
    if ((fromTemperature.unit == Celsius)&&(fromTemperature.value < -273.15))
         inCelsius.value = 12345;
    if ((fromTemperature.unit == Kelvin)&&(fromTemperature.value < 0))
        inCelsius.value = 12345;
    if ((fromTemperature.unit == Fahrenheit)&&(fromTemperature.value < -459.67))
        inCelsius.value = 12345;
    if ((fromTemperature.unit == Fahrenheit)&&(fromTemperature.value < -90.14))
        inCelsius.value = 12345;
    else
        inCelsius.value = a[fromTemperature.unit] * fromTemperature.value
+ b[fromTemperature.unit];
    return inCelsius;
}
Temperature TemperatureConvertor:: ConvertFromCelsius(Temperature inCelsius,
TemperatureUnit toUnit) {
    double a[4] = {1, 1, 5/9, 100/33};
    double b[4] = {0, -273.15, -32, 0};
    Temperature outTemperature;
    if (inCelsius.value == 12345) {
        outTemperature.value = 12345;
        printf("Erorr");
    } else {
        outTemperature.value = 1 / a[toUnit] * (inCelsius.value - b[toUnit]);
    }
    return outTemperature;
}
