/* Copyright 2013 Anna Zhbanova */
#ifndef CODE_ANNA_ZHBANOVA_INCLUDE_TRIANGLE_H_
#define CODE_ANNA_ZHBANOVA_INCLUDE_TRIANGLE_H_

#include "PointXY.h"

class Triangle {
 public :
    Triangle(PointXY a, PointXY b, PointXY c);
    Triangle();
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
    int IsEquilateral();
    int IsIsosceles();

    PointXY GetA();
    PointXY GetB();
    PointXY GetC();

    void SetA(PointXY a);
    void SetB(PointXY b);
    void SetC(PointXY c);
 private :
    PointXY a;
    PointXY b;
    PointXY c;

    float Length(PointXY point1, PointXY point2);
    float Angle(PointXY endP1, PointXY vertexOfAngle, PointXY endP2);
};

#endif  // CODE_ANNA_ZHBANOVA_INCLUDE_TRIANGLE_H_
