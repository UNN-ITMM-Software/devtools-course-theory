/* Copyright 2013 Nesmelov Aleksey */
#include <fractcalc.h>
#include <stdlib.h>
#include <stdio.h>
Fraction::Fraction(int _numenator,
                   int _denominator): numenator(_numenator),
                                      denominator(_denominator) {
    if (_denominator == 0) {
    throw "wrong denominator";
    } else {
        if (denominator < 0) {
            numenator = -numenator;
            denominator = abs(denominator);
        }
    }
}
Fraction::~Fraction() {}
int Fraction::NOD() {
    int a = abs(numenator);
    int b = abs(denominator);
    if (a != 0 && b != 0) {
        while (a%b != 0 && b%a != 0) {
            if (a > b) a = a%b;
            else
                b = b%a;
        }
    if (a > b)
    return b;
    return a;
    } else {
        if (a == 0 && b == 0)
        return 1;
        else
            if (a == 0)
            return b;
            else
            return a;
    }
}
void Fraction::CutFraction() {
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
void Fraction::SetNumenator(int value) {
    numenator = value;
}
void Fraction::SetDenominator(int value) {
    if (value == 0) {
        printf("Denominator cannot be zero!\n");
        throw "wrong denominator";
    } else {
    denominator = value;
    }
}
Fraction Fraction::Add(Fraction a, Fraction b) {
    Fraction res(a.numenator * b.denominator + a.denominator * b.numenator,
        a.denominator * b.denominator);
    res.CutFraction();
    return res;
}
Fraction Fraction::Subtract(Fraction a, Fraction b) {
    Fraction res(a.numenator * b.denominator - a.denominator * b.numenator,
        a.denominator * b.denominator);
    res.CutFraction();
    return res;
}
Fraction Fraction::Multiply(Fraction a, Fraction b) {
    Fraction res(a.numenator * b.numenator, a.denominator * b.denominator);
    res.CutFraction();
    if (res.denominator < 0) {
        res.numenator = - res.numenator;
        res.denominator = abs(res.denominator);
    }
    return res;
}
Fraction Fraction::Divide(Fraction a, Fraction b) {
    Fraction res(0, 1);
    if (b.numenator == 0) {
        throw "wrong divisor";
    } else {
        res.SetNumenator(a.numenator * b.denominator);
        res.SetDenominator(a.denominator * b.numenator);
        res.CutFraction();
        if (res.denominator < 0) {
            res.numenator = -res.numenator;
            res.denominator = abs(res.denominator);
        }
    }
    return res;
}





