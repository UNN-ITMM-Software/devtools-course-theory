#pragma once

using namespace std;

class LengthConvertor
{
public:
	LengthConvertor();
	~LengthConvertor();
	void help();
	double ToInch(double num, char* unit);
	double ToFoot(double num, char* unit);
	double ToYard(double num, char* unit);
	double ToMile(double num, char* unit);
	double ToMeter(double num, char* unit);
	double ToKMeter(double num, char* unit);
	double ToCMeter(double num, char* unit);
};