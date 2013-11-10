/* Copyright 2013 Ksenya Kochanova */
#include <TemperatureConverter.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cstdio>

TemperatureConvertor::TemperatureConvertor(void) {}

TemperatureConvertor::~TemperatureConvertor(void) {}

Temperature TemperatureConvertor::ConvertToCelsius(int flag, Temperature
fromTemperature) {
    double a[4] = {1, 1, 5/9, 100/33};
    double b[4] = {0, -273.15, -32, 0};
    Temperature inCelsius;
    if ((fromTemperature.unit == 0)&&(fromTemperature.value < -273.15)) {
         flag = 0;
         inCelsius.value = 0;
    }
    if ((fromTemperature.unit == 1)&&(fromTemperature.value < 0)) {
         flag = 0;
         inCelsius.value = 0;
    }
    if ((fromTemperature.unit == 2)&&(fromTemperature.value < -459.67)) {
         flag = 0;
         inCelsius.value = 0;
    }
    if ((fromTemperature.unit == 3)&&(fromTemperature.value < -90.14)) {
         flag = 0;
         inCelsius.value = 0;
    } else {
        inCelsius.value = a[fromTemperature.unit] * fromTemperature.value
+ b[fromTemperature.unit];
     }
    return inCelsius;
}
Temperature TemperatureConvertor:: ConvertFromCelsius(int flag,
Temperature inCelsius, TemperatureUnit toUnit) {
    double a[4] = {1, 1, 5/9, 100/33};
    double b[4] = {0, -273.15, -32, 0};
    Temperature outTemperature;
    if (flag == 0) {
        printf("Erorr");
        exit(0);
        outTemperature.value = 12345;
    } else {
        outTemperature.value = 1 / a[toUnit] * (inCelsius.value - b[toUnit]);
    }
    return outTemperature;
}
