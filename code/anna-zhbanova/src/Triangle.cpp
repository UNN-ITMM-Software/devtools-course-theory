/* Copyright 2013 Anna Zhbanova */

#include <Triangle.h>
#include <math.h>

const double PI = 3.1415926535;

Triangle::Triangle(PointXY a_, PointXY b_, PointXY c_): a(a_), b(b_), c(c_) {
}
Triangle::Triangle(): a(PointXY()), b(PointXY()), c(PointXY()) {
}
Triangle::~Triangle(void) {
}

float Triangle::Length(NameOfVertex nameOfStartVertex,
                       NameOfVertex nameOfEndVertex) {
    PointXY StartVertex = Get(nameOfStartVertex);
    PointXY EndVertex = Get(nameOfEndVertex);
    return Length(StartVertex, EndVertex);
}

float Triangle::Angle(NameOfVertex nameOfVertexAngle) {
    PointXY vertexOfAngle = Get(nameOfVertexAngle);
    PointXY endP1, endP2;
    switch (nameOfVertexAngle) {
    case A:
        endP1 = Get(B);
        endP2 = Get(C);
        break;
    case B:
        endP1 = Get(A);
        endP2 = Get(C);
        break;
    case C:
        endP1 = Get(B);
        endP2 = Get(C);
        break;
    }
    return Angle(endP1, vertexOfAngle, endP2);
}

float Triangle::Square() {
    float s = -1;
    if ( IsCorrect() ) {
        float side1 = Length(a, b);
        float side2 = Length(a, c);
        float side3 = Length(b, c);

        float sinA = static_cast<float>(sqrt(1 - ((side1 * side1 + side2 * side2
           - side3 * side3)/(2 * side1 * side2))*((side1 * side1 + side2 * side2
           - side3 * side3)/(2 * side1 * side2))));
        s = side1 * side2 * sinA / 2;
    }
    return s;
}
float Triangle::Perimeter() {
    float p = -1;
    if ( IsCorrect() )
        p = Length(a, b) + Length(a, c) + Length(b, c);
    return p;
}

bool Triangle::IsCorrect() {
    if ((Length(a, b) + Length(a, c) <= Length(b, c)) ||
        (Length(a, b) + Length(b, c) <= Length(a, c)) ||
        (Length(b, c) + Length(a, c) <= Length(a, b)))
        return false;
    return true;
}
int Triangle::IsEquilateral() {
    if ( IsCorrect() ) {
        float eps = static_cast <float>(0.0001);
        if ((fabs(Length(a, b) - Length(b, c))) < eps ||
            (fabs(Length(a, b) - Length(a, c))) < eps ||
            (fabs(Length(b, c) - Length(a, c))) < eps)
            return 1;
    } else {
        return -1;
    }
    return 0;
}
int Triangle::IsIsosceles() {
    if ( IsCorrect() ) {
        float eps = static_cast <float>(0.0001);
        if ((fabs(Length(a, b) - Length(b, c))) < eps &&
            (fabs(Length(a, b) - Length(a, c))) < eps)
            return 1;
    } else {
        return -1;
    }
    return 0;
}

PointXY Triangle::Get(NameOfVertex nameVertex) {
    PointXY coordinates;
    switch (nameVertex) {
    case A:
        coordinates = a;
        break;
    case B:
        coordinates = b;
        break;
    case C:
        coordinates = c;
        break;
    }
    return coordinates;
}

void Triangle::Set(NameOfVertex nameVertex, PointXY coordinates) {
    switch (nameVertex) {
    case A:
        a = coordinates;
        break;
    case B:
        b = coordinates;
        break;
    case C:
        c = coordinates;
        break;
    }
}

float Triangle::Length(PointXY point1, PointXY point2) {
    return static_cast <float>(sqrt ( (point1.x - point2.x) *
        (point1.x - point2.x) + (point1.y - point2.y) *
        (point1.y - point2.y) ));
}

float Triangle::Angle(PointXY endP1, PointXY vertexOfAngle, PointXY endP2) {
    float side1 = Length(endP1, vertexOfAngle);
    float side2 = Length(endP2, vertexOfAngle);
    float side3 = Length(endP1, endP2);

    return static_cast <float>(180 * acos((side1 * side1 + side2 * side2
                              - side3 * side3)/(2 * side1 * side2)) / PI);
}
