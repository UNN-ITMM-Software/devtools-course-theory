#include "AreaConverter.h"
#include "stdio.h"

int main()
{
	AreaConverter Converter;
	Converter.SetAreaType(sMeter);
	Converter.SetValue(100);
	printf("100 merers = %lf foots \n",Converter.Convert(sFoot) );
	return 0;
}