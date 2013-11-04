/* Copyright 2013 Anna Zhbanova */
#ifndef CODE_ANNA_ZHBANOVA_INCLUDE_POINTXY_H_
#define CODE_ANNA_ZHBANOVA_INCLUDE_POINTXY_H_

struct PointXY {
    float x;
    float y;

    PointXY(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }
};

#endif  // CODE_ANNA_ZHBANOVA_INCLUDE_POINTXY_H_
