#pragma once
enum Unit {Inch, Foot, Yard, Mile, Meter, KMeter, CMeter};
struct Length
{
	double num;
	Unit UnitInput;
	Unit UnitOutput;
};
class LengthConvertor
{
public:
	LengthConvertor();
	virtual ~LengthConvertor(void);
	static Length Convertor(Length data);
};