/* Copyright 2013 Ksenya Kochanova */
#include <TemperatureConverter.h>
#include <cstdio>
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
    printf("Unit of temperature: \n");
    printf(" 0 - Celsius,\n 1 - kelvin,\n 2 - Fahrenheit, \n 3 - Newton \n");
    printf("Input: %lf %d \n", temperature.value, temperature.unit);
    printf("Output: ? %d\n", newUnit);
    printf("Result: %lf\n", outTemperature.value);
    return 0;
}
