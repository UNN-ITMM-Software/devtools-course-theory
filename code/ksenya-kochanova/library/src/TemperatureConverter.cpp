/* Copyright 2013 Ksenya Kochanova */

#include "library/TemperatureConverter.h"

#include <stdint.h>
#include <limits.h>
#include <string>

TemperatureConvertor::TemperatureConvertor() {}
TemperatureConvertor::~TemperatureConvertor() {}
double TemperatureConvertor::a[4] = {1, 1, 0.5555555555555556, 3.030303030302};
double TemperatureConvertor::b[4] = {0, -273.15, -32, 0};
Temperature TemperatureConvertor::ConvertToCelsius(Temperature
                                            fromTemperature) {
    Temperature inCelsius;
    inCelsius.value = a[fromTemperature.unit] * fromTemperature.value
                                            + b[fromTemperature.unit];
    return inCelsius;
}
Temperature TemperatureConvertor::ConvertFromCelsius(Temperature inCelsius,
                                                 TemperatureUnit toUnit) {
    Temperature outTemperature;
    outTemperature.value = 1 / a[toUnit] * (inCelsius.value - b[toUnit]);
    return outTemperature;
}
int TemperatureConvertor::CheckThatHigherThanAbsoluteZero(Temperature t,
                                                 TemperatureUnit toUnit) {
    int code = 0;
    if (((t.value < -273.15)&&(t.unit == Celsius))||
            ((t.value < 0)&&(t.unit == Kelvin))||
            ((t.value < -459.67)&&(t.unit == Fahrenheit))||
            ((t.value < -90.14)&&(t.unit == Newton))||
            ((t.unit < Celsius) || (t.unit > Newton)) ||
            ((toUnit < Celsius) || (toUnit > Newton)))
            code = 1;
     return code;
}
Temperature TemperatureConvertor::Convert(Temperature t,
                               TemperatureUnit toUnit) {
    int returnCode = CheckThatHigherThanAbsoluteZero(t, toUnit);
    if (returnCode != 0) {
            throw std::string("Wrong data!");
        }
      Temperature temp = ConvertToCelsius(t);
      return ConvertFromCelsius(temp, toUnit);
}

