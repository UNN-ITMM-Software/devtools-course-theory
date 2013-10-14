enum WeightUnit {Ounce, Pound, Stone, Grams, Kilograms, Hundredweight, Ton};
struct Weight
{
	double value;
	WeightUnit unit;
};
class WeightConvertor
{
public:
	WeightConvertor(void);
	virtual ~WeightConvertor(void);
	Weight ConvertTo(Weight weight, WeightUnit UnitOutput);
};