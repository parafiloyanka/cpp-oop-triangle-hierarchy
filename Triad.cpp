#include "Triad.h"
#include <iostream>

using namespace std;

Triad::Triad() : a(0), b(0), c(0) {}

Triad::Triad(double a_val, double b_val, double c_val) : a(a_val), b(b_val), c(c_val) {}

void Triad::setValues(double a_val, double b_val, double c_val) {
    a = a_val;
    b = b_val;
    c = c_val;
}

double Triad::sum() const {
    return a + b + c;
}

void Triad::print() const {
    cout << "Трійка чисел: (" << a << ", " << b << ", " << c << ")\n";
}