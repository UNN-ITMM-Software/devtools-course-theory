/* Copyright 2013 Anna Zhbanova */
#ifndef CODE_ANNA_ZHBANOVA_INCLUDE_TRIANGLE_H_
#define CODE_ANNA_ZHBANOVA_INCLUDE_TRIANGLE_H_

#include <PointXY.h>

enum NameOfVertex {A, B, C};

class Triangle {
 public :
    Triangle(PointXY a, PointXY b, PointXY c);
    Triangle();
    virtual ~Triangle(void);

    float Length(NameOfVertex nameOfStartVertex, NameOfVertex nameOfEndVertex);
    float Angle(NameOfVertex nameOfVertexAngle);

    float Square();
    float Perimeter();

    bool IsCorrect();
    int IsEquilateral();
    int IsIsosceles();

    PointXY Get(NameOfVertex nameVertex);
    void Set(NameOfVertex nameVertex, PointXY coordinates);
 private :
    PointXY a;
    PointXY b;
    PointXY c;

    float Length(PointXY point1, PointXY point2);
    float Angle(PointXY endP1, PointXY vertexOfAngle, PointXY endP2);
};

#endif  // CODE_ANNA_ZHBANOVA_INCLUDE_TRIANGLE_H_
