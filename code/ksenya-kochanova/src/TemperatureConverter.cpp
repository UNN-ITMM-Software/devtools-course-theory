#include <iostream>
#include "TemperatureConverter.h"


TemperatureConvertor::TemperatureConvertor(void)
{
}
std::istream& operator>>(std::istream& input, TemperatureUnit& newtemp)
{ 
	std::string s;
	bool flag = false;	
	while (flag == false) 
	{

		input >> s;

		if (s == "Kelvin") 
		{
			newtemp = Kelvin;
			flag = true;
			break;
		} 
		if (s == "Celsius") 
		{
			newtemp = Celsius;
			flag = true;
			break;
		} 
		if (s == "Fahrenheit") 
		{
			newtemp = Fahrenheit;
			flag = true;
			break;
		} 
		if (s == "Newton") 
		{
			newtemp = Newton;
			flag = true;
			break;
		} 
		else 
		{
			std::cout << "Incorrect input. Repeat, please." << std::endl; 
			std::cin.clear();
			flag = false;
		}
	}
	return input;
}
Temperature TemperatureConvertor::ConvertTo(Temperature fromTemperature, TemperatureUnit toUnit)
{

	Temperature Out;
	if ((fromTemperature.unit == Celsius)&&(toUnit == Kelvin))
	{
		Out.value = fromTemperature.value + 273.15;
		Out.unit = Kelvin;
	}
	if ((fromTemperature.unit == Celsius)&&(toUnit == Newton))
	{
		Out.value = fromTemperature.value  * 0.33;
		Out.unit = Newton;
	}
	if ((fromTemperature.unit == Celsius)&&(toUnit == Fahrenheit))
	{
		Out.value = fromTemperature.value * (9/5) + 32;
		Out.unit = Fahrenheit;
	}

	if ((fromTemperature.unit == Kelvin)&&(toUnit == Celsius))
	{
		Out.value = fromTemperature.value - 273.15;
		Out.unit = Celsius;
	}
	if ((fromTemperature.unit == Kelvin)&&(toUnit == Newton))
	{
		Out.value = (fromTemperature.value - 273.15) * 0.33;
		Out.unit = Newton;
	}
	if ((fromTemperature.unit == Kelvin)&&(toUnit == Fahrenheit))
	{
		Out.value = (fromTemperature.value - 273.15) * (9/5) + 32;
		Out.unit = Fahrenheit;
	}

	if ((fromTemperature.unit == Newton)&&(toUnit == Celsius))
	{
		Out.value = fromTemperature.value / 0.33 ;
		Out.unit = Celsius;
	}
	if ((fromTemperature.unit == Newton)&&(toUnit == Kelvin))
	{
		Out.value = fromTemperature.value / 0.33 + 273.15;
		Out.unit = Kelvin;
	}
	if ((fromTemperature.unit == Newton)&&(toUnit == Fahrenheit))
	{
		Out.value = fromTemperature.value / 0.33 * (9/5) + 32;
		Out.unit = Fahrenheit;
	}

	if ((fromTemperature.unit == Fahrenheit)&&(toUnit == Celsius))
	{
		Out.value = (fromTemperature.value - 32)  / (9/5);
		Out.unit = Celsius;
	}
	if ((fromTemperature.unit == Fahrenheit)&&(toUnit == Kelvin))
	{
		Out.value = (fromTemperature.value - 32)  / (9/5) + 273.15;
		Out.unit = Kelvin;
	}
	if ((fromTemperature.unit == Fahrenheit)&&(toUnit == Newton))
	{
		Out.value = ((fromTemperature.value - 32)  / (9/5)) * 0.33;
		Out.unit = Newton;
	}
	return Out;
}
TemperatureConvertor::~TemperatureConvertor(void)
{
}
