
#pragma once

enum Unit {Celsius, Kelvin, Fahrenheit, Newton};

struct Temperature
{
public:
	double myValue;
	Unit myUnit;
};
class TemperatureConverter
{

public:
	Temperature t;
	TemperatureConverter(void);
	virtual ~TemperatureConverter(void);	
	Temperature ConvertTemperature(Temperature fromTemperature,Unit toUnit);

};

