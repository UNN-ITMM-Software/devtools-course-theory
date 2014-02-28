/* Copyright 2013 Vera Shiryaeva */

#include <stdio.h>
#include <BinOctHexCalculator.h>
#include <stack>
#include <string>
#include <cmath>

int BinToDec(std::string str);
int OctToDec(std::string str);
int HexToDec(std::string str);
std::string DecToNum(int number, Notation notation);
int NumToDec(std::string value, Notation notation);

int BinToDec(std::string str) {
    int tmp = 0;
    for(unsigned int i = 0; i < str.length(); i++) {
        if(str[i] == '1') {
            tmp+=static_cast<int>(pow(2.0, static_cast<double>(str.length()-i-1)));
        } else {
            continue;
        }
    }
    return tmp;
}

int OctToDec(std::string str) {
    int tmp = 0;
    int num = 0;
    for(unsigned int i = 0; i<str.length(); i++) {
        if(str[i] == '0') {
            continue;
        } else {
                num = str[i]-'0';
                tmp+=static_cast<int>(pow(8.0, static_cast<double>(str.length()-i-1)))*num;
        }
    }
    return tmp;
}

int HexToDec(std::string str) {
    int tmp = 0;
    int num = 0;
    for(unsigned int i = 0; i<str.length(); i++){
        if(str[i] == '0') {
            continue;
        } else {
            if(isdigit(str[i])) {
                num = str[i]-'0';
            } else {
                switch(str[i]) {
                case 'a' :
                    num = 10;
                    break;
                case 'b' :
                    num = 11;
                    break;
                case 'c' :
                    num = 12;
                    break;
                case 'd' :
                    num = 13;
                    break;
                case 'e' :
                    num = 14;
                    break;
                case 'f' :
                    num = 15;
                    break;
                }
            }
            tmp+=(static_cast<int>(pow(16.0, static_cast<double>(str.length()-i-1))))*num;
        }
    }
    return tmp;
}

int NumToDec(std::string value, Notation notation) {
    int tmp = 0;
    switch(notation) {
    case Bin :
        tmp = BinToDec(value);
        break;
    case Oct :
        tmp = OctToDec(value);
        break;
    case Hex :
        tmp = HexToDec(value);
        break;
    }
    return tmp;
}

std::string DecToNum(int number, Notation notation) {
    std::string value = "";
    switch(notation) {
    case Bin : {
        std::stack<int> mystack;
        do {
            mystack.push(number % 2);
            number /= 2;
        };
        while (number > 0);
        std::string s;
        while (!mystack.empty()) {
            if (mystack.top() == 0) {
                s.push_back('0');
            } else {
                s.push_back('1');
            }
            mystack.pop();
        }
        value = s;
             }
        break;
    case Oct : {
        char buf[100];
        sprintf(buf, "%o", number);
        value = buf;
             }
        break;
    case Hex : {
        char buf[100];
        sprintf(buf, "%x", number);
        value = buf;
             }
        break;
    }
    return value;
}

BinOctHexCalculator::BinOctHexCalculator(void) {
}
BinOctHexCalculator::~BinOctHexCalculator(void) {
}
std::string BinOctHexCalculator::Add(std::string value1, Notation notation1, std::string value2, Notation notation2, Notation outputNotation) {
    int tmp = NumToDec(value1, notation1)+NumToDec(value2, notation2);
    std::string value = DecToNum(tmp, outputNotation);
    return value;
}
std::string BinOctHexCalculator::Sub(std::string value1, Notation notation1, std::string value2, Notation notation2, Notation outputNotation) {
    int tmp = NumToDec(value1, notation1)-NumToDec(value2, notation2);
    std::string value = DecToNum(tmp, outputNotation);
    return value;
}
std::string BinOctHexCalculator::Mult(std::string value1, Notation notation1, std::string value2, Notation notation2, Notation outputNotation) {
    int tmp = NumToDec(value1, notation1)*NumToDec(value2, notation2);
    std::string value = DecToNum(tmp, outputNotation);
    return value;
}
std::string BinOctHexCalculator::Div(std::string value1, Notation notation1, std::string value2, Notation notation2, Notation outputNotation) {
    int tmp = NumToDec(value1, notation1)/NumToDec(value2, notation2);
    std::string value = DecToNum(tmp, outputNotation);
    return value;
}
