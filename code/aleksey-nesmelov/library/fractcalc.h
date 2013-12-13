/* Copyright 2013 Nesmelov Aleksey */
#ifndef CODE_ALEKSEY_NESMELOV_LIBRARY_FRACTCALC_H_
#define CODE_ALEKSEY_NESMELOV_LIBRARY_FRACTCALC_H_
class Fraction {
 public:
    Fraction(int numenator, int denominator);
    Fraction();
    ~Fraction(void);

    int GetNumenator();
    int GetDenominator();
    void SetNumenator(int value);
    void SetDenominator(int value);

    Fraction operator+(const Fraction& a) const;
    Fraction operator-(const Fraction& a) const;
    Fraction operator*(const Fraction& a) const;
    Fraction operator/(const Fraction& a) const;

    bool operator==(const Fraction& a) const;
 private :
    int numenator;
    int denominator;

    int NOD();
    void CutFraction();
};

#endif  // CODE_ALEKSEY_NESMELOV_LIBRARY_FRACTCALC_H_

