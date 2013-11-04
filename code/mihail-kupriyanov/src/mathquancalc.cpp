// Copyright 2013 Michail Kupriyanov

#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>

#include "../include/mathquancalc.h"
// #include "mathquancalc.h"

const char* EXCEPTION_MESSAGE = "Ряд распределения некорректен!";
const double ACC_VAL = 1.0E-10;

MathQuanCalc::MathQuanCalc() {
}
MathQuanCalc::MathQuanCalc(const MathQuanCalc& mqcalc) {
    sample = mqcalc.sample;
}
MathQuanCalc::~MathQuanCalc() {
}
void MathQuanCalc::PutSample(const std::vector<Event>& in_sample) {
    if (!in_sample.size())
        throw std::string(EXCEPTION_MESSAGE);

    double probability = 0.;
    for (int i = 0; i < in_sample.size(); i++) {
        probability += in_sample[i].probability;
        if (probability > 1)
            throw std::string(EXCEPTION_MESSAGE);

        for (int j = 0; j < in_sample.size(); j++) {
            if (j == i)
                continue;
            if (in_sample[j].value == in_sample[i].value)
                throw std::string(EXCEPTION_MESSAGE);
        }
    }
    if (fabs(probability - 1.) > ACC_VAL)
        throw std::string(EXCEPTION_MESSAGE);
    sample = in_sample;
}
std::vector<MathQuanCalc::Event> MathQuanCalc::GetSample() {
    return sample;
}
double MathQuanCalc::GetExpectedValue() {
    return GetPrimaryMoment(1);
}
double MathQuanCalc::GetDispersion() {
    return GetCentralMoment(2);
}
double MathQuanCalc::GetPrimaryMoment(int level) {
    GetSampleStatus();

    double moment = 0;
    for (int i = 0; i < sample.size(); i++) {
        moment += pow(sample[i].value,
        static_cast<double>(level)) * sample[i].probability;
    }
    return moment;
}
double MathQuanCalc::GetCentralMoment(int level) {
    double moment = 0;
    double expVal = GetExpectedValue();

    for (int i = 0; i < sample.size(); i++) {
        moment += pow(sample[i].value - expVal,
        static_cast<double>(level)) * sample[i].probability;
    }
    return moment;
}
void MathQuanCalc::GetSampleStatus() {
    if (sample.size() == 0)
        throw std::string(EXCEPTION_MESSAGE);
}
