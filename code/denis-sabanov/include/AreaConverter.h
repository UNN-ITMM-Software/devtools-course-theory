enum AreaType{sKilometer,hectar,ar,acre,sMeter,sFoot};
class AreaConverter
{
private:
	double value;
 	AreaType curType;		
public:
	double ConvertToSMeter(double value,AreaType type);
	double ConvertToSKilometer(double value,AreaType type);
	double ConvertToHectare(double value,AreaType type);
	double ConvertToAr(double value,AreaType type);
	double ConvertToAcre(double value,AreaType type);
	double ConvertToSFoot(double value,AreaType type);
	double GetValue();
	AreaType GetAreaType();
	void SetValue(double value);
	void SetAreaType(AreaType type);	
};
