/* Copyright 2013 Nesmelov Aleksey */
#include <fractcalc.h>

#include <stdio.h>

int main() {
    Fraction fract1(1, 3);
    Fraction fract2(-1, 2);
    Fraction fractResult(0, 1);

    printf ("\nA = %d/%d", fract1.GetNumenator(), fract1.GetDenominator());
    printf ("\nB = %d/%d", fract2.GetNumenator(), fract2.GetDenominator());
    printf("\n"); 

    fractResult = Fraction::Add(fract1, fract2);
    printf ("\nA+B = %d/%d",fractResult.GetNumenator(), fractResult.GetDenominator());

    fractResult = Fraction::Subtract(fract1, fract2);
    printf ("\nA-B = %d/%d",fractResult.GetNumenator(), fractResult.GetDenominator());

    fractResult = Fraction::Multiply(fract1, fract2);
    printf ("\nA*B = %d/%d",fractResult.GetNumenator(), fractResult.GetDenominator());

    fractResult = Fraction::Divide(fract1, fract2);
    printf ("\nA/B = %d/%d",fractResult.GetNumenator(), fractResult.GetDenominator());

	return 0;
}