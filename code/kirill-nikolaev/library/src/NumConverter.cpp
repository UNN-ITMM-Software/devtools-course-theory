// Copyright 2013 K.Nikolaev

#include <stack>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>

#include "library/NumConverter.h"

std::string DecToBin(std::string decNum);
std::string BinToDec(std::string binNum);
std::string OctToDec(std::string octNum);
std::string HexToDec(std::string hexNum);

std::string DecToBin(std::string decNum) {
    std::stack<int> mystack;
    int tmp = atoi(decNum.c_str());
    do {
        mystack.push(tmp % 2);
        tmp /= 2;
    } while (tmp > 0);
    std::string s;
    while (!mystack.empty()) {
        if (mystack.top() == 0) {
            s.push_back('0');
        } else {
            s.push_back('1');
        }
        mystack.pop();
    }
    return s;
}

std::string BinToDec(std::string binNum) {
    int tmp0 = 0;
    char buf[32];
    for (unsigned int i = 0; i < binNum.length(); i++) {
        if (binNum[i] == '0') {
            continue;
        } else {
            double tmp = pow(2.0, static_cast<double>(binNum.length() - 1 - i));
            tmp0 += static_cast<int>(tmp);
        }
    }
    snprintf(buf, sizeof(buf), "%d", tmp0);
    return buf;
}

std::string OctToDec(std::string octNum) {
    int tmp0 = 0;
    char buf[32];
    for (unsigned int i = 0; i < octNum.length(); i++) {
       if (octNum[i] == '0') {
           continue;
       } else {
          int digit = octNum[i] - '0';
          double tmp = pow(8.0, static_cast<double>(octNum.length() - 1 - i));
          tmp0 += static_cast<int>(tmp)*digit;
      }
  }
  snprintf(buf, sizeof(buf), "%d", tmp0);
  return buf;
}

std::string HexToDec(std::string hexNum) {
    int tmp0 = 0;
    char buf[32];
    for (unsigned int i = 0; i < hexNum.length(); i++) {
        if (hexNum[i] == '0') {
            continue;
        } else {
            int digit = 0;
            if (isdigit(hexNum[i]))
                digit = hexNum[i] - '0';
            if (hexNum[i] == 'a')
                digit = 10;
            if (hexNum[i] == 'b')
                digit = 11;
            if (hexNum[i] == 'c')
                digit = 12;
            if (hexNum[i] == 'd')
                digit = 13;
            if (hexNum[i] == 'e')
                digit = 14;
            if (hexNum[i] == 'f')
                digit = 15;
            double tmp;
            tmp = pow(16.0, static_cast<double>(hexNum.length() - 1 - i));
            tmp0 += static_cast<int>(tmp)*digit;
        }
    }
    snprintf(buf, sizeof(buf), "%d", tmp0);
    return buf;
}

NumConverter::~NumConverter() {
}

std::string NumConverter::ToBinary() {
    int rcode = CheckLength(Val, NumSys);
    if (rcode != 0 )
        throw std::string("Wrong format.");
    if (NumSys == bin) {
        return Val;
    } else {
        std::string s("");
        if (NumSys == dec) {
            s = Val;
            s = DecToBin(s);
        }
        if (NumSys == oct) {
            s = OctToDec(Val);
            s = DecToBin(s);
        }
        if (NumSys == hex) {
            s = HexToDec(Val);
            s = DecToBin(s);
        }
        return s;
    }
}

std::string NumConverter::ToDecimal() {
    int rcode = CheckLength(Val, NumSys);
    if (rcode != 0 )
        throw std::string("Wrong format.");
    if (NumSys == dec) {
        return Val;
    } else {
        std::string s("");
        if (NumSys == bin) {
            s = BinToDec(Val);
        }
        if (NumSys == oct) {
            s = OctToDec(Val);
        }
        if (NumSys == hex) {
            s = HexToDec(Val);
        }
        return s;
    }
}

std::string NumConverter::ToOctal() {
    int rcode = CheckLength(Val, NumSys);
    if (rcode != 0 )
        throw std::string("Wrong format.");
    if (NumSys == oct) {
        return Val;
    } else {
        std::string s("");
        if (NumSys == dec) {
            s = Val;
            int tmp = atoi(s.c_str());
            char buf[32];
            snprintf(buf, sizeof(buf), "%o", tmp);
            s = buf;
        }
        if (NumSys == bin) {
            s = BinToDec(Val);
            int tmp = atoi(s.c_str());
            char buf[32];
            snprintf(buf, sizeof(buf), "%o", tmp);
            s = buf;
        }
        if (NumSys == hex) {
            s = HexToDec(Val);
            int tmp = atoi(s.c_str());
            char buf[32];
            snprintf(buf, sizeof(buf), "%o", tmp);
            s = buf;
        }
        return s;
    }
}

std::string NumConverter::ToHex() {
    int rcode = CheckLength(Val, NumSys);
    if (rcode != 0 )
        throw std::string("Wrong format.");
    if (NumSys == hex) {
        return Val;
    } else {
        std::string s("");
        if (NumSys == dec) {
            s = Val;
            int tmp = atoi(s.c_str());
            char buf[32];
            snprintf(buf, sizeof(buf), "%x", tmp);
            s = buf;
        }
        if (NumSys == bin) {
            s = BinToDec(Val);
            int tmp = atoi(s.c_str());
            char buf[32];
            snprintf(buf, sizeof(buf), "%x", tmp);
            s = buf;
        }
        if (NumSys == oct) {
            s = OctToDec(Val);
            int tmp = atoi(s.c_str());
            char buf[32];
            snprintf(buf, sizeof(buf), "%x", tmp);
            s = buf;
        }
        return s;
    }
}

std::string NumConverter::GetValue() {
    return Val;
}

int NumConverter::CheckLength(std::string val, NumSystem numsys) {
    int code = 0;
    if (numsys == bin) {
        if (val.length() > 31)
            code = 1;
        for (unsigned int i = 0; i < val.length(); i++) {
            if (val[i] < 48 || val[i] > 49)
                code = 1;
        }
    } else if (numsys == oct) {
        if (val.length() > 10)
            code = 1;
        for (unsigned int i = 0; i < val.length(); i++) {
            if (val[i] < 48 || val[i] > 55)
                code = 1;
        }
    } else if (numsys == dec) {
        if (val.length() > 9)
            code = 1;
        for (unsigned int i = 0; i < val.length(); i++) {
            if (val[i] < 48 || val[i] > 57)
                code = 1;
        }
    } else if (numsys == hex) {
        if (val.length() > 7)
            code = 1;
        for (unsigned int i = 0; i < val.length(); i++) {
            if (val[i] < 48 || (val[i] > 57 && val[i] < 97) ||
                val[i] > 102)
                code = 1;
        }
    }
    return code;
}
