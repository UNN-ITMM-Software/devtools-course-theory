#pragma once
#include "PointXY.hpp"

class Triangle
{
public:
	Triangle(PointXY a_ = 0, PointXY b_ = 0, PointXY c_ = 0);
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

	float Length (PointXY point1, PointXY point2);
	float Angle (PointXY end_point1, PointXY vertex_of_angle, PointXY end_point2);
};