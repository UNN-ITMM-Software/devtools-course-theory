enum AreaType{sKilometer,hectare,ar,acre,sMeter,sFoot};
class AreaConverter
{
private:
        double value;
        AreaType curType;                
public:
        double Convert(AreaType newType);
        double GetValue();
        AreaType GetAreaType();
        void SetValue(double newValue);
        void SetAreaType(AreaType newType);        
};