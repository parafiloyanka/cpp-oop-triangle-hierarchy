#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Triad.h"
#include <cmath>
#include <iomanip>

class Triangle : public Triad {
public:
    Triangle();
    Triangle(double a_val, double b_val, double c_val);

    bool isValid() const;
    double area() const;
    void angles(double& alpha, double& beta, double& gamma) const;
    void printTriangle() const;
};



#endif //TRIANGLE_H
