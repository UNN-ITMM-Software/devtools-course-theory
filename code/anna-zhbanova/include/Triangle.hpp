#pragma once
#include "PointXY.hpp"

class Triangle
{
public:
	Triangle();
	Triangle(PointXY a_, PointXY b_, PointXY c_);
	virtual ~Triangle(void);
	
	float AB();
	float BC();
	float AC();

	float AngleA();
	float AngleB();
	float AngleC();

	float Square();
	float Perimeter();

	bool IsCorrect();
	bool IsEquilateral();
	bool IsIsosceles();

	PointXY GetA();
	PointXY GetB();
	PointXY GetC();

	void SetA(PointXY a_);
	void SetB(PointXY b_);
	void SetC(PointXY c_);
private:
	PointXY a;
	PointXY b;
	PointXY c;
};
