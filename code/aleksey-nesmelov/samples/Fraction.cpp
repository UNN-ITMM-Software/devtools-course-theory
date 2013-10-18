#include "fractcalc.h"
#include "stdio.h"

int main()
{
 Fraction fract_1(1,3);
 Fraction fract_2(-1,2);
 Fraction fract_res(0,1);

 printf ("\nA = %d/%d",fract_1.GetNumenator(),fract_1.GetDenominator());
 printf ("\nB = %d/%d",fract_2.GetNumenator(),fract_2.GetDenominator());
 printf("\n");

 fract_res=Fraction::Add(fract_1,fract_2);
 printf ("\nA+B = %d/%d",fract_res.GetNumenator(),fract_res.GetDenominator());

 fract_res=Fraction::Subtract(fract_1,fract_2);
 printf ("\nA-B = %d/%d",fract_res.GetNumenator(),fract_res.GetDenominator());

 fract_res=Fraction::Multiply(fract_1,fract_2);
 printf ("\nA*B = %d/%d",fract_res.GetNumenator(),fract_res.GetDenominator());

 fract_res=Fraction::Divide(fract_1,fract_2);
 printf ("\nA/B = %d/%d",fract_res.GetNumenator(),fract_res.GetDenominator());

	return 0;
}