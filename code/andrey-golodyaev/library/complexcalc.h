/* Copyright 2013 Andrey Golodyaev */
#ifndef CODE_ANDREY_GOLODYAEV_LIBRARY_COMPLEXCALC_H_
#define CODE_ANDREY_GOLODYAEV_LIBRARY_COMPLEXCALC_H_

class ComplexNumber {
 public :
    ComplexNumber();
    ComplexNumber(double _real, double _imaginary);
    ~ComplexNumber();

    double GetReal();
    double GetImaginary();
    void SetReal(double _real);
    void SetImaginary(double _imaginary);
    bool Input(const char *str);
    void Output(char* str);
    static ComplexNumber Add(ComplexNumber first,
                                 ComplexNumber second);
    static ComplexNumber Sub(ComplexNumber first,
                                 ComplexNumber second);
    static ComplexNumber Mul(ComplexNumber first,
                                   ComplexNumber second);
    static ComplexNumber Div(ComplexNumber first,
                                 ComplexNumber second);
 private :
    double real;
    double imaginary;
};

#endif  // CODE_ANDREY_GOLODYAEV_LIBRARY_COMPLEXCALC_H_
