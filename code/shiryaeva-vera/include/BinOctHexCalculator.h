/* Copyright 2013 Vera Shiryaeva */

#ifndef CODE_SHIRYAEVA_VERA_INCLUDE_BINOCTHEXCALCULATOR_H_
#define CODE_SHIRYAEVA_VERA_INCLUDE_BINOCTHEXCALCULATOR_H_

#include <string>

enum Notation {Bin, Oct, Hex};

class BinOctHexCalculator {
 public :
    BinOctHexCalculator(void);
    ~BinOctHexCalculator(void);

    std::string Add(std::string value1, Notation notation1,
                    std::string value2, Notation notation2, Notation outputNotation);
    std::string Sub(std::string value1, Notation notation1,
                    std::string value2, Notation notation2, Notation outputNotation);
    std::string Mult(std::string value1, Notation notation1,
                    std::string value2, Notation notation2, Notation outputNotation);
    std::string Div(std::string value1, Notation notation1,
                    std::string value2, Notation notation2, Notation outputNotation);
};

#endif  // CODE_SHIRYAEVA_VERA_INCLUDE_BINOCTHEXCALCULATOR_H_
