#pragma once

using namespace std;

class WeightConvertor
{
public:
	WeightConvertor();
	~WeightConvertor();
	double ToOunce(double value, char* unit);
	double ToPound(double value, char* unit);
	double ToStone(double value, char* unit);
	double ToGrams(double value, char* unit);
	double ToKilograms(double value, char* unit);
	double ToHundredweight(double value, char* unit);
	double ToTon(double value, char* unit);
};