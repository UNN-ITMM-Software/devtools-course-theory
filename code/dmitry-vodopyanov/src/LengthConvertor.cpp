#include "LengthConvertor.h"

using namespace std;

LengthConvertor::LengthConvertor(void) {}

LengthConvertor::~LengthConvertor(void) {}

Length LengthConvertor::Convert(Length length, Unit UnitOutput)
{
	double multiplier = 1;
	switch (UnitOutput)
	{
	case Inch:
		{
			switch (length.UnitInput)
			{
			case Inch:
				{
					multiplier = 1;
					break;
				}
			case Foot:
				{
					multiplier = 12;
					break;
				}
			case Yard:
				{
					multiplier = 36;
					break;
				}
			case Mile:
				{
					multiplier = 63360;
					break;
				}
			case Meter:
				{
					multiplier = 39.37;
					break;
				}
			case KMeter:
				{
					multiplier = 39370.079;
					break;
				}
			case CMeter:
				{
					multiplier = 0.394;
					break;
				}
			}
			break;
		}
	case Foot:
		{
			switch (length.UnitInput)
			{
			case Inch:
				{
					multiplier = 0.0833;
					break;
				}
			case Foot:
				{
					multiplier = 1;
					break;
				}
			case Yard:
				{
					multiplier = 3;
					break;
				}
			case Mile:
				{
					multiplier = 5280;
					break;
				}
			case Meter:
				{
					multiplier = 3.281;
					break;
				}
			case KMeter:
				{
					multiplier = 3280.84;
					break;
				}
			case CMeter:
				{
					multiplier = 0.0328;
					break;
				}
			}
			break;
		}
	case Yard:
		{
			switch (length.UnitInput)
			{
			case Inch:
				{
					multiplier = 0.0278;
					break;
				}
			case Foot:
				{
					multiplier = 0.333;
					break;
				}
			case Yard:
				{
					multiplier = 1;
					break;
				}
			case Mile:
				{
					multiplier = 1760;
					break;
				}
			case Meter:
				{
					multiplier = 1.094;
					break;
				}
			case KMeter:
				{
					multiplier = 1093.613;
					break;
				}
			case CMeter:
				{
					multiplier = 0.0109;
					break;
				}
			}
			break;			
		}
	case Mile:
		{
			switch (length.UnitInput)
			{
			case Inch:
				{
					multiplier = 0.0000158;
					break;
				}
			case Foot:
				{
					multiplier = 0.000189;
					break;
				}
			case Yard:
				{
					multiplier = 0.000568;
					break;
				}
			case Mile:
				{
					multiplier = 1;
					break;
				}
			case Meter:
				{
					multiplier = 0.000621;
					break;
				}
			case KMeter:
				{
					multiplier = 0.621;
					break;
				}
			case CMeter:
				{
					multiplier = 0.00000621;
					break;
				}
			}
			break;		
		}
	case Meter:
		{
			switch (length.UnitInput)
			{
			case Inch:
				{
					multiplier = 0.0254;
					break;
				}
			case Foot:
				{
					multiplier = 0.305;
					break;
				}
			case Yard:
				{
					multiplier = 0.914;
					break;
				}
			case Mile:
				{
					multiplier = 1609.344;
					break;
				}
			case Meter:
				{
					multiplier = 1;
					break;
				}
			case KMeter:
				{
					multiplier = 1000;
					break;
				}
			case CMeter:
				{
					multiplier = 0.01;
					break;
				}
			}
			break;
		}
	case KMeter:
		{
			switch (length.UnitInput)
			{
			case Inch:
				{
					multiplier = 0.0000254;
					break;
				}
			case Foot:
				{
					multiplier = 0.000305;
					break;
				}
			case Yard:
				{
					multiplier = 0.000914;
					break;
				}
			case Mile:
				{
					multiplier = 1.609344;
					break;
				}
			case Meter:
				{
					multiplier = 0.001;
					break;
				}
			case KMeter:
				{
					multiplier = 1;
					break;
				}
			case CMeter:
				{
					multiplier = 0.00001;
					break;
				}
			}
			break;
		}
	case CMeter:
		{
			switch (length.UnitInput)
			{
			case Inch:
				{
					multiplier = 2.54;
					break;
				}
			case Foot:
				{
					multiplier = 30.48;
					break;
				}
			case Yard:
				{
					multiplier = 91.44;
					break;
				}
			case Mile:
				{
					multiplier = 160934.4;
					break;
				}
			case Meter:
				{
					multiplier = 100;
					break;
				}
			case KMeter:
				{
					multiplier = 100000;
					break;
				}
			case CMeter:
				{
					multiplier = 1;
					break;
				}
			}
			break;		
		}
	}
	if (length.value > 0)
	{
		
		length.value= multiplier*length.value;
		return length;
	}
	else
	{
		length.value = 0;
		return length;
	}
}