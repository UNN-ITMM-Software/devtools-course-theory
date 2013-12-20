// Copyright 2013 K.Nikolaev
#include <NumConverter.h>
#include <stack>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>

NumConverter::~NumConverter() {
}

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
    std::string s = binNum;
    int tmp0 = 0;
    char buf[32];
    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            continue;
        } else {
            double tmp = pow(2.0, static_cast<double>(s.length() - 1 - i));
            tmp0 += static_cast<int>(tmp);
        }
    }
    snprintf(buf, sizeof(buf), "%d", tmp0);
    return buf;
}

std::string OctToDec(std::string octNum) {
    std::string s = octNum;
    int tmp0 = 0;
    char buf[32];
    for (unsigned int i = 0; i < s.length(); i++) {
       if (s[i] == '0') {
           continue;
       } else {
          int digit = s[i] - '0';
          double tmp = pow(8.0, static_cast<double>(s.length() - 1 - i));
          tmp0 += static_cast<int>(tmp)*digit;
      }
  }
  snprintf(buf, sizeof(buf), "%d", tmp0);
  return buf;
}

std::string HexToDec(std::string hexNum) {
    std::string s = hexNum;
    int tmp0 = 0;
    char buf[32];
    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            continue;
        } else {
            int digit = 0;
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
            double tmp = pow(16.0, static_cast<double>(s.length() - 1 - i));
            tmp0 += static_cast<int>(tmp)*digit;
        }
    }
    snprintf(buf, sizeof(buf), "%d", tmp0);
    return buf;
}

std::string NumConverter::ToBinary() {
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
