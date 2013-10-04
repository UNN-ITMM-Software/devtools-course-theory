#pragma once

#define TWOROOTS 0
#define ONEROOT 1
#define NOREALROOT 2

class QuadraticEquation
{
public:
	QuadraticEquation();
	QuadraticEquation(double _a, double _b, double _c);
	virtual ~QuadraticEquation();
	void SetCoef(double _a, double _b, double _c);
	int Solve(double &root1, double &root2);

private:
	double a, b, c;
};