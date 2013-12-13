/* Copyright 2013 Andrey Golodyaev */
#include "library/complexcalc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
ComplexNumber::ComplexNumber(): real(0), imaginary(0) {
}
ComplexNumber::ComplexNumber(double _real,
                                     double _imaginary): real(_real),
                                     imaginary(_imaginary) {
}
ComplexNumber::~ComplexNumber() {
}
double ComplexNumber::GetReal() const {
    return real;
}
double ComplexNumber::GetImaginary() const {
    return imaginary;
}
void ComplexNumber::SetReal(double _real) {
    real = _real;
}
void ComplexNumber::SetImaginary(double _imaginary) {
    imaginary = _imaginary;
}
bool ComplexNumber::Input(const char *str) {
    std::string s = str;
    std::string i = "";
    std::basic_string<char>::size_type n = 1;
    std::basic_string<char>::size_type ii = 0;
    int sh = 0;
    int si = 0;
    for (std::basic_string<char>::size_type iii = 0;
         iii < s.length(); iii++) {
        if (s[iii] == 'i') si++;
        if (s[iii] == '*' || s[iii] == '/') sh++;
        if ((si > 1) || (sh > 1) || (((s[iii] < '0') ||(s[iii] > '9'))
            && (s[iii] != 'i')
            && (s[iii] != '+') && (s[iii] != '-') && (s[iii] != '*')
            && (s[iii] != '/'))) {
            return false;
        }
    }
    int qr = 1, qi = 1;
    if (s[0] != '+' && s[0] != '-') s = "+"+s;
    s = s+' ';
    n = s.find('i');
    if (si > 0 && n > 0) {
        while (s[n-ii] != '+' && s[n-ii] != '-') {
            i = s[n-ii]+i;
            ii++;
        }
        if (s[n-ii] == '-') qi = -1;
        ii = 0;
        while (s[n+ii] != '+' && s[n+ii] != '-' && s[n+ii] != ' ') {
            i = i+s[n+ii];
            ii++;
            if (n+ii == s.length()) break;
        }
        i.erase(i.find('i'), 1);
        if (i.find("i") > 0 && i.find("i") < i.length()-1) {
            return false;
        }
        s.erase(s.find(i)-1, i.length()+1);
        i.erase(i.find('i'), 1);
        if (sh > 0) i.erase(i.find('*'), 1);
        if (sh > 0 && i == "") {
            return false;
        }
        if (i == "") imaginary = 1;
        else
            try {
                imaginary = atof(i.c_str());
            }
            catch(...) {
                return false;
            }
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
        try {
            real = atof(s.c_str());
        }
        catch(...) {
            return false;
        }
    real*=qr;
    return true;
}
void ComplexNumber::Output(char *str) {
    std::string str1 = "";
    double ep = 0.00001;
    double ep2 = 1.0000;
    if (real > ep || real < -ep) {
        std::ostringstream ss;
        ss << real;
        str1 = ss.str();
    }
    if (imaginary > ep || imaginary < -ep) {
        if (imaginary < 0) str1+='-';
        else
            if (real > ep || real < -ep) str1+='+';
        if (imaginary > ep2 || imaginary < -ep2) {
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
    if (real < ep && real > -ep &&
        imaginary < ep && imaginary > -ep) str1 = "0";
    strncpy(str, (str1.c_str()), str1.length());
}
const ComplexNumber ComplexNumber::operator +(const ComplexNumber &second) {
    ComplexNumber temp(0, 0);
    temp.real = GetReal()+second.GetReal();
    temp.imaginary = GetImaginary()+second.GetImaginary();
    return temp;
}
const ComplexNumber ComplexNumber::operator -(const ComplexNumber &second) {
    ComplexNumber temp(0, 0);
    temp.real = GetReal()-second.GetReal();
    temp.imaginary = GetImaginary()-second.GetImaginary();
    return temp;
}
const ComplexNumber ComplexNumber::operator *(const ComplexNumber &second) {
    ComplexNumber temp(0, 0);
    temp.real = GetReal()*second.GetReal()
                -GetImaginary()*second.GetImaginary();
    temp.imaginary = GetReal()*second.GetImaginary()
                     +GetImaginary()*second.GetReal();
    return temp;
}
const ComplexNumber ComplexNumber::operator /(const ComplexNumber &second) {
    ComplexNumber temp(0, 0);
    double ep = 0.00001;
    if (second.GetReal()*second.GetReal()
       +second.GetImaginary()*second.GetImaginary() < ep &&
       second.GetReal()*second.GetReal()
       +second.GetImaginary()*second.GetImaginary() > -ep)
           throw std::string("division by zero");
    temp.real = (GetReal()*second.GetReal()
                +GetImaginary()*second.GetImaginary())/
                (second.GetReal()*second.GetReal()
                +second.GetImaginary()*second.GetImaginary());
    temp.imaginary = (GetImaginary()*second.GetReal()
                     -GetReal()*second.GetImaginary())/
                     (second.GetReal()*second.GetReal()
                     +second.GetImaginary()*second.GetImaginary());
    return temp;
}
bool operator ==(const ComplexNumber &second) {
    const double eps = 0.000001;
    if (GetReal()-second.GetReal() < eps &&
        GetReal()-second.GetReal() > -eps &&
        GetImaginary()-second.GetImaginary() < eps &&
        GetImaginary()-second.GetImaginary() > -eps)
        return true;
    return false;
}
