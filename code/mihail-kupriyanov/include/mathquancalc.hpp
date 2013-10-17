#ifndef MATHQUANCALC
#define MATHQUANCALC

#include <vector>
#include <string>

class MathQuanCalc{
public:
	MathQuanCalc();
	MathQuanCalc(const MathQuanCalc&);
	virtual ~MathQuanCalc();

	struct Event{
		double value;
		double probability;
	};

	void PutSample(const std::vector<Event>& in_sample);
	std::vector<Event> GetSample();

	double GetExpectedValue();
	double GetDispersion();
	double GetPrimaryMoment(int level);
	double GetCentralMoment(int level);

	void GetSampleStatus();
private:
	std::vector<Event> sample; 
};

#endif