#include "LengthConvertor.h"
#include <iostream>

using namespace std;

LengthConvertor::LengthConvertor() {}

LengthConvertor::~LengthConvertor() {}

void LengthConvertor::help()
{
	cout << "LENGTH CONVERTOR" << endl;
	cout << "Enter a number, the dimention of the list below, and finite dimention." << std::endl;
	cout << "  Inch as IN" << endl <<
				 "  Foot as FT" << endl <<
				 "  Yard as YD" << endl <<
				 "  Mile as ML" << endl <<
				 "  Meter as M" << endl <<
				 "  Kilometer KM" << endl <<
				 "  Centimeter as CM" << endl;
	std::cout << "  Or press ALL to watch all values of all dimention." << std::endl;
}

double LengthConvertor::ToInch(double num, char* unit)
{
	double convnum;

	if (unit == "IN")
	{ convnum = num; }

	if (unit == "FT")
	{ convnum = 12*num; }

	if (unit == "YD")
	{ convnum = 36*num; }

	if (unit == "ML")
	{ convnum = 63360*num; }

	if (unit == "M")
	{ convnum = 39.37*num; }

	if (unit == "KM")
	{ convnum = 39370.079*num; }

	if (unit == "CM")
	{ convnum = 0.394*num; }

	return convnum;
}

double LengthConvertor::ToFoot(double num, char* unit)
{
	double convnum;

	if (unit == "IN")
	{ convnum = 0.0833*num; }

	if (unit == "FT")
	{ convnum = num; }

	if (unit == "YD")
	{ convnum = 3*num; }

	if (unit == "ML")
	{ convnum = 5280*num; }

	if (unit == "M")
	{ convnum = 3.281*num; }

	if (unit == "KM")
	{ convnum = 3280.84*num; }

	if (unit == "CM")
	{ convnum = 0.0328*num; }

	return convnum;
}

double LengthConvertor::ToYard(double num, char* unit)
{
	double convnum;

	if (unit == "IN")
	{ convnum = 0.0278*num; }

	if (unit == "FT")
	{ convnum = 0.333*num; }

	if (unit == "YD")
	{ convnum = num; }

	if (unit == "ML")
	{ convnum = 1760*num; }

	if (unit == "M")
	{ convnum = 1.094*num; }

	if (unit == "KM")
	{ convnum = 1093.613*num; }

	if (unit == "CM")
	{ convnum = 0.0109*num; }

	return convnum;
}

double LengthConvertor::ToMile(double num, char* unit)
{
	double convnum;

	if (unit == "IN")
	{ convnum = 0.0000158*num; }

	if (unit == "FT")
	{ convnum = 0.000189*num; }

	if (unit == "YD")
	{ convnum = 0.000568*num; }

	if (unit == "ML")
	{ convnum = num; }

	if (unit == "M")
	{ convnum = 0.000621*num; }

	if (unit == "KM")
	{ convnum = 0.621*num; }

	if (unit == "CM")
	{ convnum = 0.00000621*num; }

	return convnum;
}

double LengthConvertor::ToMeter(double num, char* unit)
{
	double convnum;

	if (unit == "IN")
	{ convnum = 0.0254*num; }

	if (unit == "FT")
	{ convnum = 0.305*num; }

	if (unit == "YD")
	{ convnum = 0.914*num; }

	if (unit == "ML")
	{ convnum = 1609.344*num; }

	if (unit == "M")
	{ convnum = num; }

	if (unit == "KM")
	{ convnum = 1000*num; }

	if (unit == "CM")
	{ convnum = 0.01*num; }

	return convnum;
}

double LengthConvertor::ToKMeter(double num, char* unit)
{
	double convnum;

	if (unit == "IN")
	{ convnum = 0.0000254*num; }

	if (unit == "FT")
	{ convnum = 0.000305*num; }

	if (unit == "YD")
	{ convnum = 0.000914*num; }

	if (unit == "ML")
	{ convnum = 1.609*num; }

	if (unit == "M")
	{ convnum = 0.001*num; }

	if (unit == "KM")
	{ convnum = num; }

	if (unit == "CM")
	{ convnum = 0.00001*num; }

	return convnum;
}

double LengthConvertor::ToCMeter(double num, char* unit)
{
	double convnum;

	if (unit == "IN")
	{ convnum = 2.54*num; }

	if (unit == "FT")
	{ convnum = 30.48*num; }

	if (unit == "YD")
	{ convnum = 91.44*num; }

	if (unit == "ML")
	{ convnum = 160934.4*num; }

	if (unit == "M")
	{ convnum = 100*num; }

	if (unit == "KM")
	{ convnum = 100000*num; }

	if (unit == "CM")
	{ convnum = num; }

	return convnum;
}