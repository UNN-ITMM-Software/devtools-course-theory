/* Copyright 2013 Ksenya Kochanova */
#include <TemperatureConverter.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cstdio>

TemperatureConvertor::TemperatureConvertor(void) {}

TemperatureConvertor::~TemperatureConvertor(void) {}

Temperature TemperatureConvertor::ConvertToCelsius(Temperature
fromTemperature) {
    double a[4] = {1, 1, 0.5555555555555556, 3.0303030303030303};
    double b[4] = {0, -273.15, -32, 0};
    Temperature inCelsius;
    inCelsius.value = a[fromTemperature.unit] * fromTemperature.value
+ b[fromTemperature.unit];
    return inCelsius;
}
Temperature TemperatureConvertor::ConvertFromCelsius(Temperature inCelsius,
TemperatureUnit toUnit) {
    double a[4] = {1, 1, 0.5555555555555556, 3.0303030303030303};
    double b[4] = {0, -273.15, -32, 0};
    Temperature outTemperature;
    outTemperature.value = 1 / a[toUnit] * (inCelsius.value - b[toUnit]);
    return outTemperature;
}
Temperature TemperatureConvertor::Convert(Temperature t,
TemperatureUnit newUnit) {
    if (((t.unit == Celsius)&&(t.value < -273.15))||
       ((t.unit == Kelvin)&&(t.value < 0))||
       ((t.unit == Fahrenheit)&&(t.value < -459.67))||
       ((t.unit == Newton)&&(t.value < -90.14)))
           throw "wrong";
           Temperature temp = ConvertToCelsius(t);
           return ConvertFromCelsius(temp, newUnit);
}
