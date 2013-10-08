enum Unit {Inch, Foot, Yard, Mile, Meter, KMeter, CMeter};
struct Length
{
    double value;
    Unit UnitInput;
};
class LengthConvertor
{
public:
    LengthConvertor(void);
    virtual ~LengthConvertor(void);
    Length Convert(Length length, Unit UnitOutput);
};