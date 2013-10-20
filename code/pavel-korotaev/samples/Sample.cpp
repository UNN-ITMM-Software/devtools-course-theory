/* Copyright 2013 Pavel Korotaev */
#include <WeightConvertor.h>
#include <stdio.h>
int main() {
    WeightConvertor Conv;
    Weight weight;
    weight.value = 100; 
        weight.unit = Pound;
    printf("100 pounds = %lf stones\n",
                Conv.ConvertTo(weight, Stone).value);
        weight.value = 22.13; weight.unit = Ounce;
    printf("22.13 ounce = %lf grams\n",
                Conv.ConvertTo(weight, Grams).value);
    weight.value = -15.0; weight.unit = Ounce;
    printf("-15 ounce = %lf grams\n",
                Conv.ConvertTo(weight, Grams).value);
    return 0;
}
