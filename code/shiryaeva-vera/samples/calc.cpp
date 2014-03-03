/* Copyright 2013 Vera Shiryaeva */

#include <BinOctHexCalculator.h>
#include <stdio.h>
#include <string>

int main() {
    BinOctHexCalculator calc;
    Number num1, num2;
    num1.notation = Hex;
    num1.value = "10";
    num2.notation = Bin;
    num2.value = "1011";
    printf("Here is result of %s + %s: %s\n", num1.value.c_str(),
            num2.value.c_str(), calc.Add(num1, num2, Bin).c_str());
    printf("Here is result of %s - %s: %s\n", num1.value.c_str(),
            num2.value.c_str(), calc.Sub(num1, num2, Bin).c_str());
    printf("Here is result of %s * %s: %s\n", num1.value.c_str(),
            num2.value.c_str(), calc.Mult(num1, num2, Bin).c_str());
    printf("Here is result of %s / %s: %s\n", num1.value.c_str(),
            num2.value.c_str(), calc.Div(num1, num2, Bin).c_str());
    return 0;
}
