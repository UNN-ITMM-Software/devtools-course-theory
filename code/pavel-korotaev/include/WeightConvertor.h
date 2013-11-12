/* Copyright 2013 Pavel Korotaev */
#ifndef CODE_PAVEL_KOROTAEV_INCLUDE_WEIGHTCONVERTOR_H_
#define CODE_PAVEL_KOROTAEV_INCLUDE_WEIGHTCONVERTOR_H_
enum WeightUnit {Ounce, Pound, Stone, Grams, Kilograms, Hundredweight, Ton};
#pragma pack(push, 1)
typedef struct {
    double value;
    WeightUnit unit;
} Weight;
#pragma pack(pop)
class WeightConvertor {
 public:
    WeightConvertor(void);
    virtual ~WeightConvertor(void);
    Weight ConvertTo(Weight weight, WeightUnit UnitOutput);
};
#endif  // CODE_PAVEL_KOROTAEV_INCLUDE_WEIGHTCONVERTOR_H_
