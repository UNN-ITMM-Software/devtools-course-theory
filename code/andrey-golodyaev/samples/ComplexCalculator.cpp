#include "complexcalc.h"
//#include "conio.h"
#include "stdio.h"

int main()
{
	ComplexCalculator a(1,1);
	ComplexCalculator b(2,2);
	ComplexCalculator c(0,0);
	char str[35]="";
	printf("A=");
	scanf("%s",str);
	a.Input(str);
	printf("B=");
	scanf("%s",str);
	b.Input(str);
	printf("\n");
	c=ComplexCalculator::Add(a,b);
	c.Output(str);
	printf("A+B=%s\n",str);
	c=ComplexCalculator::Sub(a,b);
	c.Output(str);
	printf("A-B=%s\n",str);
	c=ComplexCalculator::Multi(a,b);
	c.Output(str);
	printf("A*B=%s\n",str);
	c=ComplexCalculator::Div(a,b);
	c.Output(str);
	printf("A/B=%s\n",str);
	//getch();
	return 0;
}
