/* Copyright 2013 Andrey Golodyaev */
#ifndef CODE_ANDREY_GOLODYAEV_LIBRARY_COMPLEXCALC_H_
#define CODE_ANDREY_GOLODYAEV_LIBRARY_COMPLEXCALC_H_

class ComplexCalculator {
 public :
    ComplexCalculator();
    ComplexCalculator(double _real, double _imaginary);
    ~ComplexCalculator();

    double GetReal();
    double GetImaginary();
    void SetReal(double _real);
    void SetImaginary(double _imaginary);
    void Input(char *str);
    void Output(char* str);
    static ComplexCalculator Add(ComplexCalculator first,
                                 ComplexCalculator second);
    static ComplexCalculator Sub(ComplexCalculator first,
                                 ComplexCalculator second);
    static ComplexCalculator Multi(ComplexCalculator first,
                                   ComplexCalculator second);
    static ComplexCalculator Div(ComplexCalculator first,
                                 ComplexCalculator second);
 private :
    double real;
    double imaginary;
};

#endif  // CODE_ANDREY_GOLODYAEV_LIBRARY_COMPLEXCALC_H_
