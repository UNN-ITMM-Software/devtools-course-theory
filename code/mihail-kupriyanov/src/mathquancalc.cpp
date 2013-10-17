#include "stdio.h"
#include "mathquancalc.hpp"
#include <math.h>

const char* exception_message = "Ряд распределения некорректен!"; 
const double acc_val = 1.0E-10;

MathQuanCalc::MathQuanCalc(){
}
MathQuanCalc::MathQuanCalc(const MathQuanCalc& mqcalc){
	sample = mqcalc.sample;
}
MathQuanCalc::~MathQuanCalc(){
}
bool MathQuanCalc::PutSample(const std::vector<Event>& in_sample){
	if(!in_sample.size())
		return false;

	double probability = 0.;
	for(int i = 0; i < in_sample.size(); i++){
		probability += in_sample[i].probability;
		if(probability > 1)
			return false;

		for(int j = 0; j < in_sample.size(); j++){
			if(j == i)
				continue;
			if(in_sample[j].value == in_sample[i].value)
				return false;
		}
	}
	if(fabs(probability - 1.) > acc_val)
		return false;
	sample = in_sample;
	return true;
}
std::vector<MathQuanCalc::Event> MathQuanCalc::GetSample(){
	return sample;
}
double MathQuanCalc::GetExpectedValue(){
	return GetPrimaryMoment(1);
}
double MathQuanCalc::GetDispersion(){
	return GetCentralMoment(2);
}
double MathQuanCalc::GetPrimaryMoment(int level){
	if(!GetSampleStatus())
		throw std::string(exception_message);

	double moment = 0;
	for(int i = 0; i < sample.size(); i++){
		moment += pow(sample[i].value, (double)level) * sample[i].probability; 
	}
	return moment;
}
double MathQuanCalc::GetCentralMoment(int level){
	double moment = 0;
	double expVal = GetExpectedValue();

	for(int i = 0; i < sample.size(); i++){
		moment += pow(sample[i].value - expVal, (double)level) * sample[i].probability; 
	}
	return moment;
}
bool MathQuanCalc::GetSampleStatus(){
	return (sample.size() > 0);
}
