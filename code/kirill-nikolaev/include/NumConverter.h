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

    std::string GetValue(void);
    std::string ToHex(void);
    std::string ToOctal(void);
    std::string ToDecimal(void);
    std::string ToBinary(void);
 private:
    std::string Val;
    NumSystem NumSys;
};

#endif  // CODE_KIRILL_NIKOLAEV_INCLUDE_NUMCONVERTER_H_
