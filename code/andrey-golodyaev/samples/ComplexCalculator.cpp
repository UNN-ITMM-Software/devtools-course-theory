#include "complexcalc.h"
//#include "conio.h"
#include "stdio.h"

int main()
{
	ComplexCalculator a(1,1);
	ComplexCalculator b(1,2);
	ComplexCalculator c(0,0);
	char str[35]="";
	a.Output(str);
	printf("A=%s\n",str);
	b.Output(str);
	printf("B=%s\n",str);
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
