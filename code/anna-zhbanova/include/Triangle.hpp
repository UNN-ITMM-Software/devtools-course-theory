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

	PointXY Get_a();
	PointXY Get_b();
	PointXY Get_c();

	void Set_a(PointXY a_);
	void Set_b(PointXY b_);
	void Set_c(PointXY c_);
private:
	PointXY a;
	PointXY b;
	PointXY c;
};
