#include <iostream>
#include <cstdio>
#include "TemperatureConverter.h"

using namespace std;


int main()
{
	Temperature temperature;
	Temperature temperature_;
	TemperatureConvertor convertor;
	// For input from keyboard!
	//cout << "Input value and unit of temperature (Celsius, Kelvin, Fahrenheit, Newton)\n";
	//cin >> temperature.value;
	//cin >> temperature.unit;
	//// For example: correct input 10 Kelvin; incorrect input 10 Кельвин. 
	//cout << "Input unit of temperature (Celsius, Kelvin, Fahrenheit, Newton)\n";
	//cin >> temperature_.unit;

	// Constant value
	temperature.value = 100;
	temperature.unit = Kelvin;
	temperature_.unit = Newton;
	Temperature outTemperature = convertor.ConvertTo(temperature, temperature_.unit);
	cout << "Input: 100 Kelvin " << endl;
	cout << "Output: ? Newton" << endl;
	cout << "Result: " << outTemperature.value << endl;
	return 0;
}