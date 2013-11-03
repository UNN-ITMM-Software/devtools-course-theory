// Copyright 2013 K.Nikolaev
#include <numconverter.h>
#include <string>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstdio>

NumConverter::NumConverter(NumSystem numsys, std::string value) {
    NumSys = numsys;
    Value = value;
}

NumConverter::~NumConverter() {
}

std::string DecToBin(int decNumber) {
    std::stack<int> mystack;
    int tmp = decNumber;
    do {
        mystack.push(tmp % 2);
        tmp /= 2;
    } while (tmp > 0);
    std::string s;
    int pos = 0;
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
    std::string s = binNum;
    int tmp = 0;
    char buf[20];
    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            continue;
        } else {
            tmp += pow(2, s.length() - 1 - i);
        }
    }
    snprintf(buf, sizeof(buf), "%d", tmp);
    return buf;
}

std::string OctToDec(std::string octNum) {
    std::string s = octNum;
    int tmp = 0;
    char buf[20];
    for (unsigned int i = 0; i < s.length(); i++) {
       if (s[i] == '0') {
           continue;
       } else {
          unsigned int digit = s[i] - '0';
          tmp += pow(8, s.length() - 1 - i)*digit;
      }
  }
  snprintf(buf, sizeof(buf), "%d", tmp);
  return buf;
}

std::string HexToDec(std::string hexNum) {
    std::string s = hexNum;
    int tmp = 0;
    char buf[20];
    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            continue;
        } else {
            unsigned int digit = 0;
            if (isdigit(s[i]))
                digit = s[i] - '0';
            if (s[i] == 'a')
                digit = 10;
            if (s[i] == 'b')
                digit = 11;
            if (s[i] == 'c')
                digit = 12;
            if (s[i] == 'd')
                digit = 13;
            if (s[i] == 'e')
                digit = 14;
            if (s[i] == 'f')
                digit = 15;
            tmp += pow(16, s.length() - 1 - i)*digit;
        }
    }
    snprintf(buf, sizeof(buf), "%d", tmp);
    return buf;
}

std::string NumConverter::GetValue() {
    return Value;
}

std::string NumConverter::ToBinary() {
    if (NumSys == bin) {
        return Value;
    } else {
        if (NumSys == dec) {
            std::string s = Value;
            int tmp = atoi(s.c_str());
            s = DecToBin(tmp);
            return s;
        }
        if (NumSys == oct) {
            std::string s = OctToDec(Value);
            int tmp = atoi(s.c_str());
            s = DecToBin(tmp);
            return s;
        }
        if (NumSys == hex) {
            std::string s = HexToDec(Value);
            int tmp = atoi(s.c_str());
            s = DecToBin(tmp);
            return s;
        }
    }
}

std::string NumConverter::ToDecimal() {
    if (NumSys == dec) {
        return Value;
    } else {
        if (NumSys == bin) {
            std::string s = BinToDec(Value);
            return s;
        }
        if (NumSys == oct) {
            std::string s = OctToDec(Value);
            return s;
        }
        if (NumSys == hex) {
            std::string s = HexToDec(Value);
            return s;
        }
    }
}

std::string NumConverter::ToOctal() {
    if (NumSys == oct)
        return Value;
    {
        if (NumSys == dec) {
            std::string s = Value;
            int tmp = atoi(s.c_str());
            char buf[20];
            snprintf(buf, sizeof(buf), "%o", tmp);
            s = buf;
            return s;
        }
        if (NumSys == bin) {
            std::string s = BinToDec(Value);
            int tmp = atoi(s.c_str());
            char buf[20];
            snprintf(buf, sizeof(buf), "%o", tmp);
            s = buf;
            return s;
        }
        if (NumSys == hex) {
            std::string s = HexToDec(Value);
            int tmp = atoi(s.c_str());
            char buf[20];
            snprintf(buf, sizeof(buf), "%o", tmp);
            s = buf;
            return s;
        }
    }
}

std::string NumConverter::ToHex() {
    if (NumSys == hex)
        return Value;
    {
        if (NumSys == dec) {
            std::string s = Value;
            int tmp = atoi(s.c_str());
            char buf[20];
            snprintf(buf, sizeof(buf), "%x", tmp);
            s = buf;
            return s;
        }
        if (NumSys == bin) {
            std::string s = BinToDec(Value);
            int tmp = atoi(s.c_str());
            char buf[20];
            snprintf(buf, sizeof(buf), "%x", tmp);
            s = buf;
            return s;
        }
        if (NumSys == oct) {
            std::string s = HexToDec(Value);
            int tmp = atoi(s.c_str());
            char buf[20];
            snprintf(buf, sizeof(buf), "%x", tmp);
            s = buf;
            return s;
        }
    }
}
