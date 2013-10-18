#include <iostream>
#include <string>
#pragma once

enum TemperatureUnit {Celsius, Kelvin, Fahrenheit, Newton};
struct Temperature
{
	double value;
	TemperatureUnit unit;
};

class TemperatureConvertor
{
	friend std::istream& operator>>(std::istream& input, TemperatureUnit& newtemp);
public:
	TemperatureConvertor(void);
	virtual ~TemperatureConvertor(void);
	Temperature ConvertTo(Temperature fromTemperature,TemperatureUnit toUnit);
};
