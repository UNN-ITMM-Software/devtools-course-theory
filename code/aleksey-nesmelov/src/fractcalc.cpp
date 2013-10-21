/* Copyright 2013 Nesmelov Aleksey */
#include <fractcalc.h>
#include <iostream>
#include "stdlib.h"

using namespace std; 

Fraction::Fraction(int _numenator, int _denominator) {
  numenator = _numenator;
  denominator = _denominator;
   if (denominator < 0)
   {
	numenator = -numenator;
    denominator = abs(denominator);
   }
}
Fraction::~Fraction() {}

int Fraction::NOD() {
   int a = abs(numenator);
   int b = abs(denominator);
 if (a != 0 && b != 0)
 { 
	 while (a%b != 0 && b%a != 0)
     {
	   if (a > b)
       a = a%b;
       else
       b = b%a;
     }
  if (a > b)
  return b;
  return a;
 }
 else
  {
   if (a == 0 && b == 0)
   return 1;
   else
	if (a == 0)
		return b;
	else
		return a;
  }
}

void Fraction::Cut_Fraction() {
  int nod = NOD();
  numenator = numenator / nod;
  denominator = denominator / nod;
}

int Fraction::GetNumenator() {
	return numenator;
 }
int Fraction::GetDenominator() {
	 return denominator;
 }
void Fraction::SetNumenator(int new_numenator) {
	 numenator = new_numenator;
 }
void Fraction::SetDenominator(int new_denominator) {
	 denominator = new_denominator;
 }


Fraction Fraction::Add(Fraction a, Fraction b) {
 Fraction res(a.numenator * b.denominator + a.denominator * b.numenator,a.denominator * b.denominator);
 res.Cut_Fraction();
 return res;
}

Fraction Fraction::Subtract(Fraction a, Fraction b) {
 Fraction res(a.numenator * b.denominator - a.denominator * b.numenator,a.denominator * b.denominator);
 res.Cut_Fraction();
 return res;
}


Fraction Fraction::Multiply(Fraction a, Fraction b) {
 Fraction res(a.numenator * b.numenator,a.denominator * b.denominator);
 res.Cut_Fraction();
   if (res.denominator < 0)
   {
	res.numenator = - res.numenator;
    res.denominator = abs(res.denominator);
   }
 return res;
}

Fraction Fraction::Divide(Fraction a, Fraction b) {
Fraction res(a.numenator * b.denominator,a.denominator * b.numenator);
res.Cut_Fraction();
  if (res.denominator < 0)
  {
   res.numenator = - res.numenator;
   res.denominator = abs(res.denominator);
  }
return res;
}





