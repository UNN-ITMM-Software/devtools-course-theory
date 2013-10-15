#include "LengthConvertor.h"
#include "stdio.h"

int main()
{
	LengthConvertor convertor;
	Length length;
	length.value = 6; length.UnitInput = Inch;
	printf("6 inches = %lf meters\n", convertor.Convert(length, Meter).value);
	length.value = 45.6; length.UnitInput = KMeter;
	printf("45.6 kilometers = %lf yards\n", convertor.Convert(length, Yard).value);
	length.value = -7; length.UnitInput = KMeter;
	printf("-7 kilometers = %lf yards\n", convertor.Convert(length, Yard).value); //Incorrect input, returns 0
	return 0;
}