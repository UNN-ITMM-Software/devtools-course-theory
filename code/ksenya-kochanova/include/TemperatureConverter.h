/* Copyright 2013 Ksenya Kochanova */

enum TemperatureUnit {Celsius, Kelvin, Fahrenheit, Newton};

struct Temperature
{
	double value;
	TemperatureUnit unit;
};

static double a[4] = {1, 1, 5/9, 100/33};
static double b[4] = {0, -273.15, -32, 0};	

class TemperatureConvertor
{		
public:
	TemperatureConvertor(void);
	~TemperatureConvertor(void);

	Temperature ConvertToCelsius(Temperature fromTemperature);
	Temperature ConvertFromCelsius(Temperature inCelsius, TemperatureUnit toUnit); 
};
