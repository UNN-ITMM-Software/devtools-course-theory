#ifndef MATHQUANCALC
#define MATHQUANCALC

#include <vector>

class MathQuanCalc{
public:
	MathQuanCalc();
	MathQuanCalc(const MathQuanCalc&);
	virtual ~MathQuanCalc();

	struct SelQuan{
		double value;
		double chance;
	};

	bool PutSelection(const std::vector<SelQuan>& in_selection);
	std::vector<SelQuan> GetSelection();

	bool GetMathWaiting(double& value);
	bool GetDispertion(double& value);
	bool GetPrimaryMoment(double& value, int level);
	bool GetCentralMoment(double& value, int level);

	bool GetSelectionStatus();
private:
	std::vector<SelQuan> selection; 
};

#endif