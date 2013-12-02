/* Copyright 2013 Ksenya Kochanova */
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
Temperature TemperatureConvertor::Convert(double value,
                           TemperatureUnit fromUnit, TemperatureUnit toUnit) {
    Temperature t;
        if (((value < -273.15))&&(fromUnit == Celsius)||
            ((value < 0)&&(fromUnit == Kelvin))||
            ((value < -459.67)&&(fromUnit == Fahrenheit))||
            ((value < -90.14)&&(fromUnit == Newton))||
            ((fromUnit < Celsius) || (fromUnit > Newton)) ||
            ((toUnit < Celsius) || (toUnit > Newton))) {
            throw "wrong data";
        }
        t.value = value;
        t.unit = fromUnit;
      Temperature temp = ConvertToCelsius(t);
        return ConvertFromCelsius(temp, toUnit);
}
