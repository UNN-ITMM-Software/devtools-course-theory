#include "QuadraticEquation.h"
#include <stdio.h>

int main(void)
{
	double r1, r2;
	int returnCode;
    QuadraticEquation Sample;

	Sample.SetCoefficients(2.1, 3.1, -7.8);
	returnCode = Sample.Solve(r1, r2);
	printf("2.1x^2 + 3.1x - 7.8 = 0\n");
	if(returnCode == TWOROOTS || returnCode == ONEROOT)
	{
		printf("Root 1: %.3f\n", r1);
		printf("Root 2: %.3f\n", r2);
	}
	else
		printf("illegal coefficients\n");

	Sample.SetCoefficients(1, 2, 1);
	returnCode = Sample.Solve(r1, r2);
	printf("\nx^2 + 2x + 1 = 0\n");
	if(returnCode == TWOROOTS || returnCode == ONEROOT)
	{
		printf("Root 1: %.3f\n", r1);
		printf("Root 2: %.3f\n", r2);
	}
	else
		printf("illegal coefficients\n");

	Sample.SetCoefficients(1, 0, 1);
	returnCode = Sample.Solve(r1, r2);
	printf("\nx^2 + 1 = 0\n");
	if(returnCode == TWOROOTS || returnCode == ONEROOT)
	{
		printf("Root 1: %.3f\n", r1);
		printf("Root 2: %.3f\n", r2);
	}
	else
		printf("illegal coefficients\n");
	return(0);
}