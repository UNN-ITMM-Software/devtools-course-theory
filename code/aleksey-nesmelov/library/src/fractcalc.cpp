/* Copyright 2013 Nesmelov Aleksey */
#include "library/fractcalc.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>

Fraction::Fraction(int _numenator,
                   int _denominator): numenator(_numenator),
                                      denominator(_denominator) {
    if (_denominator == 0) {
    throw std::string("wrong denominator");
    } else {
        if (denominator < 0) {
            numenator = -numenator;
            denominator = abs(denominator);
        }
    }
}

Fraction::Fraction(const Fraction& other) {
    *this = other;
}

Fraction::Fraction(): numenator(), denominator() {
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
        throw std::string("wrong denominator");
    } else {
    denominator = value;
    }
}

Fraction& Fraction::operator=(const Fraction& a) {
    if (this != &a) {  // protect against invalid self-assignment
        numenator = a.numenator;
        denominator = a.denominator;
    }
    // by convention, always return *this
    return *this;
}

bool Fraction::operator==(const Fraction& a) const {
    if (numenator == a.numenator &&
        denominator == a.denominator) {
        return true;
    }
    return false;
}
Fraction Fraction::operator+(const Fraction& a) const {
    Fraction res(numenator * a.denominator + denominator * a.numenator,
        denominator * a.denominator);
    res.CutFraction();
    return res;
}
Fraction Fraction::operator-(const Fraction& a) const {
    Fraction res(numenator * a.denominator - denominator * a.numenator,
        denominator * a.denominator);
    res.CutFraction();
    return res;
}
Fraction Fraction::operator*(const Fraction& a) const {
    Fraction res(numenator * a.numenator, denominator * a.denominator);
    res.CutFraction();
    if (res.denominator < 0) {
        res.numenator = - res.numenator;
        res.denominator = abs(res.denominator);
    }
    return res;
}
Fraction Fraction::operator/(const Fraction& a) const {
    Fraction res(0, 1);
    if (a.numenator == 0) {
        throw std::string("wrong divisor");
    } else {
        res.SetNumenator(numenator * a.denominator);
        res.SetDenominator(denominator * a.numenator);
        res.CutFraction();
        if (res.denominator < 0) {
            res.numenator = -res.numenator;
            res.denominator = abs(res.denominator);
        }
    }
    return res;
}





