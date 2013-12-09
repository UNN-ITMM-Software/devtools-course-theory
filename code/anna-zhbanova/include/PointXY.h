/* Copyright 2013 Anna Zhbanova */
#ifndef CODE_ANNA_ZHBANOVA_INCLUDE_POINTXY_H_
#define CODE_ANNA_ZHBANOVA_INCLUDE_POINTXY_H_

struct PointXY {
    float x;
    float y;

    PointXY(): x(0), y(0) {
    }
    PointXY(float x_, float y_): x(x_), y(y_) {
    }
};

#endif  // CODE_ANNA_ZHBANOVA_INCLUDE_POINTXY_H_
