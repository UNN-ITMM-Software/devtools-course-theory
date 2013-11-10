/* Copyright 2013 Dmitriy Gorokhov */

#ifndef CODE_DMITRIY_GOROKHOV_INCLUDE_QUADRATICEQUATION_H_
#define CODE_DMITRIY_GOROKHOV_INCLUDE_QUADRATICEQUATION_H_

enum RootCount {TWOROOTS, ONEROOT, NOREALROOT};
const double EPS = 0.0000001;

class QuadraticEquation {
 public:
    QuadraticEquation();
    QuadraticEquation(double _a, double _b, double _c);
    virtual ~QuadraticEquation();
    void SetCoefficients(double _a, double _b, double _c);
    int Solve(double *root1, double *root2);

 private:
    double a, b, c;
};

#endif  // CODE_DMITRIY_GOROKHOV_INCLUDE_QUADRATICEQUATION_H_
