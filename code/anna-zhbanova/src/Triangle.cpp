#pragma once

#define _USE_MATH_DEFINES
#include "Triangle.hpp"
#include <cmath>

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
	return Length(a,b);
}
float Triangle::BC()
{
	return Length(b,c);
}
float Triangle::AC()
{
	return Length(a,c);
}

float Triangle::AngleA()
{
	return Angle(b,a,c);
}
float Triangle::AngleB()
{
	return Angle(a,b,c);
}
float Triangle::AngleC()
{
	return Angle(a,c,b);
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

float Triangle::Length (PointXY point1, PointXY point2)
{
	return sqrt((point1.x - point2.x)*(point1.x - point2.x)+(point1.y - point2.y)*(point1.y - point2.y));
}

float Triangle::Angle (PointXY end_point1, PointXY vertex_of_angle, PointXY end_point2)
{
	float side1 = Length(end_point1, vertex_of_angle);
	float side2 = Length(end_point2, vertex_of_angle);
	float side3 = Length(end_point1, end_point2);

	return 180*acos((side1*side1+side2*side2-side3*side3)/(2*side1*side2))/M_PI;
}