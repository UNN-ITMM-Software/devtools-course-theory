/* Copyright 2013 Ksenya Kochanova */
#include <iostream>
#include <stdlib.h>
#include "TemperatureConverter.h"
TemperatureConvertor::TemperatureConvertor(void) {}
TemperatureConvertor::~TemperatureConvertor(void) {}
Temperature TemperatureConvertor::ConvertToCelsius(Temperature fromTemperature)
{
    Temperature inCelsius;
    if (fromTemperature.value > -273.15)
        inCelsius.value = a[fromTemperature.unit] * fromTemperature.value 
		                                          + b[fromTemperature.unit];
    else {
		std::cout << "Error" << std::endl;
        exit (0);
    }
    return inCelsius;
}
Temperature TemperatureConvertor:: ConvertFromCelsius(Temperature inCelsius, 
TemperatureUnit toUnit) {
	Temperature outTemperature;
    outTemperature.value = 1 / a[toUnit] * (inCelsius.value - b[toUnit]);
    return outTemperature;
}
