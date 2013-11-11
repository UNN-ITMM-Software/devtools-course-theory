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
    double a[4] = {1, 1, 5/9, 100/33};
    double b[4] = {0, -273.15, -32, 0};
    Temperature inCelsius;
    inCelsius.value = a[fromTemperature.unit] * fromTemperature.value
+ b[fromTemperature.unit];
    return inCelsius;
}
Temperature TemperatureConvertor:: ConvertFromCelsius(Temperature inCelsius,
TemperatureUnit toUnit) {
    double a[4] = {1, 1, 5/9, 100/33};
    double b[4] = {0, -273.15, -32, 0};
    Temperature outTemperature;
    outTemperature.value = 1 / a[toUnit] * (inCelsius.value - b[toUnit]);
    return outTemperature;
}
Temperature TemperatureConvertor:: Convert (Temperature temperature,TemperatureUnit toUnit)
{
    Temperature temp;
    Temperature (TemperatureConvertor::*ConvertToCelsius)(Temperature);
    Temperature (TemperatureConvertor::*ConvertFromCelsius)(Temperature ,
TemperatureUnit );
    ConvertToCelsius = &TemperatureConvertor::ConvertToCelsius;
    ConvertFromCelsius = &TemperatureConvertor::ConvertFromCelsius;
    temp = (this->*ConvertToCelsius)(temperature);
    return (this->*ConvertFromCelsius)(temp,toUnit);
}
