/* Copyright 2013 Anna Zhbanova */

#define _USE_MATH_DEFINES
#include <Triangle.h>
#include <math.h>

Triangle::Triangle(PointXY a, PointXY b, PointXY c) {
    this->a = a;
    this->b = b;
    this->c = c;
}
Triangle::~Triangle(void) {
}

float Triangle::AB() {
    return Length(a, b);
}
float Triangle::BC() {
    return Length(b, c);
}
float Triangle::AC() {
    return Length(a, c);
}

float Triangle::AngleA() {
    return Angle(b, a, c);
}
float Triangle::AngleB() {
    return Angle(a, b, c);
}
float Triangle::AngleC() {
    return Angle(a, c, b);
}

float Triangle::Square() {
    float s = -1;
    if ( IsCorrect() )
        s = AB() * AC() * sin(AngleA()) / 2;
    return s;
}
float Triangle::Perimeter() {
    float p = -1;
    if ( IsCorrect() )
        p = AB() + AC() + BC();
    return p;
}

bool Triangle::IsCorrect() {
    if (AB() + AC() <= BC() || AB() + BC() <= AC() || BC() + AC() <= AB())
        return false;
    return true;
}
bool Triangle::IsEquilateral() {
    if (AB() == BC() || AB() == AC() || BC() == AC())
        return true;
    return false;
}
bool Triangle::IsIsosceles() {
    if (AB() == BC() && AB() == AC())
        return true;
    return false;
}

PointXY Triangle::GetA() {
    return a;
}
PointXY Triangle::GetB() {
    return b;
}
PointXY Triangle::GetC() {
    return c;
}

void Triangle::SetA(PointXY a) {
    this->a = a;
}
void Triangle::SetB(PointXY b) {
    this->b = b;
}
void Triangle::SetC(PointXY c) {
    this->c = c;
}

float Triangle::Length(PointXY point1, PointXY point2) {
    return sqrt ( (point1.x - point2.x) * (point1.x - point2.x) +
        (point1.y - point2.y) * (point1.y - point2.y) );
}

float Triangle::Angle(PointXY endP1, PointXY vertexOfAngle, PointXY endP2) {
    float side1 = Length(endP1, vertexOfAngle);
    float side2 = Length(endP2, vertexOfAngle);
    float side3 = Length(endP1, endP2);

    return (float)(180 * acos((side1 * side1 + side2 * side2 - side3 * side3)
                       /(2 * side1 * side2)) / M_PI);
}
