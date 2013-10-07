enum Unit {Ounce, Pound, Stone, Grams, Kilograms, Hundredweight, Ton};
struct Weight
{
	double value;
	Unit UnitInput;
	Unit UnitOutput;
};
class WeightConvertor
{
public:
	WeightConvertor();
	virtual ~WeightConvertor(void);
	static Weight Convertor(Weight data);
};