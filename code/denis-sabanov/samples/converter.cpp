#include "AreaConverter.h"
#include "stdio.h"

int main(){
	AreaConverter Converter;
	Converter.SetAreaType(sKilometer);
	Converter.SetValue(100);
	printf("100 merers = %lf foots \n",Converter.ConvertToNewType(sFoot) );
	return 0;
}
