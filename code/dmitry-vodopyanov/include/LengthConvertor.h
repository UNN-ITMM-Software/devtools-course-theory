/* Copyright 2013 Dmitry Vodopyanov */
#ifndef CODE_DMITRY_VODOPYANOV_INCLUDE_LENGTHCONVERTOR_H_
#define CODE_DMITRY_VODOPYANOV_INCLUDE_LENGTHCONVERTOR_H_

enum LengthUnit {Inch, Foot, Yard, Mile, Meter, KMeter, CMeter};

#pragma pack(push, 1)
struct Length {
    double value;
    LengthUnit UnitInput;
};
#pragma pack(pop)

class LengthConvertor {
 public:
    LengthConvertor(void);
    virtual ~LengthConvertor(void);

    Length Convert(Length length, LengthUnit UnitOutput);
};

#endif  // CODE_DMITRY_VODOPYANOV_INCLUDE_LENGTHCONVERTOR_H_
