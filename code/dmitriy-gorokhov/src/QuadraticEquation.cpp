/* Copyright 2013 Dmitriy Gorokhov */
#include <math.h>
#include <QuadraticEquation.h>

QuadraticEquation::QuadraticEquation(): a(0), b(0), c(0) {
}

QuadraticEquation::QuadraticEquation(double _a, double _b, double _c): a(_a), b(_b), c(_c) {
}

QuadraticEquation::~QuadraticEquation() {}

void QuadraticEquation::SetCoefficients(double _a, double _b, double _c) {
    a = _a;
    b = _b;
    c = _c;
}

int QuadraticEquation::Solve(double *root1, double *root2) {
    if (a <= 0 && a >= 0)
        return(ILLEGALEQUATIONFORM);
    double discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return(NOREALROOT);
    } else {
        *root1 = (-b + sqrt(discriminant))/(2*a);
        *root2 = (-b - sqrt(discriminant))/(2*a);
    }
    if (discriminant <= 0 && discriminant >= 0)
        return(ONEROOT);
    else
        return(TWOROOTS);
}


