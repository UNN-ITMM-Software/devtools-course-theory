/* Copyright 2013 K.Nikolaev */

#ifndef CODE_KIRILL_NIKOLAEV_INCLUDE_NUMCONVERTER_H_
#define CODE_KIRILL_NIKOLAEV_INCLUDE_NUMCONVERTER_H_

#include <string>

enum NumSystem {
    hex, oct, dec, bin};

std::string DecToBin(int decNum);

class NumConverter {
 public:
    NumConverter(NumSystem numsys, std::string value);
    ~NumConverter();

    std::string GetValue();
    std::string ToHex();
    std::string ToOctal();
    std::string ToDecimal();
    std::string ToBinary();
 private:
    NumSystem NumSys;
    std::string Value;
};

#endif  // CODE_KIRILL_NIKOLAEV_INCLUDE_NUMCONVERTER_H_
