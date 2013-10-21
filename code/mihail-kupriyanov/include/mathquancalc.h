// Copyright 2013 Michail Kupriyanov

#ifndef CODE_MIHAIL_KUPRIYANOV_INCLUDE_MATHQUANCALC_H_
#define CODE_MIHAIL_KUPRIYANOV_INCLUDE_MATHQUANCALC_H_

#include <vector>
#include <string>

class MathQuanCalc {
 public:
    MathQuanCalc();
    MathQuanCalc(const MathQuanCalc&);
    virtual ~MathQuanCalc();

    struct Event  {
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

#endif  // CODE_MIHAIL_KUPRIYANOV_INCLUDE_MATHQUANCALC_H_
