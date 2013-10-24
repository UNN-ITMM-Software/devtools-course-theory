/* Copyright 2013 Nesmelov Aleksey */
#ifndef CODE_ALEKSEY_NESMELOV_INCLUDE_FRACTCALC_H_
#define CODE_ALEKSEY_NESMELOV_INCLUDE_FRACTCALC_H_
class Fraction {
 public:
    Fraction (int numenator, int denominator);
    ~Fraction(void);

    int GetNumenator();
    int GetDenominator();
    void SetNumenator(int value);
    void SetDenominator(int value);

    static Fraction Add(Fraction a, Fraction b);
    static Fraction Subtract(Fraction a, Fraction b);
    static Fraction Multiply(Fraction a, Fraction b);
    static Fraction Divide(Fraction a, Fraction b); 
 private : 
    int numenator;
    int denominator;

    int NOD() ;
    void CutFraction();  
};

#endif  // CODE_ALEKSEY_NESMELOV_INCLUDE_FRACTCALC_H_

