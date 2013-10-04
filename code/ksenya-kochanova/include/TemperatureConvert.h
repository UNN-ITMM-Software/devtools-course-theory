#pragma once

struct Temperature
{
	enum  {Celsiy, Kelvin, Farengate, Newton};
	double value;
}
class TemperatureConvert
{
	enum Unit {Celsiy, Kelvin, Farengate, Newton};
public:
	TemperatureConvert(void);
	Temperature ConvertTemperature(Temperature fromTemperature, Unit toUnit);
	virtual ~TemperatureConvert(void);
};

