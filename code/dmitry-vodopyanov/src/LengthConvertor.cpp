#include "LengthConvertor.h"

LengthConvertor::LengthConvertor(void) {}

LengthConvertor::~LengthConvertor(void) {}

Length LengthConvertor::Convert(Length length, LengthUnit UnitOutput)
{
	double multiplierToMeter[7] = {0.0253999998, 0.3048, 0.914399999, 1609.34401, 1, 1000, 0.01};
	double multiplierFromMeter[7] = {39.370079, 3.2808399, 1.0936133, 0.00062137119, 1, 0.001, 100};
	if (length.value >= 0)
		length.value = multiplierToMeter[length.UnitInput]*multiplierFromMeter[UnitOutput]*length.value;
	else
		length.value = -1;	
	return length;
}