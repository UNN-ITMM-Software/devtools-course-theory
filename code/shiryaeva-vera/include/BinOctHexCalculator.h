/* Copyright 2013 Vera Shiryaeva */

#ifndef CODE_SHIRYAEVA_VERA_INCLUDE_BINOCTHEXCALCULATOR_H_
#define CODE_SHIRYAEVA_VERA_INCLUDE_BINOCTHEXCALCULATOR_H_

#include <string>

enum Notation {Bin, Oct, Hex};

struct Number {
    std::string value;
    Notation notation;
    };

class BinOctHexCalculator {
 public :
    BinOctHexCalculator(void);
    ~BinOctHexCalculator(void);

    std::string Add(Number num1, Number num2, Notation outputNotation);
    std::string Sub(Number num1, Number num2, Notation outputNotation);
    std::string Mult(Number num1, Number num2, Notation outputNotation);
    std::string Div(Number num1, Number num2, Notation outputNotation);
};

#endif  // CODE_SHIRYAEVA_VERA_INCLUDE_BINOCTHEXCALCULATOR_H_
