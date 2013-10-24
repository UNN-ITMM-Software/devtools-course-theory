/* Copyright 2013 Ksenya Kochanova */
#include "TemperatureConverter.h"

TemperatureConvertor::TemperatureConvertor(void) {}

TemperatureConvertor::~TemperatureConvertor(void) {}

Temperature  TemperatureConvertor::ConvertToCelsius(Temperature fromTemperature) {
	Temperature inCelsius;
	inCelsius.value = a[fromTemperature.unit] * fromTemperature.value + b[fromTemperature.unit]; 
	return inCelsius;
} 

Temperature TemperatureConvertor:: ConvertFromCelsius(Temperature inCelsius, TemperatureUnit toUnit) {
	Temperature outTemperature;
	outTemperature.value = 1 / a[toUnit] * ( inCelsius.value - b[toUnit]); 
	return outTemperature;
}