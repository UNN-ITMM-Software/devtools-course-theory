/* Copyright 2013 Andrey Golodyaev */
#include <complexcalc.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
ComplexCalculator::ComplexCalculator(double _real, double _imaginary): real(_real), imaginary(_imaginary) {
}
ComplexCalculator::~ComplexCalculator() {
}
double ComplexCalculator::GetReal() {
    return real;
}
double ComplexCalculator::GetImaginary() {
    return imaginary;
}
void ComplexCalculator::SetReal(double _real) {
    real = _real;
}
void ComplexCalculator::SetImaginary(double _imaginary) {
    imaginary = _imaginary;
}
void ComplexCalculator::Input(char *str) {
    std::string s = str;
    std::string i = "";
    std::basic_string<char>::size_type n = 1;
    std::basic_string<char>::size_type ii = 0;
    int qr = 1, qi = 1;
    if (s[0] != '+' && s[0] != '-') s = "+"+s;
    n = s.find('i');
    if (n != -1) {
        while (s[n-ii] != '+' && s[n-ii] != '-') {
            i = s[n-ii]+i;
            ii++;
        }
        if (s[n-ii] == '-') qi = -1;
        ii = 0;
        while (s[n+ii] != '+' && s[n+ii] != '-') {
            i = i+s[n+ii];
            ii++;
            if (n+ii == s.length()) break;
        }
        i.erase(i.find('i'), 1);
        s.erase(s.find(i), i.length());
        i.erase(i.find('i'), 1);
        if (i.find('*') > 0) i.erase(i.find('*'), 1);
        if (i == "") imaginary = 1;
        else
            imaginary = atof(i.c_str());
        imaginary*=qi;
    } else {
        imaginary = 0;
    }
    if (s[0] == '-') qr = -1;
    ii = 0;
    while (ii != s.length()) {
        if (s[ii] == '+' || s[ii] == '-') s.erase(ii, 1);
        else
            ii++;
    }
    if (s == "") real = 0;
    else
        real = atof(s.c_str());
    real*=qr;
}
void ComplexCalculator::Output(char *str) {
    std::string str1 = "";
    if (real != 0) {
        std::ostringstream ss;
        ss << real;
        str1 = ss.str();
    }
    if (imaginary != 0) {
        if (imaginary < 0) str1+='-';
        else
            if (real != 0) str1+='+';
        if (imaginary != 1) {
            std::ostringstream sss;
            if (imaginary > 0)
                sss << (imaginary);
            else
                sss << (-imaginary);
            str1+=sss.str();
            str1+="*";
        }
        str1+="i";
    }
    if (real == 0 && imaginary == 0) str1 = "0";
    strncpy(str, (str1.c_str()), str1.length());
}
ComplexCalculator ComplexCalculator::Add(ComplexCalculator first,
                                         ComplexCalculator second) {
    ComplexCalculator temp(0, 0);
    temp.real = first.GetReal()+second.GetReal();
    temp.imaginary = first.GetImaginary()+second.GetImaginary();
    return temp;
}
ComplexCalculator ComplexCalculator::Sub(ComplexCalculator first,
                                         ComplexCalculator second) {
    ComplexCalculator temp(0, 0);
    temp.real = first.GetReal()-second.GetReal();
    temp.imaginary = first.GetImaginary()-second.GetImaginary();
    return temp;
}
ComplexCalculator ComplexCalculator::Multi(ComplexCalculator first,
                                           ComplexCalculator second) {
    ComplexCalculator temp(0, 0);
    temp.real = first.GetReal()*second.GetReal()
                -first.GetImaginary()*second.GetImaginary();
    temp.imaginary = first.GetReal()*second.GetImaginary()
                     +first.GetImaginary()*second.GetReal();
    return temp;
}
ComplexCalculator ComplexCalculator::Div(ComplexCalculator first,
                                         ComplexCalculator second) {
    ComplexCalculator temp(0, 0);
    temp.real = (first.GetReal()*second.GetReal()
                +first.GetImaginary()*second.GetImaginary())/
                (second.GetReal()*second.GetReal()
                +second.GetImaginary()*second.GetImaginary());
    temp.imaginary = (first.GetImaginary()*second.GetReal()
                     -first.GetReal()*second.GetImaginary())/
                     (second.GetReal()*second.GetReal()
                     +second.GetImaginary()*second.GetImaginary());
    return temp;
}
