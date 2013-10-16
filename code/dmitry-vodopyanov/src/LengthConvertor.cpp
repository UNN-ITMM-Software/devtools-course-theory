#include "LengthConvertor.h"

LengthConvertor::LengthConvertor(void) {}

LengthConvertor::~LengthConvertor(void) {}

Length LengthConvertor::Convert(Length length, Unit UnitOutput)
{
	double multiplier[7][7] = {{1,         0.0833,  0.0278,   0.0000158,  0.0254,   0.0000254, 2.54},
                                   {12,        1,       0.333,    0.000189,   0.305,    0.000305,  30.48},
                                   {36,        3,       1,        0.000568,   0.914,    0.000914,  91.44},
                                   {63360,     5280,    1760,     1,          1609.344, 1.609344,  160934.4},
                                   {39.37,     3.281,   1.094,    0.000621,   1,        0.001,     100},
                                   {39370.079, 3280.84, 1093.613, 0.621,      1000,     1,         100000},
                                   {0.394,     0.0328,  0.0109,   0.00000621, 0.01,     0.00001,   1}};
	if (length.value > 0)
	{
		length.value= multiplier[length.UnitInput][UnitOutput]*length.value;
		return length;
	}
	else
	{
		length.value = -1;
		return length;
	}	
}