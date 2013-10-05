#pragma once

enum RootCount {TWOROOTS, ONEROOT, NOREALROOT};

class QuadraticEquation
{
public:
	QuadraticEquation();
	QuadraticEquation(double _a, double _b, double _c);
	virtual ~QuadraticEquation();
	void SetCoefficients(double _a, double _b, double _c);
	int Solve(double &root1, double &root2);

private:
	double a, b, c;
};
