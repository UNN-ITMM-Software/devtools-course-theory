// Copyright 2013 Kirill Kornyakov

#include <simplecalc.h>

#include <stdio.h>

int main() {
    printf("This is a simple calculator application!\n");

    SimpleCalculator calc;
    printf("Here is result of 2 + 3: %d\n", calc.Add(2, 3));
    printf("Here is result of 6 - 7: %d\n", calc.Sub(6, 7));

    return 0;
}
