#pragma once
enum LengthUnit {Inch, Foot, Yard, Mile, Meter, KMeter, CMeter};
struct Length
{
    double value;
    LengthUnit UnitInput;
};
class LengthConvertor
{
public:
    LengthConvertor(void);
    virtual ~LengthConvertor(void);
    Length Convert(Length length, LengthUnit UnitOutput);
};