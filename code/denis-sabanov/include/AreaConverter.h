enum AreaType{sKilometer,hectar,ar,acre,sMeter,sFoot};
class AreaConverter
{
private:
	double value;
 	AreaType curType;		
public:
	double Convert(double value,AreaType type);
	double GetValue();
	AreaType GetAreaType();
	void SetValue(double value);
	void SetAreaType(AreaType type);	
};
