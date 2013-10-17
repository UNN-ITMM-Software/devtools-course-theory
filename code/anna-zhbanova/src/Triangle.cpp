#include "Triangle.hpp"
#include <math.h>

Triangle::Triangle(PointXY a_, PointXY b_, PointXY c_)
{
	a=a_;
	b=b_;
	c=c_;
}
Triangle::~Triangle(void)
{
}
	
float Triangle::AB()
{
	float AB;
	AB = sqrt((float)((a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y)));
	return AB;
}
float Triangle::BC()
{
	float BC;
	BC = sqrt((float)((b.x - c.x)*(b.x - c.x)+(b.y - c.y)*(b.y - c.y)));
	return BC;
}
float Triangle::AC()
{
	float AC;
	AC = sqrt((float)((a.x - c.x)*(a.x - c.x)+(a.y - c.y)*(a.y - c.y)));
	return AC;
}

float Triangle::AngleA()
{
	float angleA;
	angleA = 180*acos((AB()*AB()+AC()*AC()-BC()*BC())/(2*AB()*AC()))/3.14;
	return angleA;
}
float Triangle::AngleB()
{
	float angleB;
	angleB = 180*acos((AB()*AB()+BC()*BC()-AC()*AC())/(2*AB()*BC()))/3.14;
	return angleB;
}
float Triangle::AngleC()
{
	float angleC;
	angleC = 180*acos((AC()*AC()+BC()*BC()-AB()*AB())/(2*AC()*BC()))/3.14;
	return angleC;
}

float Triangle::Square()
{
	float s = -1;
	if(IsCorrect())
		s = AB() * AC() * sin(AngleA())/2;
	return s;
}
float Triangle::Perimeter()
{
	float p = -1;
	if(IsCorrect())
		p = AB() + AC() + BC();
	return p;
}

bool Triangle::IsCorrect()
{
	if (AB() + AC() <= BC() || AB() + BC() <= AC() || BC() + AC() <= AB())
		return false;
	return true;
}
bool Triangle::IsEquilateral()
{
	if (AB() == BC() || AB() == AC() || BC() == AC())
		return true;
	return false;
}
bool Triangle::IsIsosceles()
{
	if (AB() == BC() && AB() == AC())
		return true;
	return false;
}

PointXY Triangle::GetA()
{
	return a;
}
PointXY Triangle::GetB()
{
	return b;
}
PointXY Triangle::GetC()
{
	return c;
}

void Triangle::SetA(PointXY a_)
{
	a = a_;
}
void Triangle::SetB(PointXY b_)
{
	b = b_;
}
void Triangle::SetC(PointXY c_)
{
	c = c_;
}


