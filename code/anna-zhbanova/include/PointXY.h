/* Copyright 2013 Anna Zhbanova */
#ifndef CODE_ANNA_ZHBANOVA_INCLUDE_POINTXY_H_
#define CODE_ANNA_ZHBANOVA_INCLUDE_POINTXY_H_

struct PointXY 
{
    float x;
    float y; 
    
    PointXY (float x_=0, float y_=0) {
        x = x_;
        y = y_;
    }
};

#endif  // CODE_ANNA_ZHBANOVA_INCLUDE_POINTXY_H_