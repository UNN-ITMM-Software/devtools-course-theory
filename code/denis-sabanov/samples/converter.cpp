#include "AreaConverter.h"
#include "stdio.h"

int main(){
	AreaConverter Converter(100, sKilometer);
	printf("100 kilomerers = %lf foots \n",Converter.ConvertToNewType(sFoot) );
	return 0;
}
