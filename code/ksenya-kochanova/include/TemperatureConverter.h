/* Copyright 2013 Ksenya Kochanova */
#include <iostream>
#include <cstdio>
#include "TemperatureConverter.h"

int main() {
    Temperature temperature;
    Temperature newTemperature;
    TemperatureConvertor convertor;
    temperature.value = 0;
    temperature.unit = Kelvin;
    TemperatureUnit newUnit = Newton;
    Temperature inCelsius = convertor.ConvertToCelsius(temperature);
    Temperature outTemperature = convertor.ConvertFromCelsius(inCelsius, 
    newUnit);
    std::cout << "Input: 0 Kelvin " << std::endl;
    std::cout << "Output: ? Newton" << std::endl;
    std::cout << "Result: " << outTemperature.value << std::endl;
    return 0;
}

