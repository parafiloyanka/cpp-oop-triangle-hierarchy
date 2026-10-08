#ifndef TRIAD_H
#define TRIAD_H

#include <iostream>

class Triad {
public:
    double a, b, c;
    Triad();
    Triad(double a_val, double b_val, double c_val);

    void setValues(double a_val, double b_val, double c_val);
    double sum() const;
    void print() const;
};



#endif //TRIAD_H
