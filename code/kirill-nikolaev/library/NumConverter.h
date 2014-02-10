// Copyright 2013 K.Nikolaev 

#ifndef CODE_KIRILL_NIKOLAEV_LIBRARY_NUMCONVERTER_H_
#define CODE_KIRILL_NIKOLAEV_LIBRARY_NUMCONVERTER_H_

#include <string>

enum NumSystem {
    hex, oct, dec, bin};

std::string DecToBin(std::string decNum);

#pragma pack(push, 1)
class NumConverter {
 public:
    NumConverter(std::string val, NumSystem numsys): Val(val), NumSys(numsys) {}
    ~NumConverter();

    int CheckLength(std::string val, NumSystem numsys);

    std::string GetValue(void);
    std::string ToHex(void);
    std::string ToOctal(void);
    std::string ToDecimal(void);
    std::string ToBinary(void);
 private:
    std::string Val;
    NumSystem NumSys;
};
#pragma pack(pop)

#endif  // CODE_KIRILL_NIKOLAEV_LIBRARY_NUMCONVERTER_H_
