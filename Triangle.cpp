#include "Triangle.h"
#include <iostream>

using namespace std;

Triangle::Triangle() : Triad() {}

Triangle::Triangle(double a_val, double b_val, double c_val) : Triad(a_val, b_val, c_val) {}

bool Triangle::isValid() const {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double Triangle::area() const {
    if (!isValid()) return 0;
    double s = sum() / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void Triangle::angles(double& alpha, double& beta, double& gamma) const {
    if (!isValid()) {
        alpha = beta = gamma = 0;
        return;
    }
    alpha = acos((b * b + c * c - a * a) / (2 * b * c)) * (180 / M_PI);
    beta = acos((a * a + c * c - b * b) / (2 * a * c)) * (180 / M_PI);
    gamma = 180 - alpha - beta;
}

void Triangle::printTriangle() const {
    if (!isValid()) {
        cout << "\033[1;31m" << "Такий трикутник неможливий, оскільки порушується нерівність трикутника:\n" << "\033[0m";
        if (a + b <= c) cout << "\033[1;31m" << "  - " << a << " + " << b << " ≤ " << c << "\033[0m" << "\n";
        if (a + c <= b) cout << "\033[1;31m" << "  - " << a << " + " << c << " ≤ " << b << "\033[0m" << "\n";
        if (b + c <= a) cout << "\033[1;31m" << "  - " << b << " + " << c << " ≤ " << a << "\033[0m" << "\n";
        return;
    }

    double alpha, beta, gamma;
    angles(alpha, beta, gamma);

    cout << "Трикутник зі сторонами \033[1;33m (" << a << ", " << b << ", " << c << ")\n";
    cout << "\033[0m" << "Площа: " << fixed << setprecision(3) << "\033[1;33m"<< area() << "\n";
    cout << "\033[0m" << "Кути (в градусах): α = " << fixed << setprecision(2) << "\033[1;33m" << alpha
         << "\033[0m" << ", β = " << "\033[1;33m" << beta << "\033[0m"<< ", γ = " << "\033[1;33m" << gamma << "\033[0m\n";
}