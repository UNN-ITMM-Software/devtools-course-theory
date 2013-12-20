/* Copyright 2013 K.Nikolaev */

#ifndef CODE_KIRILL_NIKOLAEV_INCLUDE_NUMCONVERTER_H_
#define CODE_KIRILL_NIKOLAEV_INCLUDE_NUMCONVERTER_H_

#include <string>

enum NumSystem {
    hex, oct, dec, bin};

std::string DecToBin(std::string decNum);

class NumConverter {
 public:
    NumConverter(NumSystem numsys, std::string val): NumSys(numsys), Val(val) {}
    ~NumConverter();

    std::string GetValue();
    std::string ToHex();
    std::string ToOctal();
    std::string ToDecimal();
    std::string ToBinary();
 private:
    NumSystem NumSys;
    std::string Val;
};

#endif  // CODE_KIRILL_NIKOLAEV_INCLUDE_NUMCONVERTER_H_
