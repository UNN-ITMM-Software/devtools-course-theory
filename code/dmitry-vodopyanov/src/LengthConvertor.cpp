#include "LengthConvertor.h"

LengthConvertor::LengthConvertor(void) {}

LengthConvertor::~LengthConvertor(void) {}

Length LengthConvertor::Convert(Length length, LengthUnit UnitOutput)
{
	double multiplierToMeter[7] = {0.0254, 0.305, 0.914, 1609.344, 1, 1000, 0.01};
	double multiplierFromMeter[7] = {39.37, 3.281, 1.094, 0.000621, 1, 0.001, 100};
	if (length.value > 0)
	{
		length.value = multiplierToMeter[length.UnitInput]*multiplierFromMeter[UnitOutput]*length.value;
		return length;
	}
	else
	{
		length.value = -1;
		return length;
	}	
}